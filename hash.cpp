#include<iostream>
#include<ctype.h>
#define max 26
using namespace std;
struct CL
{
	string name;
	long int mob_no;
};

class HashTable
{
	CL c[26];
	public:
	HashTable()
	{
		for(int i=0;i<26;i++)
		{
			c[i].name="";
			c[i].mob_no=0;
		}
	}
	void Insert();
	int Hash(string);
	void Display();
	void delete_contact();
	void Linear_probing(CL);
};
int HashTable::Hash(string temp)
{
	char c=toupper(temp[0]);
	return (c-('A'+1));
}
void HashTable::Insert()
{
	CL temp;
	int n;
	cout<<"\nEnter the number of entries : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter the name : ";
		cin>>temp.name;
		cout<<"\nEnter the mobile number : ";
		cin>>temp.mob_no;
		Linear_probing(temp);
	}
}
void HashTable::Linear_probing(CL temp)
{
	
	int index;
	index=Hash(temp.name);
	if(temp.name=="")
	{
		c[index]=temp;
	}
	else
	{
		for(int i=index+1;i%max!=index;i=i%max+1)
		{
			if(c[i].name=="")
			{
				c[i]=temp;
				break;
			}
		}
	}
}
void HashTable::Display()
{
	cout<<"\n--------------------------------------------------------------------------------\n";
	cout<<"\t"<<"Sr.No"<<"\t"<<"NAME"<<"\t\t"<<"MOBILE NO"<<endl;
	cout<<"\n--------------------------------------------------------------------------------\n";
	for(int i=0;i<26;i++)
	{
		if(c[i].name!="")
			cout<<"\t"<<i+1<<"\t"<<c[i].name<<"\t\t"<<c[i].mob_no<<endl;
	}
}
void HashTable:: delete_contact()
{
	cout<<"\nEnter the name of the contact to be deleted -\t";
	string name1;
	cin>>name1;
	int i=1;
	for(i=1;i<=26;i++)
	{
		if(c[i].name==name1)
			break;
	}
	c[i].name="";
	c[i].mob_no=0;
}
int main()
{
	HashTable h;
	h.Insert();
	h.Display();
	h.delete_contact();
	h.Display();
	return 0;
}
