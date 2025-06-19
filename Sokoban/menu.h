#pragma once

#include <iostream>
#include <string>
#include <cstdlib> // ��� ������� system("cls") - ������� ������
#include <conio.h> // ��� ������� _getch() - ������ ������� � ���������� ��� ����������� �� ������
#include <fstream> // ��� ������ � ������ ������ � ��������� ���� � �� ����

#include <locale>

using namespace std;

enum VarGameState 
{
    MAIN_MENU,
    LEVEL_SELECT,
    GAMEPLAY,
    OPTION,
    EXIT
};

extern bool GameRunning;
extern char PlayerAvatar;
extern int GameCurrentLevel, UnlockedLevels;
extern string PlayerName;
extern VarGameState GameState;

void InitGame();
void LoadProgress();
void SaveProgress();
void MainMenu();
void SelectLevelMenu();
void OptionMenu();
void ResetProgress();