
'from winbase.h and winnt.h


#define PAGE_NOACCESS          0x01     
#define PAGE_READONLY          0x02     
#define PAGE_READWRITE         0x04     
#define PAGE_WRITECOPY         0x08     

//
// Token Specific Access Rights.
//

#define TOKEN_ASSIGN_PRIMARY    (0x0001)
#define TOKEN_DUPLICATE         (0x0002)
#define TOKEN_IMPERSONATE       (0x0004)
#define TOKEN_QUERY             (0x0008)
#define TOKEN_QUERY_SOURCE      (0x0010)
#define TOKEN_ADJUST_PRIVILEGES (0x0020)
#define TOKEN_ADJUST_GROUPS     (0x0040)
#define TOKEN_ADJUST_DEFAULT    (0x0080)
#define TOKEN_ADJUST_SESSIONID  (0x0100)

#define SECTION_QUERY                0x0001
#define SECTION_MAP_WRITE            0x0002
#define SECTION_MAP_READ             0x0004
#define SECTION_MAP_EXECUTE          0x0008
#define SECTION_EXTEND_SIZE          0x0010

#define SECTION_MAP_EXECUTE_EXPLICIT 0x0020 // not included in SECTION_ALL_ACCESS

#define STANDARD_RIGHTS_REQUIRED         (0x000F0000L)

#define SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY|\
                            SECTION_MAP_WRITE |      \
                            SECTION_MAP_READ |       \
                            SECTION_MAP_EXECUTE |    \
                            SECTION_EXTEND_SIZE)


#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1) 'itr cast in macro

#define FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS


#define TRUE  1
#define FALSE 0
#define __in
#define __out
#define __in_opt  optional
#define __out_opt optional

typedef zstring *LPCTSTR, *LPCSTR
typedef sys      HANDLE
typedef long     *LONG_PTR
typedef dword    DWORD, SIZE_T
typedef void     VOID, *LPVOID, *LPCVOID,*LPSECURITY_ATTRIBUTES
typedef bool     BOOL

'const as LPVOID NULL=0 'ITR void*


'BASIC definitions.

def NULL byval 0
def INVALID_HANDLE_VALUE byval -1



extern stdcall lib "kernel32.dll"

    HANDLE CreateFileMappingA(
    __in     HANDLE hFile,
    __in_opt LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    __in     DWORD flProtect,
    __in     DWORD dwMaximumSizeHigh,
    __in     DWORD dwMaximumSizeLow,
    __in_opt LPCSTR lpName
    );

    HANDLE OpenFileMappingA(
    __in DWORD dwDesiredAccess,
    __in BOOL bInheritHandle,
    __in LPCSTR lpName
    );


    LPVOID MapViewOfFile(
    __in HANDLE hFileMappingObject,
    __in DWORD dwDesiredAccess,
    __in DWORD dwFileOffsetHigh,
    __in DWORD dwFileOffsetLow,
    __in SIZE_T dwNumberOfBytesToMap
    );

    DWORD GetLastError(
    VOID
    );

    BOOL UnmapViewOfFile(
    __in LPCVOID lpBaseAddress
    );

    BOOL CloseHandle(
    __in HANDLE hObject
    );

end extern
