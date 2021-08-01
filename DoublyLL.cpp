#include<iostream>
using namespace std;

template <class t>
class node
{
	public:
		t data;
		node * next,*prev;
		
		node(t x,node *n=NULL,node*m=NULL)
		{
		  data=x;
		  next=n;
		  prev=m;
		}
};

template <class t>
class DoublyLinkedList
{
	  node<t> *head,*tail;
	  
	  public:
	  DoublyLinkedList()
	  {
	  	  head=tail=NULL;
	  }
	  int isempty();
	  void input();
	  void insertAtBeg(t);
	  void insertAtEnd(t);
	  void insertAtPos(t);
	  void insertAfterPos(t);
	  t deleteFromBeg();
	  t deleteFromEnd();
	  void deleteFromPos();
	  node<t>* search(t);
	  void count();
	  void reverse(DoublyLinkedList<t>);
	  DoublyLinkedList<t> operator+(DoublyLinkedList <t> l1);
	  void display();		
};

template <class t>
int DoublyLinkedList<t>::isempty()
{
	if(head==NULL)
	   return 1;
	else
	   return 0;	  
}

template <class t>
void DoublyLinkedList<t>::input()
{
	int n;
	t x;
	cout<<"\nEnter no of nodes in DLL ";
	cin>>n;
	cout<<"\nEnter data part for "<<n<<" nodes"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		insertAtEnd(x);
	}
}

template <class t>
void DoublyLinkedList<t>::insertAtBeg(t x)
{
	node<t>*newnode=new node<t>(x);
	
	if(head==NULL)
	{
		  head=tail=newnode;
	}
	else
	{
		head->prev=newnode;
	    newnode->next=head;
	    head=newnode;
	}
}

template <class t>
void DoublyLinkedList<t>::insertAtEnd(t x)
{
    node<t>*newnode=new node<t>(x);
    
    if(head==NULL)
	{
		head=tail=newnode;
	}
	else
	{
		tail->next=newnode;
	    newnode->prev=tail;
	    tail=newnode;
	}
}

template <class t>
void DoublyLinkedList<t>::insertAtPos(t x)
{
	node<t>*newnode=new node<t>(x);
	node<t> *temp=head;
	int pos,i=1;
	cout<<"\nEnter the position at which you want to insert the node ";
	cin>>pos;
	if(pos<1)
	  cout<<"\nInvalid position ";
	else if(pos==1)
	{
		insertAtBeg(newnode->data);
	}
	else
	{
		while(i<(pos-1))
		{
			temp=temp->next;
			i++;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		temp->next=newnode;
		temp->next->prev=newnode;
	}
}

template <class t>
void DoublyLinkedList<t>::insertAfterPos(t x)
{
	node<t>*newnode=new node<t>(x);
	node<t> *temp=head;
	int pos,i=1;
	cout<<"\nEnter the position after which you want to insert the node ";
	cin>>pos;
	if(pos<1)
	  cout<<"\nInvalid position ";
	else
	{
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		temp->next=newnode;
		temp->next->prev=newnode;
	}
}

template <class t>
t DoublyLinkedList<t>::deleteFromBeg()
{
	t x=head->data;
	if(head==tail)
	{
		delete head;
		head=tail=NULL;
	}
	else
	{
	    head=head->next;
	    delete(head->prev);
	    head->prev=NULL;	
	}
	return x;
}

template <class t>
t DoublyLinkedList<t>::deleteFromEnd()
{
	t x=tail->data;
	if(head==tail)
	{
		delete tail;
		head=tail=NULL;
	}
	else
	{
	    tail=tail->prev;
	    delete(tail->next);
	    tail->next=NULL; 
	}
	return x;
}

template <class t>
void DoublyLinkedList<t>::deleteFromPos()
{
	int pos,i=1;
	node<t>*temp=head;
	cout<<"\nEnter the position of the node you want to delete ";
	cin>>pos;
	
	if(pos==1)
	   deleteFromBeg();
	   
	else 
	{
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		delete temp;
	}
}

template <class t>
node<t>* DoublyLinkedList<t>::search(t x)
{
	node<t>*temp;
	
	if(head->data==x)
	    return head;
	    
	else if(tail->data==x)
	    return tail;
	else
	{
		temp=head->next;
		while((temp!=NULL)&&(temp->data!=x))
	     {
		     temp=temp->next;
	     }
	     return temp;
	}
}

template <class t>
void DoublyLinkedList<t>::count()
{
	if(head==NULL)
	   cout<<"No node in doubly linked list "<<endl;
	else
	{   int c=0;
		node<t> *temp=head;
		while(temp!=NULL)
		{
			c++;
			temp=temp->next;		
		}
		cout<<"No of nodes in Doubly list are: "<<c<<endl;
	}
}

template <class t>
void DoublyLinkedList<t>::reverse(DoublyLinkedList<t> l1)
{
	node<t> *temp;
	temp=l1.head;
	while(temp!=NULL)
	{
		(*this).insertAtBeg(temp->data);
		temp=temp->next;
	}
     cout<<"\nDoubly Linked List Reversed "<<endl;
     display();
}

template <class t>
DoublyLinkedList<t> DoublyLinkedList<t>::operator+(DoublyLinkedList <t> l2)
{
	node<t>*temp;
	DoublyLinkedList<t> l3;
	if(!(*this).isempty())
	{
		temp=(*this).head;
		while(temp!=0)
		{
			l3.insertAtEnd(temp->data);
			temp=temp->next;
		}
	}
	if(!l2.isempty())
	{
		temp=l2.head;
		while(temp!=0)
		{
			l3.insertAtEnd(temp->data);
			temp=temp->next;
		}
	}
	return l3;
	
}
template <class t>
void DoublyLinkedList<t>::display()
{
	if(head==NULL)
	   cout<<"No node in Doubly linked list "<<endl;
	else
	{
		cout<<"\nContents of Doubly Linked List : "<<endl;
		node<t> *temp=head;
		
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;		
		}
		cout<<endl;
	}
}


