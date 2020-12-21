/*58.A boy can climb 1 or 2 steps at a time.In how many ways he can climb n stairs?(Extension : print the paths)*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void paths(int, char tree[50], int);


void main(){
	char tree[50] = { '\0' };
	paths(5, tree, 0);
	_getch();
}
void paths(int step, char tree[50], int ind){
	if (step > 0){
		if (step == 1){
			tree[ind] = 's';
			tree[ind + 1] = '\0';
			printf("%s \n", tree);
		}
		else{
			tree[ind++] = 's';
			paths(step - 1, tree, ind);
			tree[ind - 1] = 'd';
			paths(step - 2, tree, ind);
		}

	}
	else{
		tree[ind] = '\0';
		printf("%s \n", tree);
	}

}