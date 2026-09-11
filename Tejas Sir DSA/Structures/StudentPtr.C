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

}s[SIZE], *p;

void getData()
{

    p = s;

    for (int i = 0; i < SIZE; i++)
    {

        printf("Enter name of student %d: ", i + 1);
        scanf("%s", p->name);

        printf("Enter marks in Maths, Science and English: ");
        scanf("%d %d %d", &p->maths, &p->sci, &p->eng);

        p++;
    }
}

void calPerAndGrade()
{

    p = s;

    for (int i = 0; i < SIZE; i++)
    {

        p->prec = (p->maths + p->sci + p->eng) / 3.0;

        if (p->prec >= 35)
            p->grade = 'P';
        else
            p->grade = 'F';

        p++;
    }
}

void display()
{

    p = s;

    printf("\nName\tMaths\tScience\tEnglish\tPercentage\tGrade\n");

    for (int i = 0; i < SIZE; i++)
    {

        printf("%s\t%d\t%d\t%d\t%.2f\t%c\n", p->name, p->maths, p->sci, p->eng, p->prec, p->grade);

        p++;
    }
}

int main()
{

    getData();

    calPerAndGrade();
    
    display();

    return 0;

} // end of main