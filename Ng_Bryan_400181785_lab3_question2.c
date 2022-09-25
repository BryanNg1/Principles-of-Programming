#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//define student (structure of multiple types)

typedef struct{

    int ID;
    char firstname[15];
    char lastname[15];
    int proj1;
    int proj2;
    float finalgrade;

    } student;


//function prototype

student **create_class_list( char *filename, int *sizePtr );
int find(int idNo, student **list, int size);
void input_grades(char *filename, student **list, int size);
void print_list( student **list, int size);
void compute_final_course_grades(student **list, int size);
void output_final_course_grades(char *filename, student **list, int size);
void bubblesort(student **list, int size);
void withdraw(int idNo, student **list, int *sizePtr);
void destroy_list(student **list, int *sizePtr);

//test code

int main(){

char *file1 = "students.txt";
char *file2 = "grades.txt";
char *file3 = "finalgrades.txt";

int index;
int classsize = 0;
student **studentlist;

studentlist = create_class_list(file1, &classsize);

//printf("class: %d\n", class);


//test function 2 (find student)



printf("position for student %d: %d\n", 1200, find(1200, studentlist, classsize));

printf("position for student %d: %d\n", 9000, find(9000, studentlist, classsize));

printf("position for student %d: %d\n", 4444, find(4444, studentlist, classsize));



// test function 3

input_grades(file2, studentlist, classsize);



//test function 4

compute_final_course_grades(studentlist, classsize);

//test function 5

output_final_course_grades(file3, studentlist, classsize);

//test function 6
print_list(studentlist, classsize);

//test function 7

//testing the withdraw of student with ID 4580
withdraw(4580, studentlist, &classsize);
// print out the list to confirm the result
print_list(studentlist, classsize);
//testing the withdraw of student with ID 9000
withdraw(9000, studentlist, &classsize);
// print out the list to confirm the result
print_list(studentlist, classsize);
//testing the withdraw of student with ID 10000 (should be not found)
withdraw(100000, studentlist, &classsize);
// print out the list to confirm the result
print_list(studentlist, classsize);
//test function 8
destroy_list(studentlist, &classsize);
// print out the list to confirm the result
print_list(studentlist, classsize);

}



//function 1 definition

student **create_class_list( char *filename, int *sizePtr ){

int i;
int classsize;
int studentid;
char *firstname;
char *lastname;
student **studentsenrolled;

firstname = malloc(15);
lastname = malloc(15);

//read text file for number of students

FILE *input_file=fopen(filename, "r");

//read size of the class from first record

fscanf(input_file,"%d", &classsize);

//set class size pointer

*sizePtr = classsize;

//allocate memory block for class pointer (top level pointer)

if ((studentsenrolled = malloc(classsize * sizeof(student *))) == NULL)
        {printf("not enough memory\n"); return NULL;}

//loop to read in all students from the file and store in the pointers array

for (i=0; i<classsize; i++){

    // allocate memory for each student

    if ((studentsenrolled[i] = malloc(sizeof(student))) == NULL)
        {printf("not enough memory\n"); return NULL;}

    // read one line from student file for student id, first name and last name
    fscanf(input_file,"%d %s %s", &studentid, firstname, lastname);

    //printf("%d %s %s\n", studentid, firstname, lastname);

    // store student id, first name and last name into the array

    studentsenrolled[i] -> ID = studentid;
    strcpy(studentsenrolled[i] -> firstname,firstname);
    strcpy(studentsenrolled[i] -> lastname,lastname);


    // initialize project 1, project 2 & final grade to zero

    studentsenrolled[i] -> proj1 = 0;
    studentsenrolled[i] -> proj2 = 0;
    studentsenrolled[i] -> finalgrade = 0.0;

}

fclose(input_file); //close file

//sort student list in ascending order of student id
bubblesort(studentsenrolled, classsize);

return studentsenrolled;

}

