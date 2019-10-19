#pragma once

//typedef void (*func)(int8_t key);

typedef std::vector<std::vector<uint8_t>> map;

/*
struct map{
     std::vector<std::vector<uint8_t>> box;
};
*/

struct display{
    display(int8_t screen, int8_t field=1): screen(screen), field(field){};
    int8_t screen;
    int8_t field;
    std::vector<int32_t> opt;
    std::vector<String> stropt;
    //func hand;
};

//змея(9, 4, A, B, E, F)
/*
enum colors{
    RED = 4,
    BLUE = 9,
    GREEN = 10,
    CYAN = 11,
    YELLOW = 14,
    WHITE = 15
};
*/

struct record{
    record(String name=_T("%NONAME%"), String level=_T("%NOLEVEL%"), uint64_t result=0): name(name, 0, 65), level(level, 0, 62), result(result){};
    String name;
    String level;
    uint64_t result;
};

struct err{
    err(uint8_t cod, String mess): key(cod), message(mess){};
    uint8_t key;
    String message;
};

struct ERORR{
    ERORR(bool suc = 1): success(suc){};
    void clear(){
        success = true;
        erorrs.clear();
    }
    bool success;
    std::vector<err> erorrs;
};

struct coord{
    coord(int32_t X=0, int32_t Y=0): x(X), y(Y){};
    int32_t x;
    int32_t y;
};
coord operator+ (const coord &c1, const coord &c2);
coord operator- (const coord &c1, const coord &c2);
bool operator== (const coord &c1, const coord &c2);

//Хранит координаты углов, начала и конца; также символ
struct snake_piece{
    snake_piece(coord locate=coord(-1, -1), char symbol=0): location(locate), symb(symbol){};
    coord location;
    char symb;
};

//Хранит символ змеи и длину покраски змеи
struct snake_slice{
    snake_slice(char symbol, int64_t length): symb(symbol), len(length){};
    char symb;
    int64_t len;
};

typedef std::vector<coord> empty_space;