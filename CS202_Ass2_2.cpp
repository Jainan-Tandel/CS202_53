#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


int main() {
    unsigned int n,i,j, min_index;
    unsigned long int input, maxim, length;
    vector <unsigned long int> sizes;
    vector <vector<unsigned long int>> arrays;
    vector <unsigned long int> row;
    vector <unsigned long int> ends;
    vector <unsigned long int> col1;
    
    vector <unsigned long int> Ans;
    // vector <unsigned long int> Anse;
    cin >> n;
    vector <unsigned long int> col1_indices(n,0);
    for(i = 0; i < n; i++)
    {
        cin >> input; sizes.push_back(input);
        row = {};
        for(j = 0; j < sizes[i]; j++)
        {
            cin >> input; row.push_back(input);
        }
        col1.push_back(row.front());
        ends.push_back(row.back());
        arrays.push_back(row);
    }

    maxim = *max_element(ends.begin(),ends.end());
    for(i = 0; i < n; i++)
    {
        arrays[i].push_back(maxim);
        length+=sizes[i];
    }

    for(i = 0; i < length; i++)
    {
        min_index = min_element(col1.begin(),col1.end()) - col1.begin();
        Ans.push_back(arrays[min_index][col1_indices[min_index]]);
        col1_indices[min_index]+=1;
        col1[min_index] = arrays[min_index][col1_indices[min_index]];
    }

    for(i = 0; i < length; i++)
    {
        cout << Ans[i] << " ";
    }
    return 0;
}