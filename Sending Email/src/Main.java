import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;


class Main {

	static class Node{
		int currNode;
		int dis;
		public Node(int x,int y)
		{
			this.currNode = x;
			this.dis = y;
		}
	}
	
	static class Cell{
		int to;
		int t;
		
		public Cell(int x,int y)
		{
			this.to = x;
			this.t = y;
		}
	}
	static class IntCompare implements Comparator<Node> {

			public int compare(Node o1, Node o2) {
			
				if(o1.dis>o2.dis)
				{
					return 1;
				}else if(o1.dis<o2.dis)
				{
					return -1;
				}
				return 0;
			}

	}
	
	public static void main(String[] args)throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int cases = 0;
		for(int i = 0;i<N;i++)
		{
			cases++;
			
			String[]arr = br.readLine().split(" ");
			int n = Integer.parseInt(arr[0]);
			int m = Integer.parseInt(arr[1]);
			Node s =new Node( Integer.parseInt(arr[2]),0);

			Node T = new Node(Integer.parseInt(arr[3]),1<<30);
			
			

			LinkedList<Cell>[]adj = new LinkedList[n];
			
			for(int k = 0;k<m;k++)
			{
				String[]input = br.readLine().split(" ");
				
				int x = Integer.parseInt(input[0]);
				int y = Integer.parseInt(input[1]);
				int t = Integer.parseInt(input[2]);
				
				if(adj[x] == null)
				{
					adj[x] = new LinkedList<Cell>();
				}
				if(adj[y] == null)
				{
					adj[y] = new LinkedList<Cell>();
				}
				adj[x].add(new Cell(y,t));
				adj[y].add(new Cell(x,t));
			}
			
			Comparator<Node> comp = new IntCompare();
			PriorityQueue<Node>q = new PriorityQueue<Node>(n,comp);
			boolean[]v = new boolean[n];
			
			int[]dist = new int[n];
			Arrays.fill(dist,1<<30);
			
			q.add(s);
			dist[s.currNode]=0;
			
			while(!q.isEmpty()){
			
				int curr = q.peek().currNode;
				q.poll();
				if(curr == T.currNode)
				{
					break;
				}
				if(!v[curr])
				{
					v[curr] = true;
					
					if(adj[curr]!=null)
					{
					for(Cell j:adj[curr])
					{
						if( dist[curr] + j.t < dist[j.to])
						{
							dist[j.to] =	dist[curr] + j.t ;
							q.add(new Node(j.to,dist[j.to]));
						}
					}
					
					}
				
				}
			
		}
			
		if(dist[T.currNode]!=1<<30)
		{
			System.out.println("Case #"+cases+": "+dist[T.currNode]);

		}else 
		{
			System.out.println("Case #"+cases+": unreachable");
		}
		}
		br.close();
		
	}
}
