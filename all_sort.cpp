//MERGE SORT

/*#include<iostream>
using namespace std;
int merge(int a[],int s,int mid,int e)
{
    int merged[e-s+1];
    int indx1=s;
    int indx2=mid+1;
    int x=0;
    while(indx1<=mid && indx2<=e)
    {
        if(a[indx1]<=a[indx2])
        {
        merged[x]=a[indx1];
        x++;
        indx1++;
        }
        else
        {
        merged[x]=a[indx2];
        x++;
        indx2++;
        }
    }
    while(indx1<=mid)
    {
        merged[x]=a[indx1];
        indx1++;
        x++;
    }
    while(indx2<=e)
    {
        merged[x]=a[indx2];
        indx2++;
        x++;
    }
    for(int i=0,j=s;i<e-s+1;i++,j++)
    {
        a[j]=merged[i];
    }
    return 0;
}
int divide(int a[],int n,int s, int e)
{
    if(s<e)
    {
        int mid=s+(e-s)/2;
        divide(a,n,s,mid);
        divide(a,n,mid+1,e);
        merge(a,s,mid,e);
    }
    return 0;
}
int main()
{
    int a[] = { 7, 5, 8, 6, 0 };
int n = 5;
divide(a, n, 0, 4);
for (int i = 0; i < 5; i++) 
{
    cout<<a[i]<<" ";
}
return 0;
}*/

//QUICK SORT 

/*#include<iostream>
using namespace std;

int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
   
    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return i+1;

}
int quick_sort(int a[],int low, int high)
{
    if(low<high)
    {
        int index=partition(a,low,high);
        quick_sort(a,low,index-1);
        quick_sort(a,index+1,high);
    }
}
int main()
{
    int a[] = { 7, 5, 8, 6, 0 };
    int n = 5;
    quick_sort(a, 0, 4);
    for (int i = 0; i < 5; i++) 
    {
        cout<<a[i]<<" ";
    }
    return 0;
}*/

// COUNTING SORT

#include<iostream>
using namespace std;

// Counting Sort function
void countingSort(int a[], int n) {
    // Find the maximum element in the array
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    // Create a count array to store the frequency of each element
    int count[max + 1] = {0};

    // Store the count of each element
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    // Reconstruct the sorted array
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            a[index++] = i;
            count[i]--;
        }
    }
}

int main() 
{
    int a[] = { 7, 5, 8, 6, 0 };
    int n = sizeof(a) / sizeof(a[0]);

    countingSort(a, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
