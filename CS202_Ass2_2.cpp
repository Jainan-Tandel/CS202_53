#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned int n,i,j,k;
    unsigned long int input;
    vector <unsigned long int> sizes;
    vector <vector<unsigned long int>> arrays;
    vector <unsigned long int> row;
    // vector <unsigned long int> ends;
    // vector <unsigned long int> col1;
    vector <unsigned long int> temp_row;
    
    // vector <unsigned long int> Ans;
    // vector <unsigned long int> Anse;
    cin >> n;
    vector <unsigned long int> col1_indices(n,0);
    for(i = 0; i < n; i++)
    {
        cin >> input; sizes.push_back(input);
        row = {};
        // cin >> input; row.push_back(input);
        // col1.push_back(input);
        
        for(j = 0; j < sizes[i]; j++)
        {
            cin >> input; row.push_back(input);
        }
        // ends.push_back(row.back());
        arrays.push_back(row);
    }

    // maxim = *max_element(ends.begin(),ends.end());
    // for(i = 0; i < n; i++)
    // {
    //     arrays[i].push_back(maxim);
    //     length+=sizes[i];
    // }

    // for(i = 0; i < length; i++)
    // {
    //     min_index = min_element(col1.begin(),col1.end()) - col1.begin();
    //     Ans.push_back(arrays[min_index][col1_indices[min_index]]);
    //     col1_indices[min_index]+=1;
    //     col1[min_index] = arrays[min_index][col1_indices[min_index]];
    // }

    i = n;
    while(i>1)
    {
        // vector <unsigned long int> new_col1;
        for(j = 0; j < i-1; j+=2)
        {
            temp_row.clear();
            int row1 = 0, row2 = 0;
            while(row1 < sizes[j] && row2 < sizes[j+1])
            {
                if(arrays[j][row1] <= arrays[j+1][row2])
                {
                    temp_row.push_back(arrays[j][row1]);row1++;
                }
                else
                {
                    temp_row.push_back(arrays[j+1][row2]);row2++;
                }
            }

            while(row1 < sizes[j])
            {   temp_row.push_back(arrays[j][row1]);row1++;     }

            while(row2 < sizes[j+1])
            {   temp_row.push_back(arrays[j+1][row2]);row2++;   }

            arrays[j/2] = temp_row;
            sizes[j/2] = sizes[j] + sizes [j+1];
            // for(k = 0; k < sizes[j] + sizes[j+1]; k++)
            // {
            //     min_index = min_element(col1.begin()+j,col1.begin()+j+1) - col1.begin();
            //     temp_row.push_back(arrays[min_index][col1_indices[min_index]]);
            //     col1_indices[min_index]+=1;
            //     col1[min_index] = arrays[min_index][col1_indices[min_index]];
            // }
            // new_col1.push_back(0);
        }

        if(i&1 == 1)
        {
            arrays[(i-1)/2] = arrays[i-1];
            sizes[(i-1)/2] = sizes[i-1];
        }
    
        i = (i+1)/2;
        // col1=new_col1;
        // vector <unsigned long int> col1_indices(i,0);
    }

    for(i = 0; i < sizes[0]; i++)
    {
        cout << arrays[0][i] << " ";
    }
    return 0;
}
