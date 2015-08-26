import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;

public class Main {

	public static int MAX = 1000000 + 1;
	public static int PRIMES_COUNT = 78498;
	public static int[] primes = new int[PRIMES_COUNT];

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		seive();
		StringBuilder out = new StringBuilder();

		while (true) {
			int n = Integer.parseInt(br.readLine().trim());
			if (n == 0)
				break;
			int ans = 1;
			for (int i = 0; i <PRIMES_COUNT; i++) {
				if (primes[i] <= n) {
					
						
					int power = binarysearch(primes[i], n);
					if(primes[i]==5)
						power = Math.max(power-binarysearch(2, n),0);
					if(primes[i]==2)
						power =  Math.max(power-binarysearch(5, n),0);

					ans = ((ans%10 )* (powFn(primes[i], power)%10))%10;					 
				}
			}
			
			System.out.println((ans));
			

		}

	}

	public static int powFn(int base, int power) {
		if (power == 0)
			return 1;
		if (power % 2 != 0)
			return base * powFn(base, power - 1);
		int res =  powFn(base, power / 2);
		return res * res;
	}

	public static int binarysearch(int n, int x) {
		int lo = 0;
		int hi = (int) (Math.log(x) / Math.log(n));
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if (powFn(n, mid) > x) {
				hi = mid - 1;
			} else {
				lo = mid;
			}
		}
		return lo;
	}

	public static void seive() {

		boolean[] is_prime = new boolean[MAX];
		Arrays.fill(is_prime, true);

		is_prime[0] = is_prime[1] = false;
		for (int i = 2; i < MAX / i; i++) {
			if (is_prime[i]) {
				for (int j = i * i; j < MAX; j += i) {
					is_prime[j] = false;
				}
			}
		}
		int index = 0;
		for (int i = 0; i < MAX; i++) {
			if (is_prime[i])
				primes[index++] = i;
		}

	}

}
