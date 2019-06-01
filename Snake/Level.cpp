#include "stdafx.h"
#include "addons.h"
#include "structures.h"

Level::Level(std::vector<String> &lvl_list, colors color)
    :snake(color), level_list(lvl_list), level_number(-1), level_name(_T("Луг")), level_author(_T("RADIOFAN")){
        box.create(map(15, std::vector<uint8_t>(30, 0)));
}


ERORR &Level::save_level(std::vector<String> options){

    std::vector<String> file;
    error.clear();
    level_name = options[1];
    level_author = options[2];
    level_number = -2;
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
                //вывод имя карты и имя автора
                lvl_out << options[1] << std::endl << options[2];
                lvl_out.close();
                box.create(file);
                level_list.push_back(path);
                level_number = level_list.size();
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
                        error.erorrs.push_back(err(0x05, _T("Unexpected start in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("] replace to empty")));
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
                        error.erorrs.push_back(err(0x05, _T("Unexpected start in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("] replace to empty")));
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
                        error.erorrs.push_back(err(0x05, _T("Unexpected start in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("] replace to empty")));
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
                        error.erorrs.push_back(err(0x05, _T("Unexpected start in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("] replace to empty")));
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
                        error.erorrs.push_back(err(0x05, _T("Unexpected start in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("] replace to empty")));
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
                        error.erorrs.push_back(err(0x05, _T("Unexpected start in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("] replace to empty")));
                        space.push_back(coord(x, y));
                        count += 1;
                    }else{
                        start = true;
                    }
                    break;
                default:
                    file[y][x] = '1';
                    error.erorrs.push_back(err(0x05, _T("Unexpected char in place [") + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("] replace to wall")));
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

String Level::get_level_option(uint8_t a){
    switch(a){
        case 0:
            return std::to_string(level_number + 1);
        case 1:
            return level_name;
        case 2:
            return level_author;
        default:
            return _T("ERORR! Level.cpp str# 200 ") + std::to_string(a);;
    }
}

void Level::level_draw(){
    CONSOLE_SCREEN_BUFFER_INFO info;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &info);
    WORD concolor = info.wAttributes;
    for(uint16_t y=0; y<box.get_h(); y++){
        SetConsoleTextAttribute(console, (WORD) ((2 << 4) | 0));//зелёный фон, черный текст
        for(uint16_t x=0; x<box.get_w(); x++){
            if(box.get_tile(x, y)){
                std::cout << '█';
            }else{
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
        SetConsoleTextAttribute(console, concolor);//вернем как было
    }
}


Level::~Level(void){

}
