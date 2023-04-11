#include "shape_info.h"

float get_perimeter(circle* shape)
{
    return 2 * M_PI * shape->radius;
}

float get_area(circle* shape)
{
    return (shape->radius * shape->radius) * M_PI;
}
