#include <stdio.h>


int main(){
    int counter, counter2, sum=0, num, remainder;

    //allows user to input an integer

    printf("Enter a number: ");
    scanf("%d", &num);

    //loop through all integers within the range of the user's inputted integer (in descending order)

    for(counter=num;counter>=1;counter--){


    // find the sum of all factors

        for(counter2=1;counter2<counter;counter2++){

            remainder = counter%counter2;

            if(remainder==0){

                sum=sum+counter2;

            }
        }

        // if the sum of factors equals the number entered, it is deemed a perfect number

        if(sum==counter){
        printf("Perfect number: %d \n", sum);
        }
        sum=0;

    }
    return 0;
}
