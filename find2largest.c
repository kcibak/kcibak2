#include <stdio.h>
#define N 10

void find_two_largest(int arr[], int n, int *largest, int *second_largest);
//find the largest and the second largest value in an array

int main()
{
    int i, max, second_max;
    int a[N];
    printf("Enter %d elements for the arary: ", N);
    for(i=0;i<N;i++)
        scanf("%d", &a[i]);
    find_two_largest(a, N, &max, &second_max);
    printf("the largest value is: %d and the second largest is: %d\n", max,second_max);
    return 0;
}

void find_two_largest(int arr[], int n, int *largest, int *second_largest)
{
    int max=arr[0], max2=arr[1];
    int temp;
    
    if(max<max2){
        temp=max;
        max=max2;
        max2=temp;
    }
    
    for(int i=2; i<n; i++){
        if(arr[i]>max){
            max2=max;
            max=arr[i];
        }
        if((arr[i]>max2) && (arr[i]<max)){
            max2=arr[i];
        }
            
    }
    *largest=max;
    *second_largest=max2;
}