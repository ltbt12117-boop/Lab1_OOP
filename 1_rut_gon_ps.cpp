#include <bits/stdc++.h>
using namespace std;

// kiểm tra chuỗi có phải số nguyên hợp lệ không
// input: chuỗi s
// output: true nếu hợp lệ, false nếu không
bool kt_so_hop_le(const string& s, int& x){
    stringstream ss(s); // biến chuỗi thành luồng để đọc

    char kt_thua;

    // Chuyển chuỗi thành kiểu số nguyên (true) và chuyển chuỗi thành kiểu kí tự (sai)
    if (ss >> x && !(ss >> kt_thua)){
        return true;
    }
    return false;
}

// nhập 1 phân số
// input: tham chiếu tu, mau
// Output: gán giá trị hợp lệ cho tu, mau
void nhap_ps(int& tu, int& mau){
    string s;

    // tử là một số nguyên, không phải kí tự đặc biệt hay chữ cái
    while (true){
        cout << "Nhập tử số: ";
        getline(cin, s);
        if (kt_so_hop_le(s, tu)) break;
        else cout << "Tử số không hợp lệ.\n";
    }

    // điều kiện mẫu số tương tự tử số, và mẫu số khác 0
    while (true){
        cout << "Nhập mẫu số: ";
        getline (cin, s);
        if (kt_so_hop_le (s, mau) && mau != 0) break;
        cout << "Mẫu số không hợp lệ.\n";
    }
}

// tìm ước chung lớn nhất để rút gọn phân số
// input: a, b
// output: UCLN của a và b
int ucln(int a, int b){
    if (b==0) return a;
    else return ucln(b, a%b);
}

// rút gọn phân số bằng cách lấy tử và mẫu chia cho ucln của chúng
void rut_gon_ps (int& tu, int& mau){
    int k = ucln (tu, mau);
    tu = tu / k;
    mau = mau / k;
}

int main(){
    int tu, mau;

    nhap_ps (tu, mau);

    if (tu==0) cout << "Kết quả là: 0"; // nếu ban đầu tử bằng 0 thì in kết quả 0 luôn
    else if (mau==1) cout << "Kết quả là: " << tu; // nếu ban đầu mẫu bằng 1 thì kết quả bằng tử luôn
    else {
        rut_gon_ps (tu, mau);
        if (mau==1) cout << "Kết quả là: " << tu;
        else cout << "Kết quả là : " << tu << "/" << mau;
    }
    return 0;
}
