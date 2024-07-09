#include"Ass.h"


char Iterative_Linear_search(int *arr,int size,int numb)
{
    int i=0;
    char flag=0;
    for(i=0; i<size; i++)
    {
        if(arr[i]==numb)
        {
            flag=1;
            break;
        }
    }
    return flag;
}
char Recurise_Linear_search(int *arr,int size,int numb)
{
    static int i=0;
    if(arr[i]==numb)
    {
        return 1;
    }
    else
    {
        if(i<(size-1))
        {
            i++;
        }
        else
        {
            return 0;
        }

        Recurise_Linear_search(arr,size,numb);
    }
}
char Iterative_Binary_search(int *arr,int size,int numb)
{
    int First=0,Last=size-1,Middle;
    char flag=0;
    while(Last>=First)
    {
        Middle=(First+Last)/2;
        if(arr[Middle]==numb)
        {
            flag=1;
            break;
        }
        else if(arr[Middle]>numb)
        {
            Last=Middle-1;
        }
        else
        {
            First=Middle+1;
        }
    }
    return flag;
}

char Recurise_Binary_search(int *arr,int size,int numb)
{
    static int First=0,Last=0,Middle=0;
    static int flag=0;
    if(flag==0)
    {
        Last=size-1;
        flag=1;
    }
    Middle=(First+Last)/2;
    if(arr[Middle]==numb)
    {
        return 1;
    }
    else if(arr[Middle]>numb)
    {
        Last=Middle-1;
        if(Last<First)
        {
            return 0;
        }
        Recurise_Binary_search(arr,size,numb);
    }
    else
    {
        First=Middle+1;
        if(Last<First)
        {
            return 0;
        }
        Recurise_Binary_search(arr,size,numb);
    }

}
void Bubble_Sort(int *arr,int Size)
{
    int temp;
    char flag;
    for(int i=0; i<Size; i++)
    {
        flag=0;
        for(int j=0; j<Size-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}
void Selection_Sort(int *arr,int Size)
{
    int last=Size-1,max;
    char temp;
    for(int i=0; i<Size; i++)
    {
        max=0;
        for(int j=0; j<Size-i; j++)
        {
            if(arr[max]<arr[j])
            {
                max=j;
            }
        }
        temp=arr[max];
        arr[max]=arr[last];
        arr[last]=temp;
        last--;
    }
}
void Merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;

    j = 0;


    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// l is first index in array
// r is last index in array (size-1)
void Merge_Sort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        Merge_Sort(arr, l, m);
        Merge_Sort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}
void Insertion_Sort(int *arr,int Size)
{
    int i, key, j;
    for (i = 1; i < Size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int Size)
{
    int i;
    for (i = 0; i < Size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


