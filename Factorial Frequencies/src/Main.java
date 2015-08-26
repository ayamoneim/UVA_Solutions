import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

import javax.print.DocFlavor.STRING;

public class Main {

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			int n = Integer.parseInt(br.readLine());
			if (n == 0)
				break;
			BigInteger ans = new BigInteger("1");
			for (int i = 1; i <= n; i++) {
				ans = ans.multiply(new BigInteger("" + i));
			}
			char[] n_factorial = ans.toString().toCharArray();
			System.out.println("" + n + "! --");

			for (int i = 0; i <= 9; i++) {
				int count = 0;
				for (int j = 0; j < n_factorial.length; j++) {
					if (n_factorial[j] - '0' == i) {
						count++;

					}
				}

				System.out.print("   (" + i + ")    " + count);
				if (i != 4 && i != 9)
					System.out.print("    ");
				else
					System.out.println();

			}

		}

	}
}
