//cp866
#include "stdafx.h"
#include "addons.h"
#include "structures.h"
#include "UI_and_lang_constants.h"

Level::Level(std::vector<String> &lvl_list, int16_t &color, int16_t &lang)
    :snake(color), meat_ready(false), level_list(lvl_list), level_number(-1), lg(lang), generator(std::random_device()()){
        this->default_level();
}


ERORR &Level::save_level(std::vector<String> options){

    std::vector<String> file;

    this->data_clear();

    level_name = options[1];
    level_author = options[2];

    this->read_file(options[0], file);
    
    if(error.success){
        if(analys_file(file)){
            std::ofstream lvl_out;
            String path = _T("./levels/level") + std::to_string(level_list.size()+1) + _T(".lvl");
            lvl_out.open(path, std::ios_base::out);
            if(!lvl_out.is_open()){
                error.success = 0;
                error.erorrs.push_back(err(0x01, LANG::TEXT_ERR_CREATE[lg]));
            }else{
                for(uint16_t i=0; i<file.size(); i++){
                    lvl_out << file[i] << std::endl;
                }
                //вывод имя карты и имя автора
                lvl_out << options[1] << std::endl << options[2];
                lvl_out.close();
                box.create(file);
                level_list.push_back(path);
                level_number = level_list.size()-1;
            }
        }
    }
    return error;
}

bool Level::delete_level(){
    if(level_number < 0 || level_number >= (int64_t) level_list.size())
        return false;
    if(remove(level_list[level_number].c_str()) != 0){
        //неудача
        return false;
    }else{
        //успех
        int32_t del_ind = level_number;
        this->step_level(-1);
        level_list.erase(level_list.cbegin() + del_ind);
        String str;
        for(uint32_t i=0; i<level_list.size(); i++){
            str = ".\\levels\\level" + std::to_string(i+1) + ".lvl";
            if(level_list[i] != str){
                rename(level_list[i].c_str(), str.c_str());
                level_list[i] = str;
            }
        }
        return true;
    }
}

bool Level::read_file(String &path, std::vector<String> &ret){
    std::ifstream file(path, std::ios_base::in);
    if(!file.is_open()){
        error.success = 0;
        error.erorrs.push_back(err(0x01, LANG::TEXT_ERR_OPEN[lg]));
        return false;
    }else{
        file.seekg(0, std::ios::end);
        double size = static_cast<double>(file.tellg()) / 8192;
        file.seekg(0, std::ios::beg);
        if(size > 512){
            error.success = 0;
            error.erorrs.push_back(err(0x02, LANG::TEXT_ERR_ABOVE[lg]));
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
        error.erorrs.push_back(err(0x03, LANG::TEXT_ERR_EMPTY[lg]));
        return false;
    }
    uint16_t h = file.size();
    uint16_t w = file[0].length();
    if(w > 1500){
        error.success = 0;
        error.erorrs.push_back(err(0x07, LANG::TEXT_ERR_WIDTH[lg]));
        return false;
    }
    if(h > 1500){
        error.success = 0;
        error.erorrs.push_back(err(0x07, LANG::TEXT_ERR_HEIGHT[lg]));
        return false;
    }
    space.reserve(h*w/2);
    uint32_t count = 0;
    bool start = false;
    for(uint32_t y=0; y < h; y++){
        if(file[y].length() != w){
            error.success = 0;
            error.erorrs.push_back(err(0x04, LANG::TEXT_ERR_RECTANGLE[lg] + std::to_string(y+1) + _T("]")));
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
                case '2':
                case '^':
                case 'u':
                case 'U':
                    if(start){
                        file[y][x] = '0';
                        error.erorrs.push_back(err(0x05, LANG::TEXT_ERR_UNSTART_1[lg] + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + LANG::TEXT_ERR_UNSTART_2[lg]));
                        space.push_back(coord(x, y));
                        count += 1;
                    }else{
                        file[y][x] = '2';
                        error.erorrs.push_back(err(0x00, LANG::TEXT_ERR_USTART[lg] + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("]")));
                        start = true;
                        snake.set_start(coord(x, y), 0);
                    }
                    break;
                case '3':
                case '>':
                case 'r':
                case 'R':
                    if(start){
                        file[y][x] = '0';
                        error.erorrs.push_back(err(0x05, LANG::TEXT_ERR_UNSTART_1[lg] + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + LANG::TEXT_ERR_UNSTART_2[lg]));
                        space.push_back(coord(x, y));
                        count += 1;
                    }else{
                        file[y][x] = '3';
                        error.erorrs.push_back(err(0x00, LANG::TEXT_ERR_RSTART[lg] + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("]")));
                        start = true;
                        snake.set_start(coord(x, y), 1);
                    }
                    break;
                case '4':
                case 'v':
                case 'V':
                case 'D':
                case 'd':
                    if(start){
                        file[y][x] = '0';
                        error.erorrs.push_back(err(0x05, LANG::TEXT_ERR_UNSTART_1[lg] + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + LANG::TEXT_ERR_UNSTART_2[lg]));
                        space.push_back(coord(x, y));
                        count += 1;
                    }else{
                        file[y][x] = '4';
                        error.erorrs.push_back(err(0x00, LANG::TEXT_ERR_DSTART[lg] + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("]")));
                        start = true;
                        snake.set_start(coord(x, y), 2);
                    }
                    break;
                case '5':
                case '<':
                case 'l':
                case 'L':
                    if(start){
                        file[y][x] = '0';
                        error.erorrs.push_back(err(0x05, LANG::TEXT_ERR_UNSTART_1[lg] + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + LANG::TEXT_ERR_UNSTART_2[lg]));
                        space.push_back(coord(x, y));
                        count += 1;
                    }else{
                        file[y][x] = '5';
                        error.erorrs.push_back(err(0x00, LANG::TEXT_ERR_LSTART[lg] + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("]")));
                        start = true;
                        snake.set_start(coord(x, y), 3);
                    }
                    break;
                case '6':
                case 's':
                case 'S':
                case '*':
                    if(start){
                        file[y][x] = '0';
                        error.erorrs.push_back(err(0x05, LANG::TEXT_ERR_UNSTART_1[lg] + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + LANG::TEXT_ERR_UNSTART_2[lg]));
                        space.push_back(coord(x, y));
                        count += 1;
                    }else{
                        file[y][x] = '6';
                        error.erorrs.push_back(err(0x00, LANG::TEXT_ERR_RANDSTART[lg] + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + _T("]")));
                        start = true;
                        std::uniform_int_distribution<int8_t> dist(0, 3);
                        snake.set_start(coord(x, y), dist(generator));
                    }
                    break;
                case '0':
                    space.push_back(coord(x, y));
                    count += 1;
                    break;
                case '1':
                    break;
                default:
                    file[y][x] = '1';
                    error.erorrs.push_back(err(0x05, LANG::TEXT_ERR_UNCHAR_1[lg] + std::to_string(x+1) + _T("; ") + std::to_string(y+1) + LANG::TEXT_ERR_UNCHAR_2[lg]));
                    break;
            }
        }
    }
    if(!start)
        error.erorrs.push_back(err(0x00, LANG::TEXT_ERR_RANDOM[lg]));
    space.resize(count);
    if(space.size() < 10){
        error.success = 0;
        error.erorrs.push_back(err(0x06, LANG::TEXT_ERR_SPACE[lg]));
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
        /*
        case 3:
            if(level_number >= 0 && level_number < (int64_t) level_list.size()){
                return level_list[level_number];
            }else{
                return _T("");
            }
            */
        default:
            return _T("ERORR! Нет опции в level_option под номером ") + std::to_string(a);
    }
}

