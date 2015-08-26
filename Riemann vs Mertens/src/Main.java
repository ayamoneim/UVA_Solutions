import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;


public class Main {
	static int MAX = 1000+50;
	static int PRIMES_COUNT = 176;
	static Stack<Integer>ans = new Stack<Integer>();
	static int[]primes = new int[PRIMES_COUNT];
	static int[]mu = new int[1000000+1];
	public static void main(String[]args)throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		seive();
		mu[1] = 1;
		for(int  i = 2;i<1000000;i++){
			mu[i]= mu[i-1] + numPF(i);
		}
		while(true){
			int n = Integer.parseInt(br.readLine());
			if(n==0)
				break;
			System.out.printf("%8d%8d%8d\n",n,(mu[n]-mu[n-1]),(mu[n]));
		}
		
		
	}
	
	
	public static int numPF(int n){
		int index = 0;
		int pf = primes[index++];
		int count = 0;
		while(n!=1 && pf*pf <= n){
			if(n%pf==0){
				count++;
				n/=pf;
			}
			if(n%pf==0)
				return 0;
			pf = primes[index++];
		}
		if(n>1)
			count++;
		if(count%2==0)
			return 1;
		else 
			return -1;
		
	}
	public static void seive(){
		boolean[]is_prime = new boolean[MAX];
		Arrays.fill(is_prime,true);
		is_prime[0] = is_prime[1] = false ;
		for(int  i =2;i<MAX/i;i++){
			if(is_prime[i]){
				for(int  j = i*i;j<MAX;j+=i){
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
