import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class Main {

	
	public static void main(String[]args)throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while(true){
			String in = br.readLine();
			if(in==null)
				break;
			BigInteger ans = BigInteger.ONE;
			int n = Integer.parseInt(in);
			for(int i = 1;i<=n;i++){
				ans = ans.multiply(new BigInteger(""+i));
			}
			System.out.println(n+"!");
			System.out.println(ans.toString());
		}
		
		
	}
}
