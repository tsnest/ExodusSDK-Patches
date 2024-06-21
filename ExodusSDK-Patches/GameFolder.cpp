#include "GameFolder.h"

GameFolder::GameFolder()
{
	this->mi = GetModuleData("uEditor_m.dll");

	// Обход проверки наличия игры
	// 40 55 41 56 41 57 48 8d ac 24 ? ? ? ? b8 ? ? ? ? e8 ? ? ? ? 48 2b e0 48 c7 44 24 ? ? ? ? ? 48 89 9c 24 ? ? ? ? 48 89 b4 24 ? ? ? ? 48 89 bc 24 ? ? ? ? 48 8b 05 ? ? ? ? 48 33 c4 48 89 85 ? ? ? ? c6 44 24
	LPVOID checker = (LPVOID)FindPattern(
		(DWORD64)mi.lpBaseOfDll,
		mi.SizeOfImage,
		(BYTE*)"\x40\x55\x41\x56\x41\x57\x48\x8d\xac\x24\x00\x00\x00\x00\xb8\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x48\x2b\xe0\x48\xc7\x44\x24\x00\x00\x00\x00\x00\x48\x89\x9c\x24\x00\x00\x00\x00\x48\x89\xb4\x24\x00\x00\x00\x00\x48\x89\xbc\x24\x00\x00\x00\x00\x48\x8b\x05\x00\x00\x00\x00\x48\x33\xc4\x48\x89\x85\x00\x00\x00\x00\xc6\x44\x24",
		"xxxxxxxxxx????x????x????xxxxxxx?????xxxx????xxxx????xxxx????xxx????xxxxxx????xxx");

	// mov eax, 1
	// ret
	BYTE ret[] = { 0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3 };
	ASMWrite(checker, ret, sizeof(ret));
}
