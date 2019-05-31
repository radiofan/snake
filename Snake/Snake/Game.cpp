#include "stdafx.h"
#include "addons.h"
#include "structures.h"

extern CRITICAL_SECTION sc;

Game::Game(void)
    :lvl(settings.levelsReturn()), done(0), console(GetStdHandle(STD_OUTPUT_HANDLE)), events(&Game::eventExec, this){

    menu.push(display(0, 1));
    system("color 17");//Žá­®¢­®© ­ ¡®à - á¨­¨© ä®­, ¡¥«ë© â¥ªáâ
    
}

int16_t Game::exec(){
    this->display_menu();

    while(!done){

    }
    events.detach();
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
        case 2:
            this->draw_screen(0, 10);
            this->display_add_level_menu();
            break;
        case 3:
            this->draw_screen(0, 10);
            this->display_settings_menu();
            break;
        case 4:
            system("cls");
            this->display_wallpaper();
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
        default:
            break;
    }
}

void Game::display_wallpaper(){
    std::cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿"       << std::endl         
              << "³                                                                             ³"       << std::endl         
              << "³                     .-=-.          .--.                    _                ³"       << std::endl         
              << "³         __        .'     '.       / øø )                  ³ ³ by RADIOFAN   ³"       << std::endl         
              << "³ _     .'  '.     /   .-.   \\     /  .-'    ___ _ __   __ _³ ³ _____         ³"      << std::endl         
              << "³( \\   / .-.  \\   /   /   \\   \\   /  /      / __³ '_ \\ / _` ³ ³/ / _ \\        ³" << std::endl         
              << "³ \\ `-` /   \\  `-'   /     \\   `-`  /       \\__ \\ ³ ³ ³ (_³ ³   <  __/        ³"  << std::endl         
              << "³  `-.-`     '.____.'       `.____.'        ³___/_³ ³_³\\__,_³_³\\_\\___³        ³"    << std::endl         
              << "³                                                                             ³"       << std::endl         
              << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ"       << std::endl;
}

void Game::display_main_menu(){
    EnterCriticalSection(&sc);
    std::cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿"       << std::endl
              << "³                                                                             ³"       << std::endl
              << "³       Y                 ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                 Y       ³"       << std::endl
              << "³      (\")                ³";

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "        NEW  GAME        ";
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                (\")      ³" << std::endl         
              << "³       \\\\                ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                //       ³"     << std::endl
              << "³        \\\\                                                         //        ³"     << std::endl 
              << "³         ))              ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸              ((         ³"       << std::endl
              << "³        //               ³";

    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "        ADD LEVEL        ";
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³               \\\\        ³" << std::endl         
              << "³       //                ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                \\\\       ³"     << std::endl         
              << "³      ((                                                             ))      ³"       << std::endl         
              << "³       \\\\                ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                //       ³"     << std::endl         
              << "³        \\\\               ³";

    if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "         CUSTOMS         ";
    if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³               //        ³" << std::endl         
              << "³         ))              ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾              ((         ³"       << std::endl         
              << "³        //                                                         \\\\        ³"     << std::endl         
              << "³       //                ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                \\\\       ³"     << std::endl         
              << "³      ((                 ³";

    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "         RECORDS         ";
    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                 ))      ³" << std::endl         
              << "³       \\\\                ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                //       ³"     << std::endl         
              << "³        \\\\                                                         //        ³"     << std::endl         
              << "³         ))              ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸              ((         ³"       << std::endl         
              << "³        //               ³";

    if(menu.top().field == 5) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "       INFORMATION       ";
    if(menu.top().field == 5) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³               \\\\        ³" << std::endl         
              << "³       //                ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                \\\\       ³"     << std::endl         
              << "³      ((                                                             ))      ³"       << std::endl         
              << "³       \\\\                ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                //       ³"     << std::endl         
              << "³        V                ³";

    if(menu.top().field == 6) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "          EXIT           ";
    if(menu.top().field == 6) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                V        ³" << std::endl         
              << "³                         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                         ³"       << std::endl         
              << "³                                                                             ³"       << std::endl         
              << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ"       << std::endl;
    LeaveCriticalSection(&sc);
}

