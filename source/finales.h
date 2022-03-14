void Determine_equipes_finale()
{
	//1er Qualif
	if (demi[0].jouer == 1){
		if (demi[0].score1 > demi[0].score2) {Demi[0].premier = demi[0].numero1;Demi[0].deuxieme = demi[0].numero2;}
		else if (demi[0].score2 > demi[0].score1) {Demi[0].premier = demi[0].numero2;Demi[0].deuxieme = demi[0].numero1;}
		else if (demi[0].score1 == demi[0].score2)
		{
			if (demi[0].penalty1 > demi[0].penalty2) {Demi[0].premier = demi[0].numero1;Demi[0].deuxieme = demi[0].numero2;}
			else if (demi[0].penalty1 < demi[0].penalty2) {Demi[0].premier = demi[0].numero2;Demi[0].deuxieme = demi[0].numero1;}
		}
		finales[1].numero1 = Demi[0].premier;
		finales[1].equipe1 = equipe[finales[1].numero1].nom;
		finales[1].abb1 = equipe[finales[1].numero1].abb;

		finales[0].numero1 = Demi[0].deuxieme;
		finales[0].equipe1 = equipe[finales[0].numero1].nom;
		finales[0].abb1 = equipe[finales[0].numero1].abb;
	}
	else{
		finales[1].numero1 = 32;
		if (langue == 1) {finales[1].equipe1 = "Winner 61"; finales[1].abb1 = "W61";}
		else if (langue == 2) {finales[1].equipe1 = "Vainqueur 61"; finales[1].abb1 = "V61";}
		else if (langue == 3) {finales[1].equipe1 = "WINNER 61"; finales[1].abb1 = "W61";}
		else if (langue == 4) {finales[1].equipe1 = "Vincitore 61"; finales[1].abb1 = "V61";}
		else if (langue == 5) {finales[1].equipe1 ="Ganador 61"; finales[1].abb1 = "G61";}
		else {finales[1].equipe1 = "WINNER 61"; finales[1].abb1 = "W61";}

		finales[0].numero1 = 32;
		if (langue == 1) {finales[0].equipe1 = "LOSER 61"; finales[0].abb1 = "L61";}
		else if (langue == 2) {finales[0].equipe1 = "PERDANT 61"; finales[0].abb1 = "P61";}
		else if (langue == 3) {finales[0].equipe1 = "LOSER 61"; finales[0].abb1 = "L61";}
		else if (langue == 4) {finales[0].equipe1 = "LOSER 61"; finales[0].abb1 = "L61";}
		else if (langue == 5) {finales[0].equipe1 ="PERDEDOR 61"; finales[0].abb1 = "P61";}
		else {finales[0].equipe1 = "LOSER 61"; finales[0].abb1 = "L61";}
	}
	//2eme Qualif
	if (demi[1].jouer == 1){
		if (demi[1].score1 > demi[1].score2) {Demi[1].premier = demi[1].numero1;Demi[1].deuxieme = demi[1].numero2;}
		else if (demi[1].score2 > demi[1].score1) {Demi[1].premier = demi[1].numero2;Demi[1].deuxieme = demi[1].numero1;}
		else if (demi[1].score1 == demi[1].score2)
		{
			if (demi[1].penalty1 > demi[1].penalty2) {Demi[1].premier = demi[1].numero1;Demi[1].deuxieme = demi[1].numero2;}
			else if (demi[1].penalty1 < demi[1].penalty2) {Demi[1].premier = demi[1].numero2;Demi[1].deuxieme = demi[1].numero1;}
		}
		finales[1].numero2 = Demi[1].premier;
		finales[1].equipe2 = equipe[finales[1].numero2].nom;
		finales[1].abb2 = equipe[finales[1].numero2].abb;

		finales[0].numero2 = Demi[1].deuxieme;
		finales[0].equipe2 = equipe[finales[0].numero2].nom;
		finales[0].abb2 = equipe[finales[0].numero2].abb;
	}
	else{
		finales[1].numero2 = 32;
		if (langue == 1) {finales[1].equipe2 = "WINNER 62"; finales[1].abb2 = "W62";}
		else if (langue == 2) {finales[1].equipe2 = "Vainqueur 62"; finales[1].abb2 = "V62";}
		else if (langue == 3) {finales[1].equipe2 = "WINNER 62"; finales[1].abb2 = "W62";}
		else if (langue == 4) {finales[1].equipe2 = "Vincitore 62"; finales[1].abb2 = "V62";}
		else if (langue == 5) {finales[1].equipe2 = "Ganador 62"; finales[1].abb2 = "G62";}
		else {finales[1].equipe2 = "WINNER 62"; finales[1].abb2 = "W62";}

		finales[0].numero2 = 32;
		if (langue == 1) {finales[0].equipe2 = "LOSER 62"; finales[0].abb2 = "L62";}
		else if (langue == 2) {finales[0].equipe2 = "PERDANT 62"; finales[0].abb2 = "P62";}
		else if (langue == 3) {finales[0].equipe2 = "LOSER 62"; finales[0].abb2 = "L62";}
		else if (langue == 4) {finales[0].equipe2 = "LOSER 62"; finales[0].abb2 = "L62";}
		else if (langue == 5) {finales[0].equipe2 = "PERDEDOR 62"; finales[0].abb2 = "P62";}
		else {finales[0].equipe2 = "LOSER 62"; finales[0].abb2 = "L62";}
	}
}

