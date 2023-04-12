#include <stdio.h>

#include <libgeometry/syntax.h>

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
    if ((shape[counter + 1] != '\0') && (shape[counter + 1] != '\n')) {
        printf("%s\n", shape);
        misstake_pointer[counter + 1] = '^';
        printf("%s\n", misstake_pointer);
        printf("Delite unexpected extras!\n");
        return 0;
    }

    return 1;
}
