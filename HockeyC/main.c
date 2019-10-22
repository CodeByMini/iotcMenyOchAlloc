#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "safeinput.h"
#include <stdbool.h>

typedef struct
{
	char name[50];
	int jerseynumber;
	long salary;
} PLAYER;


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

void Add(int x)
{
	x = x+ 1;
}


int main()
{
	int x = 13;
	Add(x);
	printf("%d", x);

	SYSTEM_STATE state;
	state.allaSpelare = NULL;
	state.AntalSpelare = 0;
	Huvudmeny(&state);

	return 0;
}

