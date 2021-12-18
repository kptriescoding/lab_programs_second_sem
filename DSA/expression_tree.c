#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
typedef struct node
{
  struct node *left, *right;
  char data;
} Node;
typedef struct stack
{
  int top;
  Node *arr[100];
} stn;
stn ste,sto;
char inf[100];
Node *createnode (char data);
Node *exprtree (Node * root);
void push (stn *st,Node * op);
Node* pop (stn *st);
Node* peek (stn *st);
int isop (char ch);
int prec (char ch);
void postorder (Node * root);
void preorder (Node * root);
void inorder (Node * root);
void getstring();
int main(){
ste.top=-1;
sto.top=-1;
  Node *root = NULL;
  printf ("Enter the infix expression\n");
  getstring();
  root = exprtree (root);
  printf ("The postfix expression is\n");
    postorder (root);
   printf("\n");
  printf ("The prefix expression is\n");
    preorder (root);
  printf ("\n");
    printf ("The infix expression is\n");
    inorder (root);
  printf ("\n");
}
Node *exprtree(Node *root){
Node *temp1,*temp,*temp2;
char ch=inf[0];
for(int i=0;inf[i]!='\0';i++){
ch=inf[i];
if(isalnum(ch)){
temp=createnode(ch);
push(&ste,temp);
}
else if(prec(ch)){
if(sto.top==-1||prec(ch)>prec(peek(&sto)->data)||ch=='^'){
temp=createnode(ch);
push(&sto,temp);
}
else{
while(sto.top!=-1&&prec(ch)<=prec(peek(&sto)->data)){
temp=pop(&sto);
temp1=pop(&ste);
temp2=pop(&ste);
temp->left=temp2;
temp->right=temp1;
push(&ste,temp);
}
temp=createnode(ch);
push(&sto,temp);
}
}
}
while(sto.top!=-1){
temp=pop(&sto);
temp1=pop(&ste);
temp2=pop(&ste);
temp->left=temp2;
temp->right=temp1;
push(&ste,temp);
}
root=pop(&ste);
return root;
}
Node *createnode (char data)
{
  Node *newnode = (Node *) malloc (sizeof (Node));
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

Node * pop (stn *st)
{
    return st->arr[st->top--];
}
void push (stn *st,Node * op)
{
    st->arr[++st->top] = op;
}
Node * peek(stn *st)
{
  return st->arr[st->top];
}
int prec (char ch)
{
  if (ch == '^')
    return 3;
  if (ch == '*' || ch == '/' || ch == '%')
    return 2;
  if (ch == '-' || ch == '+')
    return 1;
  return 0;
}
void inorder (Node * root)
{
if(root==NULL)return;
    inorder (root->left);
      printf (" %c ", root->data);
    inorder (root->right);
}
void postorder (Node * root)
{
if(root==NULL)return;
    postorder (root->left);
    postorder (root->right);
  printf (" %c ", root->data);
}
void preorder (Node * root)
{
if(root==NULL)return;
  printf (" %c ", root->data);
    preorder (root->left);
    preorder (root->right);
}
void getstring(){
strcpy(inf,"");
char ch;
int i=0;
while(scanf("%c",&ch))
{
	if(ch=='\n')
	break;
	else
	{
		inf[i]=ch;
		i++;
	}
}
}
