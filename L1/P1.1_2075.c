#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct Student {
    int rollNum;
    char name[50];
    float marks;
    int gender;
};

int main() {
    struct Student *student = (struct Student*) malloc(sizeof(struct Student));

    int roll;
    char name[50];
    float marks;
    int gender;

    printf("Enter roll number: ");
    scanf("%d", &roll);

    printf("Select Gender (1 -> Female, 0 -> Male): ");
    scanf("%d", &gender);

    printf("Enter marks: ");
    scanf("%f", &marks);

    printf("Enter Name: ");
    scanf("%s", &name);

    student->gender = gender;
    student->marks = marks;
    student->rollNum = roll;
    strcpy(student->name, name);

    printf("\nStudent(roll: %d, marks: %f, gender: %d, name: %s)", student->rollNum, student->marks, student->gender, student->name);

    return 0;
}