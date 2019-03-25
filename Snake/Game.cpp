#include "stdafx.h"
#include "addons.h"
#include "structures.h"

extern CRITICAL_SECTION sc;

Game::Game(void)
    :done(0), menu(0), field(1), console(GetStdHandle(STD_OUTPUT_HANDLE)), events(&Game::eventExec, this){

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
    switch(menu){
        case 0:
            this->display_main_menu();
            break;
        case 1:
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

    if(field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "        NEW  GAME        ";
    if(field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                (\")      ³" << std::endl         
              << "³       \\\\                ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                //       ³"     << std::endl         
              << "³        \\\\                                                         //        ³"     << std::endl         
              << "³         ))              ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸              ((         ³"       << std::endl         
              << "³        //               ³";

    if(field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "        ADD LEVEL        ";
    if(field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³               \\\\        ³" << std::endl         
              << "³       //                ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                \\\\       ³"     << std::endl         
              << "³      ((                                                             ))      ³"       << std::endl         
              << "³       \\\\                ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                //       ³"     << std::endl         
              << "³        \\\\               ³";

    if(field == 3) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "         CUSTOMS         ";
    if(field == 3) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³               //        ³" << std::endl         
              << "³         ))              ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾              ((         ³"       << std::endl         
              << "³        //                                                         \\\\        ³"     << std::endl         
              << "³       //                ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                \\\\       ³"     << std::endl         
              << "³      ((                 ³";

    if(field == 4) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "         RECORDS         ";
    if(field == 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                 ))      ³" << std::endl         
              << "³       \\\\                ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                //       ³"     << std::endl         
              << "³        \\\\                                                         //        ³"     << std::endl         
              << "³         ))              ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸              ((         ³"       << std::endl         
              << "³        //               ³";

    if(field == 5) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "       INFORMATION       ";
    if(field == 5) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³               \\\\        ³" << std::endl         
              << "³       //                ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                \\\\       ³"     << std::endl         
              << "³      ((                                                             ))      ³"       << std::endl         
              << "³       \\\\                ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸                //       ³"     << std::endl         
              << "³        V                ³";

    if(field == 6) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "          EXIT           ";
    if(field == 6) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³                V        ³" << std::endl         
              << "³                         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾                         ³"       << std::endl         
              << "³                                                                             ³"       << std::endl         
              << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ"       << std::endl;
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

    if(field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "           YES           ";
    if(field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³         ³";

    if(field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//ªà á­ë© ä®­, ¡¥«ë© â¥ªáâ
    std::cout << "           NO            ";
    if(field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//á¨­¨© ä®­, ¡¥«ë© â¥ªáâ

    std::cout << "³       ³" << std::endl
              << "³       ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾         ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾       ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "³                                                                             ³" << std::endl
              << "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" << std::endl;
    LeaveCriticalSection(&sc);
}

void Game::eventExec(){
    //EnterCriticalSection(&sc);
    char key;
    while(true){
        key = _getch();
        switch(key){
            case 27://esc
                if(menu == 0){
                    menu = 1;
                }else if(menu == 1){
                    menu = 0;
                }
                field = 1;
                this->display_menu();
                break;

            case 72://strelka vverh
                if(menu == 0){
                    if(field == 1){
                        field = 6;
                    }else{
                        field -= 1;
                    }
                    this->display_menu();
                }
                break;

            case 80://strelka vniz
                if(menu == 0){
                    if(field == 6){
                        field = 1;
                    }else{
                        field += 1;
                    }
                    this->display_menu();
                }
                break;

            case 77://strelka vpravo
                if(menu == 1){
                    if(field == 2){
                        field = 1;
                    }else{
                        field = 2;
                    }
                    this->display_menu();
                }
                break;

            case 75://strelka vlevo
                if(menu == 1){
                    if(field == 1){
                        field = 2;
                    }else{
                        field = 1;
                    }
                    this->display_menu();
                }
                break;

            case 13://enter
                if(field == 6 && menu == 0){
                    field = 1;
                    menu = 1;
                    this->display_menu();
                }else if(field == 1 && menu == 1){
                    done = 1;
                }else if(field == 2 && menu == 1){
                    menu = 0;
                    field = 1;
                    this->display_menu();
                }
                break;

            default:
                break;
        }
    }
    //LeaveCriticalSection(&sc);
}


Game::~Game(void){

}