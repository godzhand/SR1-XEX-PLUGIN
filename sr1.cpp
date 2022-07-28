// sr1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>
#include <cassert>
#include <fstream>
#include "global.h"
#include "Player.h"
#include <d3d9.h> //Application entry point
#include <iostream>
#include "wave.h"
#include "Util.h"
#include "XMAHardwareAbstraction.h"
#include <xact3.h>
#include <ctype.h>
#include <winsockx.h>
#include <vector>
#include "MD5X.h"
using namespace std;
#define VERBOSE_DEBUG
#ifdef _XBOX 
#define fourccRIFF 'RIFF'
#define fourccDATA 'data'
#define fourccFMT 'fmt '
#define fourccWAVE 'WAVE'
#define fourccXWMA 'XWMA'
#define fourccDPDS 'dpds'
#endif

#ifndef _XBOX
#define fourccRIFF 'FFIR'
#define fourccDATA 'atad'
#define fourccFMT ' tmf'
#define fourccWAVE 'EVAW'
#define fourccXWMA 'AMWX'
#define fourccDPDS 'sdpd'
#endif

extern SOCKET Sock;
BOOL bbInitialized = false;
DWORD (__cdecl *XamGetCurrentTitleID)() = (DWORD (__cdecl *)())ResolveFunction("xam.xex", 0x1CF);
typedef void(__cdecl* ConsoleCommandT)(const char command[]);
ConsoleCommandT ConsoleCommand = (ConsoleCommandT)0x8263CB10;
VOID PlayPCM( IXAudio2* pXaudio2, const char* szFilename );
VOID PlayXMA2( IXAudio2* pXaudio2, const char* szFilename );
bool playerSP = false;
bool player1ONLINE = false;
bool player2ONLINE = false;
bool player3ONLINE = false;
bool player4ONLINE = false;
bool player5ONLINE = false;
bool player6ONLINE = false;
bool player7ONLINE = false;
bool player8ONLINE = false;
bool player9ONLINE = false;
bool player10ONLINE = false;
bool player11ONLINE = false;
bool player12ONLINE = false;
bool player1isinPIT = false;
N::Player p1;
N::Player p2;
N::Player p3;
N::Player p4;
N::Player p5;
N::Player p6;
N::Player p7;
N::Player p8;
N::Player p9;
N::Player p10;
N::Player p11;
N::Player p12;
N::Player sp;
char* position;
float positionz;
bool debug2file = true;
bool debug2screen = false;
bool seePos = true;
bool seePlayer1State = false;
bool enable_camera_first_mode = true;
// console & offset settings
bool NathanielHack = true;
bool rainbowGunfire = false;
bool smooth_camera = false;
bool show_hud = true;
bool hide_player_info = false;
bool beer_muscles = false;
bool force_host = false;
bool shadows = true;
bool lights = true;
bool allow_single_player = false;
bool recoil = true;
bool turret_mode = false;
bool unlimited_ammo = false;
bool two_player_ranked = true;
bool Black_Sprint = false;
bool unlimited_Sprint = false;
bool give_achievements = false;
bool make_Pit_Invulnerable = false;
std::string WelcomeMSG = "Welcome To Hell!";
bool SwitchGamertag = false;
std::string defaultgamertag = "test";
bool ChangeWeather = false;
int DefaultWeather = 3; // 1-6
bool custom_Jump_height = true;
float jump_height = 3.0;
bool custom_gravity = true;
std::string gravity = "0.5";
bool custom_saturation = false;
float saturation = -2.0;
bool allow_crouch_walk = false;
float crouch_walk = 0.2;
bool char_in_car_height = true;
float char_height = 1.0;
bool custom_char_ambient = true;
std::string dchar_ambient_r = "20";
std::string dchar_ambient_g = "0";
std::string dchar_ambient_b = "0";
bool custom_level_ambient = true;
std::string dlevel_ambient_r = "40";
std::string dlevel_ambient_g = "40";
std::string dlevel_ambient_b = "40";
bool afk_macro = false; 
std::string AFKMSG = "we will be back after these messages!";
bool master_door_lock = false;
bool level_ambient_door = true;
bool char_ambient_door = true;
bool flash_console_window = false;
bool keep_console_open = false;
bool max_players_2 = true;
bool write_over_console = true;
int WeaponsSpawn = 1;
std::string jump_heightStr = "3.0";
bool ascii_art = false;
bool Connect_to_IRC7 = false;
bool Connect_to_Twitch = true;
bool ACCEPT_COMMANDS_IRC = true;
bool ONJOIN_COMMANDS = false;
bool IRC_SHOW_CONNECT_RAWS = false;
bool ConsoleWindowOpen = false;
bool SEND_INPUT_TO_CHANNEL = true;
std::string gamertag = "lol"; 
IXAudio2* pXAudio2Engine = NULL;
HANDLE KeyHandle;
//SOCKET currentSock;
HANDLE moduleHandle2;
//--------------------------------------------------------------------------------------
// Constants
//--------------------------------------------------------------------------------------
const int   XMA_BUFFER_SIZE = 131072;      // number of bytes to submit to XMA at a time.
// It's possible to submit up to 8MB at a time,
// and when you're submitting in-memory buffers
// you should generally submit the whole thing
// at once. This sample submits smaller buffers
// in order to show how to submit data that's
// broken up into little pieces--for instance,
// data that's being streamed from disk.

const int   SAMPLE_BUFFER_SIZE = 1024;    // number of samples in XMA output buffer

//--------------------------------------------------------------------------------------
// CreatePCMOutputVoicesForXMAFile
//
// In order to hear the output from the XMA decoder we need to pass it to XAudio2.
// Since the XMA decoder output is 16-bit PCM data, we can pass it directly
// to an XAudio2 PCM voice for output. This function creates a set of PCM voices,
// one for each XMA stream, and sets them up to output surround sound. The demo
// will pass buffers of decoded XMA sound to these voices.
//
// NOTE: this function is for demo purposes only. If the decoded data will not be
//       processed further before being sent to XAudio2, it is simpler and more
//       efficient to feed the original XMA data to XAudio2 directly.
//--------------------------------------------------------------------------------------


void Reset()
{
	bbInitialized = false;
}
//if (keyStroke.Flags &= XINPUT_KEYSTROKE_SHIFT) {
//				NotifyPopup(L"Your hitting the shift key");
//			}
void SendSockInfo2(SOCKET s) {
	currentSock = s;
}
int instr2(string istring, string tofind){
	if (istring.find(tofind)!=istring.npos){
		return istring.find(tofind)+1;
	}else{
		return 0;
	}
}
int Instr2( char *SearchString, char *SearchTerm )
{
	int stringSize = strlen( SearchString );
	int termSize = strlen( SearchTerm );

	if ( termSize > stringSize )
	{
		return 0;
	}

	int numberFound = 0;
	const char* subString = NULL;

	for ( int i = 0 ; i <= stringSize - termSize; ++i )
	{
		if ( strncmp( &SearchString[ i ], SearchTerm, termSize ) == 0 )
		{
			i += termSize;    // Skip past this term.
			++numberFound;
		}
	}

	return numberFound;
}
void ReplaceStringInPlace2(std::string& subject, const std::string& search,
	const std::string& replace) {
		size_t pos = 0;
		while ((pos = subject.find(search, pos)) != std::string::npos) {
			subject.replace(pos, search.length(), replace);
			pos += replace.length();
		}
}

