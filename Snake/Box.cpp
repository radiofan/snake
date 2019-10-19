#include "stdafx.h"
#include "addons.h"
#include "structures.h"

Box::Box(void){
}

/*
* 0 - �������
* 1 - �����
* 2 - �����, ���������� �����
* 3 - �����, ���������� ������
* 4 - �����, ���������� ����
* 5 - �����, ���������� �����
*/
void Box::create(map &mapka){
    box = mapka;
}

void Box::create(std::vector<String> &mapka){
    uint16_t h = mapka.size();
    uint16_t w = mapka[0].length();
    box.resize(h);
    for(uint16_t y=0; y<h; y++){
        box[y].resize(w);
        for(uint16_t x=0; x<w; x++){
            if(mapka[y][x] == '1'){
                box[y][x] = 1;
            }else{
                box[y][x] = 0;
            }
        }
    }
}

//���� ������
uint16_t Box::get_h(){
    return box.size();
}

//���� ������
uint16_t Box::get_w(){
    return box[0].size();
}

//���� ������
uint8_t Box::get_tile(uint16_t x, uint16_t y){
    if(x >= this->get_w() || y >= this->get_h()){
        std::cout << "ERROR: Box::get_tile(" << x << ", " << y << ") can't return result. Box_w=" 
        << this->get_w() << " Box_h=" << this->get_h() << std::endl;
        system("pause");
        return 255;
    }else{
        return box[y][x];
    }
}

//���� ������ �� �����
map &Box::get_box(){
    return box;
}


Box::~Box(void){

}
