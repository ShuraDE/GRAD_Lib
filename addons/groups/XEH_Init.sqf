#include "script_component.hpp"
LOG_INFO("xeh init groups");
LOG_INFO(TEST_PATH(test));
LOG_INFO(TEST_PATH(test));
LOG_INFO(TEST_PATH(test));
//ADDON = false;
//PRECO(test)
SMIFUNC(groupTypeSelection) = compile preProcessFileLineNumbers "\y\grad\addons\groups\functions\fnc_groupTypeSelection.sqf";
call SMIFUNC(groupTypeSelection);
//ADDON = true;
