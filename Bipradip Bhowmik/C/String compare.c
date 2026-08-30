#include<stdio.h>
#include<string.h>
int main(){
    char str1[100],str2[100];
    printf("Enter a first string");
    scanf("%s",str1);
    printf("Enter a second string");
    scanf("%s",str2);
    if( strcmp (str1,str2)== 0)
    printf("string are equal");
    else 
    printf("string are not equal");

    return 0;
}