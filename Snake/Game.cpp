//cp866
#include "stdafx.h"
#include "addons.h"
#include "structures.h"
#include "UI_and_lang_constants.h"

//extern CRITICAL_SECTION sc;

Game::Game(void)
    //:lvl(settings.levelsReturn(), (colors) settings.setReturn(1)), done(0), console(GetStdHandle(STD_OUTPUT_HANDLE)), events(&Game::eventExec, this){
    :lvl(settings.levelsReturn(), settings.setLinkReturn(1), settings.setLinkReturn(0)), done(0), console(GetStdHandle(STD_OUTPUT_HANDLE)){

    CONSOLE_CURSOR_INFO cursor_info;
    GetConsoleCursorInfo(console,&cursor_info);
    cursor_info.bVisible = false;
    SetConsoleCursorInfo(console, &cursor_info);

    COORD xory = GetLargestConsoleWindowSize(console);
    SMALL_RECT win_size;
    win_size.Bottom = xory.Y - 1;
    xory.X = 80;
    xory.Y = 300;
    win_size.Left = 0;
    win_size.Top = 0;
    win_size.Right = xory.X - 1;
    SetConsoleWindowInfo(console, true, &win_size);
    SetConsoleScreenBufferSize(console, xory);

    menu.push(display(0, 1));
    system("color 17");//Žá­®¢­®© ­ ¡®à - á¨­¨© ä®­, ¡¥«ë© â¥ªáâ
    
}

int16_t Game::exec(){
    this->display_menu();
    this->eventExec();
    /*while(!done){

    }
    events.detach();*/
    return 0;
}

void Game::display_menu(){
    //SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//¯¥à¢ ï ä®­, ¢â®à ï â¥ªáâ
    // C -ïàª®ªà á­ë© ä®­ (12)
    switch(menu.top().screen){
        case 0:
            this->draw_screen();
            this->display_wallpaper();
            this->display_main_menu();
            break;
        case 1:
            this->draw_screen(0, 10);
            this->display_level_choice();
            break;
        case 2:
            this->draw_screen(0, 10);
            this->display_add_level_menu();
            break;
        case 3:
            this->draw_screen(0, 10);
            this->display_settings_menu();
            break;
        case 4:
            this->display_records_menu();
            break;
        case 5:
            this->display_info_menu();
            break;
        case 6:
            this->draw_screen(0, 15);
            this->display_exit_menu();
            break;
        case 7:
            this->draw_screen(0, 15);
            this->display_records_clear_menu();
            break;
        case 8:
            this->draw_screen(0, 10);
            this->display_add_level_data_menu();
            break;
        case 9:
            this->display_level_preview();
            break;
        case 10:
            this->draw_screen(0, 15);
            this->display_delete_menu();
            break;
        default:
            break;
    }
}

void Game::display_wallpaper(){
    std::cout << UI::UP_FRAME_0       << std::endl         
              << UI::MIDDLE_FRAME_0       << std::endl         
              << "³                     .-=-.          .--.                    _                ³"       << std::endl         
              << "³         __        .'     '.       / øø )                  ³ ³ " << LANG::WORD_BY[settings.setReturn(0)] << " RADIOFAN   ³"<< std::endl         
              << "³ _     .'  '.     /   .-.   \\     /  .-'    ___ _ __   __ _³ ³ _____         ³"      << std::endl         
              << "³( \\   / .-.  \\   /   /   \\   \\   /  /      / __³ '_ \\ / _` ³ ³/ / _ \\        ³" << std::endl         
              << "³ \\ `-` /   \\  `-'   /     \\   `-`  /       \\__ \\ ³ ³ ³ (_³ ³   <  __/        ³"  << std::endl         
              << "³  `-.-`     '.____.'       `.____.'        ³___/_³ ³_³\\__,_³_³\\_\\___³        ³"    << std::endl         
              << UI::MIDDLE_FRAME_0       << std::endl         
              << UI::DOWN_FRAME_0       << std::endl;
}

void Game::display_main_menu(){
    //EnterCriticalSection(&sc);
    std::cout << UI::UP_FRAME_0       << std::endl
              << UI::MIDDLE_FRAME_0       << std::endl
              << "³       Y                 ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                 Y       ³"       << std::endl
              << "³      (\")                ³";

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_NEW_GAME[settings.setReturn(0)];
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                (\")      ³" << std::endl         
              << "³       \\\\                ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                //       ³"     << std::endl
              << "³        \\\\                                                         //        ³"     << std::endl 
              << "³         ))              ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸              ((         ³"       << std::endl
              << "³        //               ³";

    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_ADD_LVL[settings.setReturn(0)];
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³               \\\\        ³" << std::endl         
              << "³       //                ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                \\\\       ³"     << std::endl         
              << "³      ((                                                             ))      ³"       << std::endl         
              << "³       \\\\                ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                //       ³"     << std::endl         
              << "³        \\\\               ³";

    if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_CUSTOMS[settings.setReturn(0)];
    if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³               //        ³" << std::endl         
              << "³         ))              ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾              ((         ³"       << std::endl         
              << "³        //                                                         \\\\        ³"     << std::endl         
              << "³       //                ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                \\\\       ³"     << std::endl         
              << "³      ((                 ³";

    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_RECORDS[settings.setReturn(0)];
    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                 ))      ³" << std::endl         
              << "³       \\\\                ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                //       ³"     << std::endl         
              << "³        \\\\                                                         //        ³"     << std::endl         
              << "³         ))              ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸              ((         ³"       << std::endl         
              << "³        //               ³";

    if(menu.top().field == 5) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_INFO[settings.setReturn(0)];
    if(menu.top().field == 5) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³               \\\\        ³" << std::endl         
              << "³       //                ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                \\\\       ³"     << std::endl         
              << "³      ((                                                             ))      ³"       << std::endl         
              << "³       \\\\                ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                //       ³"     << std::endl         
              << "³        V                ³";

    if(menu.top().field == 6) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_EXIT[settings.setReturn(0)];
    if(menu.top().field == 6) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                V        ³" << std::endl         
              << UI::DOWN_BUTTON_0       << std::endl         
              << UI::MIDDLE_FRAME_0       << std::endl         
              << UI::DOWN_FRAME_0       << std::endl;
    //LeaveCriticalSection(&sc);
}

