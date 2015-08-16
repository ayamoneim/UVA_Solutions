import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;


class Main {

	static class Cell{
		int from;
		int to;
		int t;
		
		public Cell(int x,int y,int z)
		{
			this.from = x;
			this.to = y;
			this.t = z;
		}
	}
	
	public static boolean negative_cycle(int s, int t,Cell[]adj,int n,int[]dist){
		for(int i = 0;i<t;i++){
					for(Cell e:adj){
						if(dist[e.from] + e.t < dist[e.to])
							dist[e.to]=dist[e.from]+e.t;
					}
		}
		
		for(Cell e:adj){
			if(dist[e.from] + e.t < dist[e.to])
						return true;
			}
			
		return false;
		}
	
	public static void main(String[]args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(br.readLine());
		
		for(int out = 0; out<cases; out++)
		{
			String[]one = br.readLine().split(" ");
			
			int n = Integer.parseInt(one[0]);
			int m = Integer.parseInt(one[1]);
			
			Cell[]adj = new Cell[m];
			
			for(int row = 0 ; row<m ; row++)
			{
				String[]two = br.readLine().split(" ");
				
				int from = Integer.parseInt(two[0]);
				int to = Integer.parseInt(two[1]);
				int weight = Integer.parseInt(two[2]);
				
				if(adj[row]==null)
				{
					adj[row] = new Cell(from,to,weight);
				}
				
				
			}
			
			int[]dist = new int[n];
			Arrays.fill(dist, 1<<30);
			
			if(negative_cycle(0,n-1,adj,m,dist))
			{
				System.out.println("possible");
			}else
			{
				System.out.println("not possible");
			}
			
		}
		
		br.close();
	}
	
	
	
}
