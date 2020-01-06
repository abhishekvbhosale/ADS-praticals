#include <iostream>
using namespace std;
struct node
{
    node* left;
    int data;
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
                curr=new node;
                cout<<"\nEnter the data  --\t";
                cin>>curr->data;
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
                        if(curr->data<temp->data)
                        {
                            if(temp->left==NULL)
                            {
                                temp->left=curr;
                                break;
                            }
                            else
                                temp=temp->left;
                        }
                        else
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
            }
            void search_nonRecursive()
            {
                cout<<"\nEnter value to be searched--\t";
                int key;
                cin>>key;
                node* temp;
                temp=root;
                int flag=0;
                while(1)
                {
                    if(key==temp->data)
                    {
                        flag=1;
                        break;
                    }
                    else if(key<temp->data)
                    {
                        temp=temp->left;
                    }
                    else if(key>temp->data)
                        temp=temp->right;
                    if(temp==NULL)
                        break;
                }
                if(flag)
                    cout<<"\nElement Found!!!";
                else
                    cout<<"\nElement Not found";
            }
            int search_recursive(int key,node* temp)  //Give temp value of root before calling!!!
            {
                if(temp==NULL)
                        return 0;
                else if(key<temp->data)
                {
                    temp=temp->left;
                    search_recursive(key,temp);
                }
                else if(key>temp->data)
                {
                    temp=temp->right;
                    search_recursive(key,temp);
                }
                else if(key==temp->data)
                    return 1;
            }
        void minimum()
        {
            node* temp;
            temp=root;
            while(1)
            {
                if(temp->left==NULL)
                    break;
                else
                    temp=temp->left;
            }
            cout<<"\nThe Smallest Element is--\t"<<temp->data<<endl;
        }
        int height(node* root)
        {
            int hl,hr;
            if(root==NULL)
                return 0;
            else
            {
                hl=height(root->left)+1;
                hr=height(root->right)+1;
            }
            if(hl>hr)
                return hl;
            else
                return hr;
        }
};

int main()
{
    Binary_tree b1;
    int ch;
    int a=1;
    do{
        cout<<"\nEnter your choice---\n\t1.Create\n\t2.Non-Recursive Search\n\t3.Recursive Search\n\t4.Minimum"<<endl;
        cout<<"\n\t5.Height\n\t6.Exit\n\t---\t";
        cin>>ch;
        switch(ch)
        {
            case 1 :
                    b1.insert();
                    break;
            case 2 :
                    b1.search_nonRecursive();
                    break;
            case 3 :
                    cout<<"\nEnter key to be searched--\t";
                    int key;
                    cin>>key;
                    node* temp;
                    temp=b1.root;
                    int ans;
                    ans=b1.search_recursive(key,temp);
                    if(ans)
                    cout<<"\nElement Found!!!";
                    else
                    cout<<"\nElement Not found";
                    break;
            case 4 :
                    b1.minimum();
                    break;
            case 5 :
                    cout<<"\nThe Height is--\t"<<b1.height(b1.root)<<endl;
                    break;
            case 6 :
                    a=0;

        }
    }while(a);
    return 0;
}
