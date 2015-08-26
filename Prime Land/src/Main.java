import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;

public class Main {

	static int MAX = 50000;
	static int PRIMES_COUNT = 5133;
	static Stack<Integer>ans = new Stack<Integer>();
	static int[]primes = new int[PRIMES_COUNT];
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		seive();
		while (true) {
			String[] in = br.readLine().split(" ");
			if (in.length == 1)
				break;
			long num = getNumber(in);
			num--;
			factorize(num);
			StringBuilder b = new StringBuilder();
			while(!ans.isEmpty()){
				b.append(ans.pop()+" ");
			}
			System.out.println(b.toString().trim());
			
		}

	}

	public static void factorize(long N){
		int index = 0;
		int pf = primes[index++];
		while(N!=1 && pf*pf<=N){
			int counter = 0;

			while(N%pf==0){
				N/=pf;
				counter++;
			}
			if(counter>0){
				ans.push(counter);
				ans.push(pf);
			}
			pf = primes[index++];
		}
		if(N>1){
			ans.push(1);
			ans.push((int) N);
		}
		
		
	}
	
	public static long powFn(int base,int power){
		if(power==0)
			return 1;
		if(power%2!=0)
			return base*powFn(base,power-1);
		long res = powFn(base,power/2);
		return res*res;
	}
	
	
	public static long getNumber(String[] in) {
		
		long ans = 1;
		for(int i = 0;i<in.length;i+=2){
			ans*=powFn(Integer.parseInt(in[i]),Integer.parseInt(in[i+1]));
		}
		return ans;
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
