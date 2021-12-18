#include<stdio.h>
#include<stdlib.h>
typedef struct Nodes{
int coef,pow;
struct Nodes *next;
}Node;
void printpoly(Node* head);
Node* addpoly(Node* head,int coef,int pow);
Node* multipoly(Node *head1,Node* head2, Node *head3);
int main(){

int coef,pow,key,te1,te2;
Node *head1=NULL,*head2=NULL,*head3=NULL;
printf("How many terms in the first polynomial: ");
scanf("%d",&te1);
printf("Enter the terms in the form 'coef pow'\n");
for(int i=0;i<te1;i++){
scanf("%d%d",&coef,&pow);
head1=addpoly(head1,coef,pow);
}
printf("How many terms in the second polynomial: ");
scanf("%d",&te2);
printf("Enter the terms in the form 'coef pow'\n");
for(int i=0;i<te2;i++){
scanf("%d%d",&coef,&pow);
head2=addpoly(head2,coef,pow);
}
printf("The first polynomial is\n");
printpoly(head1);
printf("\nThe second polynomial is\n");
printpoly(head2);
head3=multipoly(head1,head2,head3);
printf("\n");
printf("The product is\n");
printpoly(head3);
printf("\n");
}
Node* addpoly(Node* head,int coef,int pow){
Node *newnode=(Node*)malloc(sizeof(Node));
newnode->coef=coef;
newnode->pow=pow;
newnode->next=NULL;
Node* temp=head,*temp2=head;
if(head==NULL)
head=newnode;
else{
while(temp->next!=NULL&&temp->pow>pow){
temp2=temp;
temp=temp->next;
}
if(temp->pow==pow)
temp->coef+=coef;
else if(temp==head)
{
if(temp->pow<pow){
newnode->next=head;
head=newnode;
}
else
temp->next=newnode;
}
else if(temp->next==NULL){
if(temp->pow<pow){
temp2->next=newnode;
newnode->next=temp;
}
else
temp->next=newnode;
}
else{
newnode->next=temp->next;
temp->next=newnode;
}
}
return head;
}
Node* multipoly(Node *head1,Node* head2, Node *head3){
Node *temp1=head1, *temp2=head2;
while(temp1!=NULL){
temp2=head2;
while(temp2!=NULL){
int coef=(temp1->coef)*(temp2->coef);
int pow=(temp1->pow)+(temp2->pow);
head3=addpoly(head3,coef,pow);
temp2=temp2->next;
}
temp1=temp1->next;
}
return head3;
}
void printpoly(Node *head){
while(head!=NULL&&head->next!=NULL){
printf(" %dx^%d ",head->coef,head->pow);
if(head->next->coef>0)printf("+");
head=head->next;
}
if(head!=NULL){
if(head->pow!=0)
printf(" %dx^%d ",head->coef,head->pow);
else
printf(" %d ",head->coef);
}
}
