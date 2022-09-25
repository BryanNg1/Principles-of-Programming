#include <stdio.h>

int main()
{
    //initialize count to 30 and counts until 1000

    int count, sum=0;
    for (count=30;count<1000;count++){

    //if statement checks to see if each number is divisible by 4
        if(count%4==0){
        sum=count+sum;
        }
    }

    printf("The sum is %d \n", sum);

    //same idea but using the while loop (so while the number is less than 1000)

    //reinitialize the variables sum and count

    sum = 0;
    count=30;

    while(count<1000){
        if(count%4==0){
            sum=count+sum;
        }
        count=count+1;
    }
    printf("The sum is %d \n", sum);

    //same thing but with do and while statements (do this while this)


    sum=0;
    count=30;

    do{
        if(count%4==0){
            sum=count+sum;
        }
        count=count+1;
    }
    while(count<1000);

    printf("The sum is %d", sum);

    return 0;

}


