##include <iostream>
using namespace std;

int main() {
    unsigned int n1, n2, n1_c, n2_c, gcd, power_2;

    cout << "Enter two positive integers: ";
    cin >> n1 >> n2;

    n1_c = n1; n2_c = n2;

    gcd = 0; power_2 = 0;

    while(1)
    {
        if(n1 == n2)
        {
            gcd = n1; break;
        }

        if(n1 == 0)
        {
            gcd = n2; break;
        }

        if(n2 == 0)
        {
            gcd = n1; break;
        }

        if (n1>n2)
        {
            n1 += n2;
            n2 = n1 - n2;
            n1 = n1 - n2;
        }

        if((n1/2)*2 == n1)
        {
            if((n2/2)*2 == n2)
            {
                power_2 += 1;
                n2 /= 2;
            }
            n1 /= 2;
        }
        else
        {
            if((n2/2)*2 == n2)
            {
                n2 /= 2;
            }
            else
            {
                n2 -= n1;
            }
        }
    }

    for(unsigned int i = 0; i < power_2; i++)
    {
        gcd*=2;
    }
    cout << gcd;
    return 0;
}
