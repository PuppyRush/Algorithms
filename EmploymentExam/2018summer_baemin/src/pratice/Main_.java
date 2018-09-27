package pratice;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main_ 
{
	static int memo[][];
	public static int recursive(final int[] args,final int prevIdx, final int nowidx, final int one, int point)
	{
		final int argc = args.length;
		if(nowidx > argc-1)
			return -1;
		if(one>=2)
			return -1;
		if(nowidx==argc-1)
			return args[nowidx]+point;
		
		final int sum = point+args[nowidx];
		
		if(memo[prevIdx][nowidx]!=-1)
			if(sum < memo[prevIdx][nowidx])
				return -1;
		memo[prevIdx][nowidx] = sum;
		
		int first = -1;
		int second = -1;
		
		first = recursive(args,nowidx,nowidx+1,one+1,sum);
		second = recursive(args,nowidx,nowidx+2,0,sum);
		return first > second ? first : second;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		memo = new int[301][301];
		for(int i=0; i < 301 ; i++)
		{
			for(int l=0 ; l < 301 ; l++)
				memo[i][l] = -1;
		}
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		final int size = Integer.parseInt(br.readLine());
		int stairway[]= new int[size+1];
		stairway[0] = 0;
		for(int i=0 ; i < size ; i++)
			stairway[i+1] = Integer.parseInt(br.readLine());
		
		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );
		final int result = recursive(stairway,0,0,-1,0);
		bw.write(String.valueOf(result));
		bw.flush();
		bw.close();
	}

}

