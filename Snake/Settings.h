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


        ~Settings(void);
};

