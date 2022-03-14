void Determine_equipes_quarts()
{
	//1er QUART
	if (huitieme[0].jouer == 1){
		if (huitieme[0].score1 > huitieme[0].score2) Huitiemes[0].premier = huitieme[0].numero1;
		else if (huitieme[0].score2 > huitieme[0].score1) Huitiemes[0].premier = huitieme[0].numero2;
		else if (huitieme[0].score1 == huitieme[0].score2)
		{
			if (huitieme[0].penalty1 > huitieme[0].penalty2) Huitiemes[0].premier = huitieme[0].numero1;
			else if (huitieme[0].penalty1 < huitieme[0].penalty2) Huitiemes[0].premier = huitieme[0].numero2;
		}
		quarts[0].numero1 = Huitiemes[0].premier;
		quarts[0].equipe1 = equipe[quarts[0].numero1].nom;
		quarts[0].abb1 = equipe[quarts[0].numero1].abb;
	}
	else{
		quarts[0].numero1 = 32;
		if (langue == 1) {quarts[0].equipe1 = "WINNER 49"; quarts[0].abb1 = "W49";}
		else if (langue == 2) {quarts[0].equipe1 = "Vainqueur 49"; quarts[0].abb1 = "V49";}
		else if (langue == 3) {quarts[0].equipe1 = "WINNER 49"; quarts[0].abb1 = "W49";}
		else if (langue == 4) {quarts[0].equipe1 = "Vincitore 49"; quarts[0].abb1 = "V49";}
		else if (langue == 5) {quarts[0].equipe1 = "Ganador 49"; quarts[0].abb1 = "G49";}
		else {quarts[0].equipe1 = "WINNER 49"; quarts[0].abb1 = "W49";}
	}

	if (huitieme[1].jouer == 1){
		if (huitieme[1].score1 > huitieme[1].score2) Huitiemes[1].premier = huitieme[1].numero1;
		else if (huitieme[1].score2 > huitieme[1].score1) Huitiemes[1].premier = huitieme[1].numero2;
		else if (huitieme[1].score1 == huitieme[1].score2)
		{
			if (huitieme[1].penalty1 > huitieme[1].penalty2) Huitiemes[1].premier = huitieme[1].numero1;
			else if (huitieme[1].penalty1 < huitieme[1].penalty2) Huitiemes[1].premier = huitieme[1].numero2;
		}
		quarts[0].numero2 = Huitiemes[1].premier;
		quarts[0].equipe2 = equipe[quarts[0].numero2].nom;
		quarts[0].abb2 = equipe[quarts[0].numero2].abb;
	}
	else{
		quarts[0].numero2 = 32;
		if (langue == 1) {quarts[0].equipe2 = "WINNER 50"; quarts[0].abb2 = "W50";}
		else if (langue == 2) {quarts[0].equipe2 = "Vainqueur 50"; quarts[0].abb2 = "V50";}
		else if (langue == 3) {quarts[0].equipe2 = "WINNER 50"; quarts[0].abb2 = "W50";}
		else if (langue == 4) {quarts[0].equipe2 = "Vincitore 50"; quarts[0].abb2 = "V50";}
		else if (langue == 5) {quarts[0].equipe2 = "Ganador 50"; quarts[0].abb2 = "G50";}
		else {quarts[0].equipe2 = "WINNER 50"; quarts[0].abb2 = "W50";}
	}

	//2em QUART
	if (huitieme[4].jouer == 1)
	{
		if (huitieme[4].score1 > huitieme[4].score2) Huitiemes[4].premier = huitieme[4].numero1;
		else if (huitieme[4].score2 > huitieme[4].score1) Huitiemes[4].premier = huitieme[4].numero2;
		else if (huitieme[4].score1 == huitieme[4].score2)
		{
			if (huitieme[4].penalty1 > huitieme[4].penalty2) Huitiemes[4].premier = huitieme[4].numero1;
			else if (huitieme[4].penalty1 < huitieme[4].penalty2) Huitiemes[4].premier = huitieme[4].numero2;
		}
		quarts[1].numero1 = Huitiemes[4].premier;
		quarts[1].equipe1 = equipe[quarts[1].numero1].nom;
		quarts[1].abb1 = equipe[quarts[1].numero1].abb;
	}
	else
	{
		quarts[1].numero1 = 32;
		if (langue == 1) {quarts[1].equipe1 = "WINNER 53"; quarts[1].abb1 = "W53";}
		else if (langue == 2) {quarts[1].equipe1 = "Vainqueur 53"; quarts[1].abb1 = "V53";}
		else if (langue == 3) {quarts[1].equipe1 = "WINNER 53"; quarts[1].abb1 = "W53";}
		else if (langue == 4) {quarts[1].equipe1 = "Vincitore 53"; quarts[1].abb1 = "V53";}
		else if (langue == 5) {quarts[1].equipe1 = "Ganador 53"; quarts[1].abb1 = "G53";}
		else {quarts[1].equipe1 = "WINNER 53"; quarts[1].abb1 = "W53";}
	}
	if (huitieme[5].jouer == 1)
	{
		if (huitieme[5].score1 > huitieme[5].score2) Huitiemes[5].premier = huitieme[5].numero1;
		else if (huitieme[5].score2 > huitieme[5].score1) Huitiemes[5].premier = huitieme[5].numero2;
		else if (huitieme[5].score1 == huitieme[5].score2)
		{
			if (huitieme[5].penalty1 > huitieme[5].penalty2) Huitiemes[5].premier = huitieme[5].numero1;
			else if (huitieme[5].penalty1 < huitieme[5].penalty2) Huitiemes[5].premier = huitieme[5].numero2;
		}
		quarts[1].numero2 = Huitiemes[5].premier;
		quarts[1].equipe2 = equipe[quarts[1].numero2].nom;
		quarts[1].abb2 = equipe[quarts[1].numero2].abb;
	}
	else
	{
		quarts[1].numero2 = 32;
		if (langue == 1) {quarts[1].equipe2 = "WINNER 54"; quarts[1].abb2 = "W54";}
		else if (langue == 2) {quarts[1].equipe2 = "Vainqueur 54"; quarts[1].abb2 = "V54";}
		else if (langue == 3) {quarts[1].equipe2 = "WINNER 54"; quarts[1].abb2 = "W54";}
		else if (langue == 4) {quarts[1].equipe2 = "Vincitore 54"; quarts[1].abb2 = "V54";}
		else if (langue == 5) {quarts[1].equipe2 = "Ganador 54"; quarts[1].abb2 = "G54";}
		else {quarts[1].equipe2 = "WINNER 54"; quarts[1].abb2 = "W54";}
	}

	//3eme QUART
	if (huitieme[2].jouer == 1)
	{
		if (huitieme[2].score1 > huitieme[2].score2) Huitiemes[2].premier = huitieme[2].numero1;
		else if (huitieme[2].score2 > huitieme[2].score1) Huitiemes[2].premier = huitieme[2].numero2;
		else if (huitieme[2].score1 == huitieme[2].score2)
		{
			if (huitieme[2].penalty1 > huitieme[2].penalty2) Huitiemes[2].premier = huitieme[2].numero1;
			else if (huitieme[2].penalty1 < huitieme[2].penalty2) Huitiemes[2].premier = huitieme[2].numero2;
		}
		quarts[2].numero1 = Huitiemes[2].premier;
		quarts[2].equipe1 = equipe[quarts[2].numero1].nom;
		quarts[2].abb1 = equipe[quarts[2].numero1].abb;
	}
	else
	{
		quarts[2].numero1 = 32;
		if (langue == 1) {quarts[2].equipe1 = "WINNER 51"; quarts[2].abb1 = "W51";}
		else if (langue == 2) {quarts[2].equipe1 = "Vainqueur 51"; quarts[2].abb1 = "V51";}
		else if (langue == 3) {quarts[2].equipe1 = "WINNER 51"; quarts[2].abb1 = "W51";}
		else if (langue == 4) {quarts[2].equipe1 = "Vincitore 51"; quarts[2].abb1 = "V51";}
		else if (langue == 5) {quarts[2].equipe1 = "Ganador 51"; quarts[2].abb1 = "G51";}
		else {quarts[2].equipe1 = "WINNER 51"; quarts[2].abb1 = "W51";}
	}
	if (huitieme[3].jouer == 1)
	{
		if (huitieme[3].score1 > huitieme[3].score2) Huitiemes[3].premier = huitieme[3].numero1;
		else if (huitieme[3].score2 > huitieme[3].score1) Huitiemes[3].premier = huitieme[3].numero2;
		else if (huitieme[3].score1 == huitieme[3].score2)
		{
			if (huitieme[3].penalty1 > huitieme[3].penalty2) Huitiemes[3].premier = huitieme[3].numero1;
			else if (huitieme[3].penalty1 < huitieme[3].penalty2) Huitiemes[3].premier = huitieme[3].numero2;
		}
		quarts[2].numero2 = Huitiemes[3].premier;
		quarts[2].equipe2 = equipe[quarts[2].numero2].nom;
		quarts[2].abb2 = equipe[quarts[2].numero2].abb;
	}
	else
	{
		quarts[2].numero2 = 32;
		if (langue == 1) {quarts[2].equipe2 = "WINNER 52"; quarts[2].abb2 = "W52";}
		else if (langue == 2) {quarts[2].equipe2 = "Vainqueur 52"; quarts[2].abb2 = "V52";}
		else if (langue == 3) {quarts[2].equipe2 = "WINNER 52"; quarts[2].abb2 = "W52";}
		else if (langue == 4) {quarts[2].equipe2 = "Vincitore 52"; quarts[2].abb2 = "V52";}
		else if (langue == 5) {quarts[2].equipe2 = "Ganador 52"; quarts[2].abb2 = "G52";}
		else {quarts[2].equipe2 = "WINNER 52"; quarts[2].abb2 = "W52";}
	}

	//4em QUART
	if (huitieme[6].jouer == 1)
	{
		if (huitieme[6].score1 > huitieme[6].score2) Huitiemes[6].premier = huitieme[6].numero1;
		else if (huitieme[6].score2 > huitieme[6].score1) Huitiemes[6].premier = huitieme[6].numero2;
		else if (huitieme[6].score1 == huitieme[6].score2)
		{
			if (huitieme[6].penalty1 > huitieme[6].penalty2) Huitiemes[6].premier = huitieme[6].numero1;
			else if (huitieme[6].penalty1 < huitieme[6].penalty2) Huitiemes[6].premier = huitieme[6].numero2;
		}
		quarts[3].numero1 = Huitiemes[6].premier;
		quarts[3].equipe1 = equipe[quarts[3].numero1].nom;
		quarts[3].abb1 = equipe[quarts[3].numero1].abb;
	}
	else
	{
		quarts[3].numero1 = 32;
		if (langue == 1) {quarts[3].equipe1 = "WINNER 55"; quarts[3].abb1 = "W55";}
		else if (langue == 2) {quarts[3].equipe1 = "Vainqueur 55"; quarts[3].abb1 = "V55";}
		else if (langue == 3) {quarts[3].equipe1 = "WINNER 55"; quarts[3].abb1 = "W55";}
		else if (langue == 4) {quarts[3].equipe1 = "Vincitore 55"; quarts[3].abb1 = "V55";}
		else if (langue == 5) {quarts[3].equipe1 = "Ganador 55"; quarts[3].abb1 = "G55";}
		else {quarts[3].equipe1 = "WINNER 55"; quarts[3].abb1 = "W55";}
	}
	if (huitieme[7].jouer == 1)
	{
		if (huitieme[7].score1 > huitieme[7].score2) Huitiemes[7].premier = huitieme[7].numero1;
		else if (huitieme[7].score2 > huitieme[7].score1) Huitiemes[7].premier = huitieme[7].numero2;
		else if (huitieme[7].score1 == huitieme[7].score2)
		{
			if (huitieme[7].penalty1 > huitieme[7].penalty2) Huitiemes[7].premier = huitieme[7].numero1;
			else if (huitieme[7].penalty1 < huitieme[7].penalty2) Huitiemes[7].premier = huitieme[7].numero2;
		}
		quarts[3].numero2 = Huitiemes[7].premier;
		quarts[3].equipe2 = equipe[quarts[3].numero2].nom;
		quarts[3].abb2 = equipe[quarts[3].numero2].abb;
	}
	else
	{
		quarts[3].numero2 = 32;
		if (langue == 1) {quarts[3].equipe2 = "WINNER 56"; quarts[3].abb2 = "W56";}
		else if (langue == 2) {quarts[3].equipe2 = "Vainqueur 56"; quarts[3].abb2 = "V56";}
		else if (langue == 3) {quarts[3].equipe2 = "WINNER 56"; quarts[3].abb2 = "W56";}
		else if (langue == 4) {quarts[3].equipe2 = "Vincitore 56"; quarts[3].abb2 = "V56";}
		else if (langue == 5) {quarts[3].equipe2 = "Ganador 56"; quarts[3].abb2 = "G56";}
		else {quarts[3].equipe2 = "WINNER 56"; quarts[3].abb2 = "W56";}
	}
}