int main()
{
   DoublyLinkedList<int> l1,l2,l3;
   l1.input();
   node<int>*temp;
   int choice,d,x,e,b;
   char ch='y';
   do
	{
	    cout<<"-----------Main Menu----------"<<endl;
		cout<<"1.Insert At Beg "<<endl;
		cout<<"2.Insert At End "<<endl;
		cout<<"3.Insert At Pos "<<endl;
		cout<<"4.Insert After Pos "<<endl;
		cout<<"5.Delete From Beg "<<endl;
		cout<<"6.Delete From End "<<endl;
		cout<<"7.Delete From Pos"<<endl;
		cout<<"8.Search the Node"<<endl;
		cout<<"9.Count no of Nodes"<<endl;
		cout<<"10.Reverse the List"<<endl;
		cout<<"11.Concatenate Two List"<<endl;
		cout<<"12.Display the List"<<endl;
		cout<<"\nEnter choice "<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1:  cout<<"Enter the data of new node you want to insert at beginning of list"<<endl;
 	                 cin>>d;
 	                 l1.insertAtBeg(d);
			         l1.display();
			         break;
			        
			case 2:  cout<<"Enter the data of new node you want to insert at end "<<endl;
 	                 cin>>d;
			         l1.insertAtEnd(d);
			         l1.display();
			         break;
			        
		    case 3:  cout<<"Enter the data of new node you want at position "<<endl;
 	                 cin>>d;
					 l1.insertAtPos(d);
			         l1.display();
			         break;
			    
			case 4:  cout<<"Enter the data of new node  you want to insert after position "<<endl;
 	                 cin>>d;
 	               	 l1.insertAfterPos(d);
			         l1.display();
			         break;
			
			case 5:  if(l1.isempty())
	                 {
		              cout<<"Doubly Linked List Already Empty . Can't Delete "<<endl;
	                 }
		            else
		             {
		               b=l1.deleteFromBeg();
		               cout<<"The node having data "<<b<<" is deleted."<<endl;
		               l1.display();
		             }
		             break;
		             
		    case 6:  if(l1.isempty())
	                 {
		              cout<<"Doubly Linked List Already Empty . Can't Delete "<<endl;
	                 }
		            else
		             {
		               e=l1.deleteFromEnd();
		               cout<<"The node having data "<<e<<" is deleted."<<endl;
		               l1.display();
		             }
		             break;
		             
		   case 7:  if(l1.isempty())
	                 {
		              cout<<"Doubly Linked List Already Empty . Can't Delete "<<endl;
	                 }
		            else
		             {
		               l1.deleteFromPos();
		               l1.display();
		             }
		             break;
			
			case 8: cout<<"Enter data of node to be searched "<<endl;
		            cin>>x;
			        temp=l1.search(x);
			        if(temp!=NULL)
			            cout<<"Node found having data "<<temp->data<<endl;
			        else
			            cout<<"Node not Found "<<endl;
		            break;    
		            
		   case 9:  l1.count();
			        break;
					       
		   case 10:  l2.reverse(l1);
			         break;
			        
		   case 11:   cout<<"Enter Elements of 2nd Linked List"<<endl;
			          l2.input();
			          l2.display();
					  l3=l1+l2;
		              l3.display();
		             break;
		             
		   case 12:  l1.display();
		             break;
		
		   default :  cout<<"Error in input ";
							    	
	      }
cout<<"\nDo you want to continue ";
cin>>ch;
}while(ch=='y');
}
	
	
	
	
	
	
	
	


