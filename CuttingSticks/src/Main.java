import java.io.BufferedReader;
import java.io.InputStreamReader;


class Main {

	static long[][]memo ;
	
	public static void main(String[] args)throws Exception {
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		String[]in = br.readLine().split(" ");
		int l = Integer.parseInt(in[0]);
		while(l!=0)
		{
			in = br.readLine().split(" ");
			int n = Integer.parseInt(in[0]);
			memo = new long[n+2][n+2];
			for(int i = 0;i<n+2;i++)
			{
				for(int j = 0;j<n+2;j++)
				{
					memo[i][j] = -1;
				}
			}
			int[]cuts = new int[n+2];
			int i;
			in = br.readLine().split(" ");
			cuts[0] = 0;
			for(i=1;i<=n;i++)
			{
				
				cuts[i] = Integer.parseInt(in[i-1]);
				
			}
			cuts[i] = l;
			
			System.out.println("The minimum cutting is "+getCost(0,n+1,cuts)+".");
			in = br.readLine().split(" ");
			l = Integer.parseInt(in[0]);
		}
		br.close();

	}

	public static long getCost(int l,int r,int[]cuts)
	{
		if(l-r+1==0)
			return 0;
		if(memo[l][r]!=-1)
		{
			return memo[l][r];
		}
		long cost = 1<<30;
		for(int i=l+1;i<r;i++)
		{
			 cost = Math.min(cost, cuts[r]-cuts[l]+getCost(l,i,cuts)+getCost(i,r,cuts));
		}
		return memo[l][r] = cost;
	}
	
}
