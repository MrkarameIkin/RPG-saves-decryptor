#include <iostream>
#include <fstream>

void startMenu()
{
    std::cout << "\nВыберите действие:\n";
    std::cout << "1) Играть!\n";
    std::cout << "2) Настройки\n";
    std::cout << "3) Выйти\n";
}

void playMenu()
{
    std::cout << "\n1) Начать новую игру\n";
    std::cout << "2) Сохранения\n";
    std::cout << "3) Вернуться в главное меню\n";
}

void locOutput(std::string location)
{
    if(location == "MEADOW") std::cout << "Луг\n";
    else if(location == "DESERT") std::cout << "Пустыня\n";
    else if(location == "FOREST") std::cout << "Лес\n";
    else if(location == "VOLCANO") std::cout << "Вулкан\n";
    else std::cout << "Замок Лорда демонов\n";
}

void dataOutput(std::ifstream &player)
{
    std::string buffer;

    player.seekg(7);
    player >> buffer;

    std::cout << "Никнейм: " << buffer << std::endl;

    player.seekg(player.tellg() + std::streampos(8));

    player >> buffer;
    std::cout << "Уровень: " << buffer << std::endl;

    player.seekg(player.tellg() + std::streampos(7));

    player >> buffer;
    std::cout << "Золото: " << buffer << std::endl;

    player.seekg(player.tellg() + std::streampos(11));

    player >> buffer;
    std::cout << "Локация: ";
    locOutput(buffer);

    player.close();
}

void savesOutput ()
{
    std::ifstream player;

    for(int i = 0; i < 4; i++)
        {
        std::cout << "\nСохранение №" << i+1 << std::endl;
        switch(i)
        {
            case 0:
                player.open("players_saves/hero_save_1.txt", std::ios::binary);
                break;
            case 1:
                player.open("players_saves/hero_save_2.txt", std::ios::binary);
                break;
            case 2:
                player.open("players_saves/hero_save_3.txt", std::ios::binary);
                break;
            case 3:
                player.open("players_saves/hero_save_4.txt", std::ios::binary);
                break;
        }

        dataOutput(player);
    }
}

int main()
{
    char input;

    std::cout << "Приветствуем в игре Defeat the Demon Lord!\n";
    
    while(true)
    {
        startMenu();
        
        std::cout << "\n> ";
        std::cin >> input;

        if(input == '1')
        {
            while(true)
            {
                playMenu();

                std::cout << "\n> ";
                std::cin >> input;

                if(input == '1') std::cout << "\nНовая игра пока не работает( Попробуйте сыграть в одно из сохранений\n";
                else if(input == '2') savesOutput();
                else if(input == '3') break;
                else std::cout << "\nНеправильный ввод! Повторите снова\n";
            }
        }
        else if(input == '2') std::cout << "\nНастройки пока не работают( Попробуйте что-то другое\n";
        else if(input == '3') break;
        else std::cout << "\nНеправильный ввод! Повторите снова\n";
    }
}