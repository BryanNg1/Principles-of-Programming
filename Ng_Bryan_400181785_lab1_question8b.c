#include <stdio.h>

int main(){

    int remainder, num, newnum, counter2=0, decider=0, divisor, tens=10, counter=1;

    //gets the input from user


    printf("Enter a number: ");
    scanf("%d", &num);

    //newnum is used to find the number of digits

    newnum = num;

    //the loop will divide number by 10 until it cannot be divided and the number of times is counted and tallied up

    while(newnum>0){

        newnum= newnum/10;

        counter2++;
    }

    //same as part a but the counter is set to the number of digits (counter2)

    while(counter<=counter2){

        remainder = (num%tens)/(tens/10);

        if(remainder!=0){
            decider = 0;
        }

        if(remainder==0 && counter==1){
            decider = 1;
        }
        if(decider!=1){
        printf("%d", remainder);

        }
        counter=counter+1;

        tens=tens*10;


    }

    return 0;

}
