#include <PA9.h>
#include <fat.h>
#include <maxmod9.h>
#include "ky_geturl.h"
#include <sys/dir.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "soundbank_bin.h"
#include "soundbank.h"

#define FILEGAME "/BWCMDS/BWCMDS.SAV" //nom de la sauvegarde
u8 isDLDISystem = 0;

#include "all_gfx.h"

bool downloadfile(const char*,char*);

#include "licensed.h"
#include "credits.h"
#include "black.h"
#include "palib.h"
#include "devkitpro.h"

#include "intro1.h"
#include "intro2.h"
#include "intro3.h"

#include "mineirao.h"
#include "nacional.h"
#include "castelao.h"
#include "baixada.h"
#include "maracana.h"
#include "dunas.h"
#include "amazonia.h"
#include "beirario.h"
#include "pernambuco.h"
#include "pantanal.h"
#include "fontenova.h"
#include "saopaulo.h"

#include "BG3_bas_wifi_fra.h"
#include "BG3_bas_wifi_eng.h"
#include "BG3_bas_wifi_ita.h"
#include "BG3_bas_wifi_esp.h"
#include "BG3_bas_wifi_ger.h"

#include "BG3_bas_connexion_fra.h"
#include "BG3_bas_connexion_eng.h"
#include "BG3_bas_connexion_ita.h"
#include "BG3_bas_connexion_esp.h"
#include "BG3_bas_connexion_ger.h"

#include "BG3_bas_reussi_fra.h"
#include "BG3_bas_reussi_eng.h"
#include "BG3_bas_reussi_ita.h"
#include "BG3_bas_reussi_esp.h"
#include "BG3_bas_reussi_ger.h"

#include "BG3_bas_echec_fra.h"
#include "BG3_bas_echec_eng.h"
#include "BG3_bas_echec_ita.h"
#include "BG3_bas_echec_esp.h"
#include "BG3_bas_echec_ger.h"

#include "BG3_haut_titre.h"

#include "BG3_haut_groupes_fra.h"
#include "BG3_haut_groupes_eng.h"
#include "BG3_haut_groupes_ita.h"
#include "BG3_haut_groupes_esp.h"
#include "BG3_haut_groupes_ger.h"

#include "BG3_haut_huitieme_fra.h"
#include "BG3_haut_huitieme_eng.h"
#include "BG3_haut_huitieme_ita.h"
#include "BG3_haut_huitieme_esp.h"
#include "BG3_haut_huitieme_ger.h"

#include "BG3_haut_quart_fra.h"
#include "BG3_haut_quart_eng.h"
#include "BG3_haut_quart_ita.h"
#include "BG3_haut_quart_esp.h"
#include "BG3_haut_quart_ger.h"

#include "BG3_haut_demi_fra.h"
#include "BG3_haut_demi_eng.h"
#include "BG3_haut_demi_ita.h"
#include "BG3_haut_demi_esp.h"
#include "BG3_haut_demi_ger.h"

#include "BG3_haut_finale_fra.h"
#include "BG3_haut_finale_eng.h"
#include "BG3_haut_finale_ita.h"
#include "BG3_haut_finale_esp.h"
#include "BG3_haut_finale_ger.h"

#include "BG3_bas_menu_fra.h"
#include "BG3_bas_menu_eng.h"
#include "BG3_bas_menu_ita.h"
#include "BG3_bas_menu_esp.h"
#include "BG3_bas_menu_ger.h"

#include "BG3_bas_equipes_fra.h"
#include "BG3_bas_equipes_eng.h"
#include "BG3_bas_equipes_ger.h"
#include "BG3_bas_equipes_ita.h"
#include "BG3_bas_equipes_esp.h"

#include "BG3_bas_stades_fra.h"
#include "BG3_bas_stades_eng.h"
#include "BG3_bas_stades_ger.h"
#include "BG3_bas_stades_ita.h"
#include "BG3_bas_stades_esp.h"

#include "BG3_bas_groupes.h"
#include "BG3_bas_quatres.h"
#include "BG3_bas_deux.h"
#include "BG3_bas_score.h"
#include "BG3_bas_penalty.h"


#define BOUTON_R 48
#define BOUTON_L 49
#define BOUTON_SCORE 50
#define BOUTON_VALIDER 51
#define BOUTON_ANNULER 52
#define BOUTON_RESET 53
#define FLAG1 54
#define FLAG2 55
#define SCORE1 56
#define SCORE2 57
#define PENALTY1 70
#define PENALTY2 71
#define LETTRE 72
#define SIGNE1 73
#define SIGNE2 74
#define SIGNE3 75
#define SIGNE4 76
#define QUITTER 79