void InitMatchsQuarts()
{
	Determine_equipes_quarts();

	//LES SPRITES
	//HAUT

	//BAS
	PA_SetSpriteAnim(0, 38, quarts[0].numero1 + 1);
	PA_SetSpriteAnim(0, 39, quarts[0].numero2 + 1);
	PA_SetSpriteAnim(0, 40, quarts[1].numero1 + 1);
	PA_SetSpriteAnim(0, 41, quarts[1].numero2 + 1);
	PA_SetSpriteAnim(0, 42, quarts[2].numero1 + 1);
	PA_SetSpriteAnim(0, 43, quarts[2].numero2 + 1);
	PA_SetSpriteAnim(0, 44, quarts[3].numero1 + 1);
	PA_SetSpriteAnim(0, 45, quarts[3].numero2 + 1);

	PA_SetSpriteAnim(0, 60, (quarts[0].score1+1) * quarts[0].jouer);
	PA_SetSpriteAnim(0, 61, (quarts[0].score2+1) * quarts[0].jouer);
	PA_SetSpriteAnim(0, 62, (quarts[1].score1+1) * quarts[1].jouer);
	PA_SetSpriteAnim(0, 63, (quarts[1].score2+1) * quarts[1].jouer);
	PA_SetSpriteAnim(0, 64, (quarts[2].score1+1) * quarts[2].jouer);
	PA_SetSpriteAnim(0, 65, (quarts[2].score2+1) * quarts[2].jouer);
	PA_SetSpriteAnim(0, 66, (quarts[3].score1+1) * quarts[3].jouer);
	PA_SetSpriteAnim(0, 67, (quarts[3].score2+1) * quarts[3].jouer);

	PA_OutputText(0, 2, 8, "%s                      %s", quarts[0].abb1, quarts[0].abb2);
	PA_OutputText(0, 2, 11, "%s                      %s", quarts[1].abb1, quarts[1].abb2);
	PA_OutputText(0, 2, 14, "%s                      %s", quarts[2].abb1, quarts[2].abb2);
	PA_OutputText(0, 2, 17, "%s                      %s", quarts[3].abb1, quarts[3].abb2);

	if (quarts[0].penalty1 != 0 || quarts[0].penalty2 != 0) PA_OutputText(0, 11, 8, "%d        %d", quarts[0].penalty1, quarts[0].penalty2);
	if (quarts[1].penalty1 != 0 || quarts[1].penalty2 != 0) PA_OutputText(0, 11, 11, "%d        %d", quarts[1].penalty1, quarts[1].penalty2);
	if (quarts[2].penalty1 != 0 || quarts[2].penalty2 != 0) PA_OutputText(0, 11, 14, "%d        %d", quarts[2].penalty1, quarts[2].penalty2);
	if (quarts[3].penalty1 != 0 || quarts[3].penalty2 != 0) PA_OutputText(0, 11, 17, "%d        %d", quarts[3].penalty1, quarts[3].penalty2);

	PA_CenterOutputText(1, 17, quarts[selection].ville);
	PA_CenterOutputText(1, 19, quarts[selection].stade);

	if (langue == 1){
		PA_OutputText(1, 1, 21, "ON %s", quarts[selection].date);
		PA_OutputText(1, 23, 21, "IN %s", quarts[selection].heure);
	}
	else if (langue == 2){
		PA_OutputText(1, 1, 21, "LE %s", quarts[selection].date);
		PA_OutputText(1, 24, 21, "A %s", quarts[selection].heure);
	}
	else if (langue == 3){
		PA_OutputText(1, 1, 21, "AM %s", quarts[selection].date);
		PA_OutputText(1, 23, 21, "IN %s", quarts[selection].heure);
	}
	else if (langue == 4){
		PA_OutputText(1, 1, 21, "SU %s", quarts[selection].date);
		PA_OutputText(1, 24, 21, "A %s", quarts[selection].heure);
	}
	else if (langue == 5){
		PA_OutputText(1, 1, 21, "EL %s", quarts[selection].date);
		PA_OutputText(1, 23, 21, "EN %s", quarts[selection].heure);
	}
	else{
		PA_OutputText(1, 1, 21, "ON %s", quarts[selection].date);
		PA_OutputText(1, 23, 21, "IN %s", quarts[selection].heure);
	}

	PA_OutputText(1, 1, 22, "%s", quarts[selection].equipe1);
	PA_RightOutputText(1, 22, quarts[selection].equipe2);
}