void Game::display_level_choice(){
    //EnterCriticalSection(&sc);
    //N - 69 symbols
    //name - 65 symbols
    //author - 63 symbols
    //notice - 63 symbols
    std::cout << UI::UP_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << "³                  <ÄÄÄÄÄÄÄ" << LANG::BUTT_LVL_CHOICE[settings.setReturn(0)] << "ÄÄÄÄÄÄÄ>                  ³" << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::UP_FRAME_1 << std::endl
              << UI::MIDDLE_FRAME_1 << std::endl
              << UI::PIECE_0 << "ü ";
    String str = lvl.get_level_option(0).substr(0, 69);
    std::cout << str << String(69 - str.length(), ' ') << UI::PIECE_1 << std::endl
              << UI::MIDDLE_FRAME_1 << std::endl
              << UI::PIECE_0 << LANG::WORD_NAME[settings.setReturn(0)];
    str = lvl.get_level_option(1).substr(0, 65);
    std::cout << str << String(65 - str.length(), ' ') << UI::PIECE_1 << std::endl
              << UI::MIDDLE_FRAME_1 << std::endl
              << UI::PIECE_0 << LANG::WORD_AUTHOR[settings.setReturn(0)];
    str = lvl.get_level_option(2).substr(0, 63);
    std::cout << str << String(63-str.length(), ' ') << UI::PIECE_1 << std::endl;
    if(lvl.error.erorrs.size()){
        std::cout << UI::MIDDLE_FRAME_1 << std::endl
                  << UI::PIECE_0 << LANG::WORD_NOTICE[settings.setReturn(0)] << "                                                            º ³" << std::endl;
        if(!lvl.error.success)
            std::cout << UI::MIDDLE_FRAME_1 << std::endl
                      << "³ º       > " << LANG::WORD_FATAL_ERROR[settings.setReturn(0)] << "                                       º ³" << std::endl;
        for(uint32_t i=0; i<lvl.error.erorrs.size(); i++){
            str = "";
            if(lvl.error.erorrs[i].key)
                str += _T("[") + LANG::TEXT_ERROR[settings.setReturn(0)] + _T(" ü") + std::to_string(lvl.error.erorrs[i].key) + _T("] ");
            str += lvl.error.erorrs[i].message;
            std::cout << UI::MIDDLE_FRAME_1 << std::endl
                      << "³ º       > " << str.substr(0, 63);
            if(str.length()>63){
                for(uint16_t i1=63; i1<str.length(); i1 += 63){
                    std::cout << UI::PIECE_1 << std::endl << "³ º         " << str.substr(i1, 63);
                }
            }
            if(str.length()%63)
                std::cout << String(63 - (str.length()%63),' ');
            std::cout << UI::PIECE_1 << std::endl;
        }
    }
    std::cout << UI::MIDDLE_FRAME_1 << std::endl
              << UI::DOWN_FRAME_1 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl;
    if(lvl.error.success){
        std::cout << UI::UP_BUTTON_0 << std::endl
                  << UI::MIDDLE_BUTTON_0;

        if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
        std::cout << LANG::BUTT_START[settings.setReturn(0)];
        if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ
        
        std::cout << UI::MIDDLE_BUTTON_0 << std::endl
                  << UI::DOWN_BUTTON_0 << std::endl
                  << UI::MIDDLE_FRAME_0 << std::endl

                  << UI::UP_BUTTON_0 << std::endl
                  << UI::MIDDLE_BUTTON_0;

        if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
        std::cout << LANG::BUTT_PREVIEW[settings.setReturn(0)];
        if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ
        
        std::cout << UI::MIDDLE_BUTTON_0 << std::endl
                  << UI::DOWN_BUTTON_0 << std::endl
                  << UI::MIDDLE_FRAME_0 << std::endl;
    }
    if(lvl.get_level_number() > -1){
        std::cout << UI::UP_BUTTON_0 << std::endl
                  << UI::MIDDLE_BUTTON_0;

        if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
        std::cout << LANG::BUTT_DEL[settings.setReturn(0)];
        if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

        std::cout << UI::MIDDLE_BUTTON_0 << std::endl
                  << UI::DOWN_BUTTON_0 << std::endl
                  << UI::MIDDLE_FRAME_0 << std::endl;
    }
    std::cout << UI::UP_BUTTON_0 << std::endl
              << UI::MIDDLE_BUTTON_0;
    
    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_BACK[settings.setReturn(0)];
    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ
    
    std::cout << UI::MIDDLE_BUTTON_0 << std::endl
              << UI::DOWN_BUTTON_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::DOWN_FRAME_0 << std::endl;
    //LeaveCriticalSection(&sc);
}

