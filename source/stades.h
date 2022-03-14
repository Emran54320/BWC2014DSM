void InitStades()
{   
	//LES SPRITES
	//HAUT
	if (stade_courant == 0)
	{
		PA_LoadGif(1, (void*)mineirao);
		PA_LoadBackground(0, 2, &BG2_bas_mineirao);
		PA_CenterOutputText(0, 1, "ESTADIO MINEIRAO");
	}
	if (stade_courant == 1)
	{
		PA_LoadGif(1, (void*)nacional);
		PA_LoadBackground(0, 2, &BG2_bas_nacional);
		PA_CenterOutputText(0, 1, "ESTADIO NACIONAL");
	}
	if (stade_courant == 2)
	{
		PA_LoadGif(1, (void*)pantanal);
		PA_LoadBackground(0, 2, &BG2_bas_pantanal);
		PA_CenterOutputText(0, 1, "ARENA PANTANAL");
	}
	if (stade_courant == 3)
	{
		PA_LoadGif(1, (void*)baixada);
		PA_LoadBackground(0, 2, &BG2_bas_baixada);
		PA_CenterOutputText(0, 1, "ARENA DA BAIXADA");
	}
	if (stade_courant == 4)
	{
		PA_LoadGif(1, (void*)castelao);
		PA_LoadBackground(0, 2, &BG2_bas_castelao);
		PA_CenterOutputText(0, 1, "ESTADIO CASTELAO");
	}
	if (stade_courant == 5)
	{
		PA_LoadGif(1, (void*)amazonia);
		PA_LoadBackground(0, 2, &BG2_bas_amazonia);
		PA_CenterOutputText(0, 1, "ARENA AMAZONIA");
	}
	if (stade_courant == 6)
	{
		PA_LoadGif(1, (void*)dunas);
		PA_LoadBackground(0, 2, &BG2_bas_dasdunas);
		PA_CenterOutputText(0, 1, "ESTADIO DAS DUNAS");
	}
	if (stade_courant == 7)
	{
		PA_LoadGif(1, (void*)beirario);
		PA_LoadBackground(0, 2, &BG2_bas_beirario);
		PA_CenterOutputText(0, 1, "ESTADIO BEIRA-RIO");
	}
	if (stade_courant == 8)
	{
		PA_LoadGif(1, (void*)pernambuco);
		PA_LoadBackground(0, 2, &BG2_bas_pernambuco);
		PA_CenterOutputText(0, 1, "ARENA PERNAMBUCO");
	}
	if (stade_courant == 9)
	{
		PA_LoadGif(1, (void*)maracana);
		PA_LoadBackground(0, 2, &BG2_bas_maracana);
		PA_CenterOutputText(0, 1, "ESTADIO DO MARACANA");
	}
	if (stade_courant == 10)
	{
		PA_LoadGif(1, (void*)fontenova);
		PA_LoadBackground(0, 2, &BG2_bas_fontenova);
		PA_CenterOutputText(0, 1, "ARENA FONTE NOVA");
	}
	if (stade_courant == 11)
	{
		PA_LoadGif(1, (void*)saopaulo);
		PA_LoadBackground(0, 2, &BG2_bas_saopaulo);
		PA_CenterOutputText(0, 1, "ARENA DE SAO PAULO");
	}
	
	PA_OutputText(0, 13, 3, "%02d  12", stade_courant+1);
}

void NavigationStades()
{
	startmenu = 13;
	fadeout();

	while (startmenu == 13)
	{
		if ((Pad.Newpress.R && stade_courant < 11)
		|| (Stylus.Newpress && PA_StylusInZone(159, 22, 180, 32) && stade_courant < 11))
		{
			PA_SetSpriteAnim(0, BOUTON_R, 16);
			fadein();
			stade_courant++;
			PA_DeleteText(0);
			InitStades();
			PA_SetSpriteAnim(0, BOUTON_R, 15);
			fadeout();
			Pad.Newpress.R = false;
		}
		else if ((Pad.Newpress.R && stade_courant == 11)
		|| (Stylus.Newpress && PA_StylusInZone(159, 22, 180, 32) && stade_courant == 11))
		{
			PA_SetSpriteAnim(0,BOUTON_R, 16);
			fadein();
			stade_courant = 0;
			PA_DeleteText(0);
			InitStades();
			PA_SetSpriteAnim(0, BOUTON_R, 15);
			fadeout();
			Pad.Newpress.R = false;
		}

		if ((Pad.Newpress.L && stade_courant > 0)
		|| (Stylus.Newpress && PA_StylusInZone(75, 22, 96, 32) && stade_courant > 0))
		{
			PA_SetSpriteAnim(0,BOUTON_L, 14);
			fadein();
			stade_courant--;
			PA_DeleteText(0);
			InitStades();
			PA_SetSpriteAnim(0,BOUTON_L, 13);
			fadeout();
			Pad.Newpress.L = false;
		}
		else if ((Pad.Newpress.L && stade_courant == 0)
		|| (Stylus.Newpress && PA_StylusInZone(75, 22, 96, 32) && stade_courant == 0))
		{
			PA_SetSpriteAnim(0,BOUTON_L, 14);
			fadein();
			stade_courant = 11;
			PA_DeleteText(0);
			InitStades();
			PA_SetSpriteAnim(0,BOUTON_L, 13);
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


