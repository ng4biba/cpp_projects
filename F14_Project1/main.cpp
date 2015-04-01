#include <iostream>
#include <fstream>
using namespace std;


void printArray(int [], int ); // print the array
void insertionSort(int [], int);
void selectionSort(int [], int);
void quickSort(int[], int);
void recQuickSort(int [], int, int);
int partition(int [], int, int);
void swap(int[], int, int);
void heapSort(int[], int, int);
void heapDown(int [],int,int);
void mergeSort(int[], int, int);
void merge( int [], int, int, int, int);
void shellSort(int [], int);
void getIntegers(int[], int n, string); // read integer from the files
void writeCount(int&, int&, string, string); // open a file write the count for comparison and swaps
void copyArray(int [], int[], int); // copy the array into a temp array
int compCounter = 0, swapCounter = 0; // variables to hold the count comparisons and swaps


int main()
{
    
    int rand100[100];
    int rand1000[1000];
    int inv100[100];
    int inv1000[1000];
    int alm100[100];
    int alm1000[1000];
    int temp100[100];
    int temp1000[1000];
    
    getIntegers(rand100, 100, "Random100.txt");
    getIntegers(rand1000, 1000, "Random1000.txt");
    getIntegers(inv100, 100, "Inverse100.txt");
    getIntegers(inv1000, 1000, "Inverse1000.txt");
    getIntegers(alm100, 100, "Almost100.txt");
    getIntegers(alm1000, 1000, "Almost1000.txt");
    
    //********************** Selection Sort******************************************************
    cout<<"\n--------------------------- Selection Sort------------------------------------- \n\n";
    cout<<" 100 Random integers before sorting :"<<endl<<endl;
    printArray(rand100, 100);
    copyArray(temp100,rand100, 100);
    selectionSort(temp100, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Selection Sort 100 Random", "counterSummary.txt");
    
    cout<<" 1000 Random integers before sorting :"<<endl<<endl;
    printArray(rand1000, 1000);
    copyArray(temp1000,rand1000, 1000);
    selectionSort(temp1000, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Selection Sort 1000 Random", "counterSummary.txt");
    
    cout<<" 100 integers sorted in opposite order – descending :"<<endl<<endl;
    printArray(inv100, 100);
    copyArray(temp100, inv100, 100);
    selectionSort(temp100, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Selection Sort 100 opposite order", "counterSummary.txt");
    
    cout<<" 1000 integers sorted in opposite order – descending :"<<endl<<endl;
    printArray(inv1000, 1000);
    copyArray(temp1000, inv1000, 1000);
    selectionSort(temp1000, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Selection Sort 1000 opposite order", "counterSummary.txt");
    
    cout<<" 100 integers almost in order:"<<endl<<endl;
    printArray(alm100, 100);
    copyArray(temp100, alm100, 100);
    selectionSort(temp100, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Selection Sort 100 almost order", "counterSummary.txt");
    
    cout<<" 1000 integers almost in order:"<<endl<<endl;
    printArray(alm1000, 1000);
    copyArray(temp1000, alm1000, 1000);
    selectionSort(temp1000, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Selection Sort 1000 almost order", "counterSummary.txt");
    
    //********************** Insertion Sort******************************************************
    cout<<"\n--------------------------- Insertion Sort-----------------------------------------\n\n";
    cout<<" 100 Random integers before sorting :"<<endl<<endl;
    printArray(rand100, 100);
    copyArray(temp100,rand100, 100);
    insertionSort(temp100, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Insertion Sort 100 random", "counterSummary.txt");
    
    cout<<" 1000 Random integers before sorting :"<<endl<<endl;
    printArray(rand1000, 1000);
    copyArray(temp1000,rand1000, 1000);
    insertionSort(temp1000, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Insertion Sort 1000 random", "counterSummary.txt");
    
    cout<<" 100 integers sorted in opposite order – descending :"<<endl<<endl;
    printArray(inv100, 100);
    copyArray(temp100, inv100, 100);
    insertionSort(temp100, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Insertion Sort 100 opposite order", "counterSummary.txt");
    
    cout<<" 1000 integers sorted in opposite order – descending :"<<endl<<endl;
    printArray(inv1000, 1000);
    copyArray(temp1000, inv1000, 1000);
    insertionSort(temp1000, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Insertion Sort 1000 opposite order", "counterSummary.txt");
    
    cout<<" 100 integers almost in order:"<<endl<<endl;
    printArray(alm100, 100);
    copyArray(temp100, alm100, 100);
    insertionSort(temp100, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Insertion Sort 100 almost order", "counterSummary.txt");
    
    cout<<" 1000 integers almost in order:"<<endl<<endl;
    printArray(alm1000, 1000);
    copyArray(temp1000, alm1000, 1000);
    insertionSort(temp1000, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Insertion Sort 1000 almost order", "counterSummary.txt");
    
    //********************** Quick Sort******************************************************
    cout<<"\n--------------------------- Quick Sort----------------------------------\n\n";
    cout<<" 100 Random integers before sorting :"<<endl<<endl;
    printArray(rand100, 100);
    copyArray(temp100,rand100, 100);
    quickSort(temp100, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Quick Sort 100 random ", "counterSummary.txt");
    
    cout<<" 1000 Random integers before sorting :"<<endl<<endl;
    printArray(rand1000, 1000);
    copyArray(temp1000,rand1000, 1000);
    quickSort(temp1000, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Quick Sort 1000 random ", "counterSummary.txt");
    
    cout<<" 100 integers sorted in opposite order – descending :"<<endl<<endl;
    printArray(inv100, 100);
    copyArray(temp100, inv100, 100);
    quickSort(temp100, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Quick Sort 100 opposite order ", "counterSummary.txt");
    
    cout<<" 1000 integers sorted in opposite order – descending :"<<endl<<endl;
    printArray(inv1000, 1000);
    copyArray(temp1000, inv1000, 1000);
    quickSort(temp1000, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Quick Sort 1000 opposite order ", "counterSummary.txt");
    
    cout<<" 100 integers almost in order:"<<endl<<endl;
    printArray(alm100, 100);
    copyArray(temp100, alm100, 100);
    quickSort(temp100, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Quick Sort 100 almost order ", "counterSummary.txt");
    
    cout<<" 1000 integers almost in order:"<<endl<<endl;
    printArray(alm1000, 1000);
    copyArray(temp1000, alm1000, 1000);
    quickSort(temp1000, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Quick Sort 1000 almost order ", "counterSummary.txt");
    
    //********************** Merge Sort******************************************************
    cout<<"\n--------------------------- Merge Sort----------------------------------\n\n";
    cout<<" 100 Random integers before sorting :"<<endl<<endl;
    printArray(rand100, 100);
    copyArray(temp100,rand100, 100);
    mergeSort(temp100, 0, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Merge Sort 100 random ", "counterSummary.txt");
    
    cout<<" 1000 Random integers before sorting :"<<endl<<endl;
    printArray(rand1000, 1000);
    copyArray(temp1000,rand1000, 1000);
    mergeSort(temp1000, 0, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Merge Sort 1000 random ", "counterSummary.txt");
    
    cout<<" 100 integers sorted in opposite order – descending :"<<endl<<endl;
    printArray(inv100, 100);
    copyArray(temp100, inv100, 100);
    mergeSort(temp100, 0, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Merge Sort 100 opposite order ", "counterSummary.txt");
    
    cout<<" 1000 integers sorted in opposite order – descending :"<<endl<<endl;
    printArray(inv1000, 1000);
    copyArray(temp1000, inv1000, 1000);
    mergeSort(temp1000, 0, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Merge Sort 1000 opposite order ", "counterSummary.txt");
    
    cout<<" 100 integers almost in order:"<<endl<<endl;
    printArray(alm100, 100);
    copyArray(temp100, alm100, 100);
    mergeSort(temp100, 0, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Merge Sort 100 almost order ", "counterSummary.txt");
    
    cout<<" 1000 integers almost in order:"<<endl<<endl;
    printArray(alm1000, 1000);
    copyArray(temp1000, alm1000, 1000);
    mergeSort(temp1000, 0, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Merge Sort 1000 almost order ", "counterSummary.txt");
    
    //********************** Heap Sort******************************************************
    cout<<"\n--------------------------- Heap Sort----------------------------------\n\n";
    cout<<" 100 Random integers before sorting :"<<endl<<endl;
    printArray(rand100, 100);
    copyArray(temp100,rand100, 100);
    heapSort(temp100, 0, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Heap Sort 100 random ", "counterSummary.txt");
    
    cout<<" 1000 Random integers before sorting :"<<endl<<endl;
    printArray(rand1000, 1000);
    copyArray(temp1000,rand1000, 1000);
    heapSort(temp1000, 0, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Heap Sort 1000 random ", "counterSummary.txt");
    
    cout<<" 100 integers sorted in opposite order – descending :"<<endl<<endl;
    printArray(inv100, 100);
    copyArray(temp100, inv100, 100);
    heapSort(temp100, 0, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Heap Sort 100 opposite order ", "counterSummary.txt");
    
    cout<<" 1000 integers sorted in opposite order – descending :"<<endl<<endl;
    printArray(inv1000, 1000);
    copyArray(temp1000, inv1000, 1000);
    heapSort(temp1000, 0, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Heap Sort 1000 opposite order ", "counterSummary.txt");
    
    cout<<" 100 integers almost in order:"<<endl<<endl;
    printArray(alm100, 100);
    copyArray(temp100, alm100, 100);
    heapSort(temp100, 0, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Heap Sort 100 almost order ", "counterSummary.txt");
    
    cout<<" 1000 integers almost in order:"<<endl<<endl;
    printArray(alm1000, 1000);
    copyArray(temp1000, alm1000, 1000);
    heapSort(temp1000, 0, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Heap Sort 1000 almost order ", "counterSummary.txt");
    
    //********************** Shell Sort******************************************************
    cout<<"\n--------------------------- Shell Sort------------------------------------- \n\n";
    cout<<" 100 Random integers before sorting :"<<endl<<endl;
    printArray(rand100, 100);
    copyArray(temp100,rand100, 100);
    shellSort(temp100, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Shell Sort 100 random ", "counterSummary.txt");
    
    cout<<" 1000 Random integers before sorting :"<<endl<<endl;
    printArray(rand1000, 1000);
    copyArray(temp1000,rand1000, 1000);
    shellSort(temp1000, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Shell Sort 1000 random ", "counterSummary.txt");
    
    cout<<" 100 integers sorted in opposite order – descending :"<<endl<<endl;
    printArray(inv100, 100);
    copyArray(temp100, inv100, 100);
    shellSort(temp100, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Shell Sort 100 opposite order ", "counterSummary.txt");
    
    cout<<" 1000 integers sorted in opposite order – descending :"<<endl<<endl;
    printArray(inv1000, 1000);
    copyArray(temp1000, inv1000, 1000);
    shellSort(temp1000, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Shell Sort 1000 opposite order ", "counterSummary.txt");
    
    cout<<" 100 integers almost in order:"<<endl<<endl;
    printArray(alm100, 100);
    copyArray(temp100, alm100, 100);
    shellSort(temp100, 100);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp100, 100);
    writeCount(compCounter, swapCounter, "Shell Sort 100 almost order ", "counterSummary.txt");
    
    cout<<" 1000 integers almost in order:"<<endl<<endl;
    printArray(alm1000, 1000);
    copyArray(temp1000, alm1000, 1000);
    shellSort(temp1000, 1000);
    cout<<" After sorting :"<<endl<<endl;
    printArray(temp1000, 1000);
    writeCount(compCounter, swapCounter, "Shell Sort 1000 almost order ", "counterSummary.txt");
    
    
    
    return 0;
}

void printArray(int array[], int size )
{
    for (int i= 0; i<size;i++)
        cout<<array[i]<<" ";
    cout<<endl<<endl;
}
void selectionSort(int arr[], int size)
{
    int i, j, minIndex, tmp;
    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < size; j++)
        {
            compCounter++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
            
        }
        if (minIndex != i)
        {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
            swapCounter++;
        }
    }
}

void insertionSort(int arr[], int size)
{
    int key ;
    for (int j = 1 ; j <size ; j++)
    {
        key = arr[j] ;
        int i = j - 1 ;
        while (i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i] ;
            i-- ;
            compCounter++;
        }
        arr[i+1] = key ;
        swapCounter++;
    }
}

void quickSort(int arr[], int size)
{
    recQuickSort(arr, 0, size -1);
}
void recQuickSort(int arr[], int first, int last)
{
    int pivotLocation;
    if (first < last)
    {
        pivotLocation = partition(arr, first, last);
        recQuickSort(arr, first, pivotLocation - 1);
        recQuickSort(arr, pivotLocation + 1, last);
    }
}
int partition(int arr[], int first, int last)
{
    int pivot;
    int index, smallIndex;
    swap(arr, first, (first + last) / 2);
    swapCounter++;
    pivot = arr[first];
    smallIndex = first;
    for (index = first + 1; index <= last; index++)
        if (arr[index]<pivot)
        {
            compCounter++;
            smallIndex++;
            swap(arr, smallIndex, index);
            swapCounter++;
        }
    swap(arr, first, smallIndex);
    swapCounter++;
    return smallIndex;
}
void swap(int arr[], int first, int second)
{
    int temp;
    temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

void heapSort(int arr[], int root, int last)
{
    //build the heap
    for(int i=(last /2 -1);i>=0;i--)
        heapDown(arr,i,last-1);
    // sort
    for(int i=(last-1);i>=1;i--)
    {
        swap(arr,0,i);
        swapCounter++;
        heapDown(arr,0,i-1);
    }
}

void heapDown(int A[], int root, int last)
{
    int temp=A[root];
    int large=2*root+1;
    while(large<=last)
    {
        compCounter++;
        if(large<last)
            if(A[large]<A[large+1])
            {
                large=large+1;
                compCounter++;
            }
        if(temp>A[large])
            break;
        else
        {
            A[root]=A[large];
            root=large;
            large=2*root+1;
            compCounter++;
            swapCounter++;
        }
    }
    A[root]=temp;
}

void mergeSort(int arr[], int first, int last)
{
    if(first<last)
    {
        int middle=(first+last)/2;
        mergeSort(arr, first, middle);
        mergeSort(arr, middle+1, last);
        merge(arr, first, middle, middle + 1, last);
    }
}

void merge( int arr[], int firstL, int lastL, int firstR, int lastR)
{
    int *X;
    X= new int [lastR];
    int save = firstL;
    int i= firstL;
    while(firstL<=lastL && firstR<=lastR)
    {
        compCounter++;
        if(arr[firstL]<arr[firstR])
        {
            X[i++]=arr[firstL++];
            swapCounter++;
        }
        else
        {
            X [i++]=arr[firstR++];
            swapCounter++;
        }
    }
    while(firstL<=lastL)
    {
        X[i++] = arr[firstL++];
        swapCounter++;
    }
    while(firstR<=lastR)
    {
        X[i++] = arr[firstR++];
        swapCounter++;
    }
    for(int j= save;j<=lastR;j++)
    {
        arr[j] = X[j];
        swapCounter++;
    }
}

void shellSort(int arr[], int size)
{
    for (int gap = size / 2; gap >= 1; gap = gap / 2)
    {
        // insertion sort on every gap'th element
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
                swapCounter++;
                compCounter++;
            }
            arr[j] = temp;
            swapCounter++;
        }
    }
}

void getIntegers(int arr [], int size, string fileName)
{
    ifstream integerFile;
    integerFile.open(fileName);
    for( int i =0; i<size;i++ )
    {
        //assert(integerFile);
        integerFile>>arr[i];
    }
    integerFile.close();
}
void writeCount(int &counts, int &swaps, string sortType, string fileName)
{
    ofstream fileCounter;
    fileCounter.open(fileName, ios_base::app);
    fileCounter<<"-----------------------"<< sortType<<"--------------------------"<<endl;
    fileCounter<<" Total comparison is :"<<counts<<"\t\t"<<" Total swaps is :"<<swaps<<endl<<endl;
    fileCounter.close();
    counts = 0;
    swaps = 0;
}

void copyArray(int arr1 [], int arr2 [], int size)
{
    for (int i = 0; i < size; i++)
        arr1[i] = arr2[i];
    
}
