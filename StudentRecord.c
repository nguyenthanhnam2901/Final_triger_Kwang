#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"
#include "Check.h"

int n;
student students[1003];
int mx(int a, int b) {
    return (a > b ? a : b);
}

void input()
{
    bool numberstudent = false;
    while (!numberstudent)
    {
        printf("Enter the number of students: ");
        printf("\n");
        scanf("%d", &n);
        if (!isValidNumberOfStudents(n))
        {
            printf("Invalid number of students. Please try again\n");
        }
        
        else
        {
            numberstudent = true;
        }

        for (int i = 1; i <= n; ++i)
        {
            bool validID = false;
            while (!validID)
            {
                printf("Enter the information of student #%d\n", i);
                printf("ID: ");
                scanf("%s", students[i].id);
                printf("\n");

                if (isDuplicateID(students, i, students[i].id))
                {
                    printf("Duplicate ID. Please enter a different ID.\n");
                }

                else
                {
                    validID = true;
                }
            }

            printf("Fullname, last name and first name, separated by a space: ");
            scanf("%s%s", students[i].fullName.lastName, students[i].fullName.firstName);
            printf("\n");

            // Validate birthdate input
            bool validBirthdate = false;
            while (!validBirthdate)
            {
                printf("Birthdate in the format date month year: ");
                scanf("%d%d%d", &students[i].birthDay.day, &students[i].birthDay.month, &students[i].birthDay.year);
                printf("\n");
                if (!isValidBirthdate(students[i].birthDay.day, students[i].birthDay.month, students[i].birthDay.year))
                {
                    printf("Invalid birthdate. Please try again.\n");
                }
                
                else
                {
                    validBirthdate = true;
                }
            }

            // Validate grade input
            bool validGrade = false;
            while (!validGrade)
            {
                printf("Algebra, Calculus, BP grade, separated by a space: ");
                scanf("%f%f%f", &students[i].grade[0], &students[i].grade[1], &students[i].grade[2]);
                printf("\n");
                if (!isValidGrade(students[i].grade))
                {
                    printf("Invalid grade. Please try again.\n");
                }

                else
                {
                    validGrade = true;
                }
            }
        }
    }
}

int  numLen(int x) {
    if(x == 0) return 1;
    int len = 0;
    while (x > 0)
    {
        x /= 10;
        len++;
    }
    return len;
}
int tableLen[7] = {2,9,9,7,8,17,4};

int main()
{
    input();
    for(int i = 1; i <= n; ++i) {
        tableLen[0] = mx(tableLen[0],strlen(students[i].id));
        tableLen[1] = mx(tableLen[1],strlen(students[i].fullName.lastName) + strlen(students[i].fullName.firstName) + 1);
        tableLen[2] = mx(tableLen[2], numLen(students[i].birthDay.day) + numLen(students[i].birthDay.month) + numLen(students[i].birthDay.year) + 2);
    }
    printf("ID");
    for(int i = 1; i <= tableLen[0] - 2; ++i) printf(" ");
    printf("\tFull Name"); 
    for(int i = 1; i <= tableLen[1] - 9; ++i) printf(" ");
    printf("\tBirthdate");
    for(int i = 1; i <= tableLen[2] - 9; ++i) printf(" ");
    printf("\tAlgebra       ");
    printf("Calculus       ");
    printf("Basic Programming       ");
    printf("GPA\n");
    for(int i = 1; i <= n; ++i) {
        printf("%s", students[i].id);
        for(int j = 1; j <= tableLen[0] - strlen(students[i].id); ++j) printf(" ");
        printf("\t%s %s", students[i].fullName.lastName, students[i].fullName.firstName);
        for(int j = 1; j <= tableLen[1] - strlen(students[i].fullName.lastName) - strlen(students[i].fullName.firstName); ++j) printf(" ");
        printf("\t%d/%d/%d", students[i].birthDay.day, students[i].birthDay.month, students[i].birthDay.year);
        for(int j = 1; j <= tableLen[2] - (numLen(students[i].birthDay.day) + numLen(students[i].birthDay.month) + numLen(students[i].birthDay.year) + 2); ++j) printf(" ");
        for(int j = 0; j <= 2; ++j) {
            if(students[i].grade[j] < 10.0) {
                printf("       %.2f", students[i].grade[j]);
                for(int k = 1; k <= tableLen[3 + j] - 4; ++k) printf(" ");
            }
            else {
                printf("       %.2f", students[i].grade[j]);
                for(int k = 1; k <= tableLen[3 + j] - 5; ++k) printf(" ");
            }
        }
        printf("       %.2f\n",gpa(students[i]));
    }
}
