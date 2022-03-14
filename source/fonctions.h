void charge_img_equipes()
{
	char path[128];
	
	sprintf(path, "/BWCMDS/Img/%s.gif", equipe[equipe_courant].abb);

	FILE* imgFile = fopen (path, "rb");

	if(imgFile){
	    free(buffer);
		u32 imgSize;
		fseek (imgFile, 0 , SEEK_END);
		imgSize = ftell (imgFile);
		rewind (imgFile);

		buffer = (char*) malloc (sizeof(char)*imgSize);
		fread (buffer, 1, imgSize, imgFile);

		fclose (imgFile);
		PA_LoadGif(1, (void *)buffer);
	}
}

void fadein()
{
	s8 i;
	for (i = 0; i >= -32; i-=6)
	{
		PA_SetBrightness(0, i);
		PA_SetBrightness(1, i);
		PA_WaitForVBL();
		PA_WaitForVBL();
	}
}

void fadeout()
{
	s8 i;
	for (i = -32; i <= 0; i+=6)
	{
		PA_SetBrightness(0, i);
		PA_SetBrightness(1, i);
		PA_WaitForVBL();
		PA_WaitForVBL();
	}
}

void PA_DeleteText(u8 screen)
{
	u8 z;
	for (z = 0; z < 24; z++) PA_OutputText(screen, 0, z, "                                ");
}

void PA_CenterOutputText(u8 screen, u8 y, char *text)
{
	int taille = strlen(text);
	u8 x = 16 - (taille / 2);

	PA_OutputText(screen, x, y, "%s", text);
}

void PA_RightOutputText(u8 screen, u8 y, char *text)
{
	int taille = strlen(text);
	u8 x = 31 - taille;
	
	PA_OutputText(screen, x, y, "%s", text);
}

void animation_bouton(u8 sprite, u8 depart, u8 fin)
{
	PA_StartSpriteAnimEx(0, sprite, depart, fin, 10, ANIM_ONESHOT);
}

void attente_ou_touche(u16 temps)
{
	u16 z = 0;
	while (z < temps)
	{
		z++;
		//test stylus ou pad
		if(Stylus.Newpress || Pad.Newpress.Anykey) {z = temps;}
		PA_WaitForVBL();
	}
	Stylus.Newpress = false;
	Pad.Newpress.Anykey = false;
}

void attente(u16 temps)
{
	u16 z = 0;
	while (z < temps)
	{
		z++;
		PA_WaitForVBL();
	}
}

