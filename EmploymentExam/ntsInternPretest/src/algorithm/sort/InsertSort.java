package algorithm.sort;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.SortedMap;

public class InsertSort<E> extends Sort<E>{

	public InsertSort(ArrayList<E> source, Comparator<E> comp) {
		super(source, comp);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void sort() {
		// TODO Auto-generated method stub
		
		for(int i=0 ; i < sortedSource.size() ; i++){
			for(int l=0 ; l < i ; l++){
				
				boolean comp = comparator.compare(sortedSource.get(i), sortedSource.get(l)) == 1 ? false : true;
				if(comp)
					swap(i,l);
				
			}
			
			
		}
		
		isFinishSorting = true;
	
	}

	
	
	@Override
	public void printSortingProcess() {
		// TODO Auto-generated method stub
		
		
		for(int i=0 ; i < sortedSource.size() ; i++){
			for(int l=0 ; l < i ; l++){
				
				boolean comp = comparator.compare(sortedSource.get(i), sortedSource.get(l)) == 1 ? false : true;
				if(comp){
					E temp = sortedSource.get(i);
					sortedSource.set(i, sortedSource.get(l));
					sortedSource.set(l, temp);					
				}
				
			}
			
			System.out.println(sortedSource);
			
			
		}
		
		isFinishSorting = true;
		
	}

	
	

	
	
	
}
