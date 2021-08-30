#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
    *a = *b + *a;
    *b = *a - *b;
    *a = *a - *b;
}


void sort_5(vector<int> &N)
{ 
    if(N[0]>N[1])
    {   
        swap(&N[0],&N[1]); 
    }
    
    if(N[3]>N[4])
    {
         swap(&N[3],&N[4]);
    }

    if(N[0]>N[2])
    {
        swap(&N[1],&N[2]);
        swap(&N[1],&N[0]);
    }
    else
    {
        if(N[1] > N[2])
        {   
            swap(&N[1],&N[2]); 
        }
    }

    vector<int> N_new(5,0);
    int i=0, j=0;

    for(int k = 0; k < 5; k++)
    {
        if(i == 3)
        {
            for(int x = k; x < 5; x += 1)
            {
                N_new[x] = N.at(x);
            }
            break;
        }
        if(j == 2)
        {
            for(int x = k; x < 5; x += 1)
            {
                N_new[x] = N.at(x-2);
            }
            break;
        }
        if(N.at(i) > N.at(3+j))
        {
            N_new[k] = N.at(3+j);
            j+=1;
        }
        else
        {
            N_new[k] = N.at(i);
            i+=1;
        }  
    }    
    for(unsigned int x = 0; x < 5; x++)
    {   
        N.at(x)=N_new[x];
    }
    // cout << "\n";
    // for(unsigned int x = 0; x < 5; x++)
    // {   
    //     cout << N_new[x] << " ";  
    // }
    // cout << "\n";
}

int main() {
    unsigned int l;
    int input;
    cout << "Enter the number of integers (>=5) to sort:";
    cin >> l;
    vector<int> N_in;
    for(unsigned int i = 0; i<l; i++)
    {
        cin >> input; N_in.push_back(input);
    }

    for(unsigned int i = 0; i < (l-1)/4; i++)
    {
        bool swapped = false;
        for(unsigned int j = 0; j < l - 4*i - 4; j++)
        {
            vector<int> subvector = {N_in.begin()+j, N_in.begin()+j+5};
            vector<int> sub_copy = subvector;
            sort_5(subvector);
            if(subvector != sub_copy)
            {
                swapped = true;
                for(unsigned int x = j; x < j+5; x++)
                {   
                    N_in[x]=subvector[x-j];
                }
            }
            // for(unsigned int i = 0; i < l; i++)
            // {   
            //     cout << N_in[i] << " ";  
            // }
        }
        if(swapped == false)
        {
            break;
        }
    }
    if (((l-1)/4)*4 != l-1)
    {
        vector<int> subvector = {N_in.begin(), N_in.begin()+5};
        sort_5(subvector);
        for(unsigned int x = 0; x < 5; x++)
        {   
            N_in[x]=subvector[x];
        }
    }
    

    for(unsigned int i = 0; i < l; i++)
    {   
        cout << N_in[i] << " ";  
    }
    return 0;
}
