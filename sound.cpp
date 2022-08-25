/***************************************************************************/
/*                                                                         */
/* FileName: sound.cpp                      ***  **  ~~                    */
/*                                          *** * *~                       */
/* Details: Sound! (prt9)                   ****  *    ~~                  */
/*                                          ***   * ~                      */
/* Author: Ben_3D & Wishi                   ****  *  ~~~                   */
/*                                          *** * *   ~~~                  */
/* URL: www.xfactordev.net                  ***  ** ~~~                    */
/*                                                                         */
/***************************************************************************/

#include "StdAfx.h"
#include "sound.h"


/***************************************************************************/
/*                                                                         */
/*  CSound Instructions                                                    */
/*                                                                         */
/***************************************************************************/
//                                                                         //
// How the CSound Class works:                                             //
// Well first you have to initilise DirectX, this can be done in the       //
// graphics stage, e.g. "Direct3DCreate8(D3D_SDK_VERSION);", this is so    //
// that we can use the directX components.                                 //
//                                                                         //
// So you can create as many CSound objects and you like, like this:       //
// CSound Madonna;                                                         //
// CSound MySong;                                                          //
// CSound GameOverTune;                                                    //
//                                                                         //
// Then in the inilisation stage you call the member functions to load,    //
// your tune in                                                            //
// e.g.  GameOverTune.Create("D:\\chomp.wav");                             //
//                                                                         //
// Now once you've loaded your tune in...you can play it simply by calling //
// the member function playsound....                                       //
// This will play the tune until the end....you can add to this simple     //
// class to include 'stop()'...'pause()'...member functions possibly.      //
//                                                                         //
//                                                                         //
// So whenever you want to play the tune, just call the member function.   //
//                                                                         //
// GameOverTune.playsound();                                               //
//                                                                         //
// Simple as that :)                                                       //
//                                                                         //
/***************************************************************************/


// Static members of the class... as with directx sound, you only need to 
// initilise them once....so you don't need seperate copies for all your
// classes, instead you can share them, by making them static....so a single
// instance of them is shared between all our sound classes.

IDirectMusicLoader8*		CSound::m_pLoader		= NULL;
IDirectMusicPerformance8*	CSound::m_pPerformance	= NULL;

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// Create(..) - The name speaks for itself.                                //
// We check if our dx soudn have been initilised...if now we call the      //
// sound setup and setup our seound....only need to do it once.            //
// Them we load our sound file.                                            //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

void CSound::Create(char* filename) //e.g. "D:\\chomp.wav"
{
	
	if( (m_pLoader == NULL) && (m_pPerformance == NULL))
	{
		SetupSound();
	}

	LoadSound(filename);
}

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// LoadSound(..) - another description function name :)  We load our sound //
// into our m_pSoundSegment,....which is what holds our .wav.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

void CSound::LoadSound(char* filename) //e.g. "D:\\chomp.wav"
{	
	m_pLoader->LoadObjectFromFile( CLSID_DirectMusicSegment, IID_IDirectMusicSegment8,
                                  filename, (VOID**)&m_pSoundSegment);
}

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// Using our m_pSoundSegment, which was loaded using LoadSound(..)...we    //
// then play it using our m_pPerformance dx interface.                     //
//                                                                         //
// You can change parameters to this PlaySegmentEX(..) if you want to      //
// repeat you rsound etc.                                                  //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
void CSound::playsound()
{
	m_pPerformance->PlaySegmentEx( m_pSoundSegment, NULL, NULL, DMUS_SEGF_SECONDARY, 
		                                   0, NULL, NULL, NULL );
}

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// If you want to know this code...you'll have to go over it slowly...     //
// its purpose it to inilize or dx sound.                                  //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

void CSound::SetupSound()
{
	// Initialize DMusic

    IDirectMusicHeap* pNormalHeap;
    DirectMusicCreateDefaultHeap( &pNormalHeap );

    IDirectMusicHeap* pPhysicalHeap;
    DirectMusicCreateDefaultPhysicalHeap( &pPhysicalHeap );

    DirectMusicInitializeEx( pNormalHeap, pPhysicalHeap, &DirectMusicDefaultFactory );

    pNormalHeap->Release();
    pPhysicalHeap->Release();
	

    // Create loader object
    DirectMusicCreateInstance( CLSID_DirectMusicLoader, NULL,
                               IID_IDirectMusicLoader8, (VOID**)&m_pLoader );

    // Create performance object
    DirectMusicCreateInstance( CLSID_DirectMusicPerformance, NULL,
                               IID_IDirectMusicPerformance8, (VOID**)&m_pPerformance );

    
	 m_pPerformance->InitAudioX( DMUS_INITAUDIO_NOTHREADS, 64, 128, 0 );



}


/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// Tidy up...                                                              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

void CSound::Release()
{
	m_pSoundSegment->Release();
	
}

