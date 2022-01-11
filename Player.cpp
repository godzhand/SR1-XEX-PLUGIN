// my_class.cpp
#include "StdAfx.h"
#include "stdafx.h"
#include "Player.h" // header in local directory
#include <iostream> // header in standard library
#include "Tools.h"
#include "global.h"
#include <cstdint>
#include <iostream>
#include <sstream>
#include <fstream>
typedef void(__cdecl* ConsoleCommand2T)(const char command[]);
ConsoleCommand2T ConsoleCommand2 = (ConsoleCommand2T)0x8263CB10;
using namespace N;
using namespace std;

void Player::disconnected()
{
	if (PlayerID == 1) {
		player1ONLINE = false;
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
void Player::connecting()
{
	if (PlayerID == 1) {
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
	std::string name("subtitle_add \"Welcome ");
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
	name += "\" 3";
	const char* nName = name.c_str();
	ConsoleCommand2(nName);
	if (flash_console_window == true) { 
		*(uint8_t*)(0x835F4C3E) = 0x01;
		Sleep(500);

	}
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
	if (flash_console_window == true) { 
		*(uint8_t*)(0x835F4C3E) = 0x00;
	}
}
void Player::connected()
{
	float x1;
	float y1;
	float z1;
	int player_state;
	//position = reinterpret_cast<char*>(0xC2482510);
	if (PlayerID == 1) {
		float x1 = *(float *)0xC2482510; // thank you Zedek and Jif for figuring out the coordinates
		float y1 = *(float *)0xC2482514;
		float z1 = *(float *)0xC2482518;
		int player_state =  *(int*)(0xC25C7E9A);
	}
	else if (PlayerID == 2) { 
		float x1 = *(float *)0xC25C2480; // thank you Zedek and Jif for figuring out the coordinates
		float y1 = *(float *)0xC25C2484;
		float z1 = *(float *)0xC25C2488;
		int player_state = *(short int*)(0xC25C282A);
	}
	else if (PlayerID == 3) {
		float x1 = *(float *)0xC25DCE10; // thank you Zedek and Jif for figuring out the coordinates
		float y1 = *(float *)0xC25DCE14;
		float z1 = *(float *)0xC25DCE18;
	}
	else if (PlayerID == 4) { 
		float x1 = *(float *)0xC25D77A0; // thank you Zedek and Jif for figuring out the coordinates
		float y1 = *(float *)0xC25D77A4;
		float z1 = *(float *)0xC25D77A8;
	}
	if (PlayerID == 5) {
		float x5 = *(float *)0xC25DCE10; // thank you Zedek and Jif for figuring out the coordinates
		float y5 = *(float *)0xC25DCE14;
		float z5 = *(float *)0xC25DCE18;
	}
	else if (PlayerID == 6) { 
		float x1 = *(float *)0xC25E1DE0; // thank you Zedek and Jif for figuring out the coordinates
		float y1 = *(float *)0xC25E1DE4;
		float z1 = *(float *)0xC25E1DE8;
	}
	else if (PlayerID == 7) {
		float x1 = *(float *)0xC25E7450; // thank you Zedek and Jif for figuring out the coordinates
		float y1 = *(float *)0xC25E7454;
		float z1 = *(float *)0xC25E7458;
	}
	else if (PlayerID == 8) { 
		float x1 = *(float *)0xC25E1DE0; // thank you Zedek and Jif for figuring out the coordinates
		float y1 = *(float *)0xC25E1DE4;
		float z1 = *(float *)0xC25E1DE8;
	}
	if (PlayerID == 9) {
		float x1 = *(float *)0xC25E1DE0; // thank you Zedek and Jif for figuring out the coordinates
		float y1 = *(float *)0xC25E1DE4;
		float z1 = *(float *)0xC25E1DE8;
	}
	else if (PlayerID == 10) { 
		float x1 = *(float *)0xC25F7100; // thank you Zedek and Jif for figuring out the coordinates
		float y1 = *(float *)0xC25F7104;
		float z1 = *(float *)0xC25F7108;
	}
	else if (PlayerID == 11) {
		float x1 = *(float *)0xC25FC770; // thank you Zedek and Jif for figuring out the coordinates
		float y1 = *(float *)0xC25FC774;
		float z1 = *(float *)0xC25FC778;
	}
	else if (PlayerID == 12) { 
		float x1 = *(float *)0xC25FC770; // thank you Zedek and Jif for figuring out the coordinates
		float y1 = *(float *)0xC25FC774;
		float z1 = *(float *)0xC25FC778;
	}
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

	if (seePos == true) { 
		std::string pos5("subtitle_add \"");


		std::ostringstream ss;
		ss << round(x1);
		std::string s(ss.str());
		pos5 += s;
		pos5 += "x";

		std::ostringstream ss2;
		ss2 << round(y1);
		std::string s2(ss2.str());
		pos5 += s2;
		pos5 += "y";
		std::ostringstream ss3;
		ss3 << round(z1);
		std::string s3(ss3.str());
		pos5 += s3;
		pos5 += "z";
		pos5 += "\" 2";
		const char* npos = pos5.c_str();
		ConsoleCommand2(npos);
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
}