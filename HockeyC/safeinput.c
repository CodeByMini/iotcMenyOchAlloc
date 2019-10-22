#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "safeinput.h"

bool GetInputInt(char* prompt, int* value)
{
	char buff[255];
	if (GetInput(prompt, buff, sizeof(buff)) != INPUT_RESULT_OK)
		return false;
	long l = LONG_MIN;

	l = strtol(buff, NULL, 10);
	if (l == LONG_MIN) return false;
	*value = l;
	return true;
}


bool GetInputFloat(char* prompt, float* value)
{
	char buff[255];
	if (GetInput(prompt, buff, sizeof(buff)) != INPUT_RESULT_OK)
		return false;
	float l = -100000000.0f;

	l = strtof(buff, NULL, 10);
	if (l == -100000000.0f) return false;
	*value = l;
	return true;
}


bool GetInputChar(char* prompt, char* value)
{
	char buff[255];
	if (GetInput(prompt, buff, sizeof(buff)) != INPUT_RESULT_OK)
		return false;
	*value = buff[0];
	return true;
}


INPUT_RESULT GetInput(char* prompt, char* buff, int maxSize)
{

	if (prompt != NULL && strlen(prompt) > 0)
	{
		printf("%s", prompt);
	}
	if (fgets(buff, maxSize, stdin) == NULL)
		return INPUT_RESULT_NO_INPUT;

	// If it was too long, there'll be no newline. In that case, we flush
	// to end of line so that excess doesn't affect the next call.
	if (buff[strlen(buff) - 1] != '\n') {
		int extra = 0;
		char ch;
		while (((ch = getchar()) != '\n') && (ch != EOF))
			extra = 1;
		return (extra == 1) ? INPUT_RESULT_TOO_LONG : INPUT_RESULT_OK;
	}

	// Otherwise remove newline and give string back to caller.
	buff[strlen(buff) - 1] = '\0';
	return INPUT_RESULT_OK;
}



