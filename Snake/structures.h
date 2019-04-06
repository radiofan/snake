#pragma once

typedef void (*func)(int8_t key);

struct map{
     std::vector<std::vector<uint8_t>> box;
};

struct display{
    display(int8_t screen, int8_t field=1): screen(screen), field(field){};
    int8_t screen;
    int8_t field;
    std::vector<int32_t> opt;
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