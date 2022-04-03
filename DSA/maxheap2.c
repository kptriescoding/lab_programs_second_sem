#include<stdio.h>
#define N 10
int n=0;
void heapify(int arr[],int i){
   
   int l=2*i+1,r=2*i+2,lar=i;
        if(l<=n&&arr[l]>arr[lar])
        lar=l;
        if(r<=n&&arr[r]>arr[lar]) 
        lar=r;      
        if(lar!=i)
        {
            int temp=arr[i];
            arr[i]=arr[lar];
            arr[lar]=temp;
            heapify(arr,lar);
        }
    }
void buildheap(int arr[]){
    for(int i=n/2;i>-1;i--)
    heapify(arr,i);
}
void insert(int arr[]){
 int k;
      printf("How many elements do you\n");
      scanf("%d",&k);
      for(int i=0;i<k;i++){
          if(n==N)
          {
              printf("Heap is Full\n");
              break;
          }
          scanf("%d",&arr[n++]);
      }
printf("Inserted Successfully\n");
}
buildheap(arr);
}
void delete(int arr[]){
    if(n<0){
        printf("Heap is empty\n");
        return;
    }
printf("The max is %d\n",arr[0]);
arr[0]=arr[n-1];
n--;
heapify(arr,0);
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
