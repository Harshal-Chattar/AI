#include<iostream>
using namespace std;

int arr[10];
void Selection(int n)
{
    int min, index;
    for(int i=0; i<n-1; i++)
    {
        min = arr[i];
        index = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        swap(arr[i],arr[index]);
    }
    cout << "After Using selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    cout<<"Enter How Many Numbers in Array: ";
    cin>>n;
    cout<<"\nEnter elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    Selection(n);
}