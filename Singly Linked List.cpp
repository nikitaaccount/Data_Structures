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
class SinglyLinkedList
{
	  node<t> *head;
	  
	  public:
	  SinglyLinkedList()
	  {
	  	  head=NULL;
	  }
	  int isempty();
	  void insertAtBeg(t);
	  void insertAtEnd(t);
	  void insertAfterNode(t);
	  void insertBeforeNode(t);
	  void removeBeg();
	  void removeLast();
	  void removeNode();
	  node<t>* search(t);
	  void count();
	  void reverse();
	  SinglyLinkedList<t> operator+(SinglyLinkedList<t>);
	  void display();	
};

template <class t>
int SinglyLinkedList<t>::isempty()
{
	if(head==NULL)
	   return 1;
	else
	   return 0;	  
}

template <class t>
void SinglyLinkedList<t>::insertAtBeg(t x)
{
	node<t>*newnode=new node<t>(x);
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
	 	newnode->next=head;
	    head=newnode;
    }    	
}

template <class t>
void SinglyLinkedList<t>::insertAtEnd(t x)
{
	node<t>*newnode=new node<t>(x);
	   if(head==NULL)
		{
		  head=newnode;
	    }
		else
		{
		 node<t> *temp=head;
		 while(temp->next!=NULL)
			    temp=temp->next;
		 temp->next=newnode;
		}
}

template <class t>
void SinglyLinkedList<t>::insertAfterNode(t x)
{
	node<t>*newnode=new node<t>(x);
	t after;
	node<t> *temp=head;
	cout<<"\nEnter the data part of the node after which you want to insert "<<endl;
	cin>>after;
	while(temp!=NULL)
	{
		if(temp->data==after)
		{
		  newnode->next=temp->next;
	      temp->next=newnode;
	      cout<<"Node Inserted after "<<after<<endl;
	      return ;
	    }
	    temp=temp->next; 
	}
}

template <class t>
void SinglyLinkedList<t>::insertBeforeNode(t x)
{
	node<t>*newnode=new node<t>(x);
	t before;
	cout<<"\nEnter the data part of the node before which you want to insert "<<endl;
	cin>>before;
	node<t> *temp;
	if(head->data==before)
	{
		newnode->next=head;
		head=newnode;
		return;
	}
	for(temp=head;temp->next!=NULL;temp=temp->next)
	{
		if(temp->next->data==before)
		{
			newnode->next=temp->next;
			temp->next=newnode;
			return;
		}
	}
}

template <class t>
void SinglyLinkedList<t>::removeBeg()
{
	node<t> *temp;
	temp=head;
	head=head->next;
	delete temp;
	cout<<"First Node deleted "<<endl;
    
}
	
template <class t>
void SinglyLinkedList<t>::removeLast()
{
	node<t> *temp;
	node<t> *prevnode;
	temp=head;
	while(temp->next!=NULL)
	{
		prevnode=temp;
		temp=temp->next;
	}
	if(temp==head)
	   head=0;
	else
	   prevnode->next=0;
	delete temp;	
	cout<<"Last Node deleted "<<endl;	 
}
	
template <class t>
void SinglyLinkedList<t>::removeNode()
{
	       t del;
	       cout<<"Enter the data part of the node you want to delete "<<endl;
	       cin>>del;
       	   node<t> *temp=NULL;
		   node<t> *prevptr=head;
		   node<t> *currentptr=head->next;
		   while(currentptr!=NULL)	
		   {
		   	 if(currentptr->data==del)
		   	 {
		   	 	temp=currentptr;
		   	 	currentptr=NULL;
			 }
			 else
			 {
			 	prevptr=prevptr->next;
			 	currentptr=currentptr->next;
			 }
		   }
		   if(temp!=NULL)
		   {
		   	 prevptr->next=temp->next;
		   	 cout<<"Node deleted having data "<<del<<endl;
		   }
		   else
		   {
		   	 cout<<"Node doesn't exits with data value "<<del<<endl;
		   }
}

