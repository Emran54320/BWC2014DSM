void Determine_equipes_demi()
{
	//1er Qualif
	if (quarts[0].jouer == 1){
		if (quarts[0].score1 > quarts[0].score2) Quarts[0].premier = quarts[0].numero1;
		else if (quarts[0].score2 > quarts[0].score1) Quarts[0].premier = quarts[0].numero2;
		else if (quarts[0].score1 == quarts[0].score2)
		{
			if (quarts[0].penalty1 > quarts[0].penalty2) Quarts[0].premier = quarts[0].numero1;
			else if (quarts[0].penalty1 < quarts[0].penalty2) Quarts[0].premier = quarts[0].numero2;
		}
		demi[0].numero1 = Quarts[0].premier;
		demi[0].equipe1 = equipe[demi[0].numero1].nom;
		demi[0].abb1 = equipe[demi[0].numero1].abb;
	}
	else{
		demi[0].numero1 = 32;
		if (langue == 1) {demi[0].equipe1 = "Winner 57"; demi[0].abb1 = "W57";}
		else if (langue == 2) {demi[0].equipe1 = "Vainqueur 57"; demi[0].abb1 = "V57";}
		else if (langue == 3) {demi[0].equipe1 = "WINNER 57"; demi[0].abb1 = "W57";}
		else if (langue == 4) {demi[0].equipe1 = "Vincitore 57"; demi[0].abb1 = "V57";}
		else if (langue == 5) {demi[0].equipe1 ="Ganador 57"; demi[0].abb1 = "G57";}
		else {demi[0].equipe1 = "WINNER 57"; demi[0].abb1 = "W57";}
	}
	//2eme Qualif
	if (quarts[1].jouer == 1){
		if (quarts[1].score1 > quarts[1].score2) Quarts[1].premier = quarts[1].numero1;
		else if (quarts[1].score2 > quarts[1].score1) Quarts[1].premier = quarts[1].numero2;
		else if (quarts[1].score1 == quarts[1].score2)
		{
			if (quarts[1].penalty1 > quarts[1].penalty2) Quarts[1].premier = quarts[1].numero1;
			else if (quarts[1].penalty1 < quarts[1].penalty2) Quarts[1].premier = quarts[1].numero2;
		}
		demi[0].numero2 = Quarts[1].premier;
		demi[0].equipe2 = equipe[demi[0].numero2].nom;
		demi[0].abb2 = equipe[demi[0].numero2].abb;
	}
	else{
		demi[0].numero2 = 32;
		if (langue == 1) {demi[0].equipe2 = "WINNER 58"; demi[0].abb2 = "W58";}
		else if (langue == 2) {demi[0].equipe2 = "Vainqueur 58"; demi[0].abb2 = "V58";}
		else if (langue == 3) {demi[0].equipe2 = "WINNER 58"; demi[0].abb2 = "W58";}
		else if (langue == 4) {demi[0].equipe2 = "Vincitore 58"; demi[0].abb2 = "V58";}
		else if (langue == 5) {demi[0].equipe2 = "Ganador 58"; demi[0].abb2 = "G58";}
		else {demi[0].equipe2 = "WINNER 58"; demi[0].abb2 = "W58";}
	}
	//3eme Qualif
	if (quarts[2].jouer == 1){
		if (quarts[2].score1 > quarts[2].score2) Quarts[2].premier = quarts[2].numero1;
		else if (quarts[2].score2 > quarts[2].score1) Quarts[2].premier = quarts[2].numero2;
		else if (quarts[2].score1 == quarts[2].score2)
		{
			if (quarts[2].penalty1 > quarts[2].penalty2) Quarts[2].premier = quarts[2].numero1;
			else if (quarts[2].penalty1 < quarts[2].penalty2) Quarts[2].premier = quarts[2].numero2;
		}
		demi[1].numero1 = Quarts[2].premier;
		demi[1].equipe1 = equipe[demi[1].numero1].nom;
		demi[1].abb1 = equipe[demi[1].numero1].abb;
	}
	else{
		demi[1].numero1 = 32;
		if (langue == 1) {demi[1].equipe1 = "WINNER 59"; demi[1].abb1 = "W59";}
		else if (langue == 2) {demi[1].equipe1 = "Vainqueur 59"; demi[1].abb1 = "V59";}
		else if (langue == 3) {demi[1].equipe1 = "WINNER 59"; demi[1].abb1 = "W59";}
		else if (langue == 4) {demi[1].equipe1 = "Vincitore 59"; demi[1].abb1 = "V59";}
		else if (langue == 5) {demi[1].equipe1 ="Ganador 59"; demi[1].abb1 = "G59";}
		else {demi[1].equipe1 = "WINNER 59"; demi[1].abb1 = "W59";}
	}
	//4eme Qualif
	if (quarts[3].jouer == 1){
		if (quarts[3].score1 > quarts[3].score2) Quarts[3].premier = quarts[3].numero1;
		else if (quarts[3].score2 > quarts[3].score1) Quarts[3].premier = quarts[3].numero2;
		else if (quarts[3].score1 == quarts[3].score2)
		{
			if (quarts[3].penalty1 > quarts[3].penalty2) Quarts[3].premier = quarts[3].numero1;
			else if (quarts[3].penalty1 < quarts[3].penalty2) Quarts[3].premier = quarts[3].numero2;
		}
		demi[1].numero2 = Quarts[3].premier;
		demi[1].equipe2 = equipe[demi[1].numero2].nom;
		demi[1].abb2 = equipe[demi[1].numero2].abb;
	}
	else{
		demi[1].numero2 = 32;
		if (langue == 1) {demi[1].equipe2 = "WINNER 60"; demi[1].abb2 = "W60";}
		else if (langue == 2) {demi[1].equipe2 = "Vainqueur 60"; demi[1].abb2 = "V60";}
		else if (langue == 3) {demi[1].equipe2 = "WINNER 60"; demi[1].abb2 = "W60";}
		else if (langue == 4) {demi[1].equipe2 = "Vincitore 60"; demi[1].abb2 = "V60";}
		else if (langue == 5) {demi[1].equipe2 = "Ganador 60"; demi[1].abb2 = "G60";}
		else {demi[1].equipe2 = "WINNER 60"; demi[1].abb2 = "W60";}
	}
}

