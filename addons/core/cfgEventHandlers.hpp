
class Extended_PreInit_EventHandlers {
    class ADDON {
          Init = QUOTE(call COMPILE_FILE(XEH_PreInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
          Init = QUOTE(call COMPILE_FILE(XEH_PostInit));
    };
}