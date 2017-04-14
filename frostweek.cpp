
#include <iostream>
 
int merge(int arr[], int temp[], int left, int mid, int right)
{
	int inv = 0;
	int i = left;
	int j = mid;
	int k = left;
	while ((i <= mid -1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
			inv = inv + (mid -i);
		}
	}
	while (i <= mid -1){
		temp[k++] = arr[i++];
	}
	while (j <= right){
		temp[k++] = arr[j++];
	}
	for (i = left; i <= right; i++)
	{
		arr[i] = temp[i];
	}
	return inv;
}


int mergeSort(int arr[], int temp[], int left, int right)
{
	int mid = 0;
	int inv = 0;
	if ( right > left)
	{
		mid = (right + left)/2;
		inv = mergeSort(arr, temp, left, mid);
		inv += mergeSort(arr, temp, mid+1, right);
		inv += merge(arr, temp, left, mid+1, right);
	}
	return inv;
}

int main()
{
	int n, number;
	scanf("%d", &n);
	int array[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		array[i] = number;
	}
	int counter = 0;
	int temp[n];
	int inv = mergeSort(array, temp, 0, n-1);
	printf("%d\n", inv);

}