void Game::display_add_level_menu(){
     //EnterCriticalSection(&sc);
     std::cout << UI::UP_FRAME_0       << std::endl
               << UI::MIDDLE_FRAME_0       << std::endl
               << UI::UP_BUTTON_0       << std::endl
               << UI::MIDDLE_BUTTON_0;

     if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
     std::cout << LANG::BUTT_ADD_LVL[settings.setReturn(0)];
     if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

     std::cout << UI::MIDDLE_BUTTON_0                                                           << std::endl
               << UI::DOWN_BUTTON_0       << std::endl
               << UI::MIDDLE_FRAME_0       << std::endl
               << UI::UP_BUTTON_0       << std::endl
               << UI::MIDDLE_BUTTON_0;

     if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
     std::cout << LANG::BUTT_DEL_LVL[settings.setReturn(0)];
     if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

     std::cout << UI::MIDDLE_BUTTON_0                                                           << std::endl
               << UI::DOWN_BUTTON_0       << std::endl
               << UI::MIDDLE_FRAME_0       << std::endl
               << UI::UP_BUTTON_0       << std::endl
               << UI::MIDDLE_BUTTON_0;

     if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
     std::cout << LANG::BUTT_BACK[settings.setReturn(0)];
     if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

     std::cout << UI::MIDDLE_BUTTON_0                                                           << std::endl
               << UI::DOWN_BUTTON_0       << std::endl
               << UI::MIDDLE_FRAME_0       << std::endl
               << UI::DOWN_FRAME_0       << std::endl;
     //LeaveCriticalSection(&sc);
}

void Game::display_settings_menu(){
    //EnterCriticalSection(&sc);
    String out;
    std::cout << UI::UP_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << "³                          " << LANG::BUTT_CUSTOMS[settings.setReturn(0)] << "                          ³" << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::UP_FRAME_1 << std::endl
              << UI::MIDDLE_FRAME_1 << std::endl
              << "³ º                                    ^                                    º ³" << std::endl
              << "³ º    " << LANG::WORD_COMPLEX[settings.setReturn(0)] << "             <";

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    out = std::to_string(settings.setReturn(2));
    if(settings.setReturn(2) < 10)
        out = "0" + out;
    std::cout << "           " << out << "            ";
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << ">    º ³" << std::endl
              << UI::MIDDLE_FRAME_1 << std::endl
              << "³ º    " << LANG::WORD_LANGUAGE[settings.setReturn(0)] << "             <";

    
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_LANG[settings.setReturn(0)];
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << ">    º ³" << std::endl
              << UI::MIDDLE_FRAME_1 << std::endl
              << "³ º    " << LANG::WORD_SNAKE_COLOR[settings.setReturn(0)] << "             <";

    if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((2 << 4) | (settings.setReturn(1))));//§¥«¥­ë© ä®­, ‡Œ…ˆ›‰ â¥ªáâ
    switch(settings.setReturn(1)){
        case 4:
            std::cout << LANG::BUTT_RED[settings.setReturn(0)];
            break;
        case 9:
            std::cout << LANG::BUTT_BLUE[settings.setReturn(0)];
            break;
        case 10:
            std::cout << LANG::BUTT_GREEN[settings.setReturn(0)];
            break;
        case 11:
            std::cout << LANG::BUTT_CYAN[settings.setReturn(0)];
            break;
        case 14:
            std::cout << LANG::BUTT_YELLOW[settings.setReturn(0)];
            break;
        case 15:
            std::cout << LANG::BUTT_WHITE[settings.setReturn(0)];
            break;
    }
    if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << ">    º ³" << std::endl
              << UI::MIDDLE_FRAME_1 << std::endl
              << "³ º    " << LANG::WORD_MENU_SOUND[settings.setReturn(0)] << "             <";

    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    if(settings.setReturn(3)){
        std::cout << LANG::BUTT_ON[settings.setReturn(0)];
    }else{
        std::cout << LANG::BUTT_OFF[settings.setReturn(0)];
    }
    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << ">    º ³" << std::endl
              << UI::MIDDLE_FRAME_1 << std::endl
              << "³ º    " << LANG::WORD_GAME_SOUND[settings.setReturn(0)] << "             <";

    if(menu.top().field == 5) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    if(settings.setReturn(4)){
        std::cout << LANG::BUTT_ON[settings.setReturn(0)];
    }else{
        std::cout << LANG::BUTT_OFF[settings.setReturn(0)];
    }
    if(menu.top().field == 5) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << ">    º ³" << std::endl
              << "³ º                                    v                                    º ³" << std::endl
              << UI::MIDDLE_FRAME_1 << std::endl
              << UI::DOWN_FRAME_1 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::UP_BUTTON_0 << std::endl
              << UI::MIDDLE_BUTTON_0;

    if(menu.top().field == 6) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_SAVE[settings.setReturn(0)];
    if(menu.top().field == 6) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << UI::MIDDLE_BUTTON_0 << std::endl
              << UI::DOWN_BUTTON_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::UP_BUTTON_0 << std::endl
              << UI::MIDDLE_BUTTON_0;

    if(menu.top().field == 7) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_BACK[settings.setReturn(0)];
    if(menu.top().field == 7) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << UI::MIDDLE_BUTTON_0 << std::endl
              << UI::DOWN_BUTTON_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::DOWN_FRAME_0 << std::endl;
    //LeaveCriticalSection(&sc);
}

