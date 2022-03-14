void sauver_sauvegarde()
{
	if (isDLDISystem)
	{
		FILE* handle = fopen(FILEGAME, "wb");
		if (handle != 0)
		{
			//LES MATCHS
			//Match groupes
			for (i = 0; i < 48; i++){
				fwrite(&match[i].score1, 1, sizeof(match[i].score1), handle);
				fwrite(&match[i].score2, 1, sizeof(match[i].score2), handle);
				fwrite(&match[i].penalty1, 1, sizeof(match[i].penalty1), handle);
				fwrite(&match[i].penalty2, 1, sizeof(match[i].penalty2), handle);
				fwrite(&match[i].jouer, 1, sizeof(match[i].jouer), handle);
			}

			//Match huitiemes
			for (i = 0; i < 8; i++){
				fwrite(&huitieme[i].score1, 1, sizeof(huitieme[i].score1), handle);
				fwrite(&huitieme[i].score2, 1, sizeof(huitieme[i].score2), handle);
				fwrite(&huitieme[i].penalty1, 1, sizeof(huitieme[i].penalty1), handle);
				fwrite(&huitieme[i].penalty2, 1, sizeof(huitieme[i].penalty2), handle);
				fwrite(&huitieme[i].jouer, 1, sizeof(huitieme[i].jouer), handle);
			}

			//Match quarts
			for (i = 0; i < 4; i++){
				fwrite(&quarts[i].score1, 1, sizeof(quarts[i].score1), handle);
				fwrite(&quarts[i].score2, 1, sizeof(quarts[i].score2), handle);
				fwrite(&quarts[i].penalty1, 1, sizeof(quarts[i].penalty1), handle);
				fwrite(&quarts[i].penalty2, 1, sizeof(quarts[i].penalty2), handle);
				fwrite(&quarts[i].jouer, 1, sizeof(quarts[i].jouer), handle);
			}

			for (i = 0; i < 2; i++){
				//Match demis
				fwrite(&demi[i].score1, 1, sizeof(demi[i].score1), handle);
				fwrite(&demi[i].score2, 1, sizeof(demi[i].score2), handle);
				fwrite(&demi[i].penalty1, 1, sizeof(demi[i].penalty1), handle);
				fwrite(&demi[i].penalty2, 1, sizeof(demi[i].penalty2), handle);
				fwrite(&demi[i].jouer, 1, sizeof(demi[i].jouer), handle);
				//Match finales
				fwrite(&finales[i].score1, 1, sizeof(finales[i].score1), handle);
				fwrite(&finales[i].score2, 1, sizeof(finales[i].score2), handle);
				fwrite(&finales[i].penalty1, 1, sizeof(finales[i].penalty1), handle);
				fwrite(&finales[i].penalty2, 1, sizeof(finales[i].penalty2), handle);
				fwrite(&finales[i].jouer, 1, sizeof(finales[i].jouer), handle);
			}

			fclose(handle);
		}
	}
}


void charger_sauvegarde()
{
	u8 erreur = 0;

	if (isDLDISystem)
	{
		FILE* handle = fopen(FILEGAME, "rb");

		if (handle != 0)
		{
			//LES MATCHS
			//Match groupes
			for (i = 0; i < 48; i++){
				fread(&match[i].score1, 1, sizeof(match[i].score1), handle);
				fread(&match[i].score2, 1, sizeof(match[i].score2), handle);
				fread(&match[i].penalty1, 1, sizeof(match[i].penalty1), handle);
				fread(&match[i].penalty2, 1, sizeof(match[i].penalty2), handle);
				fread(&match[i].jouer, 1, sizeof(match[i].jouer), handle);
			}

			//Match huitiemes
			for (i = 0; i < 8; i++){
				fread(&huitieme[i].score1, 1, sizeof(huitieme[i].score1), handle);
				fread(&huitieme[i].score2, 1, sizeof(huitieme[i].score2), handle);
				fread(&huitieme[i].penalty1, 1, sizeof(huitieme[i].penalty1), handle);
				fread(&huitieme[i].penalty2, 1, sizeof(huitieme[i].penalty2), handle);
				fread(&huitieme[i].jouer, 1, sizeof(huitieme[i].jouer), handle);
			}

			//Match quarts
			for (i = 0; i < 4; i++){
				fread(&quarts[i].score1, 1, sizeof(quarts[i].score1), handle);
				fread(&quarts[i].score2, 1, sizeof(quarts[i].score2), handle);
				fread(&quarts[i].penalty1, 1, sizeof(quarts[i].penalty1), handle);
				fread(&quarts[i].penalty2, 1, sizeof(quarts[i].penalty2), handle);
				fread(&quarts[i].jouer, 1, sizeof(quarts[i].jouer), handle);
			}

			for (i = 0; i < 2; i++){
				//Match demis
				fread(&demi[i].score1, 1, sizeof(demi[i].score1), handle);
				fread(&demi[i].score2, 1, sizeof(demi[i].score2), handle);
				fread(&demi[i].penalty1, 1, sizeof(demi[i].penalty1), handle);
				fread(&demi[i].penalty2, 1, sizeof(demi[i].penalty2), handle);
				fread(&demi[i].jouer, 1, sizeof(demi[i].jouer), handle);
				//Match finales
				fread(&finales[i].score1, 1, sizeof(finales[i].score1), handle);
				fread(&finales[i].score2, 1, sizeof(finales[i].score2), handle);
				fread(&finales[i].penalty1, 1, sizeof(finales[i].penalty1), handle);
				fread(&finales[i].penalty2, 1, sizeof(finales[i].penalty2), handle);
				fread(&finales[i].jouer, 1, sizeof(finales[i].jouer), handle);
			}

			fclose(handle);
		}
		else
		{
			erreur = 1;
		}
	}
	else
	{
		erreur = 1;
	}

	if (erreur == 1)
	{
		sauver_sauvegarde();
	}
}



