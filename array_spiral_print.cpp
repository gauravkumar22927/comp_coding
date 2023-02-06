#include <vector>
#include <string>
#include <iostream>
using namespace std;
//template <class T>
void print_arr(int arr[][10], int n, int m) {
    int start_row = 0;
    int end_col = m - 1;
    int end_row = n - 1;
    int start_col = 0;

    while (start_col <= end_col and start_row<= end_row) {
        //start_row
        for (int i = start_col; i <= end_col; i++) {
            cout << arr[start_row][i] << " ";
        }
        //end_col
        for (int i = start_row +1; i <= end_row; i++) {
            cout << arr[i][end_col] << " ";
        }
        //end_row
        for (int i = end_col -1; i >= start_col; i--) {
            if (start_row == end_row) {
                break;
            }
            cout << arr[end_row][i] << " ";
        }
        //start_col
        for (int i = end_row -1; i >= start_row +1; i--) {
            if (start_col == end_col) {
                break;
            }
            cout << arr[i][start_col] << " ";
        }

        //updating variables
        start_row++;
        end_row--;
        start_col++;
        end_col--;
    }
}
int main()
{   
    int arr[][10] = { {1,2,3,4}
                     ,{12,13,14,5}
                     ,{11,16,15,6}
                     ,{10,9,8,7} };
    int m = 4;
    int n = 4;
    print_arr(arr, n, m);
}