void Game::display_add_level_menu(){
     EnterCriticalSection(&sc);
     std::cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿"       << std::endl
               << "³                                                                             ³"       << std::endl
               << "³                         ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                         ³"       << std::endl
               << "³                         ³";

     if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
     std::cout << "        ADD LEVEL        ";
     if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

     std::cout << "³                         ³"                                                           << std::endl
               << "³                         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                         ³"       << std::endl
               << "³                                                                             ³"       << std::endl
               << "³                         ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                         ³"       << std::endl
               << "³                         ³";

     if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
     std::cout << "      DELETE LEVELS      ";
     if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

     std::cout << "³                         ³"                                                           << std::endl
               << "³                         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                         ³"       << std::endl
               << "³                                                                             ³"       << std::endl
               << "³                         ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                         ³"       << std::endl
               << "³                         ³";

     if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
     std::cout << "          <BACK          ";
     if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

     std::cout << "³                         ³"                                                           << std::endl
               << "³                         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                         ³"       << std::endl
               << "³                                                                             ³"       << std::endl
               << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ"       << std::endl;
     LeaveCriticalSection(&sc);
}

void Game::display_settings_menu(){
    EnterCriticalSection(&sc);
    String out;
    std::cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                                   CUSTOMS                                   ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»                ³" << std::endl
              << "³                º                                           º                ³" << std::endl
              << "³                º                     ^                     º                ³" << std::endl
              << "³                º                                           º                ³" << std::endl
              << "³                º  COMPLEXITY:              <";

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    out = std::to_string(settings.setReturn(2));
    if(settings.setReturn(2) < 10)
        out = "0" + out;
    std::cout << "    " << out << "     ";
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << ">   º                ³"                                                          << std::endl
              << "³                º                                           º                ³" << std::endl
              << "³                º  LANGUAGE:                <";

    
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    switch(settings.setReturn(0)){
        case 0:
            std::cout << "  ENGLISH  ";
            break;
        case 1:
            std::cout << "  “‘‘Šˆ‰  ";
            break;
    }
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << ">   º                ³"                                                          << std::endl
              << "³                º                                           º                ³" << std::endl
              << "³                º  SNAKE COLOR:             <";

    if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((2 << 4) | (settings.setReturn(1))));//§¥«¥­ë© ä®­, ‡Œ…ˆ›‰ â¥ªáâ
    switch(settings.setReturn(1)){
        case RED:
            std::cout << "    RED    ";
            break;
        case BLUE:
            std::cout << "   BLUE    ";
            break;
        case GREEN:
            std::cout << "   GREEN   ";
            break;
        case CYAN:
            std::cout << "   CYAN    ";
            break;
        case YELLOW:
            std::cout << "  YELLOW   ";
            break;
        case WHITE:
            std::cout << "   WHITE   ";
            break;
    }
    if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << ">   º                ³"                                                          << std::endl
              << "³                º                                           º                ³" << std::endl
              << "³                º  MENU SOUND:              <";

    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    if(settings.setReturn(3)){
        std::cout << "    ON     ";
    }else{
        std::cout << "    OFF    ";
    }
    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << ">   º                ³"                                                          << std::endl
              << "³                º                                           º                ³" << std::endl
              << "³                º  GAME SOUND:              <";

    if(menu.top().field == 5) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    if(settings.setReturn(4)){
        std::cout << "    ON     ";
    }else{
        std::cout << "    OFF    ";
    }
    if(menu.top().field == 5) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << ">   º                ³"                                                          << std::endl
              << "³                º                                           º                ³" << std::endl
              << "³                º                     v                     º                ³" << std::endl
              << "³                º                                           º                ³" << std::endl
              << "³                ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼                ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                         ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                         ³" << std::endl
              << "³                         ³";

    if(menu.top().field == 6) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "          SAVE           ";
    if(menu.top().field == 6) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                         ³" << std::endl
              << "³                         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                         ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                         ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                         ³" << std::endl
              << "³                         ³";

    if(menu.top().field == 7) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "         <BACK           ";
    if(menu.top().field == 7) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                         ³" << std::endl
              << "³                         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                         ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" << std::endl;
    LeaveCriticalSection(&sc);
}

