#include "game.h"
#include "menu.h"

int main()
{
    setlocale(LC_ALL, "Rus"); //Для отображения кириллицы в VS
    
    
    InitGame();
    while (GameRunning) 
    {
        switch (GameState) 
        {
            case MAIN_MENU:       MainMenu();           break;
            case LEVEL_SELECT:    SelectLevelMenu();    break;
            case GAMEPLAY:        Gameplay();           break; 
            case OPTION:          OptionMenu();         break;
            case EXIT:            GameRunning = false;  break;
        }
    }

    SaveProgress();
    system("cls");
    cout << "До новых встреч!" << endl;
    system("pause");
}
