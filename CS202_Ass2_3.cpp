#include <iostream>
#include <vector>

using namespace std;

int main() {
    long int input, n,i,j,k, median, lsize = 0, rsize = 0, x, x_index, pop_index;
    vector <long int> array;
    vector <long int> maxheap;
    vector <long int> minheap;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> input; array.push_back(input);
    }

    median = array[0];
    cout << median << " ";

    for(i = 1; i < n; i++)
    {
        x = array[i];
        // cout << "i = " << i << "  x = " << x << "\n";
        if(x >= median) // Insert right side if new number is greater than or equal to current median
        {
            // cout << "Casting right side\n";
            x_index = rsize;
            rsize++;
            minheap.push_back(x);
            while(x_index > 0 && x < minheap[(x_index - 1)/2])
            {
                minheap[x_index] += minheap[(x_index - 1)/2];
                minheap[(x_index-1)/2] = minheap[x_index] - minheap[(x_index - 1)/2];
                minheap[x_index] -= minheap[(x_index - 1)/2];
                x_index = (x_index - 1)/2;
            }
        }
        else // Insert left side if new number is smaller than current median
        {
            // cout << "Casting left side\n";
            x_index = lsize;
            lsize++;
            maxheap.push_back(x);
            while(x_index > 0 && x > maxheap[(x_index - 1)/2])
            {
                maxheap[x_index] += maxheap[(x_index - 1)/2];
                maxheap[(x_index-1)/2] = maxheap[x_index] - maxheap[(x_index - 1)/2];
                maxheap[x_index] -= maxheap[(x_index - 1)/2];
                x_index = (x_index - 1)/2;
            }
        } 

        // cout << "Casted" << lsize << rsize << "\n" ;

        if(rsize == lsize + 2) // Make minimum of right heap new median
        {
            // cout << "Making right side new median\n";
            x_index = lsize;
            lsize++;
            maxheap.push_back(median);
            while(x_index > 0 && median > maxheap[(x_index - 1)/2])
            {
                maxheap[x_index] += maxheap[(x_index - 1)/2];
                maxheap[(x_index-1)/2] = maxheap[x_index] - maxheap[(x_index - 1)/2];
                maxheap[x_index] -= maxheap[(x_index - 1)/2];
                x_index = (x_index - 1)/2;
            }

            median = minheap[0];

            if(rsize > 1){
            minheap[rsize-1] += minheap[0];
            minheap[0] = minheap[rsize-1] - minheap[0];
            minheap[rsize-1] -= minheap[0];
            }

            rsize--;
            x_index = 0;
            minheap.pop_back();
            while(x_index * 2 + 1 < rsize)
            {
                if(x_index * 2 + 2 == rsize || minheap[x_index * 2 + 1] <= minheap[x_index * 2 + 2] )
                {   pop_index = x_index * 2 + 1;    }
                else
                {   pop_index = x_index * 2 + 2;    }

                if(minheap[x_index] > minheap[pop_index])
                {
                minheap[x_index] += minheap[pop_index];
                minheap[pop_index] = minheap[x_index] - minheap[pop_index];
                minheap[x_index] -= minheap[pop_index];
                x_index = pop_index;
                }
                else
                {   break;  }
            }
        }

        
        else if(rsize == lsize - 1) // Make maximum of left heap new median
        {
            // cout << "Making left side new median\n";
            x_index = rsize;
            rsize++;
            minheap.push_back(median);
            while(x_index > 0 && median < minheap[(x_index - 1)/2])
            {
                minheap[x_index] += minheap[(x_index - 1)/2];
                minheap[(x_index-1)/2] = minheap[x_index] - minheap[(x_index - 1)/2];
                minheap[x_index] -= minheap[(x_index - 1)/2];
                x_index = (x_index - 1)/2;
            }

            median = maxheap[0];

            if(lsize > 1){
            maxheap[lsize-1] += maxheap[0];
            maxheap[0] = maxheap[lsize-1] - maxheap[0];
            maxheap[lsize-1] -= maxheap[0];
            }

            lsize--;
            x_index = 0;
            maxheap.pop_back();
            while(x_index * 2 + 1 < lsize)
            {
                if(x_index * 2 + 2 == lsize || maxheap[x_index * 2 + 1] >= maxheap[x_index * 2 + 2] )
                {   pop_index = x_index * 2 + 1;    }
                else
                {   pop_index = x_index * 2 + 2;    }

                if(maxheap[x_index] < maxheap[pop_index])
                {
                maxheap[x_index] += maxheap[pop_index];
                maxheap[pop_index] = maxheap[x_index] - maxheap[pop_index];
                maxheap[x_index] -= maxheap[pop_index];
                x_index = pop_index;
                }
                else
                {   break;  }
            }
        }
        cout << median << " ";
    }
    return 0;
}