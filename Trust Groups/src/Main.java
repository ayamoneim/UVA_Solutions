import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

class Main {
	static int n, m;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] in = br.readLine().split(" ");

		n = Integer.parseInt(in[0]);
		m = Integer.parseInt(in[1]);
		while (!(n == 0 && m == 0)) {
			Map<String, Integer> person = new HashMap<String, Integer>();
			int val = 0;
			for (int i = 0; i < n; i++) {
				String name = br.readLine();
				person.put(name, val);
				val++;
			}
			boolean[] visited = new boolean[n];
			boolean[][] G = new boolean[n][n];

			boolean[][] Gt = new boolean[n][n];
			for (int i = 0; i < m; i++) {
				String from = br.readLine();
				String to = br.readLine();
				G[person.get(from)][person.get(to)] = true;
				Gt[person.get(to)][person.get(from)] = true;
			}

			Stack<Integer> s = new Stack<Integer>();

			for (int i = 0; i < n; i++) {
				if (!visited[i])
					dfs1(i, visited, G, s);
			}
			Arrays.fill(visited, false);
			int counter;
			counter = 0;
			while (!s.isEmpty()) {
				int curr = s.pop();
				if (!visited[curr]) {
					dfs2(curr, visited, Gt);
					counter++;
				}
			}
			System.out.println(counter);
			in = br.readLine().split(" ");

			n = Integer.parseInt(in[0]);
			m = Integer.parseInt(in[1]);
		}
		br.close();

	}

	public static void dfs1(int curr, boolean[] visited, boolean[][] G,
			Stack<Integer> s) {
		if (!visited[curr]) {
			visited[curr] = true;

			for (int i = 0; i < n; i++) {
				if (G[curr][i] && !visited[i])
					dfs1(i, visited, G, s);
			}
			s.push(curr);
		}
	}

	public static void dfs2(int curr, boolean[] visited, boolean[][] GT) {
		if (!visited[curr]) {
			visited[curr] = true;
			for (int i = 0; i < n; i++) {
				if (GT[curr][i] && !visited[i])
					dfs2(i, visited, GT);
			}
		}
	}

}
