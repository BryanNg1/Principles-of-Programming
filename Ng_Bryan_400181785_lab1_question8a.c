#include <stdio.h>

int main(){

    int remainder, num, decider=0, divisor, tens=10, counter=1;

    //gets the input from user


    printf("Enter a number: ");
    scanf("%d", &num);

    //counter variable set to 7 as the code is only required to run for 7 digits

    while(counter<=7){

        //remainder calculator by modulo function (tens part is self made power function)

        remainder = (num%tens)/(tens/10);

        //flag to check zeros so if remainder is not zero, the digit is printed

        if(remainder!=0){
            decider = 0;
        }

        //flag to check zeros so if remainder is zero, it checks to see if the zeros are at the end (if they are they are not printed, but are printed if they are in the middle)

        if(remainder==0 && counter==1){
            decider = 1;
        }
        if(decider==0){
        printf("%d", remainder);

        }

        // oounter variable
        counter=counter+1;

        //the power function (multiplies by 10 per loop)

        tens=tens*10;


    }

    return 0;

}
