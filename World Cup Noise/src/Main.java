import java.util.Scanner;


class Main {


	static int n;
	static long[][]dp;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		int cases = 0;
		while(t!=0){
		n = in.nextInt();
		dp = new long[n+1][3];
		for(int i=0;i<n+1;i++)
		{
			for(int j=0;j<3;j++)
			{
				dp[i][j] = -1;
			}
		}
		cases++;
		System.out.println("Scenario #"+cases+ ":\n"+getCount(0,2));
		System.out.println();
		t--;
		}
		in.close();

	}

	public static long getCount(int index,int last)
	{
		if(index==n)
		{
			return 1;
		}
		if(dp[index][last] !=-1)
		{
			return dp[index][last] ;
		}
		long ways = 0;
		if(last==0)
		{
			dp[index][last] =ways+=getCount(index+1,0)+getCount(index+1,1);
		}else if(last==1)
		{
			dp[index][last] =ways+=getCount(index+1,0);
		}else
		{
			dp[index][last] =ways+=getCount(index+1,0)+getCount(index+1,1);
		}
		return dp[index][last] = ways;
	}
}
