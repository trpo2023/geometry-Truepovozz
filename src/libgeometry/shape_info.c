#include "shape_info.h"

void get_shape_info(char* shape, size_t size_of_shape_str, char* info)
{
    int counter = 0;
    for (int i = 0; i < size_of_shape_str; i++) {
        if (((shape[i] >= '0') && (shape[i] <= '9')) || (shape[i] == '.')
            || (shape[i] == ' ')) {
            info[counter] = shape[i];
            counter++;
        }
    }
}

