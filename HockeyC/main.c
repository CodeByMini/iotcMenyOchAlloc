#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "safeinput.h"
#include <stdbool.h>
#include <time.h>

#include "player.h"




typedef struct
{
	PLAYER* allaSpelare;
	int AntalSpelare;
}SYSTEM_STATE;



void ListPlayers(SYSTEM_STATE *state)
{
	printf("LIST ALL PLAYERS");
	for (int i = 0; i < state->AntalSpelare; i++)
	{
		PLAYER p = state->allaSpelare[i];
		printf("%s %d %ld", p.name, p.jerseynumber, p.salary);
	}
	getch();
}

void NySpelare(SYSTEM_STATE *state)
{
	printf("NY SPELARE");

	int indexForTheNewOne;
	if (state->AntalSpelare == 0)
	{
		state->allaSpelare = malloc(sizeof(PLAYER));
		state->AntalSpelare = 1;
		indexForTheNewOne = 0;
		//state.AntalSpelare[0] är den vi ska lägga in nya data på
	}
	else
	{
		state->allaSpelare = realloc(state->allaSpelare,
			sizeof(PLAYER) * (state->AntalSpelare + 1));
		indexForTheNewOne = state->AntalSpelare;
		state->AntalSpelare++;
	}


	GetInput("NAMN", state->allaSpelare[indexForTheNewOne].name,
		sizeof(state->allaSpelare[indexForTheNewOne].name));

	int jersey;
	GetInputInt("Jersey", &jersey);
	state->allaSpelare[indexForTheNewOne].jerseynumber = jersey;


	printf("Press key to continue");
	getch();

}

void ChangeSpelare()
{
	printf("CHANGE SPELARE");
	printf("Press key to continue");
	getch();

}

void Admin(SYSTEM_STATE *state)
{
	while (true)
	{
		printf("***ADMIN***\n");
		printf("1. Ny spelare\n2. Change spelare\n3. Tillbaka\n");
		int selection;
		if (!GetInputInt("Ange val:>", &selection))
			continue;
		switch (selection)
		{
		case 1:
			NySpelare(state);
			break;
		case 2:
			ChangeSpelare();
			break;
		case 3:
			return;
		}
	}

}


void Huvudmeny(SYSTEM_STATE *state)
{
	while (true)
	{
		printf("***HOCKEYMENYN***\n");
		printf("1. Lista spelare\n2. Admin\n3. Avsluta\n");
		int selection;
		if (GetInputInt("Ange val:>", &selection) == false)
			continue;
		switch (selection)
		{
		case 1:
			ListPlayers(state);
			break;
		case 2:
			Admin(state);
			break;
		case 3:
			return 0;
		}

	}

}


void RunOneOfMats()
{
	//Kanske slumpa ??
	//if(----)
	//	Blink("Hello")
	//if(----)
	//	Scroll("There")
}

void RunOneOfFoppas()
{
	
}

void RunOneOfJorgens()
{
	
}

void HandleWinning(PLAYER winning)
{
	if (!strcmp(winning.name, "Mats Sundin"))
		RunOneOfMats();
	if (!strcmp(winning.name, "Peter Forsberg"))
		RunOneOfFoppas();
	if (!strcmp(winning.name, "Jörgen Jönsson"))
		RunOneOfJorgens();
}

int main()
{
	////Två funk med samma namn Julia
	////typedef circulär...eller ännu bättre header only!  
	//Test2('w', 12);
	//SYSTEM_STATE state;
	//state.allaSpelare = NULL;
	//state.AntalSpelare = 0;


	PLAYER p;
	p.jerseynumber = 13;
	strcpy(p.name, "Mats Sundin");
	p.salary = 123;
	p.AntalLotter = 500; // 0- 500

	PLAYER p2;
	p2.jerseynumber = 21;
	strcpy(p2.name, "Peter Forsberg");
	p2.salary = 123;
	p2.AntalLotter = 1000; // 501-1500


	PLAYER p3;
	p3.jerseynumber = 21;
	strcpy(p3.name, "Jörgen Jönsson");
	p3.salary = 2;
	p3.AntalLotter = 100; //1501-1600

	PLAYER	 customers[3];
	customers[0] = p;
	customers[1] = p2;
	customers[2] = p3;
	int summaAntalLotter = 0;

	for (int i = 0; i < 3; i++)
		summaAntalLotter += customers[i].AntalLotter;
	
	srand(time(NULL));
	int r = rand() % summaAntalLotter;

	//Loopa för att se vem som innehar den lotten

	//När vi fått fram vem som har lotten
	int i = 2; //Låt oss säga att det blev 2
	PLAYER winning = customers[i];
	HandleWinning(winning);
	
	
	//Huvudmeny(&state);

	return 0;
}

