
#include "game.h"
#include "menu.h"


bool GameRunning;
char PlayerAvatar = '@';
int GameCurrentLevel, UnlockedLevels = 1, MaxLevel = 4;
string PlayerName = "Player";
VarGameState GameState;


void InitGame()
{
    GameState = MAIN_MENU;
    GameRunning = true;
    LoadProgress();
}

void LoadProgress()
{
    ifstream file("Progress.txt");
    if (!file.is_open())
    {
        cerr << "������ �������� ����� ��� ������!" << endl;
        OptionMenu();
        return;
    }
    file >> UnlockedLevels >> PlayerAvatar;
    file.ignore();
    getline(file, PlayerName);
    file.close();
}

void SaveProgress() {
    ofstream file("Progress.txt");
    if (!file.is_open()) 
    {
        cerr << "������ �������� ����� ��� ������!" << endl;
        return;
    }
    file << UnlockedLevels << endl;
    file << PlayerAvatar << endl;
    file << PlayerName << endl;
    file.close();
}

void MainMenu()
{
    system("cls");
    cout << "================== ������� ==================" << endl;
    cout << "�������� ����� ���� �������� ������� � ������" << endl;
    cout << "1. ���������� ����" << endl;
    cout << "2. ����� ������" << endl;
    cout << "3. �������� �������� ����" << endl;
    cout << "4. �������� ��� ������ � ������" << endl;
    cout << "5. �����" << endl;

    char MainMenuItem = _getch();
    switch (MainMenuItem)
    {
        case '1':
            GameCurrentLevel = UnlockedLevels;
            InitLevel();
            GameState = GAMEPLAY;
            break;

        case '2':
            GameState = LEVEL_SELECT;
            break;

        case '3':
            ResetProgress();
            break;

        case '4':
            GameState = OPTION;
            break;

        case '5':
            GameState = EXIT;
            break;
    }
}

void SelectLevelMenu()
{
    system("cls");
    cout << "======== ����� ������ =========" << endl;

    for (int i = 1; i <= MaxLevel; i++)
    {
        cout << "�������\t" << i << (i <= UnlockedLevels ? "" : " (������������)") << endl;
    }
    cout << endl << "0 - ����� �  ������� ����" << endl << endl;

    int input;
    cout << "������� ����� ���������� ������" << endl;
    cin >> input;
    if (input == 0)
    {
        GameState = MAIN_MENU;

    }
    else if (input >= 1 && input <= MaxLevel && input <= UnlockedLevels)
    {
        GameCurrentLevel = input;
        InitLevel();
        GameState = GAMEPLAY;
    }
}

void OptionMenu()
{
    system("cls");
    cout << "��� ��� ��������? (��������� �����, ����� � �������): ";
    cin >> PlayerName;
    cout << "���� �������� ���  " << PlayerName << endl;
    cout << "������ �������� ��� ������ ��� ���� - ��������� ������, �����:" << endl <<  "������� ����, '#' - ����� , ' ' - ����, 'O' - ����� � '.' - ������" << endl;
    cin >> PlayerAvatar;
    if (PlayerAvatar == '_' || PlayerAvatar == '#' || PlayerAvatar == 'O' || PlayerAvatar == '.') //�������� �� ������������ �������
    {
        while (PlayerAvatar == '#' || PlayerAvatar == ' ' || PlayerAvatar == 'O' || PlayerAvatar == '.') 
        {
            cout << "����� '#', ' ', 'O' � '.' !" << endl;
            cin >> PlayerAvatar;
        }
    }
    SaveProgress();
    cout << "������ ������� ���������" << endl;
    system("pause");
    GameState = MAIN_MENU;
}

void ResetProgress()
{
    cout << "�� ������������� ������ �������� ���� �������� � ������ ���� ������? (y/n)" << endl;
    char ResetProgress;
    cin >> ResetProgress;
    switch (ResetProgress)
    {
        case 'n':
            break;

        case 'y':
            UnlockedLevels = 1;
            PlayerAvatar = '@';
            PlayerName = "Player";
            SaveProgress();
            OptionMenu();
            break;
    }
}