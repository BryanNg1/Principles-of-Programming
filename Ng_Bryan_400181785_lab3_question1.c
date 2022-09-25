#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//function prototype

char *my_strcat(const char * const str1, const char * const str2);

//main function to test

int main(){

    char *str1, *str2;
    str1 = "mynameisjoe";
    str2 = "yoyoyo";


//prints the returned string from the function

    printf("%s", my_strcat(str1, str2));
}


//function definition

char *my_strcat(const char * const str1, const char * const str2){

//variables defined for the length of strings and for the counters used in for loops


    int len1, len2, len3, i, j;

//define third string (combination of str1 and str2)

    char *str3;

    len1 = strlen(str1);
    len2 = strlen(str2);

    len3 = len1+len2; //total length of the combined strings

//malloc used to allocate memory for str3

    str3 = malloc(len3 * sizeof(char));

//str1 elements moved into str3


    for(i=0;str1[i]!='\0';i++){

        str3[i] = str1[i];

    }

//str2 elements moved into str3 (notice the i value is not reset from first loop so str2 elements are added onto where str1 values left off)


    for(j=0;str2[j]!='\0';j++,i++){

        str3[i] = str2[j];

    }

//added a null character to indicate end of string

    str3[i] = '\0';

//str3 returned

    return str3;



}
