#include<iostream>
using namespace std;

template <class t>
class node
{
	public:
		t data;
		node * next;
		
		node(t x,node *n=NULL)
		{
		  data=x;
		  next=n;
		}
};
template <class t>
class CircularLinkedList
{
	  node<t> *cursor;
	  
	  public:
	  CircularLinkedList()
	  {
	  	  cursor=NULL;
	  }
	  void input();
	  int isempty();
	  void insertAtBeg(t);
	  void insertAtEnd(t);
	  void insertAfterNode(t);
	  t removeBeg();
	  t removeLast();
	  void removeNode();
	  node<t>* search(t);
	  CircularLinkedList<t> operator+(CircularLinkedList<t>);
	  void display();	
};

template <class t>
void CircularLinkedList<t>::input()
{
	int n;
	t x;
	cout<<"\nEnter no of nodes in CLL ";
	cin>>n;
	cout<<"\nEnter data part for "<<n<<" nodes"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		insertAtEnd(x);
	}
}

template <class t>
int CircularLinkedList<t>::isempty()
{
	if(cursor==NULL)
	   return 1;
	else
	   return 0;	  
}

template <class t>
void CircularLinkedList<t>::insertAtBeg(t x)
{
	node<t>*newnode=new node<t>(x);
	if(isempty())
	{
		cursor=newnode;
		cursor->next=cursor;
	}
	else
	{
	 	newnode->next=cursor->next;
	    cursor->next=newnode;
    }    	
}

template <class t>
void CircularLinkedList<t>::insertAtEnd(t x)
{
	node<t>*newnode=new node<t>(x);
	   if(isempty())
		{
		  cursor=newnode;
		  cursor->next=cursor;
	    }
		else
		{
		newnode->next=cursor->next;
		cursor->next=newnode;
		cursor=newnode;
		}
}

template <class t>
void CircularLinkedList<t>::insertAfterNode(t x)
{
	if(isempty())
	{
	cout<<"No node exits after which you can insert another new node "<<endl;
	}
	
	else
	{
	node<t>*newnode=new node<t>(x);
	t after;
	node<t> *temp=cursor->next;
	cout<<"\nEnter the data part of the node after which you want to insert "<<endl;
	cin>>after;
	
	do
	{
		if(temp->data==after)
		{
		  newnode->next=temp->next;
		  temp->next=newnode;	
		  
		  if(temp==cursor)
		     cursor=newnode;
		  break;
		}
		  temp=temp->next;
	}while(temp!=cursor->next);
	}
}

template <class t>
t CircularLinkedList<t>::removeBeg()
{
	node<t> *temp;
	t x=cursor->next->data;
	
	if(cursor->next==cursor)
    {
    	cursor=NULL;
    	delete cursor;
    	
	}
	else
	{
		temp=cursor->next;
		cursor->next=temp->next;
		delete temp;
	}
	return x;
}
	
template <class t>
t CircularLinkedList<t>::removeLast()
{
	node<t> *temp;
	t x=cursor->data;
	if(cursor->next==cursor)
    {
    	delete cursor;
    	cursor=NULL;
	}
	else
	{
		temp=cursor->next;
		while(temp->next!=cursor)
		{
			temp=temp->next;
		}
		temp->next=cursor->next;
		delete cursor;
		cursor=temp;
	}
	return x;
}
	
template <class t>
void CircularLinkedList<t>::removeNode()
{
	t del;
	cout<<"Enter the data part of the node you want to delete "<<endl;
	cin>>del;
	node<t> *previous,*current;
	node<t> *temp;
	if(cursor->next==cursor && cursor->data==del)
	{
		cursor=NULL;
		delete cursor;
	}
	else if(cursor->next->data==del)
	{
	    t b=removeBeg();
	    cout<<b<<" has been deleted "<<endl;
	}
	else
	{
	   previous=cursor->next;
	   current=previous->next;
	   while(current!=NULL)
	   {
	   	  if(current->data==del)
	   	  {
	   	  	temp=current;
	   	  	current=NULL;
		  }
		  else
		  {
		  	previous=previous->next;
		  	current=current->next;
		  }
		  previous->next=temp->next;
	   }	
	}  	 
}

