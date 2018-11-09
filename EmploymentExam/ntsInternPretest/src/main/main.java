package main;

import java.util.ArrayList;
import java.util.Comparator;

import algorithm.search.BinarySearch;
import algorithm.sort.HeapSort;
import algorithm.sort.InsertSort;
import algorithm.sort.QuickSort;

public class main {

	static Comparator<Integer> intComp;
	
	public static void main(String args[]){
		
		intComp = new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				// TODO Auto-generated method stub
				return o1 > o2 ? 1 : -1;
			}
		};
		
		AlgorithmManager am = new AlgorithmManager();
				
		ArrayList<Integer> ary = am.getRandomNumbersWithNonDuplication(0, 1000, 10);
	
		/*InsertSort<Integer> is = new InsertSort<Integer>(ary, intComp);
		is.sort();
		System.out.println(is);*/
		/*
		QuickSort<Integer> qs = new QuickSort<>(ary, intComp);
		qs.printSortingProcess();
		System.out.println(qs);
		*/
		
	/*	BinarySearch bs = new BinarySearch(qs.getSortedSource());
		System.out.println(bs.search(7));
		*/
		
		HeapSort<Integer> hs = new HeapSort<Integer>(ary, intComp);
		hs.sort();
		System.out.println(hs);
		
	}
	
	
}
