import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;


public class Main {

	
	public static long[]memo = new long[21];
	
	public static void main(String[]args)throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		int cases = Integer.parseInt(br.readLine());
		Arrays.fill(memo, -1);
		getFactorial(20);
		for(int t = 1;t<=cases;t++){
			
			char[]word = br.readLine().toCharArray();
			Arrays.sort(word);
			int count = 1;
			long ans = memo[word.length];
			System.out.println(ans);
			for(int i = 1;i<word.length;i++){
				
				if(word[i]==word[i-1])
					count++;
				else{
					ans/=memo[count];
					count = 1;
				}
			}
			ans/=memo[count];
			System.out.println("Data set "+t+": "+ans);
			
		}
		
		
	}

	public static long getFactorial(int n) {
		if(n==0)
			return 1;
		if(memo[n]!=-1)
			return memo[n];
		return memo[n] = n*getFactorial(n-1);
	}
	
}
