#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int partition(int a[],int low,int high)
{
    int i,j,key,temp;
    key = a[low];
    i=low+1;
    j=high;
    while(1)
    {
        while(i<high && key>=a[i])
            i++;
        while(a[j]>key)
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            temp=a[low];
            a[low]=a[j];
            a[j]=temp;

            return j;
        }
        
    }
}
int quicksort(int a[],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
int main()
{
    int i,n,a[100];
    float start,end,timetaken;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=rand();
        printf("%d  ",a[i]);
    }
    start = clock();
    quicksort(a,0,n-1);
    end = clock();
    printf("\nThe sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
    printf("\nTotal time taken to sort the array is %f",(end-start)/CLOCKS_PER_SEC);
}
