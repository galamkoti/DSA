//abccdda deleting consecutive alphabets 
 #include<iostream>
 using namespace std;
 int main()
 {
     char arr[20],i,j;
     int n;
     cin>>n;
     for ( i = 0; i < n; i++)
     {
        cin>>arr[i];
     }
     for ( i = 0; i < n; i++)
     {
         for (  j = i; j <=i+1; j++)
         { 
            if (arr[j]==arr[j+1])
            {
                arr[i]=arr[i+2];
                arr[i+1]=arr[i+3];
            }
              
         }
         
     }
     
    
     
 }