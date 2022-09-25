#include <stdio.h>
#include <math.h>


void letter_freq(const char word[], int freq[]);

int main(){

    int count;

    //freq[26] is the array that stores the number of characters (26 letters of alphabet) so a space for each

    int freq[26] = {};

    //put the size of the "string" to be 99 char

    char word[99] = "McMaster";

    letter_freq(word, freq);

    for(count=0; count<26; count++){

    //returns 2 characters ie. when 'A' plus 1, it takes ascii value and adds one and the %c will print corresponding character

    //freq count in this prints a certain index of the freq array (stores the number of characters)


        printf("'%c' and '%c': %d\n", ('A'+count), ('a'+count), freq[count]);

    }

    return 0;

}

//function definition takes in a word "string" and needs an empty array that has 26 spots to store frequency of letters in alphabet

void letter_freq(const char word[], int freq[]){

    int count=0;


    //the \0 denotes the end of "string"

    while(word[count]!='\0'){

    //ascii value of a is 97 and z is 122 so if index of word (ascii value) based on count is between this, the freq array is added 1 corresponding to the letter's place


        if(word[count]>='a' && word[count]<='z')

            //word index at count (takes ascii value) and subtracts 97 to get freq index

            freq[word[count]-'a']++;

            //same idea but for capital (A = 65) so M for McMaster will not register for first loop and will be subtracted 65 from, 77-65 = 12 (m is 12th letter in alphabet starting from0)

        else if(word[count]>='A' && word[count]<='Z')

            freq[word[count]-'A']++;

        count=count+1;

    }

}
