#include "SafeWrite.h"

void SafeWrite8(UIntPtr addr, UInt8 data)
{
	DWORD	oldProtect;

	VirtualProtect((void *)addr, sizeof(UIntPtr), PAGE_EXECUTE_READWRITE, &oldProtect);
	*((UInt8 *)addr) = data;
	VirtualProtect((void *)addr, sizeof(UIntPtr), oldProtect, &oldProtect);
}

void SafeWrite16(UIntPtr addr, UInt16 data)
{
	DWORD	oldProtect;

	VirtualProtect((void *)addr, sizeof(UIntPtr), PAGE_EXECUTE_READWRITE, &oldProtect);
	*((UInt16 *)addr) = data;
	VirtualProtect((void *)addr, sizeof(UIntPtr), oldProtect, &oldProtect);
}

void SafeWrite32(UIntPtr addr, UInt32 data)
{
	DWORD	oldProtect;

	VirtualProtect((void *)addr, sizeof(UIntPtr), PAGE_EXECUTE_READWRITE, &oldProtect);
	*((UInt32 *)addr) = data;
	VirtualProtect((void *)addr, sizeof(UIntPtr), oldProtect, &oldProtect);
}

void SafeWrite64(UIntPtr addr, UInt64 data)
{
	DWORD	oldProtect;

	VirtualProtect((void *)addr, sizeof(UIntPtr), PAGE_EXECUTE_READWRITE, &oldProtect);
	*((UInt64 *)addr) = data;
	VirtualProtect((void *)addr, sizeof(UIntPtr), oldProtect, &oldProtect);
}

void SafeWritePtr(UIntPtr addr, UIntPtr data)
{
	DWORD	oldProtect;

	VirtualProtect((void *)addr, sizeof(UIntPtr), PAGE_EXECUTE_READWRITE, &oldProtect);
	*((UInt32 *)addr) = data;
	VirtualProtect((void *)addr, sizeof(UIntPtr), oldProtect, &oldProtect);
}

void SafeWriteBuf(UIntPtr addr, void * data, size_t len)
{
	DWORD	oldProtect;

	VirtualProtect((void *)addr, len, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy((void *)addr, data, len);
	VirtualProtect((void *)addr, len, oldProtect, &oldProtect);
}

//TODO: Write x64 equiv
void WriteRelJump(UIntPtr jumpSrc, UIntPtr jumpTgt)
{
	// jmp rel32
	SafeWrite8(jumpSrc, 0xE9);
	SafeWrite32(jumpSrc + 1, jumpTgt - jumpSrc - 1 - 4);
}

void WriteRelCall(UIntPtr jumpSrc, UIntPtr jumpTgt)
{
	// call rel32
	SafeWrite8(jumpSrc, 0xE8);
	SafeWrite32(jumpSrc + 1, jumpTgt - jumpSrc - 1 - 4);
}

void WriteRelJnz(UIntPtr jumpSrc, UIntPtr jumpTgt)
{
	// jnz rel32
	SafeWrite16(jumpSrc, 0x850F);
	SafeWrite32(jumpSrc + 2, jumpTgt - jumpSrc - 2 - 4);
}

void WriteRelJle(UIntPtr jumpSrc, UIntPtr jumpTgt)
{
	// jle rel32
	SafeWrite16(jumpSrc, 0x8E0F);
	SafeWrite32(jumpSrc + 2, jumpTgt - jumpSrc - 2 - 4);
}