//function bubble sort will sort the array in ascending order of student id using bubble sort method
void bubblesort(student **list, int size){

    int i,j;
    student temp;

    for(i=0;i<size-1;i++){

        for(j=i+1;j<size;j++){

             if(list[i]->ID > list[j]->ID){

                 temp.ID=list[i]->ID;
                 strcpy(temp.firstname,list[i]->firstname);
                 strcpy(temp.lastname,list[i]->lastname);
                 temp.proj1=list[i]->proj1;
                 temp.proj2=list[i]->proj2;
                 temp.finalgrade=list[i]->finalgrade;

                 list[i]->ID=list[j]->ID;
                 strcpy(list[i]->firstname,list[j]->firstname);
                 strcpy(list[i]->lastname,list[j]->lastname);
                 list[i]->proj1=list[j]->proj1;
                 list[i]->proj2=list[j]->proj2;
                 list[i]->finalgrade=list[j]->finalgrade;

                 list[j]->ID=temp.ID;
                 strcpy(list[j]->firstname,temp.firstname);
                 strcpy(list[j]->lastname,temp.lastname);
                 list[j]->proj1=temp.proj1;
                 list[j]->proj2=temp.proj2;
                 list[j]->finalgrade=temp.finalgrade;

                 }
            }
        }
}


//function 2 to search a student

int find(int idNo, student **list, int size){

    int i;
    for(i=0;i<size;i++){
        if(list[i] -> ID == idNo){
            return i; // return index
        }
    }
    return -1; // return -1 when not found
}



// function 3 to input grades

void input_grades(char *filename, student **list, int size)
{

int i, studentid, proj1, proj2, index;

//read text file for number of students

FILE *input_file=fopen(filename, "r");

for (i=0; i<size; i++){

    fscanf(input_file,"%d %d %d", &studentid, &proj1, &proj2);
    index = find(studentid, list, size);
    if (index != -1)
    {
        list[index] -> proj1 = proj1;
        list[index] -> proj2 = proj2;
    }
}

fclose(input_file);

}


//function 4 final grade calculation

void compute_final_course_grades(student **list, int size){

    int i;

    for(i=0;i<size;i++){
        list[i] -> finalgrade = ((list[i]->proj1 + list[i]->proj2)/2.00);

    }

}



//function 5 output final grades into file

void output_final_course_grades(char *filename, student **list, int size){

    int i;

    //open file for writing

    FILE *output_file=fopen(filename, "w");

    //output class size into file

    fprintf(output_file, "%d\n", size);

    //output each student's id and final grade to output file

    for(i=0;i<size;i++){


        fprintf(output_file, "%04d %.2f\n", list[i]->ID, list[i]->finalgrade);

    }

    fclose(output_file);

}




// function 6 to print students information

void print_list( student **list, int size)
{
int i;

printf("==Student List==\n");

if (size == 0) {
    printf("The list is empty!!\n");
}
else {
    for (i=0; i<size; i++){

        printf("ID: %04d, name: %s %s, project 1 grade: %d, project 2 grade: %d, final grade: %.2f\n",
               list[i]->ID, list[i]->firstname, list[i]->lastname, list[i]->proj1, list[i]->proj2, list[i]->finalgrade);

    }

}

}

//function 7 withdraw

void withdraw(int idNo, student **list, int *sizePtr){

    int location, i;

    location = find(idNo, list, *sizePtr);

    if (location == -1){
        printf("Student %d not found!\n", idNo);
    }
    else{
        if(location == *sizePtr-1){

        //free memory for student to be withdrawn (if student is at the end of the array)

            free(&(list[location]->ID));
            free(list[location]->firstname);
            free(list[location]->lastname);
            free(&(list[location]->proj1));
            free(&(list[location]->proj2));
            free(&(list[location]->finalgrade));

            free(list[location]);
        }

        else{

        for(i=location; i<(*sizePtr-1); i++){

        //free memory for student to be withdrawn (for students that are not at the end of the array)

            free(&list[location]->ID);
            free(list[i]->firstname);
            free(list[i]->lastname);
            free(&list[location]->proj1);
            free(&list[location]->proj2);
            free(&list[location]->finalgrade);

            //point the current pointer to the next student

            list[i] = list[i+1];

        }
        //free the last pointer (because one student has been removed)
        free(list[i-1]);
        }
        //reduces the class size by 1
        *sizePtr = *sizePtr - 1;

        }
}

//function 8 deallocates all the memory used to store the class list and
//sets to 0 the variable in the caller that stores its size

void destroy_list(student **list, int *sizePtr){

    int i;

    //free the memory for each student

    for(i=0;i<*sizePtr;i++){


        free(&list[i]->ID);
        free(list[i]->firstname);
        free(list[i]->lastname);
        free(&list[i]->proj1);
        free(&list[i]->proj2);
        free(&list[i]->finalgrade);

        //free the memory of the pointer to the student
        free(list[i]);
    }

    //free the memory of pointer to the list

    free(list);

    //set size to 0

    *sizePtr = 0;

}
