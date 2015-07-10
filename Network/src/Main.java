import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;


class Main {

	static int timer = 0;
	static int n;
	public static void main(String[] args)throws Exception {
		BufferedReader br  =new BufferedReader(new InputStreamReader(System.in));
		String[]in ;
		while(true)
		{
			in = br.readLine().split(" ");
			n = Integer.parseInt(in[0]);
			if(n==0)
				break;
			
			boolean[][]adj = new boolean[n+1][n+1];
			while(true)
			{
				in = br.readLine().split(" ");
				int from = Integer.parseInt(in[0])-1;
				if(from ==-1)
					break;
				for(int i = 1;i<in.length;i++)
				{
					
					int to = Integer.parseInt(in[i])-1;
					adj[from][to] = true;
					adj[to][from] = true;
					
				}

			}

			int[]parent = new int[n+1];
			Arrays.fill(parent, -1);
			int[]low = new int[n+1];
			int[]disc = new int[n+1];
			int counter = 0;
			boolean[]art = new boolean[n+1];
			boolean[]visited = new boolean[n+1];
			for(int i=0;i<n;i++)
			{
				if(!visited[i])
					dfs(i,parent,visited,disc,low,adj,art);
			}
			for(int i = 0;i<n;i++)
			{
				if(art[i]){
					counter++;
				}
			}
			timer = 0;
			System.out.println(counter);

		}
		br.close();

	}
	public static void dfs(int curr,int[]parent,boolean[]visited,int[]disc,int[]low,boolean[][]adj,boolean[]art)
	{
		int children = 0;
		visited[curr] = true;
		disc[curr] = low[curr] = ++timer;
		for(int i=0;i<n;i++)
		{
			if(adj[curr][i]){
			if( !visited[i])
			{
				children++;
				parent[i] = curr;
				dfs(i,parent,visited,disc,low,adj,art);
				low[curr] = Math.min(low[curr], low[i]);
				if(parent[curr]==-1 && children>1)
				{
					art[curr] = true;
					
				}
				if(parent[curr]!=-1 && low[i]>=disc[curr])
				{	
					art[curr] = true;
				}
			}else if(i!=parent[curr])
				{
					low[curr] = Math.min(low[curr],disc[i]);
				}
			}
		}
	
	}

}
