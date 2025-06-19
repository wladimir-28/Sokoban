#include "game.h"
#include "menu.h"

int Rows, Cols, PlayerRow, PlayerCol, WinRow, WinCol;
int** Level = nullptr;

void InitLevel()
{
    system("cls");

    switch (GameCurrentLevel)
    {
        case 1:
            Level_1();
            break;

        case 2:
            Level_2();
            break;

        case 3:
            Level_3();
            break;

        /*case 4:
            Level_4();
            break;

        case 5:
            Level_5();
            break;

        case 6:
            Level_6();
            break;

        case 7:
            Level_7();
            break;

        case 8:
            Level_8();
            break;

        case 9:
            Level_9();
            break;

        case 10:
            Level_10();
            break;

        case 11:
            Level_11();
            break;*/
    }
}

void Level_1()
{
    Rows = 5, Cols = 5;
    PlayerRow = 1, PlayerCol = 1; 
    WinRow = 3, WinCol = 4;

    // 0 - пустое поле, 1 - стена, 2 - игрок, 3 - ящик, 4 - кнопка, 5 - игрок на кнопке, 6 - ящик на кнопке
    Level = new int* [Rows];
    Level[0] = new int[Cols] {1, 1, 1, 1, 1};
    Level[1] = new int[Cols] {1, 2, 0, 0, 1};
    Level[2] = new int[Cols] {1, 0, 3, 4, 1};
    Level[3] = new int[Cols] {1, 0, 0, 0, 1};
    Level[4] = new int[Cols] {1, 1, 1, 1, 1};
}

void Level_2()
{
    Rows = 6, Cols = 6;         
    PlayerRow = 1, PlayerCol = 1;
    WinRow = 5, WinCol = 1;

    // 0 - пустое поле, 1 - стена, 2 - игрок, 3 - ящик, 4 - кнопка, 5 - игрок на кнопке, 6 - ящик на кнопке
    Level = new int* [Rows];
    Level[0] = new int[Cols] {1, 1, 1, 1, 0, 0};
    Level[1] = new int[Cols] {1, 2, 0, 1, 1, 1},
    Level[2] = new int[Cols] {1, 0, 3, 0, 0, 1};
    Level[3] = new int[Cols] {1, 0, 0, 3, 0, 1};
    Level[4] = new int[Cols] {1, 0, 1, 4, 4, 1};
    Level[5] = new int[Cols] {1, 1, 1, 1, 1, 1};
}

void Level_3()
{
    Rows = 8, Cols = 8;
    PlayerRow = 6, PlayerCol = 2;
    WinRow = 1, WinCol = 6;

    // 0 - пустое поле, 1 - стена, 2 - игрок, 3 - ящик, 4 - кнопка, 5 - игрок на кнопке, 6 - ящик на кнопке
    Level = new int* [Rows];
    Level[0] = new int[Cols] {0, 0, 1, 1, 1, 1, 1, 0};
    Level[1] = new int[Cols] {1, 1, 1, 0, 0, 0, 1, 0};
    Level[2] = new int[Cols] {1, 0, 3, 0, 1, 0, 1, 1};
    Level[3] = new int[Cols] {1, 0, 1, 0, 0, 4, 0, 1};
    Level[4] = new int[Cols] {1, 0, 4, 0, 0, 1, 0, 1};
    Level[5] = new int[Cols] {1, 1, 3, 1, 4, 3, 0, 1};
    Level[6] = new int[Cols] {0, 1, 2, 0, 0, 1, 1, 1};
    Level[7] = new int[Cols] {0, 1, 1, 1, 1, 1, 0, 0};
}

void RestartLevel()
{
    system("cls");
    InitLevel();
}

void Gameplay()
{
    while (!CheckWin() && GameState == GAMEPLAY)
    {
        PrintLevel();
        MovePlayer();
    }

    if (CheckWin())
    {
        cout << endl << "Уровень " << GameCurrentLevel << " пройден! Поздравляю, " << PlayerName << " " << endl;
        system("pause");
        if (GameCurrentLevel == UnlockedLevels && UnlockedLevels < 3)
        {
            UnlockedLevels++;
        }
        SaveProgress();
    }
    ClearLevelMemory();
    GameState = LEVEL_SELECT;
}

