import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			int n = Integer.parseInt(br.readLine());

			if (n == 0)
				break;

			LinkedList<Integer>[] adj = new LinkedList[n];
			for (int i = 0; i < n; i++)
				adj[i] = new LinkedList<Integer>();

			int[] color = new int[n];

			while (true) {
				String[] in = br.readLine().split(" ");
				int a = Integer.parseInt(in[0]);
				int b = Integer.parseInt(in[1]);

				if (a == 0 && b == 0) {
					break;
				}
				adj[a - 1].add(b - 1);
				adj[b - 1].add(a - 1);
			}

			boolean ans = false;
			for (int i = 0; i < n; i++) {
				if (color[i] == 0) {
					color[i] = 1;
					ans |= isBipartite(i, adj, color);
				}
			}
			if (!ans) {
				System.out.println("NO");
			} else {
				System.out.println("YES");
			}

		}

	}

	public static boolean isBipartite(int curr, LinkedList<Integer>[] adj,
			int[] color) {
		boolean answer = true;
		for (int i : adj[curr]) {
			if (color[i] == color[curr])
				return false;
			else if (color[i] == 0) {
				color[i] = 3 - color[curr];
				answer &= isBipartite(i, adj, color);
			}
		}
		return answer;
	}

}
