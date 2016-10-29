#pragma once

void SafeWrite8(UIntPtr addr, UInt8 data);
void SafeWrite16(UIntPtr addr, UInt16 data);
void SafeWrite32(UIntPtr addr, UInt32 data);
void SafeWrite64(UIntPtr addr, UInt64 data);
void SafeWritePtr(UIntPtr addr, UIntPtr data);
void SafeWriteBuf(UIntPtr addr, void * data, size_t len);

// 5 bytes
void WriteRelJump(UIntPtr jumpSrc, UIntPtr jumpTgt);
void WriteRelCall(UIntPtr jumpSrc, UIntPtr jumpTgt);

// 6 bytes
void WriteRelJnz(UIntPtr jumpSrc, UIntPtr jumpTgt);
void WriteRelJle(UIntPtr jumpSrc, UIntPtr jumpTgt);
