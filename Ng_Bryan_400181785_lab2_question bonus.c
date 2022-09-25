#include <stdio.h>
#include <math.h>

//function definition for addEff

void addEff( int val1[], int val2[], int val3[],int pos1[], int pos2[],int pos3[], int k1, int k2);

void main(){

int len = 10;
int val1[4] = {-1, 25, 3, 4};
int pos1[4] = {2, 4, 6, 8};
int k1 = 4;

int val2[6] = {5, 4, 10, 12, 35, 6};
int pos2[6] = {0, 1, 2, 4, 6, 10};
int k2 = 6;

int val3[len];
int pos3[len];

int val[7]; //number of spaces that have values
int pos[7];
int count;

printf("Sparse Vector 1: \n");
printf("Val 1:");

//for loop prints each element of the val1 array

for(count=0 ; count<4 ; count++)
{
    printf("%d ", val1[count]);
}

printf("\n");
printf("Pos 1:");

//for loop prints each index of the pos1 array

for(count=0 ; count<4 ; count++)
{
    printf("%d ", pos1[count]);
}

printf("\n");
printf("Sparse Vector 2: \n");
printf("Val 2:");

//for loop prints each element of the val2 array

for(count=0 ; count<6 ; count++)
{
    printf("%d ", val2[count]);
}

printf("\n");
printf("Pos 1:");

//for loop prints each index of the pos2 array

for(count=0 ; count<6 ; count++)
{
    printf("%d ", pos2[count]);
}
//testing the addEff function
//call function addEff to add to sparse arrays

addEff(val1, val2, val3, pos1, pos2, pos3, k1, k2);

printf("\n");
printf("Sparse Vector 3: \n");
printf("Val 3:");

//for loop prints each element of the val3 array

for(count=0 ; count<7 ; count++)
{
    printf("%d ", val3[count]);
}\

printf("\n");
printf("Pos 3:");

//for loop prints each index of the pos3 array

for(count=0 ; count<7 ; count++)
{
    printf("%d ", pos3[count]);
}
}

//function efficient


void addEff( int val1[], int val2[], int val3[],int pos1[], int pos2[],int pos3[], int k1, int k2)
{
//int k3 = 0;
int p1 = 0; // Pointer to val1
int p2 = 0; // Pointer to val2
int p3 = 0; // Pointer to val3
int sum = 0;

// val1, val2 and val3 are arrays that store the actual content of the original array without the zero elements
// pos1, pos2, pos3 are arrays that store the position of the non-zero elements of the sparse arrays above

while ((p1 < k1) && (p2 < k2)) // loop until reaching the end of either the first or the second sparse array
{
    // if the position of the element from the first array is smaller than the position of the element from the
    // second array, add element of the first array to the resulting array.
        if (pos1[p1] < pos2[p2])
        {
            val3[p3] = val1[p1];
            pos3[p3] = pos1[p1];
            p1++;                // advance to the next elemnet of the 1st array
            p3++;                // advance to the next element of the resulting array
 //           k3++;
        }
    // if the position of the element from the first array is greater than the position of the element from the
    // second array, add element of the second array to the resulting array.
        else if (pos1[p1] > pos2[p2])
        {
            val3[p3] = val2[p2];
            pos3[p3] = pos2[p2];
            p2++;                // advance to the next elemnet of the 2nd array
            p3++;                // advance to the next element of the resulting array
 //           k3++;
        }
    // if the position of the element from the first array is the same as the position of the element from the
    // second array, add the two elements.
        else if (pos1[p1] == pos2[p2])
        {
            sum = val1[p1] + val2[p2];
            // if the sum if not zero, add the sum and the corresponding position to the resulting array
            if (sum != 0)
            {
                val3[p3] = sum;
                pos3[p3] = pos1[p1];
                p3++;           // advance to the next element of the resulting array
 //               k3++;
            }
            p1++;               // advance to the next elemnet of the 1nd array
            p2++;               // advance to the next elemnet of the 2nd array
        }
}

// loop to add the remaining elements from the 1st array(if any) to the resulting array

while (p1 < k1)
{
        val3[p3] = val1[p1];
        pos3[p3] = pos1[p1];
        p1++;
        p3++;
//        k3++;
}

// loop to add the remaining elements from the 2nd array(if any) to the resulting array

while (p2 < k2)
{
        val3[p3] = val2[p2];
        pos3[p3] = pos2[p2];
        p2++;
        p3++;
//        k3++;
}

}


