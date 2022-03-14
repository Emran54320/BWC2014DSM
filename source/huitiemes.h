void Determine_equipes_huitiemes()
{
	if ((equipe[0].Joue + equipe[1].Joue + equipe[2].Joue + equipe[3].Joue) == 12)
	{
		huitieme[0].numero1 = groupe[0].premier;
		huitieme[2].numero2 = groupe[0].deuxieme;
		huitieme[0].equipe1 = equipe[huitieme[0].numero1].nom;
		huitieme[2].equipe2 = equipe[huitieme[2].numero2].nom;
		huitieme[0].abb1    = equipe[huitieme[0].numero1].abb;      
		huitieme[2].abb2    = equipe[huitieme[2].numero2].abb;
	}
	else
	{
		huitieme[0].numero1 = 32;
		if (langue == 1) huitieme[0].equipe1 = "1st Group A";
		else if (langue == 2) huitieme[0].equipe1 = "1er Groupe A";
		else if (langue == 3) huitieme[0].equipe1 = "1. Gruppe A";
		else if (langue == 4) huitieme[0].equipe1 = "1° Gruppo A";
		else if (langue == 5) huitieme[0].equipe1 = "1a Grupo A";
		else huitieme[0].equipe1 = "1st Group A";
		huitieme[0].abb1 = "1-A";

		huitieme[4].numero2 = 32;
		if (langue == 1) huitieme[2].equipe2 = "2nd Group A";
		else if (langue == 2) huitieme[2].equipe2 = "2eme Groupe A";
		else if (langue == 3) huitieme[2].equipe2 = "2. Gruppe A";
		else if (langue == 4) huitieme[2].equipe2 = "2° Gruppo A";
		else if (langue == 5) huitieme[2].equipe2 = "2a Grupo A";
		else huitieme[2].equipe2 = "2nd Group A";
		huitieme[2].abb2 = "2-A";
	}

	if ((equipe[4].Joue + equipe[5].Joue + equipe[6].Joue + equipe[7].Joue) == 12)
	{
		huitieme[2].numero1 = groupe[1].premier;
		huitieme[0].numero2 = groupe[1].deuxieme;
		huitieme[2].equipe1 = equipe[huitieme[2].numero1].nom;
		huitieme[0].equipe2 = equipe[huitieme[0].numero2].nom;
		huitieme[2].abb1    = equipe[huitieme[2].numero1].abb;
		huitieme[0].abb2    = equipe[huitieme[0].numero2].abb;
	}
	else
	{
		huitieme[2].numero1 = 32;
		if (langue == 1) huitieme[2].equipe1 = "1st Group B";
		else if (langue == 2) huitieme[2].equipe1 = "1er Groupe B";
		else if (langue == 3) huitieme[2].equipe1 = "1. Gruppe B";
		else if (langue == 4) huitieme[2].equipe1 = "1° Gruppo B";
		else if (langue == 5) huitieme[2].equipe1 = "1a Grupo B";
		else huitieme[2].equipe1 = "1st Group B";
		huitieme[2].abb1 = "1-B";

		huitieme[0].numero2 = 32;
		if (langue == 1) huitieme[0].equipe2 = "2nd Group B";
		else if (langue == 2) huitieme[0].equipe2 = "2eme Groupe B";
		else if (langue == 3) huitieme[0].equipe2 = "2. Gruppe B";
		else if (langue == 4) huitieme[0].equipe2 = "2° Gruppo B";
		else if (langue == 5) huitieme[0].equipe2 = "2a Grupo B";
		else huitieme[0].equipe2 = "2nd Group B";
		huitieme[0].abb2 = "2-B";
	}

	if ((equipe[8].Joue + equipe[9].Joue + equipe[10].Joue + equipe[11].Joue) == 12)
	{
		huitieme[1].numero1 = groupe[2].premier;
		huitieme[1].equipe1 = equipe[huitieme[1].numero1].nom;
		huitieme[1].abb1 = equipe[huitieme[1].numero1].abb;

		huitieme[3].numero2 = groupe[2].deuxieme;
		huitieme[3].equipe2 = equipe[huitieme[3].numero2].nom;
		huitieme[3].abb2 = equipe[huitieme[3].numero2].abb;
	}
	else
	{
		huitieme[1].numero1 = 32;
		if (langue == 1) huitieme[1].equipe1 = "1st Group C";
		else if (langue == 2) huitieme[1].equipe1 = "1er Groupe C";
		else if (langue == 3) huitieme[1].equipe1 = "1. Gruppe C";
		else if (langue == 4) huitieme[1].equipe1 = "1° Gruppo C";
		else if (langue == 5) huitieme[1].equipe1 = "1a Grupo C";
		else huitieme[1].equipe1 = "1st Group C";
		huitieme[1].abb1 = "1-C";

		huitieme[3].numero2 = 32;
		if (langue == 1) huitieme[3].equipe2 = "2nd Group C";
		else if (langue == 2) huitieme[3].equipe2 = "2eme Groupe C";
		else if (langue == 3) huitieme[3].equipe2 = "2. Gruppe C";
		else if (langue == 4) huitieme[3].equipe2 = "2° Gruppo C";
		else if (langue == 5) huitieme[3].equipe2 = "2a Grupo C";
		else huitieme[3].equipe2 = "2nd Group C";
		huitieme[3].abb2 = "2-C";
	}

	if ((equipe[12].Joue + equipe[13].Joue + equipe[14].Joue + equipe[15].Joue) == 12)
	{
		huitieme[1].numero2 = groupe[3].deuxieme;
		huitieme[1].equipe2 = equipe[huitieme[1].numero2].nom;
		huitieme[1].abb2 = equipe[huitieme[1].numero2].abb;

		huitieme[3].numero1 = groupe[3].premier;
		huitieme[3].equipe1 = equipe[huitieme[3].numero1].nom;
		huitieme[3].abb1 = equipe[huitieme[3].numero1].abb;
	}
	else
	{
		huitieme[1].numero2 = 32;
		if (langue == 1) huitieme[1].equipe2 = "2nd Group D";
		else if (langue == 2) huitieme[1].equipe2 = "2eme Groupe D";
		else if (langue == 3) huitieme[1].equipe2 = "2. Gruppe D";
		else if (langue == 4) huitieme[1].equipe2 = "2° Gruppo D";
		else if (langue == 5) huitieme[1].equipe2 = "2a Grupo D";
		else huitieme[1].equipe2 = "2nd Group D";
		huitieme[1].abb2 = "2-D";

		huitieme[3].numero1 = 32;
		if (langue == 1) huitieme[3].equipe1 = "1st Group D";
		else if (langue == 2) huitieme[3].equipe1 = "1er Groupe D";
		else if (langue == 3) huitieme[3].equipe1 = "1. Gruppe D";
		else if (langue == 4) huitieme[3].equipe1 = "1° Gruppo D";
		else if (langue == 5) huitieme[3].equipe1 = "1a Grupo D";
		else huitieme[3].equipe1 = "1st Group D";
		huitieme[3].abb1 = "1-D";
	}

	if ((equipe[16].Joue + equipe[17].Joue + equipe[18].Joue + equipe[19].Joue) == 12)
	{
		huitieme[4].numero1 = groupe[4].premier;
		huitieme[4].equipe1 = equipe[huitieme[4].numero1].nom;
		huitieme[4].abb1 = equipe[huitieme[4].numero1].abb;

		huitieme[6].numero2 = groupe[4].deuxieme;
		huitieme[6].equipe2 = equipe[huitieme[6].numero2].nom;
		huitieme[6].abb2 = equipe[huitieme[6].numero2].abb;
	}
	else
	{
		huitieme[4].numero1 = 32;
		if (langue == 1) huitieme[4].equipe1 = "1st Group E";
		else if (langue == 2) huitieme[4].equipe1 = "1er Groupe E";
		else if (langue == 3) huitieme[4].equipe1 = "1. Gruppe E";
		else if (langue == 4) huitieme[4].equipe1 = "1° Gruppo E";
		else if (langue == 5) huitieme[4].equipe1 = "1a Grupo E";
		else huitieme[4].equipe1 = "1st Group E";
		huitieme[4].abb1 = "1-E";

		huitieme[6].numero2 = 32;
		if (langue == 1) huitieme[6].equipe2 = "2nd Group E";
		else if (langue == 2) huitieme[6].equipe2 = "2eme Groupe E";
		else if (langue == 3) huitieme[6].equipe2 = "2. Gruppe E";
		else if (langue == 4) huitieme[6].equipe2 = "2° Gruppo E";
		else if (langue == 5) huitieme[6].equipe2 = "2a Grupo E";
		else huitieme[6].equipe2 = "2nd Group E";
		huitieme[6].abb2 = "2-E";
	}

	if ((equipe[20].Joue + equipe[21].Joue + equipe[22].Joue + equipe[23].Joue) == 12)
	{
		huitieme[4].numero2 = groupe[5].deuxieme;
		huitieme[4].equipe2 = equipe[huitieme[4].numero2].nom;
		huitieme[4].abb2 = equipe[huitieme[4].numero2].abb;

		huitieme[6].numero1 = groupe[5].premier;
		huitieme[6].equipe1 = equipe[huitieme[6].numero1].nom;
		huitieme[6].abb1 = equipe[huitieme[6].numero1].abb;
	}
	else
	{
		huitieme[4].numero2 = 32;
		if (langue == 1) huitieme[4].equipe2 = "2nd Group F";
		else if (langue == 2) huitieme[4].equipe2 = "2eme Groupe F";
		else if (langue == 3) huitieme[4].equipe2 = "2. Gruppe F";
		else if (langue == 4) huitieme[4].equipe2 = "2° Gruppo F";
		else if (langue == 5) huitieme[4].equipe2 = "2a Grupo F";
		else huitieme[4].equipe2 = "2nd Group F";
		huitieme[4].abb2 = "2-F";

		huitieme[6].numero1 = 32;
		if (langue == 1) huitieme[6].equipe1 = "1st Group F";
		else if (langue == 2) huitieme[6].equipe1 = "1er Groupe F";
		else if (langue == 3) huitieme[6].equipe1 = "1. Gruppe F";
		else if (langue == 4) huitieme[6].equipe1 = "1° Gruppo F";
		else if (langue == 5) huitieme[6].equipe1 = "1a Grupo F";
		else huitieme[6].equipe1 = "1st Group F";
		huitieme[6].abb1 = "1-F";
	}

	if ((equipe[24].Joue + equipe[25].Joue + equipe[26].Joue + equipe[27].Joue) == 12)
	{
		huitieme[5].numero1 = groupe[6].premier;
		huitieme[5].equipe1 = equipe[huitieme[5].numero1].nom;
		huitieme[5].abb1 = equipe[huitieme[5].numero1].abb;

		huitieme[7].numero2 = groupe[6].deuxieme;
		huitieme[7].equipe2 = equipe[huitieme[7].numero2].nom;
		huitieme[7].abb2 = equipe[huitieme[7].numero2].abb;
	}
	else
	{
		huitieme[5].numero1 = 32;
		if (langue == 1) huitieme[5].equipe1 = "1st Group G";
		else if (langue == 2) huitieme[5].equipe1 = "1er Groupe G";
		else if (langue == 3) huitieme[5].equipe1 = "1. Gruppe G";
		else if (langue == 4) huitieme[5].equipe1 = "1° Gruppo G";
		else if (langue == 5) huitieme[5].equipe1 = "1a Grupo G";
		else huitieme[5].equipe1 = "1st Group G";
		huitieme[5].abb1 = "1-G";

		huitieme[7].numero2 = 32;
		if (langue == 1) huitieme[7].equipe2 = "2nd Group G";
		else if (langue == 2) huitieme[7].equipe2 = "2eme Groupe G";
		else if (langue == 3) huitieme[7].equipe2 = "2. Gruppe G";
		else if (langue == 4) huitieme[7].equipe2 = "2° Gruppo G";
		else if (langue == 5) huitieme[7].equipe2 = "2a Grupo G";
		else huitieme[7].equipe2 = "2nd Group G";
		huitieme[7].abb2 = "2-G";
	}

	if ((equipe[28].Joue + equipe[29].Joue + equipe[30].Joue + equipe[31].Joue) == 12)
	{
		huitieme[5].numero2 = groupe[7].deuxieme;
		huitieme[5].equipe2 = equipe[huitieme[5].numero2].nom;
		huitieme[5].abb2 = equipe[huitieme[5].numero2].abb;

		huitieme[7].numero1 = groupe[7].premier;
		huitieme[7].equipe1 = equipe[huitieme[7].numero1].nom;
		huitieme[7].abb1 = equipe[huitieme[7].numero1].abb;
	}
	else
	{
		huitieme[5].numero2 = 32;
		if (langue == 1) huitieme[5].equipe2 = "2nd Group H";
		else if (langue == 2) huitieme[5].equipe2 = "2eme Groupe H";
		else if (langue == 3) huitieme[5].equipe2 = "2. Gruppe H";
		else if (langue == 4) huitieme[5].equipe2 = "2° Gruppo H";
		else if (langue == 5) huitieme[5].equipe2 = "2a Grupo H";
		else huitieme[5].equipe2 = "2nd Group H";
		huitieme[5].abb2 = "2-H";

		huitieme[7].numero1 = 32;
		if (langue == 1) huitieme[7].equipe1 = "1st Group H";
		else if (langue == 2) huitieme[7].equipe1 = "1er Groupe H";
		else if (langue == 3) huitieme[7].equipe1 = "1. Gruppe H";
		else if (langue == 4) huitieme[7].equipe1 = "1° Gruppo H";
		else if (langue == 5) huitieme[7].equipe1 = "1a Grupo H";
		else huitieme[7].equipe1 = "1st Group H";
		huitieme[7].abb1 = "1-H";
	}
}

