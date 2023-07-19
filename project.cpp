#include <bits/stdc++.h>

using namespace std;

#define SIZE 500

int main()
{
    int *arr = (int *)malloc(sizeof(int)*SIZE);

    srand(time(0));
    
    for(int i=0; i<SIZE; i++)
    {
        // int s = rand()%2;
        // if (s == 0)
        // {
        //     s = -1;
        // }
        int s = 1;
        arr[i] = rand();
        // cout << arr[i] << " ";
    }
    // arr[0] = {1,2,3,4,5};
    // cout << endl;
    // sort(arr, arr + sizeof(arr)/(2 * sizeof(arr[0])), greater <int>());
    // sort(arr + sizeof(arr)/(2 * sizeof(arr[0])), arr + sizeof(arr)/(sizeof(arr[0])));
    sort(arr, arr + SIZE, [](int a, int b) { return a > b; });
    for(int i=0; i<SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}