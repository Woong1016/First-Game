#pragma once

#include <stdlib.h>
#include <Windows.h>

void PrepareBoards();
void ShuffleNumbers();

void ShowBingoBoards();

void GetInput();
void ApplyInput();

void CountBingos();
int Count_Row();
int Count_Column();
int Count_Diagonal();

void ShowGameStatus();

bool IsGameOver();

void ShowIntro();
void ShowOutro();

int bingoBoard[5][5];

int input;

int x;
int y;

int countBingo = 0;
int countToEnd = 5;