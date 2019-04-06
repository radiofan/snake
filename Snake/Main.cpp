#include "stdafx.h"
#include "addons.h"
#include "structures.h"


CRITICAL_SECTION sc;

int _tmain(int argc, _TCHAR* argv[]){
    //std::ios_base::sync_with_stdio(false);
    InitializeCriticalSection(&sc);
    SetConsoleCP(866);
	SetConsoleOutputCP(866);
    
    Game game;

	return game.exec();
    
    /*
    system("color 17");//ќсновной набор синий белый
    //system("color 20");//трава зеленый стена черный
    //€годка желтый(e), зме€(9, 4, A, B, E, F)
    //std::ifstream file_box("resurses/level0.lvl", std::ios_base::in);
    std::ifstream file_box("resurses/menu.txt", std::ios_base::in);
    std::vector<std::string> pole;
    if(!(file_box.is_open())){
        std::cout << "not open" << std::endl;
    }else{
        std::string str;
        while (!(file_box.eof())){
            getline(file_box, str);
            pole.push_back(str);
        }
        file_box.close();
    }

    for(uint8_t i = 0; i<pole.size(); ++i){
        std::cout << pole[i] << std::endl;
    }

    system("pause");

    return 0;*/
}

