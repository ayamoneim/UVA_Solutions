import java.util.Arrays;
import java.util.Scanner;


 class Main {

		static boolean[]v = new boolean[1000000+1];
		static int[]primes = new int[664580];

	public static void main(String[] args) {
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
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		while(n!=0)
		{
			int counter = 0;
			for(int i = 0;i<index;i++)
			{
				if((n/2)>=primes[i] && v[n-primes[i]])
				{
					counter++;
				}
			}
			System.out.println(counter);
			n = in.nextInt();
		}
		in.close();

	}

}
