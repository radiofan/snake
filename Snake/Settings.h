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


        ~Settings(void);
};

