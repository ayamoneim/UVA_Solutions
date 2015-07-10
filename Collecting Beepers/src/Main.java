import java.util.Scanner;


 class Main {

	 static int l,w;

	 static int beepers;
	 static int[][]where;
	 static int[][]memo;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t!=0)
		{
			
			l = in.nextInt();
			w = in.nextInt();
			int startx = in.nextInt();
			int starty = in.nextInt();
			beepers = in.nextInt();
			where = new int[beepers+1][beepers+1];
			where[0][0] = startx;
			where[0][1] = starty;
			for(int i = 1;i<beepers+1;i++)
			{
				where[i][0] = in.nextInt();
				where[i][1] = in.nextInt();
			}
			memo = new int[beepers+2][1<<(beepers+1)+1];
			for(int i=0;i<beepers+2;i++)
			{
				for(int j = 0;j<(1<<(beepers+1))+1;j++)
				{
						memo[i][j] = -1;
				}
			}
			int mask = 0;
			mask = (mask|(1<<0) );
			System.out.println("The shortest path has length "+getDist(0,mask));
			
			
			t--;
		}
		
		in.close();

	}
	public static int getDist(int from,int mask)
	{
		if((mask==(1<<(beepers+1))-1))
		{
			return Math.abs(where[from][0]-where[0][0])+Math.abs(where[from][1]-where[0][1]);
		}
		if(memo[from][mask]!=-1)
		{
			return memo[from][mask];
		}
		int cost =Integer.MAX_VALUE;
		for(int i = 0;i<beepers+1;i++)
		{
			if((mask&(1<<i))==0)
			{
				memo[from][mask] = cost = Math.min(cost, Math.abs(where[from][0]-where[i][0])+Math.abs(where[from][1]-where[i][1])+getDist(i,(mask|(1<<i))));
			}
		}
		return memo[from][mask] = cost;
	}

}