void InitMatchsDemi()
{
	Determine_equipes_demi();

	//LES SPRITES
	//HAUT

	//BAS
	PA_SetSpriteAnim(0, 40, demi[0].numero1 + 1);
	PA_SetSpriteAnim(0, 41, demi[0].numero2 + 1);
	PA_SetSpriteAnim(0, 42, demi[1].numero1 + 1);
	PA_SetSpriteAnim(0, 43, demi[1].numero2 + 1);

	PA_SetSpriteAnim(0, 62, (demi[0].score1+1) * demi[0].jouer);
	PA_SetSpriteAnim(0, 63, (demi[0].score2+1) * demi[0].jouer);
	PA_SetSpriteAnim(0, 64, (demi[1].score1+1) * demi[1].jouer);
	PA_SetSpriteAnim(0, 65, (demi[1].score2+1) * demi[1].jouer);

	PA_OutputText(0, 2, 11, "%s                      %s", demi[0].abb1, demi[0].abb2);
	PA_OutputText(0, 2, 14, "%s                      %s", demi[1].abb1, demi[1].abb2);

	if (demi[0].penalty1 != 0 || demi[0].penalty2 != 0) PA_OutputText(0, 11, 11, "%d        %d", demi[0].penalty1, demi[0].penalty2);
	if (demi[1].penalty1 != 0 || demi[1].penalty2 != 0) PA_OutputText(0, 11, 14, "%d        %d", demi[1].penalty1, demi[1].penalty2);

	PA_CenterOutputText(1, 17, demi[selection].ville);
	PA_CenterOutputText(1, 19, demi[selection].stade);
	
	if (langue == 1){
		PA_OutputText(1, 1, 21, "ON %s", demi[selection].date);
		PA_OutputText(1, 23, 21, "IN %s", demi[selection].heure);
	}
	else if (langue == 2){
		PA_OutputText(1, 1, 21, "LE %s", demi[selection].date);
		PA_OutputText(1, 24, 21, "A %s", demi[selection].heure);
	}
	else if (langue == 3){
		PA_OutputText(1, 1, 21, "AM %s", demi[selection].date);
		PA_OutputText(1, 23, 21, "IN %s", demi[selection].heure);
	}
	else if (langue == 4){
		PA_OutputText(1, 1, 21, "SU %s", demi[selection].date);
		PA_OutputText(1, 24, 21, "A %s", demi[selection].heure);
	}
	else if (langue == 5){
		PA_OutputText(1, 1, 21, "EL %s", demi[selection].date);
		PA_OutputText(1, 23, 21, "EN %s", demi[selection].heure);
	}
	else{
		PA_OutputText(1, 1, 21, "ON %s", demi[selection].date);
		PA_OutputText(1, 23, 21, "IN %s", demi[selection].heure);
	}

	PA_OutputText(1, 1, 22, "%s", demi[selection].equipe1);
	PA_RightOutputText(1, 22, demi[selection].equipe2);
}

