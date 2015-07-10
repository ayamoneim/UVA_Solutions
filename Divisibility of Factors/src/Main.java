import java.util.Scanner;




 class Main {
	 
static boolean divisible = true;
static int N;
static int[][]nfactors = new int[100+1][100];
static int[]dfactors;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for(int i =2;i<=100;i++)
		{
			for(int j=i;j>=2;j--){
			nFactorize(i,j);
			}
		}
		N = in.nextInt();

		long D = in.nextLong();
		while(!(N==0 && D==0))
		{
			dfactors = new int[100+1];
			if(D<0)
				D*=-1;
			if((N==0|| N==1) && D==1){
				System.out.println("1");
			}else{
			factorizeD(D);
			if(!divisible){
				System.out.println("0");
			}else 
			{
				long ans = 1;
				for(int i=0;i<100;i++)
				{
					if(dfactors[i]<=nfactors[N][i] && !(dfactors[i]==0 && nfactors[N][i]==0))
					{
						ans*=(nfactors[N][i]-dfactors[i]+1);
						
					}else if(dfactors[i]>nfactors[N][i] )
					{
						divisible = false;
						break;
					}
				}
				if(divisible){
				System.out.println(ans);
				}else
				{
					System.out.println("0");
				}
			}
			
		}
			N = in.nextInt();

			divisible = true;
			D = in.nextLong();
		}
		in.close();

	}
	
	public static void factorizeD(long D)
	{
		 while (D%2 == 0)
		    {
		    	dfactors[2]++;
		        D = D/2;
		    }
		 
		    for (int i = 3; i <= D/i; i = i+2)
		    {
		    	
		        while (D%i == 0)
		        {
		        	if(i>100)
		        	{
		        		divisible = false;
		        		return;
		        	}
		        	dfactors[i]++;
		            D = D/i;
		        }
		    }
		    if (D > 100)
		    	divisible = false;
		    else if(D>2)
		    	dfactors[(int) D]++;
		    	
		    	
		    	
	}
	public static void nFactorize(int x ,int n)
	{
		while (n%2 == 0)
	    {
	    	nfactors[x][2]++;
	        n = n/2;
	    }
	 
	    for (int i = 3; i <= n/i; i = i+2)
	    {
	    	
	        while (n%i == 0)
	        {
	        	nfactors[x][i]++;
	            n = n/i;
	        }
	    }
	    if(n>2)
	    	nfactors[x][n]++;
	}

}
