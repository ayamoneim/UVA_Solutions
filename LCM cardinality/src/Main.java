import java.util.Arrays;
import java.util.Scanner;


class Main {

	static boolean[]v = new boolean[1000000+1];
	static long[]primes = new long[664580];
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		Arrays.fill(v, true);
		v[0] = v[1] = false;
		for(int i=2;i<(1000000+1)/i;i++)
		{
			if(v[i])
			{
				for(int j = i*i;j<1000000+1;j+=i)
				{
					v[j] = false;
				}
			}
		}
		int index = 0;
		for(int i = 0;i<1000000+1;i++)
		{
			if(v[i])
				primes[index++] = i;
		}
		
		long n = in.nextLong();
		while(n!=0){
		System.out.println(n+" "+getAns(n));
		n = in.nextLong();
		}
		in.close();
	}
	public static long getAns(long n)
	{
		
		long ans = 1;
        int index = 0;
        long  pf = primes[index++];
        while (n != 1 && pf * pf <= n) {
                long  power = 0;
                while (n % pf == 0) {
                        n /= pf;
                        power++;
                }
                ans *= (2*power + 1); 
                pf = primes[index++];
        }
        if (n != 1)
                ans *= 3;
        return (ans+1)/2;
	}
}
