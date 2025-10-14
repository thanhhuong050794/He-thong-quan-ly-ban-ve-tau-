#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ===== CLASS Nguoi =====
class Nguoi {
protected:
    string HoTen;
    string NgaySinh;
    string DiaChi;
    string DienThoai;
    string Email;

public:
    Nguoi() = default;
    Nguoi(string hoTen, string ngaySinh, string diaChi, string dienThoai, string email)
        : HoTen(hoTen), NgaySinh(ngaySinh), DiaChi(diaChi), DienThoai(dienThoai), Email(email) {}

    string getHoTen() const { return HoTen; }
    string getNgaySinh() const { return NgaySinh; }
    string getDiaChi() const { return DiaChi; }
    string getDienThoai() const { return DienThoai; }
    string getEmail() const { return Email; }

    void setHoTen(const string& hoTen) { HoTen = hoTen; }
    void setNgaySinh(const string& ngaySinh) { NgaySinh = ngaySinh; }
    void setDiaChi(const string& diaChi) { DiaChi = diaChi; }
    void setDienThoai(const string& dienThoai) { DienThoai = dienThoai; }
    void setEmail(const string& email) { Email = email; }
};

// ===== CLASS HanhKhach =====
class HanhKhach : public Nguoi {
private:
    string MaKhachHang;
    string CCCD;
    string Password;

public:
    HanhKhach() = default;
    HanhKhach(string maKH, string cccd, string password,
              string hoTen = "", string ngaySinh = "", string diaChi = "", string dienThoai = "", string email = "")
        : Nguoi(hoTen, ngaySinh, diaChi, dienThoai, email),
          MaKhachHang(maKH), CCCD(cccd), Password(password) {}

    string getMaKhachHang() const { return MaKhachHang; }
    string getCCCD() const { return CCCD; }
    string getPassword() const { return Password; }

    void setMaKhachHang(const string& maKH) { MaKhachHang = maKH; }
    void setCCCD(const string& cccd) { CCCD = cccd; }
    void setPassword(const string& password) { Password = password; }

    void hienThiThongTin() const {
        cout << "Ma Khach Hang: " << MaKhachHang << endl;
        cout << "CCCD: " << CCCD << endl;
        cout << "Ho Ten: " << HoTen << endl;
        cout << "Ngay Sinh: " << NgaySinh << endl;
        cout << "Dia Chi: " << DiaChi << endl;
        cout << "Dien Thoai: " << DienThoai << endl;
        cout << "Email: " << Email << endl;
    }
};

// ===== KHAI BAO CLASS =====
class LichTrinh {
public:
    string maTau;
    string GaDi;
    string GaDen;
    string ngay;
    string gioChay;
    long giaVe;
    int soGhe;

    LichTrinh(string maTau = "", string gaDi = "", string gaDen = "", string ngay = "", string gioChay = "", long giaVe = 0, int soGhe = 0)
        : maTau(maTau), GaDi(gaDi), GaDen(gaDen), ngay(ngay), gioChay(gioChay), giaVe(giaVe), soGhe(soGhe) {}
};

class GaTau {
public:
    string maGa;
    string tenGa;
    string diaChi;
    string moTa;

    GaTau(string maGa = "", string tenGa = "", string diaChi = "", string moTa = "")
        : maGa(maGa), tenGa(tenGa), diaChi(diaChi), moTa(moTa) {}
        
    string getMaGa() const { return maGa; }
    string getTenGa() const { return tenGa; }
    string getDiaChi() const { return diaChi; }
};

class Ve {
public:
    string MaVe;
    long GiaVe;
    LichTrinh chuyentau;
    HanhKhach hanhkhach;

    Ve(string maVe = "", long giaVe = 0, LichTrinh ct = LichTrinh())
        : MaVe(maVe), GiaVe(giaVe), chuyentau(ct) {}

    long getGiaVe() const { return GiaVe; }
};

// ===== KHAI BAO BIEN TOAN CUC =====
vector<GaTau> dsgatau;
vector<LichTrinh> dschuyentau;
vector<Ve> dsveta;
const string MATKHAU = "admin123";

