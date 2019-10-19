#pragma once

class Settings{

    private:
        //Читаем значение из ini файла
        //[section]
        //key=...
        //При не удаче возвращает пустую строку
        String readIni(String section, String key);
        //Пишем значение в ini файл
        //[section]
        //key=value
        //Возвращает false если что-то пошло не так, true если всё удачно
        bool writeIni(String section, String key, String value);
        //Очистка секции
        //Возвращает false если что-то пошло не так, true если всё удачно
        bool clearSectionIni(String section);

        std::vector<record> records;
        void recordsSort();
        bool recordsInit;

        /*
        * 0-language:
        *  0 - english
        *  1 - russian
        *
        * 1-color
        *  (colors) RED, BLUE, GREEN, CYAN, YELLOW, WHITE
        *
        * 2-complex(сложность)
        *  [1; 10]
        *
        * 3-menu_sound
        *  1 - ON
        *  0 - OFF
        *
        * 4-game_sound
        *  1 - ON
        *  0 - OFF
        */
        std::vector<int16_t> set;
        //Инициализирует настройки
        //Возвращает true
        bool setRead();

        //Инициализирует список уровней
        //Возвращает true
        bool levelsRead();
        std::vector<String> lvl_list;

    public:
        Settings(void);
        //Инициализирует рекорды
        //Возвращает true если они есть, false если их нет
        bool recordsRead();
        //Возвращает ссылку на рекорды
        const std::vector<record> &recordsReturn();
        //Очищает рекорды, возвращает true
        bool recordsClear();
        //Возвращает инициализированы ли рекорды
        bool get_recordsInit();
        //Удаление рекордов из settings.ini
        //Возвращает false если что-то пошло не так, true если всё удачно
        bool recordsDelete();

        /*
        * Возвращает настройку
        * 0-language:
        *  0 - english
        *  1 - russian
        *
        * 1-color
        *  (colors) RED, BLUE, GREEN, CYAN, YELLOW, WHITE
        *
        * 2-complex(сложность)
        *  [1; 10]
        *
        * 3-menu_sound
        *  1 - ON
        *  0 - OFF
        *
        * 4-game_sound
        *  1 - ON
        *  0 - OFF
        */
        int16_t setReturn(int8_t i);
        //Сдвиг указанной настройки (i) на шаг(step) вправо или влево(step<0)
        //0-language, 1-color, 2-complex, 3-menu_sound, 4-game_sound
        bool setStep(int8_t i, int8_t step=1);
        //Сохраняет настройки
        //Возвращает false если что-то пошло не так, true если всё удачно
        bool setSave();

        std::vector<String> &levelsReturn();


        ~Settings(void);
};