static void removeTrailingCharacters2(std::string &str, const char charToRemove) {
	str.erase (str.find_last_not_of(charToRemove) + 1, std::string::npos );
}
string Mid2(string& str, int pos1, int pos2)
{
	int i;
	string temp = "";
	for(i = pos1; i < pos2; i++)
	{
		temp += str[i];
	}

	return temp;
}
std::string ProcessIRCMessages2(string Message) {
	stringstream ssx(Message);
	string sx;
	int xUpx = 1;
	vector <string> tokens;
	while (getline(ssx, sx, ' ')) {
		tokens.push_back(sx);
		xUpx++;
	}
	if (tokens[1] == "004" || tokens[1] == "251"  || tokens[1] == "252"  || tokens[1] == "253"  || tokens[1] == "254"  || tokens[1] == "255"  || tokens[1] == "265"  || tokens[1] == "266" || tokens[1] == "422") { 
		if (IRC_SHOW_CONNECT_RAWS == true) { 
			string NewMessage;
			for(int i = 3; i < tokens.size(); i++)  {
				NewMessage += " ";
				NewMessage += tokens[i];
			}
			NewMessage.erase(1,1);
			return NewMessage;
		}
		else {
			string NewMessage(" ");
			return NewMessage;
		}
	}
	else if (tokens[1] == "MODE") {
		string NewMessage;
		NewMessage = "* ";
		string splitName = tokens[0];
		stringstream splitit(splitName);
		string splitTok;
		int xUpx2 = 1;
		vector <string> SplitNameTokens;
		while (getline(splitit, splitTok,'!')) {
			SplitNameTokens.push_back(splitTok);
			xUpx2++;
		}

		NewMessage += SplitNameTokens[0];

		NewMessage = NewMessage.erase(2,1);
		NewMessage += " sets mode";
		for(int i = 3; i < tokens.size(); i++)  { 
			NewMessage += " ";
			NewMessage += tokens[i];

		}
		return NewMessage;
	}
	else if (tokens[1] == "353") {
		string NewMessage(" ");
		return NewMessage;
	}
	else if (tokens[1] == "366") { 
		string NewMessage(" ");
		return NewMessage;
	}
	else if (tokens[1] == "JOIN") {
		string NewMessage;
		NewMessage = "* ";
		string splitName = tokens[0];
		stringstream splitit(splitName);
		string splitTok;
		int xUpx2 = 1;
		vector <string> SplitNameTokens;
		while (getline(splitit, splitTok,'!')) {
			SplitNameTokens.push_back(splitTok);
			xUpx2++;
		}

		NewMessage += SplitNameTokens[0];

		NewMessage = NewMessage.erase(2,1);
		NewMessage += " Joined the channel";
		return NewMessage;

	}
	//:IRC7 332 >null2 %#Multiplayer\bPre-Game\bLobbby :Welcome to Stilwater
	else if (tokens[1] == "332") { 
		string NewMessage;
		NewMessage = "* Topic is '";
		for(int i = 4; i < tokens.size(); i++)  {
			if (i == 4) {
				string TopicCutoff = tokens[i];
				NewMessage += TopicCutoff.erase(0,1);
			}
			else {
				NewMessage += tokens[i];
			}
			if (i != tokens.size()-1) { 
				NewMessage += " ";
			}
		}
		NewMessage += "'";
		return NewMessage;
	}
	else if (tokens[1] == "PRIVMSG") {
		string NewMessage;
		NewMessage = "<";
		string splitName = tokens[0];
		stringstream splitit(splitName);
		string splitTok;
		int xUpx2 = 1;
		vector <string> SplitNameTokens;
		while (getline(splitit, splitTok,'!')) {
			SplitNameTokens.push_back(splitTok);
			xUpx2++;
		}

		NewMessage += SplitNameTokens[0];

		NewMessage = NewMessage.erase(1,1);
		NewMessage += ">";
		for(int i = 3; i < tokens.size(); i++)  { 
			NewMessage += " ";
			if (i == 3) {
				string MessageString;
				MessageString = tokens[i];
				MessageString.erase(0,1);
				NewMessage += MessageString;
			}
			else {
				NewMessage += tokens[i];
			}
		}
		return NewMessage;
	}
	else {
		return Message;
	}
}
string hexToASCII3(string hex)
{
	// initialize the ASCII code string as empty.
	string ascii = "";
	for (size_t i = 0; i < hex.length(); i += 2)
	{
		// extract two characters from hex string
		string part = hex.substr(i, 2);

		// change it into base 16 and
		// typecast as the character
		char ch = stoul(part, nullptr, 16);

		// add this char to final ASCII string
		ascii += ch;
	}
	return ascii;
}
string hexToASCII2(int hex1)
{
	// initialize the ASCII code string as empty.
	string ascii = "";
	stringstream ss;
	ss << hex1;
	string hex = ss.str();
	for (size_t i = 0; i < hex.length(); i += 2)
	{
		// extract two characters from hex string
		string part = hex.substr(i, 2);

		// change it into base 16 and
		// typecast as the character
		char ch = stoul(part, nullptr, 16);

		// add this char to final ASCII string
		ascii += ch;
	}
	return ascii;
}
string DecToHex(int p_intValue)
{
	char *l_pCharRes = new (char);
	sprintf(l_pCharRes, "%X", p_intValue);
	int l_intResult = stoi(l_pCharRes);
	return hexToASCII2(l_intResult);
}
void ExternalMsg(char* str){
	std::string sentstr(str);
	char fC = sentstr[0];
	if (fC == '/') {
			if (sentstr.length() >= 2) {
		sentstr.erase(0,1);
		if (sentstr[0] == '/') {
			if (sentstr.length() >= 2) {
			sentstr.erase(0,1);
			stringstream ss(sentstr);
			string s;
			int xUp = 1;
			stringstream ssx(sentstr);
			string sx;
			int xUpx = 1;
			vector <string> tokens;
			while (getline(ss, sx, ' ')) {
				tokens.push_back(sx);
				xUpx++;
			}
			if (tokens[0] == "msg") {
				if (xUpx >= 4) {
					std::string bar = tokens[0];
					size_t pos = sentstr.find(bar);
					size_t len = bar.length();
					sentstr.replace(pos, len, "PRIVMSG");
bar = tokens[2];
					size_t posx = sentstr.find(bar);
					sentstr.insert(posx,":");
					int xS = 0;
					bool found_buffer = false;
					while (0x83F6FF98+xS <= 0x83F7AE4F) {
						if (reinterpret_cast<char*>(0x83F6FF98+xS)[0] == 'U' && reinterpret_cast<char*>(0x83F6FF98+xS+17)[0] == 'f') {  
							found_buffer = true;
							break;
						} 
						else {
							xS=xS+0x84;
						}
					}
					if (found_buffer == false) {
						std::string wsacon("fill_console_buffer");
						const char* Nwsacon = wsacon.c_str();
						ConsoleCommand(Nwsacon);
					}
					int xA = 0;
					while (1) {
						if (reinterpret_cast<char*>(0x83F6FF98+xA)[0] == 'U' && reinterpret_cast<char*>(0x83F6FF98+xA+17)[0] == 'f') {  
							size_t pos = sentstr.find(":");
							string NewMessage = "<>" + gamertag + "> ";
							NewMessage += sentstr.substr(pos+1);
							//PRIVMSG %#Channel :MESSAGE HERE
							const char *cstr = NewMessage.c_str();
							strcpy((char*)0x83F6FF98+xA, cstr);
							break;	
						}
						else {
							xA=xA+0x84;
						}
					}

				}
				ReplaceStringInPlace2(sentstr,"#","#xgodzhand");
			}
			}
		}
		else { 
			stringstream ss(sentstr);
			string s;
			int xUp = 1;
			stringstream ssx1(sentstr);
			string sx1;
			int xUpx1 = 1;
			vector <string> tokens;
			while (getline(ssx1, sx1, ' ')) {
				tokens.push_back(sx1);
				xUpx1++;
			}
			if (tokens[0] == "msg") {
				if (xUpx1 >= 4) {
					std::string bar = tokens[0];
					size_t pos = sentstr.find(bar);
					size_t len = bar.length();
					sentstr.replace(pos, len, "PRIVMSG");
					bar = tokens[2];
					size_t posx = sentstr.find(bar);
					sentstr.insert(posx,":");
					int xS = 0;
					bool found_buffer = false;
					while (0x83F6FF98+xS <= 0x83F7AE4F) {
						if (reinterpret_cast<char*>(0x83F6FF98+xS)[0] == 'U' && reinterpret_cast<char*>(0x83F6FF98+xS+17)[0] == 'f') {  
							found_buffer = true;
							break;
						} 
						else {
							xS=xS+0x84;
						}
					}
					if (found_buffer == false) {
						std::string wsacon("fill_console_buffer");
						const char* Nwsacon = wsacon.c_str();
						ConsoleCommand(Nwsacon);
					}
					int xA = 0;
					while (1) {
						if (reinterpret_cast<char*>(0x83F6FF98+xA)[0] == 'U' && reinterpret_cast<char*>(0x83F6FF98+xA+17)[0] == 'f') {  
							size_t pos = sentstr.find(":");
							string NewMessage = "<>" + gamertag + "> ";
							NewMessage += sentstr.substr(pos+1);
							//PRIVMSG %#Channel :MESSAGE HERE
							const char *cstr = NewMessage.c_str();
							strcpy((char*)0x83F6FF98+xA, cstr);
							break;	
						}
						else {
							xA=xA+0x84;
						}
					}
				}
			}
		}
	}
	}
	else {
							int xS = 0;
					bool found_buffer = false;
					while (0x83F6FF98+xS <= 0x83F7AE4F) {
						if (reinterpret_cast<char*>(0x83F6FF98+xS)[0] == 'U' && reinterpret_cast<char*>(0x83F6FF98+xS+17)[0] == sentstr[0]) {  
							found_buffer = true;
							break;
						} 
						else {
							xS=xS+0x84;
						}
					}
					if (found_buffer == false) {
						std::string wsacon;
						wsacon.push_back(sentstr[0]);
						const char* Nwsacon = wsacon.c_str();
						ConsoleCommand(Nwsacon);
					}
					int xA = 0;
					while (1) {
						if (reinterpret_cast<char*>(0x83F6FF98+xA)[0] == 'U' && reinterpret_cast<char*>(0x83F6FF98+xA+17)[0] == sentstr[0]) {  
							size_t pos = sentstr.find(":");
							string NewMessage = "<>" + gamertag + "> ";
							NewMessage += sentstr.substr(pos+1);
							//PRIVMSG %#Channel :MESSAGE HERE
							const char *cstr = NewMessage.c_str();
							strcpy((char*)0x83F6FF98+xA, cstr);
							break;	
						}
						else {
							xA=xA+0x84;
						}
					}
					sentstr="PRIVMSG #xgodzhand :" + sentstr;
	}
	sentstr+="\r\n";
	std::string wsacon("subtitle_add \"enter!");
	wsacon += "\" 3";
	const char* Nwsacon = wsacon.c_str();
	ConsoleCommand(Nwsacon);

	NetDll_send(XNCALLER_SYSAPP, currentSock, sentstr.c_str(), sentstr.length(), 0);
}
void GetKeys(LPVOID sId) {
	char* keysToEnter = "";
	bool CAPSLOCK = false;
	while (true)
	{
		XINPUT_KEYSTROKE keyStroke;
		XInputGetKeystroke( XUSER_INDEX_ANY, XINPUT_FLAG_KEYBOARD, &keyStroke );
		char KeyPressed = keyStroke.VirtualKey;
		KeyPressed = tolower(KeyPressed);
		CAPSLOCK=false;
		if (keyStroke.Flags & XINPUT_KEYSTROKE_CAPSLOCK)
		{
			KeyPressed = toupper(KeyPressed);
			CAPSLOCK=true;
		}
		if (keyStroke.Flags & XINPUT_KEYSTROKE_SHIFT)
		{
			KeyPressed = toupper(KeyPressed);
			CAPSLOCK=true;
		}
		if(keyStroke.VirtualKey == VK_ESCAPE)  {
			if (keyStroke.Flags &= XINPUT_KEYSTROKE_KEYDOWN | XINPUT_KEYSTROKE_CAPSLOCK | XINPUT_KEYSTROKE_SHIFT)
			{	
				if (*(uint8_t*)(0x835F4C3E) == 0x01) {
					*(uint8_t*)(0x835F4C3E) = 0x00;
				}
				else {
					*(uint8_t*)(0x835F4C3E) = 0x01;

				}
			}
		}
		else if((keyStroke.VirtualKey >= 0x20)  && ( keyStroke.VirtualKey <= 0x5A))
		{
			if (CAPSLOCK==true){
				if (KeyPressed=='1'){
					KeyPressed='!';
				}
				if (KeyPressed=='2'){
					KeyPressed='@';
				}
				if (KeyPressed=='3'){
					KeyPressed='#';
				}
				if (KeyPressed=='4'){
					KeyPressed='$';
				}
				if (KeyPressed=='5'){
					KeyPressed='%';
				}
				if (KeyPressed=='6'){
					KeyPressed='^';
				}
				if (KeyPressed=='7'){
					KeyPressed='&';
				}
				if (KeyPressed=='8'){
					KeyPressed='*';
				}
				if (KeyPressed=='9'){
					KeyPressed='(';
				}
				if (KeyPressed=='0'){
					KeyPressed=')';
				}
			}				
			if (keyStroke.Flags &= XINPUT_KEYSTROKE_KEYDOWN)
			{

				strcat((char*)0x83F6FEF2, &KeyPressed);
			}

		}
		else if((keyStroke.VirtualKey == VK_OEM_1) || ( keyStroke.VirtualKey == VK_OEM_2) || (keyStroke.VirtualKey == VK_OEM_3) || (keyStroke.VirtualKey == VK_OEM_4) || (keyStroke.VirtualKey == VK_OEM_5) || (keyStroke.VirtualKey == VK_OEM_6) || (keyStroke.VirtualKey == VK_OEM_7) || (keyStroke.VirtualKey == VK_OEM_PLUS) || ( keyStroke.VirtualKey == VK_OEM_MINUS) || ( keyStroke.VirtualKey == VK_OEM_PERIOD) || ( keyStroke.VirtualKey == VK_OEM_COMMA)  )
		{
			if (keyStroke.Flags &= XINPUT_KEYSTROKE_KEYDOWN)
			{
				char ch;
				if (keyStroke.VirtualKey == VK_OEM_1) {
					ch = ';';
					if (CAPSLOCK==true){
						ch = ':';
					}
				}
				if (keyStroke.VirtualKey == VK_OEM_2) {
					ch = '/';
					if (CAPSLOCK==true){
						ch = '?';
					}
				}
				if (keyStroke.VirtualKey == VK_OEM_3) {
					ch = '`';
					if (CAPSLOCK==true){
						ch = '~';
					}
				}
				if (keyStroke.VirtualKey == VK_OEM_4) {
					ch = '[';
					if (CAPSLOCK==true){
						ch = '{';
					}
				}
				if (keyStroke.VirtualKey == VK_OEM_5) {
					ch = '\\';
					if (CAPSLOCK==true){
						ch = '|';
					}
				}
				if (keyStroke.VirtualKey == VK_OEM_6) {
					ch = ']';
					if (CAPSLOCK==true){
						ch = '}';
					}
				}
				if (keyStroke.VirtualKey == VK_OEM_PLUS) {
					ch = '=';
					if (CAPSLOCK==true){
						ch = '+';
					}
				}
				if (keyStroke.VirtualKey == VK_OEM_MINUS) {
					ch = '-';
					if (CAPSLOCK==true){
						ch = '_';
					}
				}
				if (keyStroke.VirtualKey == VK_OEM_PERIOD) {
					ch = '.';
					if (CAPSLOCK==true){
						ch = '>';
					}
				}
				if (keyStroke.VirtualKey == VK_OEM_COMMA) {
					ch = ',';
					if (CAPSLOCK==true){
						ch = '<';
					}
				}
				strcat((char*)0x83F6FEF2, &ch);
			}
		}
		if( ( keyStroke.VirtualKey == VK_RETURN))
		{
			if (keyStroke.Flags &= XINPUT_KEYSTROKE_KEYDOWN)

			{
				char* str = (char*)0x83F6FEF2;
				if (str[0] != '/') {
					ConsoleCommand(str);
				}

				if ((str[0] == '/') || (SEND_INPUT_TO_CHANNEL==true)) {
					ExternalMsg(str);
					//p1.ExternalMsg(str);
				}
				string empty = "";
				const char *emptyc = empty.c_str();
				strcpy((char*)0x83F6FEF2, emptyc);
				//p1.ExternalMsg(str);
				}
		}
		if( (keyStroke.VirtualKey == 0x08 )  && (keyStroke.Flags & XINPUT_KEYSTROKE_KEYDOWN) ) {
			char* KeyedChars = (char*)0x83F6FEF2;
			std::string KeyedStr(KeyedChars);
			if (KeyedStr.size () > 0)  KeyedStr.resize (KeyedStr.size () - 1);
			const char *cstr = KeyedStr.c_str();
			strcpy((char*)0x83F6FEF2, cstr);
		}
	}
}

