#pragma once
#include <Windows.h>

#define PSAPI_VERSION 1
#include <psapi.h>
#pragma comment (lib, "psapi.lib")

class Patcher
{
private:
	bool DataCompare(const BYTE* pData, const BYTE* pattern, const char* mask);

protected:
	typedef char string256[256];

	DWORD64 FindPattern(DWORD64 start_address, DWORD64 length, BYTE* pattern, const char* mask);
	MODULEINFO GetModuleData(const char* moduleName);
	void ASMWrite(void* address, BYTE* code, size_t size);
	void GetString(const char* section_name, const char* str_name, const char* default_str, char* result, DWORD size);
	bool GetBool(const char* section_name, const char* bool_name, bool default_bool);

	MODULEINFO mi;
};

