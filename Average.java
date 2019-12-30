import java.util.Scanner;

class Average{
			public static void main(String args[])
			{
				Scanner s=new Scanner(System.in);
				int a[]=new int[50];
				int n,i,sum=0,avg=0;
				System.out.println("\nEnter the size of array--  ");
				n=s.nextInt();
				System.out.println("\nEnter the elements of array-- ");
				for(i=0;i<n;i++)
				{
					a[i]=s.nextInt();
					sum=sum+a[i];
				}
				avg=sum/n;
				System.out.println("\n Elements of array are -- ");
				for(i=0;i<n;i++)
				{
					System.out.println(+a[i]);
				}
				System.out.println("\n Sum of array :"+sum);
				System.out.println("\n Average of array :"+avg);
			}
		}
