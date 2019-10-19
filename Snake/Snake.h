#pragma once
#include "structures.h"
class Snake{

    private:
        int16_t &color;
        /*
        * ����������� ��������
        * 0-�����
        * 1-������
        * 2-����
        * 3-�����
        */
        int8_t orient;
        std::vector<snake_piece> angles;
        bool ready;

    public:
        Snake(int16_t &colour);
        Snake(int8_t orientation, int16_t &colour);

        /*
        * ����������� ��������
        * 0-�����
        * 1-������
        * 2-����
        * 3-�����
        */
        bool set_orient(int8_t orientation=0);
        bool set_start(coord place, int8_t orientation=0);
        void angles_reserve(uint32_t reserve);
        void clear();

        bool is_ready();

        int16_t get_color();

        //������ ������ ��������� ����(snake_slice.symb) � ����� ��������(snake_slice.len)
        //���� �������� ���� � ����������� place
        //����� ������ snake_slice(0, -1)
        snake_slice get_snake_slice(coord place);

        coord get_snake_head();

        //TODO: DO iT PRIVATE!!
        //std::vector<snake_piece> angles;
        //bool ready;

        ~Snake(void);
};

