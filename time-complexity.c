#include<stdio.h>
#include<time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void merge(int a[], int l, int m, int r)
{
    int i, j, k, n1=m-l+1, n2=r-m;
	int Left[n1], Right[n2];
    for (i=0;i<n1;i++)
       {
		Left[i] = a[l+i];
	   }
    for (j=0;j<n2;j++)
        {
		Right[j] = a[m+1+j];
        }
    
    i = 0,j=0,k=l; 
    while (i<n1 && j<n2)
    {
        if (Left[i]<=Right[j])
        {
            a[k] = Left[i];
            i++;
        }
        else
        {
            a[k] = Right[j];
            j++;
        }
        k++;
    }
 
    while (i<n1)
    {
        a[k] = Left[i];
        i++;
        k++;
    }
     while (j<n2)
    {
        a[k] = Right[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r)
{
    if(l<r)
    {
        int m;
		m = l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}
int partition (int arr[], int low, int high)
{
    int j, pivot = arr[high], i = (low - 1); 
 
    for (j = low; j <= high- 1; j++)
    {
       
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
       
        int pi = partition(arr, low, high);
 		quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void main()
{
int c,d,swap,ch,i,j,min_i;
time_t start,end;
double tc;
int n;
srand(time(NULL));
printf("\nenter total elements\n");
scanf("%d",&n);
int a[n];

while(1){
printf("Enter choice\n1.Bubble sort\n2.Merge sort\n3.Insertion sort\n4.Selection sort\n5.Quick sort\n");
scanf("%d",&ch);
switch(ch){
	case 1:for(c=n-1;c>=0;c--)
{
a[c]=rand();
}
	start=clock();
for(c=0;c<n-1;c++)
{
for(d=0;d<n-c-1;d++)
{
if(a[d]>a[d+1])
{
swap=a[d];
a[d]=a[d+1];
a[d+1]=swap;
}
}
}
end=clock();
tc=(difftime(end,start)/CLOCKS_PER_SEC);
printf("time efficiency is %lf",tc);
break;

case 2:for(c=n-1;c>=0;c--)
{
a[c]=rand();
}
start=clock();
mergeSort(a, 0, n - 1);
end=clock();
tc=(difftime(end,start)/CLK_TCK);
printf("time efficiency is %lf",tc);
break;

case 3:for(c=n-1;c>=0;c--)
{
a[c]=rand();
}
start=clock();

for(i=1;i<n;i++)
{
min_i = a[i];
j=i-1;
while (a[j] > min_i && j>=0)
{
a[j+1]=a[j];
j--;
}
a[j+1]=min_i;
}
end=clock();
tc=(difftime(end,start)/CLK_TCK);
printf("time efficiency is %lf",tc);
break;
case 4:for(c=n-1;c>=0;c--)
{
a[c]=rand();
}
start=clock();

	for(i=0;i<n-1;i++)
	{
		min_i = i;
        for (j = i+1; j < n; j++)
          {
		  if (a[j] < a[min_i])
            min_i = j;
       }
       
        int temp=a[min_i];
a[min_i]=a[i];
a[i]=temp;
}
end=clock();
tc=(difftime(end,start)/CLOCKS_PER_SEC);
printf("time efficiency is %lf",tc);
break;
case 5:for(c=n-1;c>=0;c--)
{
a[c]=rand();
}
start=clock();
quickSort(a, 0, n-1);
end=clock();
tc=(difftime(end,start)/CLOCKS_PER_SEC);
printf("time efficiency is %lf",tc);
break;
}
}
}

