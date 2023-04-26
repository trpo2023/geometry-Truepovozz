#include <math.h>

#include <src/libgeometry/shape_info.h>

double get_perimeter(circle* shape)
{
    return 2 * M_PI * shape->radius;
}

double get_area(circle* shape)
{
    return (shape->radius * shape->radius) * M_PI;
}
