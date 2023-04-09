#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "geometry.h"
#include <libgeometry/syntax.h>
#include <libgeometry/shape_info.h>

#define SHAPE_NAME_SIZE 50
#define SHAPE_INFO_SIZE 20

int main(int argc, char* argv[])
{
    int bool = 0;
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Didn`t open\n");
        return -1;
    }
    char shape[SHAPE_NAME_SIZE];
    char info[SHAPE_INFO_SIZE];
    circle a;
    fgets(shape, SHAPE_NAME_SIZE, file);
    bool = syntax_check(shape);

    if (bool == 1) {
        get_shape_info(shape, info);
        sscanf(info, "%f%f%f", &a.center_x, &a.center_y, &a.radius);
    } else {
        printf("Please correct your file and try again:3");
        return 0;
    }

    printf("circle(%f %f, %f)", a.center_x, a.center_y, a.radius);
}
