#include <stdio.h>
#include <math.h>
#define ShapeText(TYPE) double (*perimeter)(struct TYPE*);\
double (*area)(struct TYPE*)

typedef struct shape_s 
{
    ShapeText(shape_s);
} shape_t;

typedef struct circle_s 
{
    ShapeText(circle_s);
    double radius;
} circle_t;

typedef struct rectangle_s 
{
    ShapeText(rectangle_s);
    double side1;
    double side2;
} rectangle_t;

typedef struct triangle_s
{
    ShapeText(triangle_s);
    double side1;
    double side2;
    double side3;
} triangle_t;

typedef struct square_s
{
    ShapeText(square_s);
    double side1;
} square_t;

double cicleperimeter(circle_t *circle)
{
    return 2*3.14 * circle->radius;
}

double circlearea(circle_t *circle)
{
    return 3.14*circle->radius*circle->radius;
}

double circlenew(circle_t *circle)
{
    circle->perimeter=cicleperimeter;
    circle->area=circlearea;
}

double rectangleperimeter(rectangle_t *rectangle)
{
    return 2*(rectangle->side1+rectangle->side2);
}

double rectanglearea(rectangle_t *rectangle)
{
    return rectangle->side1*rectangle->side2;
}

double rectanglenew(rectangle_t *rectangle)
{
    rectangle->perimeter=rectangleperimeter;
    rectangle->area=rectanglearea;
}

double triangleperimeter(triangle_t *triangle)
{
    return triangle->side1+triangle->side2+triangle->side3;
}

double trianglearea(triangle_t *triangle)
{
    double s=(triangle->side1+triangle->side2+triangle->side3)/2;
    return sqrt(s*(s-triangle->side1)*(s-triangle->side2)*(s-triangle->side3));
}

double trianglenew(triangle_t *triangle)
{
    triangle->perimeter=triangleperimeter;
    triangle->area=trianglearea;
}

double squareperimeter(square_t *square)
{
    return square->side1*4;
}

double squarearea(square_t *square)
{
    return square->side1*square->side1;
}

double squarenew(square_t *square)
{
    square->perimeter=squareperimeter;
    square->area=squarearea;
}

int main()
{
    int num1;
    int x1=0;
    int x2=0;
    int k1=0;
    int k2=0;
    double perimeter;
    double area;
    double perimeter_sum=0;
    double area_sum=0;
    char t1;
    scanf("%d", &num1);
    shape_t *shape[num1];
    circle_t circle[num1];
    rectangle_t rectangle[num1];
    triangle_t triangle[num1];
    square_t square[num1];
    for(int i=0; i<num1; i++)
    {
        circle[i].perimeter=cicleperimeter;
        circle[i].area=circlearea;
        rectangle[i].perimeter=rectangleperimeter;
        rectangle[i].area=rectanglearea;
        triangle[i].perimeter=triangleperimeter;
        triangle[i].area=trianglearea;
        square[i].perimeter=squareperimeter;
        square[i].area=squarearea;
    }
    for(int i = 0; i < num1; i++)
    {
        scanf(" %c",&t1);
        switch (t1)
        {
            case 'C':
                scanf("%lf",&circle[x1].radius);
                shape[i]=(shape_t *) &circle[x1];
                x1++;
                break;
            case 'R':
                scanf("%lf",&rectangle[x2].side1);
                scanf("%lf",&rectangle[x2].side2);
                shape[i]=(shape_t *) &rectangle[x2];
                x2++;
                break;
            case 'T':
                scanf("%lf",&triangle[k1].side1);
                scanf("%lf",&triangle[k1].side2);
                scanf("%lf",&triangle[k1].side3);
                shape[i]=(shape_t *) &triangle[k1];
                k1++;
                break;
            case 'S':
                scanf("%lf",&square[k2].side1);
                shape[i]=(shape_t *) &square[k2];
                k2++;
                break;
        }
    }
    for(int i = 0; i < num1; i++)
    {
        perimeter=shape[i]->perimeter(shape[i]);
        area=shape[i]->area(shape[i]);
        perimeter_sum=perimeter_sum+perimeter;
        area_sum=area_sum+area;
        printf("%.2lf %.2lf\n",perimeter,area);
    }
    printf("%.2lf %.2lf\n",perimeter_sum,area_sum);
}
