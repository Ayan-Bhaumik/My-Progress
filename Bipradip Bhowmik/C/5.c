#include<stdio.h>
int main(){
    char a;
    printf("Enter the character");
    scanf("%c",&a);
   if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u') {
        printf("The character is a vowel.");
    } else {
        printf("The character is not a vowel.");
    }
    return 0;
}