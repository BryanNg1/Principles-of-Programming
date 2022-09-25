#include <stdio.h>
#include <math.h>

void print_vector(double array[], int size);
void add_vectors( double vector1[],double vector2[],double vector3[], int n);
double scalar_prod( double vec1[], double vec2[], int len);
double norm2(double v[], int length);


int main(){


// test part1
    double arr[3] = {9.0,123.0,4.0};
    print_vector(arr, 3);

    printf("\n");



//test part2
    double vector1[4] = {1.2,2.3,1322.1,65.1};
    double vector2[4] = {1.0,23.8,123.6,23.6};
    double vector3[4] = {};

    add_vectors(vector1, vector2, vector3, 4);

    printf("\n");

//part 3 test
    double vec1[3] = {1.2,3.4,3.4};
    double vec2[3] = {3.1,4.4,3.1};

    scalar_prod(vec1, vec2, 3);

    printf("\n");

//test part 4

    double v[4] = {1.2,2.3,3.1,2.1};

    norm2(v, 4);


}

//part1

void print_vector(double arr[], int size){

    int num;

    for(num=0;num<size;num++){

        printf("vector: %f    ", arr[num]);

    }

}


//part2


void add_vectors( double vector1[],double vector2[],double vector3[], int n){

    int num1;

    for(num1=0;num1<n;num1++){

        vector3[num1] = vector1[num1] + vector2[num1];

        printf("%f    ", vector3[num1]);

    }

}

//part3

double scalar_prod( double vec1[], double vec2[], int len){

    double sum;
    double mult;
    int count;

    sum = 0;

    for (count=0;count<len;count++){

        mult = vec1[count]*vec2[count];

        sum = mult+sum;

    }

    printf("%f    ", sum);
    return sum;
}

//part4

double norm2(double v[], int length){

    int counter;
    double add;
    double multiply;
    double sqr;

    add = 0;

    for(counter=0;counter<length;counter++){

        multiply = v[counter]*v[counter];

        add = multiply+add;
    }

    sqr=sqrt(add);

    printf("%f    ", sqr);
    return sqr;



}