void Game::display_records_menu(){
    if(!settings.get_recordsInit()){
        //system("cls");
        if(!menu.top().opt.size()){
            menu.top().opt.push_back(0);
        }else{
            menu.top().opt[0] = 0;
        }
        std::cout << UI::UP_FRAME_0 << std::endl
                  << UI::MIDDLE_FRAME_0 << std::endl
                  << "³                          " << LANG::BUTT_RECORDS[settings.setReturn(0)] << "                          ³" << std::endl
                  << UI::MIDDLE_FRAME_0 << std::endl
                  << "³                          " << LANG::BUTT_LOAD[settings.setReturn(0)] << "                          ³" << std::endl
                  << UI::MIDDLE_FRAME_0 << std::endl
                  << UI::DOWN_FRAME_0 << std::endl;
        settings.recordsRead();
        Sleep(500);
        system("cls");
        this->display_wallpaper();
    }
    std::cout << UI::UP_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << "³                          " << LANG::BUTT_RECORDS[settings.setReturn(0)] << "                          ³" << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl;

    uint16_t len = settings.recordsReturn().size();
    if(len){
        String str;
        uint8_t space;
        for(uint16_t i=menu.top().opt[0]; i<menu.top().opt[0]+5 && i<len; i++){
            str = "ü" + std::to_string(i+1);
            space = (71 - str.length())/2;
            std::cout << UI::UP_FRAME_1 << std::endl
                      << UI::PIECE_0  << String(space, ' ') << str << String(71 - space - str.length(), ' ') << UI::PIECE_1 << std::endl
                      << UI::MIDDLE_FRAME_1 << std::endl
                      << UI::PIECE_0 << LANG::WORD_NAME[settings.setReturn(0)] << settings.recordsReturn()[i].name <<  String(65 - settings.recordsReturn()[i].name.length(), ' ') <<  UI::PIECE_1 << std::endl
                      << UI::MIDDLE_FRAME_1 << std::endl
                      << UI::PIECE_0 << LANG::WORD_LVL[settings.setReturn(0)] << settings.recordsReturn()[i].level <<  String(62 - settings.recordsReturn()[i].level.length(), ' ') <<  UI::PIECE_1 << std::endl
                      << UI::MIDDLE_FRAME_1 << std::endl
                      << UI::PIECE_0 << LANG::WORD_RESULT[settings.setReturn(0)] << settings.recordsReturn()[i].result << String(60 - std::to_string(settings.recordsReturn()[i].result).length(), ' ') <<  UI::PIECE_1 << std::endl
                      << UI::MIDDLE_FRAME_1 << std::endl
                      << UI::DOWN_FRAME_1 << std::endl;
        }
    }else{
       std::cout << "³                          " << LANG::BUTT_NOT_FOUND[settings.setReturn(0)] << "                          ³" << std::endl;
    }

    std::cout << UI::MIDDLE_FRAME_0 << std::endl
              << UI::UP_BUTTON_0 << std::endl
              << UI::MIDDLE_BUTTON_0;

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_BACK[settings.setReturn(0)];
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << UI::MIDDLE_BUTTON_0 << std::endl
              << UI::DOWN_BUTTON_0 << std::endl
              << "³             ";

    if(menu.top().opt[0] > 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 12));//á¨­¨© ä®­, ªà á­ë© â¥ªáâ
    std::cout << "<ÄÄÄÄÄÄÄ";
    if(menu.top().opt[0] > 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "                                   ";

    if(menu.top().opt[0] + 5 < (int64_t) settings.recordsReturn().size()) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 12));//á¨­¨© ä®­, ªà á­ë© â¥ªáâ
    std::cout << "ÄÄÄÄÄÄÄ>";
    if(menu.top().opt[0] + 5 < (int64_t) settings.recordsReturn().size()) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "             ³" << std::endl
              << UI::UP_BUTTON_0 << std::endl
              << UI::MIDDLE_BUTTON_0;
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_DEL_ALL[settings.setReturn(0)];
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << UI::MIDDLE_BUTTON_0 << std::endl
              << UI::DOWN_BUTTON_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::DOWN_FRAME_0 << std::endl;
}

void Game::display_info_menu(){
    //EnterCriticalSection(&sc);
    std::cout << UI::UP_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << "³ " << LANG::TEXT_GAME_INFO[settings.setReturn(0)].substr(0, 75);
    if(LANG::TEXT_GAME_INFO[settings.setReturn(0)].length() > 75){
        for(uint32_t i=75; i<LANG::TEXT_GAME_INFO[settings.setReturn(0)].length(); i += 75){
            std::cout <<" ³" << std::endl << "³ " << LANG::TEXT_GAME_INFO[settings.setReturn(0)].substr(i, 75);
        }
    }
    if(LANG::TEXT_GAME_INFO[settings.setReturn(0)].length()%75)
        std::cout << String(75 - (LANG::TEXT_GAME_INFO[settings.setReturn(0)].length()%75), ' ');
    std::cout << " ³" << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::UP_BUTTON_0 << std::endl
              << UI::MIDDLE_BUTTON_0;

    SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_BACK[settings.setReturn(0)];
    SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << UI::MIDDLE_BUTTON_0 << std::endl
              << UI::DOWN_BUTTON_0 << std::endl
              << UI::DOWN_FRAME_0 << std::endl;
    //LeaveCriticalSection(&sc);
}

void Game::display_exit_menu(){
    //EnterCriticalSection(&sc);
    std::cout << UI::UP_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << "³ " << LANG::WORD_WHAT_HAP[settings.setReturn(0)] << " ³" << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << "³ " << LANG::WORD_EXIT_1[settings.setReturn(0)] << " ³" << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::UP_BUTTON_1 << std::endl
              << "³       ³";

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_YES[settings.setReturn(0)];
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³         ³";

    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_NO[settings.setReturn(0)];
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³       ³" << std::endl
              << UI::DOWN_BUTTON_1 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::DOWN_FRAME_0 << std::endl;
    //LeaveCriticalSection(&sc);
}

void Game::display_records_clear_menu(){
    //EnterCriticalSection(&sc);
    std::cout << UI::UP_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << "³ " << LANG::WORD_WHAT_HAP[settings.setReturn(0)] << " ³" << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << "³ " << LANG::WORD_CLEAR_1[settings.setReturn(0)] << " ³" << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::UP_BUTTON_1 << std::endl
              << "³       ³";

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_NO[settings.setReturn(0)];
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³         ³";

    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_YES[settings.setReturn(0)];
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³       ³" << std::endl
              << UI::DOWN_BUTTON_1 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::DOWN_FRAME_0 << std::endl;
    //LeaveCriticalSection(&sc);
}

