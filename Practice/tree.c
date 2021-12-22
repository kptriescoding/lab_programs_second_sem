#include<stdio.h>
#include<stdlib.h>
typedef struct File{
char name[100];
}file;
typedef struct Directory{
char name[100];
file *f[5];
struct Directory *d[5];
}dir;
dir * tree_dir(dir *s_lvl){
for(int i=0;i<5;i++){
s_lvl->d[i]=NULL;
s_lvl->f[i]=NULL;
}
int n;
printf("Enter name\n");
scanf("%s",s_lvl->name);
printf("Enter how many subdirectories\n");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
dir *t=(dir*)malloc(sizeof(dir));
s_lvl->d[i]=tree_dir(t);
}
printf("Enter how many files\n");
scanf("%d",&n);
printf("Enter Files\n");
for(int i=0;i<n;i++)
{
file* t=(file*)malloc(sizeof(file));
scanf("%s",t->name);
s_lvl->f[i]=t;
}
return s_lvl;
}
dir *print_tree(dir *s_lvl){
if(s_lvl==NULL)return NULL;
printf("%s\n",s_lvl->name);
printf("----------------------------------+%s\n",s_lvl->name);
for(int i=0;i<5;i++)
if(s_lvl->d[i]!=NULL)print_tree(s_lvl->d[i]);
for(int i=0;i<5;i++)
if(s_lvl->f[i]!=NULL)printf("  *%s  \n",s_lvl->f[i]->name);
printf("----------------------------------+%s\n",s_lvl->name);
}
int main(){
dir *t=(dir*)malloc(sizeof(dir));
t=tree_dir(t);
print_tree(t);
}
