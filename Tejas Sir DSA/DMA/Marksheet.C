// #include<stdio.h>
// #include<stdlib.h>

// int main(){

//     char *name;
//     int *maths;
//     int *sci;
//     int *eng;
//     float *perc;
//     char *grade;

//     name = (char*) malloc(sizeof(char) * 30);
//     maths = (int*) malloc(sizeof(int));
//     sci = (int*) malloc(sizeof(int));
//     eng = (int*) malloc(sizeof(int));
//     perc = (float *) malloc(sizeof(float)); 
//     grade = (char *) malloc(sizeof(char));

//     printf("Enter the Name of Student : ");
//     scanf("%s", name);
//     fflush(stdin);
//     printf("Enter the Marks of Maths : ");
//     scanf("%d", maths);
//     printf("Enter the Marks of Sci : ");
//     scanf("%d", sci);
//     printf("Enter the Marks of Eng : ");
//     scanf("%d", eng);

//     *perc = (*maths + *sci + *eng) / 3.0;

//     if(*perc >= 35){

//         *grade = 'P';

//     }else{

//         *grade = 'F';

//     }//end of if-else

//     printf("\nName : %s", name);
//     printf("\nMaths : %d", *maths);
//     printf("\nSci : %d", *sci);
//     printf("\nEng : %d", *eng);
//     printf("\nPerc : %f", *perc);
//     printf("\nGrade : %c", *grade);

// }//end of main

#include<stdio.h>
#include<stdlib.h>

struct Student
{
 
    char name[30];
    int maths;
    int sci;
    int eng;
    float perc;
    char grade;
    
};


int main(){

    struct Student *s;
    
    s = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter the Name of Student : ");
    scanf("%s", s->name);
    fflush(stdin);
    printf("Enter the Marks of Maths : ");
    scanf("%d", &s->maths);
    printf("Enter the Marks of Sci : ");
    scanf("%d", &s->sci);
    printf("Enter the Marks of Eng : ");
    scanf("%d", &s->eng);

    s->perc = (s->maths + s->sci + s->eng) / 3.0;

    if(s->perc >= 35){

        s->grade = 'P';

    }else{

        s->grade = 'F';

    }//end of if-else

    printf("\nName : %s", s->name);
    printf("\nMaths : %d", s->maths);
    printf("\nSci : %d", s->sci);
    printf("\nEng : %d", s->eng);
    printf("\nPerc : %f", s->perc);
    printf("\nGrade : %c", s->grade);

}//end of main