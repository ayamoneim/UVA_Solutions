import java.util.Scanner;


 class Main {

	static int[][]memo = new int[20+1][20+1];
	 
	 
	public static void main(String[] args) {
		
		for(int i=0;i<20+1;i++)
		{
			for(int j = 0;j<20+1;j++)
			{
				memo[i][j] = -1;
			}
		}
		
		C(20,11);
		int cases = 0;
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
		
		int n = in.nextInt();
		if(cases>0)
			System.out.println();
		System.out.println(C(2*n,n)-C(2*n,n+1));
		cases++;
		}
		in.close();

	}

	public static int C(int i,int j)
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
		return memo[i][j] = C(i-1, j-1) + C(i-1, j);
	}
}
