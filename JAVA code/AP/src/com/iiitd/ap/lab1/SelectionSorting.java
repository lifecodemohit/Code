package com.iiitd.ap.lab1;

/**
 * 
 * @author Varun Bansal 2013168
 *
 */

public class SelectionSorting{
	public int swaps = 0;
	private int i, j;
	private int len;
	public <T extends Comparable> T[] Sort(T[] arr){
		len = arr.length;
		swaps = 0;
		T temp;
		int min;
		for(i=0; i<len; i++){
			min = i;
			for(j=i; j<len; j++){
				if(arr[j].compareTo(arr[min])<0)
					min = j;
			}
			if(min!=i){
				temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
				swaps++;
			}
		}
		return arr;
	}
	
	
	

}
