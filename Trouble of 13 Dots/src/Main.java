
import java.io.BufferedReader;
import java.io.InputStreamReader;


 class Main {

	 static int[][]memo;
	 static int budget;
	 static int items;
	 static int[]price;
	 static int[]value;
	public static void main(String[] args)throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[]in = br.readLine().split(" ");
		budget = Integer.parseInt(in[0]);
		items = Integer.parseInt(in[1]);
		while(true)
		{
			
			memo = new int[items+1][budget+300];
			price = new int[items];
			value = new int[items];
			for(int i = 0;i<items;i++)
			{
				in = br.readLine().split(" ");
				price[i] = Integer.parseInt(in[0]);
				value[i] = Integer.parseInt(in[1]);
			}
			for(int i=0;i<items+1;i++)
			{
				for(int j=0;j<budget+300;j++)
				{
					memo[i][j] = -1;
				}
			}
			System.out.println(getMaxVal(0,0));
			String tr = br.readLine();
			if(tr==null)
				break;
			in = tr.split(" ");
			budget = Integer.parseInt(in[0]);
			items = Integer.parseInt(in[1]);
		}
				
		br.close();

	}

	
	
	public static int getMaxVal(int index,int paid)
	{
		if(paid>budget+200 )
			return -(1<<9);
		
		if(index==value.length)
		{
			if(paid>budget && paid<=2000)
				return -(1<<9);
			return 0;				
		}
		if(memo[index][paid]!=-1)
			return memo[index][paid];
		
		return memo[index][paid] = Math.max(getMaxVal(index+1,paid), value[index] + getMaxVal(index+1,paid+price[index]));
	}
}
