#include<stdio.h>
void insert(int *arr,int i)
{
    int root=(i-1)/2;
     while(arr[root]<arr[i])
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
    a[n-1]=a[0];
    a[0]=last;
    for(int i=0;i<n-1;)
    {
             int root=i;
             int left=2*i+1;
             int right=2*i+2;
             int max,index;
             if(right<n-1)
             {
              max=(a[left]>a[right])?a[left]:a[right];
              index=(a[left]>a[right])?left:right;
             }
             if(left==n-2)
             {
                max=left;
                index=left;
             }
             if(a[root]>max||left>=n-1)
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
   printf("\nMAX HEAP\n");
   for(int i=0;i<n;i++)
   {
    printf("%d ",a[i]);
   }
   printf("\n");
   int t=n;
   for(int i=0;i<n;i++)
   {
    delete_max(a,t);
    t=t-1;
   }
   printf("\nAfter heap sort\n");
   for(int i=0;i<n;i++)
   {
    printf("%d ",a[i]);
   }

}