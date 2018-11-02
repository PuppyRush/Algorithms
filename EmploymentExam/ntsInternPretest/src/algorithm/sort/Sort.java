package algorithm.sort;

import java.util.ArrayList;
import java.util.Comparator;

public abstract class Sort <E> {

	
	
	protected Comparator<E> comparator;
	protected boolean isFinishSorting;
	protected ArrayList<E> source;
	protected ArrayList<E> sortedSource;
	
	public ArrayList<E> getSortedSource(){
		return sortedSource;
	}
	
	public Sort(ArrayList<E> source, Comparator<E> comp){
		this.source = new ArrayList<E>(source);
		sortedSource = new ArrayList<E>(source);

		comparator = comp;
	}
	
	public abstract void sort();
	
	protected void swap(int leftIdx, int rightIdx){
		
		E temp = sortedSource.get(leftIdx);
		sortedSource.set(leftIdx, sortedSource.get(rightIdx));
		sortedSource.set(rightIdx, temp);		
		
	}
	
	public abstract void printSortingProcess();
	
	public void addSource(ArrayList<E> newSource){
		source.addAll(newSource);
	}

	public void initializeSource(ArrayList<E> source){
		this.source = new ArrayList<E>(source);
		sortedSource = new ArrayList<E>(source);
	}
	
	@Override
	public String toString(){
		
		StringBuilder bld = new StringBuilder();
		
		String isSort = isFinishSorting ? "정렬됨" : "정렬되지 않음";
		bld.append("정렬여부 : " + isSort + "\n");
		
		if(isFinishSorting){
			bld.append(source).append("\n").append(sortedSource).append("\n");
		}
		else{
			bld.append(source).append("\n");
		}
		
		return bld.toString();
		
	}
	
}
