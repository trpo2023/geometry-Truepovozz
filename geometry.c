#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define SHAPE_NAME_SIZE 50
#define SHAPE_INFO_SIZE 20

typedef struct {
    float center_x;
    float center_y;
    float radius;
} circle;

int syn_check(char*);
void get_shape_info(char*, char*);

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

int syntax_check(char* shape)
{
	int lean_of_circle = 6;
    char real_shape_name[lean_of_circle] = {'c', 'i', 'r', 'c', 'l', 'e'};
    char shape_name[SHAPE_NAME_SIZE];
    char misstake_pointer[SHAPE_NAME_SIZE];
    int counter = 0;
    for (int i = 0; i < SHAPE_NAME_SIZE; i++) {
        misstake_pointer[i] = ' ';
        misstake_pointer[i + 1] = '\0';
    }

    for (int i = 0; i < lean_of_circle; i++) {
        shape_name[i] = shape[i];
    }
    for (int i = 0; i < lean_of_circle; i++) {
        if (real_shape_name[i] != shape_name[i]) {
            printf("%s\n", shape);
            misstake_pointer[counter] = '^';
            printf("%s\n", misstake_pointer);
            printf("Wrong shape name!\n");
            return 0;
        }
        counter++;
    }

    if (shape[counter] != '(') {
        printf("%s\n", shape);
        misstake_pointer[counter] = '^';
        printf("%s\n", misstake_pointer);
        printf("Problem in firtst brecket!\n");
        return 0;
    }
    counter++;

    for (int i = counter; shape[i] != ' '; i++) {
        if ((shape[i] <= '0') && (shape[i] >= '9') && (shape[i] != '.')) {
            printf("%s\n", shape);
            misstake_pointer[counter] = '^';
            printf("%s\n", misstake_pointer);
            printf("In points we use float nums! Or you missed a space between "
                   "coortinates\n");
            return 0;
        }
        counter++;
    }

    counter++;

    for (int i = counter; shape[i] != ','; i++) {
        if ((shape[i] <= '1') && (shape[i] >= '9') && (shape[i] != '.')) {
            printf("%s\n", shape);
            misstake_pointer[counter] = '^';
            printf("%s\n", misstake_pointer);
            printf("In points we use float nums! Or you missed a comma between "
                   "point and radius\n");
            return 0;
        }
        counter++;
    }

    counter++;

    if (shape[counter] != ' ') {
        printf("%s\n", shape);
        misstake_pointer[counter] = '^';
        printf("%s\n", misstake_pointer);
        printf("Write space between comma and radius!\n");
        return 0;
    }

    counter++;

    for (int i = counter;
         ((shape[i] != '\0') && (shape[i] != '(') && (shape[i] != ')'));
         i++) {
        if ((shape[i] <= '1') && (shape[i] >= '9') && (shape[i] != '.')) {
            printf("%s\n", shape);
            misstake_pointer[counter] = '^';
            printf("%s\n", misstake_pointer);
            printf("In radius we use float nums! Or you missed the second "
                   "brecket\n");
            return 0;
        }
        counter++;
    }

    if (shape[counter] != ')') {
        printf("%s\n", shape);
        misstake_pointer[counter] = '^';
        printf("%s\n", misstake_pointer);
        printf("Problem in second brecket!\n");
        return 0;
    }
    if (shape[counter + 1] != '\0') {
        printf("%s\n", shape);
        misstake_pointer[counter + 1] = '^';
        printf("%s\n", misstake_pointer);
        printf("Delite unexpected extras!\n");
        return 0;
    }

    return 1;
}

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
