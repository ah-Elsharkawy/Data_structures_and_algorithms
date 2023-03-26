#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, vector<int> v1, vector<int> v2)
{
    int i=0, j=0, k=0;
    while (i < v1.size() && j < v2.size())
    {
        if(v1[i] <= v2[j])
        {
            v[k] = v1[i];
            i++;
        }
        else
        {
            v[k] = v2[j];
            j++;
        }
        k++;
    }

    while(i < v1.size())
    {
        v[k] = v1[i];
        i++;
        k++;
    }

    while(j < v2.size())
    {
        v[k] = v2[j];
        j++;
        k++;
    }
   
}

void merge_sort(vector<int> &v)
{
    if(v.size() <= 1)
        return;

    vector<int> left;
    vector<int> right;

    int mid = v.size() / 2 ;

    for (int i = 0; i < mid ; i++)
    {
        left.push_back(v[i]);
    }

    for (int i = mid; i < v.size(); i++)
    {
        right.push_back(v[i]);
    }

    merge_sort(left);
    merge_sort(right);

    merge(v, left, right);
}




int main()
{
    vector<int> v = {-3, 5, 7, 0, 1, 3, 2, 374, 192, 2, -384};

    cout << "before sorting:\n";
    for(auto i: v)
    {
        cout << i << " ";
    }
    cout << endl;

    merge_sort(v);

    cout << "after sorting:\n";
    for(auto i: v)
    {
        cout << i << " ";
    }
    cout << endl;
}