void determine_codage()
{
	for (i=0; i < 4; i++)
	{
		equipe[i + (4 * groupe_courant)].Pointsp = 0;
		equipe[i + (4 * groupe_courant)].Differencep = 0;
		equipe[i + (4 * groupe_courant)].ButPourp = 0;

		//Sur 3 critères !!!
		sprintf(equipe[i + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[i + (4 * groupe_courant)].Points,
		  100 + equipe[i + (4 * groupe_courant)].Difference,
		 		equipe[i + (4 * groupe_courant)].ButPour,
				equipe[i + (4 * groupe_courant)].Pointsp,
		  100 + equipe[i + (4 * groupe_courant)].Differencep,
		 		equipe[i + (4 * groupe_courant)].ButPourp);
	}

//***Egalité à 2

	//Si 1 et 2 égal
	if (strcmp(equipe[0 + (4 * groupe_courant)].Codage, equipe[1 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[0 + (4 * groupe_courant)].Codage, equipe[2 + (4 * groupe_courant)].Codage) != 0
	 && strcmp(equipe[0 + (4 * groupe_courant)].Codage, equipe[3 + (4 * groupe_courant)].Codage) != 0)
	{
		for ( i = 0; i < 48; i++)
		{
			if (match[i].jouer == 1)
			{
				//Trouve le match en question
				if (match[i].numero1 == equipe[0 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[1 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp = 1;
						equipe[1 + (4 * groupe_courant)].Pointsp = 1;
					}
					else if (match[i].score1 < match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;

					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score2;
				}
				else if (match[i].numero1 == equipe[1 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[0 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp = 1;
						equipe[1 + (4 * groupe_courant)].Pointsp = 1;
					}
					else if (match[i].score1 < match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;

					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score2;
				}
			}
		}

		equipe[0 + (4 * groupe_courant)].Differencep = equipe[0 + (4 * groupe_courant)].ButPourp - equipe[1 + (4 * groupe_courant)].ButPourp;
		equipe[1 + (4 * groupe_courant)].Differencep = equipe[1 + (4 * groupe_courant)].ButPourp - equipe[0 + (4 * groupe_courant)].ButPourp;

		sprintf(equipe[0 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[0 + (4 * groupe_courant)].Points,
		  100 + equipe[0 + (4 * groupe_courant)].Difference,
		 		equipe[0 + (4 * groupe_courant)].ButPour,
				equipe[0 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[0 + (4 * groupe_courant)].Differencep,
		 		equipe[0 + (4 * groupe_courant)].ButPourp);
				
		sprintf(equipe[1 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[1 + (4 * groupe_courant)].Points,
		  100 + equipe[1 + (4 * groupe_courant)].Difference,
		 		equipe[1 + (4 * groupe_courant)].ButPour,
				equipe[1 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[1 + (4 * groupe_courant)].Differencep,
		 		equipe[1 + (4 * groupe_courant)].ButPourp);
	}
	
	//Si 1 et 3 égal
	if (strcmp(equipe[0 + (4 * groupe_courant)].Codage, equipe[2 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[0 + (4 * groupe_courant)].Codage, equipe[1 + (4 * groupe_courant)].Codage) != 0
	 && strcmp(equipe[0 + (4 * groupe_courant)].Codage, equipe[3 + (4 * groupe_courant)].Codage) != 0)
	{
		for ( i = 0; i < 48; i++)
		{
			if (match[i].jouer == 1)
			{
				//Trouve le match en question
				if (match[i].numero1 == equipe[0 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[2 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp = 1;
						equipe[2 + (4 * groupe_courant)].Pointsp = 1;
					}
					else if (match[i].score1 < match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;

					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score2;
				}
				else if (match[i].numero1 == equipe[2 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[0 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp = 1;
						equipe[2 + (4 * groupe_courant)].Pointsp = 1;
					}
					else if (match[i].score1 < match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;

					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score2;
				}
			}
		}

		equipe[0 + (4 * groupe_courant)].Differencep = equipe[0 + (4 * groupe_courant)].ButPourp - equipe[2 + (4 * groupe_courant)].ButPourp;
		equipe[2 + (4 * groupe_courant)].Differencep = equipe[2 + (4 * groupe_courant)].ButPourp - equipe[0 + (4 * groupe_courant)].ButPourp;

		sprintf(equipe[0 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[0 + (4 * groupe_courant)].Points,
		  100 + equipe[0 + (4 * groupe_courant)].Difference,
		 		equipe[0 + (4 * groupe_courant)].ButPour,
				equipe[0 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[0 + (4 * groupe_courant)].Differencep,
		 		equipe[0 + (4 * groupe_courant)].ButPourp);
				
		sprintf(equipe[2 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[2 + (4 * groupe_courant)].Points,
		  100 + equipe[2 + (4 * groupe_courant)].Difference,
		 		equipe[2 + (4 * groupe_courant)].ButPour,
				equipe[2 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[2 + (4 * groupe_courant)].Differencep,
		 		equipe[2 + (4 * groupe_courant)].ButPourp);
	}
	
	//Si 1 et 4 égal
	if (strcmp(equipe[0 + (4 * groupe_courant)].Codage, equipe[3 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[0 + (4 * groupe_courant)].Codage, equipe[1 + (4 * groupe_courant)].Codage) != 0
	 && strcmp(equipe[0 + (4 * groupe_courant)].Codage, equipe[2 + (4 * groupe_courant)].Codage) != 0)
	{
		for ( i = 0; i < 48; i++)
		{
			if (match[i].jouer == 1)
			{
				//Trouve le match en question
				if (match[i].numero1 == equipe[0 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[3 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp = 1;
						equipe[3 + (4 * groupe_courant)].Pointsp = 1;
					}
					else if (match[i].score1 < match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;

					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score2;
				}
				else if (match[i].numero1 == equipe[3 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[0 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp = 1;
						equipe[3 + (4 * groupe_courant)].Pointsp = 1;
					}
					else if (match[i].score1 < match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;

					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score2;
				}
			}
		}

		equipe[0 + (4 * groupe_courant)].Differencep = equipe[0 + (4 * groupe_courant)].ButPourp - equipe[3 + (4 * groupe_courant)].ButPourp;
		equipe[3 + (4 * groupe_courant)].Differencep = equipe[3 + (4 * groupe_courant)].ButPourp - equipe[0 + (4 * groupe_courant)].ButPourp;

		sprintf(equipe[0 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[0 + (4 * groupe_courant)].Points,
		  100 + equipe[0 + (4 * groupe_courant)].Difference,
		 		equipe[0 + (4 * groupe_courant)].ButPour,
				equipe[0 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[0 + (4 * groupe_courant)].Differencep,
		 		equipe[0 + (4 * groupe_courant)].ButPourp);
				
		sprintf(equipe[3 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[3 + (4 * groupe_courant)].Points,
		  100 + equipe[3 + (4 * groupe_courant)].Difference,
		 		equipe[3 + (4 * groupe_courant)].ButPour,
				equipe[3 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[3 + (4 * groupe_courant)].Differencep,
		 		equipe[3 + (4 * groupe_courant)].ButPourp);
	}
	
	//Si 2 et 3 égal
	if (strcmp(equipe[1 + (4 * groupe_courant)].Codage, equipe[2 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[1 + (4 * groupe_courant)].Codage, equipe[0 + (4 * groupe_courant)].Codage) != 0
	 && strcmp(equipe[1 + (4 * groupe_courant)].Codage, equipe[3 + (4 * groupe_courant)].Codage) != 0)
	{
		for ( i = 0; i < 48; i++)
		{
			if (match[i].jouer == 1)
			{
				//Trouve le match en question
				if (match[i].numero1 == equipe[1 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[2 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[1 + (4 * groupe_courant)].Pointsp = 1;
						equipe[2 + (4 * groupe_courant)].Pointsp = 1;
					}
					else if (match[i].score1 < match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;

					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score2;
				}
				else if (match[i].numero1 == equipe[2 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[1 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[1 + (4 * groupe_courant)].Pointsp = 1;
						equipe[2 + (4 * groupe_courant)].Pointsp = 1;
					}
					else if (match[i].score1 < match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;

					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score2;
				}
			}
		}

		equipe[1 + (4 * groupe_courant)].Differencep = equipe[1 + (4 * groupe_courant)].ButPourp - equipe[2 + (4 * groupe_courant)].ButPourp;
		equipe[2 + (4 * groupe_courant)].Differencep = equipe[2 + (4 * groupe_courant)].ButPourp - equipe[1 + (4 * groupe_courant)].ButPourp;

		sprintf(equipe[1 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[1 + (4 * groupe_courant)].Points,
		  100 + equipe[1 + (4 * groupe_courant)].Difference,
		 		equipe[1 + (4 * groupe_courant)].ButPour,
				equipe[1 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[1 + (4 * groupe_courant)].Differencep,
		 		equipe[1 + (4 * groupe_courant)].ButPourp);
				
		sprintf(equipe[2 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[2 + (4 * groupe_courant)].Points,
		  100 + equipe[2 + (4 * groupe_courant)].Difference,
		 		equipe[2 + (4 * groupe_courant)].ButPour,
				equipe[2 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[2 + (4 * groupe_courant)].Differencep,
		 		equipe[2 + (4 * groupe_courant)].ButPourp);
	}
	
	//Si 2 et 4 égal
	if (strcmp(equipe[1 + (4 * groupe_courant)].Codage, equipe[3 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[1 + (4 * groupe_courant)].Codage, equipe[0 + (4 * groupe_courant)].Codage) != 0
	 && strcmp(equipe[1 + (4 * groupe_courant)].Codage, equipe[2 + (4 * groupe_courant)].Codage) != 0)
	{
		for ( i = 0; i < 48; i++)
		{
			if (match[i].jouer == 1)
			{
				//Trouve le match en question
				if (match[i].numero1 == equipe[1 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[3 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[1 + (4 * groupe_courant)].Pointsp = 1;
						equipe[3 + (4 * groupe_courant)].Pointsp = 1;
					}
					else if (match[i].score1 < match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;

					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score2;
				}
				else if (match[i].numero1 == equipe[3 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[1 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[1 + (4 * groupe_courant)].Pointsp = 1;
						equipe[3 + (4 * groupe_courant)].Pointsp = 1;
					}
					else if (match[i].score1 < match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;

					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score2;
				}
			}
		}

		equipe[1 + (4 * groupe_courant)].Differencep = equipe[1 + (4 * groupe_courant)].ButPourp - equipe[3 + (4 * groupe_courant)].ButPourp;
		equipe[3 + (4 * groupe_courant)].Differencep = equipe[3 + (4 * groupe_courant)].ButPourp - equipe[1 + (4 * groupe_courant)].ButPourp;

		sprintf(equipe[1 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[1 + (4 * groupe_courant)].Points,
		  100 + equipe[1 + (4 * groupe_courant)].Difference,
		 		equipe[1 + (4 * groupe_courant)].ButPour,
				equipe[1 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[1 + (4 * groupe_courant)].Differencep,
		 		equipe[1 + (4 * groupe_courant)].ButPourp);
				
		sprintf(equipe[3 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[3 + (4 * groupe_courant)].Points,
		  100 + equipe[3 + (4 * groupe_courant)].Difference,
		 		equipe[3 + (4 * groupe_courant)].ButPour,
				equipe[3 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[3 + (4 * groupe_courant)].Differencep,
		 		equipe[3 + (4 * groupe_courant)].ButPourp);
	}
	
	//Si 3 et 4 égal
	if (strcmp(equipe[2 + (4 * groupe_courant)].Codage, equipe[3 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[2 + (4 * groupe_courant)].Codage, equipe[0 + (4 * groupe_courant)].Codage) != 0
	 && strcmp(equipe[2 + (4 * groupe_courant)].Codage, equipe[1 + (4 * groupe_courant)].Codage) != 0)
	{
		for ( i = 0; i < 48; i++)
		{
			if (match[i].jouer == 1)
			{
				//Trouve le match en question
				if (match[i].numero1 == equipe[2 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[3 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[2 + (4 * groupe_courant)].Pointsp = 1;
						equipe[3 + (4 * groupe_courant)].Pointsp = 1;
					}
					else if (match[i].score1 < match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;

					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score2;
				}
				else if (match[i].numero1 == equipe[3 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[2 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[2 + (4 * groupe_courant)].Pointsp = 1;
						equipe[3 + (4 * groupe_courant)].Pointsp = 1;
					}
					else if (match[i].score1 < match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;

					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score2;
				}
			}
		}

		equipe[2 + (4 * groupe_courant)].Differencep = equipe[2 + (4 * groupe_courant)].ButPourp - equipe[3 + (4 * groupe_courant)].ButPourp;
		equipe[3 + (4 * groupe_courant)].Differencep = equipe[3 + (4 * groupe_courant)].ButPourp - equipe[2 + (4 * groupe_courant)].ButPourp;

		sprintf(equipe[2 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[2 + (4 * groupe_courant)].Points,
		  100 + equipe[2 + (4 * groupe_courant)].Difference,
		 		equipe[2 + (4 * groupe_courant)].ButPour,
				equipe[2 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[2 + (4 * groupe_courant)].Differencep,
		 		equipe[2 + (4 * groupe_courant)].ButPourp);
				
		sprintf(equipe[3 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[3 + (4 * groupe_courant)].Points,
		  100 + equipe[3 + (4 * groupe_courant)].Difference,
		 		equipe[3 + (4 * groupe_courant)].ButPour,
				equipe[3 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[3 + (4 * groupe_courant)].Differencep,
		 		equipe[3 + (4 * groupe_courant)].ButPourp);
	}

//****Egalié à 3
	//Si 1 et 2 et 3 égal
	if (strcmp(equipe[0 + (4 * groupe_courant)].Codage, equipe[1 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[0 + (4 * groupe_courant)].Codage, equipe[2 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[0 + (4 * groupe_courant)].Codage, equipe[3 + (4 * groupe_courant)].Codage) != 0)
	{
		for ( i = 0; i < 48; i++)
		{
			if (match[i].jouer == 1)
			{
				//Trouve le match en question
				if (match[i].numero1 == equipe[0 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[1 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp ++;
						equipe[1 + (4 * groupe_courant)].Pointsp ++;
					}
					else if (match[i].score1 < match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;

					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[0 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[1 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				else if (match[i].numero1 == equipe[1 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[0 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp ++;
						equipe[1 + (4 * groupe_courant)].Pointsp ++;
					}
					else if (match[i].score1 < match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;

					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[1 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[0 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				
				if (match[i].numero1 == equipe[0 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[2 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp ++;
						equipe[2 + (4 * groupe_courant)].Pointsp ++;
					}
					else if (match[i].score1 < match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;

					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[0 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[2 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				else if (match[i].numero1 == equipe[2 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[0 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp ++;
						equipe[2 + (4 * groupe_courant)].Pointsp ++;
					}
					else if (match[i].score1 < match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;

					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[2 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[0 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				
				if (match[i].numero1 == equipe[1 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[2 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[1 + (4 * groupe_courant)].Pointsp ++;
						equipe[2 + (4 * groupe_courant)].Pointsp ++;
					}
					else if (match[i].score1 < match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;

					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[1 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[2 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				else if (match[i].numero1 == equipe[2 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[1 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[1 + (4 * groupe_courant)].Pointsp ++;
						equipe[2 + (4 * groupe_courant)].Pointsp ++;
					}
					else if (match[i].score1 < match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;

					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[2 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[1 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
			}
		}

		sprintf(equipe[0 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[0 + (4 * groupe_courant)].Points,
		  100 + equipe[0 + (4 * groupe_courant)].Difference,
		 		equipe[0 + (4 * groupe_courant)].ButPour,
				equipe[0 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[0 + (4 * groupe_courant)].Differencep,
		 		equipe[0 + (4 * groupe_courant)].ButPourp);
	
		sprintf(equipe[1 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[1 + (4 * groupe_courant)].Points,
		  100 + equipe[1 + (4 * groupe_courant)].Difference,
		 		equipe[1 + (4 * groupe_courant)].ButPour,
				equipe[1 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[1 + (4 * groupe_courant)].Differencep,
		 		equipe[1 + (4 * groupe_courant)].ButPourp);
	
		sprintf(equipe[2 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[2 + (4 * groupe_courant)].Points,
		  100 + equipe[2 + (4 * groupe_courant)].Difference,
		 		equipe[2 + (4 * groupe_courant)].ButPour,
				equipe[2 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[2 + (4 * groupe_courant)].Differencep,
		 		equipe[2 + (4 * groupe_courant)].ButPourp);
	}
	
	//Si 2 et 3 et 4 égal
	if (strcmp(equipe[1 + (4 * groupe_courant)].Codage, equipe[2 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[1 + (4 * groupe_courant)].Codage, equipe[3 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[1 + (4 * groupe_courant)].Codage, equipe[0 + (4 * groupe_courant)].Codage) != 0)
	{
		for ( i = 0; i < 48; i++)
		{
			if (match[i].jouer == 1)
			{
				//Trouve le match en question
				if (match[i].numero1 == equipe[1 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[2 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[1 + (4 * groupe_courant)].Pointsp++;
						equipe[2 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;

					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[1 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[2 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				else if (match[i].numero1 == equipe[2 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[1 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[1 + (4 * groupe_courant)].Pointsp++;
						equipe[2 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;

					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[2 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[1 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				
				if (match[i].numero1 == equipe[3 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[2 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[3 + (4 * groupe_courant)].Pointsp++;
						equipe[2 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;

					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[3 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[2 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				else if (match[i].numero1 == equipe[2 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[3 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[3 + (4 * groupe_courant)].Pointsp++;
						equipe[2 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;

					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[2 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[3 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				
				if (match[i].numero1 == equipe[1 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[3 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[1 + (4 * groupe_courant)].Pointsp++;
						equipe[3 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;

					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[1 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[3 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				else if (match[i].numero1 == equipe[3 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[1 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[1 + (4 * groupe_courant)].Pointsp++;
						equipe[3 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;

					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[3 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[1 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
			}
		}

		sprintf(equipe[3 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[3 + (4 * groupe_courant)].Points,
		  100 + equipe[3 + (4 * groupe_courant)].Difference,
		 		equipe[3 + (4 * groupe_courant)].ButPour,
				equipe[3 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[3 + (4 * groupe_courant)].Differencep,
		 		equipe[3 + (4 * groupe_courant)].ButPourp);
	
		sprintf(equipe[1 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[1 + (4 * groupe_courant)].Points,
		  100 + equipe[1 + (4 * groupe_courant)].Difference,
		 		equipe[1 + (4 * groupe_courant)].ButPour,
				equipe[1 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[1 + (4 * groupe_courant)].Differencep,
		 		equipe[1 + (4 * groupe_courant)].ButPourp);
	
		sprintf(equipe[2 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[2 + (4 * groupe_courant)].Points,
		  100 + equipe[2 + (4 * groupe_courant)].Difference,
		 		equipe[2 + (4 * groupe_courant)].ButPour,
				equipe[2 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[2 + (4 * groupe_courant)].Differencep,
		 		equipe[2 + (4 * groupe_courant)].ButPourp);
	}
	
	//Si 3 et 4 et 1 égal
	if (strcmp(equipe[2 + (4 * groupe_courant)].Codage, equipe[3 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[2 + (4 * groupe_courant)].Codage, equipe[0 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[2 + (4 * groupe_courant)].Codage, equipe[1 + (4 * groupe_courant)].Codage) != 0)
	{
		for ( i = 0; i < 48; i++)
		{
			if (match[i].jouer == 1)
			{
				//Trouve le match en question
				if (match[i].numero1 == equipe[2 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[3 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[2 + (4 * groupe_courant)].Pointsp++;
						equipe[3 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;

					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[2 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[3 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				else if (match[i].numero1 == equipe[3 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[2 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[3 + (4 * groupe_courant)].Pointsp++;
						equipe[2 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;

					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[3 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[2 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				
				if (match[i].numero1 == equipe[0 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[2 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp++;
						equipe[2 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;

					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[0 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[2 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				else if (match[i].numero1 == equipe[2 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[0 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[2 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp++;
						equipe[2 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;

					equipe[2 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[2 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[0 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				
				if (match[i].numero1 == equipe[0 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[3 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp++;
						equipe[3 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;

					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[0 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[3 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				else if (match[i].numero1 == equipe[3 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[0 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp++;
						equipe[3 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;

					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[3 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[0 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
			}
		}

		sprintf(equipe[3 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[3 + (4 * groupe_courant)].Points,
		  100 + equipe[3 + (4 * groupe_courant)].Difference,
		 		equipe[3 + (4 * groupe_courant)].ButPour,
				equipe[3 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[3 + (4 * groupe_courant)].Differencep,
		 		equipe[3 + (4 * groupe_courant)].ButPourp);
	
		sprintf(equipe[0 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[0 + (4 * groupe_courant)].Points,
		  100 + equipe[0 + (4 * groupe_courant)].Difference,
		 		equipe[0 + (4 * groupe_courant)].ButPour,
				equipe[0 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[0 + (4 * groupe_courant)].Differencep,
		 		equipe[0 + (4 * groupe_courant)].ButPourp);
	
		sprintf(equipe[2 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[2 + (4 * groupe_courant)].Points,
		  100 + equipe[2 + (4 * groupe_courant)].Difference,
		 		equipe[2 + (4 * groupe_courant)].ButPour,
				equipe[2 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[2 + (4 * groupe_courant)].Differencep,
		 		equipe[2 + (4 * groupe_courant)].ButPourp);
	}
	
	//Si 2 et 4 et 1 égal
	if (strcmp(equipe[3 + (4 * groupe_courant)].Codage, equipe[0 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[3 + (4 * groupe_courant)].Codage, equipe[1 + (4 * groupe_courant)].Codage) == 0
	 && strcmp(equipe[3 + (4 * groupe_courant)].Codage, equipe[2 + (4 * groupe_courant)].Codage) != 0)
	{
		for ( i = 0; i < 48; i++)
		{
			if (match[i].jouer == 1)
			{
				//Trouve le match en question
				if (match[i].numero1 == equipe[2 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[3 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[1 + (4 * groupe_courant)].Pointsp++;
						equipe[3 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;

					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[1 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[3 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				else if (match[i].numero1 == equipe[3 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[1 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[3 + (4 * groupe_courant)].Pointsp++;
						equipe[1 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;

					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[3 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[1 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				
				if (match[i].numero1 == equipe[0 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[1 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp++;
						equipe[1 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;

					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[0 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[1 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				else if (match[i].numero1 == equipe[1 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[0 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[1 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp++;
						equipe[1 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;

					equipe[1 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[1 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[0 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				
				if (match[i].numero1 == equipe[0 + (4 * groupe_courant)].numero &&
					match[i].numero2 == equipe[3 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp++;
						equipe[3 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;

					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[0 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[3 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
				else if (match[i].numero1 == equipe[3 + (4 * groupe_courant)].numero &&
						 match[i].numero2 == equipe[0 + (4 * groupe_courant)].numero)
				{
					if (match[i].score1 > match[i].score2) equipe[3 + (4 * groupe_courant)].Pointsp = 3;
					else if (match[i].score1 == match[i].score2)
					{
						equipe[0 + (4 * groupe_courant)].Pointsp++;
						equipe[3 + (4 * groupe_courant)].Pointsp++;
					}
					else if (match[i].score1 < match[i].score2) equipe[0 + (4 * groupe_courant)].Pointsp = 3;

					equipe[3 + (4 * groupe_courant)].ButPourp += match[i].score1;
					equipe[0 + (4 * groupe_courant)].ButPourp += match[i].score2;
					
					equipe[3 + (4 * groupe_courant)].Differencep += match[i].score1 - match[i].score2;
					equipe[0 + (4 * groupe_courant)].Differencep += match[i].score2 - match[i].score1;
				}
			}
		}

		sprintf(equipe[3 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[3 + (4 * groupe_courant)].Points,
		  100 + equipe[3 + (4 * groupe_courant)].Difference,
		 		equipe[3 + (4 * groupe_courant)].ButPour,
				equipe[3 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[3 + (4 * groupe_courant)].Differencep,
		 		equipe[3 + (4 * groupe_courant)].ButPourp);
	
		sprintf(equipe[0 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[0 + (4 * groupe_courant)].Points,
		  100 + equipe[0 + (4 * groupe_courant)].Difference,
		 		equipe[0 + (4 * groupe_courant)].ButPour,
				equipe[0 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[0 + (4 * groupe_courant)].Differencep,
		 		equipe[0 + (4 * groupe_courant)].ButPourp);
	
		sprintf(equipe[1 + (4 * groupe_courant)].Codage, "%d%03d%02d%d%03d%02d",
		 		equipe[1 + (4 * groupe_courant)].Points,
		  100 + equipe[1 + (4 * groupe_courant)].Difference,
		 		equipe[1 + (4 * groupe_courant)].ButPour,
				equipe[1 + (4 * groupe_courant)].Pointsp,
		  100 + equipe[1 + (4 * groupe_courant)].Differencep,
		 		equipe[1 + (4 * groupe_courant)].ButPourp);
	}
}


void tri_alphabetique(char *tableau[], int taille)
{
	char *temp;
	int x, y;

	for (x = 0; x < taille; x++)
	{
		for (y = 0; y < taille; y++)
		{
			if (strcmp(tableau[x], tableau[y]) < 0)
			{
				temp = tableau[x];
				tableau[x] = tableau[y];
				tableau[y] = temp;
			}
		}
	}
}


void CalculStats()
{
	//PTS & DIFF
	for ( j = 0; j < 32; j++)
	{
		equipe[j].Points = 0;
		equipe[j].Difference = 0;
		equipe[j].Joue = 0;
		equipe[j].Gagne = 0;
		equipe[j].Nul = 0;
		equipe[j].Perdu = 0;
		equipe[j].ButPour = 0;
		equipe[j].ButContre = 0;
	}

	for ( i = 0; i < 48; i++)
	{
		if (match[i].jouer == 1)
		{
			for ( j = 0; j < 32; j++)
			{
				//JOUER
				if (match[i].numero1 == equipe[j].numero)
				{
					equipe[j].Joue++;
					if (match[i].score1 > match[i].score2) equipe[j].Gagne++;
					if (match[i].score1 == match[i].score2) equipe[j].Nul++;
					if (match[i].score1 < match[i].score2) equipe[j].Perdu++;
					equipe[j].ButPour += match[i].score1;
					equipe[j].ButContre += match[i].score2;
				}

				if (match[i].numero2 == equipe[j].numero)
				{
					equipe[j].Joue++;
					if (match[i].score2 > match[i].score1) equipe[j].Gagne++;
					if (match[i].score2 == match[i].score1) equipe[j].Nul++;
					if (match[i].score2 < match[i].score1) equipe[j].Perdu++;
					equipe[j].ButPour += match[i].score2;
					equipe[j].ButContre += match[i].score1;
				}
			}
		}
	}

	//PTS & DIFF
	for ( j = 0; j < 32; j++)
	{
		equipe[j].Points = (equipe[j].Gagne * 3) + equipe[j].Nul;
		equipe[j].Difference = equipe[j].ButPour - equipe[j].ButContre;
	}
}

void Init_Bug()
{
	for (groupe_courant = 0; groupe_courant < 8; groupe_courant++)
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

	}
}


