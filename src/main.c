#include <ctype.h>
#include <libgeometry/geometry.h>
#include <libgeometry/shape_info.h>
#include <libgeometry/syntax.h>
#include <stdio.h>
#include <stdlib.h>

#define SHAPE_INFO_SIZE 20
#define QUONTITY_OF_SHAPES 2

int main(int argc, char* argv[])
{
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Didn`t open\n");
        return -1;
    }

    char* shape_str = NULL;
    size_t size_of_shape_str = 0;
    circle* shapes[QUONTITY_OF_SHAPES];
    for (int i = 0; i < QUONTITY_OF_SHAPES; i++) {
        shapes[i] = malloc(sizeof(circle));
        getline(&shape_str, &size_of_shape_str, file);

        if (syntax_check(shape_str, size_of_shape_str)) {
            sscanf(shape_str,
                   "circle(%f %f, %f)",
                   &shapes[i]->center_x,
                   &shapes[i]->center_y,
                   &shapes[i]->radius);
        } else {
            printf("Please correct your file and try again:3\n");
            return 0;
        }
        free(shape_str);
    }

    for (int i = 0; i < QUONTITY_OF_SHAPES; i++) {
        printf("circle(%f %f, %f)\n",
               shapes[i]->center_x,
               shapes[i]->center_y,
               shapes[i]->radius);
        printf("perimeter = %f\n", get_perimeter(shapes[i]));
        printf("area = %f\n", get_area(shapes[i]));
    }
}