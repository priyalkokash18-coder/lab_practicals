#include <stdio.h>
struct Student {
    char name[10];
    int year;
    char branch;
    float avg;
};
int main() {
     struct student s[3],s1;
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("year: ");
        scanf("%d", &s[i].year);
        printf("branch: ");
        scanf("%d", &s[i].bramch);
        printf("Average Marks: ");
        scanf("%f", &s[i].avg);
    }
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (s[j].avg < s[j+1].avg) {
                s1=s[j];
                s[j]=s[j+1];
                s[j+1]=s1;
            }
        }
    }
    printf("\nName:%s, year:%d, branch:%s, average:%f\n" , s[i].name, s[i].year, s[i].branch, s[i].avg:);
    }
    }
    return 0;
}
