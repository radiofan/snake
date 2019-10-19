//cp866
#pragma once

namespace UI{
    const String UP_BUTTON_0     = _T("�                         �������������������������͸                         �");
    const String DOWN_BUTTON_0   = _T("�                         �������������������������;                         �");
    const String MIDDLE_BUTTON_0 = _T("�                         �");

    const String UP_BUTTON_1     = _T("�       �������������������������͸         �������������������������͸       �");
    const String DOWN_BUTTON_1   = _T("�       �������������������������;         �������������������������;       �");
    
    const String UP_FRAME_0      = _T("�����������������������������������������������������������������������������Ŀ");
    const String MIDDLE_FRAME_0  = _T("�                                                                             �");
    const String DOWN_FRAME_0    = _T("�������������������������������������������������������������������������������");

    const String UP_FRAME_1      = _T("� �������������������������������������������������������������������������ͻ �");
    const String MIDDLE_FRAME_1  = _T("� �                                                                         � �");
    const String DOWN_FRAME_1    = _T("� �������������������������������������������������������������������������ͼ �");

    const String PIECE_0         = _T("� � ");
    const String PIECE_1         = _T(" � �");

}

/*
* ��䨪� BUTT_ ����砥� �� ����� ⥪�� ���� �������, ����� ����� 25 ᨬ�����, ��室���� �� ����
* ��䨪� WORD_ ����砥� �� ����� ⥪�� ����� 䨪�஢����� �����
* ��䨪� TEXT_ ����砥� �� ����� ⥪�� ����� ����� ���� �����
*
* 0-english
* 1-russian
*/
namespace LANG{
    const uint16_t lang_count = 2;

    const String BUTT_YES[lang_count]         = {_T("           YES           "), _T("           ��            ")};
    const String BUTT_NO[lang_count]          = {_T("           NO            "), _T("           ���           ")};
    const String BUTT_BACK[lang_count]        = {_T("          <BACK          "), _T("        ���������        ")};

    //display_main_menu
    const String BUTT_NEW_GAME[lang_count]    = {_T("        NEW  GAME        "), _T("       �����  ����       ")};
    const String BUTT_ADD_LVL[lang_count]     = {_T("        ADD LEVEL        "), _T("    ��������  �������    ")};//display_add_level_menu, display_add_level_data_menu
    const String BUTT_CUSTOMS[lang_count]     = {_T("         CUSTOMS         "), _T("        ���������        ")};//display_settings_menu
    const String BUTT_RECORDS[lang_count]     = {_T("         RECORDS         "), _T("         �������         ")};//display_records_menu
    const String BUTT_INFO[lang_count]        = {_T("       INFORMATION       "), _T("       ��� ������?       ")};
    const String BUTT_EXIT[lang_count]        = {_T("          EXIT           "), _T("          �����          ")};

    //display_level_choice
    const String BUTT_LVL_CHOICE[lang_count]  = {_T("      LEVEL  CHOICE      "), _T("      �����  ������      ")};
    const String BUTT_START[lang_count]       = {_T("          START          "), _T("         �������         ")};
    const String BUTT_PREVIEW[lang_count]     = {_T("         PREVIEW         "), _T("        ���������        ")};
    const String BUTT_DEL[lang_count]         = {_T("         DELETE          "), _T("         �������         ")};
    
    //display_add_level_menu
    const String BUTT_DEL_LVL[lang_count]     = {_T("      DELETE LEVELS      "), _T("     �������  ������     ")};
    
    //display_settings_menu
    const String BUTT_LANG[lang_count]        = {_T("         ENGLISH         "), _T("         �������         ")};
    const String BUTT_RED[lang_count]         = {_T("           RED           "), _T("         �������         ")};
    const String BUTT_BLUE[lang_count]        = {_T("          BLUE           "), _T("          �����          ")};
    const String BUTT_GREEN[lang_count]       = {_T("          GREEN          "), _T("         �������         ")};
    const String BUTT_CYAN[lang_count]        = {_T("          CYAN           "), _T("         �������         ")};
    const String BUTT_YELLOW[lang_count]      = {_T("         YELLOW          "), _T("         ������          ")};
    const String BUTT_WHITE[lang_count]       = {_T("          WHITE          "), _T("          �����          ")};
    const String BUTT_ON[lang_count]          = {_T("           ON            "), _T("           ���           ")};
    const String BUTT_OFF[lang_count]         = {_T("           OFF           "), _T("           ����          ")};
    const String BUTT_SAVE[lang_count]        = {_T("          SAVE           "), _T("        ���������        ")};

