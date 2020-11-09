//#pragma once

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED 1

typedef struct
{
	char name[50];
	int jerseynumber;
	long salary;
	int AntalLotter;
} PLAYER;



int GetAdjustedSalaryForPlayer(PLAYER p);
#endif