void Equipes()
{
	charge_img_equipes();

	if (equipe_courant == 0)
	{
		//PA_LoadGif(1, (void*)bra);
		PA_LoadBackground(0, 2, &BG2_bas_bra);
	}
	else if (equipe_courant == 1)
	{
		//PA_LoadGif(1, (void*)cro);
		PA_LoadBackground(0, 2, &BG2_bas_cro);
	}
	else if (equipe_courant == 2)
	{
		//PA_LoadGif(1, (void*)mex);
		PA_LoadBackground(0, 2, &BG2_bas_mex);
	}
	else if (equipe_courant == 3)
	{
		//PA_LoadGif(1, (void*)cmr);
		PA_LoadBackground(0, 2, &BG2_bas_cmr);
	}
	else if (equipe_courant == 4)
	{
		//PA_LoadGif(1, (void*)esp);
		PA_LoadBackground(0, 2, &BG2_bas_esp);
	}
	else if (equipe_courant == 5)
	{
		//PA_LoadGif(1, (void*)ned);
		PA_LoadBackground(0, 2, &BG2_bas_ned);
	}
	else if (equipe_courant == 6)
	{
		//PA_LoadGif(1, (void*)chi);
		PA_LoadBackground(0, 2, &BG2_bas_chi);
	}
	else if (equipe_courant == 7)
	{
		//PA_LoadGif(1, (void*)aus);
		PA_LoadBackground(0, 2, &BG2_bas_aus);
	}
	else if (equipe_courant == 8) {PA_LoadBackground(0, 2, &BG2_bas_col);}
	else if (equipe_courant == 9) {PA_LoadBackground(0, 2, &BG2_bas_gre);}
	else if (equipe_courant == 10) {PA_LoadBackground(0, 2, &BG2_bas_civ);}
	else if (equipe_courant == 11) {PA_LoadBackground(0, 2, &BG2_bas_jpn);}
	else if (equipe_courant == 12) {PA_LoadBackground(0, 2, &BG2_bas_uru);}
	else if (equipe_courant == 13) {PA_LoadBackground(0, 2, &BG2_bas_crc);}
	else if (equipe_courant == 14) {PA_LoadBackground(0, 2, &BG2_bas_eng);}
	else if (equipe_courant == 15) {PA_LoadBackground(0, 2, &BG2_bas_ita);}//15
	else if (equipe_courant == 16) {PA_LoadBackground(0, 2, &BG2_bas_sui);}
	else if (equipe_courant == 17) {PA_LoadBackground(0, 2, &BG2_bas_ecu);}
	else if (equipe_courant == 18) {PA_LoadBackground(0, 2, &BG2_bas_fra);}
	else if (equipe_courant == 19) {PA_LoadBackground(0, 2, &BG2_bas_hon);}//19
	else if (equipe_courant == 20) {PA_LoadBackground(0, 2, &BG2_bas_arg);}//20
	else if (equipe_courant == 21) {PA_LoadBackground(0, 2, &BG2_bas_bih);}//21
	else if (equipe_courant == 22) {PA_LoadBackground(0, 2, &BG2_bas_irn);}//22
	else if (equipe_courant == 23) {PA_LoadBackground(0, 2, &BG2_bas_nga);}//23
	else if (equipe_courant == 24) {PA_LoadBackground(0, 2, &BG2_bas_ger);}
	else if (equipe_courant == 25) {PA_LoadBackground(0, 2, &BG2_bas_por);}//25
	else if (equipe_courant == 26) {PA_LoadBackground(0, 2, &BG2_bas_gha);}//26
	else if (equipe_courant == 27) {PA_LoadBackground(0, 2, &BG2_bas_usa);}//27
	else if (equipe_courant == 28) {PA_LoadBackground(0, 2, &BG2_bas_bel);}//28
	else if (equipe_courant == 29) {PA_LoadBackground(0, 2, &BG2_bas_alg);}//29
	else if (equipe_courant == 30) {PA_LoadBackground(0, 2, &BG2_bas_rus);}//30
	else if (equipe_courant == 31) {PA_LoadBackground(0, 2, &BG2_bas_kor);}//31
	
	PA_OutputText(0, 13, 3, "%02d  32", equipe_courant+1);
	PA_CenterOutputText(0, 1, equipe[equipe_courant].nom);
}

void NavigationEquipes()
{
	startmenu = 15;
	fadeout();

	while (startmenu == 15)
	{
		if ((Pad.Newpress.R && equipe_courant < 31)
		|| (Stylus.Newpress && PA_StylusInZone(159, 22, 180, 32) && equipe_courant < 31))
		{
			PA_SetSpriteAnim(0, BOUTON_R, 16);
			fadein();
			equipe_courant++;
			PA_DeleteText(0);
			Equipes();
			PA_SetSpriteAnim(0, BOUTON_R, 15);
			fadeout();
			Pad.Newpress.R = false;
		}
		else if ((Pad.Newpress.R && equipe_courant == 31)
		|| (Stylus.Newpress && PA_StylusInZone(159, 22, 180, 32) && equipe_courant == 31))
		{
			PA_SetSpriteAnim(0, BOUTON_R, 16);
			fadein();
			equipe_courant = 0;
			PA_DeleteText(0);
			Equipes();
			PA_SetSpriteAnim(0, BOUTON_R, 15);
			fadeout();
			Pad.Newpress.R = false;
		}

		if ((Pad.Newpress.L && equipe_courant > 0)
		|| (Stylus.Newpress && PA_StylusInZone(75, 22, 96, 32) && equipe_courant > 0))
		{
			PA_SetSpriteAnim(0, BOUTON_L, 14);
			fadein();
			equipe_courant--;
			PA_DeleteText(0);
			Equipes();
			PA_SetSpriteAnim(0, BOUTON_L, 13);
			fadeout();
			Pad.Newpress.L = false;
		}
		else if ((Pad.Newpress.L && equipe_courant == 0)
		|| (Stylus.Newpress && PA_StylusInZone(75, 22, 96, 32) && equipe_courant == 0))
		{
			PA_SetSpriteAnim(0, BOUTON_L, 14);
			fadein();
			equipe_courant = 31;
			PA_DeleteText(0);
			PA_SetSpriteAnim(0, BOUTON_L, 13);
			Equipes();
			fadeout();
			Pad.Newpress.L = false;
		}

		if ((Pad.Newpress.B) || (Stylus.Newpress && PA_StylusInZone(182, 22, 1194, 32)))
		{
			PA_SetSpriteAnim(0, QUITTER, 2);
			attente(3);
			fadein();
			startmenu = 0;
			PA_DeleteText(0);
			Pad.Newpress.B = false;
		}

		PA_WaitForVBL();
	}
}


