/*
 * File name: solu.cpp
 */

#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

long merge(vector<long> &in, vector<long> &out, long left, long right)
{
    long pos = left;
    long left_pos = left;
    long left_end = (left + right) / 2;
    long right_pos = (left + right) / 2 + 1;
    long right_end = right;
    long ret = 0;

    while (left_pos <= left_end && right_pos <= right_end) {
        if (in[left_pos] <= in[right_pos]) {
            out[pos++] = in[left_pos++];
        } else {
            ret = ret + left_end - left_pos + 1;
            out[pos++] = in[right_pos++];
        }
    }

    while (left_pos <= left_end) {
        out[pos++] = in[left_pos++];
    }

    while (right_pos <= right_end) {
        out[pos++] = in[right_pos++];
    }

    for (int i = left; i <= right; i++) {
        in[i] = out[i];
    }

    return ret;
}

long merge_sort(vector<long> &in, vector<long> &out, long left, long right)
{
    long ret = 0;
    long center = (left + right) / 2;

    if (left >= right)
        return 0;

    ret += merge_sort(in, out, left,  center);
    ret += merge_sort(in, out, center + 1, right);

    ret += merge(in, out, left, right);

    return ret;
}

int main(void)
{
    fstream in("IntegerArray.txt", ios::in);

    long ret = 0;
    vector<long> tmp;
    string s;

    while (getline(in, s)) {
        tmp.push_back(stoi(s));
    }

    vector<long> tmp2(tmp.size(), 0);
    ret = merge_sort(tmp, tmp2, 0, tmp.size() - 1);

    printf("max pair is %ld\n", ret);

    return 0;
}