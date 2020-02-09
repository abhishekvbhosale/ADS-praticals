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
				Stack<node*> s2;
				node* temp, * curr;
				temp = root;
				do
				{
					while (temp != NULL)
					{
						s1.push(temp);
						temp = temp->left;
					}
					if (!s1.isEmpty())
					{
						temp = s1.pop();
						s2.push(temp);
						temp = temp->right;
					}
					else
						break;
				} while (1);
				while (!s2.isEmpty())
				{
					curr = s2.pop();
					cout << curr->word << "\t";
				}
			}
			node* findmin(node* root)
			{
				if(root==NULL || root->left==NULL)
					return root;
				findmin(root->left);
			}
			node* Delete(node* root,char key[])
			{
				if(root==NULL)
					return root;
				if(strcmp(key,root->word)<0)
					root->left=Delete(root->left,key);
				else if(strcmp(key,root->word)>0)
					root->right=Delete(root->right,key);
				else
				{
					if(root->left==NULL && root->right==NULL)
					{
						delete root;
						root=NULL;
					}
					else if(root->right==NULL)
					{
						node* temp=root;
						root=root->left;
						delete temp;
					}
					else if(root->left==NULL)
					{
						node* temp=root;
						root=root->right;
						delete temp;
					}
					else
					{
						node* temp=findmin(root->right);
						strcpy(root->word,temp->word);
						strcpy(root->meaning,temp->meaning);
						root->right=Delete(root->right,root->word);
					}
				}
				return root;
			}

};
int main()
{
	Binary_tree t1;
	int ch;
	int exit=1;
	char key[10];
	do{
			cout<<"\nEnter your choice for --\n\t1.Insert\n\t2.Display\n\t3.Delete\n\t4.Ascending\n\t5.Descending";
			cout<<"\n\t6.Edit\n\t7.Exit\n\t\t--";
			cin>>ch;
			switch(ch)
			{
				case 1 :
						t1.insert();
						break;
				case 2 :
						t1.display();
						break;
				case 3 :
						cout<<"\nEnter the vale to be deleted--\t"<<endl;
						cin>>key;
						t1.Delete(t1.root,key);
						break;
				case 4 :
						t1.inorder(t1.root);
						break;
				case 5 :
						t1.descending(t1.root);
						break;
				case 6 :
						t1.edit();
						break;
				case 7 :
						exit=0;
			}
	}while(exit);
	cout<<endl;
	return 0;
}