//--------------------------------------------------------------------------------------
// Name: XACTNotificationCallback()
// Desc: Received notifications from the XACT engine.  Assume that the pvContext
//         is an event handle which is signaled.
//--------------------------------------------------------------------------------------
void WINAPI XACTNotificationCallback( const XACT_NOTIFICATION* pNotification )
{
	if( ( NULL != pNotification ) && ( NULL != pNotification->pvContext ) )
	{
		SetEvent( ( HANDLE )pNotification->pvContext );
	}
}
//--------------------------------------------------------------------------------------
// Name: PlayXMA2
// Desc: Plays an .XMA2 wave and blocks until the wave finishes playing
//--------------------------------------------------------------------------------------
IXAudio2SourceVoice** CreatePCMOutputVoicesForXMAFile( const XMA2WAVEFORMATEX& SourceFormat)
{
	HRESULT hr = S_OK;

	WORD nNumStreams = SourceFormat.NumStreams;

	//Create the default mastering voice
	IXAudio2MasteringVoice* pMasteringVoice = 0;
	if( SUCCEEDED( hr = pXAudio2Engine->CreateMasteringVoice(&pMasteringVoice))) {
		NotifyPopup(L"Success creating a Mastering Voice");
	}
	// ATG::FatalError( "Error %#X calling CreateMasteringVoice\n", hr );


	IXAudio2SourceVoice** pSourceVoices = new IXAudio2SourceVoice*[ nNumStreams ];

	//
	// Create a source voice for each XMA stream
	// NOTE: It's also possible to create one multichannel voice
	// and manually interleave the XMA streams before handing them
	// to XAudio2. The method shown here is the simplest way to
	// get this functionality, not necessarily the best.
	//
	for( WORD i = 0; i < nNumStreams; ++i )
	{
		WORD nChannelCount = 2;

		// Create the channel mapping matrix.
		// In this sample, there cannot be more than 6 destination channels
		// and two source channels:
		float fLevelMatrix[6 * 2] = {0};

		// Set the first and second channel mapping to the appropriate destination:
		// [SourceChannelCount * (ChannelsPerStream * StreamIndex + ChannelIndex) + ChannelIndex]
		fLevelMatrix[2*(2*i+0)+0] = 1.0f;
		fLevelMatrix[2*(2*i+1)+1] = 1.0f;

		// If channel count is odd, set channel count
		// and level mapping for final stream,
		if ((i == (nNumStreams-1)) && (SourceFormat.wfx.nChannels % 2 == 1))
		{
			nChannelCount = 1;
			fLevelMatrix[2*(2*i+1)+1] = 0.0f;
		}

		WAVEFORMATEX pSourceFormat = {0};
		pSourceFormat.wFormatTag  = WAVE_FORMAT_PCM;
		pSourceFormat.nChannels = nChannelCount;
		pSourceFormat.nSamplesPerSec = SourceFormat.wfx.nSamplesPerSec;
		pSourceFormat.wBitsPerSample = 16;
		pSourceFormat.cbSize = 34;

		// Calculations good for PCM data only:
		pSourceFormat.nBlockAlign = pSourceFormat.nChannels * pSourceFormat.wBitsPerSample / 8;
		pSourceFormat.nAvgBytesPerSec = pSourceFormat.nBlockAlign * pSourceFormat.nSamplesPerSec;

		pSourceVoices[i] = NULL;
		NotifyPopup(L"attempting to create a voice");
		//if( SUCCEEDED( hr = pXAudio2Engine->CreateSourceVoice(&pSourceVoices[i],reinterpret_cast<WAVEFORMATEX *>(&pSourceFormat) ) ) ) {
		//NotifyPopup(L"Successfully created a voice");
		// ATG::FatalError( "Error %#X calling XAudioCreateSourceVoice\n", hr );
		//}


		//pSourceVoices[i]->SetOutputMatrix(NULL, nChannelCount, 6, fLevelMatrix);

	}

	return pSourceVoices;
}
VOID PlayXMA2( IXAudio2* pXAudio2, const char* szFilename )
{
	HRESULT hr = S_OK;
	NotifyPopup(L"Successfully called function PlayXMA2!");
	//
	// Read the wave file
	//

	WAVE::WaveFile WaveFile;
	if( SUCCEEDED( hr = WaveFile.Open( szFilename ) ) ) {
		NotifyPopup(L"Successfully opened wave!");
		//   ATG::FatalError( "Error %#X opening WAV file\n", hr );
		// Read the format header
		WAVEFORMATEXTENSIBLE wfx = {0};
		XMA2WAVEFORMATEX xma2 = {0};
		if( SUCCEEDED( hr = WaveFile.GetFormat( &wfx, &xma2 ) ) ) {
			NotifyPopup(L"Successlly read the format header!");
			//   ATG::FatalError( "Error %#X reading WAV format\n", hr );
			if( wfx.Format.wFormatTag == WAVE_FORMAT_XMA2 ) {
				NotifyPopup(L"format is XMA2!");
				//   ATG::FatalError( "Error - Expected an XMA2 XAudio2 compatible file\n" );
				// Calculate how many bytes and samples are in the wave
				DWORD cbWaveSize = 0;
				WaveFile.GetDuration( &cbWaveSize );

				// Read the sample data into memory (XMA packets must be 2K aligned)

				//BYTE* pbWaveData = ( BYTE* )XPhysicalAlloc( cbWaveSize, MAXULONG_PTR, 0, PAGE_READWRITE | MEM_LARGE_PAGES );
				BYTE* pbWaveData = ( BYTE* )XPhysicalAlloc( cbWaveSize, MAXULONG_PTR, 2048, PAGE_READWRITE );
				if( SUCCEEDED( hr = WaveFile.ReadSample( 0, pbWaveData, cbWaveSize, &cbWaveSize ) ) ) {
					NotifyPopup(L"Successly reading data!");




					// ATG::FatalError( "Error %#X reading WAV data\n", hr );
					//
					// Play the wave using a new XAudio2SourceVoice
					//

					// Create the source voice
					//IXAudio2SourceVoice* pSourceVoice;
					//if( SUCCEEDED( hr = pXAudio2->CreateSourceVoice( &pSourceVoice, ( WAVEFORMATEX* )&xma2 ) ) ) {
					//   ATG::FatalError( "Error %#X creating source voice\n", hr );
					//	NotifyPopup(L"Successly created a source voice!!");
					//				}
				}
			}
		}
	}
	/*
	// submit the wave sample data using an XAUDIO2_BUFFER structure
	XAUDIO2_BUFFER buffer = {0};
	buffer.pAudioData = pbWaveData;
	buffer.Flags = XAUDIO2_END_OF_STREAM;  // tell the source voice not to expect any data after this buffer
	buffer.AudioBytes = cbWaveSize;
	if(SUCCEEDED( hr = pSourceVoice->SubmitSourceBuffer( &buffer ) ) ) {
	//   ATG::FatalError( "Error %#X submitting source buffer\n", hr );
	NotifyPopup(L"Successfully submitted source buffer!");
	hr = pSourceVoice->Start( 0 );

	BOOL isRunning = TRUE;
	while( SUCCEEDED( hr ) && isRunning )
	{
	XAUDIO2_VOICE_STATE state;
	pSourceVoice->GetState( &state, XAUDIO2_VOICE_NOSAMPLESPLAYED );
	isRunning = ( state.BuffersQueued > 0 );

	// Detect reboot keypress
	//       ATG::Input::GetMergedInput();
	}

	pSourceVoice->DestroyVoice();
	XPhysicalFree( pbWaveData );
	}
	}

	}
	}
	}
	}
	*/
}

