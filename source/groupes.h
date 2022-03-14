void InitMatchsGroupes()
{
	determine_codage();

	char *valeurs[] = 
	{
		equipe[0 + (4 * groupe_courant)].Codage,
		equipe[1 + (4 * groupe_courant)].Codage,
		equipe[2 + (4 * groupe_courant)].Codage,
		equipe[3 + (4 * groupe_courant)].Codage
	};

	tri_alphabetique(valeurs, 4);

	for (i = 0; i < 4; i++)
	{
		if (equipe[i + (4 * groupe_courant)].Codage == valeurs[3]) premier = i + (4 * groupe_courant);
		else if (equipe[i + (4 * groupe_courant)].Codage == valeurs[2]) deuxieme = i + (4 * groupe_courant);
		else if (equipe[i + (4 * groupe_courant)].Codage == valeurs[1]) troisieme = i + (4 * groupe_courant);
		else if (equipe[i + (4 * groupe_courant)].Codage == valeurs[0]) quatrieme = i + (4 * groupe_courant);
	}
	
	//Classement par defaut
	if (equipe[0 + (4*groupe_courant)].Joue + equipe[1 + (4*groupe_courant)].Joue +
		equipe[2 + (4*groupe_courant)].Joue + equipe[3 + (4*groupe_courant)].Joue == 0)
	{
		premier = 4*groupe_courant;
		deuxieme = 1 + (4*groupe_courant);
		troisieme = 2 + (4*groupe_courant);
		quatrieme = 3 + (4*groupe_courant);
	}

	groupe[groupe_courant].premier = premier;
	groupe[groupe_courant].deuxieme = deuxieme;

	//LES SPRITES
	//HAUT
	PA_SetSpriteAnim(1, 0, equipe[premier].Points + 1);
	PA_SetSpriteAnim(1, 1, equipe[premier].Joue + 1);
	PA_SetSpriteAnim(1, 2, equipe[premier].Gagne + 1);
	PA_SetSpriteAnim(1, 3, equipe[premier].Nul + 1);
	PA_SetSpriteAnim(1, 4, equipe[premier].Perdu + 1);
	PA_SetSpriteAnim(1, 5, equipe[premier].ButPour + 1);
	PA_SetSpriteAnim(1, 6, equipe[premier].ButContre + 1);	
	if (equipe[premier].Difference < 0)
	{
		equipe[premier].Difference = equipe[premier].Difference * -1;
		PA_SetSpriteAnim(1, SIGNE1, 2);
	}
	else if (equipe[premier].Difference == 0)
	{
		PA_SetSpriteAnim(1, SIGNE1, 0);
	}
	else
	{
		PA_SetSpriteAnim(1, SIGNE1, 1);
	} 
	PA_SetSpriteAnim(1, 7, equipe[premier].Difference + 1);

	PA_SetSpriteAnim(1, 8, equipe[deuxieme].Points + 1);
	PA_SetSpriteAnim(1, 9, equipe[deuxieme].Joue + 1);
	PA_SetSpriteAnim(1, 10, equipe[deuxieme].Gagne + 1);
	PA_SetSpriteAnim(1, 11, equipe[deuxieme].Nul + 1);
	PA_SetSpriteAnim(1, 12, equipe[deuxieme].Perdu + 1);
	PA_SetSpriteAnim(1, 13, equipe[deuxieme].ButPour + 1);
	PA_SetSpriteAnim(1, 14, equipe[deuxieme].ButContre + 1);
	if (equipe[deuxieme].Difference < 0)
	{
		equipe[deuxieme].Difference = equipe[deuxieme].Difference * -1;
		PA_SetSpriteAnim(1, SIGNE2, 2);
	}
	else if (equipe[deuxieme].Difference == 0)
	{
		PA_SetSpriteAnim(1, SIGNE2, 0);
	}
	else
	{
		PA_SetSpriteAnim(1, SIGNE2, 1);
	}
	PA_SetSpriteAnim(1, 15, equipe[deuxieme].Difference + 1);

	PA_SetSpriteAnim(1, 16, equipe[troisieme].Points + 1);
	PA_SetSpriteAnim(1, 17, equipe[troisieme].Joue + 1);
	PA_SetSpriteAnim(1, 18, equipe[troisieme].Gagne + 1);
	PA_SetSpriteAnim(1, 19, equipe[troisieme].Nul + 1);
	PA_SetSpriteAnim(1, 20, equipe[troisieme].Perdu + 1);
	PA_SetSpriteAnim(1, 21, equipe[troisieme].ButPour + 1);
	PA_SetSpriteAnim(1, 22, equipe[troisieme].ButContre + 1);
	if (equipe[troisieme].Difference < 0)
	{
		equipe[troisieme].Difference = equipe[troisieme].Difference * -1;
		PA_SetSpriteAnim(1, SIGNE3, 2);
	}
	else if (equipe[troisieme].Difference == 0)
	{
		PA_SetSpriteAnim(1, SIGNE3, 0);
	}
	else
	{
		PA_SetSpriteAnim(1, SIGNE3, 1);
	}
	PA_SetSpriteAnim(1, 23, equipe[troisieme].Difference + 1);

	PA_SetSpriteAnim(1, 24, equipe[quatrieme].Points + 1);
	PA_SetSpriteAnim(1, 25, equipe[quatrieme].Joue + 1);
	PA_SetSpriteAnim(1, 26, equipe[quatrieme].Gagne + 1);
	PA_SetSpriteAnim(1, 27, equipe[quatrieme].Nul + 1);
	PA_SetSpriteAnim(1, 28, equipe[quatrieme].Perdu + 1);
	PA_SetSpriteAnim(1, 29, equipe[quatrieme].ButPour + 1);
	PA_SetSpriteAnim(1, 30, equipe[quatrieme].ButContre + 1);
	if (equipe[quatrieme].Difference < 0)
	{
		equipe[quatrieme].Difference = equipe[quatrieme].Difference * -1;
		PA_SetSpriteAnim(1, SIGNE4, 2);
	}
	else if (equipe[quatrieme].Difference == 0)
	{
		PA_SetSpriteAnim(1, SIGNE4, 0);
	}
	else
	{
		PA_SetSpriteAnim(1, SIGNE4, 1);
	}
	PA_SetSpriteAnim(1, 31, equipe[quatrieme].Difference + 1);

	PA_SetSpriteAnim(1, 32, premier + 1);
	PA_SetSpriteAnim(1, 33, deuxieme + 1);
	PA_SetSpriteAnim(1, 34, troisieme + 1);
	PA_SetSpriteAnim(1, 35, quatrieme + 1);

	//BAS
	if (groupe_courant == 0)//A
	{
		PA_SetSpriteAnim(0, 36, equipe[0].numero + 1); PA_SetSpriteAnim(0, 37, equipe[1].numero + 1);
		PA_SetSpriteAnim(0, 38, equipe[2].numero + 1); PA_SetSpriteAnim(0, 39, equipe[3].numero + 1);
		PA_SetSpriteAnim(0, 40, equipe[0].numero + 1); PA_SetSpriteAnim(0, 41, equipe[2].numero + 1);
		PA_SetSpriteAnim(0, 42, equipe[3].numero + 1); PA_SetSpriteAnim(0, 43, equipe[1].numero + 1);
		PA_SetSpriteAnim(0, 44, equipe[3].numero + 1); PA_SetSpriteAnim(0, 45, equipe[0].numero + 1);
		PA_SetSpriteAnim(0, 46, equipe[1].numero + 1); PA_SetSpriteAnim(0, 47, equipe[2].numero + 1);

		PA_SetSpriteAnim(0, 58, (match[0].score1+1) * match[0].jouer); PA_SetSpriteAnim(0, 59, (match[0].score2+1) * match[0].jouer);
		PA_SetSpriteAnim(0, 60, (match[1].score1+1) * match[1].jouer); PA_SetSpriteAnim(0, 61, (match[1].score2+1) * match[1].jouer);
		PA_SetSpriteAnim(0, 62, (match[16].score1+1) * match[16].jouer); PA_SetSpriteAnim(0, 63, (match[16].score2+1) * match[16].jouer);
		PA_SetSpriteAnim(0, 64, (match[17].score1+1) * match[17].jouer); PA_SetSpriteAnim(0, 65, (match[17].score2+1) * match[17].jouer);
		PA_SetSpriteAnim(0, 66, (match[32].score1+1) * match[32].jouer); PA_SetSpriteAnim(0, 67, (match[32].score2+1) * match[32].jouer);
		PA_SetSpriteAnim(0, 68, (match[33].score1+1) * match[33].jouer); PA_SetSpriteAnim(0, 69, (match[33].score2+1) * match[33].jouer);
	}
	else if (groupe_courant == 1)//B
	{
		PA_SetSpriteAnim(0, 36, equipe[4].numero + 1); PA_SetSpriteAnim(0, 37, equipe[5].numero + 1);
		PA_SetSpriteAnim(0, 38, equipe[6].numero + 1); PA_SetSpriteAnim(0, 39, equipe[7].numero + 1);
		PA_SetSpriteAnim(0, 40, equipe[4].numero + 1); PA_SetSpriteAnim(0, 41, equipe[6].numero + 1);
		PA_SetSpriteAnim(0, 42, equipe[7].numero + 1); PA_SetSpriteAnim(0, 43, equipe[5].numero + 1);
		PA_SetSpriteAnim(0, 44, equipe[7].numero + 1); PA_SetSpriteAnim(0, 45, equipe[4].numero + 1);
		PA_SetSpriteAnim(0, 46, equipe[5].numero + 1); PA_SetSpriteAnim(0, 47, equipe[6].numero + 1);

		PA_SetSpriteAnim(0, 58, (match[2].score1+1) * match[2].jouer); PA_SetSpriteAnim(0, 59, (match[2].score2+1) * match[2].jouer);
		PA_SetSpriteAnim(0, 60, (match[3].score1+1) * match[3].jouer); PA_SetSpriteAnim(0, 61, (match[3].score2+1) * match[3].jouer);
		PA_SetSpriteAnim(0, 62, (match[18].score1+1) * match[18].jouer); PA_SetSpriteAnim(0, 63, (match[18].score2+1) * match[18].jouer);
		PA_SetSpriteAnim(0, 64, (match[19].score1+1) * match[19].jouer); PA_SetSpriteAnim(0, 65, (match[19].score2+1) * match[19].jouer);
		PA_SetSpriteAnim(0, 66, (match[34].score1+1) * match[34].jouer); PA_SetSpriteAnim(0, 67, (match[34].score2+1) * match[34].jouer);
		PA_SetSpriteAnim(0, 68, (match[35].score1+1) * match[35].jouer); PA_SetSpriteAnim(0, 69, (match[35].score2+1) * match[35].jouer);
	}
	else if (groupe_courant == 2)//c
	{
		PA_SetSpriteAnim(0, 36, equipe[8].numero + 1); PA_SetSpriteAnim(0, 37, equipe[9].numero + 1);
		PA_SetSpriteAnim(0, 38, equipe[10].numero + 1); PA_SetSpriteAnim(0, 39, equipe[11].numero + 1);
		PA_SetSpriteAnim(0, 40, equipe[8].numero + 1); PA_SetSpriteAnim(0, 41, equipe[10].numero + 1);
		PA_SetSpriteAnim(0, 42, equipe[11].numero + 1); PA_SetSpriteAnim(0, 43, equipe[9].numero + 1);
		PA_SetSpriteAnim(0, 44, equipe[11].numero + 1); PA_SetSpriteAnim(0, 45, equipe[8].numero + 1);
		PA_SetSpriteAnim(0, 46, equipe[9].numero + 1); PA_SetSpriteAnim(0, 47, equipe[10].numero + 1);

		PA_SetSpriteAnim(0, 58, (match[4].score1+1) * match[4].jouer); PA_SetSpriteAnim(0, 59, (match[4].score2+1) * match[4].jouer);
		PA_SetSpriteAnim(0, 60, (match[5].score1+1) * match[5].jouer); PA_SetSpriteAnim(0, 61, (match[5].score2+1) * match[5].jouer);
		PA_SetSpriteAnim(0, 62, (match[20].score1+1) * match[20].jouer); PA_SetSpriteAnim(0, 63, (match[20].score2+1) * match[20].jouer);
		PA_SetSpriteAnim(0, 64, (match[21].score1+1) * match[21].jouer); PA_SetSpriteAnim(0, 65, (match[21].score2+1) * match[21].jouer);
		PA_SetSpriteAnim(0, 66, (match[36].score1+1) * match[36].jouer); PA_SetSpriteAnim(0, 67, (match[36].score2+1) * match[36].jouer);
		PA_SetSpriteAnim(0, 68, (match[37].score1+1) * match[37].jouer); PA_SetSpriteAnim(0, 69, (match[37].score2+1) * match[37].jouer);
	}
	else if (groupe_courant == 3)//D
	{
		PA_SetSpriteAnim(0, 36, equipe[12].numero + 1); PA_SetSpriteAnim(0, 37, equipe[13].numero + 1);
		PA_SetSpriteAnim(0, 38, equipe[14].numero + 1); PA_SetSpriteAnim(0, 39, equipe[15].numero + 1);
		PA_SetSpriteAnim(0, 40, equipe[12].numero + 1); PA_SetSpriteAnim(0, 41, equipe[14].numero + 1);
		PA_SetSpriteAnim(0, 42, equipe[15].numero + 1); PA_SetSpriteAnim(0, 43, equipe[13].numero + 1);
		PA_SetSpriteAnim(0, 44, equipe[15].numero + 1); PA_SetSpriteAnim(0, 45, equipe[12].numero + 1);
		PA_SetSpriteAnim(0, 46, equipe[13].numero + 1); PA_SetSpriteAnim(0, 47, equipe[14].numero + 1);

		PA_SetSpriteAnim(0, 58, (match[6].score1+1) * match[6].jouer); PA_SetSpriteAnim(0, 59, (match[6].score2+1) * match[6].jouer);
		PA_SetSpriteAnim(0, 60, (match[7].score1+1) * match[7].jouer); PA_SetSpriteAnim(0, 61, (match[7].score2+1) * match[7].jouer);
		PA_SetSpriteAnim(0, 62, (match[22].score1+1) * match[22].jouer); PA_SetSpriteAnim(0, 63, (match[22].score2+1) * match[22].jouer);
		PA_SetSpriteAnim(0, 64, (match[23].score1+1) * match[23].jouer); PA_SetSpriteAnim(0, 65, (match[23].score2+1) * match[23].jouer);
		PA_SetSpriteAnim(0, 66, (match[38].score1+1) * match[38].jouer); PA_SetSpriteAnim(0, 67, (match[38].score2+1) * match[38].jouer);
		PA_SetSpriteAnim(0, 68, (match[39].score1+1) * match[39].jouer); PA_SetSpriteAnim(0, 69, (match[39].score2+1) * match[39].jouer);
	}
	else if (groupe_courant == 4)//E
	{
		PA_SetSpriteAnim(0, 36, equipe[16].numero + 1); PA_SetSpriteAnim(0, 37, equipe[17].numero + 1);
		PA_SetSpriteAnim(0, 38, equipe[18].numero + 1); PA_SetSpriteAnim(0, 39, equipe[19].numero + 1);
		PA_SetSpriteAnim(0, 40, equipe[16].numero + 1); PA_SetSpriteAnim(0, 41, equipe[18].numero + 1);
		PA_SetSpriteAnim(0, 42, equipe[19].numero + 1); PA_SetSpriteAnim(0, 43, equipe[17].numero + 1);
		PA_SetSpriteAnim(0, 44, equipe[19].numero + 1); PA_SetSpriteAnim(0, 45, equipe[16].numero + 1);
		PA_SetSpriteAnim(0, 46, equipe[17].numero + 1); PA_SetSpriteAnim(0, 47, equipe[18].numero + 1);

		PA_SetSpriteAnim(0, 58, (match[8].score1+1) * match[8].jouer); PA_SetSpriteAnim(0, 59, (match[8].score2+1) * match[8].jouer);
		PA_SetSpriteAnim(0, 60, (match[9].score1+1) * match[9].jouer); PA_SetSpriteAnim(0, 61, (match[9].score2+1) * match[9].jouer);
		PA_SetSpriteAnim(0, 62, (match[24].score1+1) * match[24].jouer); PA_SetSpriteAnim(0, 63, (match[24].score2+1) * match[24].jouer);
		PA_SetSpriteAnim(0, 64, (match[25].score1+1) * match[25].jouer); PA_SetSpriteAnim(0, 65, (match[25].score2+1) * match[25].jouer);
		PA_SetSpriteAnim(0, 66, (match[40].score1+1) * match[40].jouer); PA_SetSpriteAnim(0, 67, (match[40].score2+1) * match[40].jouer);
		PA_SetSpriteAnim(0, 68, (match[41].score1+1) * match[41].jouer); PA_SetSpriteAnim(0, 69, (match[41].score2+1) * match[41].jouer);
	}
	else if (groupe_courant == 5)//F
	{
		PA_SetSpriteAnim(0, 36, equipe[20].numero + 1); PA_SetSpriteAnim(0, 37, equipe[21].numero + 1);
		PA_SetSpriteAnim(0, 38, equipe[22].numero + 1); PA_SetSpriteAnim(0, 39, equipe[23].numero + 1);
		PA_SetSpriteAnim(0, 40, equipe[20].numero + 1); PA_SetSpriteAnim(0, 41, equipe[22].numero + 1);
		PA_SetSpriteAnim(0, 42, equipe[23].numero + 1); PA_SetSpriteAnim(0, 43, equipe[21].numero + 1);
		PA_SetSpriteAnim(0, 44, equipe[23].numero + 1); PA_SetSpriteAnim(0, 45, equipe[20].numero + 1);
		PA_SetSpriteAnim(0, 46, equipe[21].numero + 1); PA_SetSpriteAnim(0, 47, equipe[22].numero + 1);

		PA_SetSpriteAnim(0, 58, (match[10].score1+1) * match[10].jouer); PA_SetSpriteAnim(0, 59, (match[10].score2+1) * match[10].jouer);
		PA_SetSpriteAnim(0, 60, (match[11].score1+1) * match[11].jouer); PA_SetSpriteAnim(0, 61, (match[11].score2+1) * match[11].jouer);
		PA_SetSpriteAnim(0, 62, (match[26].score1+1) * match[26].jouer); PA_SetSpriteAnim(0, 63, (match[26].score2+1) * match[26].jouer);
		PA_SetSpriteAnim(0, 64, (match[27].score1+1) * match[27].jouer); PA_SetSpriteAnim(0, 65, (match[27].score2+1) * match[27].jouer);
		PA_SetSpriteAnim(0, 66, (match[42].score1+1) * match[42].jouer); PA_SetSpriteAnim(0, 67, (match[42].score2+1) * match[42].jouer);
		PA_SetSpriteAnim(0, 68, (match[43].score1+1) * match[43].jouer); PA_SetSpriteAnim(0, 69, (match[43].score2+1) * match[43].jouer);
	}
	else if (groupe_courant == 6)//G
	{
		PA_SetSpriteAnim(0, 36, equipe[24].numero + 1); PA_SetSpriteAnim(0, 37, equipe[25].numero + 1);
		PA_SetSpriteAnim(0, 38, equipe[26].numero + 1); PA_SetSpriteAnim(0, 39, equipe[27].numero + 1);
		PA_SetSpriteAnim(0, 40, equipe[24].numero + 1); PA_SetSpriteAnim(0, 41, equipe[26].numero + 1);
		PA_SetSpriteAnim(0, 42, equipe[27].numero + 1); PA_SetSpriteAnim(0, 43, equipe[25].numero + 1);
		PA_SetSpriteAnim(0, 44, equipe[27].numero + 1); PA_SetSpriteAnim(0, 45, equipe[24].numero + 1);
		PA_SetSpriteAnim(0, 46, equipe[25].numero + 1); PA_SetSpriteAnim(0, 47, equipe[26].numero + 1);

		PA_SetSpriteAnim(0, 58, (match[12].score1+1) * match[12].jouer); PA_SetSpriteAnim(0, 59, (match[12].score2+1) * match[12].jouer);
		PA_SetSpriteAnim(0, 60, (match[13].score1+1) * match[13].jouer); PA_SetSpriteAnim(0, 61, (match[13].score2+1) * match[13].jouer);
		PA_SetSpriteAnim(0, 62, (match[28].score1+1) * match[28].jouer); PA_SetSpriteAnim(0, 63, (match[28].score2+1) * match[28].jouer);
		PA_SetSpriteAnim(0, 64, (match[29].score1+1) * match[29].jouer); PA_SetSpriteAnim(0, 65, (match[29].score2+1) * match[29].jouer);
		PA_SetSpriteAnim(0, 66, (match[44].score1+1) * match[44].jouer); PA_SetSpriteAnim(0, 67, (match[44].score2+1) * match[44].jouer);
		PA_SetSpriteAnim(0, 68, (match[45].score1+1) * match[45].jouer); PA_SetSpriteAnim(0, 69, (match[45].score2+1) * match[45].jouer);
	}
	else if (groupe_courant == 7)//H
	{
		PA_SetSpriteAnim(0, 36, equipe[28].numero + 1); PA_SetSpriteAnim(0, 37, equipe[29].numero + 1);
		PA_SetSpriteAnim(0, 38, equipe[30].numero + 1); PA_SetSpriteAnim(0, 39, equipe[31].numero + 1);
		PA_SetSpriteAnim(0, 40, equipe[28].numero + 1); PA_SetSpriteAnim(0, 41, equipe[30].numero + 1);
		PA_SetSpriteAnim(0, 42, equipe[31].numero + 1); PA_SetSpriteAnim(0, 43, equipe[29].numero + 1);
		PA_SetSpriteAnim(0, 44, equipe[31].numero + 1); PA_SetSpriteAnim(0, 45, equipe[28].numero + 1);
		PA_SetSpriteAnim(0, 46, equipe[29].numero + 1); PA_SetSpriteAnim(0, 47, equipe[30].numero + 1);

		PA_SetSpriteAnim(0, 58, (match[14].score1+1) * match[14].jouer); PA_SetSpriteAnim(0, 59, (match[14].score2+1) * match[14].jouer);
		PA_SetSpriteAnim(0, 60, (match[15].score1+1) * match[15].jouer); PA_SetSpriteAnim(0, 61, (match[15].score2+1) * match[15].jouer);
		PA_SetSpriteAnim(0, 62, (match[30].score1+1) * match[30].jouer); PA_SetSpriteAnim(0, 63, (match[30].score2+1) * match[30].jouer);
		PA_SetSpriteAnim(0, 64, (match[31].score1+1) * match[31].jouer); PA_SetSpriteAnim(0, 65, (match[31].score2+1) * match[31].jouer);
		PA_SetSpriteAnim(0, 66, (match[46].score1+1) * match[46].jouer); PA_SetSpriteAnim(0, 67, (match[46].score2+1) * match[46].jouer);
		PA_SetSpriteAnim(0, 68, (match[47].score1+1) * match[47].jouer); PA_SetSpriteAnim(0, 69, (match[47].score2+1) * match[47].jouer);
	}

	PA_OutputText(0, 2, 5, "%s                      %s", match[groupe_courant*2].abb1, match[groupe_courant*2].abb2);
	PA_OutputText(0, 2, 8, "%s                      %s", match[groupe_courant*2 + 1].abb1, match[groupe_courant*2 + 1].abb2);
	PA_OutputText(0, 2, 11, "%s                      %s", match[groupe_courant*2 + 16].abb1, match[groupe_courant*2 + 16].abb2);
	PA_OutputText(0, 2, 14, "%s                      %s", match[groupe_courant*2 + 17].abb1, match[groupe_courant*2 + 17].abb2);
	PA_OutputText(0, 2, 17, "%s                      %s", match[groupe_courant*2 + 32].abb1, match[groupe_courant*2 + 32].abb2);
	PA_OutputText(0, 2, 20, "%s                      %s", match[groupe_courant*2 + 33].abb1, match[groupe_courant*2 + 33].abb2);

	selection_match = (groupe_courant*2) + selection;

	if (langue == 1) PA_SetSpriteAnim(1, LETTRE, 8+groupe_courant+1);
	else if (langue == 2) PA_SetSpriteAnim(1, LETTRE, groupe_courant+1);
	else if (langue == 3) PA_SetSpriteAnim(1, LETTRE, 8+groupe_courant+1);
	else if (langue == 4) PA_SetSpriteAnim(1, LETTRE, 16+groupe_courant+1);
	else if (langue == 5) PA_SetSpriteAnim(1, LETTRE, 24+groupe_courant+1);
	else PA_SetSpriteAnim(1, LETTRE, 8+groupe_courant+1);

	PA_CenterOutputText(1, 17, match[selection_match].ville);
	PA_CenterOutputText(1, 19, match[selection_match].stade);

	if (langue == 1){
		PA_OutputText(1, 1, 21, "ON %s", match[selection_match].date);
		PA_OutputText(1, 23, 21, "IN %s", match[selection_match].heure);
	}
	else if (langue == 2){
		PA_OutputText(1, 1, 21, "LE %s", match[selection_match].date);
		PA_OutputText(1, 24, 21, "A %s", match[selection_match].heure);
	}
	else if (langue == 3){
		PA_OutputText(1, 1, 21, "AM %s", match[selection_match].date);
		PA_OutputText(1, 23, 21, "IN %s", match[selection_match].heure);
	}
	else if (langue == 4){
		PA_OutputText(1, 1, 21, "SU %s", match[selection_match].date);
		PA_OutputText(1, 24, 21, "A %s", match[selection_match].heure);
	}
	else if (langue == 5){
		PA_OutputText(1, 1, 21, "EL %s", match[selection_match].date);
		PA_OutputText(1, 23, 21, "EN %s", match[selection_match].heure);
	}
	else{
		PA_OutputText(1, 1, 21, "ON %s", match[selection_match].date);
		PA_OutputText(1, 23, 21, "IN %s", match[selection_match].heure);
	}

	PA_OutputText(1, 1, 22, "%s", match[selection_match].equipe1);
	PA_RightOutputText(1, 22, match[selection_match].equipe2);
}

