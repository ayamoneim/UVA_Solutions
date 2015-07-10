import java.util.Arrays;
import java.util.Scanner;


 class Main {

	static int n,m;
	static int len ;
	static int[][][]memo = new int[10+1][100+1][(1<<10)+1];;
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t!=0)
		{
			n = in.nextInt();
			m = in.nextInt();
			
			for(int i=0;i<n+1;i++)
			{
				for(int j = 0;j<m+1;j++)
				{

						for(int l = 0;l<(1<<n)+1;l++)
						{
							memo[i][j][l] = -1;
						}
					
				}
			}
			int res = 0;
			for(int j = 1;j<=m;j++){
			
				len =j;
				res = (res%1000000007+getCount(0,j,0)%1000000007)%1000000007;
			}
			System.out.println(res);
			t--;
		}

		in.close();
	}
	
	public static int getCount(int mask,int index,int last)
	{
		if((mask ==((1<<n)-1)) && index==0 ){
			return 1;
		}
		if(index<=0 ){
			return 0;
		}
		if(memo[last][index][mask]!=-1)
			return memo[last][index][mask];
		int count = 0;
		for(int i=0;i<n;i++)
		{
			if((index==len || (Math.abs(last-i)==1) && index!=len) &&!(index==len && i==0))
			{
				memo[last][index][mask] = count = (count%1000000007+getCount((mask|(1<<i)),index-1,i)%1000000007)%1000000007;
			}
		}
			
		return memo[last][index][mask] = count%1000000007;
		
	}

}
