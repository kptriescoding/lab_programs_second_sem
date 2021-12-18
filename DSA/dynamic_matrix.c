#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data,row,col;
struct node *next,*prev;
}Node;
Node* insert(Node *head,int data,int row,int col);
void displaymatrix(Node *head,int row,int col);
void display(Node *head);
int main(){
Node *head=NULL;
int row,col;
printf("Enter the number of rows\n");
scanf("%d",&row);
printf("Enter the number of columns\n");
scanf("%d",&col);
printf("Enter the elements\n");
for(int i=0;i<row;i++)
for(int j=0;j<col;j++)
{
int data;
scanf("%d",&data);
if(data!=0)
head=insert(head,data,i,j);
}
printf("The Linked List is\n");
display(head);
printf("\nThe inputted matrix is\n");
displaymatrix(head,row,col);
}
Node* insert(Node *head,int data,int row,int col){
Node *newnode=(Node*)malloc(sizeof(Node));
newnode->data=data;
newnode->row=row;
newnode->col=col;
newnode->next=NULL;
newnode->prev=NULL;
Node*temp=head;
if(head==NULL)
head=newnode;
else{
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
newnode->prev=temp;
}
return head;
}
void displaymatrix(Node *head, int row,int col){
Node *temp=head;
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++){
if(temp!=NULL&&i==temp->row&&j==temp->col){
printf(" %d ",temp->data);
if(temp!=NULL||temp->next!=NULL)temp=temp->next;
}
else
printf(" 0 ");
}
printf("\n");
}
}
void display(Node *head){
Node *temp=head;
while(temp->next!=NULL)
{
printf(" %d ",temp->data);
temp=temp->next;
}
printf(" %d ",temp->data);
}
