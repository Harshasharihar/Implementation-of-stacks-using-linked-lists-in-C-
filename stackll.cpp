#include<iostream>
using namespace std;
#define null 0

class Stackl
{
	private :
			struct node
			{
				int data;
				struct node *next;
			}*top;
	
	public	:
			Stackl();
			void push(int);
			int pop();
			~Stackl();

};

Stackl::Stackl()
{
	cout<<"Inside the constructor\n";
	top = null;	
}

void Stackl::push(int num)
{
	struct node *temp;
	temp = new struct node;
	if(temp == null)
	{
		cout<<"memory allocation failed\n";
		return;
	}
	temp -> data = num;
	temp->next = top;
	top = temp;
}

int Stackl::pop()
{
	struct node *temp;
	temp = top;
	if(top == null)
	{
		cout<<"The stack is empty\n";
		exit(0);
	}
	
	int x = top->data;
	top = top->next;
	delete temp;
	return x;
}

Stackl::~Stackl()
{
	struct node *temp;
	if(top == null)
	{
		cout<<"The stack is empty\n";
		return;
	}
	while(temp!=null)
	{
	
		temp = top;
		top = top->next;
		delete temp;
	}
}

int main()
{
	int num = 0,choice  = 0;
	Stackl s;
	
	while(1)
	{
		cout<<"Enter the choice\n";
		cout<<"Enter 1 to push\n";
		cout<<"Enter 2 to pop\n";
		cout<<"Enter 3 to exit\n";
		cin>>choice;
		
		switch(choice)
		{
			case 1:cout<<"Enter the number\n";
			cin>>num;
			s.push(num);
			break;
			case 2:num = s.pop();
			cout<<"The poped data is "<<num<<endl;
			break;
			case 3:cout<<"Exiting...\n";
			exit(0);
			default :cout<<"invalid input\n";
			break;
		}
	}
}
