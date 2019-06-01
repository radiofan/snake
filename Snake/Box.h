#pragma once
#include "structures.h"

class Box{

    private:
       map box;

    public:
        Box(void);
        void create(map &mapka);//�������� ����� �� �����, ����� ������ 0 � 1
        void Box::create(std::vector<String> &mapka);//�������� ����� �� ����� ������
        uint16_t get_h();//���� ������
        uint16_t get_w();//���� ������
        uint8_t  get_tile(uint16_t x, uint16_t y);//���� ������
        map     &get_box();//���� ������ �� �����

        ~Box(void);
};

