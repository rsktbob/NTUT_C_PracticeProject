#include <stdio.h>
#include <stdlib.h>
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

double circleperimeter(circle_t* circle) {
    return 2*3.14*circle->radius;
}

double circlearea(circle_t* circle) {
    return circle->radius*circle->radius*3.14;
}

double circlenew(circle_t* circle) {
    circle->perimeter=circleperimeter;
    circle->area=circlearea;
}

double rectangleperimeter(rectangle_t* rectangle) {
    return (rectangle->side1+rectangle->side2)*2;
}

double rectanglearea(rectangle_t* rectangle) {
    return rectangle->side1*rectangle->side2;
}

double rectanglenew(rectangle_t* rectangle) {
    rectangle->perimeter=rectangleperimeter;
    rectangle->area=rectanglearea;
}

double triangleperimeter(triangle_t* triangle) {
    return triangle->side1+triangle->side2+triangle->side3;
}

double trianglearea(triangle_t* triangle) {
    double s=(triangle->side1+triangle->side2+triangle->side3)/2;
    return sqrt(s*(s-triangle->side1)*(s-triangle->side2)*(s-triangle->side3));
}

double trianglenew(triangle_t* triangle) {
    triangle->perimeter=triangleperimeter;
    triangle->area=trianglearea;
}

double squareperimeter(square_t* square) {
    return square->side1*4;
}

double squarearea(square_t* square) {
    return square->side1*square->side1;
}

double squarenew(square_t* square) {
    square->perimeter=squareperimeter;
    square->area=squarearea;
}

int main() {
    int x1;
    char x2;
    double perimeter;
    double area;
    scanf("%d",&x1);
    shape_t *shape[x1];
    for(int i=0;i<x1;i++) {
        scanf(" %c",&x2);
        switch(x2) {
            case 'C':
                ;   
                circle_t *circle=(circle_t *)malloc(sizeof(circle_t));
                scanf("%lf",&(circle->radius));
                circlenew(circle);
                shape[i]=(shape_t *)circle;
                break;
            case 'S':
                ;
                square_t *square=(square_t *)malloc(sizeof(square_t));
                scanf("%lf",&(square->side1));
                squarenew(square);
                shape[i]=(shape_t *)square;
                break;
            case 'T':
                ;
                triangle_t *triangle=(triangle_t *)malloc(sizeof(triangle_t));
                scanf("%lf %lf %lf",&(triangle->side1),&(triangle->side2),&(triangle->side3));
                trianglenew(triangle);
                shape[i]=(shape_t *)triangle;
                break;
            case 'R':
                ;
                rectangle_t *rectangle=(rectangle_t *)malloc(sizeof(rectangle_t));
                scanf("%lf %lf",&(rectangle->side1),&(rectangle->side2));
                rectanglenew(rectangle);
                shape[i]=(shape_t *)rectangle;
        }
    }
    for(int i=0;i<x1;i++) {
        perimeter=shape[i]->perimeter(shape[i]);
        area=shape[i]->area(shape[i]);
        printf("%.2lf %.2lf\n",perimeter,area);
    }
}