#include <iostream>
#include <string.h>
#include "Stack.h"
using namespace std;
struct node
{
    node* left;
    char word[10];
    char meaning[50];
    node* right;
};
class Binary_tree
{
    public :
            node* root;
            Binary_tree()
            {
                root=NULL;
            }
            void insert()
            {
                node* curr;
                char ch;
                do{
		            curr=new node;
		            cout<<"\nEnter the word  --\t";
		            cin>>curr->word;
		            cout<<"\nEnter its meaning  --\t";
		            cin.ignore();
		            cin.getline(curr->meaning,50);
		            curr->left=curr->right=NULL;
		            if(root==NULL)
		            {
		                root=curr;
		            }
		            else
		            {
		                node* temp;
		                temp=root;
		                while(1)
		                {
		                    if(strcmp(curr->word,temp->word)<0)
		                    {
		                        if(temp->left==NULL)
		                        {
		                            temp->left=curr;
		                            break;
		                        }
		                        else
		                            temp=temp->left;
		                    }
		                    else if(strcmp(curr->word,temp->word)>0)
		                    {
		                        if(temp->right==NULL)
		                        {
		                            temp->right=curr;
		                            break;
		                        }
		                        else
		                            temp=temp->right;
		                    }
		                }
		            }
		            cout<<"\nDo you want to add more ?--\t";
		            cin>>ch;
                }while(ch=='y' || ch=='Y');
            }
            node* search(char key[],node* temp)  
            {
                if(temp==NULL)
                        return 0;
                else if(strcmp(key,temp->word)<0)
                {
                    temp=temp->left;
                    search(key,temp);
                }
                else if(strcmp(key,temp->word)>0)
                {
                    temp=temp->right;
                    search(key,temp);
                }
                else if(strcmp(key,temp->word)==0)
                    return temp;
            }
            void edit()
            {
            	node* edit1;
            	cout<<"\nEnter the word to be edited--\t";
            	char key[10];
            	cin>>key;
            	edit1= search(key,root);
            	if(edit1==0)
            	{
            		cout<<"\nNo word found\n";
            		return ;
            	}
            	else
            	{
            		cout<<"\nEdit the word---\n\t";
            		cin>>edit1->word;
            		cout<<"\nEdit the meaning of the word---\n\t";
            		cin.ignore();
            		cin.getline(edit1->meaning,50);
            		cout<<endl;
            	}
            }
            void display()
            {
            	node* disp1;
            	cout<<"\nEnter the word to find its meaning--\t";
            	char key[10];
            	cin>>key;
            	disp1= search(key,root);
            	if(disp1==0)
            	{
            		cout<<"\nNo word found\n";
            		return ;
            	}
            	else
            	{
            		cout<<"\nThe meaning of the word is--\n\t";
            		cout<<disp1->meaning;
            		cout<<endl;
            	}
            }
            void inorder(node* root)   //ascending
		    {
		    	if(root!=NULL)
		    	{
		    		inorder(root->left);
		    		cout<<root->word<<"\t";
		    		inorder(root->right);
		    	}
		    }
		    void descending(node* root) //descending
			{
				Stack<node*> s1;
				
			}
			/*node* Delete(char key[])
			{
				node* del1=search(key,root);
				if(del1==0)
					cout<<"\nNo such word"<<endl;
				else
				{
					if(del1->left==NULL && del2->right==NULL)
					{
						
					}	
				}
			}*/
};
int main()
{
	Binary_tree t1;
	t1.insert();
	t1.inorder(t1.root);
	cout<<endl;
	//t1.edit();
	//t1.display();
	t1.postorder(t1.root);
	cout<<endl;
	return 0;
}
