#include <bits/stdc++.h>
using namespace std;

// giống bài 1
bool kt_so_hop_le(const string& s, int& x){
    stringstream ss(s);
    char kt_thua;
    if (ss >> x && !(ss >> kt_thua)) return true;
    return false;
}

// nhập phân số
void nhap_ps(int& tu, int& mau){
    string s;
    while (true){
        cout << "nhập tử số: ";
        getline(cin, s);
        if (kt_so_hop_le(s, tu)) break;
        cout << "tử không hợp lệ\n";
    }

    while (true){
        cout << "nhập mẫu số: ";
        getline(cin, s);
        if (kt_so_hop_le(s, mau) && mau != 0) break;
        cout << "mẫu không hợp lệ\n";
    }
}

// tìm UCLN
// Input: a, b
// Output: UCLN của a và b
int ucln(int a, int b){
    if (b == 0) return a;
    return ucln(b, a % b);
}

// rút gọn phân số
// Input/Output: tu, mau (tham chiếu)
void rut_gon(int& tu, int& mau){
    int k = ucln(abs(tu), abs(mau));
    tu /= k;
    mau /= k;
}

// in phân số
// Input: tu, mau
void xuat_ps(int tu, int mau){
    rut_gon(tu, mau);
    if (mau == 1) cout << tu;
    else cout << tu << "/" << mau;
}

int main(){
    int tu1, mau1, tu2, mau2;

    cout << "Phân số 1:\n";
    nhap_ps(tu1, mau1);

    cout << "Phân số 2:\n";
    nhap_ps(tu2, mau2);

    // tổng
    int tu = tu1*mau2 + tu2*mau1;
    int mau = mau1*mau2;
    cout << "Tổng: "; xuat_ps(tu, mau); cout << endl;

    // hiệu
    tu = tu1*mau2 - tu2*mau1;
    mau = mau1*mau2;
    cout << "Hiệu: "; xuat_ps(tu, mau); cout << endl;

    // tích
    tu = tu1*tu2;
    mau = mau1*mau2;
    cout << "Tích: "; xuat_ps(tu, mau); cout << endl;

    // thương
    tu = tu1*mau2;
    mau = mau1*tu2;
    cout << "Thương: "; xuat_ps(tu, mau);

    return 0;
}