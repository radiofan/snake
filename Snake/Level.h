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

        int32_t lg;

        //Читает построчно файл в вектор ret
        //Ошибки в error
        bool read_file(String &path, std::vector<String> &ret);
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
        * 7 - возможны ошибки в отображении карты
        */
        ERORR error;

        //Level(String link = "");
        
        Level(std::vector<String> &lvl_list, colors color, int32_t lang);
        //Создает карту box из вектора строк
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
        //удаляет активный уровень
        //true - успех
        //false - неудача
        bool delete_level();

        /*
        * Возвращает
        * 0 - level_number + 1
        * 1 - level_name
        * 2 - level_author
        */
        String get_level_option(uint8_t a=0);
        //Возвращает level_number
        int32_t get_level_number();

        COORD get_level_size();

        ERORR &step_level(int32_t step=1);
        
        bool load_level(int32_t ind = -1);

        void level_draw();

        void default_level();


        ~Level(void);
};

