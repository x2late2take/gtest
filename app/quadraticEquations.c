#include <math.h>
#include <quadraticEquations.h>

Roots quadraticEquations(double a, double b, double c) {
    Roots roots;
    double discriminant = b * b - 4 * a * c;

    roots.discriminant = discriminant;

    if (discriminant > 0) {
        roots.root1 = (-b + sqrt(discriminant)) / (2 * a);
        roots.root2 = (-b - sqrt(discriminant)) / (2 * a);
        roots.numRoots = 2;
    } else if (discriminant == 0) {
        roots.root1 = roots.root2 = -b / (2 * a);
        roots.numRoots = 1;
    } else {
        roots.numRoots = 0;
    }

    return roots;
}