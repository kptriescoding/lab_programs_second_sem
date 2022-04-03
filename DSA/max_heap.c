#include<stdio.h>
#define N 10
int n=0;
void heapify(int arr[]){
    int i, k, j, sm, flag;
    for(i = n/2; i >-1; i--){
        k = i;
        sm = arr[k];
        flag = 0;
        while(!flag && 2*k+1 < n){
            j = 2 * k+1;
            if (j < n){
                if(arr[j] < arr[j+1])
                    j = j+1;
            }
            if(sm >= arr[j])
                flag = 1;
            else{
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = sm;
    }
}
void insert(int arr[]){
int k;
printf("Enter the number of elements\n");
scanf("%d",&k);
printf("Enter the elements\n");
int max=n+k,in;
for(int i=n;i<max;i++){
scanf("%d",&in);
if(n==N){
printf("The Heap is full\n");
break;
}
arr[i]=in;
n++;
printf("Inserted Successfully\n");
}
heapify(arr);
}
void delete(int arr[]){
printf("The max is %d\n",arr[0]);
arr[0]=arr[n-1];
n--;
heapify(arr);
printf("Max is removed\n");
}
void display(int arr[]){
printf("The elements of max queue are \n");
for(int i=0;i<n;i++)
printf(" %d ",arr[i]);
printf("\n");
}
int main(){
int ch=0,arr[N],k;
while(ch!=4){
printf("1. Insert\n2. Extract Max\n3. Display\n4. Exit\n");
scanf("%d",&ch);
switch(ch){
case 1:
insert(arr);
break;
case 2:
delete(arr);
case 3:
display(arr);
break;
case 4:
printf("Exited Succesfully\n");
break;
default:
printf("Invalid input\n");
}
}
}
