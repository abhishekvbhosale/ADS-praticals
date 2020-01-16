#include <iostream> 
#include <string.h>
#include "Stack.h"
using namespace std;
struct node
{
    node* left;
    char data;
    node* right;
};
class Exp_tree
{
    public :
            node* root;
            Exp_tree()
            {
                root=NULL;
            }
            void insert(char post[])
            {
            	int i=0;
            	Stack<node*> s;
            	while(post[i]!='\0')
            	{
		            node* curr;
		            curr=new node;
		            curr->data=post[i];
		            curr->left=curr->right=NULL;
			       if(post[i]>='a' && post[i]<='z')
			        	s.push(curr);
			        else
			        {
			        	node* temp1=s.pop();
			        	node* temp2=s.pop();
			        	curr->left=temp2;
			        	curr->right=temp1;
			        	s.push(curr);
			        }
	            	i++;
                }
                root=s.pop();
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
		 void swap(node* root)
		{
			if(root!=NULL)
			{
				swap(root->left);
				swap(root->right);
				node* temp=root->left;
				root->left=root->right;
				root->right=temp;
			}
		}
};
int main()
{
	char post[20];
	cout<<"\nEnter the Expression---\n\t";
	cin>>post;
	Exp_tree t1;
	t1.insert(post);
	cout<<"\nInorder is--"<<endl;
	t1.inorder(t1.root);
	cout<<endl;
	cout<<"preorder is--"<<endl;
	t1.preorder(t1.root);
	cout<<endl;
	cout<<"Postorder is--"<<endl;
	t1.postorder(t1.root);
	cout<<endl;
	t1.swap(t1.root);
	cout<<"\nInorder is--"<<endl;
	t1.inorder(t1.root);
	cout<<endl;
	cout<<"preorder is--"<<endl;
	t1.preorder(t1.root);
	cout<<endl;
	cout<<"postorder is--"<<endl;
	t1.postorder(t1.root);
	cout<<endl;
	return 0;
}
