import java.util.Scanner;


 class Main {

	static int k,n;
	static long[][][]dp = new long[101][66][66];
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		int cases = 0;
		while(t!=0)
		{
			n = in.nextInt();
			k = in.nextInt();
			cases++;
			for(int i =0;i<k+1;i++)
			{
				for(int j=0;j<n+1;j++)
				{
					for(int l = 0;l<n+1;l++)
					{
							dp[i][j][l] = -1;
					}
				}
			}
			if(k==0)
			{
				System.out.println("Case "+cases+": "+"0");
			}else{
			System.out.println("Case "+cases+": "+getCount(0,0,0,0));
			}
			t--;
		}
		
		in.close();

	}

	public static long getCount(long mask,long index,int ones,int mod)
	{
		if(ones==n-ones && mod==0 && index==n)
	    {
	        return 1;
	    }
	    if(index==n)
	    {
	        return 0;
	    }
	    if(dp[mod][(int)index][ones]!= -1)
	        return dp[mod][(int)index][ones] ;
	    long  counter = 0;
	    if(index==n-1){
	         counter+=getCount((mask|(1L<<index)),index+1,ones+1,(int)((mask|(1L<<index))%k));
	         dp[mod][(int)index][ones] = counter;
	    }
	    else{
	         counter+=getCount((mask|(1L<<index)),index+1,ones+1,(int)((mask|(1L<<index))%k))+getCount(mask,index+1,ones,(int)(mask%k));
	        dp[mod][(int)index][ones] = counter;
	    }

	    return dp[mod][(int)index][ones] = counter;
	}
}
