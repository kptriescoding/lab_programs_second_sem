#include<stdio.h>
#include<stdlib.h>
typedef struct file{
char name[50];
}file;
typedef struct directory{
char name[50];
struct directory *d[5];
file *f[5];
}dir;
void print_directory(dir *s_lvl,int n){
if(s_lvl==NULL) return;
printf("Subdirectory name: %s\n",s_lvl->name);
printf("---------------------------------+%s\n",s_lvl->name);
printf("Its files:\n");
for(int i=0;i<n;i++)
if(s_lvl->f[i]!=NULL)
printf("%s\n",s_lvl->f[i]->name);
printf("---------------------------------+%s\n",s_lvl->name);
}
void single_level(dir *s_lvl,int flag){
for(int i=0;i<5;i++){
s_lvl->d[i]=NULL;
s_lvl->f[i]=NULL;
}
printf("Enter the number of files in directory:%s\n",s_lvl->name);
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
file *t=(file*)malloc(sizeof(file));
printf("Enter the file name to be inserted to %s\n",s_lvl->name);
scanf("%s",t->name);
s_lvl->f[i]=t;
}
if(flag)
print_directory(s_lvl,n);
}
void two_level(dir *s_lvl){
for(int i=0;i<5;i++){
s_lvl->d[i]=NULL;
s_lvl->f[i]=NULL;
}
printf("Enter the name of the root directory\n");
scanf("%s",s_lvl->name);
printf("Enter the number of subdirectories in this directory\n");
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
dir *t=(dir*)malloc(sizeof(dir));
printf("Enter the subdirectory\n");
scanf("%s",t->name);
single_level(t,0);
s_lvl->d[i]=t;
}
printf("Directory name:%s\n",s_lvl->name);
for(int i=0;i<5;i++){
print_directory(s_lvl->d[i],n);
printf("\n");
}
}
dir* tree_directory(dir *root){
if(root==NULL)
return NULL;
for(int i=0;i<5;i++)
{
root->d[i]=NULL;
root->f[i]=NULL;
}
printf("Enter the name of the directory\n");
scanf("%s",root->name);
printf("Enter the number of subdirectories in %s\n",root->name);
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
dir *t=(dir*)malloc(sizeof(dir));
root->d[i]=tree_directory(t);
}
int fn;
printf("Enter the number of files in %s directory \n",root->name);
scanf("%d",&fn);
for(int i=0;i<fn;i++)
{
file *t=(file*) malloc(sizeof(file));
printf("Enter the file name\n");
scanf("%s",t->name);
root->f[i]=t;
}
return root;
}
int count=0;
void print_treedirectory(dir *root){
if(root==NULL) return ;
printf("%s\n",root->name);
printf("---------------------------------+%s\n",root->name);
for(int i=0;i<5;i++)
print_treedirectory(root->d[i]);
for(int i=0;i<5;i++)
{
printf("\t");
if(root->f[i]!=NULL)printf(" * %s \n",root->f[i]->name);
}
printf("\n");
printf("---------------------------------+%s\n",root->name);
printf("\n");
}
int main(){
dir *t=(dir*)malloc(sizeof(dir));
/*printf("Single level Directory\n");
printf("Enter the name of the directory\n");
scanf("%s",t->name);
single_level(t,1);
printf("Two level Directory\n");
two_level(t);*/
printf("Tree Directory\n");
t=tree_directory(t);
print_treedirectory(t);
}
