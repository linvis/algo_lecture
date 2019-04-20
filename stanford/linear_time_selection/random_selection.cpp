/*
 * File name: random_selection.cpp
 */
#include <iostream>
#include <vector>

using namespace std;


// we always use order [1, N]

int median(vector<int> &arr, int left, int right)
{
    int center = (left + right) / 2;

    if (arr[left] > arr[center])
        swap(arr[left], arr[center]);

    if (arr[center] > arr[right])
        swap(arr[center], arr[right]);

    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);

    swap(arr[center], arr[right]);

    return arr[right];
}

int r_selection(vector<int> &arr, int left, int right, int order)
{
    if (left >= right)
        return arr[left];

    int pivot = median(arr, left, right);

    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // pivot in i + 1
    //    < pivot   |  > pivot            |  pivot
    // left       i |   i+ 1     right -1 |  right
    swap(arr[i + 1], arr[right]);

    int idx = i + 1;
    
    if (idx == order - 1) {
        return pivot;
    } else if (idx > order - 1) {
        return r_selection(arr, left, idx - 1, order);
    } else {
        return r_selection(arr, idx + 1, right, order);
    }
}

int random_selection(vector<int> &arr, int order)
{
    return r_selection(arr, 0, arr.size() - 1, order);
}

int main(void)
{
    // 1, 2, 3, 4, 5, 6, 7, 8, 9
    vector<int> arr = {1, 8, 5, 2, 4, 3, 7, 9, 6};
    int order = 9;

    for (auto i = 1; i <= order; i++)
        cout << random_selection(arr, i) << endl;
}
