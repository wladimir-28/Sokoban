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

        case 4:
            Level_4();
            break;
    }
}

void Level_1()
{
    Rows = 5, Cols = 5;
    PlayerRow = 1, PlayerCol = 1; 
    WinRow = 3, WinCol = 4;

    // 0 - ������ ����, 1 - �����, 2 - �����, 3 - ����, 4 - ������, 5 - ����� �� ������, 6 - ���� �� ������
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

    // 0 - ������ ����, 1 - �����, 2 - �����, 3 - ����, 4 - ������, 5 - ����� �� ������, 6 - ���� �� ������
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
    Rows = 9, Cols = 9;
    PlayerRow = 2, PlayerCol = 2;
    WinRow = 7, WinCol = 8;

    // 0 - ������ ����, 1 - �����, 2 - �����, 3 - ����, 4 - ������, 5 - ����� �� ������, 6 - ���� �� ������
    Level = new int* [Rows];
    Level[0] = new int[Cols] {0, 0, 1, 1, 1, 1, 1, 0, 0};
    Level[1] = new int[Cols] {1, 1, 1, 0, 0, 0, 1, 0, 0};
    Level[2] = new int[Cols] {1, 4, 2, 3, 0, 0, 1, 0, 0};
    Level[3] = new int[Cols] {1, 1, 1, 0, 3, 4, 1, 0, 0};
    Level[4] = new int[Cols] {1, 4, 1, 1, 3, 0, 1, 0, 0};
    Level[5] = new int[Cols] {1, 0, 1, 0, 4, 0, 1, 1, 1};
    Level[6] = new int[Cols] {1, 3, 0, 6, 3, 3, 0, 4, 1};
    Level[7] = new int[Cols] {1, 0, 0, 0, 4, 0, 0, 0, 1};
    Level[8] = new int[Cols] {1, 1, 1, 1, 1, 1, 1, 1, 1};
}

void Level_4()
{
    Rows = 8, Cols = 8;
    PlayerRow = 6, PlayerCol = 2;
    WinRow = 1, WinCol = 6;

    // 0 - ������ ����, 1 - �����, 2 - �����, 3 - ����, 4 - ������, 5 - ����� �� ������, 6 - ���� �� ������
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
        ExitStatus();
        PrintLevel();
        MovePlayer();
    }

    if (CheckWin())
    {
        if (GameCurrentLevel == MaxLevel) { cout << "��� ������ ���� ��������! ����������, " << PlayerName << " !" << endl;}
        else { cout << endl << "������� " << GameCurrentLevel << " �������!" << endl;}
        system("pause");

        if (GameCurrentLevel == UnlockedLevels && UnlockedLevels < MaxLevel)
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
    cout << "==================== ������� " << GameCurrentLevel << " ====================" << endl;
    cout << "���� ��� ������ ������ - ����������� ����� � ������" << endl;
    cout << "WASD - ��������, R - �������, ESC - ������� � ����" << endl << endl;
    
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
    int cell = Level[newRow][newCol];
    return !(newRow < 0 || newRow >= Rows || newCol < 0 || newCol >= Cols)  &&   (cell == 0 || cell == 3 || cell == 4 || cell == 6);
}

void ExitStatus() //�������� �������� ������
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

bool CheckWin()
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

    // 0 - ������ ����, 1 - �����, 2 - �����, 3 - ����, 4 - ������, 5 - ����� �� ������, 6 - ���� �� ������
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

void ClearLevelMemory() //������� ������ �� ���. ������� ������
{
    for (int i = 0; i < Rows; i++) 
    {
        delete[] Level[i];
    }
    Level = nullptr;
}
