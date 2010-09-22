//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   Main.cpp
//    Author:      Streamlet
//    Create Time: 2010-09-14
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------


#include <stdio.h>
#include <tchar.h>
#include <locale.h>
#include "../ZLibWrap/ZLibWrap.h"

void ShowBanner()
{
    _tprintf(_T("ZLibWrapTest  By Streamlet\n"));
    _tprintf(_T("\n"));
}

void ShowHelp()
{
    _tprintf(_T("Usage:\n"));
    _tprintf(_T("    ZLibWrapTest /z <SourceFiles> <ZipFile>\n"));
    _tprintf(_T("    ZLibWrapTest /u <ZipFile> <DestFolder>\n"));
}

int _tmain(int argc, TCHAR *argv[])
{
    setlocale(LC_ALL, "");

    ShowBanner();

    if (argc != 4)
    {
        ShowHelp();
        return 0;
    }

    enum
    {
        ZIP,
        UNZIP

    } TODO;

    if (_tcscmp(argv[1], _T("/z")) == 0 ||
        _tcscmp(argv[1], _T("/Z")) == 0)
    {
        TODO = ZIP;
    }
    else if (_tcscmp(argv[1], _T("/u")) == 0 ||
             _tcscmp(argv[1], _T("/U")) == 0)
    {
        TODO = UNZIP;
    }
    else
    {
        ShowHelp();
        return 0;
    }

    switch (TODO)
    {
    case ZIP:
        if (ZWZipCompress(argv[2], argv[3]))
        {
            _tprintf(_T("Compressed %s to %s successfully.\n"), argv[2], argv[3]);
        }
        else
        {
            _tprintf(_T("Failed to compress %s to %s.\n"), argv[2], argv[3]);
        }
        break;
    case UNZIP:
        if (ZWZipExtract(argv[2], argv[3]))
        {
            _tprintf(_T("Extracted %s to %s successfully.\n"), argv[2], argv[3]);
        }
        else
        {
            _tprintf(_T("Failed to Extract %s to %s.\n"), argv[2], argv[3]);
        }
        break;
    default:
        break;
    }

    return 0;
}




