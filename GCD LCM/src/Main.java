import java.util.Scanner;


class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int t = in.nextInt();
		while(t!=0)
		{
			int g = in.nextInt();
			int l = in.nextInt();
			
			if(l%g==0)
			{
				System.out.println(g+" "+l);
			}else
			{
				System.out.println("-1");
			}
			t--;
		}
		
		
		in.close();

	}

}
