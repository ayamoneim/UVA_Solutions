import java.io.BufferedReader;
import java.io.InputStreamReader;


class Main {

	static int[]circular = {2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,197,199,311,337,373,719,733,919,971,991,1193,1931,3119,3779,7793,7937,9311,9377,11939,19391,19937,37199,39119,71993,91193,93719,93911,99371,193939,199933,319993,331999,391939,393919,919393,933199,939193,939391,993319,999331};

public static void main(String[] args)throws Exception {
	
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String[]in = br.readLine().split(" ");
	
	 int a = Integer.parseInt(in[0]);
	while(a!=-1)
	{
		int b = Integer.parseInt(in[1]);
		int counter = 0;
		
		for(int i =0;i<55;i++)
		{
			if(circular[i]>=a && circular[i]<=b)
			{
				
				counter++;
			}
		}

		if(counter==0)
		{
			System.out.println("No Circular Primes.");
		}else if(counter==1)
		{
			System.out.println(counter+" Circular Prime.");	
		}else 
		{
			System.out.println(counter+" Circular Primes.");
		}
		in = br.readLine().split(" ");
		a = Integer.parseInt(in[0]);
	}
	
	
	br.close();
	
}

}
