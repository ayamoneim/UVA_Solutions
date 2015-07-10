import java.util.Arrays;
import java.util.Scanner;


 class Main {
		static boolean[]v = new boolean[10000000+1];
		static long[]primes = new long[664580];

	public static void main(String[] args) {
		Arrays.fill(v, true);
		v[0] = v[1] = false;
		for(int i=2;i<(10000000+1)/i;i++)
		{
			if(v[i])
			{
				for(int j = i*i;j<10000000+1;j+=i)
				{
					v[j] = false;
				}
			}
		}
		int index = 0;
		for(int i = 0;i<10000000+1;i++)
		{
			if(v[i])
				primes[index++] = i;
		}
		Scanner in = new Scanner(System.in);
		long x = in.nextLong();
		while(x!=0)
		{
			boolean isNegative = false;
			if(x<0)
			{
				x*=-1;
				isNegative = true;
			}
			if(isPrime(x)){
				System.out.println("1");
		}else{
			long ans = getAns(x);
			if(isNegative )
			{
				while((ans%2)==0)
				{
					ans/=2;
				}
			}
				System.out.println(ans);
			}
			x = in.nextLong();
		}
		
		in.close();

	}
	public static long getAns(long n)
	{
		
        int index = 0;
        long pf = primes[index++];
        long g = 0;
        while (n != 1 && pf * pf <= n) {
               int power = 0;
                while (n % pf == 0) {
                        n /= pf;
                        power++;
                }
                if(power>0){
                 g = gcd(g,power);
                }
                pf = primes[index++];
        }
        if (n != 1){
                g = gcd(g,1);
        }
        return g;
	}
	
	
	public static long gcd(long a,long b)
	{
	    if(b==0)
	    {
	        return a;
	    }
	    return gcd(b,a%b);
	    
	}
	public static boolean isPrime(long x)
	{
		for(int i = 2;i<=x/i;i++)
		{
			if((x%i)==0)
				return false;
		}
		return true;
	}

}
