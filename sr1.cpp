// sr1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>
#include <cassert>
#include <fstream>

using namespace std;

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
void Reset()
{
	bbInitialized = false;
}
float round(float var)
{
    // we use array of chars to store number
    // as a string.
    char str[40];
 
    // Print in string the value of var
    // with two decimal point
    sprintf(str, "%.1f", var);
 
    // scan string value in var
    sscanf(str, "%f", &var);
 
    return var;
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
				

	//if (*(int*)(0xC25C7E3C) == 0x00) {
					if (player1ONLINE == true) { 
						if (*(int*)(0xC25C7E3C) == 0x00) {
              ConsoleCommand("subtitle_add disconnected 5");
			  player1ONLINE = false;
						}
					 else {
					//position = reinterpret_cast<char*>(0xC2482510);
					float x1 = *(float *)0xC2482510; // thank you Zedek and Jif for figuring out the coordinates
                    float y1 = *(float *)0xC2482514;
					float z1 = *(float *)0xC2482518;
					int player1_state =  *(int*)(0xC25C7E9A);
					if (seePlayer1State == true) { 
										std::string pState("subtitle_add \"player state ");
		std::stringstream stream;
stream << std::hex << *(short int*)(0xC25C7E9A);
std::string result( stream.str() );
           pState += result;
           pState += "\" 3";
           const char* npState = pState.c_str();
				ConsoleCommand(npState);
					}
if (round(x1) == 2.f) {
	                     if (player1_state == 0xB41F0000) {
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
   	                             ConsoleCommand(cla);
								 Sleep(500);
								 		std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
							change_level_ambienceR += r;
							change_level_ambienceR += " ";
							change_level_ambienceR += g;
							change_level_ambienceR += " ";
							change_level_ambienceR += b;
							    const char* claR = change_level_ambienceR.c_str();
   	                             ConsoleCommand(claR);
								 Sleep(500);
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
   	ConsoleCommand(npos);
	 }
	 if (debug2file == true) { 
	std::string ascii("");
			 ascii += reinterpret_cast<char*>(0xC2482510);
           const char* nascii = ascii.c_str();
		   if (debug2screen == true) { 
				ConsoleCommand(nascii);
		   }
				 ofstream myfile;
  myfile.open ("HDD:\\sr1debug.txt", fstream::app);
  myfile << ascii;
  myfile.close();
	 }
					}
					}
						else if (player1ONLINE == false) { 
						if (*(int*)(0xC25C7E3C) != 0x00) {
											player1ONLINE = true;
									std::string name("subtitle_add \"Welcome ");
				 int i = 0;
				 while (i < 30) { 
					 name += reinterpret_cast<char*>(0xC25C7D61 + i);
					 i++;
				 }
         name += "\" 3";
           const char* nName = name.c_str();
				ConsoleCommand(nName);
				if (flash_console_window == true) { 
				*(uint8_t*)(0x835F4C3E) = 0x01;
				Sleep(500);
				
				}
                                if (NathanielHack == true) {
                                    std::string nh("Nathaniel_hack true");
                               const char* nH = nh.c_str();
                               ConsoleCommand(nH);
                                std::string nhr("mp_remote_console \"Nathaniel_hack true");
                               const char* nHr = nhr.c_str();
                               ConsoleCommand(nHr);
                               Sleep(500);
                                }
								else {
								std::string nh("Nathaniel_hack false");
			                   const char* nH = nh.c_str();
				               ConsoleCommand(nH);
							   	std::string nhr("mp_remote_console \"Nathaniel_hack false");
			                   const char* nHr = nhr.c_str();
				               ConsoleCommand(nHr);
							   Sleep(500);
							
								}
								if (rainbowGunfire == true) {
														std::string rg("particle_debug true");
			                   const char* rG = rg.c_str();
				               ConsoleCommand(rG);
							   	std::string rgr("mp_remote_console \"particle_debug true");
			                   const char* rGr = rgr.c_str();
				               ConsoleCommand(rGr);
							   Sleep(500);
							
								}
								else {
								std::string rg("particle_debug false");
			                   const char* rG = rg.c_str();
				               ConsoleCommand(rG);
							   	std::string rgr("mp_remote_console \"particle_debug false");
			                   const char* rGr = rgr.c_str();
				               ConsoleCommand(rGr);
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
				               ConsoleCommand(fH);
							   	//std::string fhr("mp_remote_console \"mp_setup_match_host_serves true");
			        //           const char* fHr = fhr.c_str();
				       //        ConsoleCommand(fHr);
							   Sleep(500);
							  
								}
								else {
								std::string fh("mp_setup_match_host_serves false");
			                   const char* fH = fh.c_str();
				               ConsoleCommand(fH);
							   	std::string fhr("mp_remote_console \"mp_setup_match_host_serves false");
			                   const char* fHr = fhr.c_str();
				               ConsoleCommand(fHr);
							   Sleep(500);
						
								}
								if  (shadows == true) { }
								else { }
								if (lights == true) { }
								else { }
								if (allow_single_player == true) {
														std::string asp("mp_allow_single_player true");
			                   const char* aSp = asp.c_str();
				               ConsoleCommand(aSp);
							   	std::string aspr("mp_remote_console \"mp_allow_single_player true");
			                   const char* aSpr = aspr.c_str();
				               ConsoleCommand(aSpr);
							   Sleep(500);
							
								}
								else {
								std::string rg("mp_allow_single_player false");
			                   const char* rG = rg.c_str();
				               ConsoleCommand(rG);
							   	std::string rgr("mp_remote_console \"mp_allow_single_player false");
			                   const char* rGr = rgr.c_str();
				               ConsoleCommand(rGr);
							   Sleep(500);
						
								}
								if (recoil == true) { }
								else { }
								if (turret_mode == true) { }
								else { }
								if (unlimited_ammo == true) {				
									std::string nh("ammo true");
			                   const char* nH = nh.c_str();
				               ConsoleCommand(nH);
							   	std::string nhr("mp_remote_console \"ammo true");
			                   const char* nHr = nhr.c_str();
				               ConsoleCommand(nHr);
							   Sleep(500);
							
								}
								else {
								std::string nh("ammo false");
			                   const char* nH = nh.c_str();
				               ConsoleCommand(nH);
							   	std::string nhr("mp_remote_console \"ammo false");
			                   const char* nHr = nhr.c_str();
				               ConsoleCommand(nHr);
							   Sleep(500);
							
								}

								if (max_players_2 == true) {  
							std::string asp("mp_auto_mm_conn_needed 2");
			                   const char* aSp = asp.c_str();
				               ConsoleCommand(aSp);
							   	std::string aspr("mp_remote_console \"mp_auto_mm_conn_needed 2");
			                   const char* aSpr = aspr.c_str();
				               ConsoleCommand(aSpr);
							   Sleep(500);
						
								}
								else {
								std::string rg("mp_auto_mm_conn_needed 4");
			                   const char* rG = rg.c_str();
				               ConsoleCommand(rG);
							   Sleep(500);
							   	std::string rgr("mp_remote_console \"mp_auto_mm_conn_needed 4");
			                   const char* rGr = rgr.c_str();
				               ConsoleCommand(rGr);
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
				               ConsoleCommand(sW);
							   Sleep(500);
							   	std::string swr("mp_remote_console \"jump_height ");
								swr += satStr;
			                   const char* sWr = swr.c_str();
				               ConsoleCommand(sWr);
							    XPhysicalFree(convJumpN);
							   Sleep(500);
								
								}
								else { }
								if (custom_gravity == true)  {
						      std::string sw("char_gravity_multiplier ");
								  sw += gravity;
			                   const char* sW = sw.c_str();
				               ConsoleCommand(sW);
							   Sleep(500);
							   	std::string swr("mp_remote_console \"char_gravity_multiplier ");
								swr += gravity;
			                   const char* sWr = swr.c_str();
				               ConsoleCommand(sWr);

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
				               ConsoleCommand(cW);
							   Sleep(500);
							   	std::string cwr("mp_remote_console \"weather_set_stage ");
								cwr += wStr;
			                   const char* cWr = cwr.c_str();
				               ConsoleCommand(cWr);
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
				               ConsoleCommand(sW);
							   Sleep(500);
							   	std::string swr("mp_remote_console \"r_saturation ");
								swr += satStr;
			                   const char* sWr = swr.c_str();
				               ConsoleCommand(sWr);
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
				               ConsoleCommand(crW);
							   Sleep(500);
							   	std::string crwr("mp_remote_console \"set_in_car_character_height ");
								crwr += charStr;
			                   const char* crWr = crwr.c_str();
				               ConsoleCommand(crWr);
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
   	                             ConsoleCommand(cha);
								 	Sleep(500);
									std::string change_char_ambienceR("mp_remote_console \"char_ambient ");
							change_char_ambienceR += dchar_ambient_r;
							change_char_ambienceR += " ";
							change_char_ambienceR += dchar_ambient_g;
							change_char_ambienceR += " ";
							change_char_ambienceR += dchar_ambient_b;
							    const char* chaR = change_char_ambienceR.c_str();
   	                             ConsoleCommand(chaR);
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
   	                             ConsoleCommand(lla);
								 	Sleep(500);
									std::string change_dlevel_ambienceR("mp_remote_console \"level_ambient ");
							change_dlevel_ambienceR += dlevel_ambient_r;
							change_dlevel_ambienceR += " ";
							change_dlevel_ambienceR += dlevel_ambient_g;
							change_dlevel_ambienceR += " ";
							change_dlevel_ambienceR += dlevel_ambient_b;
							    const char* llaR = change_dlevel_ambienceR.c_str();
   	                             ConsoleCommand(llaR);
							   Sleep(500);
								}
								else { }
								if (allow_crouch_walk == true) { }
								else { }
								if (flash_console_window == true) { 
				*(uint8_t*)(0x835F4C3E) = 0x00;
				
				}
					}
					else {
			  *(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
              }
				}

											if (player2ONLINE == true) { 
						if (*(int*)(0xC25C27CC) == 0x00) {
              ConsoleCommand("subtitle_add disconnected 5");

			  player2ONLINE = false;
						}
					 else {
					//position = reinterpret_cast<char*>(0xC2482510);
					float x2 = *(float *)0xC25C2480; // thank you Zedek and Jif for figuring out the coordinates
                    float y2 = *(float *)0xC25C2484;
					float z2 = *(float *)0xC25C2488;
					int player2_state = *(short int*)(0xC25C282A);
					
if (round(x2) == 2.f) {
	if (player2_state == 0xF41F) {
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
   	                             ConsoleCommand(cla);
								 	
									std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
							change_level_ambienceR += r;
							change_level_ambienceR += " ";
							change_level_ambienceR += g;
							change_level_ambienceR += " ";
							change_level_ambienceR += b;
							    const char* claR = change_level_ambienceR.c_str();
   	                             ConsoleCommand(claR);
					}
}

	 if (seePos == true) { 
			std::string pos5("subtitle_add \"");

			
			std::ostringstream ss;
			ss << round(x2);
			std::string s(ss.str());
			pos5 += s;
			pos5 += "x";

             std::ostringstream ss2;
           ss2 << round(y2);
           std::string s2(ss2.str());
           pos5 += s2;
		      pos5 += "y";


           std::ostringstream ss3;
           ss3 << round(z2);
  std::string s3(ss3.str());
  pos5 += s3;
    pos5 += "z";
   pos5 += "\" 2";
    const char* npos = pos5.c_str();
   	ConsoleCommand(npos);
	 }
					}
					}
						else if (player2ONLINE == false) { 
						if (*(int*)(0xC25C27CC) != 0x00) {
					std::string name("subtitle_add \"Welcome ");
				 int i = 0;
				 while (i < 30) { 
					 name += reinterpret_cast<char*>(0xC25C26F1 + i);
					 i++;
				 }
           name += "\" 3";
           const char* nName = name.c_str();
				ConsoleCommand(nName);
				
					std::string nameR("mp_remote_console \"subtitle_add \"Welcome");
		nameR += " 3";
           const char* nNameR = nameR.c_str();
				ConsoleCommand(nNameR);
				
					player2ONLINE = true;
					if (flash_console_window == true) { 
				*(uint8_t*)(0x835F4C3E) = 0x01;
				Sleep(500);
				
				}
				if (max_players_2 == true) {  
							std::string asp("mp_auto_mm_conn_needed 2");
			                   const char* aSp = asp.c_str();
				               ConsoleCommand(aSp);
							   	std::string aspr("mp_remote_console \"mp_auto_mm_conn_needed 2");
			                   const char* aSpr = aspr.c_str();
				               ConsoleCommand(aSpr);
							   Sleep(500);
						
								}
								else {
								std::string rg("mp_auto_mm_conn_needed 4");
			                   const char* rG = rg.c_str();
				               ConsoleCommand(rG);
							   Sleep(500);
							   	std::string rgr("mp_remote_console \"mp_auto_mm_conn_needed 4");
			                   const char* rGr = rgr.c_str();
				               ConsoleCommand(rGr);
							   Sleep(500);
						
								}

														if (custom_saturation == true)  { 
						std::ostringstream convSaturationN;
                          convSaturationN << saturation;
                        const std::string satStr(convSaturationN.str());  
								  std::string sw("r_saturation ");
								  sw += satStr;
			                   const char* sW = sw.c_str();
				               ConsoleCommand(sW);
							   Sleep(500);
							   	std::string swr("mp_remote_console \"r_saturation ");
								swr += satStr;
			                   const char* sWr = swr.c_str();
				               ConsoleCommand(sWr);
							   Sleep(500);
								} 
  if (NathanielHack == true) {
                                    std::string nh("Nathaniel_hack true");
                               const char* nH = nh.c_str();
                               ConsoleCommand(nH);
                                std::string nhr("mp_remote_console \"Nathaniel_hack true");
                               const char* nHr = nhr.c_str();
                               ConsoleCommand(nHr);
                               Sleep(500);
                                }
								else {
								std::string nh("Nathaniel_hack false");
			                   const char* nH = nh.c_str();
				               ConsoleCommand(nH);
							   	std::string nhr("mp_remote_console \"Nathaniel_hack false");
			                   const char* nHr = nhr.c_str();
				               ConsoleCommand(nHr);
							   Sleep(500);
							
								}
															if (unlimited_ammo == true) {				
									std::string nh("ammo true");
			                   const char* nH = nh.c_str();
				               ConsoleCommand(nH);
							   	std::string nhr("mp_remote_console \"ammo true");
			                   const char* nHr = nhr.c_str();
				               ConsoleCommand(nHr);
							   Sleep(500);
							
								}
								else {
								std::string nh("ammo false");
			                   const char* nH = nh.c_str();
				               ConsoleCommand(nH);
							   	std::string nhr("mp_remote_console \"ammo false");
			                   const char* nHr = nhr.c_str();
				               ConsoleCommand(nHr);
							   Sleep(500);
							
								}
										if (char_in_car_height == true) {
										std::ostringstream convcharheightN;
                          convcharheightN << char_height;
                        const std::string charStr(convcharheightN.str());  
								  std::string crw("set_in_car_character_height ");
								  crw += charStr;
			                   const char* crW = crw.c_str();
				               ConsoleCommand(crW);
							   Sleep(500);
							   	std::string crwr("mp_remote_console \"set_in_car_character_height ");
								crwr += charStr;
			                   const char* crWr = crwr.c_str();
				               ConsoleCommand(crWr);
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
   	                             ConsoleCommand(cha);
								 	Sleep(500);
									std::string change_char_ambienceR("mp_remote_console \"char_ambient ");
							change_char_ambienceR += dchar_ambient_r;
							change_char_ambienceR += " ";
							change_char_ambienceR += dchar_ambient_g;
							change_char_ambienceR += " ";
							change_char_ambienceR += dchar_ambient_b;
							    const char* chaR = change_char_ambienceR.c_str();
   	                             ConsoleCommand(chaR);
							   Sleep(500);
								}
								else { }
					if (flash_console_window == true) { 
				*(uint8_t*)(0x835F4C3E) = 0x00;
				
				}
					}
						 
					else {
			  *(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
              }
				}

					if (player3ONLINE == true) { 
						if (*(int*)(0xC25DD15C) == 0x00) {
              ConsoleCommand("subtitle_add disconnected 5");
			  player3ONLINE = false;
						}
					 else {
					//position = reinterpret_cast<char*>(0xC2482510);
					float x3 = *(float *)0xC25DCE10; // thank you Zedek and Jif for figuring out the coordinates
                    float y3 = *(float *)0xC25DCE14;
					float z3 = *(float *)0xC25DCE18;
if (round(x3) == 2.f) {
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
   	                             ConsoleCommand(cla);
								 	
									std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
							change_level_ambienceR += r;
							change_level_ambienceR += " ";
							change_level_ambienceR += g;
							change_level_ambienceR += " ";
							change_level_ambienceR += b;
							    const char* claR = change_level_ambienceR.c_str();
   	                             ConsoleCommand(claR);
					}
	
	 if (seePos == true) { 
			std::string pos5("subtitle_add \"");

			
			std::ostringstream ss;
			ss << round(x3);
			std::string s(ss.str());
			pos5 += s;
			pos5 += "x";

             std::ostringstream ss2;
           ss2 << round(y3);
           std::string s2(ss2.str());
           pos5 += s2;
		      pos5 += "y";


           std::ostringstream ss3;
           ss3 << round(z3);
  std::string s3(ss3.str());
  pos5 += s3;
    pos5 += "z";
   pos5 += "\" 2";
    const char* npos = pos5.c_str();
   	ConsoleCommand(npos);
	 }
					}
					}
						else if (player3ONLINE == false) { 
						if (*(int*)(0xC25DD15C) != 0x00) {
					std::string name("subtitle_add \"Welcome ");
				 int i = 0;
				 while (i < 30) { 
					 name += reinterpret_cast<char*>(0xC25DD081 + i);
					 i++;
				 }
           name += "\" 3";
           const char* nName = name.c_str();
				ConsoleCommand(nName);
				
					std::string nameR("mp_remote_console \"subtitle_add \"Welcome");
		nameR += " 3";
           const char* nNameR = nameR.c_str();
				ConsoleCommand(nNameR);
				
					player3ONLINE = true;
					}
					else {
			  *(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
              }
				}
							if (player4ONLINE == true) { 
						if (*(int*)(0xC25D7AEC) == 0x00) {
              ConsoleCommand("subtitle_add disconnected 5");
			  player4ONLINE = false;
						}
					 else {
					//position = reinterpret_cast<char*>(0xC2482510);
					float x4 = *(float *)0xC25D77A0; // thank you Zedek and Jif for figuring out the coordinates
                    float y4 = *(float *)0xC25D77A4;
					float z4 = *(float *)0xC25D77A8;
if (round(x4) == 2.f) {
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
   	                             ConsoleCommand(cla);
								 	
									std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
							change_level_ambienceR += r;
							change_level_ambienceR += " ";
							change_level_ambienceR += g;
							change_level_ambienceR += " ";
							change_level_ambienceR += b;
							    const char* claR = change_level_ambienceR.c_str();
   	                             ConsoleCommand(claR);
					}
	
	 if (seePos == true) { 
			std::string pos5("subtitle_add \"");

			
			std::ostringstream ss;
			ss << round(x4);
			std::string s(ss.str());
			pos5 += s;
			pos5 += "x";

             std::ostringstream ss2;
           ss2 << round(y4);
           std::string s2(ss2.str());
           pos5 += s2;
		      pos5 += "y";


           std::ostringstream ss3;
           ss3 << round(z4);
  std::string s3(ss3.str());
  pos5 += s3;
    pos5 += "z";
   pos5 += "\" 2";
    const char* npos = pos5.c_str();
   	ConsoleCommand(npos);
	 }
					}
					}
						else if (player4ONLINE == false) { 
						if (*(int*)(0xC25D7AEC) != 0x00) {
					std::string name("subtitle_add \"Welcome ");
				 int i = 0;
				 while (i < 30) { 
					 name += reinterpret_cast<char*>(0xC25D7A11 + i);
					 i++;
				 }
           name += "\" 3";
           const char* nName = name.c_str();
				ConsoleCommand(nName);
				
					std::string nameR("mp_remote_console \"subtitle_add \"Welcome");
		nameR += " 3";
           const char* nNameR = nameR.c_str();
				ConsoleCommand(nNameR);
				
					player4ONLINE = true;
					}
					else {
			  *(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
              }
				}

							if (player5ONLINE == true) { 
						if (*(int*)(0xC25D247C) == 0x00) {
              ConsoleCommand("subtitle_add disconnected 5");
			  player5ONLINE = false;
						}
					 else {
					//position = reinterpret_cast<char*>(0xC2482510);
					float x5 = *(float *)0xC25DCE10; // thank you Zedek and Jif for figuring out the coordinates
                    float y5 = *(float *)0xC25DCE14;
					float z5 = *(float *)0xC25DCE18;
if (round(x5) == 2.f) {
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
   	                             ConsoleCommand(cla);
								 	
									std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
							change_level_ambienceR += r;
							change_level_ambienceR += " ";
							change_level_ambienceR += g;
							change_level_ambienceR += " ";
							change_level_ambienceR += b;
							    const char* claR = change_level_ambienceR.c_str();
   	                             ConsoleCommand(claR);
					}

	 if (seePos == true) { 
			std::string pos5("subtitle_add \"");

			
			std::ostringstream ss;
			ss << round(x5);
			std::string s(ss.str());
			pos5 += s;
			pos5 += "x";

             std::ostringstream ss2;
           ss2 << round(y5);
           std::string s2(ss2.str());
           pos5 += s2;
		      pos5 += "y";


           std::ostringstream ss3;
           ss3 << round(z5);
  std::string s3(ss3.str());
  pos5 += s3;
    pos5 += "z";
   pos5 += "\" 2";
    const char* npos = pos5.c_str();
   	ConsoleCommand(npos);
	 }
					}
					}
						else if (player5ONLINE == false) { 
						if (*(int*)(0xC25D247C) != 0x00) {
					std::string name("subtitle_add \"Welcome ");
				 int i = 0;
				 while (i < 30) { 
					 name += reinterpret_cast<char*>(0xC25D23A1 + i);
					 i++;
				 }
           name += "\" 3";
           const char* nName = name.c_str();
				ConsoleCommand(nName);
				
					std::string nameR("mp_remote_console \"subtitle_add \"Welcome");
		nameR += " 3";
           const char* nNameR = nameR.c_str();
				ConsoleCommand(nNameR);
				
					player5ONLINE = true;
					}
					else {
			  *(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
              }
				}
	if (player6ONLINE == true) { 
						if (*(int*)(0xC25E211C) == 0x00) {
              ConsoleCommand("subtitle_add disconnected 5");
			  player6ONLINE = false;
						}
					 else {
					//position = reinterpret_cast<char*>(0xC2482510);
					float x6 = *(float *)0xC25E1DE0; // thank you Zedek and Jif for figuring out the coordinates
                    float y6 = *(float *)0xC25E1DE4;
					float z6 = *(float *)0xC25E1DE8;
if (round(x6) == 2.f) {
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
   	                             ConsoleCommand(cla);
								 	
									std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
							change_level_ambienceR += r;
							change_level_ambienceR += " ";
							change_level_ambienceR += g;
							change_level_ambienceR += " ";
							change_level_ambienceR += b;
							    const char* claR = change_level_ambienceR.c_str();
   	                             ConsoleCommand(claR);
					}
	
	 if (seePos == true) { 
			std::string pos5("subtitle_add \"");

			
			std::ostringstream ss;
			ss << round(x6);
			std::string s(ss.str());
			pos5 += s;
			pos5 += "x";

             std::ostringstream ss2;
           ss2 << round(y6);
           std::string s2(ss2.str());
           pos5 += s2;
		      pos5 += "y";


           std::ostringstream ss3;
           ss3 << round(z6);
  std::string s3(ss3.str());
  pos5 += s3;
    pos5 += "z";
   pos5 += "\" 2";
    const char* npos = pos5.c_str();
   	ConsoleCommand(npos);
	 }
					}
					}
						else if (player6ONLINE == false) { 
						if (*(int*)(0xC25E211C) != 0x00) {
					std::string name("subtitle_add \"Welcome ");
				 int i = 0;
				 while (i < 30) { 
					 name += reinterpret_cast<char*>(0xC25D23A1 + i);
					 i++;
				 }
           name += "\" 3";
           const char* nName = name.c_str();
				ConsoleCommand(nName);
				
					std::string nameR("mp_remote_console \"subtitle_add \"Welcome");
		nameR += " 3";
           const char* nNameR = nameR.c_str();
				ConsoleCommand(nNameR);
				
					player6ONLINE = true;
					}
					else {
			  *(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
              }
				}

							if (player7ONLINE == true) { 
						if (*(int*)(0xC25E779C) == 0x00) {
              ConsoleCommand("subtitle_add disconnected 5");
			  player7ONLINE = false;
						}
					 else {
					//position = reinterpret_cast<char*>(0xC2482510);
					float x7 = *(float *)0xC25E7450; // thank you Zedek and Jif for figuring out the coordinates
                    float y7 = *(float *)0xC25E7454;
					float z7 = *(float *)0xC25E7458;
if (round(x7) == 2.f) {
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
   	                             ConsoleCommand(cla);
								 	
									std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
							change_level_ambienceR += r;
							change_level_ambienceR += " ";
							change_level_ambienceR += g;
							change_level_ambienceR += " ";
							change_level_ambienceR += b;
							    const char* claR = change_level_ambienceR.c_str();
   	                             ConsoleCommand(claR);
					}
	
	 if (seePos == true) { 
			std::string pos5("subtitle_add \"");

			
			std::ostringstream ss;
			ss << round(x7);
			std::string s(ss.str());
			pos5 += s;
			pos5 += "x";

             std::ostringstream ss2;
           ss2 << round(y7);
           std::string s2(ss2.str());
           pos5 += s2;
		      pos5 += "y";


           std::ostringstream ss3;
           ss3 << round(z7);
  std::string s3(ss3.str());
  pos5 += s3;
    pos5 += "z";
   pos5 += "\" 2";
    const char* npos = pos5.c_str();
   	ConsoleCommand(npos);
	 }
					}
					}
						else if (player7ONLINE == false) { 
						if (*(int*)(0xC25E779C) != 0x00) {
					std::string name("subtitle_add \"Welcome ");
				 int i = 0;
				 while (i < 30) { 
					 name += reinterpret_cast<char*>(0xC25D23A1 + i);
					 i++;
				 }
           name += "\" 3";
           const char* nName = name.c_str();
				ConsoleCommand(nName);
				
					std::string nameR("mp_remote_console \"subtitle_add \"Welcome");
		nameR += " 3";
           const char* nNameR = nameR.c_str();
				ConsoleCommand(nNameR);
				
					player7ONLINE = true;
					}
					else {
			  *(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
              }
				}


							if (player8ONLINE == true) { 
						if (*(int*)(0xC25ECE0C) == 0x00) {
              ConsoleCommand("subtitle_add disconnected 5");
			  player8ONLINE = false;
						}
					 else {
					//position = reinterpret_cast<char*>(0xC2482510);
					float x8 = *(float *)0xC25E1DE0; // thank you Zedek and Jif for figuring out the coordinates
                    float y8 = *(float *)0xC25E1DE4;
					float z8 = *(float *)0xC25E1DE8;
if (round(x8) == 2.f) {
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
   	                             ConsoleCommand(cla);
								 	
									std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
							change_level_ambienceR += r;
							change_level_ambienceR += " ";
							change_level_ambienceR += g;
							change_level_ambienceR += " ";
							change_level_ambienceR += b;
							    const char* claR = change_level_ambienceR.c_str();
   	                             ConsoleCommand(claR);
					}

	 if (seePos == true) { 
			std::string pos5("subtitle_add \"");

			
			std::ostringstream ss;
			ss << round(x8);
			std::string s(ss.str());
			pos5 += s;
			pos5 += "x";

             std::ostringstream ss2;
           ss2 << round(y8);
           std::string s2(ss2.str());
           pos5 += s2;
		      pos5 += "y";


           std::ostringstream ss3;
           ss3 << round(z8);
  std::string s3(ss3.str());
  pos5 += s3;
    pos5 += "z";
   pos5 += "\" 2";
    const char* npos = pos5.c_str();
   	ConsoleCommand(npos);
	 }
					}
					}
						else if (player8ONLINE == false) { 
						if (*(int*)(0xC25ECE0C) != 0x00) {
					std::string name("subtitle_add \"Welcome ");
				 int i = 0;
				 while (i < 30) { 
					 name += reinterpret_cast<char*>(0xC25D23A1 + i);
					 i++;
				 }
           name += "\" 3";
           const char* nName = name.c_str();
				ConsoleCommand(nName);
				
					std::string nameR("mp_remote_console \"subtitle_add \"Welcome");
		nameR += " 3";
           const char* nNameR = nameR.c_str();
				ConsoleCommand(nNameR);
				
					player8ONLINE = true;
					}
					else {
			  *(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
              }
				}
							if (player9ONLINE == true) { 
						if (*(int*)(0xC25F1DDC) == 0x00) {
              ConsoleCommand("subtitle_add disconnected 5");
			  player9ONLINE = false;
						}
					 else {
					//position = reinterpret_cast<char*>(0xC2482510);
					float x9 = *(float *)0xC25E1DE0; // thank you Zedek and Jif for figuring out the coordinates
                    float y9 = *(float *)0xC25E1DE4;
					float z9 = *(float *)0xC25E1DE8;
if (round(x9) == 2.f) {
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
   	                             ConsoleCommand(cla);
								 	
									std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
							change_level_ambienceR += r;
							change_level_ambienceR += " ";
							change_level_ambienceR += g;
							change_level_ambienceR += " ";
							change_level_ambienceR += b;
							    const char* claR = change_level_ambienceR.c_str();
   	                             ConsoleCommand(claR);
					}

	 if (seePos == true) { 
			std::string pos5("subtitle_add \"");

			
			std::ostringstream ss;
			ss << round(x9);
			std::string s(ss.str());
			pos5 += s;
			pos5 += "x";

             std::ostringstream ss2;
           ss2 << round(y9);
           std::string s2(ss2.str());
           pos5 += s2;
		      pos5 += "y";


           std::ostringstream ss3;
           ss3 << round(z9);
  std::string s3(ss3.str());
  pos5 += s3;
    pos5 += "z";
   pos5 += "\" 2";
    const char* npos = pos5.c_str();
   	ConsoleCommand(npos);
	 }
					}
					}
						else if (player9ONLINE == false) { 
						if (*(int*)(0xC25F1DDC) != 0x00) {
					std::string name("subtitle_add \"Welcome ");
				 int i = 0;
				 while (i < 30) { 
					 name += reinterpret_cast<char*>(0xC25D23A1 + i);
					 i++;
				 }
           name += "\" 3";
           const char* nName = name.c_str();
				ConsoleCommand(nName);
				
					std::string nameR("mp_remote_console \"subtitle_add \"Welcome");
		nameR += " 3";
           const char* nNameR = nameR.c_str();
				ConsoleCommand(nNameR);
				
					player9ONLINE = true;
					}
					else {
			  *(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
              }
				}
							if (player10ONLINE == true) { 
						if (*(int*)(0xC25F744C) == 0x00) {
              ConsoleCommand("subtitle_add disconnected 5");
			  player10ONLINE = false;
						}
					 else {
					//position = reinterpret_cast<char*>(0xC2482510);
					float x10 = *(float *)0xC25F7100; // thank you Zedek and Jif for figuring out the coordinates
                    float y10 = *(float *)0xC25F7104;
					float z10 = *(float *)0xC25F7108;
if (round(x10) == 2.f) {
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
   	                             ConsoleCommand(cla);
								 	
									std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
							change_level_ambienceR += r;
							change_level_ambienceR += " ";
							change_level_ambienceR += g;
							change_level_ambienceR += " ";
							change_level_ambienceR += b;
							    const char* claR = change_level_ambienceR.c_str();
   	                             ConsoleCommand(claR);
					}

	 if (seePos == true) { 
			std::string pos5("subtitle_add \"");

			
			std::ostringstream ss;
			ss << round(x10);
			std::string s(ss.str());
			pos5 += s;
			pos5 += "x";

             std::ostringstream ss2;
           ss2 << round(y10);
           std::string s2(ss2.str());
           pos5 += s2;
		      pos5 += "y";


           std::ostringstream ss3;
           ss3 << round(z10);
  std::string s3(ss3.str());
  pos5 += s3;
    pos5 += "z";
   pos5 += "\" 2";
    const char* npos = pos5.c_str();
   	ConsoleCommand(npos);
	 }
					}
					}
						else if (player10ONLINE == false) { 
						if (*(int*)(0xC25F744C) != 0x00) {
					std::string name("subtitle_add \"Welcome ");
				 int i = 0;
				 while (i < 30) { 
					 name += reinterpret_cast<char*>(0xC25D23A1 + i);
					 i++;
				 }
           name += "\" 3";
           const char* nName = name.c_str();
				ConsoleCommand(nName);
				
					std::string nameR("mp_remote_console \"subtitle_add \"Welcome");
		nameR += " 3";
           const char* nNameR = nameR.c_str();
				ConsoleCommand(nNameR);
				
					player10ONLINE = true;
					}
					else {
			  *(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
              }
				}
							if (player11ONLINE == true) { 
						if (*(int*)(0xC25FCABC) == 0x00) {
              ConsoleCommand("subtitle_add disconnected 5");
			  player11ONLINE = false;
						}
					 else {
					//position = reinterpret_cast<char*>(0xC2482510);
					float x11 = *(float *)0xC25FC770; // thank you Zedek and Jif for figuring out the coordinates
                    float y11 = *(float *)0xC25FC774;
					float z11 = *(float *)0xC25FC778;
if (round(x11) == 2.f) {
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
   	                             ConsoleCommand(cla);
								 	
									std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
							change_level_ambienceR += r;
							change_level_ambienceR += " ";
							change_level_ambienceR += g;
							change_level_ambienceR += " ";
							change_level_ambienceR += b;
							    const char* claR = change_level_ambienceR.c_str();
   	                             ConsoleCommand(claR);
					}
	
	 if (seePos == true) { 
			std::string pos5("subtitle_add \"");

			
			std::ostringstream ss;
			ss << round(x11);
			std::string s(ss.str());
			pos5 += s;
			pos5 += "x";

             std::ostringstream ss2;
           ss2 << round(y11);
           std::string s2(ss2.str());
           pos5 += s2;
		      pos5 += "y";


           std::ostringstream ss3;
           ss3 << round(z11);
  std::string s3(ss3.str());
  pos5 += s3;
    pos5 += "z";
   pos5 += "\" 2";
    const char* npos = pos5.c_str();
   	ConsoleCommand(npos);
	 }
					}
					}
						else if (player11ONLINE == false) { 
						if (*(int*)(0xC25FCABC) != 0x00) {
					std::string name("subtitle_add \"Welcome ");
				 int i = 0;
				 while (i < 30) { 
					 name += reinterpret_cast<char*>(0xC25D23A1 + i);
					 i++;
				 }
           name += "\" 3";
           const char* nName = name.c_str();
				ConsoleCommand(nName);
				
					std::string nameR("mp_remote_console \"subtitle_add \"Welcome");
		nameR += " 3";
           const char* nNameR = nameR.c_str();
				ConsoleCommand(nNameR);
				
					player11ONLINE = true;
					}
					else {
			  *(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
              }
				}

							if (player12ONLINE == true) { 
						if (*(int*)(0xC260C76C) == 0x00) {
              ConsoleCommand("subtitle_add disconnected 5");
			  player12ONLINE = false;
						}
					 else {
					//position = reinterpret_cast<char*>(0xC2482510);
					float x12 = *(float *)0xC25FC770; // thank you Zedek and Jif for figuring out the coordinates
                    float y12 = *(float *)0xC25FC774;
					float z12 = *(float *)0xC25FC778;
if (round(x12) == 2.f) {
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
   	                             ConsoleCommand(cla);
								 	
									std::string change_level_ambienceR("mp_remote_console \"level_ambient ");
							change_level_ambienceR += r;
							change_level_ambienceR += " ";
							change_level_ambienceR += g;
							change_level_ambienceR += " ";
							change_level_ambienceR += b;
							    const char* claR = change_level_ambienceR.c_str();
   	                             ConsoleCommand(claR);
					}
	 if (seePos == true) { 
			std::string pos5("subtitle_add \"");

			
			std::ostringstream ss;
			ss << round(x12);
			std::string s(ss.str());
			pos5 += s;
			pos5 += "x";

             std::ostringstream ss2;
           ss2 << round(y12);
           std::string s2(ss2.str());
           pos5 += s2;
		      pos5 += "y";


           std::ostringstream ss3;
           ss3 << round(z12);
  std::string s3(ss3.str());
  pos5 += s3;
    pos5 += "z";
   pos5 += "\" 2";
    const char* npos = pos5.c_str();
   	ConsoleCommand(npos);
	 }
					}
					}
						else if (player12ONLINE == false) { 
						if (*(int*)(0xC260C76C) != 0x00) {
					std::string name("subtitle_add \"Welcome ");
				 int i = 0;
				 while (i < 30) { 
					 name += reinterpret_cast<char*>(0xC25D23A1 + i);
					 i++;
				 }
           name += "\" 3";
           const char* nName = name.c_str();
				ConsoleCommand(nName);
				
					std::string nameR("mp_remote_console \"subtitle_add \"Welcome");
		nameR += " 3";
           const char* nNameR = nameR.c_str();
				ConsoleCommand(nNameR);
				
					player12ONLINE = true;
					}
					else {
			  *(unsigned int*)(0xC25C762F) = 0x7270E0; // generates 19.2 million to purchase clothing
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

// Convert string of hex numbers to its equivalent char-stream
int is_hex(char arr[])
{
    if (arr[0] == '0' && (arr[1] == 'x' || arr[1] == 'X')) {
        return 1;
    }
    return 0;
}

int check_if_good(char arr[])
{
    if (is_hex(arr)) {
        int len = strlen(arr);
        for (int i = 2; i < len; i++) {
            if ((arr[i] > 'f' && arr[i] <= 'z') || (arr[i] > 'F' && arr[i] <= 'Z')) {
                return 0;
            }
        }
    }

    return 1;
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