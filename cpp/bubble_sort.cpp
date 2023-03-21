#include <bits/stdc++.h>
using namespace std;

// Space complexity: O(1), No extra space needed
// Time complexity: O(n^2) 
// bubble and selection sorting both don't require extra space and have the same time complexity
// However bubble sorting is better because it stops the itation once the vector is sorted 
// so bubble sorting at best case can have Time complexity: O(n)
void bubble_sort(vector<int> &v)
{
    int tmp;
    bool flag;// to indicate whether any replacements happened or not;
    for (int j=v.size()-1; j > 0; j--)
    {   
        flag = true; // reset the flag so if no replacments happened this iteration stop the algorithm
        for(int i=0; i<j; i++)
        {
            if(v[i] > v[i+1])
            {
                tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;
                flag = false;
            }
        }
        if(flag)  // stops the algorithm if the vector is sorted
            break;
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
    bubble_sort(v);
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}