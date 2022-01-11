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

BOOL bbInitialized = false;
DWORD (__cdecl *XamGetCurrentTitleID)() = (DWORD (__cdecl *)())ResolveFunction("xam.xex", 0x1CF);
typedef void(__cdecl* ConsoleCommandT)(const char command[]);
ConsoleCommandT ConsoleCommand = (ConsoleCommandT)0x8263CB10;
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
char* position;
float positionz;
bool debug2file = true;
bool debug2screen = false;
bool seePos = false;
bool seePlayer1State = false;
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
bool flash_console_window = true;
bool max_players_2 = true;
int WeaponsSpawn = 1;
std::string jump_heightStr = "3.0";
void Reset()
{
	bbInitialized = false;
}

void xui(PLDR_DATA_TABLE_ENTRY ModuleHandle){
	while (true)
	{
		if (XamGetCurrentTitleId() == 0xFFFE07D1) // xbDash
		{
			bool player2ONLINE = false;
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
				Sleep(10000);//freeze correction
				NotifyPopup(L"Welcome to Stilwater");
				//*(int*)(0xC25C7495) = 0xFF; 
				bbInitialized = TRUE;

			}
			else  {

				N::Player p1;
				p1.PlayerID = 1;
				N::Player p2;
				p2.PlayerID = 2;
				N::Player p3;
				p3.PlayerID = 3;
				N::Player p4;
				p4.PlayerID = 4;
				N::Player p5;
				p5.PlayerID = 5;
				N::Player p6;
				p6.PlayerID = 6;
				N::Player p7;
				p7.PlayerID = 7;
				N::Player p8;
				p8.PlayerID = 8;
				N::Player p9;
				p9.PlayerID = 9;
				N::Player p10;
				p10.PlayerID = 10;
				N::Player p11;
				p11.PlayerID = 11;
				N::Player p12;
				p12.PlayerID = 12;
				//if (*(int*)(0xC25C7E3C) == 0x00) {
				if (player1ONLINE == true) { 
					if (*(int*)(0xC25C7E3C) == 0x00) {
						p1.disconnected();
					}
					else {
						p1.connected();
					}
				}
				else if (player1ONLINE == false) { 
					if (*(int*)(0xC25C7E3C) != 0x00) {
						p1.connecting();
					}
					else {
						*(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
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
						p2.connecting();
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
						p3.connecting();
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
						p4.connecting();
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
						p5.connecting();
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
						p6.connecting();
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
						p7.connecting();
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
						p8.connecting();
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
						p9.connecting();
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
						p10.connecting();
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
						p11.connecting();
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
						p12.connecting();
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