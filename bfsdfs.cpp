#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b,c,comb=0;
    for (a = 1; a <= 100; a++)
    {
        for (b = 1; b <=100; b++)
        {
            for ( c = 1; c<= 100; c++)
            {
                if (a*a+b*b==c*c)
                {
                    cout<<"the combination is"<<a<<" "<<b<<" "<<c<<"\n";
                    comb++;
                }   
            }   
        }
    }
    cout<<"total combinations are"<<comb;
}