void NavigationMatchsDemi()
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
		if (Pad.Newpress.Down && selection < 1)
		{
			selection++;
			PA_DeleteText(1);
			InitMatchsDemi();
			Pad.Newpress.Down = false;
		}
		else if (Pad.Newpress.Up && selection > 0)
		{
			selection--;
			PA_DeleteText(1);
			InitMatchsDemi();
			Pad.Newpress.Up = false;
		}
	
		if (Stylus.Newpress)
		{
			//SELECTION AU STYLET
			if (PA_StylusInZone(4, 32, 252, 166))
			{
				PA_DeleteText(1);

				if (PA_StylusInZone(4, 80, 252, 104)) selection = 0;
				else if (PA_StylusInZone(4, 104, 252, 128)) selection = 1;
			}

			//SCORE
			if (PA_StylusInZone(112, 8, 144, 24) && (demi[selection].numero1 != 32) && (demi[selection].numero2 != 32) && ((finales[0].jouer + finales[1].jouer) == 0))
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

				PA_SetSpriteAnim(0, FLAG1, demi[selection].numero1 + 1);
				PA_SetSpriteAnim(0, FLAG2, demi[selection].numero2 + 1);
				PA_SetSpriteAnim(0, SCORE1, demi[selection].score1 + 1);
				PA_SetSpriteAnim(0, SCORE2, demi[selection].score2 + 1);
				fadeout();
			}

			Stylus.Newpress = false;
		}

		PA_BGScrollY(0, 2, -48-selection*24);
	}
	else if (entrer_score == 1)
	{
		if (Stylus.Newpress)
		{
			if (PA_StylusInZone(70, 70, 86, 78))
			{
				mmEffect(SFX_SFXB);
				demi[selection].score1++;
				PA_SetSpriteAnim(0, SCORE1, demi[selection].score1 + 1);
			}
			else if (PA_StylusInZone(70, 86, 86, 104) && demi[selection].score1 > 0)
			{
				demi[selection].score1--;
				PA_SetSpriteAnim(0, SCORE1, demi[selection].score1 + 1);
			}

			if (PA_StylusInZone(166, 70, 182, 78))
			{
				mmEffect(SFX_SFXB);
				demi[selection].score2++;
				PA_SetSpriteAnim(0, SCORE2, demi[selection].score2 + 1);
			}
			else if (PA_StylusInZone(166, 86, 182, 104) && demi[selection].score2 > 0)
			{
			demi[selection].score2--;
				PA_SetSpriteAnim(0, SCORE2, demi[selection].score2 + 1);
			}

			//VALIDER
			if (PA_StylusInZone(8, 152, 40, 168))
			{
				if (demi[selection].score1 > demi[selection].score2)
				{
					Demi[selection].premier = demi[selection].numero1;
					Demi[selection].deuxieme = demi[selection].numero2;
				}
				else if (demi[selection].score2 > demi[selection].score1)
				{
					Demi[selection].premier = demi[selection].numero2;
					Demi[selection].deuxieme = demi[selection].numero1;
				}
				else
				{
					mmEffect(SFX_SFXA);
					penalty = 1;
					fadein();
					PA_LoadGif(0, (void*)BG3_bas_penalty);
					PA_SetSpriteAnim(0, BOUTON_RESET, 0);
					PA_SetSpriteAnim(0, PENALTY1, demi[selection].penalty1 + 1);
					PA_SetSpriteAnim(0, PENALTY2, demi[selection].penalty2 + 1);
					fadeout();
					Stylus.Newpress = false;

					while(penalty == 1)
					{
						if (Stylus.Newpress)
						{
							if (PA_StylusInZone(70, 116, 88, 124))
							{
								mmEffect(SFX_SFXB);
								demi[selection].penalty1++;
								PA_SetSpriteAnim(0, PENALTY1, demi[selection].penalty1 + 1);
							}
							else if (PA_StylusInZone(70, 132, 88, 140) && demi[selection].penalty1 > 0)
							{
								demi[selection].penalty1--;
								PA_SetSpriteAnim(0, PENALTY1, demi[selection].penalty1 + 1);
							}

							if (PA_StylusInZone(166, 116, 182, 124))
							{
								mmEffect(SFX_SFXB);
								demi[selection].penalty2++;
								PA_SetSpriteAnim(0, PENALTY2, demi[selection].penalty2 + 1);
							}
							else if (PA_StylusInZone(166, 132, 182, 140) && demi[selection].penalty2 > 0)
							{
								demi[selection].penalty2--;
								PA_SetSpriteAnim(0, PENALTY2, demi[selection].penalty2 + 1);
							}

							//VALIDER
							if (PA_StylusInZone(8, 152, 40, 168))
							{
								if (demi[selection].penalty1 > demi[selection].penalty2)
								{
									Demi[selection].premier = demi[selection].numero1;
									Demi[selection].deuxieme = demi[selection].numero2;
									penalty = 0;
								}
								else if (demi[selection].penalty2 > demi[selection].penalty1)
								{
									Demi[selection].premier = demi[selection].numero2;
									Demi[selection].deuxieme = demi[selection].numero1;
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
				demi[selection].jouer = 1;

				entrer_score = 0;
				InitMatchsDemi();
				sauver_sauvegarde();
				PA_LoadGif(0, (void*)BG3_bas_deux);
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
				demi[selection].jouer = 0;
				demi[selection].score1 = 0;
				demi[selection].score2 = 0;
				demi[selection].penalty1 = 0;
				demi[selection].penalty2 = 0;
				Demi[selection].premier = 32;
				Demi[selection].deuxieme = 32;
				entrer_score = 0;
				InitMatchsDemi();
				sauver_sauvegarde();
				PA_LoadGif(0, (void*)BG3_bas_deux);
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

void NavigationDemi()
{
	startmenu = 9;

	while (startmenu == 9)
	{
		NavigationMatchsDemi();

		PA_CenterOutputText(1, 17, demi[selection].ville);
		PA_CenterOutputText(1, 19, demi[selection].stade);
		
		if (langue == 1){
			PA_OutputText(1, 1, 21, "ON %s", demi[selection].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection + 60 + 1);
			PA_OutputText(1, 23, 21, "IN %s", demi[selection].heure);
		}
		else if (langue == 2){
			PA_OutputText(1, 1, 21, "LE %s", demi[selection].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection + 60 + 1);
			PA_OutputText(1, 24, 21, "A %s", demi[selection].heure);
		}
		else if (langue == 3){
			PA_OutputText(1, 1, 21, "AM %s", demi[selection].date);
			PA_OutputText(1, 12, 21, "SPIEL %02d", selection + 60 + 1);
			PA_OutputText(1, 23, 21, "IN %s", demi[selection].heure);
		}
		else if (langue == 4){
			PA_OutputText(1, 1, 21, "SU %s", demi[selection].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection + 60 + 1);
			PA_OutputText(1, 24, 21, "A %s", demi[selection].heure);
		}
		else if (langue == 5){
			PA_OutputText(1, 1, 21, "EL %s", demi[selection].date);
			PA_OutputText(1, 11, 21, "PARTIDO %02d", selection + 60 + 1);
			PA_OutputText(1, 23, 21, "EN %s", demi[selection].heure);
		}
		else{
			PA_OutputText(1, 1, 21, "ON %s", demi[selection].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection + 60 + 1);
			PA_OutputText(1, 23, 21, "IN %s", demi[selection].heure);
		}

		PA_OutputText(1, 1, 22, "%s", demi[selection].equipe1);
		PA_RightOutputText(1, 22, demi[selection].equipe2);

		PA_WaitForVBL();
	}
}


