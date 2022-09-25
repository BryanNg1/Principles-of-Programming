#include <stdio.h>
#include <math.h>
#define N 3 //this code makes all N equal to 3

//the prototype

void print_sqmatrix(int mat[N][N]);


//test code to test the function


int main(){

//test 3 by 3 matrix

int mat[N][N]={1,2,3,1,3,2,4,2,1};

print_sqmatrix(mat);

return 0;
}

//function definition return nothing (printing function)

void print_sqmatrix(int mat[N][N]){

    //define counter variable

    int count;

    //first run, 0,0 prints then breaks while loop as r becomes -1 and is reset to 1,0, then first index subtract 1 and second add 1 which leaves 0,1...


    for( count=0;count<N;count++){

        int r= count, c = 0;

        while(r>=0&&c<N){

        printf("%d ",mat[r][c]);

        r=r-1;
        c=c+1;


    //it will overun and read index out of bound however c does not stop at this
    //eventually the loops will be broken out of and the next set runs in a similar fashion


        }

    }

    for(count=1;count<N;count++){

        int r = N-1, c= count;
        while(r>=0&&c<N){


        printf("%d ",mat[r][c]);

        r=r-1;

        c=c+1;

        }

    }

}
