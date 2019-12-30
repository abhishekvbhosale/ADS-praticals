import java.util.Scanner;

class heap{
			public static int a[]=new int[50];
			public static int n;

		heap()
		{
					
			
		}
 			public static void read(){
				Scanner s=new Scanner(System.in);
				System.out.println("\nEnter the size of array--  ");
				n=s.nextInt();
				System.out.println("\nEnter the elements of array-- ");
				for(int i=0;i<n;i++)
				{
					a[i]=s.nextInt();
				}
		 	}
			public static void display(){
            System.out.println("\n Elements of array are -- ");
				for(int i=0;i<n;i++)
				{
					System.out.print("\t"+a[i]);
				}
				
			}
			public static void reheapdown(int i,int n){
				
				while(2*i+1<=n)
				{
					int l=2*i+1;
					int r=2*i+2;
						if(a[l]<a[r] && r<n)
						{
						        l=r;
						    if(a[i]<a[l])
						    {
						        int t;
						        t=a[i];
						        a[i]=a[l];
						        a[l]=t;
						    }
						    else
						        break;
						}
						else if(a[l]>a[r] && r<n)
						{
						    if(a[i]<a[l])
						    {
						        int t;
						        t=a[i];
						        a[i]=a[l];
						        a[l]=t;
						    }
						    else
						        break;
						} 
						i=l;
						display();
				}
		} // end of rehepdown
		public static void heap_sort()
		{
		    for(int i=(n-1)/2;i>=0;i--){
		    	        reheapdown(i,n);
		    	        display();
		    }
		    
		    int n1=n;
		    n1--;
		    System.out.println("Delete root");
		    display();
		    
		    while(n1>1){
		        int t;
		        t=a[n1];
		        a[n1]=a[0];
		        a[0]=t;
		        
		        reheapdown(0,n1);
		        n1--;
		        System.out.println("\nInside dr");
		        display();
		    }
		    
			}
			public static void main(String args[])
			{
				
				
				int i;
				heap h;
				//read();
				n=8;
				int b[]=new int[]{129,30,80,60,10,22,56,69};
				for(i=0;i<n;i++)
				{	a[i]=b[i];   }
				display();
				heap_sort();
				display();
				System.out.println("\n");
			}
		}
