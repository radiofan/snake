#include "stdafx.h"
#include "addons.h"
#include "structures.h"


//CRITICAL_SECTION sc;


coord operator+ (const coord &c1, const coord &c2){
    return coord(c1.x + c2.x, c1.y + c2.y);
}

coord operator- (const coord &c1, const coord &c2){
    return coord(c1.x - c2.x, c1.y - c2.y);
}

bool operator== (const coord &c1, const coord &c2){
    return (c1.x == c2.x) && (c1.y == c2.y);
}


int _tmain(int argc, _TCHAR* argv[]){
    //std::ios_base::sync_with_stdio(false);
    //InitializeCriticalSection(&sc);
    SetConsoleCP(866);
	SetConsoleOutputCP(866);
    
    Game game;

	return game.exec();
    
    /*
    system("color 17");//Основной набор синий белый
    //system("color 20");//трава зеленый стена черный
    //ягодка лиловый(5), змея(9, 4, A, B, E, F)
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

