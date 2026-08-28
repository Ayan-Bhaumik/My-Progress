#include<stdio.h>
int main(){
    float english,physics,chemistry,maths,biology,total,percentage;
    printf("Enter marks of English:");
    scanf("%f",&english);
    printf("Enter marks of physics:");
    scanf("%f",&physics);
    printf("Enter marks of chemistry:");
    scanf("%f",&chemistry);
    printf("Enter marks of maths:");
    scanf("%f",&maths);
    printf("Enter marks of biology:");
    scanf("%f",&biology);
    total=english+physics+chemistry+maths+biology;
    percentage=total/5;
    printf("Total marks=%f\n",total);
    printf("Percentage=%f\n",percentage);

        if(percentage>=90){
            printf("Grade A");

        }
        else if(percentage>=80){
            printf("Grade B");
        }
        else if(percentage>=70){
            printf("Grade C");
        }
        else if(percentage>=60){
            printf("Grade D");
        }
        else if(percentage>=40){
            printf("Grade E");
        }
        else{
            printf("Grade Mubha rakho app fail ho gaye ho");

        }
        return 0;
    }

        

        