void InitMatchsFinales()
{
	Determine_equipes_finale();

	//LES SPRITES
	//HAUT

	//BAS
	PA_SetSpriteAnim(0, 40, finales[0].numero1 + 1);
	PA_SetSpriteAnim(0, 41, finales[0].numero2 + 1);
	PA_SetSpriteAnim(0, 42, finales[1].numero1 + 1);
	PA_SetSpriteAnim(0, 43, finales[1].numero2 + 1);

	PA_SetSpriteAnim(0, 62, (finales[0].score1+1) * finales[0].jouer);
	PA_SetSpriteAnim(0, 63, (finales[0].score2+1) * finales[0].jouer);
	PA_SetSpriteAnim(0, 64, (finales[1].score1+1) * finales[1].jouer);
	PA_SetSpriteAnim(0, 65, (finales[1].score2+1) * finales[1].jouer);

	PA_OutputText(0, 2, 11, "%s                      %s", finales[0].abb1, finales[0].abb2);
	PA_OutputText(0, 2, 14, "%s                      %s", finales[1].abb1, finales[1].abb2);
	
	if (finales[0].penalty1 != 0 || finales[0].penalty2 != 0) PA_OutputText(0, 11, 11, "%d        %d", finales[0].penalty1, finales[0].penalty2);
	if (finales[1].penalty1 != 0 || finales[1].penalty2 != 0) PA_OutputText(0, 11, 14, "%d        %d", finales[1].penalty1, finales[1].penalty2);

	PA_CenterOutputText(1, 17, finales[selection].ville);
	PA_CenterOutputText(1, 19, finales[selection].stade);
	
	if (langue == 1){
		PA_OutputText(1, 1, 21, "ON %s", finales[selection].date);
		PA_OutputText(1, 23, 21, "IN %s", finales[selection].heure);
	}
	else if (langue == 2){
		PA_OutputText(1, 1, 21, "LE %s", finales[selection].date);
		PA_OutputText(1, 24, 21, "A %s", finales[selection].heure);
	}
	else if (langue == 3){
		PA_OutputText(1, 1, 21, "AM %s", finales[selection].date);
		PA_OutputText(1, 23, 21, "IN %s", finales[selection].heure);
	}
	else if (langue == 4){
		PA_OutputText(1, 1, 21, "SU %s", finales[selection].date);
		PA_OutputText(1, 24, 21, "A %s", finales[selection].heure);
	}
	else if (langue == 5){
		PA_OutputText(1, 1, 21, "EL %s", finales[selection].date);
		PA_OutputText(1, 23, 21, "EN %s", finales[selection].heure);
	}
	else{
		PA_OutputText(1, 1, 21, "ON %s", finales[selection].date);
		PA_OutputText(1, 23, 21, "IN %s", finales[selection].heure);
	}

	PA_OutputText(1, 1, 22, "%s", finales[selection].equipe1);
	PA_RightOutputText(1, 22, finales[selection].equipe2);   
}

