#include "GameFolder.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        Beep(1000, 200);

        GameFolder::GameFolder();
    }

    return TRUE;
}

