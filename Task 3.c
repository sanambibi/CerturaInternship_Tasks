#include <stdio.h>
#include <math.h>

void solveEquation(float coeffA, float coeffB, float coeffC) {
    float discValue = coeffB * coeffB - 4 * coeffA * coeffC;

    printf("\n============================================\n");
    printf("   Solving Quadratic Equation   \n");
    printf("===============================================\n");

    printf("Discriminant = %.2f\n", discValue);

    if (discValue > 0) {
        float firstRoot = (-coeffB + sqrt(discValue)) / (2 * coeffA);
        float secondRoot = (-coeffB - sqrt(discValue)) / (2 * coeffA);
        printf("Roots are Real and Different.\n");
        printf("First Root: %.2f\n", firstRoot);
        printf("Second Root: %.2f\n", secondRoot);
    } 
    else if (discValue == 0) {
        float onlyRoot = -coeffB / (2 * coeffA);
        printf("Roots are Real and Equal.\n");
        printf("Repeated Root: %.2f\n", onlyRoot);
    } 
    else {
        float realPart = -coeffB / (2 * coeffA);
        float imagPart = sqrt(-discValue) / (2 * coeffA);
        printf("Roots are Complex.\n");
        printf("First Root: %.2f + %.2fi\n", realPart, imagPart);
        printf("Second Root: %.2f - %.2fi\n", realPart, imagPart);
    }
}

int main() {
    float coeffA, coeffB, coeffC;

    printf("Enter the coefficients for ax^2 + bx + c = 0\n");
    printf("Coefficient a: ");
    scanf("%f", &coeffA);
    printf("Coefficient b: ");
    scanf("%f", &coeffB);
    printf("Coefficient c: ");
    scanf("%f", &coeffC);

    if (coeffA == 0) {
        printf("This is not a quadratic equation, as 'a' cannot be zero.\n");
    } else {
        solveEquation(coeffA, coeffB, coeffC);
    }

    return 0;
}

