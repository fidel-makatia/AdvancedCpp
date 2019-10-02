#include <iostream>
#include <string>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class stack{
	private:
		int top;
		int arr[5];
	public:
		stack()
		{
			top=-1;
			for(int i=0;i<5;i++)
			{
				arr[i]=0;
			}
		}
		bool isEmpty()
		{
			if(top==-1)
			  return true;
			else
			 return false;
		}
		bool isFull()
		{
			if(top==4)
			  return true;
			else
			  return false;
		}
		void push(int val)
		{
			if(isFull())
			{
				cout<<"stack overflow"<<endl;
			}
			else
			{
				top++;
				arr[top]=val;
			}
		}
		
		int pop()
		{
			if(isEmpty())
			{
				cout<<"stack underflow"<<endl;
			}
			else
			{
				int popValue=arr[top];
				arr[top]=0;
				top--;
				return popValue;
			}
		}
		int count()
		{
			return(top+1);
		}
		
		int peek(int pos)
		{
			if(isEmpty())
			{
				cout<<"Stack Underflow"<<endl;
			}
			else
			{
				return arr[pos];
			}
		}
		void change(int pos, int val)
		{
			arr[pos]=val;
			cout<<"value changed at position: "<<pos<<endl;
		}
		void display()
		{
			cout<<"Values in the stack are: "<<endl;
			for(int i=4;i>=0;i--)
			{
				cout<<arr[i]<<endl;
			}
		}
};

int main() {
	
	stack s1;
	int position,option,value;
	do
	{
		cout<<"what operation do you wanna perfom? \nenter 0 to exit"<<endl;
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. isFull()"<<endl;
		cout<<"5. Peek"<<endl;
		cout<<"6. count"<<endl;
		cout<<"7. change()"<<endl;
		cout<<"8. diplay()"<<endl;
		cout<<"9. clear screen"<<endl;
		cin>>option;
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"enter value to push"<<endl;
				cin>>value;
				s1.push(value);
				break;
			case 2:
				cout<<"Poping from stack"<<endl;
				value=s1.pop();
				cout<<"value poped is"<<value<<endl;
				break;
			case 3:
				if(s1.isEmpty())
				  cout<<"stack is empty"<<endl;
				else
				 cout<<"stack is not empty"<<endl;
				break;
			case 4:
				if(s1.isFull())
				  cout<<"stack is Full"<<endl;
				else
				 cout<<"stack is not Full"<<endl;
				break;
			case 5:
				cout<<"enter position to pick from"<<endl;
				cin>>position;
				value=s1.peek(position);
				cout<<"value at: "<<position<<"is "<<value<<endl;
				break;
			case 6:
				cout<<"total stack positions are"<<s1.count()<<endl;
				break;
				
			case 7:
				cout<<"Enter value and position respectively"<<endl;
				cin>>value;
				cin>>position;
				s1.change(position,value);
				break;
			case 8:
				s1.display();
				break;
			case 9:
				system("cls");
				break;
			default:
				cout<<"enter proper option"<<endl;
				
				
				
				
				
		
		}
	}while(option!=0);
	return 0;
}