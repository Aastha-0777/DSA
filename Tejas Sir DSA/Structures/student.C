#include <stdio.h>
#define SIZE 3

struct student
{

    char name[50];
    int maths;
    int sci;
    int eng;
    float prec;
    char grade;
};

struct student s[SIZE];

void getDetails()
{

    for (int i = 0; i < SIZE; i++)
    {

        printf("Enter the Name, Maths, Sci, Eng : ");
        scanf("%s%d%d%d", &s[i].name, &s[i].maths, &s[i].sci, &s[i].eng);

    } // end of for

} // end of getDetails

void calPercAndGrade()
{

    for (int i = 0; i < SIZE; i++)
    {

        s[i].prec = (s[i].maths + s[i].sci + s[i].eng) / 3.0;

        if (s[i].prec >= 35)
        {

            s[i].grade = 'P';
        }
        else
        {

            s[i].grade = 'F';

        } // end of if-else

    } // end of for

} // end of calPercAndGrade

void display()
{

    printf("| Name |\t| Maths |\t| Sci |\t| Eng |\t| Perc |\t| Grade |\n");

    for (int i = 0; i < SIZE; i++)
    {

        printf("| %s |\t| %d |\t| %d |\t| %d |\t| %f |\t| %c |\n", s[i].name, s[i].maths, s[i].sci, s[i].eng, s[i].prec, s[i].grade);

    } // end of for

} // end of display

int main() {

    getDetails();

    calPercAndGrade();

    display();

    return 0;

} // end of main
