#pragma once

#include <iostream>
#include <string>
#include <cstdlib> // ��� ������� system("cls") - ������� ������
#include <conio.h> // ��� ������� _getch() - ������ ������� � ���������� ��� ����������� �� ������
#include <fstream> // ��� ������ � ������ ������ � ��������� ���� � �� ����

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