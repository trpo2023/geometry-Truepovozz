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

int intersection(circle* a, circle* b)
{
    double distance;

    distance = sqrt((pow((a->center_x - b->center_x), 2)) + (pow((a->center_y - b->center_y), 2)));

    if(distance > a->radius && distance > b->radius)
        return 0;
    
    return 1;
}