void NavigationMatchsGroupes()
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
		if ((Pad.Newpress.R && groupe_courant < 7) || (Stylus.Newpress && PA_StylusInZone(219, 3, 252, 20) && groupe_courant < 7))
		{
			PA_SetSpriteAnim(0, BOUTON_R, 4);
			fadein();			
			groupe_courant++;
			PA_DeleteText(1);
			CalculStats();
			InitMatchsGroupes();
			PA_SetSpriteAnim(0, BOUTON_R, 3);
			fadeout();
			Pad.Newpress.R = false;
			Stylus.Newpress = false;
		}
		else if ((Pad.Newpress.R && groupe_courant == 7) || (Stylus.Newpress && PA_StylusInZone(219, 3, 252, 20) && groupe_courant == 7))
		{
			PA_SetSpriteAnim(0, BOUTON_R, 4);
			fadein();
			groupe_courant = 0;
			PA_DeleteText(1);
			CalculStats();
			InitMatchsGroupes();
			PA_SetSpriteAnim(0, BOUTON_R, 3);
			fadeout();
			Pad.Newpress.R = false;
			Stylus.Newpress = false;
		}

		if ((Pad.Newpress.L && groupe_courant > 0) || (Stylus.Newpress && PA_StylusInZone(3, 3, 36, 20) && groupe_courant > 0))
		{
			PA_SetSpriteAnim(0, BOUTON_L, 2);
			fadein();
			groupe_courant--;
			PA_DeleteText(1);
			CalculStats();
			InitMatchsGroupes();
			PA_SetSpriteAnim(0, BOUTON_L, 1);
			fadeout();
			Pad.Newpress.L = false;
			Stylus.Newpress = false;
		}
		else if ((Pad.Newpress.L && groupe_courant == 0) || (Stylus.Newpress && PA_StylusInZone(3, 3, 36, 20) && groupe_courant == 0))
		{
			PA_SetSpriteAnim(0, BOUTON_L, 2);
			fadein();
			groupe_courant = 7;
			PA_DeleteText(1);
			CalculStats();
			InitMatchsGroupes();
			PA_SetSpriteAnim(0, BOUTON_L, 1);
			fadeout();		
			Pad.Newpress.L = false;
			Stylus.Newpress = false;
		}

		if (Pad.Newpress.Down && selection_y < 5)
		{
			selection_y++;
			PA_DeleteText(1);
			Pad.Newpress.Down = false;
		}
		else if (Pad.Newpress.Up && selection_y > 0)
		{
			selection_y--;
			PA_DeleteText(1);
			Pad.Newpress.Up = false;
		}
	
		if (Stylus.Newpress)
		{
			//SCORE
			if (PA_StylusInZone(112, 8, 144, 24) && ((huitieme[0].jouer + huitieme[1].jouer + huitieme[2].jouer + huitieme[3].jouer
			+ huitieme[4].jouer + huitieme[5].jouer + huitieme[6].jouer + huitieme[7].jouer) == 0))
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

				PA_SetSpriteAnim(0, FLAG1, match[selection_match].numero1 + 1);
				PA_SetSpriteAnim(0, FLAG2, match[selection_match].numero2 + 1);
				PA_SetSpriteAnim(0, SCORE1, match[selection_match].score1 + 1);
				PA_SetSpriteAnim(0, SCORE2, match[selection_match].score2 + 1);
				fadeout();
			}

			//SELECTION AU STYLET
			if (PA_StylusInZone(4, 32, 252, 166))
			{
				PA_DeleteText(1);

				if (PA_StylusInZone(4, 32, 252, 56)) selection_y = 0;
				else if (PA_StylusInZone(4, 56, 252, 80)) selection_y = 1;
				else if (PA_StylusInZone(4, 80, 252, 104)) selection_y = 2;
				else if (PA_StylusInZone(4, 104, 252, 128)) selection_y = 3;
				else if (PA_StylusInZone(4, 128, 252, 152)) selection_y = 4;
				else if (PA_StylusInZone(4, 152, 252, 176)) selection_y = 5;
			}

			Stylus.Newpress = false;
		}

		if (selection_y == 0) selection = 0;
		if (selection_y == 1) selection = 1;
		if (selection_y == 2) selection = 16;
		if (selection_y == 3) selection = 17;
		if (selection_y == 4) selection = 32;
		if (selection_y == 5) selection = 33;

		PA_BGScrollY(0, 2, -selection_y*24);
	}
	else if (entrer_score == 1)
	{
		if (Stylus.Newpress)
		{
			if (PA_StylusInZone(70, 70, 86, 78))
			{
				mmEffect(SFX_SFXB);
				match[selection_match].score1++;
				PA_SetSpriteAnim(0, SCORE1, match[selection_match].score1 + 1);
			}
			else if (PA_StylusInZone(70, 86, 86, 104) && match[selection_match].score1 > 0)
			{
				match[selection_match].score1--;
				PA_SetSpriteAnim(0, SCORE1, match[selection_match].score1 + 1);
			}

			if (PA_StylusInZone(166, 70, 182, 78))
			{
				mmEffect(SFX_SFXB);
				match[selection_match].score2++;
				PA_SetSpriteAnim(0, SCORE2, match[selection_match].score2 + 1);
			}
			else if (PA_StylusInZone(166, 86, 182, 104) && match[selection_match].score2 > 0)
			{
				match[selection_match].score2--;
				PA_SetSpriteAnim(0, SCORE2, match[selection_match].score2 + 1);
			}

			//VALIDER
			if (PA_StylusInZone(8, 152, 40, 168))
			{
				mmEffect(SFX_SFXA);
				fadein();
				match[selection_match].jouer = 1;
				CalculStats();
				entrer_score = 0;
				//InitMatchsGroupes();
				sauver_sauvegarde();
				InitMatchsGroupes();
				PA_LoadGif(0, (void*)BG3_bas_groupes);
				PA_SetSpriteAnim(0, BOUTON_L, 1);
				PA_SetSpriteAnim(0, BOUTON_R, 3);
				PA_SetSpriteAnim(0, BOUTON_SCORE, 5);
				PA_SetSpriteAnim(0, BOUTON_VALIDER, 0);
				PA_SetSpriteAnim(0, BOUTON_ANNULER, 0);
				PA_SetSpriteAnim(0, BOUTON_RESET, 0);
				PA_SetSpriteAnim(0, QUITTER, 1);

				PA_SetSpriteAnim(0, FLAG1, 0);
				PA_SetSpriteAnim(0, FLAG2, 0);
				PA_SetSpriteAnim(0, SCORE1, 0);
				PA_SetSpriteAnim(0, SCORE2, 0);

				PA_ShowBg(0, 2);
				fadeout();
			}

			//RESET
			if (PA_StylusInZone(216, 152, 248, 168))
			{
				fadein();
				match[selection_match].jouer = 0;
				match[selection_match].score1 = 0;
				match[selection_match].score2 = 0;
				CalculStats();
				entrer_score = 0;
				//InitMatchsGroupes();
				sauver_sauvegarde();
				InitMatchsGroupes();
				PA_LoadGif(0, (void*)BG3_bas_groupes);
				PA_SetSpriteAnim(0, BOUTON_L, 1);
				PA_SetSpriteAnim(0, BOUTON_R, 3);
				PA_SetSpriteAnim(0, BOUTON_SCORE, 5);
				PA_SetSpriteAnim(0, BOUTON_VALIDER, 0);
				PA_SetSpriteAnim(0, BOUTON_ANNULER, 0);
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

void NavigationGroupes()
{
	startmenu = 3;

	while (startmenu == 3)
	{
		NavigationMatchsGroupes();

		selection_match = (groupe_courant*2) + selection;

		PA_CenterOutputText(1, 17, match[selection_match].ville);
		PA_CenterOutputText(1, 19, match[selection_match].stade);

		if (langue == 1){
			PA_OutputText(1, 1, 21, "ON %s", match[selection_match].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection_match + 1);
			PA_OutputText(1, 23, 21, "IN %s", match[selection_match].heure);
		}
		else if (langue == 2){
			PA_OutputText(1, 1, 21, "LE %s", match[selection_match].date);
			PA_OutputText(1, 13, 21, "MATCH %02d", selection_match + 1);
			PA_OutputText(1, 24, 21, "A %s", match[selection_match].heure);
		}
		else if (langue == 3){
			PA_OutputText(1, 1, 21, "AM %s", match[selection_match].date);
			PA_OutputText(1, 12, 21, "SPIEL %02d", selection_match + 1);
			PA_OutputText(1, 23, 21, "IN %s", match[selection_match].heure);
		}
		else if (langue == 4){
			PA_OutputText(1, 1, 21, "SU %s", match[selection_match].date);
			PA_OutputText(1, 13, 21, "MATCH %02d", selection_match + 1);
			PA_OutputText(1, 24, 21, "A %s", match[selection_match].heure);
		}
		else if (langue == 5){
			PA_OutputText(1, 1, 21, "EL %s", match[selection_match].date);
			PA_OutputText(1, 11, 21, "PARTIDO %02d", selection_match + 1);
			PA_OutputText(1, 23, 21, "EN %s", match[selection_match].heure);
		}
		else{
			PA_OutputText(1, 1, 21, "ON %s", match[selection_match].date);
			PA_OutputText(1, 12, 21, "MATCH %02d", selection_match + 1);
			PA_OutputText(1, 23, 21, "IN %s", match[selection_match].heure);
		}

		PA_OutputText(1, 1, 22, "%s", match[selection_match].equipe1);
		PA_RightOutputText(1, 22, match[selection_match].equipe2);

		PA_WaitForVBL();
	}
}