void Game::display_add_level_data_menu(){
    //EnterCriticalSection(&sc);
    std::cout << UI::UP_FRAME_0       << std::endl
              << UI::MIDDLE_FRAME_0       << std::endl
              << "³                          " << LANG::BUTT_ADD_LVL[settings.setReturn(0)] << "                          ³"       << std::endl
              << UI::MIDDLE_FRAME_0       << std::endl
              << UI::UP_FRAME_1       << std::endl
              << UI::MIDDLE_FRAME_1       << std::endl
              << "³ º        ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ º ³"       << std::endl
              << UI::PIECE_0 ;

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::WORD_PATH[settings.setReturn(0)];
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    //60 symbols
    int32_t len = menu.top().stropt[0].length();
    if(len <= 60){
        std::cout << " ³ " << menu.top().stropt[0] << String(60 - len, ' ');
    }else{
        std::cout << " ³" << menu.top().stropt[0].substr(len-61, 61);
    }

    std::cout << " ³ º ³" << std::endl
              << "³ º        ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ º ³"       << std::endl
              << UI::MIDDLE_FRAME_1       << std::endl
              << "³ º         ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿                              º ³"       << std::endl
              << UI::PIECE_0 ;

    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::WORD_NAME[settings.setReturn(0)];
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    //30 symbols
    len = menu.top().stropt[1].length();
    if(len <= 30){
        std::cout << "  ³ " << menu.top().stropt[1] << String(30 - len, ' ');
    }else{
        std::cout << "  ³" << menu.top().stropt[1].substr(len-31, 31);
    }

    std::cout << " ³                              º ³" << std::endl
              << "³ º         ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ                              º ³"       << std::endl
              << UI::MIDDLE_FRAME_1       << std::endl
              << "³ º         ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿                              º ³"       << std::endl
              << UI::PIECE_0 ;

    if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::WORD_AUTHOR[settings.setReturn(0)];
    if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    //30 symbols
    len = menu.top().stropt[2].length();
    if(len <= 30){
        std::cout << "³ " << menu.top().stropt[2] << String(30 - len, ' ');
    }else{
        std::cout << "³" << menu.top().stropt[2].substr(len-31, 31);
    }

    std::cout << " ³                              º ³"       << std::endl
              << "³ º         ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ                              º ³"       << std::endl
              << UI::MIDDLE_FRAME_1       << std::endl
              << "³ º                       ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                       º ³"       << std::endl
              << "³ º                       ³";

    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << LANG::BUTT_SAVE[settings.setReturn(0)];
    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                       º ³"       << std::endl
              << "³ º                       ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                       º ³"       << std::endl
              << UI::MIDDLE_FRAME_1       << std::endl
              << UI::DOWN_FRAME_1       << std::endl
              << UI::MIDDLE_FRAME_0       << std::endl
              << UI::UP_BUTTON_0       << std::endl
              << UI::MIDDLE_BUTTON_0;

    if(menu.top().field == 5) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std:: cout << LANG::BUTT_BACK[settings.setReturn(0)];
    if(menu.top().field == 5) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << UI::MIDDLE_BUTTON_0       << std::endl
              << UI::DOWN_BUTTON_0       << std::endl
              << UI::MIDDLE_FRAME_0       << std::endl
              << UI::DOWN_FRAME_0       << std::endl;
    //LeaveCriticalSection(&sc);
}

void Game::display_level_preview(){
    /*
    CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
    GetConsoleScreenBufferInfo(console, &ScreenBufferInfo);
    std::cout << "X: " << ScreenBufferInfo.dwSize.X << "Y: " << ScreenBufferInfo.dwSize.Y << std::endl;
    */
    //x: 80, y: 300
    COORD size = lvl.get_level_size();
    size.X += 1;
    if(size.X < 80){
        size.X = 80;
    }
    size.Y += 100;
    if(size.Y < 300){
        size.Y = 300;
    }
    COORD maxWindow = GetLargestConsoleWindowSize(console);
    SMALL_RECT win_size;
    win_size.Left = 0;
    win_size.Top = 0;
    if(size.X < maxWindow.X){
        win_size.Right = size.X - 1;
    }else{
        win_size.Right = maxWindow.X - 1;
    }
    if(size.Y < maxWindow.Y){
        win_size.Bottom = size.Y - 1;
    }else{
        win_size.Bottom = maxWindow.Y - 1;
    }
    SetConsoleScreenBufferSize(console, size);
    SetConsoleWindowInfo(console, true, &win_size);

    //"      LEVEL PREVIEW      "
    std::cout << "É" << String(size.X - 3, 'Í') << "»" << std::endl
              << "º" << String((size.X - 27)/2, ' ') << LANG::BUTT_LVL_PREV[settings.setReturn(0)] << String((size.X - 28)/2 + (size.X - 28)%2, ' ') << "º" << std::endl
              << "È" << String(size.X - 3, 'Í') << "¼" << std::endl << std::endl;
    lvl.level_preview();
    if(lvl.error.erorrs.size()){
        std::cout << std::endl
                  << LANG::WORD_NOTICE[settings.setReturn(0)] << std::endl;
        for(uint32_t i=0; i<lvl.error.erorrs.size(); i++){
            if(lvl.error.erorrs[i].key)
                continue;
            std::cout << std::endl
                      << "       > " << lvl.error.erorrs[i].message;
        }
    }
}

