#include "shape_info.h"

void get_shape_info(char* shape, char* info)
{
    int counter = 0;
    for (int i = 0; i < SHAPE_NAME_SIZE; i++) {
        if (((shape[i] >= '0') && (shape[i] <= '9')) || (shape[i] == '.')
            || (shape[i] == ' ')) {
            info[counter] = shape[i];
            counter++;
        }
    }
}
