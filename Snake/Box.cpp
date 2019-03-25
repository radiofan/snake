#include "stdafx.h"
#include "addons.h"
#include "structures.h"

Box::Box(void){
}

void Box::create(map &mapka){
    boxx = mapka;
}

//дать высоту
uint32_t Box::get_h(){
    return boxx.box.size();
}

//дать ширину
uint32_t Box::get_w(){
    return boxx.box[0].size();
}

//дать €чейку
uint8_t Box::get_tile(uint32_t x, uint32_t y){
    if(x >= this->get_w() || y >= this->get_h()){
        std::cout << "ERROR: Box::get_tile(" << x << ", " << y << ") can't return result. Box_w=" 
        << this->get_w() << " Box_h=" << this->get_h() << std::endl;
        return 255;
    }else{
        return boxx.box[y][x];
    }
}

//дать ссылку на карту
map &Box::get_box(){
    return boxx;
}


Box::~Box(void){

}
