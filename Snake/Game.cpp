#include "stdafx.h"
#include "addons.h"
#include "structures.h"

extern CRITICAL_SECTION sc;

Game::Game(void)
    :done(0), console(GetStdHandle(STD_OUTPUT_HANDLE)), events(&Game::eventExec, this){

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
    system("cls");
    this->display_wallpaper();
    //SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//¯¥à¢ ï ä®­, ¢â®à ï â¥ªáâ
    // C -ïàª®ªà á­ë© ä®­ (12)
    switch(menu.top().screen){
        case 0:
            this->display_main_menu();
            break;
        case 4:
            this->display_records_menu();
            break;
        case 5:
            this->display_info_menu();
            break;
        case 6:
            this->display_exit_menu();
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
        Sleep(1000);
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
    std::cout << "           OK            ";
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
    std::cout << "         DELETE          ";
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
    std::cout << "           OK            ";
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

void Game::eventExec(){
    //EnterCriticalSection(&sc);
    int8_t key;
    while(true){
        key = _getch();
        switch(menu.top().screen){
            case 0:
                this->event_main_menu(key);
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
            this->display_menu();
            break;
        case 77://strelka vpravo
        case 75://strelka vlevo
        default:
            break;
    }
}

void Game::event_records_menu(int8_t key){
    switch(key){
        case 27://esc
            menu.pop();
            settings.recordsClear();
            this->bell();
            this->display_menu();
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
                menu.pop();
                settings.recordsClear();
                this->bell();
                this->display_menu();
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


Game::~Game(void){

}