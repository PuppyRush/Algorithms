package main;

import java.util.List;
import java.util.Random;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class AlgorithmManager {

	public ArrayList<Integer> getRandomNumbersWithNonDuplication(int left, int right, int size){
		
		if( Math.abs(right-left) < size){
			throw new IllegalArgumentException(":"  + Math.abs(right-left) + " " + size);
		}
		
		int absNumber = Math.abs(left-right);
		Random rdm = new Random();
		HashMap<Integer, Boolean> checker = new HashMap<Integer, Boolean>();
		ArrayList<Integer> ary = new ArrayList<Integer>(); 
		for(int i=0 ; i < size ; i++){
			
			int number;
			if(left<0)
				number = rdm.nextInt(absNumber)-right;
			else
				number = rdm.nextInt(right);
			
			if(checker.containsKey(number)){
				i--;
				continue;
			}
			else{
				checker.put(number, true);
				ary.add(number);
			}
			
		}

		return ary;
	}
	
	public ArrayList<Integer> getRandomNumbers(int left, int right, int size){
		
		int absNumber = Math.abs(left-right);
		Random rdm = new Random();
		ArrayList<Integer> ary = new ArrayList<Integer>(); 
		for(int i=0 ; i < size ; i++){		
			int number = rdm.nextInt(absNumber)-right;
			ary.add(number);
		
		}

		return ary;
	}
		
}
