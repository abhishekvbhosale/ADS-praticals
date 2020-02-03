#include <iostream>
using namespace std;
struct node
{
    node* left;
    int data;
    int lthread,rthread;
    node* right;
};
class tbt
{
    public :
            node* root;
            node* head;
            tbt()
            {
                root=NULL;
                head=new node;
                head->left=head->right=head;
                head->lthread=head->rthread=1;
            }
            void insert()
            {
            	char ch;
            	node* curr;node* temp;
            	do
            	{
		            
		            curr=new node;
		            cout<<"\nEnter the data  --\t";
		            cin>>curr->data;
		            curr->lthread=curr->rthread=1;
		            curr->left=curr->right=head;
		             if(root==NULL)
		            {
		                root=curr;
		                head->left=root;
		                head->lthread=1;
		                
		            }
		            else
		            {
		                
		                temp=root;
				        while(1)
				        {
				        	if(curr->data < temp->data)
				        	{
				        		if(temp->lthread==1)
				        		{
						    		curr->left=temp->left;
						    		temp->left=curr;
						    		temp->lthread=0;
						    		curr->right=temp;
						    		break;
						    	}
						    	else 
						    		temp=temp->left;
				        	}
				        	else
				        	{
				        		if(temp->rthread==1)
				        		{
						    		curr->right=temp->right;
						    		temp->right=curr;
						    		temp->rthread=0;
						    		curr->left=temp;
						    		break;
						    	}
						    	else 
						    		temp=temp->right;
				        	}
				        }
				     }
				     cout<<"\nDo you want to add more??";
				     cin>>ch;
		         }while(ch=='y' || ch=='Y');
		   }
		   void preorder()
		   {
		   		node* temp;
		   		int flag=0; 
		   		temp=root;
		   		while(temp!=head)
		   		{
		   			if(flag==0)
		   				cout<<temp->data<<" ";
		   			if(temp->lthread==0 && flag==0)
		   				temp=temp->left;
		   			else
		   			{
		   				if(temp->rthread==0)
		   				{
		   					temp=temp->right;
		   					flag=0;
		   				}
		   				else
		   				{
		   					temp=temp->right;
		   					flag=1;
		   				}
		   			}
		   		}
		   }
		    void inorder()
		   {
		   		node* temp;
		   		int flag=0; 
		   		temp=root;
		   		while(temp!=head)
		   		{
		   			
		   			if(temp->lthread==0 && flag==0)
		   				temp=temp->left;
		   			else
		   			{
		   			    flag=0;
		   				if(flag==0) cout<<temp->data<<" ";
		   				if(temp->rthread==0)
		   				{
		   					temp=temp->right;
		   					flag=0;
		   				}
		   				else
		   				{
		   					temp=temp->right;
		   					flag=1;
		   				}
		   			}
		   		}
		   }//wrongggggg
};
int main()
{
tbt b1;
b1.insert();
b1.preorder();
cout<<endl<<endl;
b1.inorder();
return 0;
}
