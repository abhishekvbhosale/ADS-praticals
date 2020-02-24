#include <iostream>
#include <string.h>
#define max 26
using namespace std;
class dictionary
{
	string word;
    string meaning;
    friend class HashTable;
};
class HashTable
{
	dictionary c[50];
	public:
	HashTable()
	{
		for(int i=0;i<50;i++)
		{
			c[i].word="";
			c[i].meaning="";
		}
	}
	int Hash(string temp)
	{
		char c=temp[0];
		return (c-('a'));
	}
	void Insert()
	{
		dictionary temp;
		int n;
		cout<<"\nEnter the number of entries : ";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"\nEnter the word : ";
			cin>>temp.word;
			cout<<"\nEnter the meaning : ";
			cin>>temp.meaning;
			//Linear_probing(temp);
			quadratic_probing(temp);
			
		}
	}
	void Linear_probing(dictionary temp)
	{
		
		int index;
		index=Hash(temp.word);
		if(temp.word=="")
		{
			c[index]=temp;
		}
		else
		{
			for(int i=index+1;i%max!=index;i=i%max+1)
			{
				if(c[i].word=="")
				{
					c[i]=temp;
					break;
				}
			}
		}
	}
	void quadratic_probing(dictionary temp)
	{
		int index;
		index=Hash(temp.word);
		if(c[index].word=="")
		{
			c[index]=temp;
		}
		else
		{
			for(int i=1;i<50 ;i++)
			{
				
				if(c[i].word=="")
				{
					int j=(i*i)+Hash(temp.word);
					cout<<j<<endl;
					c[j]=temp;
					break;
				}
			}
		}
	}
	void Display()
	{
		cout<<"\n--------------------------------------------------------------------------------\n";
		cout<<"\t"<<"Sr.No"<<"\t"<<"WORD"<<"\t\t"<<"MEANING"<<endl;
		cout<<"\n--------------------------------------------------------------------------------\n";
		for(int i=0;i<50;i++)
		{
			if(c[i].word!="")
				cout<<"\t"<<i+1<<"\t"<<c[i].word<<"\t\t"<<c[i].meaning<<endl;
		}
	}
	void delete_word()
	{
		cout<<"\nEnter the word to be deleted -\t";
		string name1;
		cin>>name1;
		int i=1;
		for(i=0;i<26;i++)
		{
			if(c[i].word==name1)
				break;
		}
		c[i].word="";
		c[i].meaning="";
	}
};
int main()
{
	HashTable h;
	h.Insert();
	h.Display();
	h.delete_word();
	h.Display();
	return 0;
}
