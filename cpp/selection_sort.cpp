#include <bits/stdc++.h>
using namespace std;

// Space complexity: O(1)
// Time complexity:  O(n^2)
void selection_sort(vector<int> &v)
{
    int min, tmp;
    int min_index;

    for(int i = 0; i < v.size(); i++)
    {
        min = v[i];
        min_index = i;
        for(int j = i+1; j < v.size(); j++)
        {
            if(v[j] < min)
            {
                min = v[j];
                min_index = j;                
            }
        }
        tmp = v[i];
        v[i] = v[min_index];
        v[min_index] = tmp;
    }

}



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
    selection_sort(v);
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

}