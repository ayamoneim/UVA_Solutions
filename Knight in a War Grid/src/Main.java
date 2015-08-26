import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;


public class Main {

	public static class Node{
		int x;
		int y;
		public Node(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	public static boolean[][]grid ;
	public static boolean[][]vis;
	public static int n,m,r,c;
	public static int even,odd;
	public static void main(String[]args)throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(br.readLine());
		for(int t = 1;t<=cases;t++){
			String[]in = br.readLine().split("\\s+");
			r = Integer.parseInt(in[0]);
			c = Integer.parseInt(in[1]);
			m = Integer.parseInt(in[2]);
			n = Integer.parseInt(in[3]);
			grid = new boolean[r][c];
			vis = new boolean[r][c];
			even = odd = 0;
			int w = Integer.parseInt(br.readLine());
			for(int i = 0;i<w;i++){
				in = br.readLine().split(" ");
				grid[Integer.parseInt(in[0])][Integer.parseInt(in[1])] = true;
			}
			
			bfs();
			System.out.println("Case "+t+": "+even+" "+odd);
			
		}
	}
	public static void bfs() {
		Queue<Node>q = new LinkedList<Node>();
		Node src = new Node(0,0);
		q.add(src);
		vis[0][0] = true;

		while(!q.isEmpty()){
			Node curr = q.poll();
			int count = 0;
			boolean[][]counted = new boolean[r][c];
			if(curr.x+n<r && curr.y+m<c && !grid[curr.x+n][curr.y+m] && !counted[curr.x+n][curr.y+m]){
				counted[curr.x+n][curr.y+m] = true;
				count++;
				if(!vis[curr.x+n][curr.y+m]){
					vis[curr.x+n][curr.y+m] = true;
					q.add(new Node(curr.x+n,curr.y+m));
				}
				
			}
			if(curr.x-n>=0 && curr.y+m<c && !grid[curr.x-n][curr.y+m] && !counted[curr.x-n][curr.y+m]){
				counted[curr.x-n][curr.y+m] = true;
				count++;
				if(!vis[curr.x-n][curr.y+m]){
					vis[curr.x-n][curr.y+m] = true;
					q.add(new Node(curr.x-n,curr.y+m));
				}
				
			}
			if(curr.x+n<r && curr.y-m>=0 && !grid[curr.x+n][curr.y-m] && !counted[curr.x+n][curr.y-m]){
				counted[curr.x+n][curr.y-m] = true;
				count++;
				if(!vis[curr.x+n][curr.y-m]){
					vis[curr.x+n][curr.y-m] = true;
					q.add(new Node(curr.x+n,curr.y-m));
				}
				
			}
			if(curr.x-n>=0 && curr.y-m>=0 && !grid[curr.x-n][curr.y-m] && !counted[curr.x-n][curr.y-m]){
				counted[curr.x-n][curr.y-m] = true;
				count++;
				if(!vis[curr.x-n][curr.y-m]){
					vis[curr.x-n][curr.y-m] = true;
					q.add(new Node(curr.x-n,curr.y-m));
				}
				
			}
			
			if(curr.x+m<r && curr.y+n<c && !grid[curr.x+m][curr.y+n] && !counted[curr.x+m][curr.y+n]){
				counted[curr.x+m][curr.y+n] = true;
				count++;
				if(!vis[curr.x+m][curr.y+n]){
					vis[curr.x+m][curr.y+n] = true;
					q.add(new Node(curr.x+m,curr.y+n));
				}
				
			}
			if(curr.x-m>=0 && curr.y+n<c && !grid[curr.x-m][curr.y+n] && !counted[curr.x-m][curr.y+n]){
				counted[curr.x-m][curr.y+n] = true;
				count++;
				if(!vis[curr.x-m][curr.y+n]){
					vis[curr.x-m][curr.y+n] = true;
					q.add(new Node(curr.x-m,curr.y+n));
				}
				
			}
			if(curr.x+m<r && curr.y-n>=0 && !grid[curr.x+m][curr.y-n] && !counted[curr.x+m][curr.y-n]){
				counted[curr.x+m][curr.y-n] = true;
				count++;
				if(!vis[curr.x+m][curr.y-n]){
					vis[curr.x+m][curr.y-n] = true;
					q.add(new Node(curr.x+m,curr.y-n));
				}
				
			}
			if(curr.x-m>=0 && curr.y-n>=0 && !grid[curr.x-m][curr.y-n] && !counted[curr.x-m][curr.y-n]){
				counted[curr.x-m][curr.y-n] = true;
				count++;
				if(!vis[curr.x-m][curr.y-n]){
					vis[curr.x-m][curr.y-n] = true;
					q.add(new Node(curr.x-m,curr.y-n));
				}
				
			}
			if(count%2==0)
				even++;
			else
				odd++;
			
			
		}
		
		
		
	}
}
