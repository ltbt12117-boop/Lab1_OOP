#include <bits/stdc++.h>
using namespace std;

// kiểm tra chuỗi có phải số nguyên hợp lệ không
// Input: chuỗi s
// Output: true nếu hợp lệ, false nếu không
bool kt_so_hop_le(const string& s, int& x){
    stringstream ss(s);
    char kt_thua;
    if (ss >> x && !(ss >> kt_thua)) return true;
    return false;
}

// nhập 1 phân số
// Input: tham chiếu tu, mau
// Output: gán giá trị hợp lệ cho tu, mau
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

// so sánh 2 phân số
// Input: tu1/mau1 và tu2/mau2
// Output: true nếu ps1 > ps2
bool lon_hon(int tu1, int mau1, int tu2, int mau2){
    return tu1 * mau2 > tu2 * mau1;
}

int main(){
    int tu1, mau1, tu2, mau2;

    cout << "Phân số 1:\n";
    nhap_ps(tu1, mau1);

    cout << "Phân số 2:\n";
    nhap_ps(tu2, mau2);

    if (lon_hon(tu1, mau1, tu2, mau2))
        cout << "Phân số lớn nhất: " << tu1 << "/" << mau1;
    else
        cout << "Phân số lớn nhất: " << tu2 << "/" << mau2;

    return 0;
}