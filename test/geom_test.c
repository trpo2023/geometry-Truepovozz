#include <math.h>
#include <stdio.h>
#include <thirdparty/ctest.h>

#include <src/libgeometry/geometry.h>
#include <src/libgeometry/shape_info.h>
#include <src/libgeometry/syntax.h>

CTEST(syntax, syntax_chek)
{
    char* str1 = "circle(4 2, 234)";
    char* str2 = "circle(4 3, 345)";
    char* str3 = "circle(7 7, 456)";
    char* str4 = "circle(5 8, 776)";
    char* str5 = "circle(1 1, 2)";

    size_t size1 = 16;
    size_t size2 = 14;

    int result1 = syntax_check(str1, size1);
    int result2 = syntax_check(str2, size1);
    int result3 = syntax_check(str3, size1);
    int result4 = syntax_check(str4, size1);
    int result5 = syntax_check(str5, size2);

    int expected = 1;

    ASSERT_EQUAL(expected, result1);
    ASSERT_EQUAL(expected, result2);
    ASSERT_EQUAL(expected, result3);
    ASSERT_EQUAL(expected, result4);
    ASSERT_EQUAL(expected, result5);
}

// CTEST(shape_info, petimetr)
// {
//     circle c1;
//     c1.center_x = 1.0;
//     c1.center_y = 1.0;
//     c1.radius = 2.0;

//     circle c2;
//     c2.center_x = 1.0;
//     c2.center_y = 7.0;
//     c2.radius = 3.0;

//     circle c3;
//     c3.center_x = 5.0;
//     c3.center_y = 3.0;
//     c3.radius = 16.0;

//     circle c4;
//     c4.center_x = 8.0;
//     c4.center_y = 2.0;
//     c4.radius = 4.0;

//     circle c5;
//     c5.center_x = 6.0;
//     c5.center_y = 15.0;
//     c5.radius = 9.0;

//     circle* pc1 = &c1;
//     circle* pc2 = &c2;
//     circle* pc3 = &c3;
//     circle* pc4 = &c4;
//     circle* pc5 = &c5;

//     double result1 = 2 * M_PI * pc1->radius;
//     double result2 = 2 * M_PI * pc2->radius;
//     double result3 = 2 * M_PI * pc3->radius;
//     double result4 = 2 * M_PI * pc4->radius;
//     double result5 = 2 * M_PI * pc5->radius;

//     ASSERT_DBL_NEAR(result1, get_perimeter(pc1));
//     ASSERT_DBL_NEAR(result2, get_perimeter(pc2));
//     ASSERT_DBL_NEAR(result3, get_perimeter(pc3));
//     ASSERT_DBL_NEAR(result4, get_perimeter(pc4));
//     ASSERT_DBL_NEAR(result5, get_perimeter(pc5));
// }

// CTEST(shape_info, area)
// {
//     circle c1;
//     c1.center_x = 1.0;
//     c1.center_y = 1.0;
//     c1.radius = 2.0;

//     circle c2;
//     c2.center_x = 1.0;
//     c2.center_y = 7.0;
//     c2.radius = 3.0;

//     circle c3;
//     c3.center_x = 5.0;
//     c3.center_y = 3.0;
//     c3.radius = 16.0;

//     circle c4;
//     c4.center_x = 8.0;
//     c4.center_y = 2.0;
//     c4.radius = 4.0;

//     circle c5;
//     c5.center_x = 6.0;
//     c5.center_y = 15.0;
//     c5.radius = 9.0;

//     circle* pc1 = &c1;
//     circle* pc2 = &c2;
//     circle* pc3 = &c3;
//     circle* pc4 = &c4;
//     circle* pc5 = &c5;

//     double result1 = (pc1->radius * pc1->radius) * M_PI;
//     double result2 = (pc2->radius * pc2->radius) * M_PI;
//     double result3 = (pc3->radius * pc3->radius) * M_PI;
//     double result4 = (pc4->radius * pc4->radius) * M_PI;
//     double result5 = (pc5->radius * pc5->radius) * M_PI;

//     ASSERT_DBL_NEAR(result1, get_area(pc1));
//     ASSERT_DBL_NEAR(result2, get_area(pc2));
//     ASSERT_DBL_NEAR(result3, get_area(pc3));
//     ASSERT_DBL_NEAR(result4, get_area(pc4));
//     ASSERT_DBL_NEAR(result5, get_area(pc5));
// }