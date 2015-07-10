import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;


class Main {

	static boolean[]v = new boolean[5000000+1];
	static int[]primes = new int[664580];
	
public static void main(String[] args)throws Exception{
	Arrays.fill(v, true);
	v[0] = v[1] = false;
	int[]sums = new int[5000000+1];
	int[]parent = new int[5000000+1];
	for(int i=2;i<(5000000+1)/i;i++)
	{
		if(v[i])
		{
			parent[i] = i;
			for(int j = i+i;j<5000000+1;j+=i)
			{
				v[j] = false;
			if(j/i < parent[j]){
				parent[j/i] = i;
			}else
			{
				parent[j] = i;
			}
				
			}
		}
	}

	for(int i =0;i<5000000+1;i++)
	{
		if(v[i] && parent[i]==0)
		{
			parent[i] = i;
		}
	}
	for(int i=2;i<5000000+1;i++)
	{
		int last = parent[i];
		sums[i]+=last;
		int num = i;
		while(num!=0 && parent[num]!=0)
		{
			num /= parent[num];
			if(last!=parent[num])
			{
				last = parent[num];
				sums[i]+=last;
			}
		}
	}
	int count = 0;
	int counter[] = new int[5000000+1];
	for(int i=2;i<5000000+1;i++)
	{
		if(v[sums[i]])
		{
			count++;
		}
		counter[i] = count;
	}
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		String[]in = br.readLine().split(" ");
		int a = Integer.parseInt(in[0]);
		while(a!=0)
		{
			int b =Integer.parseInt(in[1]);

			System.out.println(counter[b]-counter[a-1]);
			in = br.readLine().split(" ");
			a = Integer.parseInt(in[0]);
			
		}
		br.close();

	}



}
