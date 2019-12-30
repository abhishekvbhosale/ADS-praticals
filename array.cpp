#include <iostream>
#define MAX 50
using namespace std;
class Array
{
		int arr[MAX];
		int n;
	public :
		Array()
		{
			n=5;
			//arr=new int[n];
			int b[n]={129,30,80,60,10};
			for(int i=0;i<n;i++)
			    arr[i]=b[i];
			
		}
		void set_arr()
		{
			cout<<"\nEnter the number of elements in the array--\t";
			cin>>n;
			cout<<"\nEnter the elements of the array--\n";
			for(int i=0;i<n;i++)
				cin>>arr[i];
			cout<<endl;
		}
		void show_arr()
		{
			//cout<<"\nThe Size of the array--\t";
			//cout<<n<<endl;
			cout<<"\nElements in the array--\n";
			for(int i=0;i<n;i++)
				cout<<arr[i]<<"\t";
			cout<<endl;
		}
		void reheapdown(int i)
		{
		    while(i+2<n)
		    {
			    int l=2*i+1;
			    int r=2*i+2;
				    if(arr[l]<arr[r] && r<n)
				    {
				            l=r;
				        if(arr[i]<arr[l])
				        {
				          //  cout<<arr[l]<<endl;
				            //cout<<arr[i]<<endl;
				            int t;
				            t=arr[i];
				            arr[i]=arr[l];
				            arr[l]=t;
				            //cout<<"1"<<endl;
				        }
				        else
				            break;
				    }
				    else if(arr[l]>arr[r] && r<n)
				    {
				        if(arr[i]<arr[l])
				        {
				           // cout<<arr[l]<<endl;
				           // cout<<arr[i]<<endl;
				            int t;
				            t=arr[i];
				            arr[i]=arr[l];
				            arr[l]=t;
				            //cout<<"2"<<endl;
				        }
				        else
				            break;
				    } 
				    i=l;
				    show_arr();
		    }
		}
		void heap_sort()
		{
		    for(int i=(n-1)/2;i>=0;i--)
		        reheapdown(i);
		    int n1=n--;
		    show_arr();
		    do
		    {
		        int t;
		        t=arr[n];
		        arr[n]=arr[0];
		        arr[0]=t;
		        reheapdown(0);
		        n--;
		        //cout<<"3"<<endl;
		        show_arr();
		    }while(n>1);
		    n=n1;
		}
};
int main()
{
	Array a;
	//a.set_arr();
	a.show_arr();
	a.heap_sort();
	a.show_arr();
	return 0;
}
