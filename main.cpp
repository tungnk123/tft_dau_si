#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Mal;
class Cho;
class Tuong{
public:
    int giap;

    void Nhap(){
        cin  >> giap;
    }
    virtual void Xuat() = 0;
    virtual short Tinh(int n) = 0;
};

class Mal: public Tuong{
public:
    long satthuonggiam;
    void Xuat(){
        cout << "Malphite - Sat thuong duoc giam: " ;
    }
    short Tinh(int n){
        return (giap + 10) * 2 * n;
    }
};

class Cho: public Tuong{
public:
    short satthuonggiam;
    void Xuat(){
        cout << "Cho'Gath - Sat thuong duoc giam: " ;
    }
    short Tinh(int n){
        for (int i = 0; i < n; i++){
            satthuonggiam +=giap + 10;
            giap+=5;
        }
        return satthuonggiam;
    }
};

int main(){
    int n;
    cin >> n;
    Tuong *a[n];
    int t;
    for (int i = 0;i < n;i++){
        cin >> t;
        if (t == 1 ){
            a[i] = new Mal;
            a[i]->Nhap();
        }
        if (t == 2){
            a[i] = new Cho;
            a[i]->Nhap();
        }
    }

    int x;
    cin >> x;
    for (int i = 0;i < n;i++){
        a[i]->Xuat();
        cout << a[i]->Tinh(x) << endl;
    }
}
