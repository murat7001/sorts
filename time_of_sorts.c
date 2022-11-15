#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<time.h>


void instruction();
void randomSayi(int *array,int first,int last);
void insertion(int *array,int size);
void selection(int *array,int size);
void quick(int *array,int first, int size);
void bubble(int *array,int size);
void merge_sort(int *array, int left, int right,int size);
void merge(int *array,int left , int mid, int right,int size);
void heapSort(int *array,int size);
void heapify(int *array, int size, int i);
void print(int *array,int size);

int main(){
    int *array;
    int size,choice=0;
    printf("Please enter the size:");
    scanf("%d",&size);
    array=malloc(sizeof(int)*size);
    randomSayi(array,0,size);
    //print(array,size);
    instruction();
    scanf("%d",&choice);
    clock_t t=clock();
    switch(choice){
        case 1:
            insertion(array,size);
            break;
        case 2:
            
            selection(array,size);
            break;
        case 3:
            quick(array,0,size);
            break;
        case 4:
            bubble(array,size);
            break;
        case 5:
            merge_sort(array,0,size,size);
            break;
        case 6:
            heapSort(array,size);
            break;
        case 7:
            break;
    }
    t=clock()-t;
    double a=(double)(t)/CLOCKS_PER_SEC;
    printf("The running time of sorting is= %f\n",a);
    //print(array,size);
    free(array);
}

void randomSayi(int *array,int first,int size){

    //srand(time(0));
    for (int i = 0; i < size; i++)
    {
        int k=abs((rand()*rand())%(size+1));
        array[i]=k;
    }
}

void insertion(int*array,int size){
    int key,j,i;
    for (i = 1; i < size; i++)
    {
        key=array[i];
        for (j = i-1; j >=0 && key<= array[j] ; j--)
        {
            array[j+1]=array[j];
        }
        array[j+1]=key;
    }
}

void selection(int *array,int size){
    int i, minindex, j;
    for (i = 0; i < (size-1); i++) {
        minindex = size-1;
        for (j = i; j < (size-1); j++){
            if (array[j] < array[minindex]){
            minindex = j;
        }
    }
        if (i != minindex){//swap
            int temp=array[i];
            array[i]=array[minindex];
            array[minindex]=temp;
        }
}   
}

void quick(int *array,int first, int size){
    int i=first;
    int j=size;
    int pivot=array[(first+size)/2];
    int temp;

    do
    {
        while (array[i]<pivot)
        {
            i++;
        }
        while (array[j]>pivot)
        {
            j--;
        }
        if (i<=j)
        {
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
            i++;
            j--;
        }
    } while (i<j);
    if (i<size)
    {
        quick(array,i,size);
    }
    if (first<j)
    {
        quick(array,first,j);
    }
    
}

void bubble(int *array,int size){
    int temp, k, i; 
    for (i = 0; i < (size-1); i++){
        for (k = 0; k < (size-1-i); k++){
            if (array[k] > array[k+1]){ 
                temp = array[k];    
                array[k] = array[k+1];
                array[k+1] = temp; 
            }
        }
    }
}

void merge_sort(int *array, int left, int right,int size){
    int mid;
    if(left<right){
        mid=(left+right)/2;
        merge_sort(array,left,mid,size);
        merge_sort(array,mid+1,right,size);
        merge(array,left,mid,right,size);
    }
}

void merge(int *array,int left , int mid, int right,int size){
    int i,j,index=0;
    int *tempArr=(int*)malloc(sizeof(int)*size);
    for(i=left,j=mid+1;(i<=mid) && (j<=right);){
        if(array[i]<array[j]){
            tempArr[index]=array[i];
            i++;
            index++;
        }
        else{
            tempArr[index]=array[j];
            j++;
            index++;
        }
    }
    
    while(i<=mid){
        tempArr[index]=array[i];
        i++;
        index++;
    }

    while(j<=right){
        tempArr[index]=array[j];
        j++;
        index++;
    }
    //Copying tempArr to Original array
    for(i=left,index=0 ; i<=right ; i++,index++)
        
        array[i]=tempArr[index];

    free(tempArr);
    
}

void heapify(int *array, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;
    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(array, size, largest);
    }
}

void heapSort(int *array, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
    for (int i = size - 1; i >= 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
}

void print(int *array,int size){
    for(int i=0;i<size;i++){
        printf("%d\t",array[i]);
    }
}

void instruction(){
    printf("\nPlease enter 1 to Checking running time of insertion sort.\nPlease enter 2 to Checking running time of selection sort.\nPlease enter 3 to Checking running time oaf quick sort.\nPlease enter 4 to Checking running time of bubble sort.\nPlease enter 5 to Checking running time of merge sort.\nPlease enter 6 to Checking running time of heap sort.\nPlease enter 7 for exit.\nYour answer:");
    
}