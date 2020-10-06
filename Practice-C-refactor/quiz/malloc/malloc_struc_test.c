#include <stdio.h>
#include <stdlib.h>
int main(void)

{

int num, i;
struct student
{
char name[10];
int score;
}*ptr;


printf("Number of student:");
scanf("%d",&num);

ptr=(struct student *) malloc(num*sizeof(struct student));

for (i=0;i<num;i++)
{
fflush(stdin); //clean all data in buffer
printf("name for student %d:", i+1);
fgets((ptr+i)->name,10,stdin);
printf("score for student %d:",i+1);
scanf("%d", &(ptr+i)->score);
}

for(i=0;i<num;i++)

printf("%s: score=%d\n",(ptr+i)->name,(ptr+i)->score);
free(ptr);
system("pause");
return 0;


}