void Game::display_delete_menu(){
    //EnterCriticalSection(&sc);
    std::cout << UI::UP_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl;

    if(menu.top().opt[0] == 0){//ã¤ «¥­¨¥
        std::cout << "³ " << LANG::WORD_WHAT_HAP[settings.setReturn(0)] << " ³" << std::endl
                  << UI::MIDDLE_FRAME_0 << std::endl
                  << "³ " << LANG::WORD_DELETE_1[settings.setReturn(0)] << " ³" << std::endl
                  << UI::MIDDLE_FRAME_0 << std::endl
                  << UI::MIDDLE_FRAME_0 << std::endl
                  << UI::UP_BUTTON_1 << std::endl
                  << "³       ³";

        if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
        std::cout << LANG::BUTT_NO[settings.setReturn(0)];
        if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

        std::cout << "³         ³";

        if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
        std::cout << LANG::BUTT_YES[settings.setReturn(0)];
        if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

        std::cout << "³       ³" << std::endl
                  << UI::DOWN_BUTTON_1 << std::endl;
    }else{
         if(menu.top().opt[0] == 1){//ãá¯¥è­®
             std::cout << UI::MIDDLE_FRAME_0 << std::endl
                       << "³ " << LANG::WORD_DELETE_2[settings.setReturn(0)] << " ³" << std::endl
                       << UI::MIDDLE_FRAME_0 << std::endl;
         }else{//­¥ãá¯¥è­®
            std::cout << UI::MIDDLE_FRAME_0 << std::endl
                       << "³ " << LANG::WORD_DELETE_3[settings.setReturn(0)] << " ³" << std::endl
                       << UI::MIDDLE_FRAME_0 << std::endl;
         }
         std::cout << UI::MIDDLE_FRAME_0 << std::endl
                   << UI::MIDDLE_FRAME_0 << std::endl
                   << UI::UP_BUTTON_0 << std::endl
                   << UI::MIDDLE_BUTTON_0;

         SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
         std::cout << LANG::BUTT_WELL[settings.setReturn(0)];
         SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

         std::cout << UI::MIDDLE_BUTTON_0 << std::endl
                   << UI::DOWN_BUTTON_0 << std::endl;
    }

    std::cout << UI::MIDDLE_FRAME_0 << std::endl
              << UI::MIDDLE_FRAME_0 << std::endl
              << UI::DOWN_FRAME_0 << std::endl;
    //LeaveCriticalSection(&sc);
}

///////////////////////////////////////////////////////////////////////////////

void Game::eventExec(){
    ////EnterCriticalSection(&sc);
    int8_t key;
    while(!done){
        key = _getch();
        switch(menu.top().screen){
            case 0:
                this->event_main_menu(key);
                break;
            case 1:
                this->event_level_choice(key);
                break;
            case 2:
                this->event_add_level_menu(key);
                break;
            case 3:
                this->event_settings_menu(key);
                break;
            case 4:
                this->event_records_menu(key);
                break;
            case 5:
                this->event_info_menu(key);
                break;
            case 6:
                this->event_exit_menu(key);
                break;
            case 7:
                this->event_records_clear_menu(key);
                break;
            case 8:
                this->event_add_level_data_menu(key);
                break;
            case 9:
                this->event_level_preview(key);
                break;
            case 10:
                this->event_delete_menu(key);
                break;
            default:
                break;
        }
    }
    ////LeaveCriticalSection(&sc);
}

void Game::event_main_menu(int8_t key){
    switch(key){
        case 27://esc
            menu.push(display(6, 1));
            this->bell();
            this->display_menu();
            break;
        case 72://strelka vverh
            if(menu.top().field == 1){
                menu.top().field = 6;
            }else{
                menu.top().field -= 1;
            }
            this->bell();
            this->display_menu();
            break;
        case 80://strelka vniz
            if(menu.top().field == 6){
                menu.top().field = 1;
            }else{
                menu.top().field += 1;
            }
            this->bell();
            this->display_menu();
            break;
        case 13://enter
            if(menu.top().field != 1){
                menu.push(display(menu.top().field, 1));
            }else{
                if(lvl.error.success){
                    menu.push(display(menu.top().field, 1));
                }else{
                    menu.push(display(menu.top().field, 4));
                }
            }
            this->bell();
            if(menu.top().screen != 6){
                system("cls");
                this->display_wallpaper();
            }
            this->display_menu();
            break;
        case 77://strelka vpravo
        case 75://strelka vlevo
        default:
            break;
    }
}

