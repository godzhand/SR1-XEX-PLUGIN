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
/*                                                                         */
/* Details: Class to encapsulate the sound, includeds the                  */
/* initialisation and loading of sounds                                    */
/*                                                                         */
/***************************************************************************/
#pragma once
#include <stdio.h>


#include <xtl.h>
#include <dmusici.h>

/***************************************************************************/
/*                                                                         */
/* CSound Class definition                                                 */
/*                                                                         */
/***************************************************************************/

class CSound
{
protected:
	IDirectMusicSegment8*     m_pSoundSegment;

public:
	void Create(char* filename);  //e.g. "D:\\chomp.wav" 

	void playsound();

	void Release();

protected:
	static IDirectMusicLoader8*      m_pLoader;
	static IDirectMusicPerformance8* m_pPerformance;

	void LoadSound(char* filename);

	void SetupSound();
};

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




