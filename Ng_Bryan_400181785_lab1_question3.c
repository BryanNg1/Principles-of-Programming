#include <stdio.h>


int main()
{
    int num, x, n;

    //checks the condition of x


    while(x!=0){

     //user's input is asked for here

        printf("Enter a integer number: ");
        scanf("%d", &x);

    //if x is greater than 9999 but less than 100000 then it must be 5 digit (same with negatives)

        if((x > 9999 && x < 100000) || (x < -9999 && x > -100000)){
            printf("Your input is a 5 digit number: %d \n", x);
        }


    }
    printf("Thanks for using my software. Bye!");
    return 0;
}