    //display_records_menu
    const String BUTT_LOAD[lang_count]        = {_T("        LOADING...       "), _T("       ��������...       ")};
    const String BUTT_NOT_FOUND[lang_count]   = {_T("    RECORDS NOT FOUND    "), _T("���������� �� ���������� ")};
    const String BUTT_DEL_ALL[lang_count]     = {_T("       DELETE  ALL       "), _T("       ������� ���       ")};

    //display_level_preview
    const String BUTT_LVL_PREV[lang_count]    = {_T("      LEVEL PREVIEW      "), _T("    ���������  ������    ")};

    //display_delete_menu
    const String BUTT_WELL[lang_count]        = {_T("          WELL           "), _T("         �������         ")};


    //2-symbols
    //display_wallpaper
    const String WORD_BY[lang_count]               = {_T("by"), _T("��")};

    //6-symbols
    //display_level_choice
    //display_add_level_data_menu
    //display_level_choice
    const String WORD_NAME[lang_count]        = {_T("NAME: "), _T("���:  ")};

    //6-symbols
    //display_add_level_data_menu
    const String WORD_PATH[lang_count]        = {_T("PATH: "), _T("����: ")};

    //9-symbols
    //display_records_menu
    const String WORD_LVL[lang_count]         = {_T("LEVEL:   "), _T("�������: ")};

    //11-symbols
    //display_records_menu
    const String WORD_RESULT[lang_count]      = {_T("RESULT:    "), _T("���������: ")};

    //8-symbols
    //display_level_choice
    //display_add_level_data_menu
    //display_level_choice
    const String WORD_AUTHOR[lang_count]      = {_T("AUTHOR: "), _T("�����:  ")};

    //12-symbols
    //display_level_choice
    //display_level_preview
    const String WORD_NOTICE[lang_count]      = {_T("NOTICE:     "), _T("����������: ")};

    //25-symbols
    //display_level_choice
    const String WORD_FATAL_ERROR[lang_count] = {_T("!!!FATAL ERROR!!!        "), _T("!!!������������ ������!!!")};

    //25-symbols
    //display_settings_menu
    const String WORD_COMPLEX[lang_count]     = {_T("COMPLEXITY:              "), _T("���������:               ")};

    //25-symbols
    //display_settings_menu
    const String WORD_LANGUAGE[lang_count]    = {_T("LANGUAGE:                "), _T("���� ����:               ")};

    //25-symbols
    //display_settings_menu
    const String WORD_SNAKE_COLOR[lang_count] = {_T("SNAKE COLOR:             "), _T("���� ����:               ")};

    //25-symbols
    //display_settings_menu
    const String WORD_MENU_SOUND[lang_count]  = {_T("MENU SOUND:              "), _T("���� ����:               ")};

    //25-symbols
    //display_settings_menu
    const String WORD_GAME_SOUND[lang_count]  = {_T("GAME SOUND:              "), _T("���� ����:               ")};

    //75-symbols
    //display_exit_menu
    //display_records_clear_menu
    //display_delete_menu
    const String WORD_WHAT_HAP[lang_count]    = {_T("                            WHAT\'S THE MATTER?                             "), _T("                               ��� ���������?                              ")};

    //75-symbols
    //display_exit_menu
    const String WORD_EXIT_1[lang_count]      = {_T("                          YOU WANT A SMOKE BREAK?                          "), _T("                          ������ �������� �������?                         ")};

    //75-symbols
    //display_records_clear_menu
    const String WORD_CLEAR_1[lang_count]     = {_T("                       YOU WANT TO CLEAR YOUR FAILS?                       "), _T("                       ������ �������� ���� �������?                       ")};

