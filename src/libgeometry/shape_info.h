#pragma once
#include "geometry.h"
#include <stddef.h>
#include <math.h>

#define SHAPE_INFO_SIZE 20

void get_shape_info(char*, size_t, char*); // string with shape, string`s length and string for info
float get_perimeter(circle*);
float get_area(circle*);