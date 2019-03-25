#include "stdafx.h"
#include "addons.h"
#include "structures.h"

extern CRITICAL_SECTION sc;

Game::Game(void)
    :done(0), menu(0), field(1), console(GetStdHandle(STD_OUTPUT_HANDLE)), events(&Game::eventExec, this){

    system("color 17");//�᭮���� ����� - ᨭ�� 䮭, ���� ⥪��
    
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
    //SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//��ࢠ� 䮭, ���� ⥪��
    // C -�મ���� 䮭 (12)
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
    std::cout << "�����������������������������������������������������������������������������Ŀ"       << std::endl         
              << "�                                                                             �"       << std::endl         
              << "�                     .-=-.          .--.                    _                �"       << std::endl         
              << "�         __        .'     '.       / �� )                  � � by RADIOFAN   �"       << std::endl         
              << "� _     .'  '.     /   .-.   \\     /  .-'    ___ _ __   __ _� � _____         �"      << std::endl         
              << "�( \\   / .-.  \\   /   /   \\   \\   /  /      / __� '_ \\ / _` � �/ / _ \\        �" << std::endl         
              << "� \\ `-` /   \\  `-'   /     \\   `-`  /       \\__ \\ � � � (_� �   <  __/        �"  << std::endl         
              << "�  `-.-`     '.____.'       `.____.'        �___/_� �_�\\__,_�_�\\_\\___�        �"    << std::endl         
              << "�                                                                             �"       << std::endl         
              << "�������������������������������������������������������������������������������"       << std::endl;
}

void Game::display_main_menu(){
    EnterCriticalSection(&sc);
    std::cout << "�����������������������������������������������������������������������������Ŀ"       << std::endl         
              << "�                                                                             �"       << std::endl         
              << "�       Y                 �������������������������͸                 Y       �"       << std::endl         
              << "�      (\")                �";

    if(field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//���� 䮭, ���� ⥪��
    std::cout << "        NEW  GAME        ";
    if(field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//ᨭ�� 䮭, ���� ⥪��

    std::cout << "�                (\")      �" << std::endl         
              << "�       \\\\                �������������������������;                //       �"     << std::endl         
              << "�        \\\\                                                         //        �"     << std::endl         
              << "�         ))              �������������������������͸              ((         �"       << std::endl         
              << "�        //               �";

    if(field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//���� 䮭, ���� ⥪��
    std::cout << "        ADD LEVEL        ";
    if(field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//ᨭ�� 䮭, ���� ⥪��

    std::cout << "�               \\\\        �" << std::endl         
              << "�       //                �������������������������;                \\\\       �"     << std::endl         
              << "�      ((                                                             ))      �"       << std::endl         
              << "�       \\\\                �������������������������͸                //       �"     << std::endl         
              << "�        \\\\               �";

    if(field == 3) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//���� 䮭, ���� ⥪��
    std::cout << "         CUSTOMS         ";
    if(field == 3) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//ᨭ�� 䮭, ���� ⥪��

    std::cout << "�               //        �" << std::endl         
              << "�         ))              �������������������������;              ((         �"       << std::endl         
              << "�        //                                                         \\\\        �"     << std::endl         
              << "�       //                �������������������������͸                \\\\       �"     << std::endl         
              << "�      ((                 �";

    if(field == 4) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//���� 䮭, ���� ⥪��
    std::cout << "         RECORDS         ";
    if(field == 4) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//ᨭ�� 䮭, ���� ⥪��

    std::cout << "�                 ))      �" << std::endl         
              << "�       \\\\                �������������������������;                //       �"     << std::endl         
              << "�        \\\\                                                         //        �"     << std::endl         
              << "�         ))              �������������������������͸              ((         �"       << std::endl         
              << "�        //               �";

    if(field == 5) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//���� 䮭, ���� ⥪��
    std::cout << "       INFORMATION       ";
    if(field == 5) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//ᨭ�� 䮭, ���� ⥪��

    std::cout << "�               \\\\        �" << std::endl         
              << "�       //                �������������������������;                \\\\       �"     << std::endl         
              << "�      ((                                                             ))      �"       << std::endl         
              << "�       \\\\                �������������������������͸                //       �"     << std::endl         
              << "�        V                �";

    if(field == 6) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//���� 䮭, ���� ⥪��
    std::cout << "          EXIT           ";
    if(field == 6) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//ᨭ�� 䮭, ���� ⥪��

    std::cout << "�                V        �" << std::endl         
              << "�                         �������������������������;                         �"       << std::endl         
              << "�                                                                             �"       << std::endl         
              << "�������������������������������������������������������������������������������"       << std::endl;
    LeaveCriticalSection(&sc);
}

void Game::display_exit_menu(){
    EnterCriticalSection(&sc);
    std::cout << "�����������������������������������������������������������������������������Ŀ" << std::endl
              << "�                                                                             �" << std::endl
              << "�                             WHAT\'S THE MATTER?                              �" << std::endl
              << "�                                                                             �" << std::endl
              << "�                           YOU WANT A SMOKE BREAK?                           �" << std::endl
              << "�                                                                             �" << std::endl
              << "�                                                                             �" << std::endl
              << "�       �������������������������͸         �������������������������͸       �" << std::endl
              << "�       �";

    if(field == 1) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//���� 䮭, ���� ⥪��
    std::cout << "           YES           ";
    if(field == 1) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//ᨭ�� 䮭, ���� ⥪��

    std::cout << "�         �";

    if(field == 2) SetConsoleTextAttribute(console, (WORD) ((12 << 4) | 7));//���� 䮭, ���� ⥪��
    std::cout << "           NO            ";
    if(field == 2) SetConsoleTextAttribute(console, (WORD) ((1 << 4) | 7));//ᨭ�� 䮭, ���� ⥪��

    std::cout << "�       �" << std::endl
              << "�       �������������������������;         �������������������������;       �" << std::endl
              << "�                                                                             �" << std::endl
              << "�                                                                             �" << std::endl
              << "�������������������������������������������������������������������������������" << std::endl;
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