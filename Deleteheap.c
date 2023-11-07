#include<stdio.h>
void insert(int *arr,int i)
{
    int root=(i-1)/2;
     while(arr[root]>arr[i])
     {
        int temp=arr[root];
        arr[root]=arr[i];
        arr[i]=temp;
        i=root;
        root=(root-1)/2;
     }
     return;
}
void delete_max(int *a,int n)
{
    int last =a[n-1];
    a[0]=last;
    for(int i=0;i<n-1;)
    {
             int root=i;
             int left=2*i+1;
             int right=2*i+2;
             int min=(a[left]<a[right])?a[left]:a[right];
             int index=(a[left]<a[right])?left:right;
             if(a[root]<min)
             {
                break;
             }
             else
             {
               int temp=a[root];
               a[root]=a[index];
               a[index]=temp;
               i=index;
             }
    }

}
int main()
{
   int n;
   printf("Enter number of elements:\t");
   scanf("%d",&n);
   int a[n];
   for(int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
       insert(a,i);
   }
   for(int i=0;i<n;i++)
   {
    printf("%d ",a[i]);
   }
   printf("\n");
   delete_max(a,n);
   n=n-1;
   printf("\nOUTPUT\n");
   for(int i=0;i<n;i++)
   {
    printf("%d ",a[i]);
   }

}