#include<stdio.h>
#include<stdlib.h>
struct arrayADT* createArray(int capacity);
int setItem(struct arrayADT *arr,int index,int value);
int getItem(struct arrayADT *arr,int index);
int editItem(struct arrayADT *arr,int index,int new_value);
int countItem(struct arrayADT *arr);
int removeItem(struct arrayADT *arr,int index);
int search(struct arrayADT *arr,int item);
void sort(struct arrayADT *arr);
struct arrayADT{
	int capacity,lastIndex;
	int *ptr;
};
struct arrayADT* createArray(int capacity){
	struct arrayADT *arr;
	arr=(struct arrayADT*)malloc(sizeof(struct arrayADT));
	arr->capacity=capacity;
	arr->lastIndex=-1;
	arr->ptr=(int *)malloc(arr->capacity*sizeof(int));
	return(arr);
}
int setItem(struct arrayADT *arr,int index,int value){
	if(index<0||index>arr->lastIndex+1)
	{
	printf("Invalid index");
	return(0);
    }
	if(index==arr->lastIndex+1)
	{
	arr->lastIndex++;
	arr->ptr[index]=value;
	return(1);
    }
	if(index<arr->lastIndex)
	{
		int i;
		arr->lastIndex++;
		for( i=0;i<index;i++)
		arr->ptr[arr->lastIndex-i]=arr->ptr[arr->lastIndex-i-1];
		arr->ptr[index=value];
		return(1);
	}
	if(arr->lastIndex==arr->capacity-1)
	{
		printf("Overflow");
		return(0);
	}
}
int getItem(struct arrayADT *arr,int index){
	if(index>arr->lastIndex||index<0)
	{
		printf("Invalid Index");
		return(0);
	}
	else
	{	return(arr->ptr[index]);	}
}
int editItem(struct arrayADT *arr,int index,int new_value){
	if(index<0||index>arr->lastIndex)
	{
		printf("Invalid index");
		return(0);
	}
	else
	{
		arr->ptr[index=new_value];
		return(1);
	}
}
int countItem(struct arrayADT *arr){
	return(arr->lastIndex+1);
}
int removeItem(struct arrayADT *arr,int index){
	if(index<0||index>arr->lastIndex){
		printf("Invalid index");
		return(0);
	}
	if(index<arr->lastIndex)
	{
		int i;
	 for( i=0;i<arr->lastIndex-index;i++)
	 arr->ptr[index+i]=arr->ptr[index+i+1];
	 arr->lastIndex--;
	}
	if(index==arr->lastIndex)
	{
		arr->lastIndex--;
		return(1);
	}
}
int search(struct arrayADT *arr,int item){
	int i;
	if(arr->lastIndex==-1)
	return(-1);
	for(i=0;i<=arr->lastIndex;i++)
	if(arr->ptr[i]==item)
	return (i);
	return(-1);
}
void sort(struct arrayADT *arr){
int n,r,i,t;
n=arr->lastIndex+1;
for(r=0;r<n;r++)
{
	for(i=0;i<n-1-r;i++)
	{
		if(arr->ptr[i]>arr->ptr[i+1])
		{
			t=arr->ptr[i];
			arr->ptr[i]=arr->ptr[i+1];
			arr->ptr[i+1]=t;
		}
	}
}
}
void main()
{
	int i;
	struct arrayADT *arr;
	arr=createArray(6);
	setItem(arr,0,4);
	setItem(arr,1,3);
	setItem(arr,2,9);
	setItem(arr,3,7);
	setItem(arr,4,2);
	removeItem(arr,1);
	printf("%d\n",getItem(arr,2));
	for( i=0;i<=arr->lastIndex;i++)
	printf("%d\t",getItem(arr,i));
	printf("\n");
	sort(arr);
	for( i=0;i<=arr->lastIndex;i++)
	printf("%d\t",getItem(arr,i));
}
