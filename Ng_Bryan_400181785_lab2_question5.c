#include <stdio.h>
#include <math.h>

//prototype

void string_copy(const char source[],char destination[],int n);



 int main(){


    char source[100]="McMaster is the best school";

    int n = 40;

    char destination[n];

    string_copy(source,destination,n);

    return 0;
}

void string_copy(const char source[],char destination[],int n){

    int count=0;
    int lengthsource=0;

    //this code finds the length of the source string (adds one every time a char is read until \0 which denotes the end of a string)

    for(count=0;source[count]!='\0';count++){

        lengthsource++;

        }

    //n is the user input for size of destination array
    //if the size is equal to or greater than the source length, the destination indexes will be set equal to the source index values until n

    if(lengthsource<n || lengthsource==n){

        for(count=0;count<lengthsource;count++){

            destination[count]=source[count];

        }

    }


    //if the n is less than the length of the source array, the same applies however the loop stops when count is equal to n
    //ie. length of McMaster is 8 and if n = 5, only McMas will be stored in the destination array


    else if(lengthsource>n){

        for(count=0;count<n;count++){

            destination[count]=source[count];

        }

    }

    //these statements print the string in the destination array

    printf("\nString in destination:");

    //loop goes through each index of the destination index and prints them


    for(count=0;count<n;count++){


        printf("%c",destination[count]);


        }
}
