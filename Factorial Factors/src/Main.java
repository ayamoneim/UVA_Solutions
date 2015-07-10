import java.util.Arrays;
import java.util.Scanner;


 class Main {

		static boolean[]v = new boolean[10000000+1];
		static int[]primes = new int[664580];

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
		long[]counter = new long[1000000+1];
		for(int i=2;i<=1000000;i++)
		{
			counter[i] = counter[i-1]+numDiv(i);
		}
		Scanner in = new Scanner(System.in);
		
		while(in.hasNext())
		{
			int n = in.nextInt();
			System.out.println(counter[n]);
		}
		in.close();
	}
	

	public static long numDiv(int N) { 
         long ans = 0;
        int index = 0;
        int  pf = primes[index++];
        while (N != 1 && pf * pf <= N) {
                long  power = 0;
                while (N % pf == 0) {
                        N /= pf;
                        power++;
                }
                ans +=power; 
                pf = primes[index++];
        }
        if (N != 1)
                ans+=1; 
        return ans;
}
	
}