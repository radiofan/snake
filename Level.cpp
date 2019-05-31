#include "stdafx.h"
#include "addons.h"
#include "structures.h"

/*
Level::Level(String link){
    std::vector<String> mapka;
    if(link != ""){
        std::ifstream file_box(link, std::ios_base::in);
        if(!(file_box.is_open())){
            error = 0x01;//не удалось открыть файл
            return;
        }else{
            String str;
            while(!(file_box.eof())){
                getline(file_box, str);
                mapka.push_back(str);
            }
            file_box.close();
        }
    }else{
        mapka.resize(18);
        mapka[0] =  "11111111111111111111111111111111111111111";
        for(uint8_t i=1; i<17; ++i){
            mapka[i] =  "11000000000000000000000000000000000000011";
        }
        mapka[17] = "11111111111111111111111111111111111111111";
    }
    this->analys(mapka);
}
*/

Level::Level(std::vector<String> &lvl_list)
    :level_list(lvl_list){

}


ERORR &Level::save_level(std::vector<String> options){

    std::vector<String> file;
    this->read_file(options[0], file);
    
    if(error.success){
        if(analys_file(file)){
            std::ofstream lvl_out;
            String path = _T("./levels/level") + std::to_string(level_list.size()+1) + _T(".lvl");
            lvl_out.open(path, std::ios_base::out);
            if(!lvl_out.is_open()){
                error.success = 0;
                error.erorrs.push_back(err(0x01, "Don't create the level-file"));
            }else{
                for(uint16_t i=0; i<file.size(); i++){
                    lvl_out << file[i] << std::endl;
                }
                //вывод им€ карты и им€ автора
                lvl_out << options[1] << std::endl << options[2];
                lvl_out.close();
                box.create(file);
                level_list.push_back(path);
            }
        }
    }
    return error;
}

bool Level::read_file(String &path, std::vector<String> &ret){
    std::ifstream file(path, std::ios_base::in);
    if(!file.is_open()){
        error.success = 0;
        error.erorrs.push_back(err(0x01, _T("File don't opened!")));
        return false;
    }else{
        file.seekg(0, std::ios::end);
        double size = static_cast<double>(file.tellg()) / 8192;
        file.seekg(0, std::ios::beg);
        if(size > 512){
            error.success = 0;
            error.erorrs.push_back(err(0x02, _T("Filesize is above 0.5MB")));
            file.close();
            return false;
        }

        String str;
        while(!file.eof()){
            getline(file, str);
            ret.push_back(str);
        }
        file.close();
        return true;
    }
}

bool Level::analys_file(std::vector<String> &file){
    if(file.size() == 0){
        error.success = 0;
        error.erorrs.push_back(err(0x03, _T("File is empty")));
        return false;
    }
    uint16_t h = file.size();
    uint16_t w = file[0].length();
    if(w >= 80)
        error.erorrs.push_back(err(0x07, _T("Probable error in the map display")));
    space.reserve(h*w/2);
    uint32_t count = 0;
    bool start = false;
    for(uint32_t y=0; y < h; y++){
        if(file[y].length() != w){
            error.success = 0;
            error.erorrs.push_back(err(0x04, _T("Map is not a rectangle [String ") + std::to_string(y+1) + _T("]")));
            return false;
        }
        for(uint32_t x=0; x < w; x++){
            switch(file[y][x]){
                case ',':
                case '.':
                case ' ':
                    file[y][x] = '0';
                    space.push_back(coord(x, y));
                    count += 1;
                    break;
                case '-':
                case '#':
                    file[y][x] = '1';
                    break;
                case '^':
                case 'u':
                case 'U':
                    if(start){
                        file[y][x] = '0';
                        error.erorrs.push_back(err(0x05, _T("Unexpected start in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("]\n Replace to empty")));
                        space.push_back(coord(x, y));
                        count += 1;
                    }else{
                        file[y][x] = '2';
                        start = true;
                    }
                    break;
                case '>':
                case 'r':
                case 'R':
                    if(start){
                        file[y][x] = '0';
                        error.erorrs.push_back(err(0x05, _T("Unexpected start in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("]\n Replace to empty")));
                        space.push_back(coord(x, y));
                        count += 1;
                    }else{
                        file[y][x] = '3';
                        start = true;
                    }
                    break;
                case 'v':
                case 'V':
                case 'D':
                case 'd':
                    if(start){
                        file[y][x] = '0';
                        error.erorrs.push_back(err(0x05, _T("Unexpected start in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("]\n Replace to empty")));
                        space.push_back(coord(x, y));
                        count += 1;
                    }else{
                        file[y][x] = '4';
                        start = true;
                    }
                    break;
                case '<':
                case 'l':
                case 'L':
                    if(start){
                        file[y][x] = '0';
                        error.erorrs.push_back(err(0x05, _T("Unexpected start in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("]\n Replace to empty")));
                        space.push_back(coord(x, y));
                        count += 1;
                    }else{
                        file[y][x] = '5';
                        start = true;
                    }
                    break;
                case 's':
                case 'S':
                case '*':
                    if(start){
                        file[y][x] = '0';
                        error.erorrs.push_back(err(0x05, _T("Unexpected start in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("]\n Replace to empty")));
                        space.push_back(coord(x, y));
                        count += 1;
                    }else{
                        file[y][x] = '6';
                        start = true;
                    }
                    break;
                case '0':
                case '1':
                    break;
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                    if(start){
                        file[y][x] = '0';
                        error.erorrs.push_back(err(0x05, _T("Unexpected start in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("]\n Replace to empty")));
                        space.push_back(coord(x, y));
                        count += 1;
                    }else{
                        start = true;
                    }
                    break;
                default:
                    file[y][x] = '1';
                    error.erorrs.push_back(err(0x05, _T("Unexpected char in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("]\n Replace to wall")));
                    break;
            }
        }
    }
    space.resize(count);
    if(space.size() < 1){
        error.success = 0;
        error.erorrs.push_back(err(0x06, _T("Small amount of empty space")));
        return false;
    }
    return true;
}

Level::~Level(void){

}
