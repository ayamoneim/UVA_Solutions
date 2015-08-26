import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

	public static int n;
	public static ArrayList<Integer>[] adj;

	public static boolean[] vis1;
	public static boolean[] vis2;

	public static HashSet<Integer> reachable_1 = new HashSet<Integer>();
	public static HashSet<Integer> reachable_2 = new HashSet<Integer>();

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(br.readLine());
		for (int t = 1; t <= cases; t++) {
			n = Integer.parseInt(br.readLine());
			adj = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<Integer>();

			}

			vis1 = new boolean[n];

			vis2 = new boolean[n];

			Arrays.fill(vis1, false);
			Arrays.fill(vis2, false);

			for (int j = 0; j < n; j++) {
				String[] line = br.readLine().split("\\s+");
				for (int i = 0; i < n; i++) {
					if (line[i].equals("1")) {
						adj[j].add((Integer) i);
					}
				}
			}
			StringBuilder b = new StringBuilder();
			boolean[][] ans = new boolean[n][n];

			dfs1(0);
			for (int j = 0; j < n; j++) {
				dfs2(0, j);
				for (int k = 0; k < n; k++) {
					if (reachable_1.contains(k) && !reachable_2.contains(k)
							&& j != k) {
						ans[j][k] = true;
					}
				}
				reachable_2.clear();
				Arrays.fill(vis2, false);

			}
			for (int j = 0; j < n; j++) {
				if (reachable_1.contains(j)) {
					ans[j][j] = true;
				} else {
					ans[j][j] = false;
				}
			}
			reachable_1.clear();
			b.append("Case " + t + ":\n");
			for (int i = 0; i < n; i++) {
				b.append("+");
				for (int j = 1; j < 2 * n; j++) {
					b.append("-");

				}
				b.append("+\n");
				b.append("|");
				for (int j = 0; j < n; j++) {
					if (ans[i][j]) {
						b.append("Y|");
					} else {
						b.append("N|");

					}

				}
				b.append("\n");
			}
			b.append("+");
			for (int j = 1; j < 2 * n; j++) {
				b.append("-");

			}
			b.append("+\n");
			System.out.print(b.toString());

		}

	}

	private static void dfs2(int curr, int removed) {

		if (curr != removed) {
			reachable_2.add(curr);

			vis2[curr] = true;
			for (int i : adj[curr]) {
				if (!vis2[i])
					dfs2(i, removed);
			}
		}

	}

	private static void dfs1(int curr) {
		reachable_1.add(curr);
		vis1[curr] = true;
		for (int i : adj[curr]) {
			if (!vis1[i])
				dfs1(i);
		}

	}

}
