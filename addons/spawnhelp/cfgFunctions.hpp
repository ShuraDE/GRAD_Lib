class CfgFunctions
{
  class ADDON
  {
    class spawning
    {

      class checkEntities {
                            description = "Find entities in the sphere with given radius.";
                            file = "\y\grad\addons\spawnhelp\functions\fnc_checkEntities.sqf";
                          };
      class checkHousePos {
                             description = "Find all available positions in a building or structure.";
                            file = "\y\grad\addons\spawnhelp\functions\fnc_checkHousePos.sqf";
                          };
      class checkHouses {
                           description = "Find Houses with given radius.";
                           file = "\y\grad\addons\spawnhelp\functions\fnc_checkHouses.sqf";
                         };
      class checkObjects {
                           description = "Find entities in the sphere with given radius.";
                           file = "\y\grad\addons\spawnhelp\functions\fnc_checkObjects.sqf";
                         };
     class checkTerrainObj {
                              description = "Returns a list of nearest terrain objects.";
                              file = "\y\grad\addons\spawnhelp\functions\fnc_checkTerrainObj.sqf";
                            };
      class dataType {
                       description = "Returns the data type of an expression.";
                       file = "\y\grad\addons\spawnhelp\functions\fnc_dataType.sqf";
                     };
      class getMapLocations {
                              description = "Returns the Locations of Map.";
                              file = "\y\grad\addons\spawnhelp\functions\fnc_getMapLocations.sqf";
                            };
      class getSlope {
                        description = "Returns an average slope value of terrain within passed radius.";
                        file = "\y\grad\addons\spawnhelp\functions\fnc_getSlope.sqf";
                      };
      class getStreetDir {
                            description = "Check the Direction of given Streetblock.";
                            file = "\y\grad\addons\spawnhelp\functions\fnc_getStreetDir.sqf";
                         };
      class getStreetLine {
                            description = "Return Number of Streetblocks in Line to specific Position or Direction.";
                            file = "\y\grad\addons\spawnhelp\functions\fnc_getStreetLine.sqf";
                          };
      class getStreets {
                        description = "Checks for Streets in a spezific Range.";
                        file = "\y\grad\addons\spawnhelp\functions\fnc_getStreets.sqf";
                       };
      class isOnMap {
                       description = "Check Position is inside of Map.";
                       file = "\y\grad\addons\spawnhelp\functions\fnc_isOnMap.sqf";
                    };
      class isWater {
                        description = "Returns whether water is at given position.";
                        file = "\y\grad\addons\spawnhelp\functions\fnc_isWater.sqf";
                    };
      class nearestStreet {
                             description = "Find nearest Street to given Position.";
                             file = "\y\grad\addons\spawnhelp\functions\fnc_nearestStreet.sqf";
                          };
      class setDebugMarker {
                              description = "Set a Arrow with different Colors to Position";
                              file = "\y\grad\addons\spawnhelp\functions\fnc_setDebugMarker.sqf";
                           };

    };
  };
};
