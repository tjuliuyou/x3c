#ifndef X3GCC_PORTABILITY_H
#define X3GCC_PORTABILITY_H

#include <string.h>
#include <stdlib.h>

#undef _WIN32

#ifndef interface
#define interface struct
#endif

typedef void* HMODULE;
typedef void* HANDLE;
typedef void* HWND;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef DWORD ULONG;

inline void DebugBreak() {}
inline long InterlockedIncrement(long* p) { return ++(*p); }
inline long InterlockedDecrement(long* p) { return --(*p); }
inline long InterlockedExchange(long* p, long v)
    { long old = *p; *p = v; return old; }
inline void* InterlockedCompareExchange(void** p, void* newv, void* cmp)
{
    void* old = *p;
    if (cmp == *p)
        *(long*)p = (long)newv;
    return old;
}


bool FreeLibrary(HMODULE hdll);
HMODULE LoadLibraryW(const wchar_t* filename);
HMODULE LoadLibraryExW(const wchar_t* filename, void*, DWORD);
HMODULE GetModuleHandleW(const wchar_t* filename);
void* GetProcAddress(HMODULE hdll, const char* name);
void GetModuleFileNameW(HMODULE hdll, wchar_t* filename, int size);
void GetModuleFileNameA(HMODULE hdll, char* filename, int size);

HANDLE CreateFileW(const wchar_t* filename, DWORD access, 
                   DWORD shareMode, void*, DWORD disposition, 
                   DWORD attributes, void*);
bool CloseFile(HANDLE file);
bool ReadFile(HANDLE file, void* buf, DWORD size, DWORD* readed, void*);
bool WriteFile(HANDLE file, const void* buf, DWORD size, DWORD* written, void*);
bool PathFileExistsW(const wchar_t* path);
bool CreateDirectoryW(const wchar_t* path, void*);
bool DeleteFileW(const wchar_t* filename);
DWORD GetFileSize(HANDLE file, DWORD* high);

char* PathFindFileNameA(const char* path);
wchar_t* PathFindFileNameW(const wchar_t* path);
bool PathIsRelativeW(const wchar_t* path);
void PathStripPathW(wchar_t* path);
void PathRemoveFileSpecW(wchar_t* path);
void PathRemoveExtensionW(wchar_t* path);
void PathRemoveBackslashW(wchar_t* path);
void PathAppendW(wchar_t* path, const wchar_t* more);
wchar_t* PathAddBackslashW(wchar_t* path);
void PathRenameExtensionW(wchar_t* path, const wchar_t* more);

void GetTempPathW(DWORD len, wchar_t* buf);
DWORD GetFileAttributesW(const wchar_t* filename);
bool SetFileAttributesW(const wchar_t* filename, DWORD attr);
DWORD GetLastError();

int WideCharToMultiByte(int codepage, DWORD flags,
                        const wchar_t* wstr, int wchars,
                        char* astr, int achars,
                        const char* defaultChar, void*);
int MultiByteToWideChar(int codepage, DWORD flags,
                        const char* astr, int achars,
                        wchar_t* wstr, int wchars);

#endif // X3GCC_PORTABILITY_H