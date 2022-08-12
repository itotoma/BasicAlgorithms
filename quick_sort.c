#include <stdio.h>

/*値を入れ替える関数*/
void swap(int *x, int *y) {
	printf("\nswap %d and %d", *x, *y);
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/*
pivotを決め
全データをpivotを境目に振り分け、
pivotの添字を返す
*/


int partition (int array[], int i, int j) {
	int pivot = i; //本当はfind_pivotで見つけるが簡単のため先頭要素をpivotとする

	do {
		do { i++; } while (array[i] < array[pivot]); 
		/*左から右に走査してarray[i] > array[pivot] となる i を返す*/
		//do { j--; } while (array[pivot] < array[j]);
		while(array[pivot] < array[j]){j--;}
		/*右から左に走査してarray[i] < array[pivot] となる i を返す*/
		if(i < j) { swap(&array[i], &array[j]); }
	} while (i < j); /*i j 出会ったら終了*/
	swap(&array[pivot], &array[j]); /*pivotに使ったものは後半の先頭*/ 
	return j;
}

void quick_sort(int array[], int left, int right) {
	int pivot;
	printf("\nleft:%d, right:%d",left, right);
	if (left < right) {
		pivot = partition(array, left, right);
		printf("\npivot:%d",pivot );
		quick_sort(array, left, pivot); /*左端とpivotの間でさらにソート*/
		quick_sort(array, pivot+1, right); /*pivotと右端の間でさらにソート*/
	}
}

int main (void){
	int array[10] = {1, 2, 8, 5, 4, 7, 9, 0, 6, 3};//{0, 2, 8, 5, 4, 7, 9, 1, 6, 3};
	int i;
	printf("Before sort: ");
	for(i = 0; i < 10; i++) {printf("%d ", array[i]);}
	printf("\n");

	quick_sort(array, 0, 9);

	printf("After sort: ");
  	for (i = 0; i < 10; i++) { printf("%d ", array[i]);}
  	printf("\n");

  	return 0;
}








