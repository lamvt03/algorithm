#include <iostream>

using namespace std;

bool binarySearchByLoop(int arr[], int n, int x);
bool binarySearchByRecursion(int arr[], int left, int right, int x);
void exchangeSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void shakerSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void shellSort(int arr[], int n, int divideBy);
void quickSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
int main()
{
    int arr[] = {4,24,1,13,45,24,4,7,8,16,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int  x = 1;

    //heapSort(arr,n);
    //mergeSort(arr,0,n-1);
    //quickSort(arr,0,n-1);
    //shellSort(arr,n,2);
    //insertionSort(arr,n);
    //selectionSort(arr,n);
    //shakerSort(arr,n);
    //bubbleSort(arr,n);
    // exchangeSort(arr,n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    if(binarySearchByRecursion(arr,0,n-1,x))
        cout << "Co " << x  <<" trong mang\n";
    else cout << "Khong co " << x  <<" trong mang\n";

    return 0 ;
}
bool binarySearchByLoop(int arr[], int n, int x){
    /*Mảng đầu vào đã được sắp xếp tăng dần*/
    int left = 0, right = n-1;
    int mid;
    while(left <= right){
        mid = (left+right)/2;
        //nếu giá trị cần tìm nhỏ hơn giá trị ở giữa thì nó có thể nằm ở bên trái vị trí mid
        if(x < arr[mid])
            right = mid-1

        //nếu giá trị cần tìm lớn hơn giá trị ở giữa thì nó có thể nằm ở bên phải vị trí mid   
        else if(x > arr[mid])
            left = mid+1;
        else if(x == arr[mid])
            return true;
    }
    return false;
}
bool binarySearchByRecursion(int arr[], int left, int right, int x){
    if(left <= right){
        int mid = (left+right)/2;
        if(x == arr[mid])
            return true;
        else if(x < arr[mid])
            return binarySearchByRecursion(arr,left,mid-1,x);
        else if(x > arr[mid])
            return binarySearchByRecursion(arr,mid+1,right,x);
    }
    return false;
}
void exchangeSort(int arr[], int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
}
void bubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++)
    
    //Đẩy giá trị nhỏ nhất lên đầu và không xét vị trí đó nữa
        for(int j = n-1; j>i; j--)
            if(arr[j] < arr[j-1])
                swap(arr[j],arr[j-1]);
}
void shakerSort(int arr[], int n){
    int left = 0, right = n-1;
    int k;
    while(left < right)
    {
        //đẩy giá trị lớn nhất ra cuối mảng và không xét vị trí đó nữa
        for(int i = left; i < right; i++)
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
            k = i;
        }
        right = k; 

        //đẩy giá trị nhỏ nhất lên đầu mảng vào không xét vị trí đó nữa
        for(int i = right; i > left; i--)
            if(arr[i] < arr[i-1]){
                swap(arr[i],arr[i-1]);
                k=i;
            }
        left = k;
    }
    
}
void selectionSort(int arr[], int n){
    int min = 0;
    for(int i = 0; i < n-1; i++)
    {
        min = i;
        //tìm vị trí phần tử nhỏ nhất trong mảng
        for(int j = i+1; j < n; j++)
            if(arr[min] > arr[j])
                min = j;
        
        //nếu vị trí đang xét không là nhỏ nhất thì đổi chỗ với giá trị nhỏ nhất
        //làm tương tự với n-i phần tử còn lại
        if(min != i)
            swap(arr[min],arr[i]);
    }
}
void insertionSort(int arr[], int n){
    int temp, pos;
    //coi mảng bên trái của vị trí đang xét là đã sắp xếp
    for(int i = 1; i < n; i++)
    {
        //gán giá trị của vị trí đang xét
        temp = arr[i];

        //xét mảng bên trái từ phải sang trái
        //nếu có giá trị lớn hơn giá trị của vị trí đang xét thì dời giá trị đó sang phải 1 ô nhớ

        for(pos = i; pos > 0 && temp < arr[pos-1]; pos--)
        {
            arr[pos] = arr[pos-1];
        }

        //ghi đè giá trị của vị trí đang xét vào vị trí còn lại
        arr[pos] = temp;
    }
}
void shellSort(int arr[], int n, int divideBy){
   int i, j, gap;
   /*
        chia mảng thành các mảng "gồm các phần từ cách nhau gap vị trí"
        VD: mảng gồm 10 phần tử
            khi gap = 5, { {0,5}, {1,6}, {2,7}, {3,8}, {4,9} }
            khi gap = 2, { {0,2,4,6,8}, {1,3,5,7,9} }
            khi gap = 1, tương tự insertionSort
   */
   for(gap = n/divideBy; gap >=1; gap /= divideBy)
   {
        for(i = gap; i < n; i++)
        {
            int temp = arr[i], pos;
            for(pos = i-gap; pos>=0 && temp < arr[pos]; pos -= gap)
            {
                arr[pos+gap] = arr[pos];
            }
            arr[pos+gap] = temp;
        }
   }
}
void quickSort(int arr[], int left, int right){
    if(left >= right)
        return;
    int i = left, j = right;

    //pivot: giá trị ở giữa mảng
    int pivot = arr[(left+right)/2];
    while(i <= j)
    {
        //vị trí bên trái pivot phải nhỏ hơn pivot
        while(arr[i] < pivot)
            i++;

        //vị trí bên phải pivot phải lớn hơn pivot
        while(arr[j] > pivot)
            j--;

        if(i <= j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    //phân hoạch 2 mảng con
    quickSort(arr,left,j);
    quickSort(arr,i,right);
}
void merge(int arr[], int left, int mid, int right){
    /*Trộn 2 mảng con đã sắp xếp vào mảng phụ*/
    int i = left, j = mid+1;
    int index = 0;
    int temp[right-left+1];
    while(i <= mid || j <= right){
        if((i <= mid && arr[i] < arr[j]) || j > right)
            temp[index++] = arr[i++];
        else
            temp[index++] = arr[j++];
    }
    //ghi đè mảng phụ vào vị trí phù hợp
    for(int i = 0; i < index; i++)
        arr[left+i] = temp[i];
}
void mergeSort(int arr[], int left, int right){
    if(left >= right)
        return;
    int mid = (left+right)/2;
    //phân hoạch mảng bên trái
    mergeSort(arr,left,mid);

    //phân hoạch mảng bên phải
    mergeSort(arr,mid+1,right);
    
    //trộn 
    merge(arr,left,mid,right);
}
void heapify(int arr[], int n, int i){
    if(i > n/2 -1)
        return;
    
    //node trái và phải của vị trí thứ i
    int left = 2*i + 1, right = 2*i + 2;

    /*node cha phải lớn hơn node con*/
    //tìm vị trí lớn nhất
    int max = left;
    if(right < n && arr[right] > arr[max])
        max = right;

    //nếu vị trí đang xét không phải max
    if(arr[max] > arr[i])
    {
        swap(arr[max], arr[i]);

        //heapify vị trí bị ảnh hưởng
        heapify(arr,n,max);
    }
    
}
void heapSort(int arr[], int n){
    /*
        BUILD HEAP: node cha bất kỳ luôn lớn hơn node con
    */
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr,n,i);

    /*
        Đưa giá trị lớn nhất về cuối
        Sau đó, heapify vị trí thứ 0 với n-1 phần tử
    */
    for(int i = n-1; i >= 0; i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}