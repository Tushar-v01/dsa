#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int coef;
    int exp;
    struct node* next;
}*head,*head1,*head2,*newnode,*temp,*temp1,*t,*temp2,*head3,*temp3;

struct node* Pread()  // Take input from user
{
     int n;
     printf("Enter number of term in polynomial:");
     scanf("%d",&n);
     head=NULL;
     for(int i=0;i<n;i++)
     {
       // printf("%d\n",i);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        printf("Enter coefficient:");
        scanf("%d",&newnode->coef);
        printf("Enter exponent:");
        scanf("%d",&newnode->exp);
        if(head==NULL)
        {
            head=newnode;
            newnode->next=head;
        }
          temp1=head;
          t=NULL;
         if(newnode!=head)
         {
            
           do
            {
                
                if((temp1->exp)>(newnode->exp))
                {
                    t=temp1;
                    
                }
                     temp1=temp1->next;     
            }
             while(temp1!=head);
         if(t!=NULL)
         {
            temp=t->next;
            newnode->next=temp;
            t->next=newnode;
         }
         
         if(t==NULL)
         {
           newnode->next=head;
           temp=head;
           while(temp->next!=head)
           {
              temp=temp->next;
           }
           temp->next=newnode;
           head=newnode;
         }
         }

     }
     return head;
}
void Pwrite(struct node* h) // Print output
{
     temp=h;
     printf("%+dx^%d",temp->coef,temp->exp);
     temp=temp->next;
     while(temp!=h)
     {
          printf("%+dx^%d",temp->coef,temp->exp);
          temp=temp->next;
     }  
     printf("\n");
}

void Padd()      // Addition of two polynomial
{
     temp1=head1;
     temp2=head2;
     head3=NULL;
    do
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        int a=temp1->coef;
        int b=temp2->coef;
        if(head3==NULL)
        {
            head3=newnode;
            newnode->next=head3;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
            newnode->next=head3;
        }
      if(head3==temp)
      {
           if(temp1->exp==temp2->exp)
        {
            newnode->exp=temp1->exp;
            newnode->coef=a+b;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else  if(temp1->exp>temp2->exp)
        {
            newnode->exp=temp1->exp;
            newnode->coef=a;
            temp1=temp1->next;
        }
        else  if(temp1->exp<temp2->exp)
        {
            newnode->exp=temp2->exp;
            newnode->coef=b;
           
            temp2=temp2->next;
        }
      }
      else
      {
        if(temp1->exp==temp2->exp)
        {
            newnode->exp=temp1->exp;
            newnode->coef=a+b;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else  if(temp2==head2||temp1->exp>temp2->exp)
        {
            newnode->exp=temp1->exp;
            newnode->coef=a;
            temp1=temp1->next;
        }
        else  if(temp1==head1||temp1->exp<temp2->exp)
        {
            newnode->exp=temp2->exp;
            newnode->coef=b;
           
            temp2=temp2->next;
        }
      }

    }
    while(temp1!=head1||temp2!=head2);
    Pwrite(head3);
}


void Psub()
{
     temp1=head1;
     temp2=head2;
     head3=NULL;
    do
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        int a=temp1->coef;
        int b=temp2->coef;
        if(head3==NULL)
        {
            head3=newnode;
            newnode->next=head3;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
            newnode->next=head3;
        }
      if(head3==temp)
      {
           if(temp1->exp==temp2->exp)
        {
            newnode->exp=temp1->exp;
            newnode->coef=a-b;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else  if(temp1->exp>temp2->exp)
        {
            newnode->exp=temp1->exp;
            newnode->coef=a;
            temp1=temp1->next;
        }
        else  if(temp1->exp<temp2->exp)
        {
            newnode->exp=temp2->exp;
            newnode->coef=0-b;
           
            temp2=temp2->next;
        }
      }
      else
      {
        if(temp1->exp==temp2->exp)
        {
            newnode->exp=temp1->exp;
            newnode->coef=a-b;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else  if(temp2==head2||temp1->exp>temp2->exp)
        {
            newnode->exp=temp1->exp;
            newnode->coef=a;
            temp1=temp1->next;
        }
        else  if(temp1==head1||temp1->exp<temp2->exp)
        {
            newnode->exp=temp2->exp;
            newnode->coef=0-b;
           
            temp2=temp2->next;
        }
      }

    }
    while(temp1!=head1||temp2!=head2);
    Pwrite(head3);
}

void Pmult()
{
    temp1=head1;
    temp2=head2;
    head3=NULL;
   do
    {
        do
        {
            struct node *newnode=(struct node *) malloc (sizeof(struct node));
            newnode->coef=temp1->coef*temp2->coef;
            newnode->exp=temp1->exp+temp2->exp;
            newnode->next=NULL;
            if(head3==NULL)
            {
                head3=newnode;
                temp3=newnode;
                newnode->next=head3;
            }
            else
        {
            temp3->next=newnode;
            temp3=newnode;
            newnode->next=head3;
        }
            temp2=temp2->next;
           
        }
        while(temp2!=head2);
        temp1=temp1->next;
        temp2=head2;
    }
     while(temp1!=head1);

     
    Pwrite(head3);
}
void Peval()
{
    float x;
    printf("Enter value of x:");
    scanf("%f",&x);
    float ans=0;
    temp=head1;
   do
   {
        int c=temp->coef;
        int d=temp->exp;
        ans+=c*pow(x,d);
        temp=temp->next;
   }
   while(temp!=head1);
   printf("Polynomial1=%f ",ans);
   
    
}

void Perase()
{
    int pos;
    printf("Enter position of term you want to erase in Polynomial1:");
    scanf("%d",&pos);
    int count=1;
    temp1=head1;
    printf("%d",temp1->next->coef);
    do
    {
        
           if(pos==1)
           {
             temp=head1;
             if(temp->next==head1)
             {
                head1=NULL;
                break;
             }
             else
             {
              while(temp->next!=head1)
             {
                  temp=temp->next;
             }
             }
             temp->next=temp->next->next;
             head1=temp->next;

             
           }
          
          else if(count==(pos-1))
          {
               temp1->next=temp1->next->next;
          }
           temp1=temp1->next;
           count++;
    }
    while(temp1!=head1);
    Pwrite(head1);

    
}
int main()
{
     
     head1=Pread();
     Pwrite(head1);
     head2=Pread();
     Pwrite(head2);
     printf("\n\nADD=");
     Padd();
     printf("\n\nSUB=");
     Psub();
     printf("\n\nMULTIPLY=");
     Pmult();
     printf("\n\nEVALUATION=");
     Peval();
     printf("\n\nErase:\n");
     Perase();
}