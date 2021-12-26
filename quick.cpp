#include<iostream>
using namespace std;
int partition(int a[],int l,int h){
    int k,i,t,j;
    k=a[l];
    i=l+1;
    j=h;
    while(i<=j){
        while(a[i]<k && i<=h){
            i++;
        }
        while(a[j]>k)
            j--;
        if(i<j){
            t=a[j];
            a[j]=a[i];
            a[i]=t;
            i++;
            j--;
        }
    }
    a[l]=a[j];
    a[j]=k;
    return j;
}

int sort(int a[],int l,int h){
    int p;
    if(l>=h)
    return 0;
    p=partition(a,l,h);
    sort(a,l,p-1);
    sort(a,p+1,h);
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}