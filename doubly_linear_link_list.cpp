#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
class DoublyLinear
{
    struct node *head;
    int iCnt;
    public:
    DoublyLinear()
    {
        head=NULL;
        iCnt=0;
    }
    ~DoublyLinear()
    {
        if(head!=NULL)
        {
            while(head!=NULL)
            {
                if(head->next==NULL)
                {
                    delete(head);
                    head=NULL;
                }
                else
                {
                    head=head->next;
                    delete(head->prev);
                }
                
            }
        }
    }
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPosition(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int);
    
};
void DoublyLinear::InsertFirst(int no)
{
    struct node *newn=NULL;
    newn=new struct node;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
    
    if(head==NULL)
    {
      head=newn;
    }
    else
    {
        head->prev=newn;
        newn->next=head;
        head=newn;
    }
    iCnt++;    
}
void DoublyLinear::InsertLast(int no)
{
    struct node *newn=NULL;
    newn=new struct node;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(head==NULL)
    {
        head=newn;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
    iCnt++;
}
void DoublyLinear::InsertAtPosition(int pos,int no)
{
    if((pos<1)||(pos>iCnt+1))
    {
        cout<<"\nInvalid Choice!!";
        return;
    }
    if(pos==1)
    {
        InsertFirst(no);
    }
    else if (pos==iCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node *temp=head;
        struct node *newn=NULL;
        newn=new struct node;
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;

        for(int i=1;i<pos-1;i++)
        {
          temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;

        iCnt++;
    }
    
}
void DoublyLinear::DeleteFirst()
{
    if(head==NULL)
    {
        cout<<"\nThere is no element!!";
        return;
    }
    else if (head->next==NULL)
    {
      delete(head);
      head=NULL;  
    }
    else
    {
        head=head->next;
        delete(head->prev);
        head->prev=NULL;   
    }
    iCnt--;
    
}
void DoublyLinear::DeleteLast()
{
    if(head==NULL)
    {
        cout<<"\nThere is no element!!";
        return;
    }
    else if(head->next==NULL)
    {
        delete(head);
        head=NULL;
    }
    else
    {
        struct node *temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete(temp->next);
        temp->next=NULL;
    }
    iCnt--;
}
void DoublyLinear::DeleteAtPosition(int pos)
{
    if((pos<1)||(pos>iCnt))
    {
        cout<<"\nInvalid Position!!";
        return;
    }
    if(pos==1)
    {
        DeleteFirst();
    }
    else if (pos==iCnt)
    {
        DeleteLast();
    }
    else
    {
        struct node *temp=head;
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        delete(temp->next->prev);
        temp->next->prev=temp;
        
        iCnt--;
    }
    
    
}
void DoublyLinear::Display()
{
    struct node *temp=head;
    
    if(head==NULL)
    {
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    
}
int DoublyLinear::Count()
{
    return iCnt;
}
int main()
{
    DoublyLinear s1;
    int no=0,pos=0,choice=0,iRet=0;

    char ans='\0';
    do
    {
        cout<<"1.Insert At First Position\n";
        cout<<"2.Insert At Last Postion\n";
        cout<<"3.Insert At specific position\n";
        cout<<"4.Delete At First Position\n";
        cout<<"5.Delete At Last Position\n";
        cout<<"6.Delete At Specific Position\n";
        cout<<"7.Count how many are there in link list\n";
        cout<<"8.Display all elements in the list\n";
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice)
        {
            case 1:cout<<"\nEnter the element:";
                   cin>>no;
                   s1.InsertFirst(no);
                   s1.Display();
                   
                   break;
            case 2:cout<<"\nEnter the element:";
                   cin>>no;
                   s1.InsertLast(no);
                   s1.Display();
                   break;
            case 3:cout<<"\nEnter position:";
                   cin>>pos;
                   cout<<"\nEnter the element:";
                   cin>>no;
                   s1.InsertAtPosition(pos,no);  
                   s1.Display();
                   
                   break;

            case 4:s1.DeleteFirst();
                   s1.Display();
                   break;
            case 5:s1.DeleteLast();
                   s1.Display();
                   break;
            case 6:cout<<"\nEnter the Position:";
                   cin>>pos;
                   s1.DeleteAtPosition(pos);
                   s1.Display();
                   break;

            case 7:iRet=s1.Count();
                   cout<<"No. of Elements:"<<iRet;
                    break;

            case 8:s1.Display();
                   break;
            default:cout<<"Invalid input!!\n";
                     break;
        }
        cout<<"\nDo you want above operation again(y/n):";
        cin>>ans;

    }while(ans=='Y' || ans=='y');
 
    return 0;
}