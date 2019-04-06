#pragma once
#include "Snake.h"
#include "Box.h"

class Level{
    
    private:
        Snake snake;
        Box   box;

    public:
        uint8_t error;

        Level(String link = "");
        void analys(std::vector<String> &mapka);

        ~Level(void);
};

