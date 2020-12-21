/*71.given an array where elements in array becomes the parent node for child nodes which are their indices, find the maximum height*/
/*solution : since Height = Depth, calculating the depths of all nodes recursively , complexity = O(n)*/

#include<stdio.h>
#include<stdlib.h>
void calculateDepth(int[8], int[8], int);
void main(){
	int arr[8] = { 1, -1, 4, 0, 1, 2, 4, 0 };
	int buff[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
	for (int i = 0; i < 8; i++){
		if (buff[i] == -1)
			calculateDepth(arr, buff, i);
	}
	for (int i = 0; i < 8; i++)
		printf("%d \n", buff[i]);
	getchar();
}

void calculateDepth(int arr[8], int buff[8], int ind){
	if (arr[ind] == -1){
		buff[ind] = 0;
		return;
	}
	calculateDepth(arr, buff, arr[ind]);
	buff[ind] = buff[arr[ind]] + 1;
	return;
}