int32_t Level::get_level_number(){
    return level_number;
}

COORD Level::get_level_size(){
    COORD size;
    size.X = box.get_w();
    size.Y = box.get_h();
    return size;
}

void Level::level_draw(){
    if(!error.success){
        std::cout << "Не могу нарисовать уровень, анализ уровня не пройден!" << std::endl;
        system("pause");
        return;
    }
    CONSOLE_SCREEN_BUFFER_INFO info;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &info);
    WORD concolor = info.wAttributes;

    //int64_t time_color = -1;
    //bool draw_box = true;
    char next_char = 0;
    snake_slice slice(0, -1);

    for(uint16_t y=0; y<box.get_h(); y++){
        SetConsoleTextAttribute(console, (WORD) ((2 << 4) | 0));//зелёный фон, черный текст
        for(uint16_t x=0; x<box.get_w(); x++){
            //рисуем мясо
            if(slice.len == 0){
                SetConsoleTextAttribute(console, (WORD) ((2 << 4) | 0));//зелёный фон, черный текст
                slice.len -= 1;
            }else if(slice.len == 1){
                next_char = 0;
            }
            if(meat_ready && coord(x, y) == meat){
                SetConsoleTextAttribute(console, (WORD) ((2 << 4) | 5));//зелёный фон, лиловый текст
                //std::cout << "■ o O * @ Q . + ░ ¤ °";
                std::cout << '*';
                slice.len = 0;
                continue;
            }
            if(next_char){
                std::cout << next_char;
            }else{
                if(snake.is_ready())
                    slice = snake.get_snake_slice(coord(x, y));
                if(slice.len > 0 || slice.len == -2){
                    SetConsoleTextAttribute(console, (WORD) ((2 << 4) | snake.get_color()));//зелёный фон, ЗМЕИНЫЙ текст
                    std::cout << slice.symb;
                    if(slice.len > 2 || slice.len == -2){
                        next_char = snake.get_snake_slice(coord(x+1, y)).symb;
                    }
                }else{
                    if(box.get_tile(x, y)){
                        std::cout << '█';
                    }else{
                        std::cout << ' ';
                        //std::cout << y % 10;
                    }
                }
            }
            if(slice.len > 0)
                slice.len -= 1;
        }
        slice.len = -1;
        next_char = 0;
        SetConsoleTextAttribute(console, concolor);//вернем как было
        std::cout << std::endl;
    }
}

