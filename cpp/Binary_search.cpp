#include <bits/stdc++.h>
using namespace std;


// searching through a sorted vector returning the index if found and -1 if not
// Time comlexity: O(log n), where n is the size of the vector
int binary_search(int value, vector<int> &v)
{
    int first = 0, last = v.size();
    int mid;

    while (first <= last)
    {
        mid = (first + last) / 2;
        if(v[mid] == value)
            return mid;

        if(v[mid] > value)
            last = mid - 1;
        
        else
            first = mid + 1; 
    }

    return -1;
    
}

int main()
{
    vector<int> v(30);
    iota(v.begin(), v.end(), 1); // initializing the vector with values from 1 to 30

    int n; cin >> n;

    cout << (binary_search(n, v) == -1 ? "not found: " : "found at index: ") << binary_search(n, v) << endl;
}