void PrintLevel()
{
    system("cls");
    cout << "==================== УРОВЕНЬ " << GameCurrentLevel << " ====================" << endl;
    cout << "Если все кнопки нажаты - открывается выход с уровня" << endl;
    cout << "WASD - движение, R - рестарт, ESC - возврат в меню" << endl << endl;
    CheckOpenExit();
    for (int i = 0; i < Rows; ++i) 
    {
        cout << "\t\t";
        for (int j = 0; j < Cols; ++j)
        {
            if (Level[i][j] == 0) { cout << " " << " "; }
            else if (Level[i][j] == 1) { cout << "#" << " "; }
            else if (Level[i][j] == 2 || Level[i][j] == 5) { cout << PlayerAvatar << " "; }
            else if (Level[i][j] == 3 || Level[i][j] == 6) { cout << "O" << " "; }
            else if (Level[i][j] == 4) { cout << "." << " "; }
        }
        cout << endl;
    }
}

bool CanMove(int newRow, int newCol) {
    if (newRow < 0 || newRow >= Rows || newCol < 0 || newCol >= Cols) 
    {
        return false; 
    }

    int c = Level[newRow][newCol];
    {
        return c == 0 || c == 3 || c == 4 || c == 6;
    }
}

void CheckOpenExit() //проверка открытия выхода
{
    bool check = true;
    for (int i = 0; i < Rows; ++i)
    {
        for (int j = 0; j < Cols; ++j)
        {
            if (Level[i][j] == 4) { check = false; }
        }
    }

    if (check) 
    { 
        Level[WinRow][WinCol] = 0; 
    }
    else 
    { 
        Level[WinRow][WinCol] = 1; 
    }
}

bool CheckWin() // тру это победа 
{
    return (PlayerRow == WinRow && PlayerCol == WinCol);
}

void MovePlayer()
{
    char move = tolower(_getch());
    int dCol = 0, dRow = 0;
    switch (move)
    {
        case 'a': dCol = -1; break;
        case 'd': dCol = +1; break;
        case 'w': dRow = -1; break;
        case 's': dRow = +1; break;
        case 'r': ClearLevelMemory(); RestartLevel();   return;
        case 27: GameState = LEVEL_SELECT;              return;
    }
    StepPlayer(dRow, dCol);
}

void StepPlayer (int dRow, int dCol)
{
    int newPlayer_Col = PlayerCol + dCol;
    int newPlayer_Row = PlayerRow + dRow;
    if (!CanMove(newPlayer_Row, newPlayer_Col)) { return; }

    int& current = Level[PlayerRow][PlayerCol];
    int& next = Level[newPlayer_Row][newPlayer_Col];

    // 0 - пустое поле, 1 - стена, 2 - игрок, 3 - ящик, 4 - кнопка, 5 - игрок на кнопке, 6 - ящик на кнопке
    if (next == 3 || next == 6)
    {
        int newBoxCol = newPlayer_Col + dCol;
        int newBoxRow = newPlayer_Row + dRow;

        if (CanMove(newBoxRow, newBoxCol) && Level[newBoxRow][newBoxCol] != 3 && Level[newBoxRow][newBoxCol] != 6)
        {
            if (Level[newBoxRow][newBoxCol] == 4)
            {
                Level[newBoxRow][newBoxCol] = 6;

            }
            else
            {
                Level[newBoxRow][newBoxCol] = 3;
            }

            if (next == 4)
            {
                next = 5;
            }
            else if (next == 6)
            {
                next = 5;
            }
            else
            {
                next = 2;
            }

            if (current == 5)
            {
                current = 4;
            }
            else
            {
                current = 0;
            }

            PlayerCol = newPlayer_Col;
            PlayerRow = newPlayer_Row;
        }
    }
    else
    {

        if (next == 4)
        {
            next = 5;
        }
        else
        {
            next = 2;
        }

        if (current == 5)
        {
            current = 4;
        }
        else
        {
            current = 0;
        }

        PlayerCol = newPlayer_Col;
        PlayerRow = newPlayer_Row;
    }
    
}

void ClearLevelMemory() //Очистка памяти от дин. массива уровня
{
    for (int i = 0; i < Rows; i++) 
    {
        delete[] Level[i];
    }
    Level = nullptr;
}