template <class t>
node<t>* SinglyLinkedList<t>::search(t x)
{
	node<t>*temp;
	
	if(head->data==x)
	    return head;
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
void SinglyLinkedList<t>::count()
{
	if(head==NULL)
	   cout<<"No node in singly linked list "<<endl;
	else
	{   int c=0;
		node<t> *temp=head;
		while(temp!=NULL)
		{
			c++;
			temp=temp->next;		
		}
		cout<<"No of nodes in singly list are: "<<c<<endl;
	}
}

template <class t>
void SinglyLinkedList<t>::reverse()
{
	if(head==NULL||head->next==NULL)
	  return ;
	  
	else
	{
	node<t>*prev=NULL,*current=NULL,*nextn=NULL;
	current=head;
	while(current!=NULL)
	 {
		nextn=current->next;
		current->next=prev;
		prev=current;
		current=nextn;
	 }
	head=prev;
    }
}

template <class t>
SinglyLinkedList<t> SinglyLinkedList<t>::operator+(SinglyLinkedList<t> l2)
{ 
    node<t>*temp;
	SinglyLinkedList<t> l3;
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
void SinglyLinkedList<t>::display()
{
	if(head==NULL)
	   cout<<"No node in singly linked list "<<endl;
	else
	{
		cout<<"Singly Linked List values : "<<endl;
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
   SinglyLinkedList<int> l1,l2,l3;
   node<int>*temp;
   int choice,d,x;
   char ch='y';
   do
	{
	    cout<<"---------Main Menu---------"<<endl;
		cout<<"1.Insert At Beg"<<endl;
		cout<<"2.Insert At End"<<endl;
		cout<<"3.Insert After Node"<<endl;
		cout<<"4.Insert Before Node"<<endl;
		cout<<"5.Remove Beginning"<<endl;
		cout<<"6.Remove Last"<<endl;
		cout<<"7.Remove Node"<<endl;
		cout<<"8.Search a node"<<endl;
		cout<<"9.Count the no of nodes"<<endl;
		cout<<"10.Reverse the list"<<endl;
		cout<<"11.Concatenate two list "<<endl;
		cout<<"12.Display"<<endl;
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
			    
			case 4: cout<<"Enter the data of new node you want to insert before ith node "<<endl;
 	                cin>>d;
 	                l1.insertBeforeNode(d);
			        l1.display();
			        break;
			    
		    case 5: if(l1.isempty())
	                {
		             cout<<"Singly Linked List Already Empty . Can't Delete "<<endl;
	                }
		            else
		            {
		             l1.removeBeg();
		             l1.display();
		            }
		            break;
		            
		    case 6: if(l1.isempty())
	                {
		             cout<<"Singly Linked List Already Empty . Can't Delete "<<endl;
	                }
			      else
		           {
		            l1.removeLast();
		            l1.display();
		           	}
		            break;
		            
		    case 7: if(l1.isempty())
	                {
		             cout<<"Singly Linked List Already Empty . Can't    Delete "<<endl;
	                }
		            l1.removeNode();
		            l1.display();
		            break;
		               
		    case 8:  cout<<"Enter data of node to be searched "<<endl;
		             cin>>x;
			         temp=l1.search(x);
			         if(temp!=NULL)
			            cout<<"Node found having data "<<temp->data<<endl;
			         else
			            cout<<"Node not Found "<<endl;
		             break;
		            
		    case 9:   l1.count();
			          break;		
					
			case 10:  l1.reverse();
		              l1.display();
		              break;
					
			case 11:  l3=l1+l2;
			          l3.display();
			          break;
			            
			case 12:  l1.display();
				      break;
			
			default :cout<<"Error in input ";
							    	
	      }
cout<<"\nDo you want to continue ";
cin>>ch;
}while(ch=='y');
}
	

