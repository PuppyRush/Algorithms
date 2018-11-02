package algorithm.search;

import java.util.ArrayList;
import java.util.Comparator;

public abstract class Search <E> {

	
	protected ArrayList<E> source;
	
	public Search(ArrayList<E> sour){
		source = sour;
	}
	
	public abstract int search(E val);
	
	public abstract void printSortingProcess();
	
	public void initializeSource(ArrayList<E> source){
		this.source = new ArrayList<E>(source);
	}
	
	@Override
	public String toString(){
		
		return source.toString();
		
	}
	
}
