#include "\y\grad\addons\loadout\script_component.hpp"

private ["_configPath", "_missionStart"];

_configPath = missionConfigFile >> "CfgLoadouts";
_missionStart = if ( !isNil { _this select 0 } && { _this select 0 == "postInit" }) then { true } else { false };

// Make sure that only local player is considered as target on respawn.
// This is because AI don't respawn, and we especially don't want to have local AI go through an entire loadout loop again, everytime the player respawns that the AI belongs to.
_units = [];
if( !_missionStart ) then {
	_units pushBack player;
} else {
	{
		if ( local _x ) then {
			_units pushBack _x;
		};
	} forEach allUnits;
};

{
	// General --------------------------------------------------------------------------------------
	// Every single unit
	if( isClass ( _configPath >> "AllUnits" )) then {
		[_configPath >> "AllUnits", _x] call FNC_SMI(DoLoadout);
	};

	// All AI units
	if( !isPlayer _x && { isClass ( _configPath >> "AllAi" )}) then {
		[_configPath >> "AllAi", _x] call FNC_SMI(DoLoadout);
	};

	// All players
	if( isPlayer _x && { isClass ( _configPath >> "AllPlayers" )}) then {
		[_configPath >> "AllPlayers", _x] call FNC_SMI(DoLoadout);
	};

	// General sides --------------------------------------------------------------------------------
	// All blufor units
	if( side _x == blufor && { isClass ( _configPath >> "Blufor" )}) then {
		[_configPath >> "Blufor", _x] call FNC_SMI(DoLoadout);
	};

	// All opfor units
	if( side _x == opfor && { isClass ( _configPath >> "Opfor" )}) then {
		[_configPath >> "Opfor", _x] call FNC_SMI(DoLoadout);
	};

	// All independent units
	if( side _x == independent && { isClass ( _configPath >> "Independent" )}) then {
		[_configPath >> "Independent", _x] call FNC_SMI(DoLoadout);
	};

	// All civilian units
	if( side _x == civilian && { isClass ( _configPath >> "Civilian" )}) then {
		[_configPath >> "Civilian", _x] call FNC_SMI(DoLoadout);
	};

	// AI sides -------------------------------------------------------------------------------------
	// All blufor AI units
	if( side _x == blufor && { !isPlayer _x } && { isClass ( _configPath >> "BluforAi" )}) then {
		[_configPath >> "BluforAi", _x] call FNC_SMI(DoLoadout);
	};

	// All opfor AI units
	if( side _x == opfor && { !isPlayer _x } && { isClass ( _configPath >> "OpforAi" )}) then {
		[_configPath >> "OpforAi", _x] call FNC_SMI(DoLoadout);
	};

	// All independent AI units
	if( side _x == independent && { !isPlayer _x } && { isClass ( _configPath >> "IndependentAi" )}) then {
		[_configPath >> "IndependentAi", _x] call FNC_SMI(DoLoadout);
	};

	// All civilian AI units
	if( side _x == civilian && { !isPlayer _x } && { isClass ( _configPath >> "CivilianAi" )}) then {
		[_configPath >> "CivilianAi", _x] call FNC_SMI(DoLoadout);
	};

	// Player sides ---------------------------------------------------------------------------------
	// All blufor units
	if( side _x == blufor && { isPlayer _x } && { isClass ( _configPath >> "BluforPlayers" )}) then {
		[_configPath >> "BluforPlayers", _x] call FNC_SMI(DoLoadout);
	};

	// All opfor units
	if( side _x == opfor && { isPlayer _x } && { isClass ( _configPath >> "OpforPlayers" )}) then {
		[_configPath >> "OpforPlayers", _x] call FNC_SMI(DoLoadout);
	};

	// All independent units
	if( side _x == independent && { isPlayer _x } && { isClass ( _configPath >> "IndependentPlayers" )}) then {
		[_configPath >> "IndependentPlayers", _x] call FNC_SMI(DoLoadout);
	};

	// All civilian units
	if( side _x == civilian && { isPlayer _x } && { isClass ( _configPath >> "CivilianPlayers" )}) then {
		[_configPath >> "CivilianPlayers", _x] call FNC_SMI(DoLoadout);
	};
 
  //Faction
  //Faction based loadouts
	if( isClass ( _configPath >> faction _x )) then {
		[_configPath >> faction _x, _x] call FNC_SMI(DoLoadout);
	};
  
	// Class & Unique -------------------------------------------------------------------------------
	// Class based loadouts
	if( isClass ( _configPath >> typeof _x )) then {
		[_configPath >> typeof _x, _x] call FNC_SMI(DoLoadout);
	};

	// Roledescription based loadouts
	_role = [roleDescription _x] call FNC_BIS(filterString);
	if( isClass ( _configPath >> _role )) then {
		[_configPath >> _role, _x] call FNC_SMI(DoLoadout);
	};  
  
	// Name based loadouts
	_str = str _x splitString "_" select 0;
	if( isClass ( _configPath >> _str )) then {
		[_configPath >> _str, _x] call FNC_SMI(DoLoadout);
	};
} forEach _units;