// ===== KHAI BAO HAM XỬ LY =====
bool xacminhmatkhau();
bool kiemTraEmail(const string& email);
bool kiemTraSDT(const string& sdt);
bool kiemTraCCCD(const string& cccd);
void themgatau();
void danhsachgatau(const string& ten = "", const string& diachi = "");
void xoagatau();
void timkiemgatau();
void lichtrinhtau(const string& gaDi, const string& gaDen, const string& ngay);
string taoMaXacNhan();
void datveta();
void huyveta();
void tracuuveta();
void xemhanhkhach();

// ===== DINH NGHIA HAM KIEM TRA EMAIL =====
bool kiemTraEmail(const string& email) {
    size_t at = email.find('@');
    size_t dot = email.find('.', at);
    return (at != string::npos && dot != string::npos && dot > at);
}



// ===== CLASS PhieuDatVe =====
class PhieuDatVe {
private:
    int soLuong;
    long donGia;
    bool daHuy;
    HanhKhach hanhkhach;

public:
    PhieuDatVe() : soLuong(0), donGia(0), daHuy(false) {}
    PhieuDatVe(int sl, long dg, HanhKhach hk) : soLuong(sl), donGia(dg), daHuy(false), hanhkhach(hk) {}

    int getSoLuong() { return soLuong; }
    long getDonGia() { return donGia; }
    void setSoLuong(int sl) { soLuong = sl; }
    void setDonGia(long dg) { donGia = dg; }

    long tinhTongTien() { return soLuong * donGia; }

    void hienThiVe() {
        cout << "===== PHIEU DAT VE =====" << endl;
        cout << "So luong ve: " << soLuong << endl;
        cout << "Don gia    : " << donGia << endl;
        cout << "Tong tien  : " << tinhTongTien() << endl;
        cout << "Trang thai : " << (daHuy ? "Da huy ve" : "Con hieu luc") << endl;
        cout << "=========================" << endl;
    }

    void huyVe() {
        if (!daHuy) {
            daHuy = true;
            cout << "Ve da duoc huy thanh cong!" << endl;
        } else {
            cout << "Ve nay da duoc huy truoc do!" << endl;
        }
    }

    void xemThongTinHanhKhach() {
        hanhkhach.hienThiThongTin();
    }
};

// ================================================================
bool xacminhmatkhau() {
    string nhapmk;
    cout << "Nhap mat khau quan tri: "; 
    cin >> nhapmk;
    if (nhapmk == MATKHAU) {
        return true;
    } else {
        cout << "Mat khau khong dung!\n";
        return false;
    }
}

