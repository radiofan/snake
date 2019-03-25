#pragma once
#include "Snake.h"
#include "Box.h"

class Level{
    
    private:
        Snake snake;
        Box   box;

    public:
        uint8_t error;

        Level(std::string link = "");
        void analys(std::vector<std::string> &mapka);

        ~Level(void);
};

