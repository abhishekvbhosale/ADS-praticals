#include <iostream>
#include <string.h>
using namespace std;
class node
{
		int v;
		string city;
		float distance;
		node* next;
		friend class Graph;
};
class Graph
{
		node* head[10];
		string city1[6];
		
	public :
		Graph()
		{
			city1[1]="Nashik";city1[2]="Nagpur";city1[3]="Delhi";city1[4]="Pune";city1[5]="Mumbai";
			for(int i=1;i<=5;i++)
			{
				head[i]=new node;
				head[i]->v=i;
				head[i]->city=city1[i];
				head[i]->distance=0;
				head[i]->next=NULL;
			}
		}
		
		void create()
		{
			node *curr,*temp;
			int x;
			for(int i=1;i<=5;i++)
			{
				temp=head[i];
				cout<<"\nHow many cities are connected to "<<city1[i]<<": ";
				cin>>x;
				for(int j=1;j<=x;j++)
				{
					curr=new node;
					cout<<"\nEnter City Number: ";
					cin>>curr->v;
					curr->city=city1[curr->v];
					cout<<"\nEnter Distance between Cities: ";
					cin>>curr->distance;
					curr->next=NULL;
					temp->next=curr;
					temp=curr;
				}
			}
		} 
		void display()
		{
			node *temp;
			for(int i=1;i<=5;i++)
			{
				temp=head[i];
				while(temp!=NULL)
				{
					cout<<temp->v<<" "<<temp->city<<" "<<temp->distance<<"\t";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
};

int main()
{
	Graph g;
	g.create();
	g.display();
	return 0;
}
