#include "stdafx.h"
#include "addons.h"
#include "structures.h"


Settings::Settings(void)
    :recordsInit(false), set(5){
        this->setRead();
}

bool Settings::recordsRead(){
    String str;
    uint16_t count = 0;
    str = this->readIni(_T("records"), _T("count"));
    if(str == _T("")){
        this->writeIni(_T("records"), _T("count"), _T("0"));
    }else{
        count = std::stoul(str.substr(0,4));
    }
    records.resize(count);
    for(uint16_t i=0; i<count; i++){
        records[i].name = this->readIni(_T("records"), _T("name")+std::to_string(i)).substr(0, 65);
        records[i].level = this->readIni(_T("records"), _T("level")+std::to_string(i)).substr(0, 62);
        str = this->readIni(_T("records"), _T("result")+std::to_string(i)).substr(0, 18);
        try{
            records[i].result = std::stoull(str);
        }catch(std::invalid_argument& a){
            records[i].result = 0;
        }
    }
    recordsInit = true;
    if(count){
        this->recordsSort();
        return true;
    }else{
        return false;
    }
}

void Settings::recordsSort(){
    record a;
    uint16_t len = records.size();
    for(uint16_t i=1; i<len; i++){
    bool flag = true;
        for(uint16_t i1=1; i1<len; i1++){
            if(records[i1].result > records[i1-1].result){
                flag = false;
                a.level = records[i1-1].level;
                a.name = records[i1-1].name;
                a.result = records[i1-1].result;
                records[i1-1].level = records[i1].level;
                records[i1-1].name = records[i1].name;
                records[i1-1].result = records[i1].result;
                records[i1].level = a.level;
                records[i1].name = a.name;
                records[i1].result = a.result;
            }
        }
        if(flag)
            break;
    }
}

const std::vector<record> &Settings::recordsReturn(){
    return records;
}

bool Settings::recordsClear(){
    recordsInit = false;
    records.clear();
    return true;
}

bool Settings::recordsDelete(){
    return this->clearSectionIni(_T("records"));
}

bool Settings::get_recordsInit(){
    return recordsInit;
}


bool Settings::setRead(){
    String str;
    //0-language
    str = this->readIni(_T("settings"), _T("language"));
    if(str == _T("rus")){
        set[0] = 1;
    }else if(str == _T("en")){
        set[0] = 0;
    }else{
        this->writeIni(_T("settings"), _T("language"), _T("en"));
        set[0] = 0;
    }
    //1-color
    str = this->readIni(_T("settings"), _T("color"));
    if(str == _T("RED")){
        set[1] = RED;
    }else if(str == _T("BLUE")){
        set[1] = BLUE;
    }else if(str == _T("GREEN")){
        set[1] = GREEN;
    }else if(str == _T("CYAN")){
        set[1] = CYAN;
    }else if(str == _T("YELLOW")){
        set[1] = YELLOW;
    }else if(str == _T("WHITE")){
        set[1] = WHITE;
    }else{
        this->writeIni(_T("settings"), _T("color"), _T("GREEN"));
        set[1] = GREEN;
    }
    //2-complex
    str = _T("0") + this->readIni(_T("settings"), _T("complex"));
    int16_t a;
    a = std::stoi(str.substr(0, 4));
    if(a > 0 && a <= 10){
        set[2] = a;
    }else{
        this->writeIni(_T("settings"), _T("complex"), _T("1"));
        set[2] = 1;
    }
    //3-menu_sound
    str = this->readIni(_T("settings"), _T("menu_sound"));
    if(str == "1"){
        set[3] = 1;
    }else if(str == "0"){
        set[3] = 0;
    }else{
        set[3] = 1;
        this->writeIni(_T("settings"), _T("menu_sound"), _T("1"));
    }
    //4-game_sound
    str = this->readIni(_T("settings"), _T("game_sound"));
    if(str == "1"){
        set[4] = 1;
    }else if(str == "0"){
        set[4] = 0;
    }else{
        set[4] = 1;
        this->writeIni(_T("settings"), _T("game_sound"), _T("1"));
    }
    return true;
}

