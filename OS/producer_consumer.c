#include<stdio.h>
#include<string.h>
typedef struct Semaphore{
int full,empty,mutex,count;
} semaphore;
int wait(int S);
int signal(int S);
void producer(semaphore *S);
void consumer(semaphore *S);
int main(){
semaphore S;
S.full=0;
S.empty=0;
S.mutex=1;
S.count=0;
printf("Enter the number of free buffers.\n");
scanf("%d",&S.empty);
while(S.empty<=0){
printf("The Buffers should be greater than zero.\n");
printf("Enter the number of free buffers.\n");
scanf("%d",&S.empty);
}
int j=1;
while(j!=3){
printf("What would you like to do\n1. Produce\n2. Consume\n3. Exit\n");
scanf("%d",&j);
switch(j){
case 1:
producer(&S);
break;
case 2:
consumer(&S);
break;
case 3:
printf("Exited succesfully.\n");
break;
default :
printf("Wrong input TRY Again.\n"); 
break;
}
}
}
int wait(int I){
I--;
return I;
}
int signal(int I){
I++;
return I;
}
void producer(semaphore *S){
if(S->mutex==1&&S->empty>0)
{
S->mutex=wait(S->mutex);
S->empty=wait(S->empty);
if(S->empty==0)
printf("All Buffers are full!!\n");
else
printf("The process occupied one Buffer occupied!!The amount of free Buffer is %d\n.",S->empty);
S->full=signal(S->full);
S->mutex=signal(S->mutex);
}
else{
printf("The Buffer is Full!! This process is in the waiting list. This process will be executed when the buffer becomes free.\n");
S->count++;
printf("The amount of process in the waitlist is %d\n", S->count);
}}
void consumer(semaphore *S){
if(S->mutex==1&&S->full>0)
{
if(S->count>0){
printf("One buffer freed!!One process from the waitlist occupied the Buffer. All Buffers are full.\n");
S->count=wait(S->count);
if(S->count==0)
printf("No Process in the waiting list.\n");
else
printf("The amount of process in the waitlist is %d.\n", S->count);
}
else{
S->mutex=wait(S->mutex);
S->full=wait(S->full);
S->empty=signal(S->empty);
printf("One buffer freed!!The amount of free Buffer is %d.\n",S->empty);
S->mutex=signal(S->mutex);
}
}
else
printf("Nothing left to consume!! Produce something first.\n");
}
