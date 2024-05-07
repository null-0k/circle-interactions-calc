#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double r;
} Circle;

void findIntersection(Circle C1, Circle C2);

void findIntersection(Circle C1, Circle C2) {
    double dx = C2.x - C1.x; 
    double dy = C2.y - C1.y; 
    double dist = sqrt(dx * dx + dy * dy);

    double addR = C1.r + C2.r;
    double subR = fabs(C1.r - C2.r);

    if(dist > addR || dist < subR || dist == 0 && C1.r == C2.r){
        printf("\nSorry, no intersection found.");
        return;
    } 

    double a = (dist * dist + C1.r * C1.r - C2.r * C2.r) / (2 * dist); 
    double nx = dx / dist;
    double ny = dy / dist;
    double px0 = C1.x + a * nx;
    double py0 = C1.y + a * ny;

    if (dist == addR) {
        printf("The circles are externally tangent.");
        printf("P: x=\"%f\", y=\"%f\"\n", px0, py0);
        return;
    }

    if (dist == subR) {  
        printf("The circles are internally tangent.");
        printf("P: x=\"%f\", y=\"%f\"\n", px0, py0);
        return;
    }
    
    double h = sqrt(C2.r * C2.r - a * a);
    double px = px0 - h * ny;
    double py = py0 + h * nx;
    double qx = px0 + h * ny;
    double qy = py0 - h * nx;
        
    printf("Two intersections were found.\n");
    printf("P: x=\"%f\", y=\"%f\"\n", px, py);
    printf("Q: x=\"%f\", y=\"%f\"\n", qx, qy);
}

int main() {
    Circle C1, C2;

    printf("First Circle  (x, y, radius): ");
    scanf("%lf %lf %lf", &C1.x, &C1.y, &C1.r);

    printf("Second Circle (x, y, radius): ");
    scanf("%lf %lf %lf", &C2.x, &C2.y, &C2.r);

    if (C1.r <= 0 || C2.r <= 0) {
        printf("\n\033[30;41mError\033[0m Please enter a natural number for the radius.");
        return 1; // 
    }

    findIntersection(C1, C2);
    return 0; 
}
