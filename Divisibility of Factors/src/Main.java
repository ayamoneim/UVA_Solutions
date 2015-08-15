import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {

	static int[] primes = new int[25];
	static int[] n_factors = new int[25];
	static int[] d_factors = new int[25];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		seive();
		while (true) {
			String[] in = br.readLine().trim().split(" ");

			int n = Integer.parseInt(in[0]);
			long d = Long.parseLong(in[1]);
			

			if (n == 0 && d == 0)
				break;
			if ((n == 0 || n==1) && (d == 1||d==-1))
				System.out.println(1);
			else {
				Arrays.fill(n_factors, 0);
				Arrays.fill(d_factors, 0);
				
				long ans = 1;

				d = (long)Math.abs(d);
				for (int i = 0; i < 25; i++) {

					int temp = n;
					if (temp / primes[i] != 0) {
						while (temp != 0) {
							n_factors[i] += temp / primes[i];
							temp /= primes[i];

						}
					} else {
						n_factors[i] = 0;

					}
					if (d % primes[i] == 0) {
						while (d % primes[i] == 0) {
							d_factors[i]++;
							d /= primes[i];
						}
					} else {
						d_factors[i] = 0;
					}
					if (d_factors[i] < n_factors[i]) {
						ans *= ((n_factors[i] - d_factors[i]) + 1);
					} else if(d_factors[i] > n_factors[i]){
						ans = 0;
					}
				}
				if(d<100)
					System.out.println(ans);
				else
					System.out.println(0);

			}
		}
	}

	public static void seive() {
		boolean[] is_prime = new boolean[100];
		Arrays.fill(is_prime, true);
		is_prime[0] = false;
		is_prime[1] = false;
		for (int i = 2; i < 100 / i; i++) {
			if (is_prime[i]) {
				for (int j = i * i; j < 100; j += i) {
					is_prime[j] = false;

				}
			}
		}
		int index = 0;
		for (int i = 0; i < 100; i++) {
			if (is_prime[i]) {
				primes[index++] = i;
			}
		}

	}

}