void Level::level_preview(){
    if(!error.success){
        std::cout << "Не могу нарисовать уровень, анализ уровня не пройден!" << std::endl;
        system("pause");
        return;
    }
    CONSOLE_SCREEN_BUFFER_INFO info;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &info);
    WORD concolor = info.wAttributes;
    coord snake_head = snake.get_snake_head();
    for(uint16_t y=0; y<box.get_h(); y++){
        SetConsoleTextAttribute(console, (WORD) ((2 << 4) | 0));//зелёный фон, черный текст
        for(uint16_t x=0; x<box.get_w(); x++){
            if(coord(x, y) == snake_head){
                SetConsoleTextAttribute(console, (WORD) ((2 << 4) | snake.get_color()));//зелёный фон, ЗМЕИНЫЙ текст
                std::cout << '@';
                SetConsoleTextAttribute(console, (WORD) ((2 << 4) | 0));//зелёный фон, черный текст
            }else if(box.get_tile(x, y)){
                std::cout << '█';
            }else{
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
        SetConsoleTextAttribute(console, concolor);//вернем как было
    }
}

void Level::default_level(){
    level_name = _T("Луг");
    level_author = _T("RADIOFAN");
    box.create(map(15, std::vector<uint8_t>(30, 0)));
    space.resize(450);
    for(uint8_t y=0; y<15; y++){
        for(uint8_t x=0; x<30; x++){
            space[y*30+x] = coord(x, y);
        }
    }
    /*
    snake.set_orient(0);
    //═║╔╗╚╝
    snake.angles.push_back(snake_piece(coord(2, 2), '═'));//конец

    snake.angles.push_back(snake_piece(coord(1, 2), '╚'));
    snake.angles.push_back(snake_piece(coord(1, 6), '╗'));
    snake.angles.push_back(snake_piece(coord(10, 6), '╔'));
    snake.angles.push_back(snake_piece(coord(10, 8), '╝'));
    snake.angles.push_back(snake_piece(coord(9, 8), '╚'));
    snake.angles.push_back(snake_piece(coord(9, 5), '╔'));
    snake.angles.push_back(snake_piece(coord(10, 5), '╝'));
    snake.angles.push_back(snake_piece(coord(10, 3), '╗'));
    snake.angles.push_back(snake_piece(coord(8, 3), '╔'));
    snake.angles.push_back(snake_piece(coord(8, 8), '╝'));
    snake.angles.push_back(snake_piece(coord(7, 8), '╚'));
    snake.angles.push_back(snake_piece(coord(7, 3), '╗'));
    snake.angles.push_back(snake_piece(coord(6, 3), '╔'));
    snake.angles.push_back(snake_piece(coord(6, 8), '╝'));
    snake.angles.push_back(snake_piece(coord(5, 8), '╚'));
    snake.angles.push_back(snake_piece(coord(5, 3), '╗'));
    snake.angles.push_back(snake_piece(coord(4, 3), '╔'));
    snake.angles.push_back(snake_piece(coord(4, 1), '╝'));
    snake.angles.push_back(snake_piece(coord(2, 1), '╚'));

    snake.angles.push_back(snake_piece(coord(2, 5), '║'));//начало
    snake.ready = true;
    */

    error.erorrs.push_back(err(0x00, LANG::TEXT_ERR_RANDOM[lg]));
}

ERORR &Level::step_level(int32_t step){
    //+1 это нулевой уровень
    int32_t shift = abs(step) % (level_list.size()+1);
    shift *= step / abs(step);
    shift += level_number;
    if(shift < -1){
        shift += level_list.size()+1;
    }else if(shift >= (int64_t) level_list.size()){
        shift -= level_list.size()+1;
    }
    this->load_level(shift);
    return error;
}

bool Level::load_level(int32_t ind){
    if(ind < -1 || ind >= (int64_t) level_list.size()){
        //TODO: убрать
        std::cout << "Не существует уровня под номером " << ind << std::endl;
        system("pause");
        return false;
    }
    this->data_clear();
    level_number = ind;
    if(level_number == -1){
        this->default_level();
        return true;
    }
    std::vector<String> mapka;
    if(this->read_file(level_list[level_number], mapka)){
        int32_t len = mapka.size();
        if(len < 2){
            error.success = 0;
            error.erorrs.push_back(err(0x06, LANG::TEXT_ERR_INFO[lg]));
        }else{
            //author
            level_author = mapka[len-1];
            //name
            level_name = mapka[len-2];
            mapka.pop_back();
            mapka.pop_back();
            if(this->analys_file(mapka)){
                box.create(mapka);
                return true;
            }
        }
    }
    return false;
}

void Level::data_clear(){
    error.clear();
    level_name = _T("");
    level_author = _T("");
    level_number = -2;
    space.resize(0);
    box.clear();
    snake.clear();
}


Level::~Level(void){

}
