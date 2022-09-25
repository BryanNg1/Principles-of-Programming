#include <stdio.h>
#include <math.h>

//function definition for efficient

void efficient(const int source[], int val[], int pos[], int size);

//function definition for reconstruct

void reconstruct(int source[], int m, const int val[], const int pos[], int n);



void main(){
int source[10] = {0, 0, 23, 0, -7, 0, 0, 48, 0, 12};

int val[4]; //number of spaces that have values
int pos[4];
int count;

//efficient function testing

efficient(source, val, pos, 10);

printf("Sparse Vector: \n");

printf("Val:");

//for loop prints each index of the val array

for(count=0 ; count<4 ; count++){

printf("%d ", val[count]);
}

printf("\n");
printf("Pos:");

//for loop prints each index of the pos array

for(count=0 ; count<4 ; count++){

printf("%d ", pos[count]);
}


//testing the reconstruct function

printf("\n");

int new_source[10] = {};

reconstruct(new_source, 10, val, pos, 4);

printf("Reconstructed source:\n");

for(int count=0 ; count<10 ; count++) {
printf("%d ", new_source[count]);
}
}

//function efficient


void efficient(const int source[], int val[], int pos[], int size)
{
int input = 0;

// val is an array that stores the element of the original array (source) which do not contain zero
// pos is an array that stores the position number (where indexes are not equal to zero in the original source array)

for (int count=0 ; count<size ; count++) {

if (source[count] != 0) {

pos[input] = count;

val[input] = source[count];

input++;
}
}
}


//reconstruct function

void reconstruct(int source[], int m, const int val[], const int pos[], int n){

int counter;

//assigns the source array the values of array val and at the indexes of array pos

for(int count=0 ; count<n ; count++) {
source[pos[count]] = val[count];

}

//the loop runs for the length of the array
//since previously only some of the spaces of the array are filled by values of val array, this part checks the indices that have not been filled and fills them with 0

while(counter<m){

if(source[counter]>0 || source[counter]<0){

counter++;

}else{

source[counter] = 0;

counter++;

}

}
}