void InitMatchsHuitiemes()
{
	Determine_equipes_huitiemes();

	//LES SPRITES
	//HAUT

	//BAS
	PA_SetSpriteAnim(0, 38, huitieme[0 + huitieme_courant*4].numero1 + 1);
	PA_SetSpriteAnim(0, 39, huitieme[0 + huitieme_courant*4].numero2 + 1);
	PA_SetSpriteAnim(0, 40, huitieme[1 + huitieme_courant*4].numero1 + 1);
	PA_SetSpriteAnim(0, 41, huitieme[1 + huitieme_courant*4].numero2 + 1);
	PA_SetSpriteAnim(0, 42, huitieme[2 + huitieme_courant*4].numero1 + 1);
	PA_SetSpriteAnim(0, 43, huitieme[2 + huitieme_courant*4].numero2 + 1);
	PA_SetSpriteAnim(0, 44, huitieme[3 + huitieme_courant*4].numero1 + 1);
	PA_SetSpriteAnim(0, 45, huitieme[3 + huitieme_courant*4].numero2 + 1);

	PA_SetSpriteAnim(0, 60, (huitieme[0 + huitieme_courant*4].score1+1) * huitieme[0 + huitieme_courant*4].jouer);
	PA_SetSpriteAnim(0, 61, (huitieme[0 + huitieme_courant*4].score2+1) * huitieme[0 + huitieme_courant*4].jouer);
	PA_SetSpriteAnim(0, 62, (huitieme[1 + huitieme_courant*4].score1+1) * huitieme[1 + huitieme_courant*4].jouer);
	PA_SetSpriteAnim(0, 63, (huitieme[1 + huitieme_courant*4].score2+1) * huitieme[1 + huitieme_courant*4].jouer);
	PA_SetSpriteAnim(0, 64, (huitieme[2 + huitieme_courant*4].score1+1) * huitieme[2 + huitieme_courant*4].jouer);
	PA_SetSpriteAnim(0, 65, (huitieme[2 + huitieme_courant*4].score2+1) * huitieme[2 + huitieme_courant*4].jouer);
	PA_SetSpriteAnim(0, 66, (huitieme[3 + huitieme_courant*4].score1+1) * huitieme[3 + huitieme_courant*4].jouer);
	PA_SetSpriteAnim(0, 67, (huitieme[3 + huitieme_courant*4].score2+1) * huitieme[3 + huitieme_courant*4].jouer);

	PA_OutputText(0, 2, 8, "%s                      %s", huitieme[0 + huitieme_courant*4].abb1, huitieme[0 + huitieme_courant*4].abb2);
	PA_OutputText(0, 2, 11, "%s                      %s", huitieme[1 + huitieme_courant*4].abb1, huitieme[1 + huitieme_courant*4].abb2);
	PA_OutputText(0, 2, 14, "%s                      %s", huitieme[2 + huitieme_courant*4].abb1, huitieme[2 + huitieme_courant*4].abb2);
	PA_OutputText(0, 2, 17, "%s                      %s", huitieme[3 + huitieme_courant*4].abb1, huitieme[3 + huitieme_courant*4].abb2);
	
	if (huitieme[0 + huitieme_courant*4].penalty1 != 0 || huitieme[0 + huitieme_courant*4].penalty2 != 0) PA_OutputText(0, 11, 8, "%d        %d", huitieme[0 + huitieme_courant*4].penalty1, huitieme[0 + huitieme_courant*4].penalty2);
	if (huitieme[1 + huitieme_courant*4].penalty1 != 0 || huitieme[1 + huitieme_courant*4].penalty2 != 0) PA_OutputText(0, 11, 11, "%d        %d", huitieme[1 + huitieme_courant*4].penalty1, huitieme[1 + huitieme_courant*4].penalty2);
	if (huitieme[2 + huitieme_courant*4].penalty1 != 0 || huitieme[2 + huitieme_courant*4].penalty2 != 0) PA_OutputText(0, 11, 14, "%d        %d", huitieme[2 + huitieme_courant*4].penalty1, huitieme[2 + huitieme_courant*4].penalty2);
	if (huitieme[3 + huitieme_courant*4].penalty1 != 0 || huitieme[3 + huitieme_courant*4].penalty2 != 0) PA_OutputText(0, 11, 17, "%d        %d", huitieme[3 + huitieme_courant*4].penalty1, huitieme[3 + huitieme_courant*4].penalty2);
	
	selection_match = (huitieme_courant*4) + selection;

	PA_CenterOutputText(1, 17, huitieme[selection_match].ville);
	PA_CenterOutputText(1, 19, huitieme[selection_match].stade);
	
	if (langue == 1){
		PA_OutputText(1, 1, 21, "ON %s", huitieme[selection_match].date);
		PA_OutputText(1, 23, 21, "IN %s", huitieme[selection_match].heure);
	}
	else if (langue == 2){
		PA_OutputText(1, 1, 21, "LE %s", huitieme[selection_match].date);
		PA_OutputText(1, 24, 21, "A %s", huitieme[selection_match].heure);
	}
	else if (langue == 3){
		PA_OutputText(1, 1, 21, "AM %s", huitieme[selection_match].date);
		PA_OutputText(1, 23, 21, "IN %s", huitieme[selection_match].heure);
	}
	else if (langue == 4){
		PA_OutputText(1, 1, 21, "SU %s", huitieme[selection_match].date);
		PA_OutputText(1, 24, 21, "A %s", huitieme[selection_match].heure);
	}
	else if (langue == 5){
		PA_OutputText(1, 1, 21, "EL %s", huitieme[selection_match].date);
		PA_OutputText(1, 23, 21, "EN %s", huitieme[selection_match].heure);
	}
	else{
		PA_OutputText(1, 1, 21, "ON %s", huitieme[selection_match].date);
		PA_OutputText(1, 23, 21, "IN %s", huitieme[selection_match].heure);
	}

	PA_OutputText(1, 1, 22, "%s", huitieme[selection_match].equipe1);
	PA_RightOutputText(1, 22, huitieme[selection_match].equipe2);   
}

