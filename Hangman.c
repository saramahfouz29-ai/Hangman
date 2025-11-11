#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main() {
	
	printf("Welcome To our Game\n");
	printf("You have a right of 7 mistakes total.\n");
	char kelimeler[][15]={"apple","watermelon","grapes","mango","orange","lemon","cherry","strawberry"};
	int kelimeSaysi=8;
	int yanlis=1;
	int hataS=0;
	char tahmin;
	char gorunen[20];
	int dogruS;
	int i,j,k,s;
	int tamam;
	
	int oyunBitti=0;
	int tamamlandi;
	
	srand(time(NULL));
	int RastgeleIndix=rand() %kelimeSaysi;
	
	char kelime[15];
	strcpy(kelime,kelimeler[RastgeleIndix]);
	
	int uzunluk=strlen(kelime);
	for(i=0;i<uzunluk;i++){
		gorunen[i]='_';
	}
	gorunen[uzunluk]='\0';
	
	while(!oyunBitti)
	{
		printf("Fruit Name: ");
		for(i=0;i<uzunluk;i++)
		{
			printf("%c",gorunen[i]);
		}
		printf("Guess the letters\n");
		scanf(" %c", &tahmin);
		for(k=0;k<uzunluk;k++){
			if(kelime[k]==tahmin)
			{
				gorunen[k]=tahmin;
				dogruS++;
				yanlis=0;
			}
		}
		if(yanlis){
			hataS++;
			printf("You entered a wrong letter, You made %d mistake",hataS);
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
			printf("Congratiolations");
			oyunBitti=1;
		}
		else if(hataS>=7){
			printf("You Lost, The Word was %s",kelime);
			oyunBitti=1;
		}
	}
	
	return 0;
}
