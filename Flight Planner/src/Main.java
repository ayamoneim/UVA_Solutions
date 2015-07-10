
import java.util.Scanner;


class Main {

	
	static int X;
	static int[][]w ;
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t!=0)
		{

			
			int x = in.nextInt();
			w = new int[10][x/100];
			long[][]memo = new long[10][x/100+1];
			for(int i=0;i<10;i++)
			{

				for(int j=0;j<x/100;j++)
				{

					memo[i][j] = -1;
					w[i][j] = in.nextInt();
//					System.out.print(w[i][j]);
				}
//				System.out.println();
			}
			
			X = x/100;
		
			System.out.println(getCost(0,memo,0));
			System.out.println();
			t--;
		}
		
		in.close();
	}
	
	
	public static long getCost(int alt,long[][]memo,int where)
	{
		if(X==where && alt==0)
			return 0;
		if(where>=X || (alt==0 && where!=0))
			return 1<<30;
		if( memo[alt][where]!=-1)
			return memo[alt][where];
		long cost = 1<<30;
		if(alt+1<=9)
		{
			cost = Math.min(cost,60-w[10-alt-1][where]+getCost(alt+1,memo,where+1));
		}
		if(alt-1>=0 )
		{
			cost = Math.min(cost,20-w[10-alt-1][where]+getCost(alt-1,memo,where+1));
		}
		cost = Math.min(cost,30-w[10-alt-1][where]+getCost(alt,memo,where+1));
		return  memo[alt][where] = cost;
	}

}
