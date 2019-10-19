#include "stdafx.h"
#include "addons.h"
#include "structures.h"


Snake::Snake(int16_t &colour)
    :color(colour), ready(false){}

Snake::Snake(int8_t orientation, int16_t &colour)
    :color(colour), orient(0), ready(false){
    this->set_orient(orientation);
}


bool Snake::set_orient(int8_t orientation){
    if(orientation >= 0 && orientation <= 3){
        orient = orientation;
        return true;
    }
    std::cout << "Snake::set_orient() получила неверный аргумент: " << orientation << std::endl;
    system("pause");
    return false;
}

bool Snake::set_start(coord place, int8_t orientation){
    char or;
    switch(orientation){
        case 0:
        case 2:
            or = '║';
            break;
        case 1:
        case 3:
            or = '═';
            break;
        default:
            std::cout << "Snake::set_start() получила неверный аргумент: " << orientation << std::endl;
            system("pause");
            return false;
    }

    angles.push_back(snake_piece(place, or));
    angles.push_back(snake_piece(place, or));
    orient = orientation;
    ready = true;
    return ready;
}

void Snake::angles_reserve(uint32_t reserve){
    angles.reserve(reserve);
}

void Snake::clear(){
    orient = -1;
    angles.resize(0);
    ready = false;
}


bool Snake::is_ready(){
    return ready;
}


int16_t Snake::get_color(){
    return color;
}

snake_slice Snake::get_snake_slice(coord place){
    snake_slice ret(0, -1);
    for(uint32_t i=angles.size()-1; i>0; i--){
        ret.len = -1;
        ret.symb = 0;
        coord result = angles[i].location - angles[i-1].location;
        if(result.x != 0){
            if(place.y != angles[i].location.y)
                continue;
            //true - между i и i-1
            bool draw = true;
            //горизонтальный участок
            switch(angles[i].symb){
                case '╔':
                case '╚':
                    if(result.x > 0)
                        draw = false;
                    break;
                case '╗':
                case '╝':
                    if(result.x < 0)
                        draw = false;
                    break;
                case '═':
                    if((result.x > 0 && orient == 3) || (result.x < 0 && orient == 1))
                        draw = false;
                    break;

            }
            int8_t sign = result.x/abs(result.x);
            int8_t ind1 = (sign + 1)/(-2);
            int8_t ind2 = (sign - 1)/2;
            //if(sign == -1){
            //  ind1 = 0;
            //  ind2 = -1;
            //}else if(sign == 1){
            //  ind1 = -1;
            //  ind2 = 0;
            //}
            if(place.x == angles[i].location.x){
                 ret.symb = angles[i].symb;
            }else if(place.x == angles[i-1].location.x){
                 ret.symb = angles[i-1].symb;
            }else{
                 ret.symb = '═';
            }
            if(draw){
                //Если sign = 1 то place.x должен быть больше [i-1] и меньше [i]
                //___i-1____x___i____
                //Если sign = -1 то place.x должен быть больше [i] и меньше [i-1]
                //___i______x___i-1__
                if(place.x >= angles[i+ind1].location.x && place.x <= angles[i+ind2].location.x){
                    ret.len = angles[i+ind2].location.x - place.x + 1;
                    return ret;
                }
            }else{
                //Если sign = 1 то place.x должен быть не меньше [i] и не больше [i-1]
                //_x___i-1____i____x_
                //Если sign = -1 то place.x должен быть не меньше [i-1] и не больше [i]
                //__x__i___i-1___x___
                if(!(place.x < angles[i+ind2].location.x && place.x > angles[i+ind1].location.x)){
                    if(place.x <= angles[i+ind1].location.x){
                        ret.len = angles[i+ind1].location.x - place.x + 1;
                    }else{
                        ret.len = -2;//до конца поля
                    }
                    return ret;
                }
            }
        }else if(result.y != 0){
            //вертикальный участок
            if(place.x != angles[i].location.x)
                continue;

            //true - между i и i-1
            bool draw = true;
            //горизонтальный участок
            switch(angles[i].symb){
                case '╝':
                case '╚':
                    if(result.y < 0)
                        draw = false;
                    break;
                case '╗':
                case '╔':
                    if(result.y > 0)
                        draw = false;
                    break;
                case '║':
                    if((result.y > 0 && orient == 0) || (result.y < 0 && orient == 2))
                        draw = false;
                    break;

            }

            int8_t sign = result.y/abs(result.y);
            int8_t ind1 = (sign + 1)/(-2);
            int8_t ind2 = (sign - 1)/2;
            //if(sign == -1){
            //  ind1 = 0;
            //  ind2 = -1;
            //}else if(sign == 1){
            //  ind1 = -1;
            //  ind2 = 0;
            //}

            if(place.y == angles[i].location.y){
                 ret.symb = angles[i].symb;
            }else if(place.y == angles[i-1].location.y){
                 ret.symb = angles[i-1].symb;
            }else{
                 ret.symb = '║';
            }

            if(draw){
                //Если sign = 1 то place.y должен быть больше [i-1] и меньше [i]
                //___i-1____y___i____
                //Если sign = -1 то place.y должен быть больше [i] и меньше [i-1]
                //___i______y___i-1__
                if(place.y >= angles[i+ind1].location.y && place.y <= angles[i+ind2].location.y){
                    ret.len = 1;
                    return ret;
                }
            }else{
                //Если sign = 1 то place.y должен быть не меньше [i] и не больше [i-1]
                //_y___i-1____i____y_
                //Если sign = -1 то place.y должен быть не меньше [i-1] и не больше [i]
                //__y__i___i-1___y___
                if(!(place.y < angles[i+ind2].location.y && place.y > angles[i+ind1].location.y)){
                    ret.len = 1;
                    return ret;
                }
            }

        }else{
            //голова равна концу
            if(angles[i].location == place)
                return snake_slice(angles[i].symb, 1);
        }
    }
    return ret;
}

coord Snake::get_snake_head(){
    if(ready)
        return angles[angles.size()-1].location;
    return coord(-1, -1);
}


Snake::~Snake(void){

}