#include <iostream>
#include <vector>
using namespace std;

void merge_pairs(vector <unsigned long int> &Vs, vector <unsigned long int> &Ve, unsigned int left, unsigned int middle, unsigned int right)
{
    unsigned int left_index = left, right_index = middle + 1; //lenleft = middle - left + 1, lenright = right - middle
    vector <unsigned long int> temp_Vs;
    vector <unsigned long int> temp_Ve;

    while(left_index <= middle && right_index <= right)
    {
        if(Vs[left_index] <= Vs[right_index])
        {
            temp_Vs.push_back(Vs[left_index]); temp_Ve.push_back(Ve[left_index]); left_index++;
        }
        else
        {
            temp_Vs.push_back(Vs[right_index]); temp_Ve.push_back(Ve[right_index]); right_index++;
        }
    }

    while(left_index <= middle)
    {
        temp_Vs.push_back(Vs[left_index]); temp_Ve.push_back(Ve[left_index]); left_index++;
    }
    while(right_index <= right)
    {
        temp_Vs.push_back(Vs[right_index]); temp_Ve.push_back(Ve[right_index]); right_index++;
    }
    for(unsigned int i = left; i <= right; i++)
    {
        Vs[i] = temp_Vs[i-left]; Ve[i] = temp_Ve[i-left]; //cout << temp_Vs[i - left] << " " << temp_Ve[i-left] << endl;
    }
}

void mergeSort_pairs(vector <unsigned long int> &Vs, vector <unsigned long int> &Ve, unsigned int left, unsigned int right)
{
    if(left >= right)
    { return; }
    unsigned int middle = (right+left)/2;
    //cout << "Splitting here: " << middle << endl;
    mergeSort_pairs(Vs, Ve, left, middle);
    mergeSort_pairs(Vs, Ve, 1 + middle, right);
    merge_pairs(Vs, Ve, left, middle, right);
}
int main() {
    unsigned int n,m,i, A_index=0, B_index=0;
    unsigned long int input;
    vector <unsigned long int> As;
    vector <unsigned long int> Bs;
    vector <unsigned long int> Ae;
    vector <unsigned long int> Be;
    vector <unsigned long int> Anss;
    vector <unsigned long int> Anse;
    cin >> n;
    cin >> m;
    for(i = 0; i < n; i++)
    {
        cin >> input; As.push_back(input);
        cin >> input; Ae.push_back(input);
    }
    for(i = 0; i < m; i++)
    {
        cin >> input; Bs.push_back(input);
        cin >> input; Be.push_back(input);
    }
    
    mergeSort_pairs(As,Ae, 0, n-1);
    mergeSort_pairs(Bs,Be, 0, m-1);

    // for(unsigned int i = 0; i < n; i++)
    // {
    //     cout << As[i] << " " << Ae[i] << "\n";
    // }

    // for(unsigned int i = 0; i < m; i++)
    // {
    //     cout << Bs[i] << " " << Be[i] << "\n";
    // }

    As.push_back(Be[m-1]);
    Bs.push_back(Ae[n-1]);

    unsigned long int minim = min(As[0], Bs[0]);
    unsigned long int maxim = max(Ae[n-1], Be[m-1]);

    unsigned long int counter = minim;
    //cout << "Finding intervals \n";
    while(counter < maxim)
    {
        //cout << counter << endl;
        if(A_index < n && counter >= As[A_index])
        {
            //cout << "Jumping to next A interval\n";
            counter=Ae[A_index] + 1;
            while(B_index < m && Be[B_index]<counter)
            {
                B_index+=1;
            }
            A_index+=1;
        }
        else if (B_index < m && counter >= Bs[B_index])
        {
            //cout << "Jumping to next B interval\n";
            counter=Be[B_index] + 1;
            while(A_index < n && Ae[A_index]<counter)
            {
                A_index+=1;
            }
            B_index+=1;
        }
        else
        {
            //cout << "Adding interval to Ans\n";
            Anss.push_back(counter);
            counter = min(As[A_index],Bs[B_index]);
            Anse.push_back(counter - 1);
            //cout << Anss.back() << " " << Anse.back() << endl;
        }
    }

    unsigned int size = Anss.size();
    for(unsigned int i = 0; i < size; i++)
    {
        cout << Anss[i] << " " << Anse[i] << "\n";
    }
}