void Game::display_records_menu(){
    if(!settings.get_recordsInit()){
        if(!menu.top().opt.size()){
            menu.top().opt.push_back(0);
        }else{
            menu.top().opt[0] = 0;
        }
        std::cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿" << std::endl
                  << "³                                                                             ³" << std::endl
                  << "³                                   RECORDS                                   ³" << std::endl
                  << "³                                                                             ³" << std::endl
                  << "³                                  LOADING...                                 ³" << std::endl
                  << "³                                                                             ³" << std::endl
                  << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" << std::endl;
        settings.recordsRead();
        Sleep(500);
        system("cls");
        this->display_wallpaper();
    }
    std::cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                                   RECORDS                                   ³" << std::endl
              << "³                                                                             ³" << std::endl;

    uint16_t len = settings.recordsReturn().size();
    if(len){
        String str;
        uint8_t space;
        for(uint16_t i=menu.top().opt[0]; i<menu.top().opt[0]+5 && i<len; i++){
            str = "ü" + std::to_string(i+1);
            space = (71 - str.length())/2;
            std::cout << "³ ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» ³" << std::endl
                      << "³ º " << String(space, ' ') << str << String(71 - space - str.length(), ' ') << " º ³" << std::endl
                      << "³ º                                                                         º ³" << std::endl
                      << "³ º name: " << settings.recordsReturn()[i].name <<  String(65 - settings.recordsReturn()[i].name.length(), ' ') <<  " º ³" << std::endl
                      << "³ º                                                                         º ³" << std::endl
                      << "³ º level: " << settings.recordsReturn()[i].level <<  String(64 - settings.recordsReturn()[i].level.length(), ' ') <<  " º ³" << std::endl
                      << "³ º                                                                         º ³" << std::endl
                      << "³ º result: " << settings.recordsReturn()[i].result << String(63 - std::to_string(settings.recordsReturn()[i].result).length(), ' ') <<  " º ³" << std::endl
                      << "³ º                                                                         º ³" << std::endl
                      << "³ ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼ ³" << std::endl;
        }
    }else{
       std::cout << "³                              RECORDS NOT FOUND                              ³" << std::endl;
    }

    std::cout << "³                                                                             ³" << std::endl
              << "³                         ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                         ³" << std::endl
              << "³                         ³";

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "          <BACK          ";
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                         ³" << std::endl
              << "³                         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                         ³" << std::endl
              << "³             ";

    if(menu.top().opt[0] > 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 12));//á¨­¨© ä®­, ªà á­ë© â¥ªáâ
    std::cout << "<ÄÄÄÄÄÄÄ";
    if(menu.top().opt[0] > 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "                                   ";

    if(menu.top().opt[0] + 5 < settings.recordsReturn().size()) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 12));//á¨­¨© ä®­, ªà á­ë© â¥ªáâ
    std::cout << "ÄÄÄÄÄÄÄ>";
    if(menu.top().opt[0] + 5 < settings.recordsReturn().size()) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "             ³" << std::endl
              << "³                         ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                         ³" << std::endl
              << "³                         ³";
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "       DELETE ALL        ";
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                         ³" << std::endl
              << "³                         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                         ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" << std::endl;
}

void Game::display_info_menu(){
    EnterCriticalSection(&sc);
    std::cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿" << std::endl
              << "³                                                                             ³" << std::endl
              << "³            TYPA INFA, POTOM DOBAVIM                                         ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                          ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                        ³" << std::endl
              << "³                          ³";

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "          <BACK          ";
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                        ³" << std::endl
              << "³                          ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                        ³" << std::endl
              << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" << std::endl;
    LeaveCriticalSection(&sc);
}

void Game::display_exit_menu(){
    EnterCriticalSection(&sc);
    std::cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                             WHAT\'S THE MATTER?                              ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                           YOU WANT A SMOKE BREAK?                           ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³       ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸         ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸       ³" << std::endl
              << "³       ³";

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "           YES           ";
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³         ³";

    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "           NO            ";
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³       ³" << std::endl
              << "³       ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾       ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" << std::endl;
    LeaveCriticalSection(&sc);
}

void Game::display_records_clear_menu(){
    EnterCriticalSection(&sc);
    std::cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                             WHAT\'S THE MATTER?                              ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                        YOU WANT TO CLEAR YOUR FAILS?                        ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³       ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸         ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸       ³" << std::endl
              << "³       ³";

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "           NO            ";
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³         ³";

    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "           YES           ";
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³       ³" << std::endl
              << "³       ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾       ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" << std::endl;
    LeaveCriticalSection(&sc);
}

