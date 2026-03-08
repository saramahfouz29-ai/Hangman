#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main() {
	
	printf("Welcome To our Game\n");
	printf("You have a right of 7 mistakes total.\n");
	char kelimeler[][15]={"apple","watermelon","grapes","mango","orange","lemon","cherry","strawberry"};
	int kelimeSaysi=8;
	
	int hataS=0;
	char tahmin;
	char gorunen[20];
	
	int i,k,s;
	int tamam;
	
	int oyunBitti=0;
	
	
	srand(time(NULL));
	int RastgeleIndix=rand() %kelimeSaysi;
	
	char kelime[15];
	strcpy(kelime,kelimeler[RastgeleIndix]);
	
	int uzunluk=strlen(kelime);
	for(i=0;i<uzunluk;i++){
		gorunen[i]='_';
	}
	gorunen[uzunluk]='\0';
	
	char girilenHarfler[30];
	int girilenSayisi = 0;
	
	while(!oyunBitti)
	{
		printf("\nFruit Name: ");
		for(i=0;i<uzunluk;i++)
		{
			printf("%c",gorunen[i]);
		}
		printf("\nGuess the letters\n");
		scanf(" %c", &tahmin);
		int zatenGirildi = 0;
		for(k = 0; k < girilenSayisi; k++) {
			if(girilenHarfler[k] == tahmin) {
				zatenGirildi = 1;
				break;
			}
		}
		
		if(zatenGirildi) {
			printf("\nYou already guessed '%c'. Try a different letter.\n", tahmin);
			continue; 
		}
		girilenHarfler[girilenSayisi] = tahmin;
		girilenSayisi++;
		int yanlis=1;
		for(k=0;k<uzunluk;k++){
			if(kelime[k]==tahmin)
			{
				gorunen[k]=tahmin;
				
				yanlis=0;
			}
		}
		if(yanlis){
			hataS++;
			printf("\nYou entered a wrong letter. You made %d mistake(s).\n", hataS);
		}
		tamam=1;
		for(s=0;s<uzunluk;s++)
		{
			if(gorunen[s]=='_')
			{
				tamam=0;
			}
		}
		if(tamam){
			printf("Congratulations");
			oyunBitti=1;
		}
		else if(hataS>=7){
			printf("\nYou Lost, The Word was %s\n",kelime);
			oyunBitti=1;
		}
	}
	
	return 0;
}
