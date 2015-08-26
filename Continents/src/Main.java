import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
	
	public static int n,m,currX,currY,counter;
	public static boolean[][]vis;
	public static char land;
	public static char[][]grid;
	public static void main(String[]args)throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		while(true){
			String s = br.readLine();
			if(s==null)
				break;
			String[]in = s.split(" ");
			m = Integer.parseInt(in[0]);
			n = Integer.parseInt(in[1]);
			grid = new char[m][n];
			for(int i = 0;i<m;i++){
				grid[i] = br.readLine().toCharArray();
			}
			in = br.readLine().split(" ");
			vis = new boolean[m][n];
			currX = Integer.parseInt(in[0]);
			currY = Integer.parseInt(in[1]);
			land = grid[currX][currY];
			
			counter = 0;
			dfs(currX,currY);
			int ans = 0;

			counter = 0;
			for(int i = 0;i<m;i++){
				for(int j = 0;j<n;j++){
					if(!vis[i][j] && grid[i][j]==land){
						dfs(i,j);
						if(counter>ans)
							ans = counter;
						counter = 0;
					}
				}
			}
			
			System.out.println(ans);
			br.readLine();

		}
		
	}
	
	public static void dfs(int x,int y){
		
		if(y>=n)
			y = 0;
		
		if(y<0)
			y = n-1;
		if(x>=m || x<0 || grid[x][y]!=land || vis[x][y])
			return;
		vis[x][y] = true;
		counter++;
		
		dfs(x-1,y);
		dfs(x+1,y);
		dfs(x,y-1);
		dfs(x,y+1);
	
	}

}