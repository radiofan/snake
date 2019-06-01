#pragma once
#include "structures.h"

class Box{

    private:
       map box;

    public:
        Box(void);
        void create(map &mapka);//создание карты из чисел, числа только 0 и 1
        void Box::create(std::vector<String> &mapka);//создание карты из строк текста
        uint16_t get_h();//дать высоту
        uint16_t get_w();//дать ширину
        uint8_t  get_tile(uint16_t x, uint16_t y);//дать ячейку
        map     &get_box();//дать ссылку на карту

        ~Box(void);
};

