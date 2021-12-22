#include<stdio.h>
#include<string.h>
struct {
char file[100][100];
char name[100];
}dir;
int fcnt=0;
void insert(){
printf("Enter file name\n");
scanf("%s",dir.file[fcnt++]);
}
int search(){
char name[100];
printf("Enter \n");
scanf("%s",name);
for(int i=0;i<fcnt;i++)
if(strcmp(dir.file[i],name)==0){
return i;
}
return -1;
}
void delete(){
int i=search();
if(i!=-1)
strcpy(dir.file[i],dir.file[--fcnt]);
else printf("Not Found\n");
}
void display(){
printf(" %s ",dir.name);
printf("--------------------+\n");
for(int i=0;i<fcnt;i++)
printf("%s",dir.file[i]);
printf("--------------------+\n");
}
int main(){
int ch;
printf("Enter Directory name\n");
scanf("%s",dir.name);
while(1){
printf("1.Insert\n2.Delete\n3. Search\n");
scanf("%d",&ch);
switch(ch){
case 1:
insert();
break;
case 2:
delete();
break;
case 3: 
if(search()!=-1)printf("Found\n");
else printf("Not Found\n");
break;
case 4:
display();
break;
}
}
}
