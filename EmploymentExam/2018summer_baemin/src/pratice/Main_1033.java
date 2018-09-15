package pratice;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

//11047
public class Main_1033 
{
	static public int Getgcd(final int a, final int b)
	{
		int max = Math.min(a,b)/2;
		int gcd=1;
		int i=1;
		while(i<max)
		{
			if(max%i==0)
				gcd = Math.max(i, gcd);
			i++;
		}
		return gcd;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		TreeSet<Integer> tree = new TreeSet<Integer>();
		final Integer size = Integer.parseInt(br.readLine());
		Integer ary[][] = new Integer[size-1][4];
		for(int i=0 ; i < size-1 ; i++)
		{
			final String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str, " ");
			for(int l=0 ; l < 4 ;l++)
			{
				Integer val = Integer.parseInt(st.nextToken());
				if(l>=2)
					tree.add(val);
				ary[i][l] = val;
			}
		}
		
		Integer treeary[] = new Integer[tree.size()];
		tree.toArray(treeary);
		
		Integer gcd=1;
		Integer lcm=1;
		for(int i=0 ; i < treeary.length-1 ; i++)
		{
			gcd = Math.max( Getgcd(treeary[i], treeary[i+1]), gcd);
			lcm = Math.max( treeary[i]*treeary[i+1]/gcd, gcd);
		}
			
/*		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );
		bw.write();
		bw.flush();
		bw.close();
*/	}

}