void NavigationMatchsQuarts()
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
		}
		if (Pad.Newpress.Down && selection < 3)
		{
			selection++;
			PA_DeleteText(1);
			InitMatchsQuarts();
			Pad.Newpress.Down = false;
		}
		else if (Pad.Newpress.Up && selection > 0)
		{
			selection--;
			PA_DeleteText(1);
			InitMatchsQuarts();
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
			}

			//SCORE
			if (PA_StylusInZone(112, 8, 144, 24) && (quarts[selection].numero1 != 32) && ((quarts[selection].numero2 != 32) && (demi[0].jouer + demi[1].jouer) == 0))
			{
				mmEffect(SFX_SFXA);
				entrer_score = 1;
				fadein();
				PA_DeleteText(0);
				PA_LoadGif(0, (void*)BG3_bas_score);
				PA_HideBg(0, 2);
				for (i = 0; i < 51; i++) PA_SetSpriteAnim(0, i, 0);
				for (i = 58; i < 70; i++) PA_SetSpriteAnim(0, i, 0);
				PA_SetSpriteAnim(0, BOUTON_VALIDER, 7);
				PA_SetSpriteAnim(0, BOUTON_RESET, 11);
				PA_SetSpriteAnim(0, QUITTER, 0);

				PA_SetSpriteAnim(0, FLAG1, quarts[selection].numero1 + 1);
				PA_SetSpriteAnim(0, FLAG2, quarts[selection].numero2 + 1);
				PA_SetSpriteAnim(0, SCORE1, quarts[selection].score1 + 1);
				PA_SetSpriteAnim(0, SCORE2, quarts[selection].score2 + 1);
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
				quarts[selection].score1++;
				PA_SetSpriteAnim(0, SCORE1, quarts[selection].score1 + 1);
			}
			else if (PA_StylusInZone(70, 86, 86, 104) && quarts[selection].score1 > 0)
			{
				quarts[selection].score1--;
				PA_SetSpriteAnim(0, SCORE1, quarts[selection].score1 + 1);
			}

			if (PA_StylusInZone(166, 70, 182, 78))
			{
				mmEffect(SFX_SFXB);
				quarts[selection].score2++;
				PA_SetSpriteAnim(0, SCORE2, quarts[selection].score2 + 1);
			}
			else if (PA_StylusInZone(166, 86, 182, 104) && quarts[selection].score2 > 0)
			{
				quarts[selection].score2--;
				PA_SetSpriteAnim(0, SCORE2, quarts[selection].score2 + 1);
			}

			//VALIDER
			if (PA_StylusInZone(8, 152, 40, 168))
			{
				if (quarts[selection].score1 > quarts[selection].score2)
				{
					Quarts[selection].premier = quarts[selection].numero1;
				}
				else if (quarts[selection].score2 > quarts[selection].score1)
				{
					Quarts[selection].premier = quarts[selection].numero2;
				}
				else
				{
					mmEffect(SFX_SFXA);
					fadein();
					penalty = 1;
					PA_LoadGif(0, (void*)BG3_bas_penalty);
					PA_SetSpriteAnim(0, BOUTON_RESET, 0);
					PA_SetSpriteAnim(0, PENALTY1, quarts[selection].penalty1 + 1);
					PA_SetSpriteAnim(0, PENALTY2, quarts[selection].penalty2 + 1);
					fadeout();
					Stylus.Newpress = false;

					while(penalty == 1)
					{
						if (Stylus.Newpress)
						{
							if (PA_StylusInZone(70, 116, 88, 124))
							{
								mmEffect(SFX_SFXB);
								quarts[selection].penalty1++;
								PA_SetSpriteAnim(0, PENALTY1, quarts[selection].penalty1 + 1);
							}
							else if (PA_StylusInZone(70, 132, 88, 140) && quarts[selection].penalty1 > 0)
							{
								quarts[selection].penalty1--;
								PA_SetSpriteAnim(0, PENALTY1, quarts[selection].penalty1 + 1);
							}

							if (PA_StylusInZone(166, 116, 182, 124))
							{
								mmEffect(SFX_SFXB);
								quarts[selection].penalty2++;
								PA_SetSpriteAnim(0, PENALTY2, quarts[selection].penalty2 + 1);
							}
							else if (PA_StylusInZone(166, 132, 182, 140) && quarts[selection].penalty2 > 0)
							{
								quarts[selection].penalty2--;
								PA_SetSpriteAnim(0, PENALTY2, quarts[selection].penalty2 + 1);
							}

							//VALIDER
							if (PA_StylusInZone(8, 152, 40, 168))
							{
								if (quarts[selection].penalty1 > quarts[selection].penalty2)
								{
									Quarts[selection].premier = quarts[selection].numero1;
									penalty = 0;
								}
								else if (quarts[selection].penalty2 > quarts[selection].penalty1)
								{
									Quarts[selection].premier = quarts[selection].numero2;
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
				quarts[selection].jouer = 1;
 
				//***************
				entrer_score = 0;
				InitMatchsQuarts();
				sauver_sauvegarde();
				PA_LoadGif(0, (void*)BG3_bas_quatres);
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
				quarts[selection].jouer = 0;
				quarts[selection].score1 = 0;
				quarts[selection].score2 = 0;
				quarts[selection].penalty1 = 0;
				quarts[selection].penalty2 = 0;
				Quarts[selection].premier = 32;

				entrer_score = 0;
				InitMatchsQuarts();
				sauver_sauvegarde();
				PA_LoadGif(0, (void*)BG3_bas_quatres);

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

void NavigationQuarts()
{
	startmenu = 7;

	while (startmenu == 7)
	{
		NavigationMatchsQuarts();

		PA_CenterOutputText(1, 17, quarts[selection].ville);
		PA_CenterOutputText(1, 19, quarts[selection].stade);
		
		if (langue == 1){
			PA_OutputText(1, 1, 21, "ON %s", quarts[selection].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection + 56 + 1);
			PA_OutputText(1, 23, 21, "IN %s", quarts[selection].heure);
		}
		else if (langue == 2){
			PA_OutputText(1, 1, 21, "LE %s", quarts[selection].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection + 56 + 1);
			PA_OutputText(1, 24, 21, "A %s", quarts[selection].heure);
		}
		else if (langue == 3){
			PA_OutputText(1, 1, 21, "AM %s", quarts[selection].date);
			PA_OutputText(1, 12, 21, "SPIEL %02d", selection + 56 + 1);
			PA_OutputText(1, 23, 21, "IN %s", quarts[selection].heure);
		}
		else if (langue == 4){
			PA_OutputText(1, 1, 21, "SU %s", quarts[selection].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection + 56 + 1);
			PA_OutputText(1, 24, 21, "A %s", quarts[selection].heure);
		}
		else if (langue == 5){
			PA_OutputText(1, 1, 21, "EL %s", quarts[selection].date);
			PA_OutputText(1, 11, 21, "PARTIDO %02d", selection + 56 + 1);
			PA_OutputText(1, 23, 21, "EN %s", quarts[selection].heure);
		}
		else{
			PA_OutputText(1, 1, 21, "ON %s", quarts[selection].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection + 56 + 1);
			PA_OutputText(1, 23, 21, "IN %s", quarts[selection].heure);
		}

		PA_OutputText(1, 1, 22, "%s", quarts[selection].equipe1);
		PA_RightOutputText(1, 22, quarts[selection].equipe2);

		PA_WaitForVBL();
	}
}

