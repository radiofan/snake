#pragma once
#include "Level.h"
#include "Settings.h"

class Game{

    private:
        //std::vector<Level> levels;
        Settings settings;
        Level lvl;

        //True - прекратить выполнение, False - выполнять
        bool done;

        std::stack<display> menu;
        //std::vector<func> handlers;

        HANDLE console;
        std::thread events;
        
        void display_menu();
        void display_wallpaper();
        //0-screen
        void display_main_menu();
        //2-screen
        void display_add_level_menu();
        //3-screen
        void display_settings_menu();
        //4-screen
        void display_records_menu();
        //5-screen
        void display_info_menu();
        //6-screen
        void display_exit_menu();
        //7-screen
        void display_records_clear_menu();
        //8-screen
        void display_add_level_data_menu();

        //0-screen
        void event_main_menu(int8_t key);
        //2-screen
        void event_add_level_menu(int8_t key);
        //3-screen
        void event_settings_menu(int8_t key);
        //4-screen
        void event_records_menu(int8_t key);
        //5-screen
        void event_info_menu(int8_t key);
        //6-screen
        void event_exit_menu(int8_t key);
        //7-screen
        void event_records_clear_menu(int8_t key);
        //8-screen
        void event_add_level_data_menu(int8_t key);

    public:
        Game(void);
        int16_t exec();
        void eventExec();
        void bell();
        void draw_screen(uint32_t x = 0, uint32_t y = 0);

        ~Game(void);
};