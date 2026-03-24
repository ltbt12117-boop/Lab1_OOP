#include <bits/stdc++.h>
using namespace std;

// kiểm tra họ tên hợp lệ (không chứa số hoặc ký tự đặc biệt), nhập tên không dấu
// input: chuỗi s
// output: true nếu hợp lệ
bool kt_ten_hop_le(const string& s){
    if (s.empty()) return false;

    for (char c : s){
        if (!(isalpha(c) || c == ' '))
            return false;
    }
    return true;
}

// kiểm tra số thực hợp lệ
// Input: chuỗi s
// Output: true nếu là số thực hợp lệ
bool kt_so_thuc(const string& s, float& x){
    stringstream ss(s);
    char kt_thua;

    if (ss >> x && !(ss >> kt_thua))
        return true;

    return false;
}

// hàm nhập tên, điểm toán, điểm văn
// input: ten, toan, van (tham chiếu)
// output: gán giá trị hợp lệ
void nhap(string& ten, float& toan, float& van){
    string s;

    // nhập tên
    while (true){
        cout << "nhập họ tên (không dấu): ";
        getline(cin, ten);

        if (kt_ten_hop_le(ten)) break;
        else cout << "tên không hợp lệ.\n";
    }

    // nhập điểm toán
    while (true){
        cout << "nhập điểm toán: ";
        getline(cin, s);

        if (kt_so_thuc(s, toan) && toan >= 0 && toan <= 10) break;
        else cout << "điểm toán không hợp lệ.\n";
    }

    // nhập điểm văn
    while (true){
        cout << "nhập điểm văn: ";
        getline(cin, s);

        if (kt_so_thuc(s, van) && van >= 0 && van <= 10) break;
        else cout << "điểm văn không hợp lệ.\n";
    }
}

// tính điểm trung bình
// Input: toán, văn
// Output: điểm TB
float tinh_tb(float toan, float van){
    return (toan + van) / 2;
}

int main(){
    string ten;
    float toan, van;
    
    nhap(ten, toan, van);

    float tb = tinh_tb(toan, van);

    cout << "Họ tên: " << ten << endl;
    cout << "Điểm trung bình: " << tb;

    return 0;
}