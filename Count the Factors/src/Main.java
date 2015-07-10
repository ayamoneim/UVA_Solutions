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
	Scanner in = new Scanner(System.in);
	int n = in.nextInt();
	while(n!=0)
	{
		System.out.println(n+" : "+numDiffPF(n));
		n = in.nextInt();
	}
	in.close();
	

	}

	public static int numDiffPF(int N) { 
        int counter = 0;
        int index = 0;
        int pf = primes[index++];
        while (N != 1 && pf * pf <= N) {
                if (N % pf == 0)
                        counter++;
                while (N % pf == 0)
                        N /= pf;
                pf = primes[index++];
        }
        if (N != 1)
                counter++;
        return counter;
}
}
