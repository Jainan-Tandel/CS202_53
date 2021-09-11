#include <iostream>
#include <vector>
using namespace std;


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
    As.push_back(Be[m]);
    Bs.push_back(Ae[n]);

    unsigned long int minim = min(As[0], Bs[0]);
    unsigned long int maxim = max(Ae[n-1], Be[m-1]);

    unsigned long int counter = minim;

    while(counter < maxim)
    {
        if(A_index < n && counter >= As[A_index])
        {
            counter=Ae[A_index] + 1;
            if(B_index < m)
            {
                while(Be[B_index]<counter)
                {  
                    B_index+=1;
                }
            }
            A_index+=1;
        }
        else if (B_index < m && counter >= Bs[B_index])
        {
            counter=Be[B_index] + 1;
            if(A_index < n)
            {
                while(Ae[A_index]<counter)
                {
                    A_index+=1;
                }
            }
            B_index+=1;
        }
        else
        {
            Anss.push_back(counter);
            counter = min(As[A_index],Bs[B_index]);
            Anse.push_back(counter - 1);
        }
    }

    unsigned long int size = Anss.size();
    for(unsigned int i = 0; i < size; i++)
    {
        cout << Anss[i] << " " << Anse[i] << "\n";
    }
}
