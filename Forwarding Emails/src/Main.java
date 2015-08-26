import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {

	public static int bestNode, bestCount;
	public static int[] adj;
	public static boolean[] vis;
	public static int n, count;
	public static int[] memo;
	static int comp = 0;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder b = new StringBuilder();
		int cases = Integer.parseInt(br.readLine());
		for (int t = 1; t <= cases; t++) {
			n = Integer.parseInt(br.readLine());
			adj = new int[n+1];
			vis = new boolean[n+1];
			memo = new int[n+1];
			Arrays.fill(memo, -1);
			for (int i = 0; i < n; i++) {
				String[] in = br.readLine().split(" ");
				adj[Integer.parseInt(in[0])] = Integer.parseInt(in[1]);
			}
			bestCount = count = 0;
			for (int i = 1; i <= n; i++) {
				if (memo[i] == -1)
					dfs(i);
				if (memo[i] > bestCount) {
					bestCount = memo[i];
					bestNode = i;
				}
			}
			b.append("Case " + t + ": " + (bestNode ) + "\n");

		}
		System.out.print(b.toString());

	}

	public static int dfs(int curr) {

		vis[curr] = true;
		int ans = 0;

		if (!vis[adj[curr]] && adj[curr]!=0) {
			ans += dfs(adj[curr]) + 1;

		}

		vis[curr] = false;

		return memo[curr] = ans;

	}
}
