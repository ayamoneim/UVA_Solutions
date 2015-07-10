import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Stack;

class Main {


	static int n;
	static int counter;
	static Stack<Integer> s = new Stack<Integer>();
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int t = Integer.parseInt(in[0]);
		while (t != 0) {
			in = br.readLine().split(" ");
			n = Integer.parseInt(in[0]);
			int m = Integer.parseInt(in[1]);
			LinkedList<Integer> G[] = new LinkedList[n + 1];
			LinkedList<Integer> GT[] = new LinkedList[n + 1];
			boolean[]visited=new boolean[n+1];
			int[]scc = new int[n];
			int[][]edge = new int[m][2];
			for(int i=0;i<n+1;i++)
			{
				G[i] = new LinkedList();
				GT[i] = new LinkedList();
			}
			for (int i = 0; i < m; i++) {
				in = br.readLine().split(" ");
				int from = Integer.parseInt(in[0]);
				int to = Integer.parseInt(in[1]);
				G[from - 1].add(to-1);
				GT[to - 1].add(from-1);
				edge[i][0] = from-1;
				edge[i][1] =to-1;
			}
			for (int i = 0; i < n; i++) {
				if (!visited[i])
					dfs1(i,visited, G);
			}
			Arrays.fill(visited, false);
			counter = 0;

			while (!s.isEmpty()) {
				int curr = s.pop();
				if (!visited[curr]) {
					dfs2(curr,visited , GT,scc);
					counter++;
				}
			}
			boolean[]down = new boolean[counter];
			for(int i=0;i<m;i++)
			{
				if(scc[edge[i][0]]!=scc[edge[i][1]])
				{
					down[scc[edge[i][1]]] = true;
				}
			}
			int ans = 0;
			for(int i=0;i<counter;i++)
			{
				if(!down[i])
					ans++;
			}

			System.out.println(ans);
			t--;
		}
	}

	public static void dfs1(int curr,boolean[]visited, LinkedList<Integer>[] G) {
		if (!visited[curr]) {
			visited[curr] = true;
			
			for (int i:G[curr]) {
				if (!visited[i])
					dfs1(i,visited, G);
			}
			s.push(curr);
		}
	}

	public static void dfs2(int curr, boolean[]visited, LinkedList<Integer>[] GT,int[]scc) {
		if (!visited[curr]) {
			visited[curr] = true;
			scc[curr] = counter;
			for (int i:GT[curr]) {
				if (!visited[i])
					dfs2(i,visited, GT,scc);
			}
		}
	}

}
