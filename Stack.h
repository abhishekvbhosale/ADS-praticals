#include <iostream>
using namespace std;
#define MAX 50
template <class T>
class Stack
{
		int top;
		T arr[MAX];
	public :
		Stack()
		{
			top=-1;
		}
		int isFull()
		{
			return top==MAX-1;
		}
		int isEmpty()
		{
			return top==-1;
		}
		void push(T ele)
		{
			if(!isFull())
				arr[++top]=ele;
		}
		T pop()
		{
			if(!isEmpty())
				return	arr[top--];
		}
};
