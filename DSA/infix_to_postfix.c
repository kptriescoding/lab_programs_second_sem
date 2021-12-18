#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct Stack{
int top;
char item[100];
};
struct Stack s;
char inf[100],pos[100];
int isop(char);
void push(char);
char pop();
char peek();
void inpos(int n);
int precedence(char);
int exvalid(int n);
void getstring();
int main()
{
	s.top=-1;
	int i=0;
	printf("Enter the infix expression\n");
	getstring();
	while(inf[i]!='\0')
		i++;
	while(exvalid(i)==0){
		printf("Expression is invalid\n");
		printf("Enter the infix expression\n");
	getstring();
	while(inf[i]!='\0')
		i++;
	}
	inpos(i);
}
void inpos(int n){
	int i=0,j=0;
	while(i<n){
	char ch=inf[i];
		if (isalnum(ch))
		pos[j++]=ch;
		else if(ch=='(')
			push(ch);
		else if(ch==')')
		{
			while(peek()!='(')
				pos[j++]=pop();
			pop();
		}
		else if(isop(ch)){
			if(s.top==-1||peek()=='('||ch=='^'||precedence(ch)>precedence(peek()))
				push(ch);
			else
			{
				while(s.top!=-1&&precedence(ch)<=precedence(peek())&&peek()!='(')
					pos[j++]=pop();
				push(ch);
			}
		}
	i++;
	}
	while(s.top!=-1)
		pos[j++]=pop();
		printf("The Postfix Expression is %s",pos);
}
int exvalid(int n){
int i=0;
if(n<2)
return 0;
while(i<n){
	char ch=inf[i];
	if(!(isalnum(ch)||isop(ch)||ch=='('||ch==')'||ch==' '))
		return 0;
	else if(ch=='(')
	push(ch);
	else if(ch==')'){
	if(peek()!='(')
	return 0;
	else
	pop();
	}
	else if(i<n&&(isalnum(ch)&&isalnum(inf[i+1])))	
	return 0;
	else if(i<n-1&&(isop(ch)&&isop(inf[i+1])))
	return 0;
	else if(isop(inf[n-1])||isop(inf[0]))
return 0;
	i++;
}
if(s.top!=-1)
return 0;
return 1;
}
int precedence(char ch){
	if(ch=='+'||ch=='-')
		return 0;
	else if(ch=='/'||ch=='*'||ch=='%')
		return 1;
	else if(ch=='^')
		return 2;
}
int isop(char ch){
	if(ch=='+'||ch=='-'||ch=='/'||ch=='*'||ch=='%'||ch=='^')
		return 1;
	return 0;
}
void push(char ch)
{
	if(s.top==100)
		printf("\nOVERFLOW CONDITION\n");
	else
		s.item[++s.top]=ch;
}
char pop(){
	if(s.top==-1)
		printf("\nUNDERFLOW CONDITION \n");
	else
	return s.item[s.top--];
}
char peek(){
	if(s.top==-1)
		printf("\nUNDERFLOW CONDITION \n");
	else
	return s.item[s.top];
}
void getstring(){
strcpy(inf,"");
int i=0;
char ch;
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
inf[i]='\0';
}

