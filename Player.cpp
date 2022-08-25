// my_class.cpp
#include <stdint.h>
#include <stdio.h>
#include "StdAfx.h"
#include "Player.h" // header in local directory
#include <iostream> // header in standard library
#include "Tools.h"
#include "global.h"
#include <cstdint>
#include <iostream>
#include <sstream>
#include <fstream>
#include <winsockx.h>
#include <vector>
#include "MD5X.h"
#include <Xtl.h>
#include <algorithm>

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
HANDLE moduleHandle;
#if defined(_MSC_VER)
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#endif
typedef void(__cdecl* ConsoleCommand2T)(const char command[]);
ConsoleCommand2T ConsoleCommand2 = (ConsoleCommand2T)0x8263CB10;
typedef void(__cdecl* unkn_FUNCT822E3618T)(void);
unkn_FUNCT822E3618T unkn_FUNCT822E3618 = (unkn_FUNCT822E3618T)0x822E3618;
typedef void(__cdecl* s_ptp_pimp2T)(void);
s_ptp_pimp2T s_ptp_pimp2 = (s_ptp_pimp2T)0x823ED600;
typedef void(__cdecl* HeliT2)(void);
HeliT2 Heli2 = (HeliT2)0x82793f30;
typedef void(__cdecl* Function_827803C8T)(void);
Function_827803C8T Function_827803C8 = (Function_827803C8T)0x827803C8;
Detour<unsigned long long>Function_8263CA30_Detour;
using namespace N;
using namespace std;
struct sockaddr_in sockaddr_s;
int sockets, connected;
SOCKET currentSock;
SOCKET currentIRC7Sock;
SOCKET currentTSock;
HANDLE ghMutex; 
struct ARGS {

	string gt;
};

struct PARAMETERS
{

	int i;
	int j;
};
void Test(int x, int y, bool z) {
	DbgPrint("Function called %i %i %i\n",x,y,z);
std:string fuckyou = "FUCKYOU";
}
void ReplaceStringInPlace(std::string& subject, const std::string& search,
	const std::string& replace) {
		size_t pos = 0;
		while ((pos = subject.find(search, pos)) != std::string::npos) {
			subject.replace(pos, search.length(), replace);
			pos += replace.length();
		}
}

