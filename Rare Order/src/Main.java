import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;


 class Main {

	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		boolean[][]adj = new boolean[27][27];
		boolean[]v = new boolean[27];
		boolean[]exist = new boolean[27];
		Stack<Integer>s = new Stack<Integer>();
		String last = br.readLine();
		while(true)
		{
			String curr = br.readLine();
			if(curr.matches("#"))
				break;
			for(int i=0;i<Math.min(last.length(),curr.length());i++){
				if(curr.charAt(i)!=last.charAt(i)){
					adj[last.charAt(i)-'A'][curr.charAt(i)-'A'] = true;
					exist[last.charAt(i)-'A'] = true;
					exist[curr.charAt(i)-'A'] = true;
					break;
			}
			}
			last = curr;
		
		}
		
		for(int i = 0;i<27;i++)
		{
			if(exist[i])
			{
				if(!v[i])
				{
					topSort(i,v,s,adj);
				}
			}
		}
		while(!s.isEmpty())
		{
			char c = (char) (s.pop()+'A');
			System.out.print(c);
		}
		System.out.println();
		br.close();
		
	}

	public static void topSort(int curr,boolean[]v,Stack<Integer>s,boolean[][]adj){
		if(!v[curr])
		{
			v[curr] = true;
			for(int i=0;i<27;i++){
				if(adj[curr][i]){
					if(!v[i]){
						topSort(i,v,s,adj);
					}
				}
			}
		}
		s.push(curr);
	}
}
