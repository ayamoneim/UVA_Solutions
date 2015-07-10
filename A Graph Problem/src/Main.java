import java.util.Scanner;


 class Main {

	static int n;
	static int[][]memo = new int[80][4];
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		while(in.hasNext())
		{
			for(int i=0;i<80;i++)
			{
				for(int j=0;j<4;j++)
				{
					memo[i][j] = -1;
				}
			}
			n = in.nextInt();
			System.out.println(getCount(0,1));
			
		}
		
		in.close();

	}

	
	public static int getCount(int index,int zero)
	{
		if(index==n-1)
			return 1;
		if( memo[index][zero]!=-1)
		{
			return memo[index][zero];
		}
		int count = 0;
		if(zero==0)
		{
			memo[index][zero] = count+= getCount(index+1,zero+1);
		}else if(zero==1)
		{
			memo[index][zero] =count+=  getCount(index+1,zero+1)+getCount(index+1,0);
		}else if(zero==2)
		{
			memo[index][zero] =count+= getCount(index+1,0);

		}	
		return memo[index][zero]=count ;
	}
}
