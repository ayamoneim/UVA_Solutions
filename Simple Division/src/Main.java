import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main {

	static int gcd(int a, int b){
		return b==0?a:gcd(b,a%b);
	}
	
	public static void main(String[]args)throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while(true){
		String[]in = br.readLine().split(" ");
		if(in.length==1)
			break;
		int ans = 0;
		
		for(int i = 1;i<in.length-1;i++){
			ans = gcd(Integer.parseInt(in[i])-Integer.parseInt(in[0]),ans);
		}
		System.out.println((int)Math.abs(ans));
		}
		
	}
	
}
