#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include <src/libgeometry/geometry.h>
#include <src/libgeometry/shape_info.h>
#include <src/libgeometry/syntax.h>

#define QUANTITY_OF_SHAPES 5

int main(int argc, char* argv[])
{
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Didn`t open\n");
        return -1;
    }

    size_t size_of_shape_str = 0;
    char* shape_str = NULL;
    circle* shapes[QUANTITY_OF_SHAPES];
    for (int i = 0; i < QUANTITY_OF_SHAPES; i++) {
        shapes[i] = malloc(sizeof(circle));
        getline(&shape_str, &size_of_shape_str, file);

        if (syntax_check(shape_str, size_of_shape_str)) {
            sscanf(shape_str,
                   "circle(%lf %lf, %lf)",
                   &shapes[i]->center_x,
                   &shapes[i]->center_y,
                   &shapes[i]->radius);
        } else {
            printf("Please correct your file and try again:3\n");
            return 0;
        }
        free(shape_str);
    }

    for (int i = 0; i < QUANTITY_OF_SHAPES; i++) {
        printf("circle(%lf %lf, %lf)\n",
               shapes[i]->center_x,
               shapes[i]->center_y,
               shapes[i]->radius);
        printf("perimeter = %lf\n", get_perimeter(shapes[i]));
        printf("area = %lf\n", get_area(shapes[i]));
    }
}
