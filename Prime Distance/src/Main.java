import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;


public class Main {

	static int  MAX = 50000;
	static int[]primes = new int[5133];
	static boolean[]mark = new boolean[1000000+1];
	public static void main(String[]args)throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		seive();
		while(true){
			String s = br.readLine();
			if(s==null)
				break;
			String[]in = s.split(" ");
			long l = Long.parseLong(in[0]);
			long u = Long.parseLong(in[1]);
			Arrays.fill(mark, true);
			if(l==1)
				mark[0] = false;
			for(int i = 0;i<5133;i++){
				long start;
				if(l%primes[i]==0)
					start = l;
				else
					start = l + (primes[i]-(l%primes[i]));
				if(start==primes[i])
					start = primes[i]*primes[i];
				for(long j = start;j>=l && j<=u;j+=primes[i]){
					mark[(int) (j-l)] = false;
				}
			}
			int last = -1;
			long a = 0,b = 0,c = 0,d = 0;
			int min_distance = Integer.MAX_VALUE;
			int max_distance = Integer.MIN_VALUE;
			for(int i = 0;i<u-l+1;i++){

				if(mark[i]){
					if(last==-1){
						last = i;
					}else{
						if(i-last<min_distance){
							min_distance = i - last; 
							a = l + last;
							b = l + i;
						}
						if(i-last>max_distance){
							max_distance = i - last; 
							c = l + last;
							d = l + i;
						}
					}
					last = i;

				}
			}
			if(a==0 && b==0 && c==0 && d==0)
				System.out.println("There are no adjacent primes.");
			else
				System.out.printf("%d,%d are closest, %d,%d are most distant.\n",a,b,c,d);

		}

	}
	
	public static  void seive(){

		boolean[]is_prime = new boolean[MAX];
		Arrays.fill(is_prime, true);
		is_prime[0] = is_prime[1] = false;
		for(int i = 2;i< MAX/i;i++){
			if(is_prime[i]){
				for(int j = i*i;j<MAX;j+=i){
					is_prime[j] = false;
				}
			}
		}
		int index = 0;
		for(int i = 0;i<MAX;i++){
			if(is_prime[i]){
				primes[index++] = i;
			}
		}
	}
	
}
