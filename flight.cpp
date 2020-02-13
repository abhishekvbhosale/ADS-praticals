#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
class node
{
		int v;
		string city;
		float distance;
		float fuel;
		node* next;
		friend class Graph;
};
//end of node
class Graph
{
		node* head[10];
		string city1[6];
		
		
	public :
		int visited[6];
		Graph(int x)
		{
			city1[1]="Nashik";city1[2]="Nagpur";city1[3]="Delhi";city1[4]="Pune";city1[5]="Mumbai";
			for(int i=1;i<=5;i++)
			{
				head[i]=new node;
				head[i]->v=i;
				head[i]->city=city1[i];
				head[i]->distance=0;
				head[i]->fuel=0;
				head[i]->next=NULL;
			}
		}
		//end of graph constructor
		void create()
		{
			node *curr,*temp;
			int x;
			ifstream fin("flight_input.txt");
			for(int i=1;i<=5;i++)
			{
				
				temp=head[i];
				cout<<"\nHow many cities are connected to "<<city1[i]<<": ";
				fin>>x;
				for(int j=1;j<=x;j++)
				{
					curr=new node;
					cout<<"\nEnter City Number: \n";
					for(int i=1;i<6;i++)
						cout<<i<<"."<<city1[i]<<"\t";
					cout<<"\n\t--";
					fin>>curr->v;
					if(curr->v==i)
					{
						while(curr->v==i)
						{
							cout<<"\nEnter a valid city number--\t";
							fin>>curr->v;
						}
					}
					curr->city=city1[curr->v];
					cout<<"\nEnter Distance between Cities: ";
					fin>>curr->distance;
					curr->next=NULL;
					temp->next=curr;
					temp=curr;
				}
			}
		}
		//end of create function 
		void display()
		{
			node *temp;
			for(int i=1;i<=5;i++)
			{
				temp=head[i]->next;
				cout<<head[i]->v<<"  "<<head[i]->city<<"\t";
				while(temp!=NULL)
				{
					cout<<temp->city<<" "<<temp->distance<<"\t";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
		//end of display function
		void avaliable()
		{
			for(int i=1;i<6;i++)
				cout<<i<<"."<<city1[i]<<"\t";
			cout<<"\nEnter from which city --\t";
			int x;
			cin>>x;
			cout<<"\nEnter till which city--\t";
			int y;
			cin>>y;
			node* temp;
			temp=head[x];
			int flag=0;
			while(temp!=NULL)
			{
				if(temp->v==y)
				{
					flag=1;
					break;
				}
				temp=temp->next;
			}
			if(flag)
			{
				cout<<"\nFlight Found\n";
			}
			else
				cout<<"\nNo Flight Found\n";
		}
		//end of avaliable function
		void DFS(int v)
		{
			visited[v]=1;
			cout<<v<<"\t";
			node* temp;
			temp=head[v];
			while(temp!=NULL)
			{
				
				if(visited[temp->v]==0)
					DFS(temp->v);
				temp=temp->next;
			}
		}
		//end of DFS function
};
//end of Graph class
int main()
{
	Graph g;
	int t;
	int ch;
	int Exit=1;
	do
	{
		cout<<"\t1.Create\n\t2.Display\n\t3.Flights Avaliable\n\t4.DFS\n\t5.Exit\n\t--  ";
		cin>>ch;
		switch(ch)
		{
			case 1 :
					g.create();
					cout<<endl;
					break;
			case 2 :
					g.display();
					cout<<endl;
					break;
			case 3 :
					g.avaliable();
					cout<<endl;
					break;
			case 4:
					for(int i=1;i<=5;i++)
						g.visited[i]=0;
					cout<<"Enter vertex for DFS(1 to 5)\t";
					cin>>t;
					g.DFS(t);
					cout<<endl;
					break;
			case 5:
					Exit=0;
		}
	}while(Exit);
	return 0;
}
