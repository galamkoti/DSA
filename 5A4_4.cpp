#include<iostream>
#include<math.h>
using namespace std;
class Hashing_technique
{
    int data_value;
    int size_;
    public:
    void folding_method();
    void truncation_method();
    void modular_method();
};
void Hashing_technique::modular_method()
{
    cout<<"\n give size of the hash table";
    cin>>size_;
    cout<<"\n please give hash key to be hashed";
    cin>>data_value;
    cout<<"\n the hash value in modular_method is";
    cout<<data_value%size_;
}
void Hashing_technique::folding_method()
{
    int partsize;
    cout<<"\n please give size of the Hash table";
    cin>>size_;
    cout<<"\n give hash key to be hashed";
    cin>>data_value;
    cout<<"\n give size of the key in folding_method";
    cin>>partsize;
    int count=0,num=data_value;
    while(num!=0)
    {
        num=num/10;
        count++;
    }
    if(count%partsize!=0)
    {
        cout<<"\n the size of the part is not perfectly divisible by the key value";
    }
    else
    {
        int noofparts=count/partsize;
        cout<<"\n we got"<<noofparts<<"parts";
        int num=data_value;
        int count=0;
        int count1=0;
        int temp=0;
        int sum=0;
        while(num!=0)
        {
            int k=num%10;
            temp=temp+k*pow(10,count);
            count++;
            if(count==partsize)
            {
                cout<<"\n part::"<<temp;
                sum=temp+sum;
                temp=0;
                count=0;
            }
            num=num/10;
            count1++;
        }
        cout<<"\nsumof the parts"<<sum;
        cout<<"\n the hash table generated with folding approch is:";
        cout<<sum%size_<<"\n";
    }
}
void Hashing_technique::truncation_method()
{
     int pos1,pos2;
     cout<<"\n give the size of the hash table";
     cin>>size_;
     cout<<"\n give hash key to be hashed";
        cin>>data_value;
        cout<<"\n choose two options to find the index value:";
        cin>>pos1>>pos2;
        int count=0,num=data_value;
        int sum=0;
        while(num!=0)
        {
            int k=num%10;
            sum=sum*10+k;
            num=num/10;
            count++;
        }
        num=sum;
        sum=0;count=1;
        while(num!=0)
        {
            int k=num%10;
            if((pos1==count)||(pos2==count))
            sum=sum*10+k;
            num=num/10;
            count++;
        }
}
int main()
{
    int k;
    Hashing_technique h1;
    while(true)
    {
        cout<<"\n choose an option:";
        cout<<"\n1.folding method\n2.Truncation method\n3.modular arthmetic\n4.exit\n";
        cin>>k;
        switch(k)
        {
            case 1:h1.folding_method();
            break;
            case 2:h1.truncation_method();
            break;
            case 3:h1.modular_method();
            break;
            case 4:exit(0);
        }
    }
}