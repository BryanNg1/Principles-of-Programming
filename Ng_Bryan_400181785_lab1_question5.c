#include <stdio.h>


int main(){

    float sum=0, num;
    int count, n;

    printf("Enter a number: ");
    scanf("%d", &n); //asking user for input

    for(count=1;count<=n;count++){ //for loop counting up by one until the counter meets the user's inputted number
        num = (1.0/((2.0*count)-1.0))*4.0;

        if(count%2==0){ //if the term is even, it is a subtraction operation
            sum=sum-num;
        }
        else if(count%2!=0){//if the term is odd, it is an addition operation
            sum=sum+num;
        }

    }
    printf("Here is Pi: %f \n", sum); //returning the float sum (final value of the operation)

    return 0;
}
