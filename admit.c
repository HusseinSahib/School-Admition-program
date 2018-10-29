/* Hussein Sahib
10/5/18
TCES 203
Assignment #1
This program will compare two applicants to determine which one seems like the stronger one
using their SAT or ACT scores and their GPA
*/

#include <stdio.h>
#include <stdlib.h>
void intro();
int apptype();
float SAT();
float ACT();
float GPA();
float TotalScore(float, float);
void comapare(float, float);
float student(int);
int main()
{
    intro();//print introduction
    float student1;
    float student2;
    printf("Information for the first application\n");
    student1 = student(apptype());// this function take input for the first student's score  information
    printf("\nInformation for the second application\n");
    student2 = student(apptype());// this function take input for the second student's score  information
    printf("\n");
    comapare(student1,student2);// this function takes in the two students' information to compare them
    return 0;
}
// This function determine which type of application the students want to fill (ACT or SAT)
int apptype()
{
    int type;
    printf("do you have 1) SAT scores or 2) ACT scores? ");
    scanf("%d",&type);
    return type;
}
//program introduction
void intro()
{
    printf("This program compares two applicants \nto determine which one seems like the stronger\n");
    printf("applicant. For each candidate I will need \n");
    printf("either SAT or ACT scores plus a weighted GPA.\n\n\n");
}
//Takes input for SAT scores and calculates the student's score
float SAT()
{
    float math, verbal;
    printf("SAT math: ");
    scanf("%f",&math);
    printf("SAT verbal: ");
    scanf("%f",&verbal);
    float score = (2*verbal+math)/24;
    return score;
}
//Takes input for ACT scores to calculate the student score
float ACT()
{
    float reading, english, math, science;
    printf("ACT English: ");
    scanf("%f",&english);
    printf("ACT Math: ");
    scanf("%f",&math);
    printf("ACT Reading: ");
    scanf("%f",&reading);
    printf("ACT Science: ");
    scanf("%f",&science);
    float score = ((2* reading) + english + math + science)/1.8;
    return score;
}
// takes in gpa and returns the percentage of the gpa
float GPA()
{
    float yourgpa, maxgpa;
    printf("actual GPA: ");
    scanf("%f",&yourgpa);
    printf("maximum GPA :");
    scanf("%f",&maxgpa);
    float score = (yourgpa/maxgpa)*100;
    return score;
}
//calculates the total score of the student using test score and gpa
float TotalScore(float gpascore, float testscore)
{
    float score = testscore + gpascore;
    return score;
}
//compares the students scores and tells us who is the better student
void comapare(float student1, float student2)
{
    printf("first student overall score %.3f\n",student1);
    printf("second student overall score %.3f\n",student2);

    if (student1 > student2)
    {
        printf("The first applicant seems better");
    }
    else if(student2 > student1)
    {
        printf("The second applicant seems better");
    }
    else
    {
        printf("The applicants are equal!");
    }
}
//This function might seem extra but I found it helpful to have a function that puts all the information together.
float student(int num)
{
    if (num == 1)
    {
        return TotalScore(GPA(), SAT());
    }
    else
    {
        return TotalScore(GPA(), ACT());
    }

}