void NavigationMatchsFinales()
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
			InitMatchsFinales();
			Pad.Newpress.Down = false;
		}
		else if (Pad.Newpress.Up && selection > 0)
		{
			selection--;
			PA_DeleteText(1);
			InitMatchsFinales();
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
			if (PA_StylusInZone(112, 8, 144, 24) && finales[selection].numero1 != 32 && finales[selection].numero2 != 32)
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

				PA_SetSpriteAnim(0, FLAG1, finales[selection].numero1 + 1);
				PA_SetSpriteAnim(0, FLAG2, finales[selection].numero2 + 1);
				PA_SetSpriteAnim(0, SCORE1, finales[selection].score1 + 1);
				PA_SetSpriteAnim(0, SCORE2, finales[selection].score2 + 1);
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
				finales[selection].score1++;
				PA_SetSpriteAnim(0, SCORE1, finales[selection].score1 + 1);
			}
			else if (PA_StylusInZone(70, 86, 86, 104) && finales[selection].score1 > 0)
			{
				finales[selection].score1--;
				PA_SetSpriteAnim(0, SCORE1, finales[selection].score1 + 1);
			}

			if (PA_StylusInZone(166, 70, 182, 78))
			{
				mmEffect(SFX_SFXB);
				finales[selection].score2++;
				PA_SetSpriteAnim(0, SCORE2, finales[selection].score2 + 1);
			}
			else if (PA_StylusInZone(166, 86, 182, 104) && finales[selection].score2 > 0)
			{
				finales[selection].score2--;
				PA_SetSpriteAnim(0, SCORE2, finales[selection].score2 + 1);
			}

			//VALIDER
			if (PA_StylusInZone(8, 152, 40, 168))
			{
				if (finales[selection].score1 > finales[selection].score2)
				{
					Finales[selection].premier = finales[selection].numero1;
					Finales[selection].deuxieme = finales[selection].numero2;
				}
				else if (finales[selection].score2 > finales[selection].score1)
				{
					Finales[selection].premier = finales[selection].numero2;
					Finales[selection].deuxieme = finales[selection].numero1;
				}
				else
				{
					mmEffect(SFX_SFXA);
					penalty = 1;
					fadein();
					PA_LoadGif(0, (void*)BG3_bas_penalty);
					PA_SetSpriteAnim(0, BOUTON_RESET, 0);
					PA_SetSpriteAnim(0, PENALTY1, finales[selection].penalty1 + 1);
					PA_SetSpriteAnim(0, PENALTY2, finales[selection].penalty2 + 1);
					fadeout();
					Stylus.Newpress = false;

					while(penalty == 1)
					{
						if (Stylus.Newpress)
						{
							if (PA_StylusInZone(70, 116, 88, 124))
							{
								mmEffect(SFX_SFXB);
								finales[selection].penalty1++;
								PA_SetSpriteAnim(0, PENALTY1, finales[selection].penalty1 + 1);
							}
							else if (PA_StylusInZone(70, 132, 88, 140) && finales[selection].penalty1 > 0)
							{
								finales[selection].penalty1--;
								PA_SetSpriteAnim(0, PENALTY1, finales[selection].penalty1 + 1);
							}

							if (PA_StylusInZone(166, 116, 182, 124))
							{
								mmEffect(SFX_SFXB);
								finales[selection].penalty2++;
								PA_SetSpriteAnim(0, PENALTY2, finales[selection].penalty2 + 1);
							}
							else if (PA_StylusInZone(166, 132, 182, 140) && finales[selection].penalty2 > 0)
							{
								finales[selection].penalty2--;
								PA_SetSpriteAnim(0, PENALTY2, finales[selection].penalty2 + 1);
							}

							//VALIDER
							if (PA_StylusInZone(8, 152, 40, 168))
							{
								if (finales[selection].penalty1 > finales[selection].penalty2)
								{
									Finales[selection].premier = finales[selection].numero1;
									Finales[selection].deuxieme = finales[selection].numero2;
									penalty = 0;
								}
								else if (finales[selection].penalty2 > finales[selection].penalty1)
								{
									Finales[selection].premier = finales[selection].numero2;
									Finales[selection].deuxieme = finales[selection].numero1;
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
				finales[selection].jouer = 1;

				entrer_score = 0;
				InitMatchsFinales();
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
				finales[selection].jouer = 0;
				finales[selection].score1 = 0;
				finales[selection].score2 = 0;
				finales[selection].penalty1 = 0;
				finales[selection].penalty2 = 0;
				Finales[selection].premier = 32;
				Finales[selection].deuxieme = 32;
				entrer_score = 0;
				InitMatchsFinales();
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

void NavigationFinales()
{
	startmenu = 11;

	while (startmenu == 11)
	{
		NavigationMatchsFinales();

		PA_CenterOutputText(1, 17, finales[selection].ville);
		PA_CenterOutputText(1, 19, finales[selection].stade);

		if (langue == 1){
			PA_OutputText(1, 1, 21, "ON %s", finales[selection].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection + 62 + 1);
			PA_OutputText(1, 23, 21, "IN %s", finales[selection].heure);
		}
		else if (langue == 2){
			PA_OutputText(1, 1, 21, "LE %s", finales[selection].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection + 62 + 1);
			PA_OutputText(1, 24, 21, "A %s", finales[selection].heure);
		}
		else if (langue == 3){
			PA_OutputText(1, 1, 21, "AM %s", finales[selection].date);
			PA_OutputText(1, 12, 21, "SPIEL %02d", selection + 60 + 1);
			PA_OutputText(1, 23, 21, "IN %s", finales[selection].heure);
		}
		else if (langue == 4){
			PA_OutputText(1, 1, 21, "SU %s", finales[selection].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection + 62 + 1);
			PA_OutputText(1, 24, 21, "A %s", finales[selection].heure);
		}
		else if (langue == 5){
			PA_OutputText(1, 1, 21, "EL %s", finales[selection].date);
			PA_OutputText(1, 11, 21, "PARTIDO %02d", selection + 62 + 1);
			PA_OutputText(1, 23, 21, "EN %s", finales[selection].heure);
		}
		else{
			PA_OutputText(1, 1, 21, "ON %s", finales[selection].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection + 62 + 1);
			PA_OutputText(1, 23, 21, "IN %s", finales[selection].heure);
		}

		PA_OutputText(1, 1, 22, "%s", finales[selection].equipe1);
		PA_RightOutputText(1, 22, finales[selection].equipe2);

		PA_WaitForVBL();
	}
}
