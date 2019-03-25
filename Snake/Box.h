#pragma once
#include "structures.h"

class Box{

    private:
       map boxx;

    public:
        Box(void);
        void create(map &mapka);//создание карты
        uint32_t get_h();//дать высоту
        uint32_t get_w();//дать ширину
        uint8_t  get_tile(uint32_t x, uint32_t y);//дать ячейку
        map     &get_box();//дать ссылку на карту

        ~Box(void);
};

