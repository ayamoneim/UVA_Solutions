import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;


 class Main {

	static int n;
	static int timer = 0;
	static int counter = 0;
	
	public static class link{
		int from;
		int to;
	}
	static class IntCompare implements Comparator<link> {

		public int compare(link o1, link o2) {
		
			if(o1.from>o2.from )
			{
				return 1;
			}else if(o1.from<o2.from )
			{
				return -1;
			}else if(o1.from==o2.from && o1.to>o2.to)
			{
				return 1;
			}else if(o1.from==o2.from && o1.to<o2.to)
			{
				return -1;
			}
			return 0;
		}

}
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[]in;
		int cases = 0;
		while(true)
		{
			String s ="";
			if(cases!=0)
				 s= br.readLine();
			if(s==null)
				break;
			cases++;
			String in1 = br.readLine();
			if(in1==null)
				break;
			in = in1.split(" ");
			n = Integer.parseInt(in[0]);
			if(n==0){
				System.out.println("0 critical links");
			}else{
			boolean[][]adj = new boolean[n+1][n+1];
			for(int i=0;i<n;i++)
			{
				in = br.readLine().split(" ");
				int from = Integer.parseInt(in[0]);
				for(int j=2;j<in.length;j++)
				{
					int to = Integer.parseInt(in[j]);
					adj[from][to] = true;
					adj[to][from] = true;
					
				}
			}
			int[]parent = new int[n+1];
			Arrays.fill(parent, -1);
			int[]low = new int[n+1];
			int[]disc = new int[n+1];
			boolean[]art = new boolean[n+1];
			boolean[]visited = new boolean[n+1];
			Comparator<link>comp = new IntCompare();
			PriorityQueue<link> q = new PriorityQueue<link>(n,comp);
			for(int i=0;i<n;i++)
			{
				if(!visited[i])
					dfs(i,parent,visited,disc,low,adj,art,q);
			}
			
			System.out.println(counter+" critical links");
			while(!q.isEmpty())
			{
				link c = q.poll();
				System.out.println(c.from+" - "+c.to);
			}
			counter = 0;
			timer = 0;
			}
			System.out.println();
			
		}
	}
	public static void dfs(int curr,int[]parent,boolean[]visited,int[]disc,int[]low,boolean[][]adj,boolean[]art,PriorityQueue<link>q)
	{
		visited[curr] = true;
		disc[curr] = low[curr] = ++timer;
		for(int i=0;i<n;i++)
		{
			if(adj[curr][i]){
			if( !visited[i])
			{
				parent[i] = curr;
				dfs(i,parent,visited,disc,low,adj,art,q);
				low[curr] = Math.min(low[curr], low[i]);
				if(low[i]>disc[curr])
				{
					counter++;
					link a = new link();
					if(curr<i){
					a.from = curr;
					a.to = i;
					}else
					{
						a.to = curr;
						a.from = i;
					}
					q.add(a);
				}
			}else if(i!=parent[curr])
				{
					low[curr] = Math.min(low[curr],disc[i]);
				}
			}
		}
	
	}

}
