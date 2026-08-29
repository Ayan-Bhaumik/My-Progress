//New Prgm
#include <stdio.h>

int main() {

    int n;

    printf("Enter the respective year: ");
    scanf("%d", &n);

    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        printf("The respective year is a leap year");
    }
    else {
        printf("The respective year is not a leap year");
    }

    return 0;
}