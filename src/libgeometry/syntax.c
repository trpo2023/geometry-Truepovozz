#include <stdio.h>

#include <src/libgeometry/syntax.h>

int syntax_check(char* shape, const size_t size_of_str)
{
    char real_shape_name[LEN_OF_CIRCLE] = {'c', 'i', 'r', 'c', 'l', 'e'};
    char shape_name[size_of_str];
    char misstake_pointer[size_of_str];
    int counter = 0;
    for (int i = 0; i < size_of_str; i++) {
        misstake_pointer[i] = ' ';
        misstake_pointer[i + 1] = '\0';
    }

    for (int i = 0; i < LEN_OF_CIRCLE; i++) {
        shape_name[i] = shape[i];
    }
    for (int i = 0; i < LEN_OF_CIRCLE; i++) {
        if (real_shape_name[i] != shape_name[i]) {
            misstake_pointer[counter] = '^';
            error_output(shape, misstake_pointer, 0);
            return 0;
        }
        counter++;
    }

    if (shape[counter] != '(') {
        misstake_pointer[counter] = '^';
        error_output(shape, misstake_pointer, 1);
        return 0;
    }
    counter++;

    for (int i = counter; shape[i] != ' '; i++) {
        if ((shape[i] <= '0') && (shape[i] >= '9') && (shape[i] != '.')) {
            misstake_pointer[counter] = '^';
            error_output(shape, misstake_pointer, 2);
            return 0;
        }
        counter++;
    }

    counter++;

    for (int i = counter; ((shape[i] >= '1') && (shape[i] <= '9')) || (shape[i] == '.'); i++) {
        if ((shape[i] <= '1') && (shape[i] >= '9') && (shape[i] != '.')) {
            misstake_pointer[counter] = '^';
            error_output(shape, misstake_pointer, 2);
            return 0;
        }
        counter++;
    }

    if (shape[counter] != ',') {
        misstake_pointer[counter] = '^';
        error_output(shape, misstake_pointer, 3);
        return 0;
    }

    counter++;

    if (shape[counter] != ' ') {
        misstake_pointer[counter] = '^';
        error_output(shape, misstake_pointer, 4);
        return 0;
    }

    counter++;

    for (int i = counter;
         ((shape[i] != '\0') && (shape[i] != '(') && (shape[i] != ')'));
         i++) {
        if ((shape[i] <= '1') && (shape[i] >= '9') && (shape[i] != '.')) {
            misstake_pointer[counter] = '^';
            error_output(shape, misstake_pointer, 5);
            return 0;
        }
        counter++;
    }

    if (shape[counter] != ')') {
        misstake_pointer[counter] = '^';
        error_output(shape, misstake_pointer, 6);
        return 0;
    }
    if ((shape[counter + 1] != '\0') && (shape[counter + 1] != '\n')) {
        misstake_pointer[counter + 1] = '^';
        error_output(shape, misstake_pointer, 7);
        return 0;
    }

    return 1;
}

void error_output(char* shape, char* place_of_misstake, int error)
{
    printf("%s\n", shape);
    switch (error) {
    case (0):
        printf("%s\n", place_of_misstake);
        printf("Wrong shape name!\n");
        break;
    case (1):
        printf("%s\n", place_of_misstake);
        printf("Problem in firtst brecket!\n");
        break;
    case (2):
        printf("%s\n", place_of_misstake);
        printf("In points we use float nums! Or you missed a space between "
               "coortinates\n");
        break;
    case (3):
        printf("%s\n", place_of_misstake);
        printf("In points we use float nums! Or you missed a comma between "
               "point and radius\n");
        break;
    case (4):
        printf("%s\n", place_of_misstake);
        printf("Write space between comma and radius!\n");
        break;
    case (5):
        printf("%s\n", place_of_misstake);
        printf("In radius we use float nums! Or you missed the second "
               "brecket\n");
        break;
    case (6):
        printf("%s\n", place_of_misstake);
        printf("Problem in second brecket!\n");
        break;
    case (7):
        printf("%s\n", place_of_misstake);
        printf("Delite unexpected extras!\n");
        break;
    }
}