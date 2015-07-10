import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class Main {
	static int N;
	public static class Node{
		boolean[][]v = new boolean[N+1][N+1];

	}
	static long[][]dp = new long[N+2][N+2];
	public static void main(String[] args)throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = null;
		try {
			in = br.readLine().split(" " );
		} catch (IOException e1) {
			return;
		}
		int T = Integer.parseInt(in[0]);

		int cases = 0;
		while(T!=0)
		{
			try {
				in = br.readLine().split(" ");
			} catch (IOException e) {
				return;
			}
			 N = Integer.parseInt(in[0]);

			for(int i=0;i<N+2;i++)
			{
				for(int j=0;j<N+2;j++)
				{
					if(i==j)
					{
						dp[i][j] = 0;
					}else{
						System.out.println(i+" "+j);
						dp[i][j] = Long.MAX_VALUE;
					}
					
				}
			}
			
			
			for(int i =0;i<N-1;i++)
			{
				try {
					in = br.readLine().split(" ");
				} catch (IOException e) {
					return;
				}

				int count = 0;
				for(int j = i+1;j<N;j++)
				{
					int cost = Integer.parseInt(in[count++]);
					if(cost!=-1){
						 dp[i][j] = cost;
						 dp[j][i] = cost;
					}
				}	
			}
			try {
				in = br.readLine().split(" ");
			} catch (IOException e) {
				return;
			}

			int P = Integer.parseInt(in[0]);
			int rankList[] = new int[P+1];
			try {
				in = br.readLine().split(" ");
			} catch (IOException e) {
				return;
			}

			for(int i=0;i<P;i++)
			{
				rankList[i] = Integer.parseInt(in[i])-1;
			}
			
			try {
				in = br.readLine().split(" ");
			} catch (IOException e) {
				return;
			}
			
			int q = Integer.parseInt(in[0]);
			Node[]query = new Node[q+1];
			for(int i=0;i<q;i++)
			{
				try {
					in = br.readLine().split(" ");
				} catch (IOException e) {
					return;
				}
				
				int n = Integer.parseInt(in[0]);
				query[n] = new Node();
				query[n].v[Integer.parseInt(in[1])-1][Integer.parseInt(in[2])-1] = true;
				
				
				
			}
			cases++;
			System.out.print("Case "+cases+": ");
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
				{
					
					if(query[0].v[i][j] && dp[i][j]!=Long.MAX_VALUE)
					{
						System.out.print(dp[i][j]);
						q--;
						if(q!=0)
							System.out.print(" ");
					}else if(query[0].v[i][j] && dp[i][j]==Long.MAX_VALUE)
					{
						System.out.print("-1");
						q--;
						if(q!=0)
							System.out.print(" ");
					}
				}
			}
			for(int k = 0;k<P;k++)
			{
				for(int i=0;i<N;i++)
				{
					for(int j=0;j<N;j++)
					{
						if(dp[i][rankList[k]]!=Long.MAX_VALUE && dp[rankList[k]][j]!=Long.MAX_VALUE)
							dp[i][j] = Math.min(dp[i][j],dp[i][rankList[k]]+dp[rankList[k]][j]); 
						if(query[k].v[i][j] && dp[i][j]!=Long.MAX_VALUE)
						{
							System.out.print(dp[i][j]);
							q--;
							if(q!=0)
								System.out.print(" ");
						}else if(query[k].v[i][j] && dp[i][j]==Long.MAX_VALUE)
						{
							System.out.print("-1");
							q--;
							if(q!=0)
								System.out.print(" ");
						}
					}
				}
				

				if(q==0)
					break;
				
			}

			System.out.println();
			T--;
		}
	}

}
