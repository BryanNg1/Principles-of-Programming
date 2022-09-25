#include <stdio.h>
#include <math.h>

double fabs(double x); //for the absolute value of numbers

int is_diag_dom( double mat[3][3]); //matrix prototype

int main(){

    //test code for the matrix (3 by 3 matrix created

    double mat[3][3]={-3,2,-1,1,-3,2,1,-2,3};

    //prints the return from the function

    printf("return %d\n", is_diag_dom(mat));

    return 0;
}

//the function definition (paramter matrix of n by n)

int is_diag_dom(double mat[3][3]){

    //variable definition

    int maxnum, sum, maxsum, i, j;
    maxnum=0;
    sum=0;
    maxsum = 0;

    //combination of for loops check each row and shift down until the end of matrix


    for(i=0;i<3;i++){

        for(j=0;j<3;j++){

        //stores the diagonal values of the matrix


            if(i==j){
                maxnum = fabs(mat[i][j]);


        //finds the sum of the other values of the matrix

            }else{

                sum = sum + fabs(mat[i][j]);


        //every time the diagonal number is greater than or equal to sum of the other digits in the row, a the counter maxsum goes up by one

            }
        if(maxnum>=sum){
            maxsum = maxsum + 1;

        }

        }

        //if the maxsum is equal to the dimension of the matrix, the matrix is diagonal and 1 is returned

    }
    if(maxsum == 3){
        return 1;
    }else{
        return 0;

    }

}
