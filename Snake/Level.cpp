#include "stdafx.h"
#include "addons.h"
#include "structures.h"

Level::Level(std::string link){
    std::vector<std::string> mapka;
    if(link != ""){
        std::ifstream file_box(link, std::ios_base::in);
        if(!(file_box.is_open())){
            error = 0x01;//не удалось открыть файл
            return;
        }else{
            std::string str;
            while(!(file_box.eof())){
                getline(file_box, str);
                mapka.push_back(str);
            }
            file_box.close();
        }
    }else{
        mapka.resize(18);
        mapka[0] =  "11111111111111111111111111111111111111111";
        for(uint8_t i=1; i<17; ++i){
            mapka[i] =  "11000000000000000000000000000000000000011";
        }
        mapka[17] = "11111111111111111111111111111111111111111";
    }
    this->analys(mapka);
}

void Level::analys(std::vector<std::string> &mapka){

}


Level::~Level(void){

}
