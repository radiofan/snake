#pragma once
#include "structures.h"

class Box{

    private:
       map box;

    public:
        Box(void);
        void create(map &mapka);//�������� ����� �� �����, ����� ������ 0 � 1
        void Box::create(std::vector<String> &mapka);//�������� ����� �� ����� ������
        uint32_t get_h();//���� ������
        uint32_t get_w();//���� ������
        uint8_t  get_tile(uint32_t x, uint32_t y);//���� ������
        map     &get_box();//���� ������ �� �����

        ~Box(void);
};

