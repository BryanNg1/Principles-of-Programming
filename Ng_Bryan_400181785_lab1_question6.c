#include <stdio.h>


int main(){

    int side1, side2, hypo, count=0, squareh, square1, square2;


    for(side1 = 1;side1<=400;side1++){ //first loop runs until the first side is more than 400


        for(side2=1;side2<=400;side2++){ //second loop runs until second side is more than 400


            for(hypo=1;hypo<=400;hypo++){ //third loop runs until hypotenuse is more than 400
                if(side1<=side2){ //checks that side1 less than or equal side 2
                        if((side1&&side2)<hypo){ //checks that sides are less than hypo
                            squareh = hypo*hypo; //calculating squares of each side
                            square1 = side1*side1;
                            square2 = side2*side2;

                            if(squareh == square1+square2){ //seeing if squares add up to hypotenuse square
                                printf("Side1: %d \n", side1); //prints the sides
                                printf("Side2: %d \n", side2);
                                printf("Hypotenuse %d \n", hypo);
                                count = count+1; //updates the count every time the conditions for pythagorean threes are met

                }
                }
                }
            }

        }
    }
    printf("Here is the count: %d", count); //final return of count
    return 0;
}
