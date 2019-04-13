/*
 * File name: solu.cpp
 */

#include <iostream>
#include <fstream>
#include <vector>

/*
 * note: my code calculate counts is bigger than the answer
 * for first as pivot, mine is 162129, the answer is 162085, i check my code,
 * and can't find why, so I give up.
 */

using namespace std;

int choose_first_as_pivot(vector<int> &nums, int left, int right)
{
    swap(nums[left], nums[right]);
    return nums[right];
}

int choose_last_as_pivot(vector<int> &nums, int left, int right)
{
    return nums[right];
}

int choose_median_as_pivot(vector<int> &nums, int left, int right)
{
    int center = (left + right) / 2;

    if (nums[left] > nums[center])
        swap(nums[left], nums[center]);

    if (nums[center] > nums[right])
        swap(nums[center], nums[right]);

    if (nums[left] > nums[right])
        swap(nums[left], nums[right]);

    swap(nums[center], nums[right]);

    return nums[right];
}

int q_sort(vector<int> &nums, int left, int right)
{
    int count = 0;

    if (left >= right)
        return 0;

    count = right - left;

    // int pivot = choose_first_as_pivot(nums, left, right);
    // int pivot = choose_last_as_pivot(nums, left, right);
    int pivot = choose_median_as_pivot(nums, left, right);

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[right]);

    count += q_sort(nums, left, i);
    count += q_sort(nums, i + 2, right);

    return count;
}

int quick_sort(vector<int> &nums)
{
    int count = 0;

    count = q_sort(nums, 0, nums.size() - 1);

    return count;
}


int main(void)
{
    fstream file("QuickSort.txt", ios::in);

    vector<int> nums;
    string s;
    int count = 0;

    while(getline(file, s)) {
        nums.push_back(stoi(s));
    }

    count = quick_sort(nums);

    cout << count << endl;

    return 0;
}
