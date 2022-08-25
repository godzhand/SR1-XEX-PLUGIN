//--------------------------------------------------------------------------------------
// AtgFont.h
//
// Texture-based font class. This class reads .abc font files that are generated by the
// FontMaker tool (and optionally compressed, or "packed", with the FontPacker tool).
// These .abc files are used to create a texture with all the font's glyphs, and also
// extract information on the dimensions of each glyph.
//
// Once created, this class is used to render text in screenspace with the following
// function:
//    DrawText( fScreenSpaceX, fScreenSpaceY, dwTextColor, strText, dwFlags );
//
// For performance, you should batch multiple DrawText calls together between Begin()
// and End() calls, as in the following example:
//    pFont->Begin();
//    pFont->DrawText( ... );
//    pFont->DrawText( ... );
//    pFont->DrawText( ... );
//    pFont->End();
//
// Font files may have embedded, artistically-colored custom glyphs, such as wingdings
// and gamepad buttons. The default font(s) used by the samples use many such custom
// glyphs. For convenience, constants have been defined to reference these glyphs in a
// string, such as:
//    pFont->DrawText( L"Press " GLYPH_A_BUTTON " to continue." );
//
// The size (extent) of the text can be computed with the following function:
//    GetTextExtent( strText, pfReturnedWidth, pfReturnedHeight, bUseFirstLineOnly );
//
// Finally, the font class can create a texture to hold rendered text, which is useful
// for static text that must be rendered for many frames, or can even be used within a
// 3D scene. (For instance, for a player's name on a jersey.) Use the following function
// for this:
//    CreateTexture( strText, dwBackColor, dwTextColor, d3dTextureFormat );
//
// See the XDK docs for more information.
//
// Xbox Advanced Technology Group.
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#pragma once
#ifndef ATGFONT_H
#define ATGFONT_H

#ifndef ATGRESOURCE_H
#include "AtgResource.h"
#endif

namespace ATG
{

//--------------------------------------------------------------------------------------
// Flags for the Font::DrawText() function (Or them together to combine features)
//--------------------------------------------------------------------------------------
#define ATGFONT_LEFT       0x00000000
#define ATGFONT_RIGHT      0x00000001
#define ATGFONT_CENTER_X   0x00000002
#define ATGFONT_CENTER_Y   0x00000004
#define ATGFONT_TRUNCATED  0x00000008


//--------------------------------------------------------------------------------------
// Name: GLYPH_ATTR
// Desc: Structure to hold information about one glyph (font character image)
//--------------------------------------------------------------------------------------
typedef struct GLYPH_ATTR
{
    WORD tu1, tv1, tu2, tv2;    // Texture coordinates for the image
    SHORT wOffset;              // Pixel offset for glyph start
    SHORT wWidth;               // Pixel width of the glyph
    SHORT wAdvance;             // Pixels to advance after the glyph
    WORD wMask;                 // Channel mask
} GLYPH_ATTR;


//--------------------------------------------------------------------------------------
// Name: SavedStates
// Desc: List of states to save.  We use an enum so that the list can evolve over time
//          without worrying about re-ordering, inserting, or removing saved states.
//--------------------------------------------------------------------------------------
enum SavedStates
{
    SAVEDSTATE_D3DRS_ALPHABLENDENABLE,
    SAVEDSTATE_D3DRS_SRCBLEND,
    SAVEDSTATE_D3DRS_DESTBLEND,
    SAVEDSTATE_D3DRS_BLENDOP,
    SAVEDSTATE_D3DRS_ALPHATESTENABLE,
    SAVEDSTATE_D3DRS_ALPHAREF,
    SAVEDSTATE_D3DRS_ALPHAFUNC,
    SAVEDSTATE_D3DRS_FILLMODE,
    SAVEDSTATE_D3DRS_CULLMODE,
    SAVEDSTATE_D3DRS_ZENABLE,
    SAVEDSTATE_D3DRS_STENCILENABLE,
    SAVEDSTATE_D3DRS_VIEWPORTENABLE,
    SAVEDSTATE_D3DSAMP_MINFILTER,
    SAVEDSTATE_D3DSAMP_MAGFILTER,
    SAVEDSTATE_D3DSAMP_ADDRESSU,
    SAVEDSTATE_D3DSAMP_ADDRESSV,

    SAVEDSTATE_COUNT
};

//--------------------------------------------------------------------------------------
// Name: Font
// Desc: Class to implement texture-based font rendering. A .tga image file of the
//       pre-rendered font is used to create the texture. A .abc file contains info for
//       spacing the font characters (aka glyphs).
//--------------------------------------------------------------------------------------
class Font
{
public:
    PackedResource m_xprResource;

    // Font vertical dimensions taken from the font file
    FLOAT m_fFontHeight;        // Height of the font strike in pixels
    FLOAT m_fFontTopPadding;    // Padding above the strike zone
    FLOAT m_fFontBottomPadding; // Padding below the strike zone
    FLOAT m_fFontYAdvance;      // Number of pixels to move the cursor for a line feed

    FLOAT m_fXScaleFactor;      // Scaling constants
    FLOAT m_fYScaleFactor;
    FLOAT m_fSlantFactor;       // For italics
    DOUBLE m_dRotCos;           // Precalculated sine and cosine for italic like rotation
    DOUBLE m_dRotSin;

    D3DRECT m_rcWindow;         // Bounds rect if the text window, modify via accessors only!
    FLOAT m_fCursorX;           // Current text cursor
    FLOAT m_fCursorY;

