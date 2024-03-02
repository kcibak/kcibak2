
#include <stdio.h>
#include <ctype.h>


int duplicates(int *a, int n);

int main()
{
	int i;
	int n;
	printf("enter the size of the array: ");
	scanf("%d", &n);
	int a[n];
	printf("enter %d array elements: ", n); 
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	int result = duplicates(a, n);
	if(result==1)
		printf("there are duplicates in the array\n"); 
	else
		printf("no duplicates\n"); 
	
	return 0;
}

int duplicates(int *a, int n)
{
    int *p;
    int out;
    p=&a[0];
	for(int i=1; i<n; i++){
	    if(*p==a[i]){
	        out=1;
	        break;
	    }
	    if(i==(n-1))
	        *p=a[i];
	        
        else
            out=0;
	}
	return out;
}