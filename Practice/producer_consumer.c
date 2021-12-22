#include<stdio.h>
int n=5;
struct{
int empty,full,mutex;
}s;
int wait(int S){
return --S;
}
int signal(int S){
return ++S;
}
void producer(){
if(s.mutex==1&&s.empty>0){
s.mutex=wait(s.mutex);
s.empty=wait(s.empty);
printf("Free Buffers %d\n",s.empty);
s.full=signal(s.full);
s.mutex=signal(s.mutex);
}
else
printf("Buffers are Full\n");
}
void consumer(){
if(s.mutex==1&&s.full>0){
s.mutex=wait(s.mutex);
s.full=wait(s.full);
s.empty=signal(s.empty);
printf("Free Buffers %d\n",s.empty);
s.mutex=signal(s.mutex);
}
else
printf("Buffers are Empty\n");
}
int main(){
s.full=0;
s.mutex=1;
s.empty=n;
while(1){
int ch;
scanf("%d",&ch);
switch(ch){
case 1:
producer();
break;
case 2:
consumer();
}
}}
