#include <stdio.h>

int main()
{
    int n, x, min, a, count;

    //asks for the user's input

    printf("Enter the number of digits you want find the smallest of: ");
    scanf("%d",&n);

    //the loop runs for the amount of times the user's input is

    for(count=0;count<n;count++){
        printf("enter number: ");
        scanf("%d", &x);

        //checks next inputted number to see if it is larger or smaller than previous inputted

        if(min>x){

             min = x;
        }



    }

    //prints final statement (lowest number)

    printf("this is the lowest number: %d", min);
    return 0;



}