void Player::ExternalMsg(char* str){
	std::string sentstr(str);
	std::string sentstr2;
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
								ConsoleCommand2(Nwsacon);
							}
							int xA = 0;
							while (1) {
								if (reinterpret_cast<char*>(0x83F6FF98+xA)[0] == 'U' && reinterpret_cast<char*>(0x83F6FF98+xA+17)[0] == 'f') {  
									size_t pos = sentstr.find(":");
									string NewMessage = "<>" + fixedgamertag + "> ";
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
						ReplaceStringInPlace(sentstr,"#","#tharownet");
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
							ConsoleCommand2(Nwsacon);
						}
						int xA = 0;
						while (1) {
							if (reinterpret_cast<char*>(0x83F6FF98+xA)[0] == 'U' && reinterpret_cast<char*>(0x83F6FF98+xA+17)[0] == 'f') {  
								size_t pos = sentstr.find(":");
								string NewMessage = "<>" + fixedgamertag + "> ";
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
			ConsoleCommand2(Nwsacon);
		}
		int xA = 0;
		while (1) {
			if (reinterpret_cast<char*>(0x83F6FF98+xA)[0] == 'U' && reinterpret_cast<char*>(0x83F6FF98+xA+17)[0] == sentstr[0]) {  
				size_t pos = sentstr.find(":");
				string NewMessage = "<>" + fixedgamertag + "> ";
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
		sentstr2 = sentstr;
		sentstr="PRIVMSG #tharownet :" + sentstr;
		sentstr2 = "PRIVMSG %#tha-row.net :" + sentstr2;

	}
	sentstr+="\r\n";
	sentstr2+="\r\n";
	std::string wsacon("subtitle_add \"enter!");
	wsacon += "\" 3";
	const char* Nwsacon = wsacon.c_str();
	ConsoleCommand2(Nwsacon);

	NetDll_send(XNCALLER_SYSAPP, Player::Sock, sentstr.c_str(), sentstr.length(), 0);
	NetDll_send(XNCALLER_SYSAPP, Player::IRC7Sock, sentstr2.c_str(), sentstr2.length(), 0);
}
void SendSockInfo(SOCKET s) {
	currentSock = s;
}
void SendTSockInfo(SOCKET s) {
	currentTSock = s;
}
void SendIPinfo(string ip) {
	own_ip_address = ip;
}
void SendSockInfo2(SOCKET sz) {
	currentIRC7Sock = sz;
}
int instr(string istring, string tofind){
	if (istring.find(tofind)!=istring.npos){
		return istring.find(tofind)+1;
	}else{
		return 0;
	} 
}
int Instr( char *SearchString, char *SearchTerm )
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
static void removeTrailingCharacters(std::string &str, const char charToRemove) {
	str.erase (str.find_last_not_of(charToRemove) + 1, std::string::npos );
}
string Mid(string& str, int pos1, int pos2)
{
	int i;
	string temp = "";
	for(i = pos1; i < pos2; i++)
	{
		temp += str[i];
	}

	return temp;
}
std::string ProcessIRCMessages(string Message) {
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
string hexToASCII(string hex)
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
void write2console(string ConsoleMessage) {
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
		ConsoleCommand2(Nwsacon);
	}
	int xA = 0;
	while (1) {
		if (reinterpret_cast<char*>(0x83F6FF98+xA)[0] == 'U' && reinterpret_cast<char*>(0x83F6FF98+xA+17)[0] == 'f') {
			/*string NewMessage = "";*/
			string SingleLine2;
			string NewMessage;

			//NewMessage.assign(ProcessIRCMessages(SingleLine2));

			// }
			// else {
			NewMessage.assign(ProcessIRCMessages(ConsoleMessage));
			// }
			const char *cstr = NewMessage.c_str();
			strcpy((char*)0x83F6FF98+xA, cstr);
			break;	
		}
		else {
			xA=xA+0x84;
		}
	}
}
void Player::sendCar() {
	DbgPrint("HIT");
	car = true;
}
DWORD WINAPI sendCar2() {
	while (true) {
		if (car == true) {
			string send = "PRIVMSG tharow :@ENTERED_CAR\r\n";
			NetDll_send(XNCALLER_SYSAPP, currentSock, send.c_str(), send.length(), 0);
			car = false;
		}
	}
	return 0;
}
void Function_8263CA30(unsigned long long r3,unsigned long long r4,unsigned int r5,unsigned int r6) {
	DbgPrint("Function_8263CA30 hit: %i %i %i %i",r3,r4,r5,r6);
	Function_8263CA30_Detour.CallOriginal(r3,r4,r5,r6);
}
void Connect2IPX() {
	SOCKET SockIPX;
	BYTE IPAddress[0x4] =  { 47, 220, 0, 49 };
	WORD Port = 80;
	DWORD SocketError;
	XNetStartupParams xnsp;
	WSADATA WsaData;
	BOOL SockOpt = TRUE;
	DWORD sendRecvSize = 1024;
	sockaddr_in httpServerAdd;
	httpServerAdd.sin_addr.S_un.S_addr = *(PDWORD)IPAddress;
	httpServerAdd.sin_port = htons(Port);
	httpServerAdd.sin_family = AF_INET;
	ZeroMemory(&xnsp, sizeof(xnsp));
	xnsp.cfgSizeOfStruct = sizeof(XNetStartupParams);
	xnsp.cfgFlags = XNET_STARTUP_BYPASS_SECURITY;
	if ((SocketError = NetDll_XNetStartup(XNCALLER_SYSAPP, &xnsp)) != S_OK) {

	}

	if ((SocketError = NetDll_WSAStartupEx(XNCALLER_SYSAPP, MAKEWORD(2, 2), &WsaData, 2)) != S_OK) {

	}

	SockIPX = NetDll_socket(XNCALLER_SYSAPP, AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (NetDll_setsockopt(XNCALLER_SYSAPP, SockIPX, SOL_SOCKET, 0x5801, (PCSTR)&SockOpt, 4) != S_OK) {
	}
	NetDll_setsockopt(XNCALLER_SYSAPP, SockIPX, SOL_SOCKET, SO_SNDBUF, (PCSTR)&sendRecvSize, 4);
	NetDll_setsockopt(XNCALLER_SYSAPP, SockIPX, SOL_SOCKET, SO_RCVBUF, (PCSTR)&sendRecvSize, 4);
	struct timeval tv;
	tv.tv_sec = 15;
	tv.tv_usec = 0;
	setsockopt(SockIPX, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(struct timeval));
	if (NetDll_connect(XNCALLER_SYSAPP, SockIPX, (struct sockaddr*)&httpServerAdd, sizeof(httpServerAdd)) == SOCKET_ERROR) {
		//failed
	}

	else { 
		char recvbuf[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN;
		int iResult;
		///const char* ReturnBuffer;
		//string ConIRC = "PASS oauth:bu1vqoikefnlbfy8lois6i3ryzt1sa\r\nNICK tharowNET\r\n";
		string ConIRC = "GET / HTTP/1.0\r\nHost: tha-row.net\r\n\r\n";
		int ReadBytes = 0;
		ofstream ircdata;
		char buff[1024];
		NetDll_send(XNCALLER_SYSAPP, SockIPX, ConIRC.c_str(), ConIRC.length(), 0);
		while (true)
		{
			ZeroMemory(buff, 1024);

			int bytesReceived = NetDll_recv(XNCALLER_SYSAPP,SockIPX, buff, 1024, 0);
			if (bytesReceived == SOCKET_ERROR)
			{

			}
			if (bytesReceived > 0) {
				//read data
			}
			else {
				break;
			}
		}
	}
}
DWORD WINAPI Connect2SockK() {
Restart:
	std::string wsacon("subtitle_add ");
	// string *GTptr = reinterpret_cast<std::string*>(zGT)
	//string GT = *GTptr;
	// wsacon += GT;
	wsacon += " 3";
	SOCKET SockK;
	// Code mod.  allowing user to imput address
	//BYTE IPAddress[0x4] = { 98, 194, 130, 207 }; //Your IP
	BYTE IPAddress[0x4] =  { 192, 99, 241, 131 };
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
	SockK = NetDll_socket(XNCALLER_SYSAPP, AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//Sock = NetDll_socket(XNCALLER_SYSAPP, AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//Sock = socket(AF_INET, SOCK_STREAM, 0);
	// Disable network encryption
	if (NetDll_setsockopt(XNCALLER_SYSAPP, SockK, SOL_SOCKET, 0x5801, (PCSTR)&SockOpt, 4) != S_OK) {

	}

	// Configure socket send/recv size
	NetDll_setsockopt(XNCALLER_SYSAPP, SockK, SOL_SOCKET, SO_SNDBUF, (PCSTR)&sendRecvSize, 4);
	NetDll_setsockopt(XNCALLER_SYSAPP, SockK, SOL_SOCKET, SO_RCVBUF, (PCSTR)&sendRecvSize, 4);

	// Create connection timeout
	struct timeval tv;
	tv.tv_sec = 15;
	tv.tv_usec = 0;
	setsockopt(SockK, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(struct timeval));

	if (NetDll_connect(XNCALLER_SYSAPP, SockK, (struct sockaddr*)&httpServerAdd, sizeof(httpServerAdd)) == SOCKET_ERROR) {
		std::string wsacon("subtitle_add \"fai!");
		wsacon += "\" 3";
		const char* Nwsacon = wsacon.c_str();
		ConsoleCommand2(Nwsacon);
	}

	else { 
		char recvbuf[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN;
		int iResult;
		std::string wsacon("subtitle_add \"connected!");
		wsacon += "\" 3";
		const char* Nwsacon = wsacon.c_str();
		ConsoleCommand2(Nwsacon);
		///const char* ReturnBuffer;
		string ConIRC = "NICK " + fixedgamertag + "\r\nUSER " + fixedgamertag + " 0 * :Saints Row Client\r\n";
		//string ConIRC = "NICK " + gamertag + "\r\nUSER " + gamertag + " 0 * :Saints Row Client\r\n";
		//NetDll_send(XNCALLER_SYSAPP, Sock, requestExample, 255, 0);
		int ReadBytes = 0;
		ofstream ircdata;

		//ircdata.open("HDD:\\ircdata.txt");
		char buff[1024];
		NetDll_send(XNCALLER_SYSAPP, SockK, ConIRC.c_str(), ConIRC.length(), 0);
		while (true)
		{
			ZeroMemory(buff, 1024);

			int bytesReceived = NetDll_recv(XNCALLER_SYSAPP,SockK, buff, 1024, 0);
			if (bytesReceived == SOCKET_ERROR)
			{

			}
			if (bytesReceived > 0) {
				std::string Recieved(buff, bytesReceived);
				removeTrailingCharacters(Recieved, '\n');
				removeTrailingCharacters(Recieved, '\r');
				removeTrailingCharacters(Recieved, '\t');
				std::stringstream iss(Recieved);
				while(iss.good())
				{
					std::string SingleLine;
					getline(iss,SingleLine);
					if (!SingleLine.empty()) {
						removeTrailingCharacters(SingleLine, '\n');
						removeTrailingCharacters(SingleLine, '\r');
						removeTrailingCharacters(SingleLine, '\t');
						stringstream ss(SingleLine);
						string s;
						int xUp = 1;
						vector <string> tokens;
						while (getline(ss, s, ' ')) {
							tokens.push_back(s);
							xUp++;
						}
						if (tokens[0] == "PING") { 
							string x = "PONG chat1.koach.com :TIMEOUTCHECK\r\n";
							NetDll_send(XNCALLER_SYSAPP, SockK, x.c_str(), x.length(), 0);
						}
						if (tokens.size() > 1) {
							if (tokens[1] == "JOIN") {
								vector <string> ntokens;
								string getNick = tokens[0];
								string parsed;
								stringstream input_stringstream(getNick);

								if (getline(input_stringstream,parsed,'!'))
								{
									ntokens.push_back(parsed);
									// do some processing.
								}
								string getNick2 = ntokens[0];
								getNick2.erase(0,1);
								string newNick = '_' + gamertag;
								if (getNick2 == gamertag || getNick2 == newNick) {

									ConsoleWindowOpen = true;
									string sendXUID;
									sendXUID += "PRIVMSG tharow :@UPDATE_XUID=";
									sendXUID += gamertag;
									sendXUID += "!";
									sendXUID += xuidgkI64u;
									sendXUID += "\r\n";
									NetDll_send(XNCALLER_SYSAPP, SockK, sendXUID.c_str(), sendXUID.length(), 0);
								}
							}
							if (tokens[1] == "PRIVMSG") {
														if (tokens[3] == ":DISCORD_MSG") {
								string newString;
								for(int i = 4; i < tokens.size(); i++)  {
									newString += tokens[i];
									newString += " ";
								}
								SingleLine.assign(newString);
							}
							//@CHANGE_GT ?1?[clantag] gamertag?PLEASE WELCOME OWNER OF MAFIA OF WAR [clantag] gamertag
							//@CHANGE_GT ?GODZHANDXXX?1?[MAFIA] GODZHANDXXX?!!
							else if (tokens[3] == ":@CHANGE_GT") {
								vector <string> div;
								string newString;
								stringstream ss(SingleLine);
								while(getline(ss, newString, '?'))
								{
									div.push_back(newString);
								}
								string gt1 = div[1];
								string id = div[2];
								string cgt = div[3];
								string msg = div[4];
								if (gt1 == gamertag) {
									if (id == "1") {
										swprintf((wchar_t *)0xC25C7D60, L"%S", cgt);
									}
									else if (id == "2") {
										swprintf((wchar_t *)0xC25C26F0, L"%S", cgt);
									}
									else if (id == "3") {
										swprintf((wchar_t *)0xC25DD080, L"%S", cgt);
									}
									else if (id == "4") {
										swprintf((wchar_t *)0xC25D7A10, L"%S", cgt);
									} 
									else if (id == "5") {
										swprintf((wchar_t *)0xC25D23A0, L"%S", cgt);
									}
									else if (id == "6") {
										swprintf((wchar_t *)0xC25E2050, L"%S", cgt);
									}
									else if (id == "7") {
										swprintf((wchar_t *)0xC25E76C0, L"%S", cgt);
									}
									else if (id == "8") {
										swprintf((wchar_t *)0xC25ECD30, L"%S", cgt);
									}
									else if (id == "9") {
										swprintf((wchar_t *)0xC25F1D00, L"%S", cgt);
									}
									else if (id == "10") {
										swprintf((wchar_t *)0xC25F7370, L"%S", cgt);
									}
									else if (id == "11") {
										swprintf((wchar_t *)0xC25FC9E0, L"%S", cgt);
									}
									else if (id == "12") {
										swprintf((wchar_t *)0xC260C690, L"%S", cgt);
									}
									ConsoleCommand2("subtitles true");
	/*								ConsoleCommand2("mp_remote_console \"subtitles true");
								string messageR = "mp_remote_console \"subtitle_add " + msg + "\" 30";
								string message = "subtitle_add \"" + msg + "\" 30";
								const char* Nwmessage = message.c_str();
								const char* NwmessageR = messageR.c_str();
								replace(messageR.begin(), messageR.end(), ' ', '.');
								ConsoleCommand2(Nwmessage);
								ConsoleCommand2(NwmessageR);*/
								}
							}
							}
							if (tokens[1] == "001") { 
								own_ip_address = tokens[9];
								SendIPinfo(tokens[9]);
								SendSockInfo(SockK);
							}
							if (tokens[1] == "376") { 
								string Z = "JOIN #tha-row.net\r\n";
								NetDll_send(XNCALLER_SYSAPP, SockK, Z.c_str(), Z.length(), 0);
							}
							if (tokens[1] == "433") { 
								string ConIRC = "NICK _" + fixedgamertag + "\r\nUSER " + fixedgamertag + " 0 * :Saints Row Client\r\n";
								NetDll_send(XNCALLER_SYSAPP, SockK, ConIRC.c_str(), ConIRC.length(), 0);
							}
							//0x83F7AE4F
							if (ConsoleWindowOpen == true) { 
								if (tokens[1] != "001" && tokens[1] != "002" && tokens[1] != "003" && tokens[1] != "004" && tokens[1] != "005" && tokens[1] != "251" && tokens[1] != "252" && tokens[1] != "253" && tokens[1] != "254" && tokens[1] != "255" && tokens[1] != "265" && tokens[1] != "266" && tokens[1] != "375" && tokens[1] != "372" && tokens[1] != "376") {
									DWORD dresult;
									dresult = WaitForSingleObject( ghMutex, INFINITE);
									switch (dresult) 
									{
									case WAIT_OBJECT_0:
										__try {
											write2console(SingleLine);
										}
										__finally {
											ReleaseMutex(ghMutex);
										}
										break;

									}
								}
							}
						}
					}
				}
			}
			else {
				break;
			}
		}
		NetDll_closesocket(XNCALLER_SYSAPP, SockK);
	}
	return 0;
}
DWORD WINAPI ConnectSock() {
Restart:
	std::string wsacon("subtitle_add ");
	// string *GTptr = reinterpret_cast<std::string*>(zGT)
	//string GT = *GTptr;
	// wsacon += GT;
	wsacon += " 3";
	SOCKET IRC7Sock;
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
	IRC7Sock = NetDll_socket(XNCALLER_SYSAPP, AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//Sock = NetDll_socket(XNCALLER_SYSAPP, AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//Sock = socket(AF_INET, SOCK_STREAM, 0);
	// Disable network encryption
	if (NetDll_setsockopt(XNCALLER_SYSAPP, IRC7Sock, SOL_SOCKET, 0x5801, (PCSTR)&SockOpt, 4) != S_OK) {

	}

	// Configure socket send/recv size
	NetDll_setsockopt(XNCALLER_SYSAPP, IRC7Sock, SOL_SOCKET, SO_SNDBUF, (PCSTR)&sendRecvSize, 4);
	NetDll_setsockopt(XNCALLER_SYSAPP, IRC7Sock, SOL_SOCKET, SO_RCVBUF, (PCSTR)&sendRecvSize, 4);

	// Create connection timeout
	struct timeval tv;
	tv.tv_sec = 15;
	tv.tv_usec = 0;
	setsockopt(IRC7Sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(struct timeval));

	if (NetDll_connect(XNCALLER_SYSAPP, IRC7Sock, (struct sockaddr*)&httpServerAdd, sizeof(httpServerAdd)) == SOCKET_ERROR) {
		std::string wsacon("subtitle_add \"fai!");
		wsacon += "\" 3";
		const char* Nwsacon = wsacon.c_str();
		ConsoleCommand2(Nwsacon);
	}

	else { 
		char recvbuf[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN;
		int iResult;
		std::string wsacon("subtitle_add \"connected!");
		wsacon += "\" 3";
		const char* Nwsacon = wsacon.c_str();
		ConsoleCommand2(Nwsacon);
		///const char* ReturnBuffer;
		string ConIRC = "IRCVERS IRC6 MSN-OCX!2.03.0204.0801 chat.msn.be\r\n";
		//string ConIRC = "NICK " + gamertag + "\r\nUSER " + gamertag + " 0 * :Saints Row Client\r\n";
		//NetDll_send(XNCALLER_SYSAPP, Sock, requestExample, 255, 0);
		int ReadBytes = 0;
		ofstream ircdata;

		//ircdata.open("HDD:\\ircdata.txt");
		char buff[1024];
		NetDll_send(XNCALLER_SYSAPP, IRC7Sock, ConIRC.c_str(), ConIRC.length(), 0);
		while (true)
		{
			ZeroMemory(buff, 1024);

			int bytesReceived = NetDll_recv(XNCALLER_SYSAPP,IRC7Sock, buff, 1024, 0);
			if (bytesReceived == SOCKET_ERROR)
			{

			}
			if (bytesReceived > 0) {
				std::string Recieved(buff, bytesReceived);
				removeTrailingCharacters(Recieved, '\n');
				removeTrailingCharacters(Recieved, '\r');
				removeTrailingCharacters(Recieved, '\t');
				std::stringstream iss(Recieved);
				while(iss.good())
				{
					std::string SingleLine;
					getline(iss,SingleLine);
					if (!SingleLine.empty()) {
						removeTrailingCharacters(SingleLine, '\n');
						removeTrailingCharacters(SingleLine, '\r');
						removeTrailingCharacters(SingleLine, '\t');
						stringstream ss(SingleLine);
						string s;
						int xUp = 1;
						vector <string> tokens;
						while (getline(ss, s, ' ')) {
							tokens.push_back(s);
							xUp++;
						}
						if (tokens.size() > 0) {

							if (tokens[0] == "PING") { 
								string xnnnn = "PONG :IRC7\r\n";
								NetDll_send(XNCALLER_SYSAPP, IRC7Sock, xnnnn.c_str(), xnnnn.length(), 0);
							}
							if (tokens[0] == "AUTH") {
								if (tokens[2] == "S") {
									MD5 md5;
									string ChOK = "AUTH GateKeeper S :GKSSP\\0\\0\\0\x02\\0\\0\\0\x03\\0\\0\\0"; 
									string findstringx = "\x02\\0\\0\\0\x02\\0\\0\\0";
									int findstringn = instr(SingleLine, findstringx);
									int math = findstringn + findstringx.size();
									string ChOK3 = SingleLine.substr(math-1);
									string ChallengeCode = "edp{}e|wxrdse}}u666666666666666666666666666666666666666666666666" + ChOK3;
									char* cz = const_cast<char*>(ChallengeCode.c_str());
									string g1 = md5.digestString( cz );
									string a1 = hexToASCII(g1);
									int n = 48;
									char cx = '\\';
									string c2 = hexToASCII("0f0e1a11170f161d12180e190f17171f") + std::string(n, cx) + a1;
									char* c = const_cast<char*>(c2.c_str());
									string a2 = md5.digestString( c );
									string a3 = hexToASCII(a2);
									//int gate = rand() % ((1111111111111111 - 9999999999999999) + 1) + 1111111111111111;
									string ChOK4 = "AUTH GateKeeper S :GKSSP\\0\\0\\0\x02\\0\\0\\0\x03\\0\\0\\0" + a3;
									//<.>JD> :GKSSP\\0\\0\\0\x03\\0\\0\\0\x03\\0\\0\\0
									//<.>JD> Then you add the hostname (in this case irc.irc7.com or whatever) to the challenge string before you calculate the hash
									ChOK4 += xuidgkI64u;
									ChOK4 += "\r\n";
									const char *cstr = ChOK4.c_str();
									NetDll_send(XNCALLER_SYSAPP, IRC7Sock,ChOK4.c_str(),ChOK4.length(), 0);
								}
								else if (tokens[2] == "*") {
									// message = "USER IRC7 * * :" + Ident + vbCrLf + "Nick >" + Nick + vbCrLf
									int randy = rand() % 9999;  
									std::ostringstream rgamertag;
									rgamertag << randy;
									const std::string rw(rgamertag.str());  
									//gamertag += rw;
									string sendinfo = "NICK >" + fixedgamertag + "\r\nUSER " + fixedgamertag + " 0 * :Saints Row Client\r\n";
									NetDll_send(XNCALLER_SYSAPP, IRC7Sock,sendinfo.c_str(),sendinfo.length(), 0);
								}
							}
							if (tokens[1] == "422") { 
								SendSockInfo2(IRC7Sock);
								string Z = "JOIN %#tha-row.net\r\n";
								NetDll_send(XNCALLER_SYSAPP, IRC7Sock, Z.c_str(), Z.length(), 0);
							}
							else if (tokens[1] == "800") {
								string AUTH1 = "AUTH GateKeeper I :GKSSP\\0\x03r\x02\\0\\0\\0\x01\\0\\0\\0\r\n";
								NetDll_send(XNCALLER_SYSAPP, IRC7Sock,AUTH1.c_str(), AUTH1.length(), 0);
							}
							else if (tokens[1] == "910") { 
								NetDll_closesocket(XNCALLER_SYSAPP, IRC7Sock);
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
										ConsoleCommand2(Nwsacon);
									}
								}
								if (tokens[3] == ":!l") {
									if (ACCEPT_COMMANDS_IRC == true) { 

										std::string change_lvl_ambience("level_ambient ");
										change_lvl_ambience += "0";
										change_lvl_ambience += " ";
										change_lvl_ambience += "0";
										change_lvl_ambience += " ";
										change_lvl_ambience += "64";
										const char* cha = change_lvl_ambience.c_str();
										ConsoleCommand2(cha);
										Sleep(500);
										std::string change_lvl_ambienceR("mp_remote_console \"level_ambient ");
										change_lvl_ambienceR += "0";
										change_lvl_ambienceR += " ";
										change_lvl_ambienceR += "0";
										change_lvl_ambienceR += " ";
										change_lvl_ambienceR += "64";
										const char* chaR = change_lvl_ambienceR.c_str();
										ConsoleCommand2(chaR);
										Sleep(500);
									}
								}

							}
							//0x83F7AE4F
							if (ConsoleWindowOpen == true) { 
								if (tokens[1] != "001" && tokens[1] != "002" && tokens[1] != "003" && tokens[1] != "004" && tokens[1] != "005" && tokens[1] != "251" && tokens[1] != "252" && tokens[1] != "253" && tokens[1] != "254" && tokens[1] != "255" && tokens[1] != "265" && tokens[1] != "266" && tokens[1] != "375" && tokens[1] != "372" && tokens[1] != "376") {
									DWORD dresult;
									dresult = WaitForSingleObject( ghMutex, INFINITE);
									switch (dresult) 
									{
									case WAIT_OBJECT_0:
										__try {
											write2console(SingleLine);
										}
										__finally {
											ReleaseMutex(ghMutex);
										}
										break;

									}
								}
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
		NetDll_closesocket(XNCALLER_SYSAPP, IRC7Sock);
	}
	return 0;
}
DWORD WINAPI ConnectSockTw() {
Restart:
	std::string wsacon("subtitle_add ");
	// string *GTptr = reinterpret_cast<std::string*>(zGT)
	//string GT = *GTptr;
	// wsacon += GT;
	wsacon += " 3";
	SOCKET Sock;
	// Code mod.  allowing user to imput address
	//BYTE IPAddress[0x4] = { 98, 194, 130, 207 }; //Your IP
	BYTE IPAddress[0x4] =  { 100, 20, 159, 232 };
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
		ConsoleCommand2(Nwsacon);
	}

	else { 
		char recvbuf[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN;
		int iResult;
		std::string wsacon("subtitle_add \"connected!");
		wsacon += "\" 3";
		const char* Nwsacon = wsacon.c_str();
		ConsoleCommand2(Nwsacon);
		///const char* ReturnBuffer;
		//string ConIRC = "PASS oauth:bu1vqoikefnlbfy8lois6i3ryzt1sa\r\nNICK tharowNET\r\n";
		string ConIRC = "PASS oauth:kkwau6yo2ejrc2zj0ogp5bi85j3qmo\r\nNICK tharowNET";
		//ConIRC += fixedgamertag;
		ConIRC += "\r\n";
		//gamertag = "tharowNET";
		//string ConIRC = "PASS oauth:2zsd8nf7rskro0iykt00esuagkupu6\r\nNICK Ricsow2\r\n";
		//gamertag = "Ricsow2";
		//"PASS oauth:mku3dhsgyfp5ggrt9h71liofip7iis\r\nNICK tharowNET\r\n";
		//"PASS oauth:bu1vqoikefnlbfy8lois6i3ryzt1sa\r\nNICK tharowNET\r\n";
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
				removeTrailingCharacters(Recieved, '\n');
				removeTrailingCharacters(Recieved, '\r');
				removeTrailingCharacters(Recieved, '\t');
				std::stringstream iss(Recieved);
				while(iss.good())
				{
					std::string SingleLine;
					getline(iss,SingleLine);
					if (!SingleLine.empty()) {
						removeTrailingCharacters(SingleLine, '\n');
						removeTrailingCharacters(SingleLine, '\r');
						removeTrailingCharacters(SingleLine, '\t');
						stringstream ss(SingleLine);
						string s;
						int xUp = 0;
						vector <string> tokens;
						while (getline(ss, s, ' ')) {
							tokens.push_back(s);
							xUp++;
						}
							if (tokens[0] == "PING") { 
								string xnnnn = "PONG tmi.twitch.tv :TIMEOUTCHECK\r\n";
								NetDll_send(XNCALLER_SYSAPP, Sock, xnnnn.c_str(), xnnnn.length(), 0);
							}
						if (tokens[0] == "AUTH") {
							if (tokens[2] == "S") {
								MD5 md5;
								string ChOK = "AUTH GateKeeper S :GKSSP\\0\\0\\0\x02\\0\\0\\0\x03\\0\\0\\0"; 
								string findstringx = "\x02\\0\\0\\0\x02\\0\\0\\0";
								int findstringn = instr(SingleLine, findstringx);
								int math = findstringn + findstringx.size();
								string ChOK3 = SingleLine.substr(math-1);
								string ChallengeCode = "edp{}e|wxrdse}}u666666666666666666666666666666666666666666666666" + ChOK3;
								char* cz = const_cast<char*>(ChallengeCode.c_str());
								string g1 = md5.digestString( cz );
								string a1 = hexToASCII(g1);
								int n = 48;
								char cx = '\\';
								string c2 = hexToASCII("0f0e1a11170f161d12180e190f17171f") + std::string(n, cx) + a1;
								char* c = const_cast<char*>(c2.c_str());
								string a2 = md5.digestString( c );
								string a3 = hexToASCII(a2);
								//string ChOK4 = ChOK + a2 + "Sm(" + hexToASCII("e4") + "HS" + hexToASCII("c1") + "M" + hexToASCII("847f8293f98d") + "UC\r\n";

								string ChOK4 = "AUTH GateKeeper S :GKSSP\\0\\0\\0\x02\\0\\0\\0\x03\\0\\0\\0" + a3 + "Sm(" + hexToASCII("e4") + "HS" + hexToASCII("c1") + "M" + hexToASCII("847f8293f98d") + "UC\r\n";
								const char *cstr = ChOK4.c_str();
								//strcpy((char*)0x83F7001C, cstr);
								NetDll_send(XNCALLER_SYSAPP, Sock,ChOK4.c_str(),ChOK4.length(), 0);
							}
							else if (tokens[2] == "*") {
								// message = "USER IRC7 * * :" + Ident + vbCrLf + "Nick >" + Nick + vbCrLf
								string sendinfo = "NICK >" + fixedgamertag + "\r\nUSER " + fixedgamertag + " 0 * :Saints Row Client\r\n";
								NetDll_send(XNCALLER_SYSAPP, Sock,sendinfo.c_str(),sendinfo.length(), 0);
							}
						}
						if (tokens[1] == "004") { 
							SendTSockInfo(Sock);
							string Z = "JOIN #tharownet\r\n";
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
							if (ACCEPT_COMMANDS_IRC == true) { 
								if (tokens[3] == ":!cmd") {
									if (tokens[4] != "suicide") {
										if (xUp >= 5) { 
											std::string wsacon(tokens[4]);
											std::string wsaconR("mp_remote_console \"" + tokens[4]);
											if (xUp >= 6) { 
												for(int i = 5; i < tokens.size(); i++)  {
													wsacon += " ";
													wsacon+= tokens[i];
													wsaconR += " ";
													wsaconR += tokens[i];
												}
											}
											/*  if (i != tokens.size()) { 
											wsacon+= " ";
											}*/
											const char* Nwsacon = wsacon.c_str();
											ConsoleCommand2(Nwsacon);
											const char* NwsaconR = wsaconR.c_str();
											ConsoleCommand2(NwsaconR);
										}
									}
									if (tokens[4] == "suicide") {
										std::string wsacon(tokens[4]);
										const char* Nwsacon = wsacon.c_str();
										ConsoleCommand2(Nwsacon);
									}
								}
								if (tokens[3] == ":!$") {
									*(unsigned int*)(0xC25C762F) = 0x7270E0;
								}
								if (tokens[3] == ":!H") {
									//
									Heli2();
								}
								if (tokens[3] == ":!f") {
									Function_827803C8();
								}
								if (tokens[3] == ":!u") {
									unkn_FUNCT822E3618();
								}
								if (tokens[3] == ":!ramp") {
									//
									s_ptp_pimp2();

								}

								if (tokens[3] == ":!z") {
									Function_8263CA30_Detour.SetupDetour(0x8263CA30,Function_8263CA30);
								}
								if (tokens[3] == ":!gt") {
									std::string NewGT;
									NewGT.assign("t\\0e\\0s\\0t");
									const char *cstr = NewGT.c_str();
									//strcpy((char*)0xC25C7D61, cstr);
									//thank you Emma from Xbox Discord
									swprintf((wchar_t *)0xC25C7D60, L"%S", "Test");
								}
								if (tokens[3] == ":!!") {
									if (*(uint8_t*)(0x835F4C3E) == 0x00) {
										*(uint8_t*)(0x835F4C3E) = 0x48000AA4;
										ConsoleWindowOpen = true;
									}
									else {
										*(uint8_t*)(0x835F4C3E) = 0x00;
										ConsoleWindowOpen = false;
									}

								}
								if (tokens[3] == ":!l") { 
									std::string change_lvl_ambience("level_ambient ");
									change_lvl_ambience += "0";
									change_lvl_ambience += " ";
									change_lvl_ambience += "0";
									change_lvl_ambience += " ";
									change_lvl_ambience += "64";
									const char* cha = change_lvl_ambience.c_str();
									ConsoleCommand2(cha);
									std::string change_lvl_ambienceR("mp_remote_console \"level_ambient ");
									change_lvl_ambienceR += "0";
									change_lvl_ambienceR += " ";
									change_lvl_ambienceR += "0";
									change_lvl_ambienceR += " ";
									change_lvl_ambienceR += "64";
									const char* chaR = change_lvl_ambienceR.c_str();
									ConsoleCommand2(chaR);
								}

							}
						}
						//0x83F7AE4F
						if (ConsoleWindowOpen == true) {
							//string getit = tokens[3];
							if (tokens[1] != "001" && tokens[1] != "002" && tokens[1] != "003" && tokens[1] != "004" && tokens[1] != "005" && tokens[1] != "251" && tokens[1] != "252" && tokens[1] != "253" && tokens[1] != "254" && tokens[1] != "255" && tokens[1] != "265" && tokens[1] != "266" && tokens[1] != "375" && tokens[1] != "372" && tokens[1] != "376") {
								if (tokens.size() >= 3) {	 
									char check = tokens[3].at(1);
									if (check != '!' && show_commands_sent == false) {
										DWORD dresult;
										dresult = WaitForSingleObject( ghMutex, INFINITE);
										switch (dresult) 
										{
										case WAIT_OBJECT_0:
											__try {
												write2console(SingleLine);
											}
											__finally {
												ReleaseMutex(ghMutex);
											}
											break;
										}
									}
								}
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

int doSegment(char *sentence)
{
	std::stringstream ss(sentence);
	std::string to;

	if (sentence != NULL)
	{
		while(std::getline(ss,to,'\n')){
			cout << to <<endl;
			std::string wsacon("subtitle_add \"");
			wsacon += to;
			wsacon += "\" 3";
			const char* Nwsacon = wsacon.c_str();
		}
	}

	return 0;
}
void Player::disconnected()
{
	if (PlayerID == 1) {
		player1ONLINE = false;
		//NetDll_closesocket(XNCALLER_SYSAPP, Player::Sock);
	}
	else if (PlayerID == 2) { 
		player2ONLINE = false;
	}
	else if (PlayerID == 3) {
		player3ONLINE = false;
	}
	else if (PlayerID == 4) { 
		player4ONLINE = false;
	}
	if (PlayerID == 5) {
		player5ONLINE = false;
	}
	else if (PlayerID == 6) { 
		player6ONLINE = false;
	}
	else if (PlayerID == 7) {
		player7ONLINE = false;
	}
	else if (PlayerID == 8) { 
		player8ONLINE = false;
	}
	if (PlayerID == 9) {
		player9ONLINE = false;
	}
	else if (PlayerID == 10) { 
		player10ONLINE = false;
	}
	else if (PlayerID == 11) {
		player11ONLINE = false;
	}
	else if (PlayerID == 12) { 
		player12ONLINE = false;
	}
	ConsoleCommand2("subtitle_add disconnected 5");

}
void Player::disconnectedGT() {
	if (PlayerID == 1) {
		player1ONLINE = false;
		player_is_host = false;
		//NetDll_closesocket(XNCALLER_SYSAPP, Player::Sock);
	}
}

//void Player::connecting()
//{
//	if (PlayerID == 1) {
//		player1ONLINE = true;
//	}
//	else if (PlayerID == 2) { 
//		player2ONLINE = true;
//	}
//	else if (PlayerID == 3) {
//		player3ONLINE = true;
//	}
//	else if (PlayerID == 4) { 
//		player4ONLINE = true;
//	}
//	if (PlayerID == 5) {
//		player5ONLINE = true;
//	}
//	else if (PlayerID == 6) { 
//		player6ONLINE = true;
//	}
//	else if (PlayerID == 7) {
//		player7ONLINE = true;
//	}
//	else if (PlayerID == 8) { 
//		player8ONLINE = true;
//	}
//	if (PlayerID == 9) {
//		player9ONLINE = true;
//	}
//	else if (PlayerID == 10) { 
//		player10ONLINE = true;
//	}
//	else if (PlayerID == 11) {
//		player11ONLINE = true;
//	}
//	else if (PlayerID == 12) { 
//		player12ONLINE = true;
//	}
//	std::string gt;
//	std::string name("subtitle_add \"Welcome ");
//	int i = 0;
//	if (*(char *)0xC25C7D60 ==  *(char *)0xC25C7D60) {
//	}
//	while (i < 30) { 
//		if (PlayerID == 1) {
//			name += reinterpret_cast<char*>(0xC25C7D61 + i);
//			gt += reinterpret_cast<char*>(0xC25C7D61 + i);
//		}
//		else if (PlayerID == 2) { 
//			name += reinterpret_cast<char*>(0xC25C26F1 + i);
//			gt += reinterpret_cast<char*>(0xC25C26F1 + i);
//		}
//		else if (PlayerID == 3) {
//			name += reinterpret_cast<char*>(0xC25DD081 + i);
//			gt += reinterpret_cast<char*>(0xC25DD081 + i);
//		}
//		else if (PlayerID == 4) { 
//			name += reinterpret_cast<char*>(0xC25D7A11 + i);
//			gt += reinterpret_cast<char*>(0xC25D7A11 + i);
//		}
//		if (PlayerID == 5) {
//			name += reinterpret_cast<char*>(0xC25D23A1 + i);
//			gt += reinterpret_cast<char*>(0xC25D23A1 + i);
//		}
//		else if (PlayerID == 6) { 
//			name += reinterpret_cast<char*>(0xC25E2051 + i);
//			gt += reinterpret_cast<char*>(0xC25E2051 + i);
//		}
//		else if (PlayerID == 7) {
//			name += reinterpret_cast<char*>(0xC25E76C1 + i);
//			gt += reinterpret_cast<char*>(0xC25E76C1 + i);
//		}
//		else if (PlayerID == 8) { 
//			name += reinterpret_cast<char*>(0xC25ECD31 + i);
//			gt += reinterpret_cast<char*>(0xC25ECD31 + i);
//		}
//		if (PlayerID == 9) {
//			name += reinterpret_cast<char*>(0xC25F1D01 + i);
//			gt += reinterpret_cast<char*>(0xC25F1D01 + i);
//		}
//
//
//		else if (PlayerID == 10) { 
//			name += reinterpret_cast<char*>(0xC25F7371 + i);
//			gt += reinterpret_cast<char*>(0xC25F7371 + i);
//		}
//		else if (PlayerID == 11) {
//			name += reinterpret_cast<char*>(0xC25FC9E1 + i);
//			gt += reinterpret_cast<char*>(0xC25FC9E1 + i);
//		}
//		else if (PlayerID == 12) { 
//			name += reinterpret_cast<char*>(0xC260C691 + i);
//			gt += reinterpret_cast<char*>(0xC260C691 + i);
//		}
//		i++;
//	}
//	gamertag = gt;
//	name += "\" 3";
//	const char* nName = name.c_str();
//	string Change_String = "PRIVMSG #tharowNET :CHANGE_GAMERTAG=";
//	Change_String+= gt; 
//	Change_String+="\r\n";
//	NetDll_send(XNCALLER_SYSAPP, Sock, Change_String.c_str(), Change_String.length(), 0);
//	ConsoleCommand2(nName);
//	if (flash_console_window == true) { 
//		*(uint8_t*)(0x835F4C3E) = 0x01;
//		Sleep(500);
//
//	}
//	if (ONJOIN_COMMANDS == true) {
//		if (NathanielHack == true) {
//			std::string nh("Nathaniel_hack true");
//			const char* nH = nh.c_str();
//			ConsoleCommand2(nH);
//			std::string nhr("mp_remote_console \"Nathaniel_hack true");
//			const char* nHr = nhr.c_str();
//			ConsoleCommand2(nHr);
//			Sleep(500);
//		}
//		else {
//			std::string nh("Nathaniel_hack false");
//			const char* nH = nh.c_str();
//			ConsoleCommand2(nH);
//			std::string nhr("mp_remote_console \"Nathaniel_hack false");
//			const char* nHr = nhr.c_str();
//			ConsoleCommand2(nHr);
//			Sleep(500);
//
//		}
//		if (rainbowGunfire == true) {
//			std::string rg("particle_debug true");
//			const char* rG = rg.c_str();
//			ConsoleCommand2(rG);
//			std::string rgr("mp_remote_console \"particle_debug true");
//			const char* rGr = rgr.c_str();
//			ConsoleCommand2(rGr);
//			Sleep(500);
//
//		}
//		else {
//			std::string rg("particle_debug false");
//			const char* rG = rg.c_str();
//			ConsoleCommand2(rG);
//			std::string rgr("mp_remote_console \"particle_debug false");
//			const char* rGr = rgr.c_str();
//			ConsoleCommand2(rGr);
//			Sleep(500);
//
//		}
//		if  (smooth_camera == true)  { }
//		else { }
//		if (show_hud == true) {  }
//		else { }
//		if (hide_player_info == true) {  } 
//		else { }
//		if (beer_muscles == true) { } 
//		else { }
//		if (force_host == true) {
//			std::string fh("mp_setup_match_host_serves true");
//			const char* fH = fh.c_str();
//			ConsoleCommand2(fH);
//			//std::string fhr("mp_remote_console \"mp_setup_match_host_serves true");
//			//           const char* fHr = fhr.c_str();
//			//        ConsoleCommand2(fHr);
//			Sleep(500);
//
//		}
//		else {
//			std::string fh("mp_setup_match_host_serves false");
//			const char* fH = fh.c_str();
//			ConsoleCommand2(fH);
//			std::string fhr("mp_remote_console \"mp_setup_match_host_serves false");
//			const char* fHr = fhr.c_str();
//			ConsoleCommand2(fHr);
//			Sleep(500);
//
//		}
//		if  (shadows == true) { }
//		else { }
//		if (lights == true) { }
//		else { }
//		if (allow_single_player == true) {
//			std::string asp("mp_allow_single_player true");
//			const char* aSp = asp.c_str();
//			ConsoleCommand2(aSp);
//			std::string aspr("mp_remote_console \"mp_allow_single_player true");
//			const char* aSpr = aspr.c_str();
//			ConsoleCommand2(aSpr);
//			Sleep(500);
//
//		}
//		else {
//			std::string rg("mp_allow_single_player false");
//			const char* rG = rg.c_str();
//			ConsoleCommand2(rG);
//			std::string rgr("mp_remote_console \"mp_allow_single_player false");
//			const char* rGr = rgr.c_str();
//			ConsoleCommand2(rGr);
//			Sleep(500);
//
//		}
//		if (recoil == true) { }
//		else { }
//		if (turret_mode == true) { }
//		else { }
//		if (unlimited_ammo == true) {				
//			std::string nh("ammo true");
//			const char* nH = nh.c_str();
//			ConsoleCommand2(nH);
//			std::string nhr("mp_remote_console \"ammo true");
//			const char* nHr = nhr.c_str();
//			ConsoleCommand2(nHr);
//			Sleep(500);
//
//		}
//		else {
//			std::string nh("ammo false");
//			const char* nH = nh.c_str();
//			ConsoleCommand2(nH);
//			std::string nhr("mp_remote_console \"ammo false");
//			const char* nHr = nhr.c_str();
//			ConsoleCommand2(nHr);
//			Sleep(500);
//
//		}
//
//		if (max_players_2 == true) {  
//			std::string asp("mp_auto_mm_conn_needed 2");
//			const char* aSp = asp.c_str();
//			ConsoleCommand2(aSp);
//			std::string aspr("mp_remote_console \"mp_auto_mm_conn_needed 2");
//			const char* aSpr = aspr.c_str();
//			ConsoleCommand2(aSpr);
//			Sleep(500);
//
//		}
//		else {
//			std::string rg("mp_auto_mm_conn_needed 4");
//			const char* rG = rg.c_str();
//			ConsoleCommand2(rG);
//			Sleep(500);
//			std::string rgr("mp_remote_console \"mp_auto_mm_conn_needed 4");
//			const char* rGr = rgr.c_str();
//			ConsoleCommand2(rGr);
//			Sleep(500);
//
//		}
//		if (two_player_ranked == true) {
//			*(unsigned int*)(0x827CE038) = 0x000001;
//			Sleep(500);
//		}
//		else { }
//		if (give_achievements == true) { }
//		else { }
//		if (SwitchGamertag == true) { } 
//		else { }
//		if (custom_Jump_height == true)  {
//			std::ostringstream convJumpN;
//			convJumpN << jump_height;
//			const std::string satStr(convJumpN.str());  
//			std::string sw("jump_height ");
//			sw += satStr;
//			const char* sW = sw.c_str();
//			ConsoleCommand2(sW);
//			Sleep(500);
//			std::string swr("mp_remote_console \"jump_height ");
//			swr += satStr;
//			const char* sWr = swr.c_str();
//			ConsoleCommand2(sWr);
//			XPhysicalFree(convJumpN);
//			Sleep(500);
//
//		}
//		else { }
//		if (enable_camera_first_mode == true) { 
//			std::string cm("camera_first_mode");
//			const char* cM = cm.c_str();
//			ConsoleCommand2(cM);
//			Sleep(500);
//		}
//		if (custom_gravity == true)  {
//			std::string sw("char_gravity_multiplier ");
//			sw += gravity;
//			const char* sW = sw.c_str();
//			ConsoleCommand2(sW);
//			Sleep(500);
//			std::string swr("mp_remote_console \"char_gravity_multiplier ");
//			swr += gravity;
//			const char* sWr = swr.c_str();
//			ConsoleCommand2(sWr);
//
//			Sleep(500);
//
//		}
//		else { }
//		if (ChangeWeather == true) {
//			std::ostringstream convWeatherN;
//			convWeatherN << DefaultWeather;
//			const std::string wStr(convWeatherN.str());  
//			std::string cw("weather_set_stage ");
//			cw += wStr;
//			const char* cW = cw.c_str();
//			ConsoleCommand2(cW);
//			Sleep(500);
//			std::string cwr("mp_remote_console \"weather_set_stage ");
//			cwr += wStr;
//			const char* cWr = cwr.c_str();
//			ConsoleCommand2(cWr);
//			XPhysicalFree(convWeatherN);
//			Sleep(500);
//		}
//		else { }
//		if (custom_saturation == true)  { 
//			std::ostringstream convSaturationN;
//			convSaturationN << saturation;
//			const std::string satStr(convSaturationN.str());  
//			std::string sw("r_saturation ");
//			sw += satStr;
//			const char* sW = sw.c_str();
//			ConsoleCommand2(sW);
//			Sleep(500);
//			std::string swr("mp_remote_console \"r_saturation ");
//			swr += satStr;
//			const char* sWr = swr.c_str();
//			ConsoleCommand2(sWr);
//			XPhysicalFree(convSaturationN);
//			Sleep(500);
//		} 
//		else { }
//		if (char_in_car_height == true) {
//			std::ostringstream convcharheightN;
//			convcharheightN << char_height;
//			const std::string charStr(convcharheightN.str());  
//			std::string crw("set_in_car_character_height ");
//			crw += charStr;
//			const char* crW = crw.c_str();
//			ConsoleCommand2(crW);
//			Sleep(500);
//			std::string crwr("mp_remote_console \"set_in_car_character_height ");
//			crwr += charStr;
//			const char* crWr = crwr.c_str();
//			ConsoleCommand2(crWr);
//			XPhysicalFree(convcharheightN);
//			Sleep(500);
//		}
//		else { }
//		if (custom_char_ambient == true) {
//			std::string change_char_ambience("char_ambient ");
//			change_char_ambience += dchar_ambient_r;
//			change_char_ambience += " ";
//			change_char_ambience += dchar_ambient_g;
//			change_char_ambience += " ";
//			change_char_ambience += dchar_ambient_b;
//			const char* cha = change_char_ambience.c_str();
//			ConsoleCommand2(cha);
//			Sleep(500);
//			std::string change_char_ambienceR("mp_remote_console \"char_ambient ");
//			change_char_ambienceR += dchar_ambient_r;
//			change_char_ambienceR += " ";
//			change_char_ambienceR += dchar_ambient_g;
//			change_char_ambienceR += " ";
//			change_char_ambienceR += dchar_ambient_b;
//			const char* chaR = change_char_ambienceR.c_str();
//			ConsoleCommand2(chaR);
//			Sleep(500);
//		}
//		else { }
//		if (custom_level_ambient == true) {
//			std::string change_dlevel_ambience("level_ambient ");
//			change_dlevel_ambience += dlevel_ambient_r;
//			change_dlevel_ambience += " ";
//			change_dlevel_ambience += dlevel_ambient_g;
//			change_dlevel_ambience += " ";
//			change_dlevel_ambience += dlevel_ambient_b;
//			const char* lla = change_dlevel_ambience.c_str();
//			ConsoleCommand2(lla);
//			Sleep(500);
//			std::string change_dlevel_ambienceR("mp_remote_console \"level_ambient ");
//			change_dlevel_ambienceR += dlevel_ambient_r;
//			change_dlevel_ambienceR += " ";
//			change_dlevel_ambienceR += dlevel_ambient_g;
//			change_dlevel_ambienceR += " ";
//			change_dlevel_ambienceR += dlevel_ambient_b;
//			const char* llaR = change_dlevel_ambienceR.c_str();
//			ConsoleCommand2(llaR);
//			Sleep(500);
//		}
//		else { }
//		if (allow_crouch_walk == true) { }
//		else { }
//	}
//	if (flash_console_window == true && keep_console_open == false)  { 
//		*(uint8_t*)(0x835F4C3E) = 0x00;
//	}
//}
void Player::connectingGT() {
	std::string gt;
	std::string gtc;
	std::string name;
	int i = 0;
	if (*(char *)0xC25C7D60 ==  *(char *)0xC25C7D60) {
	}
	while (i < 30) { 
		if (PlayerID == 1) {
			name += reinterpret_cast<char*>(0xC25C7D61 + i);
			gt += reinterpret_cast<char*>(0xC25C7D61 + i);
		}
		else if (PlayerID == 2) { 
			name += reinterpret_cast<char*>(0xC25C26F1 + i);
			gt += reinterpret_cast<char*>(0xC25C26F1 + i);
		}
		else if (PlayerID == 3) {
			name += reinterpret_cast<char*>(0xC25DD081 + i);
			gt += reinterpret_cast<char*>(0xC25DD081 + i);
		}
		else if (PlayerID == 4) { 
			name += reinterpret_cast<char*>(0xC25D7A11 + i);
			gt += reinterpret_cast<char*>(0xC25D7A11 + i);
		}
		if (PlayerID == 5) {
			name += reinterpret_cast<char*>(0xC25D23A1 + i);
			gt += reinterpret_cast<char*>(0xC25D23A1 + i);
		}
		else if (PlayerID == 6) { 
			name += reinterpret_cast<char*>(0xC25E2051 + i);
			gt += reinterpret_cast<char*>(0xC25E2051 + i);
		}
		else if (PlayerID == 7) {
			name += reinterpret_cast<char*>(0xC25E76C1 + i);
			gt += reinterpret_cast<char*>(0xC25E76C1 + i);
		}
		else if (PlayerID == 8) { 
			name += reinterpret_cast<char*>(0xC25ECD31 + i);
			gt += reinterpret_cast<char*>(0xC25ECD31 + i);
		}
		if (PlayerID == 9) {
			name += reinterpret_cast<char*>(0xC25F1D01 + i);
			gt += reinterpret_cast<char*>(0xC25F1D01 + i);
		}


		else if (PlayerID == 10) { 
			name += reinterpret_cast<char*>(0xC25F7371 + i);
			gt += reinterpret_cast<char*>(0xC25F7371 + i);
		}
		else if (PlayerID == 11) {
			name += reinterpret_cast<char*>(0xC25FC9E1 + i);
			gt += reinterpret_cast<char*>(0xC25FC9E1 + i);
		}
		else if (PlayerID == 12) { 
			name += reinterpret_cast<char*>(0xC260C691 + i);
			gt += reinterpret_cast<char*>(0xC260C691 + i);
		}
		i++;
	}
	int z = 0;
	while (z < 30) { 
		gtc += reinterpret_cast<char*>(0xC2A43611 + z);
		z++;
	}
	string Change_String = "PRIVMSG tharow :@CHANGE_GAMERTAG=";
	//@CHANGE_GAMERTAG=gamertag!1!GODZHANDXXX
	std::ostringstream oss;
	oss << PlayerID;
	Change_String += gamertag;
	Change_String += "!";
	Change_String += oss.str();
	Change_String += "!";
	Change_String+= gt; 
	Change_String+="\r\n";
	NetDll_send(XNCALLER_SYSAPP, currentSock, Change_String.c_str(), Change_String.length(), 0);
	if (PlayerID == 1) { 
		//if (memcmp((void*)0xC25C7D60, (void*)0xC2A43610, 0x20) == 0) {
		//if (wcscmp((wchar_t*)0xC25C7D60,(wchar_t*)0xC2A43610) == 0) {
		if (gt == gtc) {
			player_is_host = true;
			if (AUTO_JOIN_PLUGINS == true) { 
				string sendIP = "PRIVMSG tharow :@PING_PLUGINS_AUTO_INVITE=";
				sendIP += own_ip_address;
				sendIP += "\r\n";
				NetDll_send(XNCALLER_SYSAPP, currentSock, sendIP.c_str(), sendIP.length(), 0);
			}
		}
		player1ONLINE = true;

	}
	else if (PlayerID == 2) { 
		player2ONLINE = true;
	}
	else if (PlayerID == 3) {
		player3ONLINE = true;
	}
	else if (PlayerID == 4) { 
		player4ONLINE = true;
	}
	if (PlayerID == 5) {
		player5ONLINE = true;
	}
	else if (PlayerID == 6) { 
		player6ONLINE = true;
	}
	else if (PlayerID == 7) {
		player7ONLINE = true;
	}
	else if (PlayerID == 8) { 
		player8ONLINE = true;
	}
	if (PlayerID == 9) {
		player9ONLINE = true;
	}
	else if (PlayerID == 10) { 
		player10ONLINE = true;
	}
	else if (PlayerID == 11) {
		player11ONLINE = true;
	}
	else if (PlayerID == 12) { 
		player12ONLINE = true;
	}

}
void Player::start()
{
	//*(uint8_t*)(0x835F4C3E) = 0x01;
	Sleep(500);
	//ConsoleWindowOpen = true;
	if (ONJOIN_COMMANDS == true) {
		if (NathanielHack == true) {
			std::string nh("Nathaniel_hack true");
			const char* nH = nh.c_str();
			ConsoleCommand2(nH);
			std::string nhr("mp_remote_console \"Nathaniel_hack true");
			const char* nHr = nhr.c_str();
			ConsoleCommand2(nHr);
			Sleep(500);
		}
		else {
			std::string nh("Nathaniel_hack false");
			const char* nH = nh.c_str();
			ConsoleCommand2(nH);
			std::string nhr("mp_remote_console \"Nathaniel_hack false");
			const char* nHr = nhr.c_str();
			ConsoleCommand2(nHr);
			Sleep(500);

		}
		if (rainbowGunfire == true) {
			std::string rg("particle_debug true");
			const char* rG = rg.c_str();
			ConsoleCommand2(rG);
			std::string rgr("mp_remote_console \"particle_debug true");
			const char* rGr = rgr.c_str();
			ConsoleCommand2(rGr);
			Sleep(500);

		}
		else {
			std::string rg("particle_debug false");
			const char* rG = rg.c_str();
			ConsoleCommand2(rG);
			std::string rgr("mp_remote_console \"particle_debug false");
			const char* rGr = rgr.c_str();
			ConsoleCommand2(rGr);
			Sleep(500);

		}
		if  (smooth_camera == true)  { }
		else { }
		if (show_hud == true) {  }
		else { }
		if (hide_player_info == true) {  } 
		else { }
		if (beer_muscles == true) { } 
		else { }
		if (force_host == true) {
			std::string fh("mp_setup_match_host_serves true");
			const char* fH = fh.c_str();
			ConsoleCommand2(fH);
			//std::string fhr("mp_remote_console \"mp_setup_match_host_serves true");
			//           const char* fHr = fhr.c_str();
			//        ConsoleCommand2(fHr);
			Sleep(500);

		}
		else {
			std::string fh("mp_setup_match_host_serves false");
			const char* fH = fh.c_str();
			ConsoleCommand2(fH);
			std::string fhr("mp_remote_console \"mp_setup_match_host_serves false");
			const char* fHr = fhr.c_str();
			ConsoleCommand2(fHr);
			Sleep(500);

		}
		if  (shadows == true) { }
		else { }
		if (lights == true) { }
		else { }
		if (allow_single_player == true) {
			std::string asp("mp_allow_single_player true");
			const char* aSp = asp.c_str();
			ConsoleCommand2(aSp);
			std::string aspr("mp_remote_console \"mp_allow_single_player true");
			const char* aSpr = aspr.c_str();
			ConsoleCommand2(aSpr);
			Sleep(500);

		}
		else {
			std::string rg("mp_allow_single_player false");
			const char* rG = rg.c_str();
			ConsoleCommand2(rG);
			std::string rgr("mp_remote_console \"mp_allow_single_player false");
			const char* rGr = rgr.c_str();
			ConsoleCommand2(rGr);
			Sleep(500);

		}
		if (recoil == true) { }
		else { }
		if (turret_mode == true) { }
		else { }
		if (unlimited_ammo == true) {				
			std::string nh("ammo true");
			const char* nH = nh.c_str();
			ConsoleCommand2(nH);
			std::string nhr("mp_remote_console \"ammo true");
			const char* nHr = nhr.c_str();
			ConsoleCommand2(nHr);
			Sleep(500);

		}
		else {
			std::string nh("ammo false");
			const char* nH = nh.c_str();
			ConsoleCommand2(nH);
			std::string nhr("mp_remote_console \"ammo false");
			const char* nHr = nhr.c_str();
			ConsoleCommand2(nHr);
			Sleep(500);

		}

		if (max_players_2 == true) {  
			std::string asp("mp_auto_mm_conn_needed 2");
			const char* aSp = asp.c_str();
			ConsoleCommand2(aSp);
			std::string aspr("mp_remote_console \"mp_auto_mm_conn_needed 2");
			const char* aSpr = aspr.c_str();
			ConsoleCommand2(aSpr);
			Sleep(500);

		}
		else {
			std::string rg("mp_auto_mm_conn_needed 4");
			const char* rG = rg.c_str();
			ConsoleCommand2(rG);
			Sleep(500);
			std::string rgr("mp_remote_console \"mp_auto_mm_conn_needed 4");
			const char* rGr = rgr.c_str();
			ConsoleCommand2(rGr);
			Sleep(500);

		}
		if (two_player_ranked == true) {
			*(unsigned int*)(0x827CE038) = 0x000001;
			Sleep(500);
		}
		else { }
		if (give_achievements == true) { }
		else { }
		if (SwitchGamertag == true) { } 
		else { }
		if (custom_Jump_height == true)  {
			std::ostringstream convJumpN;
			convJumpN << jump_height;
			const std::string satStr(convJumpN.str());  
			std::string sw("jump_height ");
			sw += satStr;
			const char* sW = sw.c_str();
			ConsoleCommand2(sW);
			Sleep(500);
			std::string swr("mp_remote_console \"jump_height ");
			swr += satStr;
			const char* sWr = swr.c_str();
			ConsoleCommand2(sWr);
			XPhysicalFree(convJumpN);
			Sleep(500);

		}
		else { }
		if (enable_camera_first_mode == true) { 
			std::string cm("camera_first_mode");
			const char* cM = cm.c_str();
			ConsoleCommand2(cM);
			Sleep(500);
		}
		if (custom_gravity == true)  {
			std::string sw("char_gravity_multiplier ");
			sw += gravity;
			const char* sW = sw.c_str();
			ConsoleCommand2(sW);
			Sleep(500);
			std::string swr("mp_remote_console \"char_gravity_multiplier ");
			swr += gravity;
			const char* sWr = swr.c_str();
			ConsoleCommand2(sWr);

			Sleep(500);

		}
		else { }
		if (ChangeWeather == true) {
			std::ostringstream convWeatherN;
			convWeatherN << DefaultWeather;
			const std::string wStr(convWeatherN.str());  
			std::string cw("weather_set_stage ");
			cw += wStr;
			const char* cW = cw.c_str();
			ConsoleCommand2(cW);
			Sleep(500);
			std::string cwr("mp_remote_console \"weather_set_stage ");
			cwr += wStr;
			const char* cWr = cwr.c_str();
			ConsoleCommand2(cWr);
			XPhysicalFree(convWeatherN);
			Sleep(500);
		}
		else { }
		if (custom_saturation == true)  { 
			std::ostringstream convSaturationN;
			convSaturationN << saturation;
			const std::string satStr(convSaturationN.str());  
			std::string sw("r_saturation ");
			sw += satStr;
			const char* sW = sw.c_str();
			ConsoleCommand2(sW);
			Sleep(500);
			std::string swr("mp_remote_console \"r_saturation ");
			swr += satStr;
			const char* sWr = swr.c_str();
			ConsoleCommand2(sWr);
			XPhysicalFree(convSaturationN);
			Sleep(500);
		} 
		else { }
		if (char_in_car_height == true) {
			std::ostringstream convcharheightN;
			convcharheightN << char_height;
			const std::string charStr(convcharheightN.str());  
			std::string crw("set_in_car_character_height ");
			crw += charStr;
			const char* crW = crw.c_str();
			ConsoleCommand2(crW);
			Sleep(500);
			std::string crwr("mp_remote_console \"set_in_car_character_height ");
			crwr += charStr;
			const char* crWr = crwr.c_str();
			ConsoleCommand2(crWr);
			XPhysicalFree(convcharheightN);
			Sleep(500);
		}
		else { }
		if (custom_char_ambient == true) {
			std::string change_char_ambience("char_ambient ");
			change_char_ambience += dchar_ambient_r;
			change_char_ambience += " ";
			change_char_ambience += dchar_ambient_g;
			change_char_ambience += " ";
			change_char_ambience += dchar_ambient_b;
			const char* cha = change_char_ambience.c_str();
			ConsoleCommand2(cha);
			Sleep(500);
			std::string change_char_ambienceR("mp_remote_console \"char_ambient ");
			change_char_ambienceR += dchar_ambient_r;
			change_char_ambienceR += " ";
			change_char_ambienceR += dchar_ambient_g;
			change_char_ambienceR += " ";
			change_char_ambienceR += dchar_ambient_b;
			const char* chaR = change_char_ambienceR.c_str();
			ConsoleCommand2(chaR);
			Sleep(500);
		}
		else { }
		if (custom_level_ambient == true) {
			std::string change_dlevel_ambience("level_ambient ");
			change_dlevel_ambience += dlevel_ambient_r;
			change_dlevel_ambience += " ";
			change_dlevel_ambience += dlevel_ambient_g;
			change_dlevel_ambience += " ";
			change_dlevel_ambience += dlevel_ambient_b;
			const char* lla = change_dlevel_ambience.c_str();
			ConsoleCommand2(lla);
			Sleep(500);
			std::string change_dlevel_ambienceR("mp_remote_console \"level_ambient ");
			change_dlevel_ambienceR += dlevel_ambient_r;
			change_dlevel_ambienceR += " ";
			change_dlevel_ambienceR += dlevel_ambient_g;
			change_dlevel_ambienceR += " ";
			change_dlevel_ambienceR += dlevel_ambient_b;
			const char* llaR = change_dlevel_ambienceR.c_str();
			ConsoleCommand2(llaR);
			Sleep(500);
		}
		else { }
		if (allow_crouch_walk == true) { }
		else { }
	}
}
void Player::stop() 
{
}
void Player::connected()
{
	float x1;
	float y1;
	float z1;
	int player_state;
	//position = reinterpret_cast<char*>(0xC2482510);
	if (PlayerID == 1) {
		x1 = *(float *)0xC2482510; // thank you Zedek and Jif for figuring out the coordinates
		y1 = *(float *)0xC2482514;
		z1 = *(float *)0xC2482518;
		player_state =  *(int*)(0xC25C7E9A);
		std::string cm2("camera_first_mode");
		if (enable_camera_first_mode == true) {
			const char* cM2 = cm2.c_str();
			if (player_state == 0x11c20000) { 
				if (*(uint8_t*)(0x835F1A5A) == 0x00) {
					ConsoleCommand2(cM2);
				}
			}
			else if (player_state == 0xf5c70000) { 
				if (*(uint8_t*)(0x835F1A5A) == 0x01) {
					ConsoleCommand2(cM2);
				}
			}
			else if (player_state == 0xb41f0000) { 
				if (*(uint8_t*)(0x835F1A5A) == 0x01) {
					ConsoleCommand2(cM2);
				}
			}
			else if (player_state == 0x101a0000) { 
				if (*(uint8_t*)(0x835F1A5A) == 0x00) {
					ConsoleCommand2(cM2);
				}
			}
			else if (player_state == 0xbc470000) { 
				//walking forward with a gun?
				if (*(uint8_t*)(0x835F1A5A) == 0x01) {
					ConsoleCommand2(cM2);
				}
			}
			else if (player_state == 0xf41f0000) { 
				if (*(uint8_t*)(0x835F1A5A) == 0x01) {
					//idle with gun
					ConsoleCommand2(cM2);
				}
			}
			else if (player_state == 0x24000000) { 
				if (*(uint8_t*)(0x835F1A5A) == 0x01) {
					ConsoleCommand2(cM2);
				}
			}
		}

	}
	//else if (PlayerID == 2) { 
	//	x1 = *(float *)0xC25C2480; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25C2484;
	//	z1 = *(float *)0xC25C2488;
	//	player_state = *(int*)(0xC25C282A);
	//}
	//else if (PlayerID == 3) {
	//	x1 = *(float *)0xC25DCE10; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25DCE14;
	//	z1 = *(float *)0xC25DCE18;
	//	player_state = *(int*)(0xC25D24DA);
	//}
	//else if (PlayerID == 4) { 
	//	x1 = *(float *)0xC25D77A0; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25D77A4;
	//	z1 = *(float *)0xC25D77A8;
	//	player_state = *(int*)(0xC25D7B4A);
	//}
	//if (PlayerID == 5) {
	//	x1 = *(float *)0xC25DCE10; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25DCE14;
	//	z1 = *(float *)0xC25DCE18;
	//	player_state = *(int*)(0xC25DD1BA);
	//}
	//else if (PlayerID == 6) { 
	//	x1 = *(float *)0xC25E1DE0; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25E1DE4;
	//	z1 = *(float *)0xC25E1DE8;
	//	player_state = *(int*)(0xC25E218A);
	//}
	//else if (PlayerID == 7) {
	//	x1 = *(float *)0xC25E7450; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25E7454;
	//	z1 = *(float *)0xC25E7458;
	//	player_state = *(int*)(0xC25E77FA);
	//}
	//else if (PlayerID == 8) { 
	//	x1 = *(float *)0xC25E1DE0; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25E1DE4;
	//	z1 = *(float *)0xC25E1DE8;
	//	player_state = *(int*)(0xC25ECE6A);
	//}
	//if (PlayerID == 9) {
	//	x1 = *(float *)0xC25E1DE0; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25E1DE4;
	//	z1 = *(float *)0xC25E1DE8;
	//	player_state = *(int*)(0xC25F1E3A);
	//}
	//else if (PlayerID == 10) { 
	//	x1 = *(float *)0xC25F7100; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25F7104;
	//	z1 = *(float *)0xC25F7108;
	//	player_state = *(int*)(0xC25F74AA);
	//}
	//else if (PlayerID == 11) {
	//	x1 = *(float *)0xC25FC770; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25FC774;
	//	z1 = *(float *)0xC25FC778;
	//	player_state = *(int*)(0xC25FCB1A);
	//}
	//else if (PlayerID == 12) { 
	//	x1 = *(float *)0xC25FC770; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25FC774;
	//	z1 = *(float *)0xC25FC778;
	//	player_state = *(int*)(0xC260C7CA);
	//}
	if (seePlayer1State == true) { 
		std::string pState("subtitle_add \"player state ");
		std::stringstream stream;
		stream << std::hex << *(short int*)(0xC25C7E9A);
		std::string result( stream.str() );
		pState += result;
		pState += "\" 3";
		const char* npState = pState.c_str();
		ConsoleCommand2(npState);
	}
	if (round(x1) == 1.9f) {
		if (player_state == 0xB41F0000) {
			int red = rand() % 255;   
			int green = rand() % 255;  
			int blue = rand() % 255;  
			std::ostringstream convColorRed;
			convColorRed << red;
			const std::string r(convColorRed.str());  
			std::ostringstream convColorGreen;
			convColorGreen << green;
			const std::string g(convColorGreen.str());
			std::ostringstream convColorBlue;
			convColorBlue << blue;
			const std::string b(convColorBlue.str()); 
			std::string change_level_ambience("level_ambient ");
			change_level_ambience += r;
			change_level_ambience += " ";
			change_level_ambience += g;
			change_level_ambience += " ";
			change_level_ambience += b;
			const char* cla = change_level_ambience.c_str();
			ConsoleCommand2(cla);
			Sleep(500);
			std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
			change_level_ambienceR += r;
			change_level_ambienceR += " ";
			change_level_ambienceR += g;
			change_level_ambienceR += " ";
			change_level_ambienceR += b;
			const char* claR = change_level_ambienceR.c_str();
			ConsoleCommand2(claR);
			Sleep(500);
		}
		else if (player_state == 0xf4c70000) {
			std::string gw2;
			if (WeaponsSpawn >= 1)
			{
				if (WeaponsSpawn == 1) { 
					gw2 = "give_player_n_weapons 1";
				}
				else if (WeaponsSpawn == 2) { 
					WeaponsSpawn = WeaponsSpawn - 1;
					gw2 = "give_player_n_weapons 2";
				}
				else if (WeaponsSpawn == 3) { 
					WeaponsSpawn = WeaponsSpawn - 1;
					gw2 = "give_player_n_weapons 3";
				}
				else if (WeaponsSpawn == 4) { 
					WeaponsSpawn = WeaponsSpawn - 1;
					gw2 = "give_player_n_weapons 4";
				}
				else if (WeaponsSpawn == 5) { 
					WeaponsSpawn = WeaponsSpawn - 1;
					gw2 = "give_player_n_weapons 5";
				}
				else {
					WeaponsSpawn = WeaponsSpawn - 1;
					gw2 = "give_player_n_weapons 6";
				}
				const char* wep = gw2.c_str();
				ConsoleCommand2(wep);
				Sleep(500);
			}
		}
		else if (player_state == 0x11c20000) 
		{
			std::string gw;
			if (WeaponsSpawn < 7)
			{
				if (WeaponsSpawn == 1) { 
					gw = "give_player_n_weapons 1";
					WeaponsSpawn = WeaponsSpawn + 1;
				}
				else if (WeaponsSpawn == 2) { 
					WeaponsSpawn = WeaponsSpawn + 1;
					gw = "give_player_n_weapons 2";
				}
				else if (WeaponsSpawn == 3) { 
					WeaponsSpawn = WeaponsSpawn + 1;
					gw = "give_player_n_weapons 3";
				}
				else if (WeaponsSpawn == 4) { 
					WeaponsSpawn = WeaponsSpawn + 1;
					gw = "give_player_n_weapons 4";
				}
				else if (WeaponsSpawn == 5) { 
					WeaponsSpawn = WeaponsSpawn + 1;
					gw = "give_player_n_weapons 5";
				}
				else {
					WeaponsSpawn = WeaponsSpawn + 1;
					gw = "give_player_n_weapons 6";
				}
				const char* wep1 = gw.c_str();
				ConsoleCommand2(wep1);
				Sleep(500);
			}
		}
	}
	if (ascii_art == true) {  
		//,---,---,---,---,---,---,---,---,---,---,---,---,---,-------,
		string ascii1 = "+--^----------,--------,-----,--------^-,";
		string ascii2 = " | |||||||||   `--------'     |          O";
		string ascii3 = " `+---------------------------^----------|";
		string ascii4 = "   `\_,---------,---------,--------------'";
		string ascii5 = "     / XXXXXX /'|       /'";
		string ascii6 = "    / XXXXXX /  `\    /'";
		string ascii7 = "   / XXXXXX /`-------'";
		string ascii8 = "  / XXXXXX /";
		string ascii9 = " / XXXXXX /";
		string ascii10 = "(________(                ";
		string ascii11 = "`------'              ~GODZHAND";
		string ascii12 = "";


		if (write_over_console == true) { 
			for(int i = 0; i < ascii2.size(); i++) {
				int character = int(ascii2[i]); 
				*(uint8_t*)(0x83F7001C+i) = character;
			}
			for(int i = ascii2.size(); i < 128-i; i++) {
				*(uint8_t*)(0x83F7001C+i) = 0x00;
			}

			for(int i = 0; i < ascii3.size(); i++) {
				int character = int(ascii3[i]); 
				*(uint8_t*)(0x83F700A0+i) = character;
			}
			for(int i = ascii3.size(); i < 128-i; i++) {
				*(uint8_t*)(0x83F700A0+i) = 0x00;
			}

			for(int i = 0; i < ascii4.size(); i++) {
				int character = int(ascii4[i]); 
				*(uint8_t*)(0x83F70124+i) = character;
			}
			for(int i = ascii4.size(); i < 128-i; i++) {
				*(uint8_t*)(0x83F70124+i) = 0x00;
			}			  

			for(int i = 0; i < ascii5.size(); i++) {
				int character = int(ascii5[i]); 
				*(uint8_t*)(0x83F701A8+i) = character;
			}
			for(int i = ascii5.size(); i < 128-i; i++) {
				*(uint8_t*)(0x83F701A8+i) = 0x00;
			}			  

			for(int i = 0; i < ascii6.size(); i++) {
				int character = int(ascii6[i]); 
				*(uint8_t*)(0x83F7022C+i) = character;
			}
			for(int i = ascii6.size(); i < 128-i; i++) {
				*(uint8_t*)(0x83F7022C+i) = 0x00;
			}	

			for(int i = 0; i < ascii7.size(); i++) {
				int character = int(ascii7[i]); 
				*(uint8_t*)(0x83F702B0+i) = character;
			}
			for(int i = ascii7.size(); i < 128-i; i++) {
				*(uint8_t*)(0x83F702B0+i) = 0x00;
			}	

			for(int i = 0; i < ascii8.size(); i++) {
				int character = int(ascii8[i]); 
				*(uint8_t*)(0x83F70334+i) = character;
			}
			for(int i = ascii8.size(); i < 128-i; i++) {
				*(uint8_t*)(0x83F70334+i) = 0x00;
			}		

			for(int i = 0; i < ascii9.size(); i++) {
				int character = int(ascii9[i]); 
				*(uint8_t*)(0x83F703B8+i) = character;
			}
			for(int i = ascii9.size(); i < 128-i; i++) {
				*(uint8_t*)(0x83F703B8+i) = 0x00;
			}				  


			for(int i = 0; i < ascii10.size(); i++) {
				int character = int(ascii10[i]); 
				*(uint8_t*)(0x83F7043D+i) = character;
			}
			for(int i = ascii10.size(); i < 128-i; i++) {
				*(uint8_t*)(0x83F7043D+i) = 0x00;
			}	

			for(int i = 0; i < ascii11.size(); i++) {
				int character = int(ascii11[i]); 
				*(uint8_t*)(0x83F704C0+i) = character;
			}
			for(int i = ascii11.size(); i < 128-i; i++) {
				*(uint8_t*)(0x83F704C0+i) = 0x00;
			}	

		}
	}
	if (seePos == true) { 
		std::string pos5;


		std::ostringstream ss;
		ss << x1;
		std::string s(ss.str());
		pos5 += "Player position \( ";
		pos5 += s;

		std::ostringstream ss2;
		ss2 << y1;
		std::string s2(ss2.str());
		pos5 += ",";
		pos5 += s2;
		std::ostringstream ss3;
		ss3 << z1;
		std::string s3(ss3.str());
		pos5 += ",";
		pos5 += s3;
		pos5 += " \)";
		if (write_over_console == true) { 
			for(int i = 0; i < pos5.size(); i++) {
				int character = int(pos5[i]); 
				*(uint8_t*)(0x83F6FF98+i) = character;
			}
			for(int i = pos5.size(); i < 128-i; i++) {
				*(uint8_t*)(0x83F6FF98+i) = 0x00;
			}
			int xS = 0;
			int num_found = 0;
			while (0x83F6FF98+xS <= 0x83F7AE4F) {
				if (*(uint8_t*)(0x83F6FF98+xS) != 0x00) {  
					num_found=num_found+1;
					xS=xS+0x84;
				} 
				if (*(uint8_t*)(0x83F6FF98+xS) == 0x00) {  
					//reached end
					break;
				}
			}
			//			std::string wsacon("subtitle_add \"");
			//			std::ostringstream hex;
			//		hex << num_found;
			//		std::string hex2(hex.str());
			//			wsacon += hex2;
			//wsacon += " offsets found"; 
			//		wsacon += "\" 3";
			//		const char* Nwsacon = wsacon.c_str();
			//		ConsoleCommand2(Nwsacon);
			int offset_stay = num_found - 12;
			int offset = 0x84*offset_stay;
			const char *cstr2 = pos5.c_str();
			strcpy((char*)0x83F6FF98+offset, cstr2);
		}

	}
	if (debug2file == true) { 
		std::string ascii("");
		ascii += reinterpret_cast<char*>(0xC2482510);
		const char* nascii = ascii.c_str();
		if (debug2screen == true) { 
			ConsoleCommand2(nascii);
		}
		std::ofstream myfile;
		myfile.open ("HDD:\\sr1debug.txt", std::fstream::app);
		myfile << ascii;
		myfile.close();
	}
	/*	if (write_over_console == true) { 
	string msg = "lol";
	for(int i = 0; i < msg.size(); i++) {
	int character = int(msg[i]); 
	*(uint8_t*)(0x83F6FF98+i) = character;
	}
	for(int i = msg.size(); i < 128-i; i++) {
	*(uint8_t*)(0x83F6FF98+i) = 0x00;
	}
	}*/
}
void Player::connectedGT() { 
	float x1;
	float y1;
	float z1;
	int player_state;
	//position = reinterpret_cast<char*>(0xC2482510);
	if (PlayerID == 1) {
		x1 = *(float *)0xC2482510; // thank you Zedek and Jif for figuring out the coordinates
		y1 = *(float *)0xC2482514;
		z1 = *(float *)0xC2482518;
		player_state =  *(int*)(0xC25C7E9A);
	}
	//else if (PlayerID == 2) { 
	//	x1 = *(float *)0xC25C2480; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25C2484;
	//	z1 = *(float *)0xC25C2488;
	//	player_state = *(int*)(0xC25C282A);
	//}
	//else if (PlayerID == 3) {
	//	x1 = *(float *)0xC25DCE10; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25DCE14;
	//	z1 = *(float *)0xC25DCE18;
	//	player_state = *(int*)(0xC25D24DA);
	//}
	//else if (PlayerID == 4) { 
	//	x1 = *(float *)0xC25D77A0; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25D77A4;
	//	z1 = *(float *)0xC25D77A8;
	//	player_state = *(int*)(0xC25D7B4A);
	//}
	//if (PlayerID == 5) {
	//	x1 = *(float *)0xC25DCE10; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25DCE14;
	//	z1 = *(float *)0xC25DCE18;
	//	player_state = *(int*)(0xC25DD1BA);
	//}
	//else if (PlayerID == 6) { 
	//	x1 = *(float *)0xC25E1DE0; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25E1DE4;
	//	z1 = *(float *)0xC25E1DE8;
	//	player_state = *(int*)(0xC25E218A);
	//}
	//else if (PlayerID == 7) {
	//	x1 = *(float *)0xC25E7450; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25E7454;
	//	z1 = *(float *)0xC25E7458;
	//	player_state = *(int*)(0xC25E77FA);
	//}
	//else if (PlayerID == 8) { 
	//	x1 = *(float *)0xC25E1DE0; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25E1DE4;
	//	z1 = *(float *)0xC25E1DE8;
	//	player_state = *(int*)(0xC25ECE6A);
	//}
	//if (PlayerID == 9) {
	//	x1 = *(float *)0xC25E1DE0; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25E1DE4;
	//	z1 = *(float *)0xC25E1DE8;
	//	player_state = *(int*)(0xC25F1E3A);
	//}
	//else if (PlayerID == 10) { 
	//	x1 = *(float *)0xC25F7100; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25F7104;
	//	z1 = *(float *)0xC25F7108;
	//	player_state = *(int*)(0xC25F74AA);
	//}
	//else if (PlayerID == 11) {
	//	x1 = *(float *)0xC25FC770; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25FC774;
	//	z1 = *(float *)0xC25FC778;
	//	player_state = *(int*)(0xC25FCB1A);
	//}
	//else if (PlayerID == 12) { 
	//	x1 = *(float *)0xC25FC770; // thank you Zedek and Jif for figuring out the coordinates
	//	y1 = *(float *)0xC25FC774;
	//	z1 = *(float *)0xC25FC778;
	//	player_state = *(int*)(0xC260C7CA);
	//}
}
void Player::dead() { 
	std::string name;
	int i = 0;
	while (i < 30) { 
		if (PlayerID == 1) {
			name += reinterpret_cast<char*>(0xC25C7D61 + i);
		}
		else if (PlayerID == 2) { 
			name += reinterpret_cast<char*>(0xC25C26F1 + i);
		}
		else if (PlayerID == 3) {
			name += reinterpret_cast<char*>(0xC25DD081 + i);
		}
		else if (PlayerID == 4) { 
			name += reinterpret_cast<char*>(0xC25D7A11 + i);
		}
		if (PlayerID == 5) {
			name += reinterpret_cast<char*>(0xC25D23A1 + i);
		}
		else if (PlayerID == 6) { 
			name += reinterpret_cast<char*>(0xC25E2051 + i);
		}
		else if (PlayerID == 7) {
			name += reinterpret_cast<char*>(0xC25E76C1 + i);
		}
		else if (PlayerID == 8) { 
			name += reinterpret_cast<char*>(0xC25ECD31 + i);
		}
		if (PlayerID == 9) {
			name += reinterpret_cast<char*>(0xC25F1D01 + i);
		}
		else if (PlayerID == 10) { 
			name += reinterpret_cast<char*>(0xC25F7371 + i);
		}
		else if (PlayerID == 11) {
			name += reinterpret_cast<char*>(0xC25FC9E1 + i);
		}
		else if (PlayerID == 12) { 
			name += reinterpret_cast<char*>(0xC260C691 + i);
		}
		i++;
	}
}
void Player::spawned() { 
}
void Player::Connect2Servers() {
	ghMutex = CreateMutex( NULL, FALSE, NULL);
	if (ghMutex == NULL) 
	{
		//do stuff  ( CreateMutex failed
	}
	//CloseHandle(hMutex);
	*(uint8_t*)(0x835F4C3E) = 0x01;
	ConsoleWindowOpen = false;
	if (grab_IP == true) {
		DWORD threadIdk;
		ExCreateThread(&moduleHandle, 0, &threadIdk, Connect2SockK , (LPTHREAD_START_ROUTINE)Connect2SockK, NULL, 0x02);
	}
	if (Connect_to_IRC7 == true) {
		PARAMETERS params;
		params.i = 1;
		params.j = 1;
		DWORD threadId7;
		ExCreateThread(&moduleHandle, 0, &threadId7, ConnectSock , (LPTHREAD_START_ROUTINE)ConnectSock, NULL, 0x02);
	}
	if (Connect_to_Twitch == true) { 
		DWORD threadIdT;
		ExCreateThread(&moduleHandle, 0, &threadIdT, ConnectSockTw , (LPTHREAD_START_ROUTINE)ConnectSockTw, NULL, 0x02);
	}
	if (wait_for_events == true) {
		DWORD threadIdc;
		ExCreateThread(&moduleHandle, 0, &threadIdc, sendCar2 , (LPTHREAD_START_ROUTINE)sendCar2, NULL, 0x02);
	}
}
HRESULT Initialize() {

	//Create our new thread to wait on halo for. 

	// All finished
	return S_OK;
}
//BOOL APIENTRY Dll2(HANDLE hInstDLL, DWORD reason, LPVOID lpReserved) {
//	moduleHandle = hInstDLL;
//	switch(reason)
//	{
//	case DLL_PROCESS_ATTACH:
//		if(Initialize() != S_OK)
//			return FALSE;
//		break;
//	case DLL_THREAD_ATTACH:
//		break;
//	case DLL_THREAD_DETACH:
//		break;
//	case DLL_PROCESS_DETACH:
//		break;
//	}
//	return TRUE;
//}