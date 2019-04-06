#include "stdafx.h"
#include "addons.h"
#include "structures.h"


Settings::Settings(void)
    :recordsInit(false){
    
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

std::vector<record> &Settings::recordsReturn(){
    return records;
}

bool Settings::recordsClear(){
    recordsInit = false;
    records.clear();
    return true;
}

bool Settings::get_recordsInit(){
    return recordsInit;
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
