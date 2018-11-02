package algorithm.search;

import java.util.ArrayList;

public class BinarySearch extends Search<Integer>{

	public BinarySearch(ArrayList<Integer> source) {
		// TODO Auto-generated constructor stub
		super(source);
	}
	
	@Override
	public int search(Integer dest) {
		// TODO Auto-generated method stub
		
		int low=0 , high = source.size()-1, mid;
		
		while(low <= high){
			
			mid = (high+low)/2;
			
			if(dest < source.get(mid))
				low = mid+1;
			else if(dest < source.get(mid))
				high = mid-1;
			else
				return mid;
		
		}
		
		return -1;
		
	}

	@Override
	public void printSortingProcess() {
		// TODO Auto-generated method stub
		
	}

	
	
}