//--------------------------------------------------------------------------------------
// Name: PlayPCM
// Desc: Plays a wave and blocks until the wave finishes playing
//--------------------------------------------------------------------------------------
VOID PlayPCM( IXAudio2* pXaudio2, const char* szFilename )
{
	HRESULT hr = S_OK;

	//
	// Read the wave file
	//
	WAVE::WaveFile WaveFile;
	if( FAILED( hr = WaveFile.Open( szFilename ) ) ) {
	}

	// Read the format header
	WAVEFORMATEXTENSIBLE wfx = {0};
	if( FAILED( hr = WaveFile.GetFormat( &wfx ) ) ) {

	}
	// Calculate how many bytes and samples are in the wave
	DWORD cbWaveSize = 0;
	WaveFile.GetDuration( &cbWaveSize );

	// Read the sample data into memory
	BYTE* pbWaveData = new BYTE[ cbWaveSize ];
	if( FAILED( hr = WaveFile.ReadSample( 0, pbWaveData, cbWaveSize, &cbWaveSize ) ) ) {
	}

	//
	// Play the wave using a new XAudio2SourceVoice
	//

	// Create the source voice
	IXAudio2SourceVoice* pSourceVoice;
	if( FAILED( hr = pXaudio2->CreateSourceVoice( &pSourceVoice, ( WAVEFORMATEX* )&wfx ) ) ) {
	}

	// Submit the wave sample data using an XAUDIO2_BUFFER structure
	XAUDIO2_BUFFER buffer = {0};
	buffer.pAudioData = pbWaveData;
	buffer.Flags = XAUDIO2_END_OF_STREAM;  // tell the source voice not to expect any data after this buffer
	buffer.AudioBytes = cbWaveSize;

	if( FAILED( hr = pSourceVoice->SubmitSourceBuffer( &buffer ) ) ) {

	}
	hr = pSourceVoice->Start( 0 );

	BOOL isRunning = TRUE;
	while( SUCCEEDED( hr ) && isRunning )
	{
		XAUDIO2_VOICE_STATE state;
		pSourceVoice->GetState( &state, XAUDIO2_VOICE_NOSAMPLESPLAYED );
		isRunning = ( state.BuffersQueued > 0 );
	}

	pSourceVoice->DestroyVoice();
	SAFE_DELETE_ARRAY( pbWaveData );
}
DWORD WINAPI ConnectSock2() {
Restart:
	std::string wsacon("subtitle_add ");
	// string *GTptr = reinterpret_cast<std::string*>(zGT)
	//string GT = *GTptr;
	// wsacon += GT;
	wsacon += " 3";
	SOCKET Sock;
	// Code mod.  allowing user to imput address
	//BYTE IPAddress[0x4] = { 98, 194, 130, 207 }; //Your IP
	BYTE IPAddress[0x4] =  { 34, 231, 248, 251 };
	string nick = "NICK >Somebot"; // NICK raw
	string user = "USER t 0 * :r"; // USER raw
	WORD Port = 6667;
	DWORD SocketError;
	XNetStartupParams xnsp;
	WSADATA WsaData;
	BOOL SockOpt = TRUE;
	DWORD sendRecvSize = 1024;
	sockaddr_in httpServerAdd;
	httpServerAdd.sin_addr.S_un.S_addr = *(PDWORD)IPAddress;
	//httpServerAdd.sin_addr.s_addr = inet_addr("tha-row.net");
	httpServerAdd.sin_port = htons(Port);
	httpServerAdd.sin_family = AF_INET;
	ZeroMemory(&xnsp, sizeof(xnsp));

	// Configure our xnsp variable
	xnsp.cfgSizeOfStruct = sizeof(XNetStartupParams);
	xnsp.cfgFlags = XNET_STARTUP_BYPASS_SECURITY;
	// Safely startup XNet
	if ((SocketError = NetDll_XNetStartup(XNCALLER_SYSAPP, &xnsp)) != S_OK) {

	}

	// Safely startup WSA
	if ((SocketError = NetDll_WSAStartupEx(XNCALLER_SYSAPP, MAKEWORD(2, 2), &WsaData, 2)) != S_OK) {

	}

	// Safely create socket
	Sock = NetDll_socket(XNCALLER_SYSAPP, AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//Sock = NetDll_socket(XNCALLER_SYSAPP, AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//Sock = socket(AF_INET, SOCK_STREAM, 0);
	// Disable network encryption
	if (NetDll_setsockopt(XNCALLER_SYSAPP, Sock, SOL_SOCKET, 0x5801, (PCSTR)&SockOpt, 4) != S_OK) {

	}

	// Configure socket send/recv size
	NetDll_setsockopt(XNCALLER_SYSAPP, Sock, SOL_SOCKET, SO_SNDBUF, (PCSTR)&sendRecvSize, 4);
	NetDll_setsockopt(XNCALLER_SYSAPP, Sock, SOL_SOCKET, SO_RCVBUF, (PCSTR)&sendRecvSize, 4);

	// Create connection timeout
	struct timeval tv;
	tv.tv_sec = 15;
	tv.tv_usec = 0;
	setsockopt(Sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(struct timeval));

	if (NetDll_connect(XNCALLER_SYSAPP, Sock, (struct sockaddr*)&httpServerAdd, sizeof(httpServerAdd)) == SOCKET_ERROR) {
		std::string wsacon("subtitle_add \"fai!");
		wsacon += "\" 3";
		const char* Nwsacon = wsacon.c_str();
		ConsoleCommand(Nwsacon);
	}

	else { 
		int iResult;
		std::string wsacon("subtitle_add \"connected!");
		wsacon += "\" 3";
		const char* Nwsacon = wsacon.c_str();
		ConsoleCommand(Nwsacon);
		///const char* ReturnBuffer;
		string ConIRC = "IRCVERS IRC6 MSN-OCX!2.03.0204.0801 chat.msn.be\r\n";
		//string ConIRC = "NICK " + gamertag + "\r\nUSER " + gamertag + " 0 * :Saints Row Client\r\n";
		//NetDll_send(XNCALLER_SYSAPP, Sock, requestExample, 255, 0);
		int ReadBytes = 0;
		ofstream ircdata;

		//ircdata.open("HDD:\\ircdata.txt");
		char buff[1024];
		NetDll_send(XNCALLER_SYSAPP, Sock, ConIRC.c_str(), ConIRC.length(), 0);
		while (true)
		{
			ZeroMemory(buff, 1024);

			int bytesReceived = NetDll_recv(XNCALLER_SYSAPP,Sock, buff, 1024, 0);
			if (bytesReceived == SOCKET_ERROR)
			{

			}
			if (bytesReceived > 0) {
				std::string Recieved(buff, bytesReceived);
				removeTrailingCharacters2(Recieved, '\n');
				removeTrailingCharacters2(Recieved, '\r');
				removeTrailingCharacters2(Recieved, '\t');
				std::stringstream iss(Recieved);
				while(iss.good())
				{
					std::string SingleLine;
					getline(iss,SingleLine);
					if (!SingleLine.empty()) {
						removeTrailingCharacters2(SingleLine, '\n');
						removeTrailingCharacters2(SingleLine, '\r');
						removeTrailingCharacters2(SingleLine, '\t');
						stringstream ss(SingleLine);
						string s;
						int xUp = 1;
						vector <string> tokens;
						while (getline(ss, s, ' ')) {
							tokens.push_back(s);
							xUp++;
						}
						if (tokens[0] == "PING") { 
							string x = "PONG :IRC7\r\n";
							NetDll_send(XNCALLER_SYSAPP, Sock, x.c_str(), x.length(), 0);
							std::string wsacon("subtitle_add \"PING? PONG!");
							wsacon += "\" 3";
							const char* Nwsacon = wsacon.c_str();
							ConsoleCommand(Nwsacon);
						}
						if (tokens[0] == "AUTH") {
							if (tokens[2] == "S") {
								MD5 md5;
								string ChOK = "AUTH GateKeeper S :GKSSP\\0\\0\\0\x02\\0\\0\\0\x03\\0\\0\\0"; 
								string findstringx = "\x02\\0\\0\\0\x02\\0\\0\\0";
								int findstringn = instr2(SingleLine, findstringx);
								int math = findstringn + findstringx.size();
								string ChOK3 = SingleLine.substr(math-1);
								string ChallengeCode = "edp{}e|wxrdse}}u666666666666666666666666666666666666666666666666" + ChOK3;
								char* cz = const_cast<char*>(ChallengeCode.c_str());
								string g1 = md5.digestString( cz );
								string a1 = hexToASCII3(g1);
								int n = 48;
								char cx = '\\';
								string c2 = hexToASCII3("0f0e1a11170f161d12180e190f17171f") + std::string(n, cx) + a1;
								char* c = const_cast<char*>(c2.c_str());
								string a2 = md5.digestString( c );
								string a3 = hexToASCII3(a2);
								//string ChOK4 = ChOK + a2 + "Sm(" + hexToASCII("e4") + "HS" + hexToASCII("c1") + "M" + hexToASCII("847f8293f98d") + "UC\r\n";

								string ChOK4 = "AUTH GateKeeper S :GKSSP\\0\\0\\0\x02\\0\\0\\0\x03\\0\\0\\0" + a3 + "Sm(" + hexToASCII3("e4") + "HS" + hexToASCII3("c1") + "M" + hexToASCII3("847f8293f98d") + "UC\r\n";
								const char *cstr = ChOK4.c_str();
								//strcpy((char*)0x83F7001C, cstr);
								NetDll_send(XNCALLER_SYSAPP, Sock,ChOK4.c_str(),ChOK4.length(), 0);
							}
							else if (tokens[2] == "*") {
								// message = "USER IRC7 * * :" + Ident + vbCrLf + "Nick >" + Nick + vbCrLf
								string sendinfo = "NICK >" + gamertag + "\r\nUSER " + gamertag + " 0 * :Saints Row Client\r\n";
								NetDll_send(XNCALLER_SYSAPP, Sock,sendinfo.c_str(),sendinfo.length(), 0);
							}
						}
						if (tokens[1] == "422") { 
							SendSockInfo2(Sock);
							string Z = "JOIN %#Multiplayer\\bPre-Game\\bLobbby\r\n";
							NetDll_send(XNCALLER_SYSAPP, Sock, Z.c_str(), Z.length(), 0);
						}
						else if (tokens[1] == "800") {
							string AUTH1 = "AUTH GateKeeper I :GKSSP\\0\x03r\x02\\0\\0\\0\x01\\0\\0\\0\r\n";
							NetDll_send(XNCALLER_SYSAPP, Sock,AUTH1.c_str(), AUTH1.length(), 0);
						}
						else if (tokens[1] == "910") { 
							NetDll_closesocket(XNCALLER_SYSAPP, Sock);
							goto Restart;
						}
						else if (tokens[1] == "PRIVMSG") {
							if (tokens[3] == ":!cmd") { 
								if (ACCEPT_COMMANDS_IRC == true) { 

									std::string wsacon(tokens[4]);
									for(int i = 5; i < tokens.size(); i++)  {
										wsacon += " ";
										wsacon+= tokens[i];
									}
									/*  if (i != tokens.size()) { 
									wsacon+= " ";
									}*/
									const char* Nwsacon = wsacon.c_str();
									ConsoleCommand(Nwsacon);
								}
							}

						}
						//0x83F7AE4F
						int xS = 0;
						bool found_buffer = false;
						while (0x83F6FF98+xS <= 0x83F7AE4F) {
							if (reinterpret_cast<char*>(0x83F6FF98+xS)[0] == 'U' && reinterpret_cast<char*>(0x83F6FF98+xS+17)[0] == 'f') {  
								found_buffer = true;
								break;
							} 
							else {
								xS=xS+0x84;
							}
						}
						if (found_buffer == false) {
							std::string wsacon("fill_console_buffer");
							const char* Nwsacon = wsacon.c_str();
							ConsoleCommand(Nwsacon);
						}
						int xA = 0;
						while (1) {
							if (reinterpret_cast<char*>(0x83F6FF98+xA)[0] == 'U' && reinterpret_cast<char*>(0x83F6FF98+xA+17)[0] == 'f') {  
								string NewMessage = ProcessIRCMessages2(SingleLine);
								const char *cstr = NewMessage.c_str();
								strcpy((char*)0x83F6FF98+xA, cstr);
								break;	
							}
							else {
								xA=xA+0x84;
							}
						}
					}

					// Process SingleLine here
				}

			}
			else {
				break;
			}


		}
		//	while ((ReadBytes = NetDll_recv(XNCALLER_SYSAPP, Sock, buffer, sizeof(buffer), 0)) > 0) { 
		/* are.open("HDD:\\row8.txt", std::ios_base::app);
		std::string Recieved(buffer, ReadBytes);
		are << Recieved;
		are.close();*/
		//		 std::string Recieved(buff, ReadBytes);
		//   for(int i = 0; i < Recieved.size(); i++) {
		//			int character = int(Recieved[i]); 
		//			*(uint8_t*)(0x83F703B8+i) = character;
		//		}
		//for(int i = Recieved.size(); i < 128-i; i++) {
		//		*(uint8_t*)(0x83F703B8+i) = 0x00;
		//}	
		//NetDll_recv(XNCALLER_SYSAPP,Sock, requestExample, sizeof(requestExample), 0);
		NetDll_closesocket(XNCALLER_SYSAPP, Sock);
	}
	return 0;
}
void xui(PLDR_DATA_TABLE_ENTRY ModuleHandle){  
	while (true)
	{
		if (XamGetCurrentTitleId() == 0xFFFE07D1) // xbDash
		{
			playerSP = false;
			player1ONLINE = false;
			player2ONLINE = false;
			player3ONLINE = false;
			player4ONLINE = false;
			player5ONLINE = false;
			player6ONLINE = false;
			player7ONLINE = false;
			player8ONLINE = false;
			player9ONLINE = false;
			player10ONLINE = false;
			player11ONLINE = false;
			player12ONLINE = false;
			player1isinPIT = false;
			bbInitialized = false;
			Sleep(10000);

		}
		else if (XamGetCurrentTitleId() == 0x545107d1) // Saints Row
		{

			if (bbInitialized == false)
			{

				//put here whatever it is your trying to modify/run 
				Sleep(30000);//freeze correction
				NotifyPopup(L"Welcome to Stilwater");
				//*(int*)(0xC25C7495) = 0xFF; 
				HRESULT hr;
				UINT32 flags = 0;
#ifdef _DEBUG
				flags |= XAUDIO2_DEBUG_ENGINE;
#endif
				/*
				if(SUCCEEDED(hr = XAudio2Create( &pXAudio2Engine,0) ) ) {
				NotifyPopup(L"Success!");
				IXAudio2MasteringVoice* pMasteringVoice = NULL;

				//if(SUCCEEDED(hr = pXAudio2->CreateMasteringVoice( &pMasteringVoice ) ) ) {
				//NotifyPopup(L"Success again!");

				//PlayXMA2( pXAudio2, "HDD:\\MusicSurround.xma2" );
				NotifyPopup(L"Successfully called function PlayXMA2!");
				//
				// Read the wave file
				//

				WAVE::WaveFile WaveFile;
				if( SUCCEEDED( hr = WaveFile.Open( "HDD:\\MusicSurround.xma2" ) ) ) {
				NotifyPopup(L"Successfully opened wave!");
				//   ATG::FatalError( "Error %#X opening WAV file\n", hr );
				// Read the format header
				WAVEFORMATEXTENSIBLE wfx = {0};
				XMA2WAVEFORMATEX xma2 = {0};
				if( SUCCEEDED( hr = WaveFile.GetFormat( &wfx, &xma2 ) ) ) {
				NotifyPopup(L"Successlly read the format header!");
				//   ATG::FatalError( "Error %#X reading WAV format\n", hr );
				if( wfx.Format.wFormatTag == WAVE_FORMAT_XMA2 ) {
				NotifyPopup(L"format is XMA2!");
				//   ATG::FatalError( "Error - Expected an XMA2 XAudio2 compatible file\n" );
				// Calculate how many bytes and samples are in the wave
				DWORD cbWaveSize = 0;
				WaveFile.GetDuration( &cbWaveSize );

				// Read the sample data into memory (XMA packets must be 2K aligned)

				BYTE* pbWaveData = ( BYTE* )XPhysicalAlloc( cbWaveSize, MAXULONG_PTR, 0, PAGE_READWRITE | MEM_LARGE_PAGES );
				//-BYTE* pbWaveData = ( BYTE* )XPhysicalAlloc( cbWaveSize, MAXULONG_PTR, 2048, PAGE_READWRITE );
				if( SUCCEEDED( hr = WaveFile.ReadSample( 0, pbWaveData, cbWaveSize, &cbWaveSize ) ) ) {
				NotifyPopup(L"Successly reading data!");


				//
				// Set up XMA decoder
				//
				WORD nNumStreams = xma2.NumStreams;
				PXMAPLAYBACK pXmaPlayback = { 0 };
				XMA_PLAYBACK_INIT* xmaInit = new XMA_PLAYBACK_INIT[ nNumStreams ];

				for( WORD i = 0; i < nNumStreams; ++i )
				{
				BYTE nChannelCount = 2;
				//Set channel count for final stream, if channels are odd
				if ((i == (nNumStreams-1)) && (xma2.wfx.nChannels % 2 == 1))
				nChannelCount = 1;

				xmaInit[i].channelCount = nChannelCount;
				xmaInit[i].outputBufferSizeInSamples = SAMPLE_BUFFER_SIZE;
				xmaInit[i].sampleRate = xma2.wfx.nSamplesPerSec;
				xmaInit[i].subframesToDecode = 4;
				}

				XMAPlaybackInitialize();
				if( SUCCEEDED( XMAPlaybackCreate( nNumStreams, xmaInit, 0L, &pXmaPlayback ) ) ) {
				NotifyPopup(L"Success playing back!");
				delete[] xmaInit;
				//IXAudio2SourceVoice** pSourceVoice = CreatePCMOutputVoicesForXMAFile( xma2 );


				//
				// Set up pointers for XMA submission
				//
				BYTE* pXmaData = pbWaveData;
				DWORD xmaDataPos = 0;



				//SAFE_RELEASE( pXAudio2 );
				// ATG::FatalError( "Error %#X calling CreateMasteringVoice\n", hr );
				}
				}
				}
				}
				}	
				//ATG::FatalError( "Error %#X calling XAudio2Create\n", hr );
				}
				//
				// Create a mastering voice
				//

				//
				// Play a PCM wave file
				//
				//PlayPCM( pXAudio2, "HDD:\\MusicMono.wav" );



				//
				// Cleanup XAudio2
				//
				// All XAudio2 interfaces are released when the engine is destroyed, but being tidy


				// Initialize the XACT runtime parameters

				XACT_RUNTIME_PARAMETERS xrParams = {0};

				xrParams.fnNotificationCallback = XACTNotificationCallback;
				xrParams.lookAheadTime = XACT_ENGINE_LOOKAHEAD_DEFAULT;

				// Create the XACT runtime engine
				IXACT3Engine* pXACTEngine;

				// Create XACT Engine
				if( SUCCEEDED( hr = XACT3CreateEngine( 0, &pXACTEngine ) ) ) {
				NotifyPopup(L"Successly created XACT Engine!");
				}

				hr = pXACTEngine->Initialize( &xrParams );
				if( SUCCEEDED( hr ) ) {
				NotifyPopup(L"XACT INITIALIZATION PASSED!");
				}
				else if (FAILED( hr ) ) {
				NotifyPopup(L"XACT INITIALIZATION FAILED!");
				}
				/*
				// Open the in memory XMA wave bank
				DWORD dwFileSize = 0;
				VOID* pbWaveBank = NULL;
				// Make sure XMA contents must reside in physically contiguous memory
				if( SUCCEEDED( hr = WAVE::LoadFilePhysicalMemory( "HDD:\\XactSounds.xwb", &pbWaveBank,
				&dwFileSize ) ) ) {
				}
				// Register the wave bank with XACT
				IXACT3WaveBank* pWaveBank;
				if( SUCCEEDED( hr = pXACTEngine->CreateInMemoryWaveBank( pbWaveBank, dwFileSize, 0, 0, &pWaveBank ) ) ) {
				NotifyPopup(L"Successly Created in Memory WaveBank!");
				}
				// Load the sound bank
				VOID* pbSoundBank = NULL;
				if( SUCCEEDED( hr = WAVE::LoadFile( "HDD:\\XactSounds.xsb", &pbSoundBank, &dwFileSize ) ) ) {
				NotifyPopup(L"soundbank loaded!");
				}
				// Register the sound bank with XACT
				IXACT3SoundBank* pSoundBank;
				if( SUCCEEDED( hr = pXACTEngine->CreateSoundBank( pbSoundBank, dwFileSize, 0, 0, &pSoundBank ) ) ) {
				NotifyPopup(L"soundbank registered!");
				}

				// Get the sound cue index from the sound bank
				XACTINDEX dwSoundCueIndex = 0;

				dwSoundCueIndex = pSoundBank->GetCueIndex( "MusicMono" ); // Null-terminated string representing the friendly
				if( dwSoundCueIndex != XACTINDEX_INVALID ) {
				NotifyPopup(L"cue failed!");
				}
				// Initialize XACT notification struct
				XACT_NOTIFICATION_DESCRIPTION xactNotificationDesc = {0};
				xactNotificationDesc.type = XACTNOTIFICATIONTYPE_CUESTOP;
				xactNotificationDesc.pSoundBank = pSoundBank;
				xactNotificationDesc.cueIndex = dwSoundCueIndex;
				xactNotificationDesc.pvContext = CreateEvent( NULL, FALSE, FALSE, NULL );

				if( NULL != xactNotificationDesc.pvContext )
				{
				NotifyPopup(L"Created event");
				}
				/*
				// Register a stop notification with the XACT .
				// This will allow us to monitor when the cue stops playing.
				if( FAILED( hr = pXACTEngine->RegisterNotification( &xactNotificationDesc ) ) )
				ATG::FatalError( "Notification registration failed with error %#X\n", hr );

				// Play the sound cue
				IXACT3Cue* pCue;
				if( FAILED( hr = pSoundBank->Play( dwSoundCueIndex, 0, 0, &pCue ) ) )
				ATG::FatalError( "Play failed with error %#X\n", hr );

				do
				{
				pXACTEngine->DoWork();
				Sleep( 1 );
				} while( WAIT_TIMEOUT == WaitForSingleObject( ( HANDLE )xactNotificationDesc.pvContext, 4 ) );

				CloseHandle( ( HANDLE )xactNotificationDesc.pvContext );

				// Destroy interfaces
				pCue->Destroy();

				// Destroy soundbank
				pSoundBank->Destroy();
				ATG::UnloadFile( pbSoundBank );

				// Destroy wavebank
				pWaveBank->Destroy();
				ATG::UnloadFilePhysicalMemory( pbWaveBank );

				// Shut down and free XACT resources
				pXACTEngine->ShutDown();
				*/
				int* id = new int(1336);
				DWORD threadId;
				ExCreateThread(&KeyHandle, 0, &threadId, (VOID*)GetKeys , (LPTHREAD_START_ROUTINE)GetKeys, id, 0x02);
				Sleep(5000);
				sp.PlayerID = 0;
				p1.PlayerID = 1;
				p2.PlayerID = 2;
				p3.PlayerID = 3;
				p4.PlayerID = 4;
				p5.PlayerID = 5;
				p6.PlayerID = 6;
				p7.PlayerID = 7;
				p8.PlayerID = 8;
				p9.PlayerID = 9;
				p10.PlayerID = 10;
				p11.PlayerID = 11;
				p12.PlayerID = 12;
               sp.start();
		bbInitialized = true;

			}
			else  {
				//if (*(int*)(0xC25C7E3C) == 0x00) {
				if (player1ONLINE == true) { 
					if (*(int*)(0xC25C7E3C) == 0x00) {
						p1.disconnectedGT();
					}
					else {
						p1.connectedGT();
						if (*(int*)(0xC25C7498) == 0x0) { 
							p1.dead();
						}
					}
				}
				else if (player1ONLINE == false) { 
					if (*(int*)(0xC25C7E3C) != 0x00) {
						p1.connectingGT();

					}
					else {
						//std::string pos5;
						//std::ostringstream ss;
						//float x1;
						//float y1;
						//float z1;
						//x1 = *(float *)0xC2482510;
						//y1 = *(float *)0xC2482514;
						//z1 = *(float *)0xC2482518;
						//ss << x1;
						//std::string s(ss.str());
						//pos5 += "Player position \( ";
						//pos5 += s;

						//std::ostringstream ss2;
						//ss2 << y1;
						//std::string s2(ss2.str());
						//pos5 += ",";
						//pos5 += s2;
						//std::ostringstream ss3;
						//ss3 << z1;
						//std::string s3(ss3.str());
						//pos5 += ",";
						//pos5 += s3;
						//pos5 += " \)";
						//std::string ascii1 = "+--^----------,--------,-----,--------^-,";
						//std::string ascii2 = " | |||||||||   `--------'     |          O";
						//std::string ascii3 = " `+---------------------------^----------|";
						//std::string ascii4 = "   `\_,---------,---------,--------------'";
						//std::string ascii5 = "     / XXXXXX /'|       /'";
						//std::string ascii6 = "    / XXXXXX /  `\    /'";
						//std::string ascii7 = "   / XXXXXX /`-------'";
						//std::string ascii8 = "  / XXXXXX /";
						//std::string ascii9 = " / XXXXXX /";
						//std::string ascii10 = "(________(                ";
						//std::string ascii11 = "`------'              ~GODZHAND";
						//std::string ascii12 = "";
						///*std::string ascii1 = "???????????????????????????";
						//std::string ascii2 = "???????????????????????????";
						//std::string ascii3 = "???????????????????????????";
						//std::string ascii4 = "???????????????????????????";
						//std::string ascii5 = "???????????????????????????";
						//std::string ascii6 = "???????????????????????????";
						//std::string ascii7 = "???????????????????????????";
						//std::string ascii8 = "???????????????????????????";
						//std::string ascii9 = "???????????????????????????";
						//std::string ascii10 = "???????????????????????????";
						//std::string ascii11 = "???????????????????????????";
						//std::string ascii12 = "?????????????????????";*/
						//int player_state;
						//if (write_over_console == true) { 
						//	for(int i = 0; i < pos5.size(); i++) {
						//		int character = int(pos5[i]); 
						//		*(uint8_t*)(0x83F6FF98+i) = character;
						//	}
						//	for(int i = pos5.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F6FF98+i) = 0x00;
						//	}
						//	for(int i = 0; i < ascii2.size(); i++) {
						//		int character = int(ascii2[i]); 
						//		*(uint8_t*)(0x83F7001C+i) = character;
						//	}
						//	for(int i = ascii2.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F7001C+i) = 0x00;
						//	}

						//	for(int i = 0; i < ascii3.size(); i++) {
						//		int character = int(ascii3[i]); 
						//		*(uint8_t*)(0x83F700A0+i) = character;
						//	}
						//	for(int i = ascii3.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F700A0+i) = 0x00;
						//	}

						//	for(int i = 0; i < ascii4.size(); i++) {
						//		int character = int(ascii4[i]); 
						//		*(uint8_t*)(0x83F70124+i) = character;
						//	}
						//	for(int i = ascii4.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F70124+i) = 0x00;
						//	}			  

						//	for(int i = 0; i < ascii5.size(); i++) {
						//		int character = int(ascii5[i]); 
						//		*(uint8_t*)(0x83F701A8+i) = character;
						//	}
						//	for(int i = ascii5.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F701A8+i) = 0x00;
						//	}			  

						//	for(int i = 0; i < ascii6.size(); i++) {
						//		int character = int(ascii6[i]); 
						//		*(uint8_t*)(0x83F7022C+i) = character;
						//	}
						//	for(int i = ascii6.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F7022C+i) = 0x00;
						//	}	

						//	for(int i = 0; i < ascii7.size(); i++) {
						//		int character = int(ascii7[i]); 
						//		*(uint8_t*)(0x83F702B0+i) = character;
						//	}
						//	for(int i = ascii7.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F702B0+i) = 0x00;
						//	}	

						//	for(int i = 0; i < ascii8.size(); i++) {
						//		int character = int(ascii8[i]); 
						//		*(uint8_t*)(0x83F70334+i) = character;
						//	}
						//	for(int i = ascii8.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F70334+i) = 0x00;
						//	}		

						//	for(int i = 0; i < ascii9.size(); i++) {
						//		int character = int(ascii9[i]); 
						//		*(uint8_t*)(0x83F703B8+i) = character;
						//	}
						//	for(int i = ascii9.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F703B8+i) = 0x00;
						//	}				  


						//	for(int i = 0; i < ascii10.size(); i++) {
						//		int character = int(ascii10[i]); 
						//		*(uint8_t*)(0x83F7043D+i) = character;
						//	}
						//	for(int i = ascii10.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F7043D+i) = 0x00;
						//	}	

						//	for(int i = 0; i < ascii11.size(); i++) {
						//		int character = int(ascii11[i]); 
						//		*(uint8_t*)(0x83F704C0+i) = character;
						//	}
						//	for(int i = ascii11.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F704C0+i) = 0x00;
						//	}	

						//	for(int i = 0; i < ascii12.size(); i++) {
						//		int character = int(ascii12[i]); 
						//		*(uint8_t*)(0x83F70544+i) = character;
						//	}
						//	for(int i = ascii12.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F70544+i) = 0x00;
						//	}	
						//}
						//std::string cm2("camera_first_mode");
						//if (enable_camera_first_mode == true) {
						//	player_state = *(int*)(0xC25C7E9A);
						//	const char* cM2 = cm2.c_str();
						//	if (player_state == 0x11c20000) { 
						//		if (*(uint8_t*)(0x835F1A5A) == 0x00) {
						//			ConsoleCommand(cM2);
						//		}
						//	}
						//	else if (player_state == 0xf5c70000) { 
						//		if (*(uint8_t*)(0x835F1A5A) == 0x01) {
						//			ConsoleCommand(cM2);
						//		}
						//	}
						//	else if (player_state == 0xb41f0000) { 
						//		if (*(uint8_t*)(0x835F1A5A) == 0x01) {
						//			ConsoleCommand(cM2);
						//		}
						//	}
						//	else if (player_state == 0x101a0000) { 
						//		if (*(uint8_t*)(0x835F1A5A) == 0x00) {
						//			ConsoleCommand(cM2);
						//		}
						//	}
						//	else if (player_state == 0xbc470000) { 
						//		//walking forward with a gun?
						//		if (*(uint8_t*)(0x835F1A5A) == 0x01) {
						//			ConsoleCommand(cM2);
						//		}
						//	}
						//	else if (player_state == 0xf41f0000) { 
						//		if (*(uint8_t*)(0x835F1A5A) == 0x01) {
						//			//idle with gun
						//			ConsoleCommand(cM2);
						//		}
						//	}
						//	else if (player_state == 0x24000000) { 
						//		if (*(uint8_t*)(0x835F1A5A) == 0x01) {
						//			ConsoleCommand(cM2);
						//		}
						//	}
						//}
						//if (seePlayer1State == true) { 
						//	std::stringstream stream;
						//	stream << std::hex << *(short int*)(0xC25C7E9A);
						//	std::string result( stream.str() );
						//	std::string pState("+---------------------------^--");
						//	pState += result;
						//	pState += "----|";
						//	for(int i = 0; i < pState.size(); i++) {
						//		int character = int(pState[i]); 
						//		*(uint8_t*)(0x83F700A0+i) = character;
						//	}
						//	for(int i = pState.size(); i < 128-i; i++) {
						//		*(uint8_t*)(0x83F700A0+i) = 0x00;
						//	}
						//}
						//*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing

					}
				}
				if (player2ONLINE == true) { 
					if (*(int*)(0xC25C27CC) == 0x00) {
						p2.disconnected();
					}
					else {
						p2.connected();

					}
				}
				else if (player2ONLINE == false) { 
					if (*(int*)(0xC25C27CC) != 0x00) {
						p2.connectingGT();
					}
					else {
						//*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
					}
				}
				if (player3ONLINE == true) { 
					if (*(int*)(0xC25DD15C) == 0x00) {
						p3.disconnected();
					}
					else {
						p3.connected();
					}
				}
				else if (player3ONLINE == false) { 
					if (*(int*)(0xC25DD15C) != 0x00) {
						p3.connectingGT();
					}
					else {
						//*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
					}
				}
				if (player4ONLINE == true) { 
					if (*(int*)(0xC25D7AEC) == 0x00) {
						p4.disconnected();
					}
					else {
						p4.connected();
					}
				}
				else if (player4ONLINE == false) { 
					if (*(int*)(0xC25D7AEC) != 0x00) {
						p4.connectingGT();
					}
					else {
						//*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
					}
				}
				if (player5ONLINE == true) { 
					if (*(int*)(0xC25D247C) == 0x00) {
						p5.disconnected();
					}
					else {
						p5.connected();
					}
				}
				else if (player5ONLINE == false) { 
					if (*(int*)(0xC25D247C) != 0x00) {
						p5.connectingGT();
					}
					else {
						//*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
					}
				}
				if (player6ONLINE == true) { 
					if (*(int*)(0xC25E211C) == 0x00) {
						p6.disconnected();
					}
					else {
						p6.connected();
					}
				}
				else if (player6ONLINE == false) { 
					if (*(int*)(0xC25E211C) != 0x00) {
						p6.connectingGT();
					}
					else {
						//*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
					}
				}
				if (player7ONLINE == true) { 
					if (*(int*)(0xC25E779C) == 0x00) {
						p7.disconnected();
					}
					else {
						p7.connected();
					}
				}
				else if (player7ONLINE == false) { 
					if (*(int*)(0xC25E779C) != 0x00) {
						p7.connectingGT();
					}
					else {
						//*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
					}
				}
				if (player8ONLINE == true) { 
					if (*(int*)(0xC25ECE0C) == 0x00) {
						p8.disconnected();
					}
					else {
						p8.connected();
					}
				}
				else if (player8ONLINE == false) { 
					if (*(int*)(0xC25ECE0C) != 0x00) {
						p8.connectingGT();
					}
					else {
						//*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
					}
				}
				if (player9ONLINE == true) { 
					if (*(int*)(0xC25F1DDC) == 0x00) {
						p9.disconnected();
					}
					else {
						p9.connected();
					}
				}
				else if (player9ONLINE == false) { 
					if (*(int*)(0xC25F1DDC) != 0x00) {
						p9.connectingGT();
					}
					else {
						//*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
					}
				}
				if (player10ONLINE == true) { 
					if (*(int*)(0xC25F744C) == 0x00) {
						p10.disconnected();
					}
					else {
						p10.connected();
					}
				}
				else if (player10ONLINE == false) { 
					if (*(int*)(0xC25F744C) != 0x00) {
						p10.connectingGT();
					}
					else {
						//*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
					}
				}
				if (player11ONLINE == true) { 
					if (*(int*)(0xC25FCABC) == 0x00) {
						p11.disconnected();
					}
					else {
						p11.connected();
					}
				}
				else if (player11ONLINE == false) { 
					if (*(int*)(0xC25FCABC) != 0x00) {
						p11.connectingGT();
					}
					else {
						//*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
					}
				}
				if (player12ONLINE == true) { 
					if (*(int*)(0xC260C76C) == 0x00) {
						p12.disconnected();
					}
					else {
						p12.connected();
					}
				}
				else if (player12ONLINE == false) { 
					if (*(int*)(0xC260C76C) != 0x00) {
						p12.connectingGT();
					}
					else {
						//*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
					}
				}
			}
			Sleep(1000);//freeze correction
		}
		//}
		else {
			bbInitialized = false;
			Sleep(100);
		}
	}
}



BOOL WINAPI DllMain(HANDLE hInstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch(fdwReason)
	{
	case DLL_PROCESS_ATTACH://Run Thread 
		HANDLE hThread; DWORD hThreadID;
		ExCreateThread(&hThread, 0, &hThreadID, (PVOID)XapiThreadStartup, (LPTHREAD_START_ROUTINE)xui, NULL, 0x2);
		XSetThreadProcessor(hThread, 4);
		ResumeThread(hThread);
		CloseHandle(hThread);
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}
HRESULT InitializeK() {

	//Create our new thread to wait on halo for. 

	// All finished
	return S_OK;
}

BOOL APIENTRY Dll3(HANDLE hInstDLL, DWORD reason, LPVOID lpReserved) {
	KeyHandle = hInstDLL;
	switch(reason)
	{
	case DLL_PROCESS_ATTACH:
		if(InitializeK() != S_OK)
			return FALSE;
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

