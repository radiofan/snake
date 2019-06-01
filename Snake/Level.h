#pragma once
#include "Snake.h"
#include "Box.h"

class Level{
    
    private:
        Snake snake;
        Box   box;
        empty_space space;

        std::vector<String> &level_list;
        int32_t level_number;
        String  level_name;
        String  level_author;

        //������ ��������� ���� � ������ ret
        //������ � error
        bool read_file(String &path, std::vector<String> &ret);
        /*
        * �������� ��������� read_file() � ����������� ���
        * ������ � error
        */
        bool analys_file(std::vector<String> &file);

    public:
        /*
        * 0 - �����
        * 1 - ���� �� ������
        * 2 - ��� ����� ��������� 0,5 ��
        * 3 - ���� ����
        * 4 - ���� �� �������� ���������������
        * 5 - �������� ��������� � �����
        * 6 - ���� ��� ������ ����
        * 7 - ������� ������ � ����������� �����
        */
        ERORR error;

        //Level(String link = "");
        
        Level(std::vector<String> &lvl_list, colors color);
        //������� ����� box �� ������� �����
        //���������� ��� ������
        //0 - �����
        uint8_t generate(std::vector<String> &mapka);
        /*
        * ��������� ����� � ������ ���� � ����� levels
        * ��������� ������ �� ������
        *
        * options[0] - path
        * options[1] - map name
        * options[2] - author
        */
        ERORR &save_level(std::vector<String> options);

        /*
        * ����������
        * 0 - level_number + 1
        * 1 - level_name
        * 2 - level_author
        */
        String get_level_option(uint8_t a=0);

        void level_draw();


        ~Level(void);
};

