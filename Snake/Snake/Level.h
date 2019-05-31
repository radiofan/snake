#pragma once
#include "Snake.h"
#include "Box.h"

class Level{
    
    private:
        Snake snake;
        Box   box;
        empty_space space;

        std::vector<String> &level_list;

        //Читает построчно файл
        //Ошибки в error
        std::vector<String> read_file(String &path);
        /*
        * Получает результат read_file() и анализирует его
        * Ошибки в error
        */
        bool analys_file(std::vector<String> &file);

    public:
        /*
        * 0 - успех
        * 1 - файл не открыт
        * 2 - вес файла превышает 0,5 МБ
        * 3 - файл пуст
        * 4 - поле не является прямоугольником
        * 5 - внесение изменений в карту
        * 6 - поле для змейки мало
        * 7 - возмжны ошибки в отображении карты
        */
        ERORR error;

        //Level(String link = "");
        
        Level(std::vector<String> &lvl_list);
        //Создает карту box из вектора строк, также проверяет её на ошибки
        //Возвращает код ошибки
        //0 - успех
        uint8_t generate(std::vector<String> &mapka);
        /*
        * Сохраняет карту в нужном виде в папке levels
        * Возвращет ссылку на ошибку
        *
        * options[0] - path
        * options[1] - map name
        * options[2] - author
        */
        ERORR &save_level(std::vector<String> options);


        ~Level(void);
};

