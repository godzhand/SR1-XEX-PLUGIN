//--------------------------------------------------------------------------------------
// AtgUtil.cpp
//
// Helper functions and typing shortcuts for samples
//
// Xbox Advanced Technology Group.
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#include "StdAfx.h"
#include "Util.h"

namespace WAVE
{


HRESULT LoadFile( const CHAR* strFileName, VOID** ppFileData, DWORD* pdwFileSize )
{
    assert( ppFileData );
    if( pdwFileSize )
        *pdwFileSize = 0L;

    // Open the file for reading
    HANDLE hFile = CreateFile( strFileName, GENERIC_READ, 0, NULL,
                               OPEN_EXISTING, 0, NULL );

    if( INVALID_HANDLE_VALUE == hFile )
        return E_HANDLE;

    DWORD dwFileSize = GetFileSize( hFile, NULL );
    VOID* pFileData = malloc( dwFileSize );

    if( NULL == pFileData )
    {
        CloseHandle( hFile );
        return E_OUTOFMEMORY;
    }

    DWORD dwBytesRead;
    if( !ReadFile( hFile, pFileData, dwFileSize, &dwBytesRead, NULL ) )
    {
        CloseHandle( hFile );
        free( pFileData );
        return E_FAIL;
    }

    // Finished reading file
    CloseHandle( hFile );

    if( dwBytesRead != dwFileSize )
    {
        free( pFileData );
        return E_FAIL;
    }

    if( pdwFileSize )
        *pdwFileSize = dwFileSize;
    *ppFileData = pFileData;

    return S_OK;
}


//--------------------------------------------------------------------------------------
// Name: UnloadFile()
// Desc: Matching unload
//--------------------------------------------------------------------------------------
VOID UnloadFile( VOID* pFileData )
{
    assert( pFileData != NULL );
    free( pFileData );
}


//--------------------------------------------------------------------------------------
// Name: LoadFilePhysicalMemory()
// Desc: Helper function to load a file into physicall memory
//--------------------------------------------------------------------------------------
HRESULT LoadFilePhysicalMemory( const CHAR* strFileName, VOID** ppFileData,
                                DWORD* pdwFileSize, DWORD dwAlignment )
{
    assert( ppFileData );
    if( pdwFileSize )
        *pdwFileSize = 0L;

    // Open the file for reading
    HANDLE hFile = CreateFile( strFileName, GENERIC_READ, 0, NULL,
                               OPEN_EXISTING, 0, NULL );

    if( INVALID_HANDLE_VALUE == hFile )
        return E_HANDLE;

    DWORD dwFileSize = GetFileSize( hFile, NULL );
    VOID* pFileData = XPhysicalAlloc( dwFileSize, MAXULONG_PTR, dwAlignment, PAGE_READWRITE );

    if( NULL == pFileData )
    {
        CloseHandle( hFile );
        return E_OUTOFMEMORY;
    }

    DWORD dwBytesRead;
    if( !ReadFile( hFile, pFileData, dwFileSize, &dwBytesRead, NULL ) )
    {
        CloseHandle( hFile );
        XPhysicalFree( pFileData );
        return E_FAIL;
    }

    // Finished reading file
    CloseHandle( hFile );

    if( dwBytesRead != dwFileSize )
    {
        XPhysicalFree( pFileData );
        return E_FAIL;
    }

    if( pdwFileSize )
        *pdwFileSize = dwFileSize;
    *ppFileData = pFileData;

    return S_OK;
}


//--------------------------------------------------------------------------------------
// Name: UnloadFilePhysicalMemory()
// Desc: Matching unload
//--------------------------------------------------------------------------------------
VOID UnloadFilePhysicalMemory( VOID* pFileData )
{
    assert( pFileData != NULL );
    XPhysicalFree( pFileData );
}


//--------------------------------------------------------------------------------------
// Name: SaveFile()
// Desc: Helper function to save a file
//--------------------------------------------------------------------------------------
HRESULT SaveFile( const CHAR* strFileName, VOID* pFileData, DWORD dwFileSize )
{
    // Open the file for reading
    HANDLE hFile = CreateFile( strFileName, GENERIC_WRITE, 0, NULL,
                               CREATE_ALWAYS, 0, NULL );
    if( INVALID_HANDLE_VALUE == hFile )
        return E_HANDLE;

    DWORD dwBytesWritten;
    WriteFile( hFile, pFileData, dwFileSize, &dwBytesWritten, NULL );

    // Finished reading file
    CloseHandle( hFile );

    if( dwBytesWritten != dwFileSize )
        return E_FAIL;

    return S_OK;
}


} // namespace ATG
