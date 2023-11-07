#include <iostream>
#include <cmath>
#include <limits>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Function to calculate the compression of the spring
double calculate_compression(double m, double d, double v, double theta, double k) {
    // Convert angle theta from degrees to radians
    double theta_radians = theta * M_PI / 180.0;

    // Coefficients for the quadratic equation ax^2 + bx + c = 0
    double a = 0.5 * k;
    double b = -m * 9.81 * sin(theta_radians);
    double c = -m * 9.81 * d * sin(theta_radians) - 0.5 * m * v * v;

    // Calculate the discriminant
    double discriminant = b * b - 4 * a * c;

    // Check if the discriminant is positive or zero, then calculate the roots
    if (discriminant >= 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        // Return the positive root since compression distance cannot be negative
        return (x1 > 0) ? x1 : x2;
    }
    else {
        // If the discriminant is negative, return -1 as the equation has no real solution
        return -1;
    }
}

int main() {
    double m, d, v, theta, k;
    char continueCalculation = 'y';

    while (continueCalculation == 'y' || continueCalculation == 'Y') {
        // Input from the user
        std::cout << "Enter the mass of the block (in kg): ";
        std::cin >> m;
        std::cout << "Enter the distance along the incline from the end of the spring (in m): ";
        std::cin >> d;
        std::cout << "Enter the initial speed of the block (in m/s): ";
        std::cin >> v;
        std::cout << "Enter the incline angle (in degrees): ";
        std::cin >> theta;
        std::cout << "Enter the spring constant (in N/m): ";
        std::cin >> k;

        // Calculate the compression of the spring
        double compression = calculate_compression(m, d, v, theta, k);

        if (compression != -1) {
            std::cout << "The spring is compressed by " << compression << " meters when the block comes to rest." << std::endl;
        }
        else {
            std::cout << "The block does not come to rest on the spring based on the given values." << std::endl;
        }

        // Ask the user if they want to continue
        std::cout << "Would you like to calculate another compression? (y/n): ";
        std::cin >> continueCalculation;

        // Clear the newline character from the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Exiting the program." << std::endl;

    return 0;
}
