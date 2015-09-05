package com.iiitd.ap.lab1;

/**
 * 
 * @author Varun Bansal 2013168
 *
 */

public class SelectionSort {
	private int swap = 0;
	private int i, j;
	private int len;
	public <T extends Comparable> T[] Sort(T[] arr){
		len = arr.length;
		T temp;
		int min;
		for(i=0; i<len; i++){
			min = i;
			for(j=i; j<len; j++){
				if(arr[j].compareTo(arr[min])<0)
					min = j;
			}
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			swap++;
		}
		return arr;
	}
	
	
	

}
