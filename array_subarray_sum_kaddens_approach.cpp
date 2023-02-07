#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#include <iostream>
using namespace std;
int largest_subarray_sum(int* arr, int n) {
    cout << "inside array\n";
    int cs = 0;
    int largest_sum = 0;
    for (int i = 0; i < n; i++) {
        cs = cs + arr[i];
        if (cs < 0) {
            cs = 0;
        }
        largest_sum = max(largest_sum, cs);
    }
    return largest_sum;
}
int main()
{
    int arr[] = {-2,3,4,-1,5,-12,6,1,3 ,2};
    int n = sizeof(arr) / sizeof(int);
    cout << largest_subarray_sum(arr, n);
    cout << endl;
}


