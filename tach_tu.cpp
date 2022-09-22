#include <iostream>
#include <string.h>
using namespace std;

template <class T>
void Dem(T* a, int n){
    int count = 1;
    for(int i=1; i<n; i++)
        if(a[i] == a[0])
            count++;
    cout << a[0] << ": " << count << endl;
    for(int i=1; i<n; i++)
        if(a[i] != a[0]){
            count = 1;
            for(int j=i+1; j<n; j++)
                if(a[i] == a[j]){
                    count++;
                    a[j] = a[0];
                }
            cout << a[i] << ": " << count << endl;
        }
}
void Cach1(string s){
    string *kq = new string[20];
    int len = 0, index = 0;
    s += " ";
    for(int i=0; i<s.size(); i++)
        if(s[i] == 32){
            kq[len] = s.substr(index, i - index);
            index = i + 1;
            len++;
        }
    Dem(kq, len);
}
void Cach2(string s){
    string *kq = new string[20];
    int len = 0;
    s += " ";
    while(s.find(" ") != -1){
        kq[len] = s.substr(0, s.find(" "));
        s.erase(0, s.find(" ") + 1);
        len++;
    }
    Dem(kq, len);
}
int main(){
    string s = "toi yeu em ma em lai yeu nguoi khac nen toi danh yeu code";
    cout << "Cach 1:\n";
    Cach1(s);
    cout << "\nCach 2:\n";
    Cach2(s);
    return 0;

}
