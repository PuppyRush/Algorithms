package pratice;

//1074

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main_1074 
{
	
	public static int recursive(int count, final int nowN, final int r, final int c)
	{
		if(nowN==2)
		{
				
		}
		
		recursive(count,size,N/2,x,y,destx,desty);
		count++;
		x+=1;
		y=(int) (Math.pow(2, (double)N)-1);
		
		return count;
	}
	
	
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		final int size = Integer.parseInt(st.nextToken());
		final int r = Integer.parseInt(st.nextToken());
		final int c = Integer.parseInt(st.nextToken());
		
		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );
		
		String str = String.valueOf(recursive(0,size,size,c,r));
		bw.write(str);
		bw.flush();
		bw.close();
	}

}

