#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "safeinput.h"
#include <stdbool.h>



typedef struct
{
	int jerseyNumber;
	char namn[250];
	char city[100];
	char team[45];
	int salary;
}PLAYER;


void printPlayer(PLAYER p)
{
	printf("%d  %s  salary:%d\n", p.jerseyNumber, p.namn, 
		p.salary);
}

int main324234()
{
	int i;
	i = 12;
	char aa[100];
	float f;
	PLAYER p;
	p.jerseyNumber = 13;
	p.salary = 1000;
	strcpy(p.namn , "Mats Sundin");
	
	PLAYER p2;
	p2.jerseyNumber = 21;
	p2.salary = 1000;
	strcpy(p2.namn, "Peter Forsberg");

	printPlayer(p);
	printPlayer(p2);

	PLAYER teamPlayers[10];
	int antalPlayers = 0;

	teamPlayers[antalPlayers] = p;
	antalPlayers++;
	
	teamPlayers[antalPlayers] = p2;
	antalPlayers++;
	
	for(int i = 0;i < antalPlayers;i++)
	{
		printPlayer(teamPlayers[i]);
	}

	//för varje spelare namn, jersey, salary
	//listOfPlayers = []
	//
	
}