// Ham kiem tra so dien thoai
bool kiemTraSDT(const string& sdt) {
    if (sdt.length() < 10 || sdt.length() > 11) return false;
    for (char c : sdt) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Ham validate CCCD
bool kiemTraCCCD(const string& cccd) {
    if (cccd.length() != 12) return false;
    for (char c : cccd) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Them ga tau (yeu cau mat khau)
void themgatau() {
    if (!xacminhmatkhau()) return;
    
    do {
        string ma, ten, diachi, mota;
        cin.ignore();
        cout << "Nhap ma ga: "; 
        getline(cin, ma);
        cout << "Nhap ten ga: "; 
        getline(cin, ten);
        cout << "Nhap dia chi: "; 
        getline(cin, diachi);
        cout << "Nhap mo ta: "; 
        getline(cin, mota);
        
        dsgatau.push_back(GaTau(ma, ten, diachi, mota));
        cout << "Da them ga tau thanh cong.\n";
        
        cout << "Nhap 'a' de them ga tau khac hoac phim bat ky de quay ve menu: ";
        string choice;
        cin >> choice;
        if (choice != "a" && choice != "A") break;
    } while (true);
};

// Ham hien thi danh sach ga tau
void danhsachgatau(const string& ten, const string& diachi) {
    cout << left << setw(15) << "Ma ga"
         << setw(25) << "Ten ga"
         << setw(40) << "Dia chi"
         << setw(30) << "Mo ta" << endl;
    cout << string(110, '-') << endl;
    
    bool hasStation = false;
    for (size_t i = 0; i < dsgatau.size(); i++) {
        const GaTau &gt = dsgatau[i];
        if ((ten.empty() || gt.tenGa.find(ten) != string::npos) &&
    (diachi.empty() || gt.diaChi.find(diachi) != string::npos)) {
    cout << left << setw(15) << gt.maGa
         << setw(25) << gt.tenGa;
}
    
    if (!hasStation) {
        cout << "Khong tim thay ga tau nao phu hop.\n";
    }
}
}

// Xoa ga tau
void xoagatau() {
    if (!xacminhmatkhau()) return;
    
    if (dsgatau.empty()) {
        cout << "Danh sach ga tau trong!\n";
        return;
    }
    
    cout << "Danh sach ga tau hien co:\n";
    danhsachgatau();
    cin.ignore();
    
    string maGa;
    cout << "Nhap ma ga can xoa: ";
    getline(cin, maGa);
    
    // Kiem tra ga co dang duoc su dung khong
    for (const auto& ct : dschuyentau) {
        if (ct.GaDi == maGa || ct.GaDen == maGa) {
            cout << "Khong the xoa! Ga nay dang duoc su dung trong chuyen tau " 
                 << ct.maTau << endl;
            return;
        }
    }
    
    // Xac nhan xoa
    cout << "Ban co chac chan muon xoa ga nay? (y/n): ";
    string xacnhan;
    getline(cin, xacnhan);
    if (xacnhan != "y" && xacnhan != "Y") {
        cout << "Da huy thao tac xoa.\n";
        return;
    }
    
    for (size_t i = 0; i < dsgatau.size(); i++) {
        if (dsgatau[i].getMaGa() == maGa) {
            dsgatau.erase(dsgatau.begin() + i);
            cout << "Da xoa ga tau thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay ga tau voi ma: " << maGa << endl;
}

// Tim kiem ga tau
void timkiemgatau() {
    string ten, diachi;
    cin.ignore();
    cout << "Nhap ten ga (co the de trong): ";
    getline(cin, ten);
    cout << "Nhap dia chi (co the de trong): ";
    getline(cin, diachi);
    
    cout << "\nKet qua tim kiem:\n";
    danhsachgatau(ten, diachi);
}

// Ham hien thi lich trinh tau
void lichtrinhtau(const string& gaDi, const string& gaDen, const string& ngay) {
    cout << left << setw(15) << "Ma tau"
         << setw(20) << "Ga di"
         << setw(20) << "Ga den"
         << setw(15) << "Ngay"
         << setw(15) << "Gio chay"
         << setw(12) << "Gia ve"
         << setw(10) << "So ghe" << endl;
    cout << string(107, '-') << endl;
    
    bool found = false;
    for (const auto& ct : dschuyentau) {
        if ((gaDi.empty() || ct.GaDi == gaDi) && 
            (gaDen.empty() || ct.GaDen == gaDen) && 
            (ngay.empty() || ct.ngay == ngay)) {
            cout << left << setw(15) << ct.maTau
                 << setw(20) << ct.GaDi
                 << setw(20) << ct.GaDen
                 << setw(15) << ct.ngay
                 << setw(15) << ct.gioChay
                 << setw(12) << fixed << setprecision(0) << ct.giaVe
                 << setw(10) << ct.soGhe << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Khong tim thay chuyen tau nao phu hop.\n";
    }
}

// Tao ma xac nhan ngau nhien
string taoMaXacNhan() {
    srand(time(0));
    string ma = "";
    for (int i = 0; i < 6; i++) {
        ma += to_string(rand() % 10);
    }
    return ma;
}

// Dat ve tau
void datveta() {
    if (dschuyentau.empty()) {
        cout << "Khong co chuyen tau nao de dat ve.\n";
        return;
    }
    
    // Nhap thong tin khach hang
    string ten, cccd, sdt, gioitinh, email;
    cin.ignore();
    
    cout << "=== THONG TIN HANH KHACH ===\n";
    cout << "Nhap ten hanh khach: ";
    getline(cin, ten);
    
    do {
        cout << "Nhap CCCD (12 so): ";
        getline(cin, cccd);
        if (!kiemTraCCCD(cccd)) {
            cout << "CCCD khong hop le! Vui long nhap 12 chu so.\n";
        }
    } while (!kiemTraCCCD(cccd));
    
    do {
        cout << "Nhap so dien thoai (10-11 so): ";
        getline(cin, sdt);
        if (!kiemTraSDT(sdt)) {
            cout << "So dien thoai khong hop le!\n";
        }
    } while (!kiemTraSDT(sdt));
    
    cout << "Nhap gioi tinh: ";
    getline(cin, gioitinh);
    
    
    // Tim chuyen tau
    string gaDi, gaDen, ngay;
    bool hasTrain = false;
    
    do {
        hasTrain = false;
        cout << "\n=== TIM CHUYEN TAU ===\n";
        cout << "Nhap ga di: "; 
        getline(cin, gaDi);
        cout << "Nhap ga den: "; 
        getline(cin, gaDen);
        cout << "Nhap ngay (dd/mm/yyyy): "; 
        getline(cin, ngay);
        
        for (const auto& ct : dschuyentau) {
            if (ct.GaDi == gaDi && ct.GaDen == gaDen && ct.ngay == ngay) {
                hasTrain = true;
                break;
            }
        }
        
        if (hasTrain) {
            cout << "\nDanh sach chuyen tau:\n";
            lichtrinhtau(gaDi, gaDen, ngay);
        } else {
            cout << "Khong tim thay chuyen tau! Vui long nhap lai.\n";
        }
    } while (!hasTrain);
    
    // Dat ve
    cout << "\nNhap ma tau muon dat (cach nhau boi dau cach): ";
    string input;
    getline(cin, input);
    istringstream iss(input);
    string matau;
    
    double tongTien = 0;
    vector<string> danhSachVeDat;
    
    while (iss >> matau) {
        bool found = false;
        for (auto& ct : dschuyentau) {
            if (ct.maTau == matau && ct.GaDi == gaDi && 
                ct.GaDen == gaDen && ct.ngay == ngay) {
                found = true;
                if (ct.soGhe > 0) {
                    HanhKhach hk(ten, cccd, sdt, gioitinh, email);
                    string maVe = taoMaXacNhan(); // Tạo mã vé ngẫu nhiên
                    dsveta.push_back(Ve(maVe, ct.giaVe, ct));
                    ct.soGhe--;
                    tongTien += ct.giaVe;
                    danhSachVeDat.push_back(matau);
                    cout << "Da them ve tau " << matau << " vao gio hang.\n";
                } else {
                    cout << "Chuyen tau " << matau << " da het cho.\n";
                }
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay chuyen tau " << matau << ".\n";
        }
    }
    
    if (danhSachVeDat.empty()) {
        cout << "Khong co ve nao duoc dat.\n";
        return;
    }
    
    // Thanh toan
    cout << "\n=== THONG TIN THANH TOAN ===\n";
    cout << "Tong tien: " << fixed << setprecision(0) << tongTien << " VND\n";
    cout << "So tai khoan: 5386763727\n";
    cout << "Ngan hang: MB Bank\n";
    cout << "Chu tai khoan: Nguyen Van A\n";
    cout << "\nSau khi chuyen khoan, nhan Enter de tiep tuc...\n";
    cin.ignore();
    
    // Tao va gui ma xac nhan
    string maXacNhan = taoMaXacNhan();
    cout << "\nMa xac nhan da duoc gui den email " << email << endl;
    cout << "(Ma xac nhan demo: " << maXacNhan << ")\n";
    cout << "Nhap ma xac nhan: ";
    string maNhap;
    cin >> maNhap;
    
    if (maNhap == maXacNhan) {
        cout << "\n=== DAT VE THANH CONG ===\n";
        for (const auto& ma : danhSachVeDat) {
            cout << "Ve tau " << ma << " da duoc dat thanh cong!\n";
        }
    } else {
        cout << "\nMa xac nhan khong dung! Dat ve that bai.\n";
        // Hoan tra ghe
        for (const auto& ma : danhSachVeDat) {
            for (auto& ct : dschuyentau) {
                if (ct.maTau == ma) {
                    ct.soGhe++;
                    break;
                }
            }
        }
        // Xoa ve da dat
        for (int i = dsveta.size() - 1; i >= 0; i--) {
            if (dsveta[i].hanhkhach.getCCCD() == cccd) {
                bool isNew = false;
                for (const auto& ma : danhSachVeDat) {
                    if (dsveta[i].chuyentau.maTau == ma) {
                        isNew = true;
                        break;
                    }
                }
                if (isNew) {
                    dsveta.erase(dsveta.begin() + i);
                }
            }
        }
    }
}

// Huy ve tau
void huyveta() {
    string cccd;
    cin.ignore();
    cout << "Nhap can cuoc cong dan: ";
    getline(cin, cccd);
    
    vector<int> danhSachVe;
    for (size_t i = 0; i < dsveta.size(); i++) {
        if (dsveta[i].hanhkhach.getCCCD() == cccd) {
            danhSachVe.push_back(i);
        }
    }
    
    if (danhSachVe.empty()) {
        cout << "Khong tim thay ve nao voi CCCD nay.\n";
    cout << left << setw(15) << "Ma tau"
         << setw(20) << "Ga di"
         << setw(20) << "Ga den"
         << setw(15) << "Ngay"
         << setw(15) << "Gio chay"
         << setw(12) << "Gia ve" << endl;
    cout << string(97, '-') << endl;

    for (size_t idx : danhSachVe) {
        const LichTrinh &ct = dsveta[idx].chuyentau;
        cout << left << setw(15) << ct.maTau
             << setw(20) << ct.GaDi
             << setw(20) << ct.GaDen
             << setw(15) << ct.ngay
             << setw(15) << ct.gioChay
             << setw(12) << fixed << setprecision(0) << ct.giaVe << endl;
    }
    }
    
    cout << "\nNhap ma tau can huy: ";
    string matau;
    getline(cin, matau);
    
    for (size_t idx : danhSachVe) {
        if (dsveta[idx].chuyentau.maTau == matau) {
            cout << "\n=== THONG TIN HOAN TIEN ===\n";
            cout << "Nhap so tai khoan: ";
            string stk;
            getline(cin, stk);
            cout << "Nhap ten ngan hang: ";
            string nganHang;
            getline(cin, nganHang);
            
            // Hoan tra ghe
            for (auto& ct : dschuyentau) {
                if (ct.maTau == matau) {
                    ct.soGhe++;
                    break;
                }
            }
            
            double tienHoan = dsveta[idx].chuyentau.giaVe;
            dsveta.erase(dsveta.begin() + idx);
            
            cout << "\nVe da duoc huy thanh cong!\n";
            cout << "So tien " << fixed << setprecision(0) << tienHoan 
                 << " VND se duoc hoan vao tai khoan trong 5 phut.\n";
            return;
        }
    }
    cout << "Khong tim thay ve voi ma tau: " << matau << endl;
}

// Tra cuu ve tau
void tracuuveta() {
    string cccd;
    cin.ignore();
    cout << "Nhap can cuoc cong dan: "; 
    getline(cin, cccd);
    
    bool found = false;
    cout << "\n=== CAC VE DA DAT ===\n";
    cout << left << setw(15) << "Ma ve"
         << setw(15) << "Ma tau"
         << setw(20) << "Ga di"
         << setw(20) << "Ga den"
         << setw(15) << "Ngay"
         << setw(15) << "Gio"
         << setw(12) << "Gia ve" << endl;
    cout << string(112, '-') << endl;
    
    for (const auto& ve : dsveta) {
        if (ve.chuyentau.maTau == cccd || ve.MaVe == cccd || ve.chuyentau.GaDi == cccd || ve.chuyentau.GaDen == cccd || ve.GiaVe == stol(cccd)) { // Or use your own logic for matching CCCD
            const LichTrinh &ct = ve.chuyentau;
            cout << left << setw(15) << ve.MaVe
                 << setw(15) << ct.maTau
                 << setw(20) << ct.GaDi
                 << setw(20) << ct.GaDen
                 << setw(15) << ct.ngay
                 << setw(15) << ct.gioChay
                 << setw(12) << fixed << setprecision(0) << ct.giaVe << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Khong tim thay ve nao voi CCCD nay.\n";
    }
}

// Xem danh sach hanh khach
void xemhanhkhach() {
    if (!xacminhmatkhau()) return;
    
    string matau;
    cin.ignore();
    cout << "Nhap ma chuyen tau: "; 
    getline(cin, matau);
    
    bool foundTrain = false;
    cout << "\n=== HANH KHACH TREN CHUYEN TAU " << matau << " ===\n";
    cout << left << setw(25) << "Ten"
         << setw(15) << "CCCD"
         << setw(15) << "SDT"
         << setw(12) << "Gioi tinh"
         << setw(30) << "Email" << endl;
    cout << string(97, '-') << endl;
    
    for (const auto& ve : dsveta) {
        if (ve.chuyentau.maTau == matau) {
            const HanhKhach &hk = ve.hanhkhach;
            cout << left << setw(25) << hk.getHoTen()
                 << setw(15) << hk.getCCCD()
                 << setw(15) << hk.getDienThoai()
                 << setw(12) << "" // Ch?a co tr??ng GioiTinh, ?? tr?ng ho?c them n?u c?n
                 << setw(30) << hk.getEmail() << endl;
            foundTrain = true;
        }
    }
    
    if (!foundTrain) {
        cout << "Khong co hanh khach nao tren chuyen tau nay.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n=== HE THONG QUAN LY VE TAU ===\n";
        cout << "1. Them ga tau\n";
        cout << "2. Hien thi danh sach ga tau\n";
        cout << "3. Xoa ga tau\n";
        cout << "4. Tim kiem ga tau\n";
        cout << "5. Hien thi lich trinh tau\n";
        cout << "6. Dat ve tau\n";
        cout << "7. Huy ve tau\n";
        cout << "8. Tra cuu ve tau\n";
        cout << "9. Xem danh sach hanh khach tren chuyen tau\n";
        cout << "10. Xem thong tin hanh khach\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                themgatau();
                break;
            case 2:
                danhsachgatau();
                break;
            case 3:
                xoagatau();
                break;
            case 4:
                timkiemgatau();
                break;
            case 5: {
                string gaDi, gaDen, ngay;
                cin.ignore();
                cout << "Nhap ga di (co the de trong): ";
                getline(cin, gaDi);
                cout << "Nhap ga den (co the de trong): ";
                getline(cin, gaDen);
                cout << "Nhap ngay (dd/mm/yyyy) (co the de trong): ";
                getline(cin, ngay);
                lichtrinhtau(gaDi, gaDen, ngay);
                break;
            }
            case 6:
                datveta();
                break;
            case 7:
                huyveta();
                break;
            case 8:
                tracuuveta();
                break;
            case 9:
                xemhanhkhach();
                break;
            case 10: {
                string cccd;
                cin.ignore();
                cout << "Nhap CCCD hanh khach: ";
                getline(cin, cccd);
                bool found = false;
                for (const auto& ve : dsveta) {
                    if (ve.hanhkhach.getCCCD() == cccd) {
                        ve.hanhkhach.hienThiThongTin();
                        found = true;
                    }
                }
                if (!found) {
                    cout << "Khong tim thay hanh khach voi CCCD nay.\n";
                }
                break;
            }
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le! Vui long chon lai.\n";
        }
    } while (choice != 0);

    return 0;
}