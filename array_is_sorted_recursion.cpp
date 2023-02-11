#include <stdio.h>
#include <iostream>

using namespace std;
bool is_sorted(int arr[], int i, int n) {
	if (i == n-1) {
		return true;
	}
	if (arr[i] < arr[i + 1] and is_sorted(arr, i + 1, n) ) {
		return true;
	}
	return false;
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8 };
	cout << is_sorted(arr, 0, 8);

}