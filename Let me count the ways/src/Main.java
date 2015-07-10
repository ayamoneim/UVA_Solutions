import java.util.Scanner;


class Main {

	static int cents;
	static int[]change = {1,5,10,25,50};
	static long[][]memo;
	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
		memo = new long[30000+500][6];
		for(int i=0;i<30000+500;i++)
		{
			for(int j=0;j<6;j++)
			{
				memo[i][j] = -1;
			}
		}
		getCount(1000,0);
		getCount(2000,0);
		getCount(5000,0);
		getCount(10000,0);
		getCount(20000,0);
		getCount(30000,0);
		while(in.hasNext()){
			cents = in.nextInt();
			if(memo[cents][0]>1){
			System.out.println("There are "+getCount(cents,0)+" ways to produce "+cents+" cents change.");
			}else{
				System.out.println("There is only "+getCount(cents,0)+" way to produce "+cents+" cents change.");
			}
			}
		in.close();

	}
	
	public static long getCount(int sum,int last)
	{
		if(sum==0 )
			return 1;
		if(sum<0 )
		{
			return 0;
		}
		if(last==change.length)
		{
			return 0;
		}
		if(memo[sum][last]!=-1)
		{
			return memo[sum][last];
		}
		
		long ways = 0;
		memo[sum][last] = ways+=getCount(sum-change[last],last);
		memo[sum][last] = ways+=getCount(sum,last+1);
		return memo[sum][last] = ways;
	}

}
