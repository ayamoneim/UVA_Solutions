import java.util.Scanner;


public class Main {
	static long[][]memo = new long[100+2][100+2];

	static long[][]dp = new long[100+2][10+1];
	static int N;
	static int[]a = new int[10];
	public static void main(String[] args) {
		for(int i=0;i<100+1;i++)
		{
			for(int j = 0;j<100+1;j++)
			{
				memo[i][j] = -1;
				if(j<10+1){
				dp[i][j] = -1;
				}
			}
			
			
		}
		
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		
		for(int i = 0;i<10;i++)
		{
			a[i] = in.nextInt();
		}
		long ans = 0;
		for(int i=1;i<=N;i++)
		{
			ans = (ans%1000000007 + getCount(i,0)%1000000007)%1000000007;
		}
		System.out.println(ans);
		in.close();

	}

	public static long getCount(int len,int digit)
	{
		
		if(len==0 && digit==10)
			return 1;
		if(len<0 || digit==10)
			return 0;
		if(dp[len][digit]!=-1)
		{
			return dp[len][digit];
		}
		long count = 0;
		for(int i=a[digit];i<=len;i++)
		{
			if(digit!=0){
				dp[len][digit] = count=(count%1000000007+getCount(len-i,digit+1)%1000000007*C(len,i)%1000000007)%1000000007;
			}else
			{
				dp[len][digit] = count=(count%1000000007+getCount(len-i,digit+1)%1000000007*C(len-1,i)%1000000007)%1000000007;
			}
		}
		return dp[len][digit] = count;
			
	}
	public static long C(int i,int j)
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
		return memo[i][j] = (C(i-1, j-1)%1000000007 + C(i-1, j)%1000000007)%1000000007;
	}
	
}
