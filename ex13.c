
#include <stdio.h>
#include <math.h>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/* Crie uma função em C que calcule a área (A) de um círculo.
A=π ×r */

double calculate_circle_area(double r)
{
    return M_PI * r * r;
}

int main()
{
    double radius;

    // Prompt user for input
    printf("Enter the radius of the circle: \n");
    scanf("%lf", &radius);

    // Validate user input
    if (radius <= 0)
    {
        fprintf(stderr, "Invalid input. Please enter a valid number.\n");
        return 1;
    }

    // Calculate and display the area
    double area = calculate_circle_area(radius);
    printf("The area of the circle is: %.2f\n", area);

    return 0;
}