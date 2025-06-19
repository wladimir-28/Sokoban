#pragma once

#include <iostream>
#include <string>
#include <cstdlib> // Для функции system("cls") - очистка экрана
#include <conio.h> // Для функции _getch() - чтение символа с клавиатуры без отображения на экране
#include <fstream> // Для записи и чтения данных в отдельный файл и из него

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