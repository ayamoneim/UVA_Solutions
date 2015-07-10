import java.util.Scanner;


class Main {

	static int n,m;
	static long[][]memo;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		m = in.nextInt();
		while(!(n==0 && m==0))
		{
			memo = new long[n+1][m+1];
			for(int i = 0;i<n+1;i++)
			{
				for(int j = 0;j<m+1;j++)
				{
					memo[i][j] = -1;
				}
			}
			System.out.println(n+" things taken "+m+" at a time is "+c(n,m)+" exactly.");
			n = in.nextInt();
			m = in.nextInt();
		}
		in.close();

	}

	public static long c(int i,int j)
	{

		if(i>=0 &&j==0)
		{
			return 1;
		}
		if(i<=0 || j<=0 || j>i)
		{
			return 0;
		}
		if(memo[i][j]!=-1)
			return memo[i][j];
		return memo[i][j] = c(i-1, j-1) + c(i-1, j);
	}
}
