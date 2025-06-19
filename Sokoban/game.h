#pragma once

#include <iostream>
#include <string>
#include <cstdlib> // Для функции system("cls") - очистка экрана
#include <conio.h> // Для функции _getch() - чтение символа с клавиатуры без отображения на экране
#include <fstream> // Для записи и чтения данных в отдельный файл и из него

#include <locale>

using namespace std;

extern int Rows, Cols, PlayerRow, PlayerCol, WinRow, WinCol;
extern int** Level;

void InitLevel();
void Level_1();
void Level_2();
void Level_3();
void Level_4();
void RestartLevel();
void Gameplay();
void PrintLevel();
bool CanMove(int row, int col);
void ExitStatus();
bool CheckWin();
void MovePlayer();
void StepPlayer(int dRow, int dCol);
void ClearLevelMemory();