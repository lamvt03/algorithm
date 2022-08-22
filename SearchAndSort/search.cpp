#include <iostream>

using namespace std;

// tìm kiếm nhị phân - phần từ đầu tiên có giá trị x
int binarySearch1(int arr[], int n, int x){
    int l = 0, r = n-1;
    while(l < r){
        int mid = (l+r)/2;
        if(x > arr[mid])
            l = mid + 1;
        else
            r = mid;
    }
    if(arr[l] == x)
        return l;
    return -1;
}
// tìm kiếm nhị phân - phần từ cuối cùng có giá trị x
int binarySearch2(int arr[], int n, int x){
    int l = 0, r = n-1;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if(x > arr[mid])
            l = mid+1;
        else if (x < arr[mid])
            r = mid-1;
        else{
            if(mid >= 0 && mid+1 < n && arr[mid+1] == x)
                l = mid+1;
            else
                return mid;
        }

    }
    
    return -1;
}
int interpolationSearch(int arr[], int n, int x){
    int l = 0, r = n-1;

    /** Trường hợp mảng có 1 phần tử và phần tử đó là giá trị cần tìm */
    if(l == r && arr[l] == x)
        return l;

    /**
     * arr[r] != arr[l] : tránh trường hợp chia cho 0
     * arr[l] <= x <= arr[r]: giá trị cần tìm phải nằm trong khoảng của mảng
     */
    while(arr[r] != arr[l] && x >= arr[l] && x <= arr[r]){
        /** Công thức nội suy tuyến tính
         * y = a*x + b (y: giá trị của phần tử mảng, x: chỉ số mảng tương ứng)
         * arr[l] = a*l + b (1)
         * arr[r] = a*r + b (2)
         * x = a*pos + b (3)
         * Từ (1) và (2) => a = (arr[r] - arr[l])/(r - l)
         * Từ (1) và (3) => pos = l + (r-l)*(x-arr[l])/(arr[r]-arr[l])
         */
        int pos = l + (r-l)*(x-arr[l])/(arr[r]-arr[l]);
        cout << "pos: " << pos << endl;
        if(x > arr[pos])
            l = pos+1;
        else if(x < arr[pos])
            r = pos-1;
        else
            return pos;
    }
    return -1;
}
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int x;
    cin >> x;

    cout << interpolationSearch(arr,n,x);
    return 0;
}