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
enum colors{
    RED = 4,
    BLUE = 9,
    GREEN = 10,
    CYAN = 11,
    YELLOW = 14,
    WHITE = 15
};

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
    bool success;
    std::vector<err> erorrs;
};

struct coord{
    coord(int32_t X=0, int32_t Y=0): x(X), y(Y){};
    int32_t x;
    int32_t y;
};

typedef std::vector<coord> empty_space;