void Game::display_add_level_data_menu(){
    EnterCriticalSection(&sc);
    std::cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿"       << std::endl
              << "³                                                                             ³"       << std::endl
              << "³                                  ADD LEVEL                                  ³"       << std::endl
              << "³                                                                             ³"       << std::endl
              << "³ ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» ³"       << std::endl
              << "³ º                                                                         º ³"       << std::endl
              << "³ º       ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿  º ³"       << std::endl
              << "³ º ";

    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "PATH:";
    if(menu.top().field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    //60 symbols
    int32_t len = menu.top().stropt[0].length();
    if(len <= 60){
        std::cout << " ³ " << menu.top().stropt[0] << String(60 - len, ' ');
    }else{
        std::cout << " ³" << menu.top().stropt[0].substr(len-61, 61);
    }

    std::cout << " ³  º ³" << std::endl
              << "³ º       ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ  º ³"       << std::endl
              << "³ º                                                                         º ³"       << std::endl
              << "³ º        ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿                               º ³"       << std::endl
              << "³ º ";

    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "NAME:";
    if(menu.top().field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    //30 symbols
    len = menu.top().stropt[1].length();
    if(len <= 30){
        std::cout << "  ³ " << menu.top().stropt[1] << String(30 - len, ' ');
    }else{
        std::cout << "  ³" << menu.top().stropt[1].substr(len-31, 31);
    }

    std::cout << " ³                               º ³" << std::endl
              << "³ º        ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ                               º ³"       << std::endl
              << "³ º                                                                         º ³"       << std::endl
              << "³ º        ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿                               º ³"       << std::endl
              << "³ º ";

    if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "AUTHOR:";
    if(menu.top().field == 3) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    //30 symbols
    len = menu.top().stropt[2].length();
    if(len <= 30){
        std::cout << "³ " << menu.top().stropt[2] << String(30 - len, ' ');
    }else{
        std::cout << "³" << menu.top().stropt[2].substr(len-31, 31);
    }

    std::cout << " ³                               º ³"       << std::endl
              << "³ º        ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ                               º ³"       << std::endl
              << "³ º                                                                         º ³"       << std::endl
              << "³ º                       ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                       º ³"       << std::endl
              << "³ º                       ³";

    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "          SAVE           ";
    if(menu.top().field == 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                       º ³"       << std::endl
              << "³ º                       ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                       º ³"       << std::endl
              << "³ º                                                                         º ³"       << std::endl
              << "³ ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼ ³"       << std::endl
              << "³                                                                             ³"       << std::endl
              << "³                         ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                         ³"       << std::endl
              << "³                         ³";

    if(menu.top().field == 5) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std:: cout << "          <BACK          ";
    if(menu.top().field == 5) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                         ³"       << std::endl
              << "³                         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                         ³"       << std::endl
              << "³                                                                             ³"       << std::endl
              << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ"       << std::endl;
    LeaveCriticalSection(&sc);
}

void Game::eventExec(){
    //EnterCriticalSection(&sc);
    int8_t key;
    while(true){
        key = _getch();
        switch(menu.top().screen){
            case 0:
                this->event_main_menu(key);
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
            case 8:
                this->event_add_level_data_menu(key);
                break;
            default:
                break;
        }
    }
    //LeaveCriticalSection(&sc);
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
            menu.push(display(menu.top().field, 1));
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
                    break;
                case 3:
                    this->event_info_menu(key);
                    break;
                default:
                    break;
            }
            break;
        case 77://strelka vpravo
        case 75://strelka vlevo
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
            if(menu.top().field == 6){
                settings.setSave();
                menu.pop();
                system("cls");
                this->bell();
            }else if(menu.top().field == 7){
                menu.pop();
                system("cls");
                this->bell();
            }else{
                menu.top().field += 1;
            this->bell();
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
            this->display_menu();
            break;
        case 80://strelka vniz
            if(menu.top().field == 2){
                menu.top().field = 1;
            }else{
                menu.top().field = 2;
            }
            this->bell();
            this->display_menu();
            break;
        case 77://strelka vpravo
            if(menu.top().opt[0] + 5 < settings.recordsReturn().size()){
                menu.top().opt[0] += 5;
                this->bell();
                this->display_menu();
            }
            break;
        case 75://strelka vlevo
            if(menu.top().opt[0] > 4){
                menu.top().opt[0] -= 5;
                this->bell();
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
            if(menu.top().field == 2){
                menu.top().field = 1;
            }else{
                menu.top().field = 2;
            }
            this->bell();
            this->display_menu();
            break;
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
            this->bell();
        case 77://strelka vpravo
        case 75://strelka vlevo
            this->event_exit_menu(key);//€­ «®£¨ç­ ï ®¡à ¡®âª 
            break;
        case 13://enter
            if(menu.top().field == 2){
                settings.recordsClear();
                settings.recordsDelete();
            }
            this->event_info_menu(key);
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
            this->display_menu();
        }else if(key == 8){//backspace
            if(str.length()){
                str = str.substr(0, str.length()-1);
                this->display_menu();
            }
        }else if(key == 13){//enter
            menu.top().field += 1;
            this->bell();
            this->display_menu();
        }
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

void Game::draw_screen(uint32_t x, uint32_t y){
    COORD xory;
    xory.X = x;
    xory.Y = y;
    SetConsoleCursorPosition(console, xory);
}


Game::~Game(void){

}