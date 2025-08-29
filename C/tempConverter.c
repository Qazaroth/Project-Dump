#include <stdio.h>

int main() {
    float celsius, kelvin, fahren;
    char choice;

    printf("Simple temperature converter\n");
    printf("Celsius <-> Kelvin\n");
    printf("Celsius <-> Fahrenheit\n");
    printf(" Kelvin <-> Fahrenheit\n");

    printf("C => Celsius\nK => Kelvin\nF => Fahrenheit\n");
    printf("What unit is the temperature using? (C|K|F) ");
    scanf("%c", &choice);

    switch (choice) {
        case 'c':
            printf("\nEnter temperature (Celsius): ");
            scanf("%f", &celsius);

            kelvin = celsius + 273.15;
            fahren = celsius * 1.8 + 32;

            break;
        case 'k':
            printf("\nEnter temperature (Kelvin): ");
            scanf("%f", &kelvin);

            celsius = kelvin - 273.15;
            fahren = kelvin * 1.8 - 459.67;

            break;
        case 'f':
            printf("\nEnter temperature (Fahrenheit): ");
            scanf("%f", &fahren);

            celsius = (fahren - 32) * 5 / 9;
            kelvin  = (fahren + 459.67) * 5 / 9;

            break;
        default:
            printf("\nInvalid temperature unit.\n");
            return 1;
    }
    
    printf("\nTemperature in Celsius: %.2f\n", celsius);
    printf("Temperature in Fahrenheit: %.2f\n", fahren);
    printf("Temperature in Kelvin: %.2f\n", kelvin);
}