void Game::event_level_choice(int8_t key){
    switch(key){
        case 27://esc
            menu.pop();
            this->bell();
            system("cls");
            this->display_wallpaper();
            this->display_menu();
            break;
        case 72://strelka vverh
            switch(menu.top().field){
                case 1:
                    menu.top().field = 4;
                    break;
                case 2:
                    if(lvl.error.success){
                        menu.top().field = 1;
                    }else{
                        menu.top().field = 4;
                    }
                    break;
                case 3:
                    if(lvl.error.success){
                        menu.top().field = 2;
                    }else{
                        menu.top().field = 4;
                    }
                    break;
                case 4:
                    if(lvl.get_level_number() > -1){
                        menu.top().field = 3;
                    }else if(lvl.error.success){
                        menu.top().field = 2;
                    }
                    break;
            }
            this->bell();
            this->display_menu();
            break;
        case 80://strelka vniz
            switch(menu.top().field){
                case 1:
                    if(lvl.error.success){
                        menu.top().field = 2;
                    }else if(lvl.get_level_number() > -1){
                        menu.top().field = 3;
                    }else{
                        menu.top().field = 4;
                    }
                    break;
                case 2:
                    if(lvl.get_level_number() > -1){
                        menu.top().field = 3;
                    }else{
                        menu.top().field = 4;
                    }
                    break;
                case 3:
                    menu.top().field = 4;
                    break;
                case 4:
                    if(lvl.error.success){
                        menu.top().field = 1;
                    }else if(lvl.get_level_number() > -1){
                        menu.top().field = 3;
                    }
                    break;
            }
            this->bell();
            this->display_menu();
            break;
        case 77://strelka vpravo
        case 75://strelka vlevo
            this->bell();
            system("cls");
            this->display_wallpaper();
            lvl.step_level(key-76);
            if(lvl.error.success){
                menu.top().field = 1;
            }else{
                menu.top().field = 3;
            }
            this->display_menu();
            break;
        case 13://enter
            switch(menu.top().field){
                case 1:
                    //TODO: start game
                    break;
                case 2:
                    if(lvl.error.success){
                        menu.push(display(9, 1));
                        this->bell();
                        system("cls");
                        this->display_menu();
                    }
                    break;
                case 3:
                    if(lvl.get_level_number() > -1){
                        menu.push(display(10, 1));
                        menu.top().opt.push_back(0);
                        this->bell();
                        this->display_menu();
                    }
                    break;
                case 4:
                    this->event_level_choice(27);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void Game::event_add_level_menu(int8_t key){
    switch(key){
        case 27://esc
            this->event_info_menu(key);
            break;
        case 72://strelka vverh
            if(menu.top().field == 1){
                menu.top().field = 3;
            }else{
                menu.top().field -= 1;
            }
            this->bell();
            this->display_menu();
            break;
        case 80://strelka vniz
            if(menu.top().field == 3){
                menu.top().field = 1;
            }else{
                menu.top().field += 1;
            }
            this->bell();
            this->display_menu();
            break;
        case 13://enter
            switch(menu.top().field){
                case 1:
                    menu.push(display(8, 1));
                    menu.top().stropt.resize(3);
                    this->bell();
                    this->display_menu();
                    break;
                case 2:
                    menu.push(display(1, 4));
                    this->bell();
                    this->display_menu();
                    break;
                case 3:
                    this->event_info_menu(key);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void Game::event_settings_menu(int8_t key){
    switch(key){
        case 27://esc
            this->event_info_menu(key);
            break;
        case 72://strelka vverh
            if(menu.top().field == 1){
                menu.top().field = 7;
            }else{
                menu.top().field -= 1;
            }
            this->bell();
            this->display_menu();
            break;
        case 80://strelka vniz
            if(menu.top().field == 7){
                menu.top().field = 1;
            }else{
                menu.top().field += 1;
            }
            this->bell();
            this->display_menu();
            break;
        case 77://strelka vpravo
        case 75://strelka vlevo
            switch(menu.top().field){
                case 1:
                    settings.setStep(2, key-76);
                    break;
                case 2:
                    settings.setStep(0, key-76);
                    break;
                case 3:
                    settings.setStep(1, key-76);
                    break;
                case 4:
                    settings.setStep(3, key-76);
                    break;
                case 5:
                    settings.setStep(4, key-76);
                    break;
                default:
                    break;
            }
            this->bell();
            this->display_menu();
            break;
        case 13://enter
            /*
            if(menu.top().field == 6){
                settings.setSave();
                menu.pop();
                this->bell();
                system("cls");
            }else if(menu.top().field == 7){
                menu.pop();
                this->bell();
                system("cls");
            }else{
                menu.top().field += 1;
                this->bell();
            }
            */
            if(menu.top().field < 6){
                menu.top().field += 1;
                this->bell();
            }else{
                if(menu.top().field == 6)
                    settings.setSave();
                menu.pop();
                this->bell();
                system("cls");
            }
            this->display_menu();
            break;
        default:
            break;
    }
}

void Game::event_records_menu(int8_t key){
    switch(key){
        case 27://esc
            settings.recordsClear();
            this->event_info_menu(key);
            break;
        case 72://strelka vverh
            if(menu.top().field == 1){
                menu.top().field = 2;
            }else{
                menu.top().field = 1;
            }
            this->bell();
            this->draw_screen(0, 10);
            this->display_menu();
            break;
        case 80://strelka vniz
            if(menu.top().field == 2){
                menu.top().field = 1;
            }else{
                menu.top().field = 2;
            }
            this->bell();
            this->draw_screen(0, 10);
            this->display_menu();
            break;
        case 77://strelka vpravo
            if(menu.top().opt[0] + 5 < (int64_t) settings.recordsReturn().size()){
                menu.top().opt[0] += 5;
                this->bell();
                system("cls");
                this->display_wallpaper();
                this->display_menu();
            }
            break;
        case 75://strelka vlevo
            if(menu.top().opt[0] > 4){
                menu.top().opt[0] -= 5;
                this->bell();
                system("cls");
                this->display_wallpaper();
                this->display_menu();
            }
            break;
        case 13://enter
            if(menu.top().field == 1){
                settings.recordsClear();
                this->event_info_menu(key);//‚ëå®¤ ¨§ ¬¥­î
            }else{
                menu.push(display(7, 1));
                this->bell();
                this->display_menu();
            }
            break;
        default:
            break;
    }
}

void Game::event_info_menu(int8_t key){
    switch(key){
        case 27://esc
        case 13://enter
            menu.pop();
            this->bell();
            system("cls");
            this->display_menu();
            break;
        default:
            break;
    }
}

void Game::event_exit_menu(int8_t key){
    switch(key){
        case 27://esc
            menu.pop();
            this->display_menu();
            break;
        case 77://strelka vpravo
        case 75://strelka vlevo
            if(menu.top().field == 1){
                menu.top().field = 2;
            }else{
                menu.top().field = 1;
            }
            this->bell();
            this->display_menu();
            break;
        case 13://enter
            if(menu.top().field == 1){
                done = 1;
            }else{
                menu.pop();
                this->display_menu();
            }
            break;
        case 72://strelka vverh
        case 80://strelka vniz
            break;
        default:
            break;
    }
}

void Game::event_records_clear_menu(int8_t key){
    switch(key){
        case 27://esc
            menu.pop();
            this->bell();
            this->draw_screen(0, 10);
            this->display_menu();
            break;
        case 77://strelka vpravo
        case 75://strelka vlevo
            this->event_exit_menu(key);//€­ «®£¨ç­ ï ®¡à ¡®âª 
            break;
        case 13://enter
            menu.pop();
            this->bell();
            if(menu.top().field == 2){
                settings.recordsClear();
                settings.recordsDelete();
                system("cls");
                this->display_wallpaper();
            }
            this->draw_screen(0, 10);
            this->display_menu();
            break;
        case 72://strelka vverh
        case 80://strelka vniz
        default:
            break;
    }
}

void Game::event_add_level_data_menu(int8_t key){
    if(key == 27){
        menu.pop();
        this->bell();
        system("cls");
        this->display_wallpaper();
        this->display_menu();
        return;
    }
    if(menu.top().field > 3){
        switch(key){
        case 72://strelka vverh
            menu.top().field -= 1;
            this->bell();
            this->display_menu();
            break;
        case 80://strelka vniz
            if(menu.top().field == 5){
                menu.top().field = 1;
            }else{
                menu.top().field += 1;
            }
            this->bell();
            this->display_menu();
            break;
        case 13://enter
            if(menu.top().field == 5){
                this->event_add_level_data_menu(27);
            }else{
                lvl.save_level(menu.top().stropt);
                menu.pop();
                menu.pop();
                if(lvl.error.success){
                    menu.push(display(1, 1));
                }else{
                    menu.push(display(1, 4));
                }
                this->bell();
                system("cls");
                this->display_wallpaper();
                this->display_menu();
            }
            break;
        default:
            break;
        }
    }else{
        //text
        String &str = menu.top().stropt[menu.top().field-1];
        if((key >= -128 && key <= -81) ||
           (key >= -32  && key <= -15) ||
            key == -4                  ||
           (key >= 32   && key <= 126)
          ){
            str += String(1, key);
            this->pick();
            this->display_menu();
        }else if(key == 8){//backspace
            if(str.length()){
                str = str.substr(0, str.length()-1);
                this->pick();
                this->display_menu();
            }
        }else if(key == 13){//enter
            menu.top().field += 1;
            this->bell();
            this->display_menu();
        }else if(key == 9){
            if(menu.top().field == 3){
                menu.top().field = 1;
            }else{
                menu.top().field += 1;
            }
            this->bell();
            this->display_menu();
        }
    }
}

void Game::event_level_preview(int8_t key){
    menu.pop();
    this->bell();
    COORD xory = GetLargestConsoleWindowSize(console);
    SMALL_RECT win_size;
    win_size.Bottom = xory.Y - 1;
    xory.X = 80;
    xory.Y = 300;
    system("cls");
    win_size.Left = 0;
    win_size.Top = 0;
    win_size.Right = xory.X - 1;
    SetConsoleWindowInfo(console, true, &win_size);
    SetConsoleScreenBufferSize(console, xory);
    this->display_wallpaper();
    this->display_menu();
}

void Game::event_delete_menu(int8_t key){
    switch(key){
        case 27://esc
            this->bell();
            this->event_exit_menu(key);
            break;
        case 77://strelka vpravo
        case 75://strelka vlevo
            if(menu.top().opt[0] != 0)
                break;
            this->event_exit_menu(key);
            break;
        case 13://enter
            if(menu.top().field == 1){
                if(menu.top().opt[0] == 1){
                    menu.pop();
                    menu.top().field = 4;
                    this->bell();
                    system("cls");
                    this->display_wallpaper();
                    this->display_menu();
                    break;
                }else{
                    event_delete_menu(27);
                }
            }else{
                this->bell();
                if(!lvl.delete_level()){
                    menu.top().opt[0] = 2;//­¥ãá¯¥è­®
                }else{
                    menu.top().opt[0] = 1;//ãá¯¥è­®
                }
                menu.top().field = 1;
                this->display_menu();
            }
            break;
        default:
            break;
    }
}

/*
void Game::event_(int8_t key){
    switch(key){
        case 27://esc
            break;
        case 72://strelka vverh
            break;
        case 80://strelka vniz
            break;
        case 77://strelka vpravo
            break;
        case 75://strelka vlevo
            break;
        case 13://enter
            break;
        default:
            break;
    }
}
*/

void Game::bell(){
    //std::cout << "\a";
    //Beep(247, 500);
    //Beep(277, 500);
    if(settings.setReturn(3))
        Beep(400, 200);
    //Beep(370, 500);
    //Beep(417, 500);
    //Beep(440, 500);
    //Beep(497, 500);
    //MessageBeep(MB_ICONHAND);//®è¨¡ª 
    //MessageBeep(MB_ICONQUESTION);//­¥ à ¡®â ¥â
    //MessageBeep(MB_ICONEXCLAMATION);//®è¨¡ª 
    //MessageBeep(MB_ICONASTERISK);//á®åà ­¨âì
}

void Game::pick(){
    if(settings.setReturn(3))
        Beep(600, 100);
}

void Game::draw_screen(uint32_t x, uint32_t y){
    COORD xory;
    xory.X = x;
    xory.Y = y;
    SetConsoleCursorPosition(console, xory);
}


Game::~Game(void){

}