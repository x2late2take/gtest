#ifndef TRIBONACCHI_H
#define TRIBONACCHI_H

typedef struct {
    double root1;
    double root2;
    double discriminant;
    int numRoots;
} Roots;

Roots tribonacchi(double a, double b, double c);

#endif // TRIBONACCHI_H
