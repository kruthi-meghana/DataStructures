
import java.io.*;
import java.net.*;
import java.util.*;


/*
Heap Sort:

Given an array of elements, 

to re-arrange the elements to form either MaxHeap or Min Heap is called Heapify - O(log n)
to insert elements in to a heap for 'n' elements - O(n)
to delete elements in a heap - O(n)

Heapify:

1) This process is done from bottom-to-up
2) you compare the child nodes with the root node and check if max(or min) heap condition is satisfied.
3) If not you swap the root and related child, and repeat the process for the child.

Sort O(nlogn):

1) At any given point of time the highest(lowest for min) number is find at the root of the tree.
2) You swap the root with the last node and decrease your 'n', and perform heapify to the newly formed array.
3) you get the sorted array when you n becomes 0.


@author: Kruthi Meghana Anumandla
*/

public class HeapSort {
    
	public void sort(int arr[]) {
        	
		int n = arr.length;
 
 	       for (int i = n - 1; i > 0; i--) {
            	    int swap = arr[0];
            	    arr[0] = arr[i];
            	    arr[i] = swap;
		    heapify(arr, i, 0);
        	}
 	}
 
 
    	void heapify(int arr[], int n, int i) {
        	int largest = i; 
        	int l = 2 * i + 1;
        	int r = 2 * i + 2; 
		
        	if (l < n && arr[l] > arr[largest])
        	    largest = l;
 
        
       		if (r < n && arr[r] > arr[largest])
            	largest = r;
 
        
	        if (largest != i) {
        	    int swap = arr[i];
            	    arr[i] = arr[largest];
            	    arr[largest] = swap;
 
 	           heapify(arr, n, largest);
        	}
    	}
	
	public static void main(String args[]) {
	        int arr[] = { 12, 11, 13, 5, 6, 7 };
        	int n = arr.length;
 
 	       HeapSort heapObj = new HeapSort();
	       for(int i = n/2 - 1; i >= 0; i++) {
		       heapObj.heapify(arr, n, i);
	       }
               heapObj.sort(arr);
 
               System.out.println("Sorted array is");
               for(int i = 0; i < n; i++)
		       System.out.println(arr[i]);
    }
}
