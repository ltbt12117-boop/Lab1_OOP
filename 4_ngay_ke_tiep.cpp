#include <bits/stdc++.h>
using namespace std;

bool la_nam_nhuan(int nam) {
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

int so_ngay(int thang, int nam) {
    if (thang == 2) {
        return la_nam_nhuan(nam) ? 29 : 28;
    }

    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return 30;
    }

    return 31;
}

bool la_so_nguyen_hop_le(const string& s, int& x) {
    stringstream ss(s);
    char ky_tu_thua;

    if (ss >> x && !(ss >> ky_tu_thua)) {
        return true;
    }

    return false;
}

bool la_ngay_hop_le(int ngay, int thang, int nam) {
    if (nam <= 0) {
        return false;
    }

    if (thang < 1 || thang > 12) {
        return false;
    }

    if (ngay < 1 || ngay > so_ngay(thang, nam)) {
        return false;
    }

    return true;
}

void nhap_ngay_thang_nam(int& ngay, int& thang, int& nam) {
    string s_ngay, s_thang, s_nam;

    while (true) {
        cout << "Nhap ngay: ";
        getline(cin, s_ngay);

        cout << "Nhap thang: ";
        getline(cin, s_thang);

        cout << "Nhap nam: ";
        getline(cin, s_nam);

        bool ngay_hop_le = la_so_nguyen_hop_le(s_ngay, ngay);
        bool thang_hop_le = la_so_nguyen_hop_le(s_thang, thang);
        bool nam_hop_le = la_so_nguyen_hop_le(s_nam, nam);

        if (!ngay_hop_le || !thang_hop_le || !nam_hop_le) {
            cout << "Ngay, thang, nam phai la so nguyen. Vui long nhap lai.\n";
            continue;
        }

        if (!la_ngay_hop_le(ngay, thang, nam)) {
            cout << "Ngay thang nam khong hop le. Vui long nhap lai.\n";
            continue;
        }

        break;
    }
}

int main() {
    int ngay, thang, nam;

    nhap_ngay_thang_nam(ngay, thang, nam);

    ngay++;

    if (ngay > so_ngay(thang, nam)) {
        ngay = 1;
        thang++;

        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }

    cout << "Ngay ke tiep: " << ngay << "/" << thang << "/" << nam;
    return 0;
}
