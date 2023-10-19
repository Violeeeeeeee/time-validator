#include <stdio.h>
#include <math.h>

double sumDwochLiczb(double x, double y) {
    return x + y;
}

double m; //median from the vertex of an angle with sides a,b

double semiPerimeter(double a, double b, double c) { //semi perimeter of triangle
    return (a + b + c) / 2;
}

double pm(double a, double b, double m) { //solving semi perimeter with median
    return (a + b + 2 * m) / 2;
}

double r; //radius of the inscribed circle
double ra, rb, rc; //radii of excircles of a circle tangent to the sides a, b, c
double rr; //radius of the circumscribed circle 
double h; //height
double srectangle(double a, double b) { //area of rectangle
     return a * b; 
}                        

typedef struct {
    double a;       //sides of quadrilaterals
    double b;
} QuadrilateralSides;

typedef struct {
    double ha;      //heights of the sides triangle
    double hb;
    double hc;
} HeightsOToTheSides;

typedef struct {
    double a;       //sides of the triangle
    double b;
    double c;
} TriangleSides;

typedef struct {
    double x;   //point of coordinate graph
    double y;
} Point;

double areaTriangleForHeightsOfTheSides ( HeightsOToTheSides heights, TriangleSides sides) {
    double area = (heights.ha * sides.a) / 2.0; //we can use also hb-b, hc-c, but in main.c we will use variable heights and sides for scanf  
    return area;
}


double areaOrientedTriangle (Point A, Point B, Point C) {
    double area = 0.5 * fabs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)); //solving oriented triangle on coordinate graph
    return area;
}

double areaHeronsFormulaTriangle (TriangleSides sides) {
    double p = semiPerimeter(sides.a, sides.b, sides.c);
    double area = sqrt(p * (p - sides.a) * (p - sides.b) * (p - sides.c)); //Heron`s formula
    return area;
}

double volumePrism (QuadrilateralSides sides) {
    double s = srectangle(sides.a, sides.b);
    double volume = h * s; 
    return volume;
}