    //75-symbols
    //display_delete_menu
    const String WORD_DELETE_1[lang_count]    = {_T("                       YOU WANT TO DELETE THIS LEVEL?                      "), _T("                       ������ �������� ���� �������?                       ")};
    
    //75-symbols
    //display_delete_menu
    const String WORD_DELETE_2[lang_count]    = {_T("                              SUCCESS DELETED                              "), _T("                              ������� �������                              ")};
    
    //75-symbols
    //display_delete_menu
    const String WORD_DELETE_3[lang_count]    = {_T("                              DELETED  FAILED                              "), _T("                             �������� ��������                             ")};


    //display_level_choice
    const String TEXT_ERROR[lang_count]       = {_T("ERORR"), _T("������")};

    //display_info_menu
    const String TEXT_GAME_INFO[lang_count]   = {_T("Iformation add potom"), _T("���ଠ�� ������ �� ��⮬ ������� ������������� ������������������� ����sdddd dddrr rdssser sss")};

    //save_level
    const String TEXT_ERR_CREATE[lang_count]    = {_T("Don\'t create the level-file"), _T("�� ���� ᮧ���� 䠩� �஢��")};

    //read_file
    const String TEXT_ERR_OPEN[lang_count]      = {_T("File don't opened!"), _T("�� ���� ������ 䠩�!")};
    const String TEXT_ERR_ABOVE[lang_count]     = {_T("Filesize is above 0.5MB"), _T("������ 䠩�� �ॢ�蠥� 0,5 ��")};

    //analys_file
    const String TEXT_ERR_EMPTY[lang_count]     = {_T("File is empty"), _T("���� ����")};
    const String TEXT_ERR_WIDTH[lang_count]     = {_T("Map width more than 1500"), _T("��ਭ� ����� �ॢ�蠥� 1500 �祥�")};
    const String TEXT_ERR_HEIGHT[lang_count]    = {_T("Map height more than 1500"), _T("���� ����� �ॢ�蠥� 1500 �祥�")};
    const String TEXT_ERR_RECTANGLE[lang_count] = {_T("Map is not a rectangle [String "), _T("���� �� ���� ��אַ㣮�쭨��� [��ப� ")};
    const String TEXT_ERR_UNSTART_1[lang_count] = {_T("Unexpected start in place ["), _T("���������� ���� � ���न���� [")};
    const String TEXT_ERR_UNSTART_2[lang_count] = {_T("] replace to empty"), _T("] ������� �� ������ �����")};
    const String TEXT_ERR_USTART[lang_count]    = {_T("Start UP in place ["), _T("���� ����� � ���न���� [")};
    const String TEXT_ERR_RSTART[lang_count]    = {_T("Start RIGHT in place ["), _T("���� ������ � ���न���� [")};
    const String TEXT_ERR_DSTART[lang_count]    = {_T("Start DOWN in place ["), _T("���� ���� � ���न���� [")};
    const String TEXT_ERR_LSTART[lang_count]    = {_T("Start LEFT in place ["), _T("���� ����� � ���न���� [")};
    const String TEXT_ERR_RANDSTART[lang_count] = {_T("Start RANDOM in place ["), _T("��������� ���� � ���न���� [")};
    const String TEXT_ERR_RANDOM[lang_count]    = {_T("Start RANDOM in random place"), _T("��������� ���� � ��砩��� ����")};//default_level
    const String TEXT_ERR_UNCHAR_1[lang_count]  = {_T("Unexpected char in place ["), _T("���������� ᨬ��� � ���न���� [")};
    const String TEXT_ERR_UNCHAR_2[lang_count]  = {_T("] replace to wall"), _T("] ������� �� �⥭�")};
    const String TEXT_ERR_SPACE[lang_count]     = {_T("Small amount of empty space"), _T("����� ������⢮ ���⮣� ����࠭�⢠")};

    //load_level
    const String TEXT_ERR_INFO[lang_count]      = {_T("File haven't additional information"), _T("���� �� ����� ��⥬��� ���ଠ樨")};
}