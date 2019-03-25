#pragma once
#include "Level.h"

class Game{

    private:
        //std::vector<Level> levels;
        //Settings settings;

        //True - ���������� ����������, False - ���������
        bool done;

        /*
        * 0 - ������� ����
        * 1 - ���� �����
        */
        int8_t menu;

        /*
        * ��������� ����
        */
        int8_t field;
        HANDLE console;
        std::thread events;

        void display_main_menu();
        void display_menu();
        void display_wallpaper();
        void display_exit_menu();

    public:
        Game(void);
        int16_t exec();
        void eventExec();

        ~Game(void);
};