import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	public static int MAX = 2000000 + 10;
	public static int PRIMES_COUNT = 148935;
	public static int[] primes = new int[PRIMES_COUNT];
	public static long[] phi = new long[MAX];
	public static int[] memo = new int[MAX];

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		seive();

		phi[2] = 1;
		memo[2] = eulerPhi(2);
		memo[1] = 0;
		Arrays.fill(memo, -1);
		for (int i = 3; i <= MAX - 10; i++) {
			int current = i;
			phi[i] = phi[i - 1];
			while (current != 1) {

				if (memo[current] != -1) {
					current = memo[current];
				} else {
					memo[current] = current = eulerPhi(current);
				}

				phi[i]++;

			}
		}

		int cases = Integer.parseInt(br.readLine());
		for (int i = 1; i <= cases; i++) {
			String[] in = br.readLine().split("\\s+");
			int m = Integer.parseInt(in[0]);
			int n = Integer.parseInt(in[1]);
			if (m <= 2) {
				System.out.println(phi[n]);
			} else {
				System.out.println(phi[n] - phi[m-1]);
			}
		}

	}

	public static int eulerPhi(int n) {
		int index = 0;
		int pf = primes[index++];
		int ans = n;
		while (n != 1 && pf * pf <= n) {
			if (n % pf == 0)
				ans -= (ans / pf);
			while (n % pf == 0) {
				n /= pf;
			}
			pf = primes[index++];
		}
		if (n > 1)
			ans -= (ans / n);
		return ans;
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
