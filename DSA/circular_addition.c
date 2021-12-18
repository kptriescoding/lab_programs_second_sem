#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}Node;
int maxf(int n1, int n2);
int getst(char s[100]);
Node *createnode(int ele);
Node* insertbeg(Node* head, int ele);
Node* insertend(Node* head, int ele);
Node* add(Node*head1,Node*head2,Node *head3,int size);
void display(Node* head, Node* recurse);
int main() {
   Node *head1=createnode(0);
    Node *head2=createnode(0);
        Node *head3=createnode(0);
    head1->next = head1;
    head2->next = head2;
   head3->next = head3;
    char n1[100], n2[100];
    printf("Enter the first number\n");
int s1=    getst(n1);
    printf("Enter the second number\n");
    int s2=getst(n2);
    int max = maxf(s1, s2);
        for (int i = 0; i < max; i++) {
            if (i < s1)
                head1 = insertbeg(head1, n1[i] - '0');
            else
                head1 = insertend(head1, 0);
            if (i < s2)
                head2 = insertbeg(head2, n2[i] - '0');
            else
                head2 = insertend(head2, 0);
        }
    head3=add(head1,head2,head3,max);
    printf("The sum is\n");
    display(head3, head3);
printf("\n");
}
int maxf(int n1, int n2) {
    if (n1 > n2)return n1;
    else return n2;
}
int getst(char s[100]) {
    int j = 0;
        scanf("%s",s);
    while (s[j] != '\0') {
        if (s[j] - '0' < 0 || s[j] - '0' > 9) {
            printf("The entered string is not correct.Enter Again\n");
            scanf("%s",s);
            j = 0;
        }
        else
            j++;
    }
    return j;
}
Node *createnode(int ele){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = ele;
    return newnode;
}
Node* insertbeg(Node* head, int ele) {
    Node* newnode = createnode(ele);
    newnode->next = head->next;
    head->next = newnode;
    return head;
}
Node* insertend(Node* head, int ele) {
    Node* newnode = createnode(ele);
    Node* temp = head->next;
    while (temp->next != head)
        temp = temp->next;
    newnode->next = head;
    temp->next = newnode;
    return head;
}
void display(Node* head, Node* recurse) {
        if (recurse->next != head)
        display(head,recurse->next);    
if(recurse!=head)
    printf("%d", recurse->data);

}
Node* add(Node*head1,Node*head2,Node *head3,int size){
    Node* temp1=head1->next;
    Node* temp2=head2->next;
int carry=0;
    for(int i=0;i<=size;i++){
            int sum=temp1->data+temp2->data+carry;
            if(sum>9)
            carry=1;
	    else
	    carry=0;
            if(i<size||sum==1)
            head3=insertend(head3,sum%10);
            temp1=temp1->next;
            temp2=temp2->next;
    }   
    return head3;
}
