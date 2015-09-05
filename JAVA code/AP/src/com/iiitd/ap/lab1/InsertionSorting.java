package com.iiitd.ap.lab1;

/**
 * 
 * @author Varun Bansal 2013168
 *
 */

public class InsertionSorting{
//	private T[] arr;
	public int swaps = 0;
	private int i, j;
	private int len;

	public InsertionSorting(){		
	}
	public <T extends Comparable<T>> T[] Sort(T[] arr){
		swaps=0;
		len = arr.length;
		for(i=1; i<len; i++){
			T t = arr[i]; //temp variable to store the index of ith element
			j = i;
			while(j>0 && (arr[j-1].compareTo(t)>=0) ){
				arr[j] = arr[j-1];
				j--;
				++swaps;
			}
			arr[j] = t;
		}
		return arr;
	}
}
