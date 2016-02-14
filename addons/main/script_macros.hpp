#include "\x\cba\addons\main\script_macros_common.hpp"
#include "\x\cba\addons\xeh\script_xeh.hpp"

// Default versioning level
#define DEFAULT_VERSIONING_LEVEL 2


#define SMEFUNC(var1,var2) TRIPLES(DOUBLES(PREFIX,var1),fnc,var2)  //MOD Function (Module Cross)
#define SMIFUNC(var1) TRIPLES(ADDON,fnc,var1) //MOD Function (Module Intern)
#define BISFUNC(var1) TRIPLES(BIS,fnc,var1)   //BIS Function
#define CBAFUNC(var1) TRIPLES(CBA,fnc,var1)   //CBA Function#

#define SMEVAR(var1,var2) QUOTE(TRIPLES(PREFIX,var1,var2))
#define SMIVAR(var1) QUOTE(DOUBLES(ADDON,var1))

//Name of Communication Logic
#define CPORT DOUBLES(ADDON,comm)


#define ARR_SELECT(ARRAY,INDEX,DEFAULT) if (count ARRAY > INDEX) then {ARRAY select INDEX} else {DEFAULT}

#ifdef DISABLE_COMPILE_CACHE
    #define PREP(fncName) SMIFUNC(fncName) = compile preprocessFileLineNumbers QUOTE(PATHTOF(functions\DOUBLES(fnc,fncName).sqf))
#else
    #define PREP(fncName) SMIFUNC(fncName) = QUOTE(PATHTOF(functions\DOUBLES(fnc,fncName).sqf)) call SLX_XEH_COMPILE
#endif

#define GRAD_isHC (!hasInterface && !isDedicated)

// TODO brauchen wir das noch ?
#define GA_fnc_LOG { params ["_file","_lineNum","_addon","_message"]; diag_log [_addon,diag_frameNo, diag_tickTime, time,  _file + ":"+str(_lineNum + 1), _message];}

#define LOG_FORMAT(module,level,file,lnr, message) FORMAT_4(QUOTE([GRAD] %1 (module) %3|%4: %2),level, message, file, lnr)
#define LOG_BASE(module,level,message) diag_log text LOG_FORMAT(module,level,__FILE__, __LINE__,message)
#define LOG_ERR(message) LOG_BASE(COMPONENT,"ERROR",message)
#define LOG_INFO(message) LOG_BASE(COMPONENT,"INFO",message)
#define LOG_WARN(message) LOG_BASE(COMPONENT,"WARN",message)
#ifdef DEBUG_MODE_FULL
    #define LOG_DEBUG(message) LOG_BASE(COMPONENT,"DEBUG",message)
#else
//kein output erzeugen
    #define LOG_DEBUG(message)
#endif

//hash macros
#define HASH_NEW(array, default) { params["_array","_default"]; [_array, _default] call CBA_fnc_hashCreate; }
#define HASH_GET(array, key) { params["_array","_key"]; [_array, _key] call CBA_fnc_hashGet; }
#define HASH_SET(array, key, value) { params["_array","_key","_value"]; [_array, _key, _value] call CBA_fnc_hashSet; }
#define HASH_HAS_KEY(array, key) { params["_array","_key"]; [_array, _key] call CBA_fnc_hashHasKey; }
#define HASH_REM(array, key) { params["_array","_key"]; [_array, _key] call CBA_fnc_hashRem; }
#define HASH_FOREACH(array, code) { params["_array","_code"]; [_array, _code] call CBA_fnc_hashEachPair; }
#define HASH_IS_HASH(object) { params["_object"]; _object call CBA_fnc_isHash; }

//<params> remoteExecCall [<function>,(<target>,<isPersistent>)];
#define RE_SRV(params,function) { params ["_params","_func"] if (!isServer) exitWith {_params remoteExecCall [str _function, 2]}}
#define RE_SRV_TST(params,function) params remoteExecCall [str function, 2]
