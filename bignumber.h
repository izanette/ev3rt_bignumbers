// bignumber.h
#pragma once
#include "ev3api.h"

#define DISTANCE_BETWEEN_NUMBERS  12  // in pixels

class BigNumber {
public:
    BigNumber();

    void draw(int number);

private:
    image_t number_imgs[10];
    int get_number_width(int i);
    int get_total_number_width(int i);

private:
    void load_images();
};
