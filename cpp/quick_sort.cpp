#include <bits/stdc++.h>
using namespace std;

// the algorithm works by swapping the left and the right elements depending
// on the value of the pivot, at the suitable index of the pivot the left
// will be bigger than the right at this point we swap the value of the right 
// index with the value of the pivot and recursivly do the same for the two
// parts around the right which is the pivot


// Time complexity: O(nlog(n))
// Space complexity: O(1)
void quick_sort(vector<int> &v, int start, int end)
{
    int pivot = start;
    int tmp, left = start+1, right = end;
    

    if(start >= end)
        return;

    while (left <= right)
    {
        if(v[left] > v[pivot] && v[right] < v[pivot])
        {
            tmp = v[left];
            v[left] = v[right];
            v[right] = tmp;
            left++;
            right--;
        }

        else if(v[left] <= v[pivot])
        {
            left++;
        }

        else if(v[right] >= v[pivot])
        {
            right--;
        }

    }

    tmp = v[pivot];
    v[pivot] = v[right];
    v[right] = tmp;

    quick_sort(v, start, right - 1);
    quick_sort(v, right + 1, end);

};



int main()
{
    vector<int> v = {2, 7, 1, 0, -2, -167, 2, 4, 7, 23, 45, 5};
    cout << "before sorting:\n";
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "after sorting:\n";
    quick_sort(v, 0, v.size()-1);
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}