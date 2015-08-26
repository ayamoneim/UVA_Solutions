import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main {
	public static int n;
	public static boolean[][]vis;
	public static char[][]grid;

	public static void main(String[]args)throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int t = 1;t<=cases;t++){
			
			n = Integer.parseInt(br.readLine());
			grid = new char[n][n];
			for(int i = 0;i<n;i++)
				grid[i] = br.readLine().toCharArray();
			vis = new boolean[n][n];
			int ans = 0;
			for(int i = 0;i<n;i++)
			{
				for(int j = 0;j<n;j++){
					if(grid[i][j]=='x' && !vis[i][j])
					{
						dfs(i,j);
						ans++;
					}
				}
			}
			
			
			System.out.println("Case "+t+": "+ans);
		}
		
	}
	
	public static void dfs(int x,int y){
		if(x<0 || x>=n || y<0 || y>=n || vis[x][y]|| grid[x][y]=='.')
			return;
		vis[x][y] = true;
		dfs(x+1,y);
		dfs(x-1,y);
		dfs(x,y+1);
		dfs(x,y-1);
		
		dfs(x+1,y+1);
		dfs(x-1,y-1);
		dfs(x-1,y+1);
		dfs(x+1,y-1);

	}
	
}
