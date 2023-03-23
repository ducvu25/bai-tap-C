#include<iostream>

using namespace std;
// Thực hiện luyện tập trên mảng
int arr[100];
int n;
// 1. Đệ quy cơ bản - chú ý điều kiện dừng/thực hiện
// + Nhập mảng
void Nhap(int i){
    // điều kiện thực hiện: i < n
    if(i < n){
        cin >> arr[i];
        Nhap(i+1);
    }
}

// + Xuất mảng
void Xuat(int i){
    // điều kiện thực hiện: i < n
    if(i < n){
        cout << arr[i] << " ";
        Xuat(i+1);
    }
    // ta cũng có thể thêm kí tự xuống dòng sau khi xuất hết mảng bằng else
    else
        cout << endl;
}
// + Tính tổng bình thường
int Sum(int i){
    if(i < n){ 
        return arr[i] + Sum(i+1); // s[n] = a[n] + s[n-1]
    }
    // ta cần thêm kết thúc sau khi hết mảng bằng else
    else
        return 0;
}
// Đêm các phần tử x trong mảng
int Count(int i, int x){
    if(i < n){ 
        if(arr[i] == x)
            return 1 + Count(i+1, x);
        else
            return Count(i+1, x); 
    }else
        return 0;
}

// 2. Đệ quy đuôi - Thêm biến lưu trữ kết quả sau mỗi quá trình - đổi kiểu trả về
// + Tính tổng 
void Sum(int i, int &kq){
    if(i < n){ 
        kq += arr[i];
        Sum(i+1, kq); // s[n] = a[n] + s[n-1]
    }
}
// Đêm các phần tử x trong mảng
void Count(int i, int x, int &count){
    if(i < n){ 
        if(arr[i] == x)
            count++;
        Count(i+1, x, count); 
    }
}
int main(){
    cout << "Nhap so luong: "; cin >> n;
    Nhap(0);
    Xuat(0);
    int x = 5;
    cout << "Tong cac phan tu trong mang: " << Sum(0) << endl;
    cout << "So luong cac phan tu " << x << " trong mang: " << Count(0, x) << endl;
    int kq = 0; 
    Sum(0, kq);
    cout << "Tong cac phan tu trong mang: " << kq << endl;
    kq = 0;
    Count(0, x, kq);
    cout << "So luong cac phan tu " << x << " trong mang: " <<kq << endl;

    return 0;
}