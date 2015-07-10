import java.io.BufferedReader;
import java.io.InputStreamReader;


 class Main {

	 static int[]song;

	 static int[][][]memo;
	 static int n ;
	 static int m;
	 static int t;
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[]in = br.readLine().split(" ");
		int cases = Integer.parseInt(in[0]);
		while(cases!=0)
		{
			br.readLine();
			in = br.readLine().split(" ");
			
			 n = Integer.parseInt(in[0]);
			 t = Integer.parseInt(in[1]);
			 m = Integer.parseInt(in[2]);
			memo = new int[n+1][m+1][t+1];
			for(int i = 0;i<n+1;i++)
			{
				for(int j = 0;j<m+1;j++)
				{
					for(int k = 0;k<t+1;k++)
					{
						memo[i][j][k] = -1;
					}
				}
			}
			in = br.readLine().split(", ");
			
			song = new int[n];
			
			for(int i = 0;i<n;i++)
			{
				song[i] = Integer.parseInt(in[i]);
			}
			
			System.out.println(songCount(0,0,0));
			if(cases!=1)
				System.out.println();
			cases--;
			
			
		}
		br.close();

	}

	public static int songCount(int whichSong,int whichCD,int fa7lo)
	{
			
		if(whichSong==n)
		{
			return 0;
		}
		if(memo[whichSong][whichCD][fa7lo]!=-1)
			return memo[whichSong][whichCD][fa7lo];
		int max = 0;
		memo[whichSong][whichCD][fa7lo]= max = Math.max(max,songCount(whichSong+1,whichCD,fa7lo));
	
	if(fa7lo+song[whichSong]<=t ){
			memo[whichSong][whichCD][fa7lo]= max =  Math.max(max,1+songCount(whichSong+1,whichCD,fa7lo+song[whichSong]));
	}
	if(whichCD+1<m && fa7lo+song[whichSong]>t){
		memo[whichSong][whichCD][fa7lo] = max = Math.max(1+songCount(whichSong+1,whichCD+1,song[whichSong]), max);
	}
	return memo[whichSong][whichCD][fa7lo] = max;
		
	}
}
