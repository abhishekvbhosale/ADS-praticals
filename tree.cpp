#include <iostream>
#include "Stack.h"
using namespace std;
struct node
{
	node* left;
	char data;
	node* right;
};
class Tree
{
	public :
		node* root;
		node* head;
		char s;
		Tree()
		{
			root=NULL;
		}	
		void create()
		{
			node *curr,*temp;
			do{
				curr=new node;
				cout<<"\nEnter the data --\t";
				cin>>curr->data;
				curr->left=curr->right=NULL;
				if(root==NULL)
				{	
					root=curr;
					head=curr;
				}
				else
				{
				   
					temp=root;
					do{
						cout<<"\nLeft or Right node(l or r) of "<< temp->data <<" :\t";
						char opt;
						cin>>opt;
						if(opt=='l')
						{
							if(temp->left==NULL)
							{
								temp->left=curr;
								break;
							}
							else
								temp=temp->left;
						}
						else if(opt=='r')
						{
							if(temp->right==NULL)
							{
								temp->right=curr;
								break;
							}
							else
								temp=temp->right;
						}
						else
							cout<<"\nEnter correct option";
			   	}while(1); 
			   }
			   	cout<<"\nDo you want to add more(y /n)-\t";
			   	cin>>s;
					
			}while(s=='y');
		}
		void inorder(node* root)
		{
			if(root!=NULL)
			{
				inorder(root->left);
				cout<<root->data;
				inorder(root->right);
			}
		}
		void preorder(node* root)
		{
			if(root!=NULL)
			{
				cout<<root->data;
				preorder(root->left);
				preorder(root->right);
			}
		}
		void postorder(node* root)
		{
			if(root!=NULL)
			{
				preorder(root->left);
				preorder(root->right);
				cout<<root->data;
			}
		}
		void nonRecursive_inorder(node* root)
		{
			Stack<node*> s1;
			node *temp,*curr;
			temp=root;
			do
			{
				while(temp!=NULL)
				{
					s1.push(temp);
					temp=temp->left;
				}
				if(!s1.isEmpty())
				{
					temp=s1.pop();
					cout<<temp->data;
					temp=temp->right;
				}
				else
					break;
			}while(1);
		}
		void nonRecursive_preorder(node* root)
		{
			Stack<node*> s1;
			node *temp,*curr;
			temp=root;
			do
			{
				while(temp!=NULL)
				{
					cout<<temp->data;
					s1.push(temp);
					temp=temp->left;
				}
				if(!s1.isEmpty())
				{
					temp=s1.pop();
					temp=temp->right;
				}
				else
					break;
			}while(1);
		}
};
int main()
{
	Tree t1;
	int ch;
	int a=1;
	do{
			cout<<"\n1.Create\n2.Inorder\n3.Preorder\n4.Postorder\n5.Non-Recursive Inorder\n6.Non-Recursive Preorder\n7.Exit\n--\t";
			cin>>ch;
			switch(ch)
			{
				case 1:
						t1.create();
						break;
				case 2:
						cout<<"\nThe Recursive Inorder is --\n\t";
						t1.inorder(t1.head);
						break;
				case 3:
						cout<<"\nThe Recursive Preorder is --\n\t";
						t1.preorder(t1.head);
						break;
				case 4:
						cout<<"\nThe Recursive Postorder is --\n\t";
						t1.postorder(t1.head);
						break;
				case 5:
						cout<<"\nThe Non-Recursive Inorder is --\n\t";
						t1.nonRecursive_inorder(t1.head);
						break;
				case 6:
						cout<<"\nThe Non-Recursive Preorder is --\n\t";
						t1.nonRecursive_preorder(t1.head);
						break;
				case 7:
						a=0;
			}
		}while(a);
		return 0;
}