    // Translator table for supporting unicode ranges
    DWORD m_cMaxGlyph;          // Number of entries in the translator table
    WCHAR* m_TranslatorTable;   // ASCII to glyph lookup table

    // Glyph data for the font
    DWORD m_dwNumGlyphs;        // Number of valid glyphs
    const GLYPH_ATTR* m_Glyphs; // Array of glyphs

    // D3D rendering objects
    D3DTexture* m_pFontTexture;

    // Saved state for rendering (if not using a pure device)
    DWORD m_dwSavedState[ SAVEDSTATE_COUNT ];
    DWORD m_dwNestedBeginCount;
    BOOL m_bSaveState;

    BOOL m_bRotate;


public:
    // Accessor functions
    inline D3DTexture* GetTexture() const
    {
        return m_pFontTexture;
    }
    inline FLOAT GetFontHeight() const
    {
        return m_fFontYAdvance;
    }
    inline VOID SetSlantFactor( FLOAT fSlantFactor )
    {
        m_fSlantFactor = fSlantFactor;
    }

    inline VOID SetScaleFactors( FLOAT fXScaleFactor, FLOAT fYScaleFactor )
    {
        m_fXScaleFactor = fXScaleFactor;
        m_fYScaleFactor = fYScaleFactor;
    }

public:
    Font();
    ~Font();

    // Functions to create and destroy the internal objects
    HRESULT Create( const CHAR* strFontFileName );
    HRESULT Create( D3DTexture* pFontTexture, const VOID* pFontData );
    VOID    Destroy();

    // Returns the dimensions of a text string
    VOID    GetTextExtent( const WCHAR* strText, FLOAT* pWidth,
                           FLOAT* pHeight, BOOL bFirstLineOnly=FALSE ) const;
    FLOAT   GetTextWidth( const WCHAR* strText ) const;

    VOID    SetWindow(const D3DRECT &rcWindow );
    VOID    SetWindow( LONG x1, LONG y1, LONG x2, LONG y2 );
    VOID    GetWindow(D3DRECT &rcWindow) const;
    VOID    SetCursorPosition( FLOAT fCursorX, FLOAT fCursorY );
    VOID    SetRotationFactor( FLOAT fRotationFactor );

    // Function to create a texture containing rendered text
    D3DTexture* CreateTexture( const WCHAR* strText,
                               D3DCOLOR dwBackgroundColor = 0x00000000,
                               D3DCOLOR dwTextColor = 0xffffffff,
                               D3DFORMAT d3dFormat = D3DFMT_A8R8G8B8 );

    // Public calls to render text. Callers can simply call DrawText(), but for
    // performance, they should batch multiple calls together, bracketed by calls to
    // Begin() and End().
    VOID    Begin();
    VOID    DrawText( DWORD dwColor, const WCHAR* strText, DWORD dwFlags=0L,
                      FLOAT fMaxPixelWidth = 0.0f );
    VOID    DrawText( FLOAT sx, FLOAT sy, DWORD dwColor, const WCHAR* strText,
                      DWORD dwFlags=0L, FLOAT fMaxPixelWidth = 0.0f );
    VOID    End();

private:
    // Internal helper functions
    HRESULT CreateFontShaders();
    VOID ReleaseFontShaders();
    VOID RotatePoint( FLOAT* X, FLOAT* Y, DOUBLE OriginX, DOUBLE OriginY ) const;
};


//--------------------------------------------------------------------------------------
// Defines for special characters. Note this depends on the font used, but all samples
// are coded to use the same basic font
//--------------------------------------------------------------------------------------
#define GLYPH_A_BUTTON      L"\400"
#define GLYPH_B_BUTTON      L"\401"
#define GLYPH_X_BUTTON      L"\402"
#define GLYPH_Y_BUTTON      L"\403"
#define GLYPH_WHITE_BUTTON  L"\404"
#define GLYPH_BLACK_BUTTON  L"\405"
#define GLYPH_LEFT_BUTTON   L"\406"
#define GLYPH_RIGHT_BUTTON  L"\407"
#define GLYPH_START_BUTTON  L"\410\411"
#define GLYPH_BACK_BUTTON   L"\412\413"

#define GLYPH_LEFT_HAND     L"\414"
#define GLYPH_RIGHT_HAND    L"\415"
#define GLYPH_UP_HAND       L"\416"
#define GLYPH_DOWN_HAND     L"\417"

#define GLYPH_BULLET        L"\500"
#define GLYPH_STAR_1        L"\501"
#define GLYPH_STAR_2        L"\502"
#define GLYPH_STAR_3        L"\503"
#define GLYPH_STAR_4        L"\504"
#define GLYPH_STAR_5        L"\505"

#define GLYPH_BIG_X         L"\506"
#define GLYPH_HAND          L"\507"
#define GLYPH_CHECK_MARK    L"\510"
#define GLYPH_X_MARK        L"\511"
#define GLYPH_SKULL         L"\512"

#define GLYPH_LEFT_TICK     L"\514"
#define GLYPH_RIGHT_TICK    L"\515"
#define GLYPH_UP_TICK       L"\516"
#define GLYPH_DOWN_TICK     L"\517"

#define GLYPH_HOLLOW_CIRCLE L"\600"
#define GLYPH_FILLED_CIRCLE L"\601"

#define GLYPH_LR_ARROW      L"\612"
#define GLYPH_UD_ARROW      L"\613"
#define GLYPH_LEFT_ARROW    L"\614"
#define GLYPH_RIGHT_ARROW   L"\615"
#define GLYPH_UP_ARROW      L"\616"
#define GLYPH_DOWN_ARROW    L"\617"

} // namespace ATG

#endif // ATGFONT_H