typedef struct {
	u8 premier;
	u8 deuxieme;
}inf;
inf groupe[8], Huitiemes[8], Quarts[4], Demi[2], Finales[2];

typedef struct {
	char *nom;
	char *abb;
	int Points;
	u8 numero;
	u8 Joue;
	u8 Gagne;
	u8 Nul;
	u8 Perdu;
	u8 ButPour;
	u8 ButContre;
	s8 Difference;
	int Pointsp;
	u8 ButPourp;
	s8 Differencep;
	char Codage[14];
}info;
info equipe[32];

typedef struct {
	char *equipe1;
	char *equipe2;
	char *abb1;
	char *abb2;
	u8 numero1;
	u8 numero2;
	u8 score1;
	u8 score2;
	u8 penalty1;
	u8 penalty2;
	char *date;
	char *ville;
	char *heure;
	char *stade;
	u8 jouer;
}plop;
plop match[48], huitieme[8], quarts[4], demi[2], finales[2];

int i, j;
u8 state;
u8 startmenu;
u8 langue;
u8 groupe_courant;
u8 stade_courant;
u8 selection_match;
u8 selection_y;
u8 selection;
u8 premier, deuxieme, troisieme, quatrieme;
u8 entrer_score;
u8 equipe_courant;
u8 huitieme_courant;
u8 penalty;
bool maj;
char *buffer;


#include "matchs.h"
#include "save.h"
#include "fonctions.h"
#include "groupes.h"
#include "huitiemes.h"
#include "quarts.h"
#include "demi.h"
#include "finales.h"
#include "stades.h"
#include "equipes.h"
#include "wifi.h"

