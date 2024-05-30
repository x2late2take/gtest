#ifndef QUADRATICEQUATIONS_H
#define QUADRATICEQUATIONS_H

typedef struct {
    double root1;
    double root2;
    double discriminant;
    int numRoots;
} Roots;

Roots quadraticEquations(double a, double b, double c);

#endif // QUADRATICEQUATIONS_H