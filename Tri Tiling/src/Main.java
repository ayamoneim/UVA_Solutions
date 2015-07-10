import java.util.Arrays;
import java.util.Scanner;


 class Main {

	static long[] a = new long[31];
	public static void main(String[] args) {
		Arrays.fill(a, 0);
		a[0] = 1;
		a[2] = 3;
		for(int i=3;i<=30;i++)
		{
			if((i%2)==0){
				a[i] = 4*a[i-2]-a[i-4];
			}
		}
		Scanner in = new Scanner (System.in);
		
		int n = in.nextInt();
		while(n!=-1)
		{
			System.out.println(a[n]);
			n = in.nextInt();
		}
		
		
		in.close();

	}

}