int main(int argc, char ** argv)
{
	defaultExceptionHandler();
	PA_Init();

	mmInitDefaultMem((mm_addr)soundbank_bin);	
	mmLoad(MOD_MUSIC);
	mmLoadEffect(SFX_SFXA);
	mmLoadEffect(SFX_SFXB);

	PA_Init8bitBg(1, 3);
	PA_Init8bitBg(0, 3);
	PA_InitText(0,0);

	langue = PA_UserInfo.Language; //0 = japonais, 1 = anglais, 2 = français, 3 = allemand, 4 = italien, 5 = espagnol

	fadein();
	PA_LoadGif(0, (void*)licensed);
	PA_LoadGif(1, (void*)devkitpro);
	fadeout();

	attente(180);
	
	fadein();
	PA_LoadGif(0, (void*)credits);
	PA_LoadGif(1, (void*)palib);
	fadeout();
	
	attente(180);

	fadein();
	if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_wifi_eng);
	else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_wifi_fra);
	else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_wifi_ger);
	else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_wifi_ita);
	else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_wifi_esp);
	else PA_LoadGif(0, (void*)BG3_bas_wifi_eng);
	PA_LoadGif(1, (void*)black);
	fadeout();

	while(state == 0)
	{
		if (Stylus.Newpress && PA_StylusInZone(104, 80, 152, 104)) {maj = true; state = 1;}
		else if (Stylus.Newpress && PA_StylusInZone(104, 136, 152, 160)) {maj = false; state = 1;}
		
		PA_WaitForVBL();
	}
	
	Stylus.Newpress = false;

	if (maj == true)
	{
		fadein();
		if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_connexion_eng);
		else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_connexion_fra);
		else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_connexion_ger);
		else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_connexion_ita);
		else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_connexion_esp);
		else PA_LoadGif(0, (void*)BG3_bas_connexion_eng);
		fadeout();
	
		PA_InitWifi();

		isDLDISystem = fatInitDefault();

		InitEquipes();
		InitMatchs();

		downloadfile("https://nds.nintendomax.com/Homebrews/Utilitaires/BrasilWorldCup2014DSManager/BWCMDS.SAV","BWCMDS.SAV");

		Wifi_DisconnectAP();
		Wifi_DisableWifi();
		
		attente(60);

		charger_sauvegarde();

		//CalculStats();
	}
	else if (maj == false)
	{
		isDLDISystem = fatInitDefault();

		InitEquipes();
		InitMatchs();

		charger_sauvegarde();

		//CalculStats();
	}
	
	PA_DeleteText(0);

	mmSetModuleVolume(512);
	mmStart(MOD_MUSIC, MM_PLAY_LOOP);

	fadein();
	PA_LoadGif(0, (void*)black);
	PA_LoadBackground(0, 2, &BG2_bas_maracana);
	PA_HideBg(0, 2);
	PA_LoadGif(1, (void*)intro1);
	fadeout();
	attente_ou_touche(30);
	fadein();
	PA_LoadGif(1, (void*)intro2);
	fadeout();
	attente_ou_touche(30);
	fadein();
	PA_LoadGif(1, (void*)intro3);
	fadeout();
	attente_ou_touche(30);
	fadein();

	//****************ECRAN BAS*************************
	//BG 0
	PA_LoadText(0, 0, &newfont);
	//BG 1
	//BG 2
	//BG 3
	if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_menu_eng);
	else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_menu_fra);
	else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_menu_ger);
	else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_menu_ita);
	else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_menu_esp);
	else PA_LoadGif(0, (void*)BG3_bas_menu_eng);

	//****************ECRAN HAUT*********************
	//BG 0
	PA_InitText(1,0);
	PA_LoadText(1, 0, &newfont);
	//BG 1
	//BG 2
	//BG 3
	PA_LoadGif(1, (void*)BG3_haut_titre);

	//***************SPRITE******************
	//HAUT
	PA_LoadSpritePal(1, 0, (void*)nombres_Pal);			
	PA_CreateSprite(1, 0, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 64, 32);
	PA_CreateSprite(1, 1, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 88, 32);
	PA_CreateSprite(1, 2, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 112, 32);
	PA_CreateSprite(1, 3, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 136, 32);
	PA_CreateSprite(1, 4, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 160, 32);
	PA_CreateSprite(1, 5, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 184, 32);
	PA_CreateSprite(1, 6, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 208, 32);
	PA_CreateSprite(1, 7, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 232, 32);

	PA_CreateSprite(1, 8, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 64, 56);
	PA_CreateSprite(1, 9, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 88, 56);
	PA_CreateSprite(1, 10, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 112, 56);
	PA_CreateSprite(1, 11, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 136, 56);
	PA_CreateSprite(1, 12, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 160, 56);
	PA_CreateSprite(1, 13, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 184, 56);
	PA_CreateSprite(1, 14, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 208, 56);
	PA_CreateSprite(1, 15, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 232, 56);

	PA_CreateSprite(1, 16, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 64, 80);
	PA_CreateSprite(1, 17, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 88, 80);
	PA_CreateSprite(1, 18, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 112, 80);
	PA_CreateSprite(1, 19, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 136, 80);
	PA_CreateSprite(1, 20, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 160, 80);
	PA_CreateSprite(1, 21, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 184, 80);
	PA_CreateSprite(1, 22, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 208, 80);
	PA_CreateSprite(1, 23, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 232, 80);

	PA_CreateSprite(1, 24, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 64, 104);
	PA_CreateSprite(1, 25, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 88, 104);
	PA_CreateSprite(1, 26, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 112, 104);
	PA_CreateSprite(1, 27, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 136, 104);
	PA_CreateSprite(1, 28, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 160, 104);
	PA_CreateSprite(1, 29, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 184, 104);
	PA_CreateSprite(1, 30, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 208, 104);
	PA_CreateSprite(1, 31, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 0, 232, 104);

	PA_LoadSpritePal(1, 1, (void*)flags_Pal);
	PA_CreateSprite(1, 32, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 1, 32, 32);
	PA_CreateSprite(1, 33, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 1, 32, 56);
	PA_CreateSprite(1, 34, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 1, 32, 80);
	PA_CreateSprite(1, 35, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 1, 32, 104);

	//BAS
	PA_LoadSpritePal(0, 2, (void*)flags_Pal);			
	PA_CreateSprite(0, 36, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 2, 56, 36);
	PA_CreateSprite(0, 37, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 2, 176, 36);
	PA_CreateSprite(0, 38, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 2, 56, 60);
	PA_CreateSprite(0, 39, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 2, 176, 60);
	PA_CreateSprite(0, 40, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 2, 56, 84);
	PA_CreateSprite(0, 41, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 2, 176, 84);
	PA_CreateSprite(0, 42, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 2, 56, 108);
	PA_CreateSprite(0, 43, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 2, 176, 108);
	PA_CreateSprite(0, 44, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 2, 56, 132);
	PA_CreateSprite(0, 45, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 2, 176, 132);
	PA_CreateSprite(0, 46, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 2, 56, 156);
	PA_CreateSprite(0, 47, (void*)flags_Sprite, OBJ_SIZE_32X16, 1, 2, 176, 156);

	PA_LoadSpritePal(0, 3, (void*)icones_Pal);			
	PA_CreateSprite(0, BOUTON_L, (void*)icones_Sprite, OBJ_SIZE_32X16, 1, 3, 4, 4);
	PA_CreateSprite(0, BOUTON_R, (void*)icones_Sprite, OBJ_SIZE_32X16, 1, 3, 220, 4);
	PA_CreateSprite(0, BOUTON_SCORE, (void*)icones_Sprite, OBJ_SIZE_32X16, 1, 3, 112, 6);
	PA_CreateSprite(0, BOUTON_VALIDER, (void*)icones_Sprite, OBJ_SIZE_32X16, 1, 3, 8, 152);
	PA_CreateSprite(0, BOUTON_ANNULER, (void*)icones_Sprite, OBJ_SIZE_32X16, 1, 3, 112, 152);
	PA_CreateSprite(0, BOUTON_RESET, (void*)icones_Sprite, OBJ_SIZE_32X16, 1, 3, 216, 152);
	
	PA_LoadSpritePal(0, 4, (void*)flags_64_Pal);			
	PA_CreateSprite(0, FLAG1, (void*)flags_64_Sprite, OBJ_SIZE_64X32, 1, 4, 16, 68);
	PA_CreateSprite(0, FLAG2, (void*)flags_64_Sprite, OBJ_SIZE_64X32, 1, 4, 192, 68);
	
	PA_LoadSpritePal(0, 5, (void*)nombres_32_Pal);			
	PA_CreateSprite(0, SCORE1, (void*)nombres_32_Sprite, OBJ_SIZE_32X32, 1, 5, 91, 68);
	PA_CreateSprite(0, SCORE2, (void*)nombres_32_Sprite, OBJ_SIZE_32X32, 1, 5, 131, 68);
	PA_CreateSprite(0, PENALTY1, (void*)nombres_32_Sprite, OBJ_SIZE_32X32, 1, 5, 91, 112);
	PA_CreateSprite(0, PENALTY2, (void*)nombres_32_Sprite, OBJ_SIZE_32X32, 1, 5, 131, 112);
	
	PA_LoadSpritePal(0, 6, (void*)nombres_Pal);			
	PA_CreateSprite(0, 58, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 6, 104, 36);
	PA_CreateSprite(0, 59, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 6, 136, 36);
	PA_CreateSprite(0, 60, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 6, 104, 60);
	PA_CreateSprite(0, 61, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 6, 136, 60);
	PA_CreateSprite(0, 62, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 6, 104, 84);
	PA_CreateSprite(0, 63, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 6, 136, 84);
	PA_CreateSprite(0, 64, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 6, 104, 108);
	PA_CreateSprite(0, 65, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 6, 136, 108);
	PA_CreateSprite(0, 66, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 6, 104, 132);
	PA_CreateSprite(0, 67, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 6, 136, 132);
	PA_CreateSprite(0, 68, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 6, 104, 156);
	PA_CreateSprite(0, 69, (void*)nombres_Sprite, OBJ_SIZE_16X16, 1, 6, 136, 156);
	
	PA_LoadSpritePal(1, 7, (void*)Groupe_Lettres_Pal);
	PA_CreateSprite(1, LETTRE, (void*)Groupe_Lettres_Sprite, OBJ_SIZE_64X32, 1, 7, 0, 0);
	
	PA_LoadSpritePal(1, 8, (void*)Signe_Pal);
	PA_CreateSprite(1, SIGNE1, (void*)Signe_Sprite, OBJ_SIZE_8X8, 1, 8, 226, 37);
	PA_CreateSprite(1, SIGNE2, (void*)Signe_Sprite, OBJ_SIZE_8X8, 1, 8, 226, 61);
	PA_CreateSprite(1, SIGNE3, (void*)Signe_Sprite, OBJ_SIZE_8X8, 1, 8, 226, 85);
	PA_CreateSprite(1, SIGNE4, (void*)Signe_Sprite, OBJ_SIZE_8X8, 1, 8, 226, 109);
	
	PA_LoadSpritePal(1, 9, (void*)ballon_Pal);
	PA_CreateSprite(1, 77, (void*)ballon_Sprite, OBJ_SIZE_64X64, 1, 9, 188, 64);
	
	PA_LoadSpritePal(0, 10, (void*)ballon_Pal);
	PA_CreateSprite(0, 78, (void*)ballon_Sprite, OBJ_SIZE_64X64, 1, 10, 95, 151);
	PA_StartSpriteAnim(0, 78, 1, 6, 7);
	
	PA_LoadSpritePal(0, 11, (void*)quitter_Pal);
	PA_CreateSprite(0, QUITTER, (void*)quitter_Sprite, OBJ_SIZE_16X16, 1, 11, -1, 177);
	
	CalculStats();
	for (groupe_courant = 0; groupe_courant < 8; groupe_courant++) InitMatchsGroupes();
	groupe_courant = 0;
	//************BAS**********
	//BG 0
	PA_DeleteText(0);
	//SPRITES
	for ( i = 36; i < 70; i++) PA_SetSpriteAnim(0, i, 0);
	PA_SetSpriteAnim(0, QUITTER, 0);

	//************HAUT**********
	//BG 0
	PA_DeleteText(1);
	//SPRITES
	for ( i = 0; i < 36; i++) PA_SetSpriteAnim(1, i, 0);
	PA_SetSpriteAnim(1, LETTRE, 0);
	PA_SetSpriteAnim(1, SIGNE1, 0);
	PA_SetSpriteAnim(1, SIGNE2, 0);
	PA_SetSpriteAnim(1, SIGNE3, 0);
	PA_SetSpriteAnim(1, SIGNE4, 0);
	
	Determine_equipes_huitiemes();
	Determine_equipes_quarts();
	Determine_equipes_demi();
	Determine_equipes_finale();

	fadeout();

	while (1)
	{
		startmenu = 1;

		//***MENU***
		while(startmenu == 1)
		{
			   //LES GROUPES
				if (Stylus.Newpress && PA_StylusInZone(0, 10, 256, 34))
				{
					fadein();
					startmenu = 2;

					//********BAS*******
					//BG 0
					//BG 1
					//BG 2
					PA_LoadBackground(0, 2, &BG2_bas_selection);
					//BG 3
					PA_LoadGif(0, (void*)BG3_bas_groupes);
					//SPRITES
					PA_SetSpriteAnim(0, BOUTON_L, 1);
					PA_SetSpriteAnim(0, BOUTON_R, 3);
					PA_SetSpriteAnim(0, BOUTON_SCORE, 5);
					PA_StopSpriteAnim(0, 78);
					PA_SetSpriteAnim(0, 78, 0);
					PA_SetSpriteAnim(0, QUITTER, 1);

					//*********HAUT********
					//BG 0
					//BG 1
					//BG 2
					//BG 3
					if (langue == 1) PA_LoadGif(1, (void*)BG3_haut_groupes_eng);
					else if (langue == 2) PA_LoadGif(1, (void*)BG3_haut_groupes_fra);
					else if (langue == 3) PA_LoadGif(1, (void*)BG3_haut_groupes_ger);
					else if (langue == 4) PA_LoadGif(1, (void*)BG3_haut_groupes_ita);
					else if (langue == 5) PA_LoadGif(1, (void*)BG3_haut_groupes_esp);
					else PA_LoadGif(1, (void*)BG3_haut_groupes_eng);

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;

					CalculStats();
					InitMatchsGroupes();
					fadeout();
					NavigationGroupes();

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;
					selection_match = 0;
					selection_y = 0;
					selection = 0;

					//************BAS**********
					//BG 0
					PA_DeleteText(0);
					//BG 1
					//BG 2
					PA_HideBg(0, 2);
					//BG 3
					if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_menu_fra);
					else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_menu_ger);
					else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_menu_ita);
					else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_menu_esp);
					else PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					//SPRITES
					for ( i = 36; i < 70; i++) PA_SetSpriteAnim(0, i, 0);
					PA_StartSpriteAnim(0, 78, 1, 6, 7);
					PA_SetSpriteAnim(0, QUITTER, 0);

					//************HAUT**********
					//BG 0
					PA_DeleteText(1);
					//BG 1
					//BG 2
					//BG 3
					PA_LoadGif(1, (void*)BG3_haut_titre);
					//SPRITES
					for ( i = 0; i < 36; i++) PA_SetSpriteAnim(1, i, 0);
					PA_SetSpriteAnim(1, LETTRE, 0);
					PA_SetSpriteAnim(1, SIGNE1, 0);
					PA_SetSpriteAnim(1, SIGNE2, 0);
					PA_SetSpriteAnim(1, SIGNE3, 0);
					PA_SetSpriteAnim(1, SIGNE4, 0);
					fadeout();
				}

				//LES HUITIEMES
				if ( Stylus.Newpress && PA_StylusInZone(0, 38, 256, 61) )
				{
					fadein();
					startmenu = 4;

					//********BAS*******
					//BG 0
					//BG 1
					//BG 2
					PA_LoadBackground(0, 2, &BG2_bas_selection);
					//BG 3
					PA_LoadGif(0, (void*)BG3_bas_quatres);
					//SPRITES
					PA_SetSpriteAnim(0, BOUTON_R, 3);
					PA_SetSpriteAnim(0, BOUTON_SCORE, 5);
					PA_StopSpriteAnim(0, 78);
					PA_SetSpriteAnim(0, 78, 0);
					PA_SetSpriteAnim(0, QUITTER, 1);

					//*********HAUT********
					//BG 0
					//BG 1
					//BG 2
					//BG 3
					if (langue == 1) PA_LoadGif(1, (void*)BG3_haut_huitieme_eng);
					else if (langue == 2) PA_LoadGif(1, (void*)BG3_haut_huitieme_fra);
					else if (langue == 3) PA_LoadGif(1, (void*)BG3_haut_huitieme_ger);
					else if (langue == 4) PA_LoadGif(1, (void*)BG3_haut_huitieme_ita);
					else if (langue == 5) PA_LoadGif(1, (void*)BG3_haut_huitieme_esp);
					else PA_LoadGif(1, (void*)BG3_haut_huitieme_eng);
					//SPRITES
					//PA_StartSpriteAnim(1, 77, 1, 6, 7);

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;

					InitMatchsHuitiemes();
					PA_BGScrollY(0, 2, -24);
					fadeout();
					NavigationHuitiemes();

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;
					selection_match = 0;
					selection_y = 0;
					selection = 0;
					huitieme_courant = 0;

					//************BAS**********
					//BG 0
					PA_DeleteText(0);
					//BG 1
					//BG 2
					//BG 3
					if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_menu_fra);
					else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_menu_ger);
					else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_menu_ita);
					else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_menu_esp);
					else PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					//SPRITES
					for ( i = 36; i < 70; i++) PA_SetSpriteAnim(0, i, 0);
					PA_StartSpriteAnim(0, 78, 1, 6, 7);
					PA_SetSpriteAnim(0, QUITTER, 0);

					//************HAUT**********
					//BG 0
					PA_DeleteText(1);
					//BG 1
					//BG 2
					PA_HideBg(0, 2);
					//BG 3
					PA_LoadGif(1, (void*)BG3_haut_titre);
					//SPRITES
					//PA_StopSpriteAnim(1, 77);
					//PA_SetSpriteAnim(1, 77, 0);
					fadeout();
				}

				//LES QUARTS
				if ( Stylus.Newpress && PA_StylusInZone(0, 64, 256, 87) )
				{
					fadein();
					startmenu = 6;

					//********BAS*******
					//BG 0
					//BG 1
					//BG 2
					PA_LoadBackground(0, 2, &BG2_bas_selection);
					//BG 3
					PA_LoadGif(0, (void*)BG3_bas_quatres);
					//SPRITES
					PA_SetSpriteAnim(0, BOUTON_SCORE, 5);
					PA_StopSpriteAnim(0, 78);
					PA_SetSpriteAnim(0, 78, 0);
					PA_SetSpriteAnim(0, QUITTER, 1);

					//*********HAUT********
					//BG 0
					//BG 1
					//BG 2
					//BG 3
					if (langue == 1) PA_LoadGif(1, (void*)BG3_haut_quart_eng);
					else if (langue == 2) PA_LoadGif(1, (void*)BG3_haut_quart_fra);
					else if (langue == 3) PA_LoadGif(1, (void*)BG3_haut_quart_ger);
					else if (langue == 4) PA_LoadGif(1, (void*)BG3_haut_quart_ita);
					else if (langue == 5) PA_LoadGif(1, (void*)BG3_haut_quart_esp);
					else PA_LoadGif(1, (void*)BG3_haut_quart_eng);
					//SPRITES
					//PA_StartSpriteAnim(1, 77, 1, 6, 7);

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;
	
					InitMatchsQuarts();
					PA_BGScrollY(0, 2, -24);
					fadeout();
					NavigationQuarts();

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;
					selection = 0;

					//************BAS**********
					//BG 0
					PA_DeleteText(0);
					//BG 1
					//BG 2
					PA_HideBg(0, 2);
					//BG 3
					if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_menu_fra);
					else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_menu_ger);
					else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_menu_ita);
					else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_menu_esp);
					else PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					//SPRITES
					for ( i = 36; i < 70; i++) PA_SetSpriteAnim(0, i, 0);
					PA_StartSpriteAnim(0, 78, 1, 6, 7);
					PA_SetSpriteAnim(0, QUITTER, 0);

					//************HAUT**********
					//BG 0
					PA_DeleteText(1);
					//BG 1
					//BG 2
					//BG 3
					PA_LoadGif(1, (void*)BG3_haut_titre);
					//SPRITES
					//PA_StopSpriteAnim(1, 77);
					//PA_SetSpriteAnim(1, 77, 0);
					fadeout();
				}

				//LES DEMI
				if ( Stylus.Newpress && PA_StylusInZone(0, 90, 256, 112) )
				{
					fadein();
					startmenu = 8;

					//********BAS*******
					//BG 0
					//BG 1
					//BG 2
					PA_LoadBackground(0, 2, &BG2_bas_selection);
					//BG 3
					PA_LoadGif(0, (void*)BG3_bas_deux);
					//SPRITES
					PA_SetSpriteAnim(0, BOUTON_SCORE, 5);
					PA_StopSpriteAnim(0, 78);
					PA_SetSpriteAnim(0, 78, 0);
					PA_SetSpriteAnim(0, QUITTER, 1);

					//*********HAUT********
					//BG 0
					//BG 1
					//BG 2
					//BG 3
					if (langue == 1) PA_LoadGif(1, (void*)BG3_haut_demi_eng);
					else if (langue == 2) PA_LoadGif(1, (void*)BG3_haut_demi_fra);
					else if (langue == 3) PA_LoadGif(1, (void*)BG3_haut_demi_ger);
					else if (langue == 4) PA_LoadGif(1, (void*)BG3_haut_demi_ita);
					else if (langue == 5) PA_LoadGif(1, (void*)BG3_haut_demi_esp);
					else PA_LoadGif(1, (void*)BG3_haut_demi_eng);
					//SPRITES
					//PA_StartSpriteAnim(1, 77, 1, 6, 7);

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;

					InitMatchsDemi();
					PA_BGScrollY(0, 2, -48);
					fadeout();
					NavigationDemi();

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;
					selection = 0;

					//************BAS**********
					//BG 0
					PA_DeleteText(0);
					//BG 1
					//BG 2
					PA_HideBg(0, 2);
					//BG 3
					if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_menu_fra);
					else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_menu_ger);
					else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_menu_ita);
					else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_menu_esp);
					else PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					//SPRITES
					for ( i = 36; i < 70; i++) PA_SetSpriteAnim(0, i, 0);
					PA_StartSpriteAnim(0, 78, 1, 6, 7);
					PA_SetSpriteAnim(0, QUITTER, 0);

					//************HAUT**********
					//BG 0
					PA_DeleteText(1);
					//BG 1
					//BG 2
					//BG 3
					PA_LoadGif(1, (void*)BG3_haut_titre);
					//SPRITES
					//PA_StopSpriteAnim(1, 77);
					//PA_SetSpriteAnim(1, 77, 0);
					fadeout();
				}

				//LES FINALES
				if ( Stylus.Newpress && PA_StylusInZone(0, 116, 256, 139) )
				{
					fadein();
					startmenu = 10;

					//********BAS*******
					//BG 0
					//BG 1
					//BG 2
					PA_LoadBackground(0, 2, &BG2_bas_selection);
					//BG 3
					PA_LoadGif(0, (void*)BG3_bas_deux);
					//SPRITES
					PA_SetSpriteAnim(0, BOUTON_SCORE, 5);
					PA_StopSpriteAnim(0, 78);
					PA_SetSpriteAnim(0, 78, 0);
					PA_SetSpriteAnim(0, QUITTER, 1);

					//*********HAUT********
					//BG 0
					//BG 1
					//BG 2
					//BG 3
					if (langue == 1) PA_LoadGif(1, (void*)BG3_haut_finale_eng);
					else if (langue == 2) PA_LoadGif(1, (void*)BG3_haut_finale_fra);
					else if (langue == 3) PA_LoadGif(1, (void*)BG3_haut_finale_ger);
					else if (langue == 4) PA_LoadGif(1, (void*)BG3_haut_finale_ita);
					else if (langue == 5) PA_LoadGif(1, (void*)BG3_haut_finale_esp);
					else PA_LoadGif(1, (void*)BG3_haut_finale_eng);
					//SPRITES
					//PA_StartSpriteAnim(1, 77, 1, 6, 7);

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;

					InitMatchsFinales();
					PA_BGScrollY(0, 2, -48);
					fadeout();
					NavigationFinales();

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;
					selection = 0;

					//************BAS**********
					//BG 0
					PA_DeleteText(0);
					//BG 1
					//BG 2
					PA_HideBg(0, 2);
					//BG 3
					if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_menu_fra);
					else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_menu_ger);
					else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_menu_ita);
					else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_menu_esp);
					else PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					//SPRITES
					for ( i = 36; i < 70; i++) PA_SetSpriteAnim(0, i, 0);
					PA_StartSpriteAnim(0, 78, 1, 6, 7);
					PA_SetSpriteAnim(0, QUITTER, 0);

					//************HAUT**********
					//BG 0
					PA_DeleteText(1);
					//BG 1
					//BG 2
					//BG 3
					PA_LoadGif(1, (void*)BG3_haut_titre);
					//SPRITES
					//PA_StopSpriteAnim(1, 77);
					//PA_SetSpriteAnim(1, 77, 0);
					fadeout();
				}

				//LES STADES
				if ( Stylus.Newpress && PA_StylusInZone(2, 160, 91, 180) )
				{
					fadein();
					startmenu = 12;

					//********BAS*******
					//BG 0
					//BG 1
					//BG 2
					//BG 3
					if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_stades_eng);
					else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_stades_fra);
					else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_stades_ger);
					else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_stades_ita);
					else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_stades_esp);
					else PA_LoadGif(0, (void*)BG3_bas_stades_eng);
					//SPRITES
					PA_SetSpriteXY(0, BOUTON_L, 70, 20);
					PA_SetSpriteXY(0, BOUTON_R, 154, 20);
					PA_SetSpriteXY(0, QUITTER, 181, 20);
					PA_SetSpriteAnim(0, BOUTON_L, 13);
					PA_SetSpriteAnim(0, BOUTON_R, 15);
					PA_StopSpriteAnim(0, 78);
					PA_SetSpriteAnim(0, 78, 0);
					PA_SetSpriteAnim(0, QUITTER, 1);

					//*********HAUT********
					//BG 0
					//BG 1
					//BG 2
					//BG 3
					//SPRITES

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;

					InitStades();
					NavigationStades();

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;

					//************BAS**********
					//BG 0
					//BG 1
					//BG 2
					PA_HideBg(0, 2);
					//BG 3
					if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_menu_fra);
					else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_menu_ger);
					else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_menu_ita);
					else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_menu_esp);
					else PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					//SPRITES
					PA_SetSpriteXY(0, BOUTON_L, 4, 4);
					PA_SetSpriteXY(0, BOUTON_R, 220, 4);
					PA_SetSpriteXY(0, QUITTER, -1, 177);
					PA_SetSpriteAnim(0, BOUTON_L, 0);
					PA_SetSpriteAnim(0, BOUTON_R, 0);
					PA_StartSpriteAnim(0, 78, 1, 6, 7);
					PA_SetSpriteAnim(0, QUITTER, 0);

					//************HAUT**********
					//BG 0
					//BG 1
					//BG 2
					//BG 3
					PA_LoadGif(1, (void*)BG3_haut_titre);
					//SPRITES
					fadeout();
				}

				//LES EQUIPES
				if ( Stylus.Newpress && PA_StylusInZone(160, 160, 254, 180) )
				{
					fadein();
					startmenu = 14;

					//********BAS*******
					//BG 0
					//BG 1
					//BG 2
					//BG 3
					if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_equipes_eng);
					else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_equipes_fra);
					else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_equipes_ger);
					else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_equipes_ita);
					else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_equipes_esp);
					else PA_LoadGif(0, (void*)BG3_bas_equipes_eng);
					//SPRITES
					PA_SetSpriteXY(0, BOUTON_L, 70, 20);
					PA_SetSpriteXY(0, BOUTON_R, 154, 20);
					PA_SetSpriteXY(0, QUITTER, 181, 20);
					PA_SetSpriteAnim(0, BOUTON_L, 13);
					PA_SetSpriteAnim(0, BOUTON_R, 15);
					PA_StopSpriteAnim(0, 78);
					PA_SetSpriteAnim(0, 78, 0);
					PA_SetSpriteAnim(0, QUITTER, 1);

					//*********HAUT********
					//BG 0
					//BG 1
					//BG 2
					//BG 3
					//SPRITES

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;

					Equipes();
					NavigationEquipes();

					Stylus.X = 0; Stylus.Y = 0;
					Stylus.Newpress = false;

					//************BAS**********
					//BG 0
					//BG 1
					//BG 2
					PA_HideBg(0, 2);
					//BG 3
					if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_menu_fra);
					else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_menu_ger);
					else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_menu_ita);
					else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_menu_esp);
					else PA_LoadGif(0, (void*)BG3_bas_menu_eng);
					//SPRITES
					PA_SetSpriteXY(0, BOUTON_L, 4, 4);
					PA_SetSpriteXY(0, BOUTON_R, 220, 4);
					PA_SetSpriteXY(0, QUITTER, -1, 177);
					PA_SetSpriteAnim(0, BOUTON_L, 0);
					PA_SetSpriteAnim(0, BOUTON_R, 0);
					PA_StartSpriteAnim(0, 78, 1, 6, 7);
					PA_SetSpriteAnim(0, QUITTER, 0);

					//************HAUT**********
					//BG 0
					//BG 1
					//BG 2
					//BG 3
					PA_LoadGif(1, (void*)BG3_haut_titre);
					//SPRITES
					fadeout();
				}
		}
		PA_WaitForVBL();
	}
	return 0;
}