template <class t>
node<t>* CircularLinkedList<t>::search(t x)
{
	node<t>*temp;
    temp=cursor->next;
    do
    {
    	if(temp->data==x)
	      return temp;
	    temp=temp->next; 
	}
	while(temp!=cursor->next);
	return NULL;
}

template <class t>
CircularLinkedList<t> CircularLinkedList<t>::operator+(CircularLinkedList<t> l2)
{ 
    node<t>*temp;
	CircularLinkedList<t> l3;
	if(!(*this).isempty())
	{
		temp=(*this).cursor->next;
		do
		{
			l3.insertAtEnd(temp->data);
			temp=temp->next;
		}
		while(temp!=(*this).cursor->next);
	}
	if(!l2.isempty())
	{
		temp=l2.cursor->next;
		do
		{
			l3.insertAtEnd(temp->data);
			temp=temp->next;
		}
		while(temp!=l2.cursor->next);
	}
	return l3;	
}

template <class t>
void CircularLinkedList<t>::display()
{
	if(cursor==NULL)
	   cout<<"No node in singly linked list "<<endl;
	else
	{
		cout<<"Circular Linked List values : "<<endl<<endl;
		node<t> *temp=cursor->next;
		do
		{
			cout<<temp->data<<"->";
			temp=temp->next;		
		}
		while(temp!=cursor->next);
		cout<<endl;
	}
}

int main()
{
   CircularLinkedList<int> l1,l2,l3;
   l1.input();
   l1.display();
   node<int>*temp;
   int choice,d,x,e,b;
   char ch='y';
   do
	{
	    cout<<"\n---------Main Menu---------"<<endl;
		cout<<"1.Insert at Beginning"<<endl;
		cout<<"2.Insert at End"<<endl;
		cout<<"3.Insert after a particular node"<<endl;
		cout<<"4.Delete first node"<<endl;
		cout<<"5.Delete last node"<<endl;
		cout<<"6.Delete a particular node"<<endl;
		cout<<"7.Search a node"<<endl;
		cout<<"8.Concatenate two list "<<endl;
		cout<<"9.Display"<<endl;
		cout<<"\nEnter choice "<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1:  cout<<"Enter the data of new node you want to insert at beginning"<<endl;
 	                 cin>>d;
                     l1.insertAtBeg(d);
			         l1.display();
			         break;
			        
			case 2:  cout<<"Enter the data of new node you want to insert at end "<<endl;
 	                 cin>>d;
			         l1.insertAtEnd(d);
			         l1.display();
			         break;
			        
		    case 3: cout<<"Enter the data of new node you want to insert after ith node "<<endl;
 	                cin>>d;
					l1.insertAfterNode(d);
			        l1.display();
			        break;
			    
		    case 4: if(l1.isempty())
	                {
		             cout<<"Circular Linked List Already Empty . Can't Delete "<<endl;
	                }
		            else
		            {
		             b=l1.removeBeg();
		             cout<<"The node having data "<<b<<" is deleted."<<endl;
		             l1.display();
		            }
		            break;
		            
		    case 5: if(l1.isempty())
	                {
		             cout<<"Circular Linked List Already Empty . Can't Delete "<<endl;
	                }
			        else
		            {
		            e=l1.removeLast();
		            cout<<"The node having data "<<e<<" is deleted."<<endl;
		            l1.display();
		           	}
		            break;
		            
		    case 6: if(l1.isempty())
	                {
		             cout<<"Circular Linked List Already Empty . Can't Delete "<<endl;
	                }
		            l1.removeNode();
		            l1.display();
		            break;
		               
		    case 7: if(l1.isempty())
	                {
		             cout<<"Circular Linked List is Empty"<<endl;
	                }
		            else
		            {
		              cout<<"Enter data of node to be searched "<<endl;
		              cin>>x;
			          temp=l1.search(x);
			          if(temp!=NULL)
			            cout<<"Node found having data "<<temp->data<<endl;
			          else
			            cout<<"Node not Found "<<endl;
					}
			        break;
					
			case 8:   cout<<"Enter Elements of 2nd Linked List"<<endl;
			          l2.input();
			          l2.display();
			          l3=l1+l2;
			          l3.display();
			          break;
			            
			case 9:  l1.display();
				      break;
			
			default :cout<<"Error in input ";
							    	
	      }
cout<<"\nDo you want to continue ";
cin>>ch;
cout<<endl;
}while(ch=='y');
}
	

