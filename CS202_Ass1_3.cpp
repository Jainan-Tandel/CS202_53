#include <iostream>
#include <vector>
using namespace std;

void opposite_sort(int A[], int n){
    for(unsigned int i = 0; i < n/2; i++ )
    {
        if(A[i] > A[n-i-1])
        {
            A[i] = A[i] + A[n-i-1];
            A[n-i-1] = A[i] - A[n-i-1];
            A[i] = A[i] - A[n-i-1];
        }
    }
}

int main() {
    unsigned int l;
    int input;
    cout << "Enter the number of integers to sort:";
    cin >> l;
    vector<int> N_in;
    for(unsigned int i = 0; i<l; i++)
    {
        cin >> input; N_in.push_back(input);
    }
    
    for(int i = l-1; i >= 0; i--)
    {
        for(unsigned int j = 0; j < i; j++)
        {
            vector<int> subvector = {N_in[j],N_in[j+1]};
            int* sub_copy_array = &subvector[0];        
            opposite_sort(sub_copy_array, 2);
            
            for(unsigned int x = j; x < j+2; x++)
            {   
                N_in[x]=sub_copy_array[x-j];
            }
        }
    }

    for(unsigned int i = 0; i < l; i++)
    {   
        cout << N_in[i] << " ";
    }
    return 0;
}
