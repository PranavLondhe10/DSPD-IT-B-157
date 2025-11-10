#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    int age;
    float avgMarks;
};

int main() {
    int n, i, j;
    struct Student temp;

    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar(); 

    struct Student s[n];

    for(i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &s[i].rollNo);
        getchar();

        printf("Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0'; 

        printf("Age: ");
        scanf("%d", &s[i].age);

        printf("Average Marks: ");
        scanf("%f", &s[i].avgMarks);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(s[j].avgMarks < s[j + 1].avgMarks) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted in descending order of average marks:\n");
    printf("RollNo\tName\t\tAge\tAvgMarks\n");
    printf("--------------------------------------------------\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%-15s\t%d\t%.2f\n", s[i].rollNo, s[i].name, s[i].age, s[i].avgMarks);
    }

    return 0;
}
