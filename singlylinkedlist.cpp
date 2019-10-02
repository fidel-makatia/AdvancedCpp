#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Node{
	public:
		int key;
		int data;
		Node * next;
		Node(){
			key=0;
			data=0;
			next=NULL;
		}
		Node(int k,int d){
			key=k;
			data=d;
		}
};

class Singlylinkedlist{
	public:
		Node *head;
		Singlylinkedlist(){
			head=NULL;
		}
		Singlylinkedlist(Node *n){
			head=n;
		}
		
		
		// check if node exists using key value
		Node * NodeExist(int k){
			Node* temp=NULL;
			Node *ptr= head;
			while(ptr!=NULL)
			{
				if(ptr->key==k)
				{
					temp=ptr;
				}
				ptr=ptr->next;
			}
			
			return temp;
		}
		
		//appending a node
		void appendNode(Node* n)
		{
			if(NodeExist(n->key)!=NULL)
			{
				cout<<"Node already exists with key value: "<<n->key<<"append a node with a different Key value"<<endl;
			}
			else{
				if(head==NULL){
					head=n;
					cout<<"Node Appended"<<endl;
				}
				else{
						Node *ptr= head;
			while(ptr->next!=NULL)
			{
			
				ptr=ptr->next;
			}
			
			ptr->next=n;
			cout<<"Node Appended"<<endl;
			
				}
			}
		}
		
		//prepend a node- attach  node at the start
		void prependNode(Node* n)
		{
		 if(NodeExist(n->key)!=NULL)
			{
				cout<<"Node already exists with key value: "<<n->key<<"append a node with a different Key value"<<endl;
			}
		else
		{
			n->next=head;
			head=n;
			cout<<"Node prepended"<<endl;
		}
		}
		void insertNodeAfter(int k,Node *n)
		{
			Node* ptr=NodeExist(k);
			if(ptr==NULL)
			{
				cout<<"No node exists with key value"<<k<<endl;
			}
			else
			{
				if(NodeExist(n->key)!=NULL)
				{
						cout<<"Node already exists with key value"<<n->key<<". Append another node with different Key Value"<<endl;
						
				}
				else
				{
					n->next=ptr->next;
					ptr->next=n;
					cout<<"Node Inserted"<<endl;
				
				}
			}
		}
		//delete node  by unique key
		void deleteNodeByKey(int k)
		{
			if(head==NULL)
			{
				cout<<"Singly linked list already empty"<<endl;
			}
			else if(head!=NULL)
			{
				if(head->key==k)
				{
					head=head->next;
					cout<<"Node Unlinked with key value: "<<k<<endl;
				}
				else
				{
					 Node* temp=NULL;
					 Node* prevptr=head;
					 Node* currentptr=head->next;
					 while(currentptr!=NULL)
					 {
					 	if(currentptr->key==k)
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
					 	cout<<"Node Unlinked with key value: "<<k<<endl;
					 	
					 }
					 else
					 {
					 	cout<<"Node Doesn't exist with key value: "<<k<<endl;
					 }
					
				}
			}
		}
		// update node
		void updateNodeByKey(int k, int d)
		{
			Node* ptr=NodeExist(k);
			if(ptr!=NULL)
			{
				ptr->data=d;
				cout<<"Node data updated successfully"<<endl;
			}
			else
			{
				cout<<"Node doesn't exist with key value: "<<k<<endl;
			}
		}
		//print list
		void printList()
		{
			if(head==NULL)
			{
				cout<<"No Nodes in the Linked List"<<endl;
			}
			else
			{
				cout<<"The list has the following values: "<<endl;
				Node* temp=head;
				
				while(temp!=NULL)
				{
					cout<<"("<<temp->key<<","<<temp->data<<")--->";
					temp=temp->next;
				}
			}
		}
};

int main() {
	Singlylinkedlist s;
	int options;
	int key1,k1,data1;
	do
	{
		cout<<"\n What operation do you wanna perfom? Select Option number.ENter 0 to exit"<<endl;
		cout<<"1. Append Node"<<endl;
		cout<<"2. Prepend Node"<<endl;
		cout<<"3. insert Node"<<endl;
		cout<<"4. Delete Node"<<endl;
		cout<<"5. Update Node"<<endl;
		cout<<"6. Print"<<endl;
		cout<<"7. Clear screen"<<endl;
		
		
		cin>>options;
		Node* n1=new Node();
		switch(options)
		{
			case 0:
				break;
			case 1:
				cout<<"Append Node Operation \n Enter key & data of the Node to be appended"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.appendNode(n1);
				//cout<<n1.key<<"="<<n1.data<<endl;
				break;
			case 2:
				cout<<"Prepend Node Operation \n Enter Key & data of the Node to be Prepended"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.prependNode(n1);
				break;
			case 3:
				cout<<"Insert Node after operation \n Enter key of existing Node after which insertion should occur: "<<endl;
				cin>>k1;
				cout<<" Enter key & data of the new Node"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.insertNodeAfter(k1,n1);
				break;
			case 4:
				cout<<" Delete Node By Key Operation.\n Enter key of the Node to be deleted: "<<endl;
				cin>>k1;
				s.deleteNodeByKey(k1);
				break;
			case 5:
				cout<<"Update Node By Key Operation. \nEnter key & new data to be updated"<<endl;
				cin>>key1;
				cin>>data1;
				s.updateNodeByKey(key1,data1);
				break;
			case 6:
				s.printList();
				break;
			case 7:
				system("cls");
				break;
			default:
				cout<<"Enter proper Option Number"<<endl;
				
			
		}
	}while(options!=0);
	
	
	return 0;
}