void NavigationMatchsHuitiemes()
{
	if (entrer_score == 0)
	{
		if ((Pad.Newpress.B) || (Stylus.Newpress && PA_StylusInZone(1, 179, 13, 189)))
		{
			PA_SetSpriteAnim(0, QUITTER, 2);
			attente(3);
			fadein();
			entrer_score = 0;
			startmenu = 0;
			Pad.Newpress.B = false;
			Stylus.Newpress = false;
		}
	
		if ((Pad.Newpress.R && huitieme_courant == 0)
		|| (Stylus.Newpress && PA_StylusInZone(219, 3, 252, 20) && huitieme_courant == 0))
		{
			PA_SetSpriteAnim(0, BOUTON_R, 4);
			fadein();			
			huitieme_courant++;
			PA_DeleteText(1);
			PA_DeleteText(0);
			InitMatchsHuitiemes();
			PA_SetSpriteAnim(0, BOUTON_R, 0);
			PA_SetSpriteAnim(0, BOUTON_L, 1);
			fadeout();
			Pad.Newpress.R = false;
			Stylus.Newpress = false;
		}
		if ((Pad.Newpress.L && huitieme_courant == 1)
		|| (Stylus.Newpress && PA_StylusInZone(3, 3, 36, 20) && huitieme_courant == 1))
		{
			PA_SetSpriteAnim(0, BOUTON_L, 2);
			fadein();
			huitieme_courant--;
			PA_DeleteText(1);
			PA_DeleteText(0);
			InitMatchsHuitiemes();
			PA_SetSpriteAnim(0, BOUTON_L, 0);
			PA_SetSpriteAnim(0, BOUTON_R, 3);
			fadeout();
			Pad.Newpress.L = false;
			Stylus.Newpress = false;
		}

		if (Pad.Newpress.Down && selection < 3)
		{
			selection++;
			PA_DeleteText(1);
			InitMatchsHuitiemes();
			Pad.Newpress.Down = false;
		}
		else if (Pad.Newpress.Up && selection > 0)
		{
			selection--;
			PA_DeleteText(1);
			InitMatchsHuitiemes();
			Pad.Newpress.Up = false;
		}
	
		if (Stylus.Newpress)
		{
			//SELECTION AU STYLET
			if (PA_StylusInZone(4, 32, 252, 166))
			{
				PA_DeleteText(1);

				if (PA_StylusInZone(4, 56, 252, 80)) selection = 0;
				else if (PA_StylusInZone(4, 80, 252, 104)) selection = 1;
				else if (PA_StylusInZone(4, 104, 252, 128)) selection = 2;
				else if (PA_StylusInZone(4, 128, 252, 152)) selection = 3;

				selection_match = (huitieme_courant*4) + selection;
			}

			//SCORE
			if (PA_StylusInZone(112, 8, 144, 24) && (huitieme[selection_match].numero1 != 32) && (huitieme[selection_match].numero2 != 32)
			&& ((quarts[0].jouer + quarts[1].jouer + quarts[2].jouer + quarts[3].jouer) == 0))
			{
				mmEffect(SFX_SFXA);
				entrer_score = 1;
				fadein();
				PA_DeleteText(0);
				PA_HideBg(0, 2);
				PA_LoadGif(0, (void*)BG3_bas_score);
				for (i = 0; i < 51; i++) PA_SetSpriteAnim(0, i, 0);
				for (i = 58; i < 70; i++) PA_SetSpriteAnim(0, i, 0);
				PA_SetSpriteAnim(0, BOUTON_VALIDER, 7);
				PA_SetSpriteAnim(0, BOUTON_RESET, 11);
				PA_SetSpriteAnim(0, QUITTER, 0);

				PA_SetSpriteAnim(0, FLAG1, huitieme[selection_match].numero1 + 1);
				PA_SetSpriteAnim(0, FLAG2, huitieme[selection_match].numero2 + 1);
				PA_SetSpriteAnim(0, SCORE1, huitieme[selection_match].score1 + 1);
				PA_SetSpriteAnim(0, SCORE2, huitieme[selection_match].score2 + 1);
				fadeout();
			} 

			Stylus.Newpress = false;
		}

		PA_BGScrollY(0, 2, -24-selection*24);
	}
	else if (entrer_score == 1)
	{
		if (Stylus.Newpress)
		{
			if (PA_StylusInZone(70, 70, 86, 78))
			{
				mmEffect(SFX_SFXB);
				huitieme[selection_match].score1++;
				PA_SetSpriteAnim(0, SCORE1, huitieme[selection_match].score1 + 1);
			}
			else if (PA_StylusInZone(70, 86, 86, 104) && huitieme[selection_match].score1 > 0)
			{
				huitieme[selection_match].score1--;
				PA_SetSpriteAnim(0, SCORE1, huitieme[selection_match].score1 + 1);
			}

			if (PA_StylusInZone(166, 70, 182, 78))
			{
				mmEffect(SFX_SFXB);
				huitieme[selection_match].score2++;
				PA_SetSpriteAnim(0, SCORE2, huitieme[selection_match].score2 + 1);
			}
			else if (PA_StylusInZone(166, 86, 182, 104) && huitieme[selection_match].score2 > 0)
			{
				huitieme[selection_match].score2--;
				PA_SetSpriteAnim(0, SCORE2, huitieme[selection_match].score2 + 1);
			} 

			//VALIDER
			if (PA_StylusInZone(8, 152, 40, 168))
			{
				if (huitieme[selection_match].score1 > huitieme[selection_match].score2)
				{
					Huitiemes[selection_match].premier = huitieme[selection_match].numero1;
				}
				else if (huitieme[selection_match].score2 > huitieme[selection_match].score1)
				{
					Huitiemes[selection_match].premier = huitieme[selection_match].numero2;
				}
				else
				{
					mmEffect(SFX_SFXA);
					fadein();
					penalty = 1;
					PA_LoadGif(0, (void*)BG3_bas_penalty);
					PA_SetSpriteAnim(0, BOUTON_RESET, 0);
					PA_SetSpriteAnim(0, PENALTY1, huitieme[selection_match].penalty1 + 1);
					PA_SetSpriteAnim(0, PENALTY2, huitieme[selection_match].penalty2 + 1);
					fadeout();
					Stylus.Newpress = false;

					while(penalty == 1)
					{
						if (Stylus.Newpress)
						{
							if (PA_StylusInZone(70, 116, 88, 124))
							{
								mmEffect(SFX_SFXB);
								huitieme[selection_match].penalty1++;
								PA_SetSpriteAnim(0, PENALTY1, huitieme[selection_match].penalty1 + 1);
							}
							else if (PA_StylusInZone(70, 132, 88, 140) && huitieme[selection_match].penalty1 > 0)
							{
								huitieme[selection_match].penalty1--;
								PA_SetSpriteAnim(0, PENALTY1, huitieme[selection_match].penalty1 + 1);
							}

							if (PA_StylusInZone(166, 116, 182, 124))
							{
								mmEffect(SFX_SFXB);
								huitieme[selection_match].penalty2++;
								PA_SetSpriteAnim(0, PENALTY2, huitieme[selection_match].penalty2 + 1);
							}
							else if (PA_StylusInZone(166, 132, 182, 140) && huitieme[selection_match].penalty2 > 0)
							{
								huitieme[selection_match].penalty2--;
								PA_SetSpriteAnim(0, PENALTY2, huitieme[selection_match].penalty2 + 1);
							}

							//VALIDER
							if (PA_StylusInZone(8, 152, 40, 168))
							{
								if (huitieme[selection_match].penalty1 > huitieme[selection_match].penalty2)
								{
								   Huitiemes[selection_match].premier = huitieme[selection_match].numero1;
								   penalty = 0;
								}
								else if (huitieme[selection_match].penalty2 > huitieme[selection_match].penalty1)
								{
									Huitiemes[selection_match].premier = huitieme[selection_match].numero2;
									penalty = 0;
								}
							}
							Stylus.Newpress = false;
						}
						PA_WaitForVBL();
					}
				}

				mmEffect(SFX_SFXA);
				fadein();
				huitieme[selection_match].jouer = 1;
 
				//***************
				entrer_score = 0;
				InitMatchsHuitiemes();
				sauver_sauvegarde();
				PA_LoadGif(0, (void*)BG3_bas_quatres);
				PA_SetSpriteAnim(0, BOUTON_L, 1*huitieme_courant);
				PA_SetSpriteAnim(0, BOUTON_R, 3-3*huitieme_courant);
				PA_SetSpriteAnim(0, BOUTON_SCORE, 5);
				PA_SetSpriteAnim(0, BOUTON_VALIDER, 0);
				PA_SetSpriteAnim(0, BOUTON_RESET, 0);
				PA_SetSpriteAnim(0, QUITTER, 1);

				PA_SetSpriteAnim(0, FLAG1, 0);
				PA_SetSpriteAnim(0, FLAG2, 0);
				PA_SetSpriteAnim(0, SCORE1, 0);
				PA_SetSpriteAnim(0, SCORE2, 0);
				PA_SetSpriteAnim(0, PENALTY1, 0);
				PA_SetSpriteAnim(0, PENALTY2, 0);

				PA_ShowBg(0, 2);
				fadeout();
			}

			//RESET
			if (PA_StylusInZone(216, 152, 248, 168))
			{
				fadein();
				huitieme[selection_match].jouer = 0;
				huitieme[selection_match].score1 = 0;
				huitieme[selection_match].score2 = 0;
				huitieme[selection_match].penalty1 = 0;
				huitieme[selection_match].penalty2 = 0;
				Huitiemes[selection_match].premier = 32;
				entrer_score = 0;
				InitMatchsHuitiemes();
				sauver_sauvegarde();
				PA_LoadGif(0, (void*)BG3_bas_quatres);
				PA_SetSpriteAnim(0, BOUTON_L, 1*huitieme_courant);
				PA_SetSpriteAnim(0, BOUTON_R, 3-3*huitieme_courant);
				PA_SetSpriteAnim(0, BOUTON_SCORE, 5);
				PA_SetSpriteAnim(0, BOUTON_VALIDER, 0);
				PA_SetSpriteAnim(0, BOUTON_RESET, 0);
				PA_SetSpriteAnim(0, QUITTER, 1);

				PA_SetSpriteAnim(0, FLAG1, 0);
				PA_SetSpriteAnim(0, FLAG2, 0);
				PA_SetSpriteAnim(0, SCORE1, 0);
				PA_SetSpriteAnim(0, SCORE2, 0);

				PA_ShowBg(0, 2);
				fadeout();
			}

			Stylus.Newpress = false;
		}
	}
}

