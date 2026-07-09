#include<iostream>
using namespace std;
#define MAX 100

int main()
{
    int arr[MAX],n,i,j=0;
    cout<<"Enter number of elements: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        
        cin>>arr[i];
    }

   
    for(i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
           swap(arr[j],arr[i]);
            j++;
        }
    }
    cout<<"Array after moving zeros to the end: ";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;




}