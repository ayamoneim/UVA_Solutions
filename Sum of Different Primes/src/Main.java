import java.io.BufferedReader;
import java.io.InputStreamReader;


 class Main {

	 static int primes[]=new int[200];
	 static boolean[]v = new boolean[1120];
	 static long[][][]memo = new long[1120+1][15][200+1];
	 static int n ,k;
	public static void main(String[] args)throws Exception {
	
	    v[0]=true;
	    v[1]=true;


	    for(int i=2;i*i<1120;i++)
	    {
	        if(!v[i])
	        {
	            for(int j=i*i;j<1120;j+=i)
	            {
	                v[j]=true;
	            }
	        }
	    }

	    int index=0;
	    for(int i=2;i<1120;i++)
	    {
	        if(!v[i])
	        {
	            primes[index++]=i;
	        }
	        if(index==200)
	        	break;
	    }
	    
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    
	    
	    String[]in = br.readLine().split(" ");
	    n = Integer.parseInt(in[0]);
	    k = Integer.parseInt(in[1]);
	    while(!(n==0 && k==0))
	    {
	    	for(int a = 0;a<1121;a++)
	    	{
	    		for(int b =0;b<15;b++)
	    		{
	    			for(int c =0;c<201;c++)
	    			{
	    				memo[a][b][c] = -1;
	    			}
	    		}
	    	}
	    	System.out.println(getCount(0,n,0));
	    	in = br.readLine().split(" ");
	    	n = Integer.parseInt(in[0]);
	    	k = Integer.parseInt(in[1]);
	    }
	    

	}
	
	public static long getCount(int i,int sum,int last)
	{
		if(sum==0 && i==k)
		{
			return 1;
		}
		if(i>=k || sum<=0 || last>=200)
		{
			return 0;
		}
		if( memo[sum][i][last]!=-1)
		{
			return memo[sum][i][last];
		}
		long count = 0;
		
		return memo[sum][i][last] = count+= getCount(i+1,sum-primes[last],last+1)+getCount(i,sum,last+1);
		
		
	}

}
