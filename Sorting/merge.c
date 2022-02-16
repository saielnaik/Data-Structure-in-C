#include<stdio.h>
#include<stdlib.h>

void mergeSort(int *, int);
void merge(int*, int, int*, int);

void main(){
	int *arr, i, n;
	
	printf("Enter the number of elements in the array :");
	scanf("%d",&n);
	
	arr = (int*) malloc(sizeof(int));
	
	printf("Enter the elements to be sorted: ");
	for(i = 0;i < n; i++)
		scanf("%d",&arr[i]);
	
	mergeSort(arr, n);
	
	printf("The sorted elements are : ");	
	for(i = 0;i < n; i++)
		printf("%d\t",arr[i]);
	printf("\n");
}

void mergeSort(int *array, int size){
    int mid;
    if(size == 1)
        return;
    else{
        mid = size/2;
        mergeSort(array, mid);
        mergeSort(array + mid, size - mid);
        merge(array, mid, array + mid, size - mid);
    }
}

void merge(int *a, int s1, int *b, int s2){
	int i, j, k, *temp_arr;
	temp_arr = (int*) malloc((s2+s1) * sizeof(int));
	i = j = k = 0;
	while(i < s1 && j < s2)
	    temp_arr[k++] = (a[i] < b[j]) ? a[i++] : b[j++];
	while(i < s1)
	    temp_arr[k++] = a[i++];
    while(j < s2)
	    temp_arr[k++] = b[j++];
	for(i = 0; i < k; i++)
	    a[i] = temp_arr[i];
    free(temp_arr);
}