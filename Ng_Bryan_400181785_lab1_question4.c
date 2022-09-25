#include <stdio.h>


int main(){
    float n, x;
    printf("Enter your average: ");
    scanf("%f",&n); //asks for the user's input

    if(n>=90 && n<=100){ // each if statement presents a condition (one for every average range)
        printf("You have a 4");

    }

    else if(n>=80 && n<=89){
    printf("You have a 3");


    }

    else if(n>=70 && n<=79){
    printf("You have a 2");

    }
    else if(n>=60 && n<=69){
    printf("You have a 1");


    }

    else if(n>=0 && n<=59){
    printf("You have a 0");

    }

    else{
    printf("invalid entry"); //invalid input if user inputs anything not within the range of 0-100
    }

    return 0;

}
