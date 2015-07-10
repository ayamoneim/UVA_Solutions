import java.util.Scanner;


class Main {

	static int p;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int b,m;
		while(in.hasNext()){
		b = in.nextInt();
		m = in.nextInt();
		p = in.nextInt();
		
		System.out.println(powFn(b,m));
		
		}
		
		
		in.close();

	}
	public static long powFn(int base,int power)
	{
		if(power==0)
			return 1;
		if((power%2)!=0)
		{
			return ((base)%p*(powFn(base,power-1)%p))%p;
		}
		long res = powFn(base,power/2);
		return ((res%p)*(res%p))%p;
	}

}
