import java.util.Scanner;


class Main {

	static int p,a;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		p = in.nextInt();
		a = in.nextInt();
		while(!(p==0 && a==0))
		{
			if(!isPrime()&& powFn(a,p)%p==a)
			{
				System.out.println("yes");
			}else
			{
				System.out.println("no");
			}
			p = in.nextInt();
			a = in.nextInt();
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
	
	public static boolean isPrime()
	{
		for(int i = 2;i<p/i;i++)
		{
			if((p%i)==0)
				return false;
		}
		return true;
	}
}
