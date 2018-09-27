package pratice;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.lang.reflect.AnnotatedParameterizedType;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.NavigableSet;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;

//11403
public class Main
{
	public static Boolean visited[][];
	public static List<List<Integer>> paths;
	//
	public static void find(Queue<Integer> q, final int i)
	{
		for(int j : paths.get(i))
		{
			if(visited[i][j])
				continue;  
			
			visited[i][j] = true;
			q.add(j);
			
			for(Integer path : q)
				visited[path][j] = true;
			
			find(q, j);
			
			q.poll();
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int size = Integer.parseInt(br.readLine());
		
		paths = new ArrayList<List<Integer>>(size);
		visited = new Boolean[size][size];
		for(int i=0 ; i < size ; i++)
			for(int l=0 ; l < size ; l++)
				visited[i][l] = false;
		
		for(int i=0 ; i < size ; i++)
		{
			paths.add(new ArrayList<Integer>());
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for(int l=0 ; l < size ; l++)
			{
				int j = Integer.parseInt(st.nextToken());
				if(j==1)
				{
					paths.get(i).add(l);
				}
			}
		}
		
		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );
		
		for(int i=0 ; i < size ; i++)
		{
			if(!paths.get(i).isEmpty())
			{
				Queue<Integer> list = new ArrayDeque<Integer>();
				list.add(i);
				find(list,i);
			}
		}
		
		StringBuilder sb = new StringBuilder(size*2*size);
		for(int i=0 ; i < size ; i++)
		{
			for(int l=0 ; l < size ; l++)
				sb.append(String.valueOf(visited[i][l]?1:0)).append(" ");
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
	}

} 