// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }


    DWORD oldprotect;
    typedef int(__stdcall* f_MoiMainWin)(HINSTANCE, LPWSTR, int);

     

            __int64 dllBase = (__int64)GetModuleHandleW(L"pk.node");
            if (dllBase) {
                VirtualProtect((LPVOID)(dllBase + 0x1000), 0x80000, PAGE_EXECUTE_READWRITE, &oldprotect);

                *(__int8*)(dllBase + 0x701ED) = 0x01;

                VirtualProtect((LPVOID)(dllBase + 0x1000), 0x80000, oldprotect, &oldprotect);
            }


    return TRUE;
}

__declspec(dllexport) int getEngineVersion() {
    return 1;
}