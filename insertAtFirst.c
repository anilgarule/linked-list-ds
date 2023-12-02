#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn -> next = NULL;
    if(*Head==NULL)
    {
        *Head = newn;
    }
    else 
    {
        newn -> next = *Head;
        *Head = newn;
    }
}
void Display(PNODE Head)
{
    printf("elements of linked list are : \n");
    while(Head!=NULL)
    {
        printf("| %d | ->",Head -> data);
        Head = Head -> next;
    }
    printf("NULL \n");
}
int Count(PNODE Head)
{
    int icnt = 0;
    while(Head!=NULL)
    {
        icnt++;
        Head = Head -> next;
    }
    return icnt;
}
void InsertLast(PPNODE Head, int no)
{
    PNODE temp = *Head;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn -> next = NULL;
    if(*Head==NULL)
    {
        *Head=newn;
    }
    else 
    {
       while(temp -> next != NULL)
       {
        temp  = temp -> next;
       }
       temp -> next= newn;
    }
}
void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;
    if(*Head==NULL)
    {
        return;
    }
    else if((*Head) -> next==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else 
    {
        *Head=(*Head)->next;
        free(temp);
    }
}
void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;
    if(*Head==NULL)
    {
        return;
    }
    else if((*Head) -> next==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else 
    {
        while(temp -> next -> next!=NULL)
        {
            temp = temp->next;

        }
        free(temp -> next);
        temp -> next = NULL;
    }

}
void InsertAtPos(PPNODE Head, int no, int ipos)
{
    PNODE temp = *Head;  // xerox
     int i= 0;
    int size = 0;
   size= Count(*Head);
   int i = 0;
   if((ipos<1) || (ipos> size+1))
   {
    printf("invalid position \n");
    return;
   }
    if(ipos==1)
   {
    InsertFirst(Head,no);
   }
   else if(ipos==size+1)
   {
    InsertLast(Head,no);
   }
   else 
   {
      PNODE newn = NULL;
      newn = (PNODE)malloc(sizeof(NODE));
      newn -> data = no;
      newn ->next = NULL;
      for(i=1; i<ipos-1; i++)
      {
        temp =temp->next;
      }
        newn -> next = temp -> next;
        temp -> next = newn;
      
      
   }
}
void DeletetAtPos(PPNODE Head,  int ipos)
{
    int size = 0;
   size= Count(*Head);
   int i = 0;
   if((ipos<1) || (ipos> size))
   {
    printf("invalid position \n");
    return;
   }
   else if(ipos==1)
   {
    DeleteFirst(Head);
   }
   else if(ipos==size)
   {
    DeleteLast(Head);
   }
   else 
   {

   }
}  
int main()
{
   PNODE first = NULL;
   int iRet = 0;
   InsertFirst(&first,111);
   InsertFirst(&first,101);
   InsertFirst(&first,51);
   InsertFirst(&first, 21);
   InsertFirst(&first,11);
   Display(first);
   iRet=Count(first);
   printf("number of nodes are : %d \n",iRet);

   InsertLast(&first,121);
   InsertLast(&first,151);
   Display(first);
   iRet=Count(first);
   printf("number of nodes are : %d \n",iRet);

   DeleteFirst(&first);
   Display(first);
   iRet=Count(first);
   printf("number of nodes are : %d \n",iRet);

   DeleteLast(&first);
   Display(first);
   iRet=Count(first);
   printf("number of nodes are : %d \n",iRet);
   return 0;
}