void NavigationHuitiemes()
{
	startmenu = 5;

	while (startmenu == 5)
	{
		selection_match = (huitieme_courant*4) + selection;
		
		NavigationMatchsHuitiemes();

		PA_CenterOutputText(1, 17, huitieme[selection_match].ville);
		PA_CenterOutputText(1, 19, huitieme[selection_match].stade);
		
		if (langue == 1){
			PA_OutputText(1, 1, 21, "ON %s", huitieme[selection_match].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection_match + 48 + 1);
			PA_OutputText(1, 23, 21, "IN %s", huitieme[selection_match].heure);
		}
		else if (langue == 2){
			PA_OutputText(1, 1, 21, "LE %s", huitieme[selection_match].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection_match + 48 + 1);
			PA_OutputText(1, 24, 21, "A %s", huitieme[selection_match].heure);
		}
		else if (langue == 3){
			PA_OutputText(1, 1, 21, "AM %s", huitieme[selection_match].date);
			PA_OutputText(1, 12, 21, "SPIEL %02d", selection_match + 48 + 1);
			PA_OutputText(1, 23, 21, "IN %s", huitieme[selection_match].heure);
		}
		else if (langue == 4){
			PA_OutputText(1, 1, 21, "SU %s", huitieme[selection_match].date);
			PA_OutputText(1, 13, 21, "MATCH %02d", selection_match + 48 + 1);
			PA_OutputText(1, 24, 21, "A %s", huitieme[selection_match].heure);
		}
		else if (langue == 5){
			PA_OutputText(1, 1, 21, "EL %s", huitieme[selection_match].date);
			PA_OutputText(1, 11, 21, "PARTIDO %02d", selection_match + 48 + 1);
			PA_OutputText(1, 23, 21, "EN %s", huitieme[selection_match].heure);
		}
		else{
			PA_OutputText(1, 1, 21, "ON %s", huitieme[selection_match].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection_match + 48 + 1);
			PA_OutputText(1, 23, 21, "IN %s", huitieme[selection_match].heure);
		}

		PA_OutputText(1, 1, 22, "%s", huitieme[selection_match].equipe1);
		PA_RightOutputText(1, 22, huitieme[selection_match].equipe2);

		PA_WaitForVBL();
	}
}

