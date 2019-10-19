#pragma once

class Settings{

    private:
        //������ �������� �� ini �����
        //[section]
        //key=...
        //��� �� ����� ���������� ������ ������
        String readIni(String section, String key);
        //����� �������� � ini ����
        //[section]
        //key=value
        //���������� false ���� ���-�� ����� �� ���, true ���� �� ������
        bool writeIni(String section, String key, String value);
        //������� ������
        //���������� false ���� ���-�� ����� �� ���, true ���� �� ������
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
        * 2-complex(���������)
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
        //�������������� ���������
        //���������� true
        bool setRead();

        //�������������� ������ �������
        //���������� true
        bool levelsRead();
        std::vector<String> lvl_list;

    public:
        Settings(void);
        //�������������� �������
        //���������� true ���� ��� ����, false ���� �� ���
        bool recordsRead();
        //���������� ������ �� �������
        const std::vector<record> &recordsReturn();
        //������� �������, ���������� true
        bool recordsClear();
        //���������� ���������������� �� �������
        bool get_recordsInit();
        //�������� �������� �� settings.ini
        //���������� false ���� ���-�� ����� �� ���, true ���� �� ������
        bool recordsDelete();

        /*
        * ���������� ���������
        * 0-language:
        *  0 - english
        *  1 - russian
        *
        * 1-color
        *  (colors) RED, BLUE, GREEN, CYAN, YELLOW, WHITE
        *
        * 2-complex(���������)
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
        //����� ��������� ��������� (i) �� ���(step) ������ ��� �����(step<0)
        //0-language, 1-color, 2-complex, 3-menu_sound, 4-game_sound
        bool setStep(int8_t i, int8_t step=1);
        //��������� ���������
        //���������� false ���� ���-�� ����� �� ���, true ���� �� ������
        bool setSave();

        std::vector<String> &levelsReturn();


        ~Settings(void);
};

