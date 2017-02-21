#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int main() {

    HANDLE hFile;
    TCHAR buffer[256] = "Some control text";
    char *filename = TEXT("test.txt");
    BOOL writeFlag = FALSE;

    hFile = CreateFile(filename,                // name of the write
                       GENERIC_WRITE,          // open for writing
                       0,                      // do not share
                       NULL,                   // default security
                       CREATE_NEW,             // create new file only
                       FILE_ATTRIBUTE_NORMAL,  // normal file
                       NULL);                  // no attr. template

    if (hFile == INVALID_HANDLE_VALUE) {
        printf(TEXT("CreateFile"));
        _tprintf(TEXT("Terminal failure: Unable to create file \"%s\" for write.\n"), filename);
        return 0;
    }

    writeFlag = WriteFile(hFile, buffer, 256, NULL, NULL);

    if (!writeFlag) {
        _tprintf(TEXT("Can't write to file"));
        return 0;
    }

    CloseHandle(hFile);
    return 1;
}