int16_t Settings::setReturn(int8_t i){
    return set.at(i);
}

bool Settings::setStep(int8_t i, int8_t step){
    int8_t shift;
    colors arr[6] = {RED, BLUE, GREEN, CYAN, YELLOW, WHITE};
    switch(i){
        case 0:
        case 3:
        case 4:
            shift = step % 2;
            if(set[i]*2-1 == shift){
                set[i] = (set[i]+2+shift) % 2;
            }else{
                set[i] += shift;
            }
            break;
        case 1:
            shift = step % 6;
            if(shift == 0)
                return true;
            switch(set[1]){
                case RED:
                    shift += 1;
                    break;
                case BLUE:
                    shift += 2;
                    break;
                case GREEN:
                    shift += 3;
                    break;
                case CYAN:
                    shift += 4;
                    break;
                case YELLOW:
                    shift += 5;
                    break;
                case WHITE:
                    shift += 6;
                    break;
            }
            if(shift > 6)
                shift -= 6;
            if(shift <= 0)
                shift += 6;
            set[1] = arr[shift-1];
            break;
        case 2:
            shift = step % 10;
            shift += set[2];
            if(shift > 10)
                shift -= 10;
            if(shift <= 0)
                shift += 10;
            set[2] = shift;
            break;
        default:
            return false;
            break;
    }
    return true;
}

bool Settings::setSave(){
    //this->writeIni(_T("settings"), _T(""), _T(""));
    String str;
    bool ret = true;
    //0-language
    if(set[0]){
        str = _T("rus");
    }else{
        str = _T("en");
    }
    if(this->writeIni(_T("settings"), _T("language"), str) != 0)
        ret = false;
    //1-color
    switch(set[1]){
        case RED:
            str = _T("RED");
            break;
        case BLUE:
            str = _T("BLUE");
            break;
        case GREEN:
            str = _T("RED");
            break;
        case CYAN:
            str = _T("CYAN");
            break;
        case YELLOW:
            str = _T("YELLOW");
            break;
        case WHITE:
            str = _T("WHITE");
            break;
    }
    if(this->writeIni(_T("settings"), _T("color"), str) != 0)
        ret = false;
    //2-complex
    if(this->writeIni(_T("settings"), _T("complex"), std::to_string(set[2])) != 0)
        ret = false;
    //3-menu_sound
    if(this->writeIni(_T("settings"), _T("menu_sound"), std::to_string(set[3])) != 0)
        ret = false;
    //4-game_sound
    if(this->writeIni(_T("settings"), _T("game_sound"), std::to_string(set[4])) != 0)
        ret = false;
    return ret;
}


//Работает с кодировкой DOS 866, потому что лень париться с кодировкой
String Settings::readIni(String section, String key){
    LPTSTR out = new TCHAR[256];
    LPCTSTR sec = section.c_str();
    LPCTSTR k = key.c_str();
    GetPrivateProfileString(
        sec,
        k,
        _T(""),
        out,
        255,
        _T(".\\settings.ini")//Файл лежит в той же папке, что и исполняемый
    );
    String str(out);
    delete[] out;
    out = nullptr;
    return str;
}

bool Settings::writeIni(String section, String key, String value){
    LPCTSTR sec = section.c_str();
    LPCTSTR k = key.c_str();
    LPCTSTR val = value.c_str();
    if(WritePrivateProfileString(
        sec,
        k,
        val,
        _T(".\\settings.ini")
    ) != 0){
        return true;
    }
    return false;
}

bool Settings::clearSectionIni(String section){
    LPCTSTR sec = section.c_str();
    if(WritePrivateProfileSection(
        sec,
        NULL,
        _T(".\\settings.ini")
    ) != 0){
        return true;
    }
    return false;
}


Settings::~Settings(void){

}
