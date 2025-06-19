
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
        cerr << "Ошибка открытия файла для чтения!" << endl;
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
        cerr << "Ошибка открытия файла для записи!" << endl;
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
    cout << "================== СОКОБАН ==================" << endl;
    cout << "Выберите пункт меню нажатием клавиши с цифрой" << endl;
    cout << "1. Продолжить игру" << endl;
    cout << "2. Выбор уровня" << endl;
    cout << "3. Сбросить прогресс игры" << endl;
    cout << "4. Поменять имя игрока и аватар" << endl;
    cout << "5. Выйти" << endl;

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
    cout << "======== ВЫБОР УРОВНЯ =========" << endl;

    for (int i = 1; i <= MaxLevel; i++)
    {
        cout << "Уровень\t" << i << (i <= UnlockedLevels ? "" : " (заблокирован)") << endl;
    }
    cout << endl << "0 - Выйти в  главное меню" << endl << endl;

    int input;
    cout << "Введите номер выбранного уровня" << endl;
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
    cout << "Как Вас называть? (Латинские буквы, цифры и символы): ";
    cin >> PlayerName;
    cout << "Буду называть Вас  " << PlayerName << endl;
    cout << "Теперь выберите ваш аватар для игры - одиночный символ, кроме:" << endl <<  "русских букв, '#' - стены , ' ' - поля, 'O' - ящика и '.' - кнопки" << endl;
    cin >> PlayerAvatar;
    if (PlayerAvatar == '_' || PlayerAvatar == '#' || PlayerAvatar == 'O' || PlayerAvatar == '.') //Проверка на допустимость символа
    {
        while (PlayerAvatar == '#' || PlayerAvatar == ' ' || PlayerAvatar == 'O' || PlayerAvatar == '.') 
        {
            cout << "КРОМЕ '#', ' ', 'O' и '.' !" << endl;
            cin >> PlayerAvatar;
        }
    }
    SaveProgress();
    cout << "Данные профиля сохранены" << endl;
    system("pause");
    GameState = MAIN_MENU;
}

void ResetProgress()
{
    cout << "Вы действительно хотите сбросить ВЕСЬ прогресс и начать игру заново? (y/n)" << endl;
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