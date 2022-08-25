// my_class.cpp
#include <stdint.h>
#include <stdio.h>
#include "StdAfx.h"
#include "stdafx.h"
#include "sp.h" // header in local directory
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
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
HANDLE moduleHandle;
#if defined(_MSC_VER)
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#endif
typedef void(__cdecl* ConsoleCommand2T)(const char command[]);
ConsoleCommand2T ConsoleCommand2 = (ConsoleCommand2T)0x8263CB10;
using namespace N;
using namespace std;
struct sockaddr_in sockaddr_s;
int sockets, connected;
SOCKET currentSockP;
struct ARGS {
	string gt;
};

struct PARAMETERS
{
	int i;
	int j;
};
void ReplaceStringInPlace(std::string& subject, const std::string& search,
	const std::string& replace) {
		size_t pos = 0;
		while ((pos = subject.find(search, pos)) != std::string::npos) {
			subject.replace(pos, search.length(), replace);
			pos += replace.length();
		}
}
void sp::ExternalMsg(char* str){
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
						ConsoleCommand2(Nwsacon);
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
				ReplaceStringInPlace(sentstr,"#","%#Multiplayer\\bPre-Game\\bLobbby");
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
						ConsoleCommand2(Nwsacon);
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
					sentstr="PRIVMSG %#Multiplayer\\bPre-Game\\bLobbby :" + sentstr;
	}
	sentstr+="\r\n";
	std::string wsacon("subtitle_add \"enter!");
	wsacon += "\" 3";
	const char* Nwsacon = wsacon.c_str();
	ConsoleCommand2(Nwsacon);

	NetDll_send(XNCALLER_SYSAPP, sp::Sock, sentstr.c_str(), sentstr.length(), 0);
}
void SendSockInfo(SOCKET s) {
	currentSock = s;
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

DWORD WINAPI ConnectSock() {
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
							ConsoleCommand2(Nwsacon);
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
								string sendinfo = "NICK >" + gamertag + "\r\nUSER " + gamertag + " 0 * :Saints Row Client\r\n";
								NetDll_send(XNCALLER_SYSAPP, Sock,sendinfo.c_str(),sendinfo.length(), 0);
							}
						}
						if (tokens[1] == "422") { 
							SendSockInfo(Sock);
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
								string NewMessage = ProcessIRCMessages(SingleLine);
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
		string ConIRC = "PASS oauth:bu1vqoikefnlbfy8lois6i3ryzt1sa\r\nNICK xgodzhand\r\n";
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
							string x = "PONG :IRC7\r\n";
							NetDll_send(XNCALLER_SYSAPP, Sock, x.c_str(), x.length(), 0);
							std::string wsacon("subtitle_add \"PING? PONG!");
							wsacon += "\" 3";
							const char* Nwsacon = wsacon.c_str();
							ConsoleCommand2(Nwsacon);
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
								string sendinfo = "NICK >" + gamertag + "\r\nUSER " + gamertag + " 0 * :Saints Row Client\r\n";
								NetDll_send(XNCALLER_SYSAPP, Sock,sendinfo.c_str(),sendinfo.length(), 0);
							}
						}
						if (tokens[1] == "004") { 
							SendSockInfo(Sock);
							string Z = "JOIN #xgodzhand\r\n";
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
								string NewMessage = ProcessIRCMessages(SingleLine);
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

void sp::start()
{
if (flash_console_window == true) { 
		*(uint8_t*)(0x835F4C3E) = 0x01;
		Sleep(500);

	}
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
	if (flash_console_window == true && keep_console_open == false)  { 
		*(uint8_t*)(0x835F4C3E) = 0x00;
	}
	if (Connect_to_IRC7 == true) {
		PARAMETERS params;
		params.i = 1;
		params.j = 1;
		DWORD threadId;
	ExCreateThread(&moduleHandle, 0, &threadId, ConnectSock , (LPTHREAD_START_ROUTINE)ConnectSock, NULL, 0x02);

		//NetDll_send(XNCALLER_SYSAPP, Sock, Test, strlen(Test), 0);
		//NetDll_recv(XNCALLER_SYSAPP, Sock, ReturnBuffer, sizeof(ReturnBuffer), 0);
		//NetDll_closesocket(XNCALLER_SYSAPP, Sock);
		//string str(ReturnBuffer);

		//
	}
	if (Connect_to_Twitch == true) { 
		DWORD threadId;
	ExCreateThread(&moduleHandle, 0, &threadId, ConnectSockTw , (LPTHREAD_START_ROUTINE)ConnectSockTw, NULL, 0x02);
	}
}

void sp::stop() { 
}
HRESULT Initialize() {

	//Create our new thread to wait on halo for. 

	// All finished
	return S_OK;
}
BOOL APIENTRY Dll2(HANDLE hInstDLL, DWORD reason, LPVOID lpReserved) {
	moduleHandle = hInstDLL;
	switch(reason)
	{
	case DLL_PROCESS_ATTACH:
		if(Initialize() != S_OK)
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