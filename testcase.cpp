#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream> // thư viện file 
#include <sstream> // thư viện stringstream
#include <ctime>  // thư viện time 

using namespace std;
// matkhau: Admin@123

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

    virtual ~Nguoi() = default;

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

    virtual void hienThiThongTin() const {
        cout << "Ho Ten: " << HoTen << endl;
        cout << "Ngay Sinh: " << NgaySinh << endl;
        cout << "Dia Chi: " << DiaChi << endl;
        cout << "Dien Thoai: " << DienThoai << endl;
        cout << "Email: " << Email << endl;
    }
};

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

class NhanVien : public Nguoi {
private:
    string Username;
    string Password;

public:
    NhanVien() = default;
    NhanVien(const string& username, const string& password,
             const string& hoTen = "", const string& ngaySinh = "", const string& diaChi = "",
             const string& dienThoai = "", const string& email = "")
        : Nguoi(hoTen, ngaySinh, diaChi, dienThoai, email),
          Username(username), Password(password) {}

    string getUsername() const { return Username; }
    string getPassword() const { return Password; }

    void setUsername(const string& username) { Username = username; }
    void setPassword(const string& password) { Password = password; }

    void hienThiThongTin() const { 
        cout << "Username: " << Username << endl;
        cout << "Password: " << Password << endl;
        cout << "Ho Ten: " << HoTen << endl;
        cout << "Ngay Sinh: " << NgaySinh << endl;
        cout << "Dia Chi: " << DiaChi << endl;
        cout << "Dien Thoai: " << DienThoai << endl;
        cout << "Email: " << Email << endl;
    }
};

class LichTrinh {
public: 
    string maTau;
    string GaDi;
    string GaDen;
    string ngay;
    string gioChay;
    string gioDen;
    long giaVe;
    int soGhe;

    LichTrinh(string maTau = "", string gaDi = "", string gaDen = "", string ngay = "", string gioChay = "", string gioDen = "", long giaVe = 0, int soGhe = 0)
        : maTau(maTau), GaDi(gaDi), GaDen(gaDen), ngay(ngay), gioChay(gioChay), gioDen(gioDen), giaVe(giaVe), soGhe(soGhe) {}
    
    string getmaTau() const { return maTau; }
    string getngay() const { return ngay; }
    string getgioChay() const { return gioChay; }
    string getgioDen() const { return gioDen; }
    long getgiaVe() const { return giaVe; }
    int getsoGhe() const { return soGhe; }
    string getGaDi() const { return GaDi; }
    string getGaDen() const { return GaDen; }
}; 

class GaTau {
public: 
    string maGa;
    string tenGa;
    string diaChi;
    string moTa;

    GaTau(string maGa = "", string tenGa = "", string diaChi = "", string moTa = "")
        : maGa(maGa), tenGa(tenGa), diaChi(diaChi), moTa(moTa) {}
        
    string getmaGa() const { return maGa; }
    string gettenGa() const { return tenGa; }
    string getdiaChi() const { return diaChi; }
    string getmoTa() const { return moTa; }
};

class Ve {
public:
    string MaVe;
    long giaVe;
    LichTrinh chuyentau; // ve thuoc chuyen tau nao 
    HanhKhach hanhkhach; // ve thuoc hanh khach nao 

    Ve(string maVe = "", long giaVe = 0, LichTrinh ct = LichTrinh())
        : MaVe(maVe), giaVe(giaVe), chuyentau(ct) {}

    long getgiaVe() const { return giaVe; }
};
class PhieuDatVe {
private:
        int soLuong;
        long donGia;
        bool daHuy;
        HanhKhach hanhkhach; // thong tin hanh khach da dat ve 
public: 
        PhieuDatVe() : soLuong(0), donGia(0), daHuy(false) {}
        PhieuDatVe(int sl, long dg, HanhKhach hk) : soLuong(sl), donGia(dg), daHuy(false), hanhkhach(hk) {}
    
        int getSoLuong() { return soLuong; }
        long getDonGia() { return donGia; }
        HanhKhach getHanhKhach() { return hanhkhach; } 
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
    
// KHAI BAO BIEN TOAN CUC
vector<GaTau> dsgatau;
vector<LichTrinh> dschuyentau;
vector<Ve> dsveta;
vector<PhieuDatVe> dsphieudatve;
vector<NhanVien> dsnhanvien; 
const string MATKHAU = "Admin@123";
 
// KHAI BAO HAM INPUT / OUTPUT 
void loadData(const string& filename = "loadData.txt"); // file input 
void saveData(const string& filename = "saveData.txt"); // file output 

// hàm input 
void loadData(string filename, vector<GaTau>& dsgatau, vector<LichTrinh>& dschuyentau) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Khong the mo file: " << filename << endl;
        return;
    }
    
    string line;
    string currentSection = "";
    
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        if (line == "[LICH TRINH]") {
            currentSection = "LICH TRINH";
            continue; 
        } else if (line == "[GA TAU]") {
            currentSection = "GA TAU";
            continue;
        }
        
        if (currentSection == "GA TAU") {
            // Tách chuỗi bằng stringstream
            stringstream ss(line);
            string ma, ten, dc, moTa;
            
            getline(ss, ma, '|');
            getline(ss, ten, '|');
            getline(ss, dc, '|');   
            getline(ss, moTa, '|');  // Có thể rỗng
            
            dsgatau.push_back(GaTau(ma, ten, dc, moTa));
        } 
        else if (currentSection == "LICH TRINH") {
            // Tách chuỗi bằng stringstream
            stringstream ss(line);
            string ma, di, den, ngay, gioKH, gioDen, giaVe_str, soGhe_str;
            
            getline(ss, ma, '|'); 
            getline(ss, di, '|');
            getline(ss, den, '|');
            getline(ss, ngay, '|');
            getline(ss, gioKH, '|');
            getline(ss, gioDen, '|');
            getline(ss, giaVe_str, '|');
            getline(ss, soGhe_str, '|');
            
            long giaVe = stol(giaVe_str); // chuyển đổi chuỗi sang long
            int soGhe = stoi(soGhe_str); // chuyển đổi chuỗi sang int
            
            dschuyentau.push_back(LichTrinh(ma, di, den, ngay, gioKH, gioDen, giaVe, soGhe));
        }
    }
    
    file.close();
    cout << "Da load thanh cong!" << endl;
}

// hàm output
void saveData(const string& filename, const vector<GaTau>& dsgatau, 
              const vector<LichTrinh>& dschuyentau, const vector<Ve>& dsveta)
{
    ofstream ofs(filename);
    if (!ofs.is_open()) {
        cout << "Khong the mo file de ghi: " << filename << endl;
        return;
    }
    
    // Ghi ga tau
    ofs << "[GA TAU]\n";
    ofs << left << setw(15) << "Ma Ga" 
        << left << setw(25) << "Ten Ga" 
        << left << setw(60) << "Dia Chi" 
        << "Mo Ta\n";
    ofs << string(220, '-') << "\n";

    for (const auto& g : dsgatau) {
        ofs << left << setw(15) << g.getmaGa() 
            << left << setw(25) << g.gettenGa() 
            << left << setw(60) << g.getdiaChi() 
            << g.getmoTa() << "\n";
    }
    ofs << "\n";

    // Ghi lich trinh
    ofs << "[LICH TRINH]\n";
    ofs << left << setw(15) << "Ma Tau"
        << left << setw(20) << "Ga Di"
        << left << setw(20) << "Ga Den"
        << left << setw(15) << "Ngay"
        << left << setw(15) << "Gio Chay"
        << left << setw(15) << "Gio Den"
        << left << setw(15) << "Gia Ve"
        << "So Ghe\n";
    ofs << string(220, '-') << "\n";
              
    for (const auto& lt : dschuyentau) {
        ofs << left << setw(15) << lt.getmaTau() 
            << left << setw(20) << lt.getGaDi() 
            << left << setw(20) << lt.getGaDen() 
            << left << setw(15) << lt.getngay() 
            << left << setw(15) << lt.getgioChay()
            << left << setw(15) << lt.getgioDen() 
            << left << setw(15) << lt.getgiaVe() 
            << lt.getsoGhe() << "\n";
    }
    ofs << "\n";

   // Ghi thong tin ve tau 
    ofs << "[THONG TIN CHUYEN TAU]\n";
    ofs << left << setw(10) << "Ma Ve"
        << setw(12) << "Gia Ve"
        << setw(10) << "Ma Tau"
        << setw(15) << "Ga Di"
        << setw(15) << "Ga Den"
        << setw(15) << "Ngay"
        << setw(12) << "Gio Chay"
        << setw(12) << "Gio Den"
        << setw(12) << "Gia Ve"
        << "So Ghe\n";
     ofs << string(220, '-') << "\n";

     // Ghi chi tiet ve tau
    for (const auto& ve : dsveta) {
        ofs << left << setw(10) << ve.MaVe
            << setw(12) << ve.giaVe
            << setw(10) << ve.chuyentau.getmaTau()
            << setw(15) << ve.chuyentau.getGaDi()
            << setw(15) << ve.chuyentau.getGaDen()
            << setw(15) << ve.chuyentau.getngay()
            << setw(12) << ve.chuyentau.getgioChay()
            << setw(12) << ve.chuyentau.getgioDen()
            << setw(12) << ve.chuyentau.getgiaVe()
            << setw(8) << ve.chuyentau.getsoGhe()
            << "\n";
    }
    ofs << "\n";

    // Ghi thong tin hanh khach
    ofs << "[THONG TIN HANH KHACH]\n";
    ofs << left
        << setw(30) << "Ma KH"
        << left << setw(30) << "CCCD"
        << left << setw(30) << "Ho Ten"
        << left << setw(15) << "Dien Thoai"
        << "Email\n";
    ofs << string(220, '-') << "\n";
    
    // Ghi chi tiet hanh khach
    for (const auto& ve : dsveta) {
        ofs << left
            << setw(30) << ve.hanhkhach.getMaKhachHang()
            << left << setw(30) << ve.hanhkhach.getCCCD()
            << left << setw(30) << ve.hanhkhach.getHoTen()
            << left<< setw(15) << ve.hanhkhach.getDienThoai()
            << ve.hanhkhach.getEmail() << "\n";
    }
    
    ofs.close();
    cout << "Da luu du lieu thanh cong vao file: " << filename << endl;
}
// KHAI BAO HAM XU LY
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
void themNhanVien();
void danhSachNhanVien();
void xemPhieuDatVe();

// DINH NGHIA HAM KIEM TRA EMAIL
bool kiemTraEmail(const string& email) {
    size_t at = email.find('@');
    size_t dot = email.find('.', at);
    return (at != string::npos && dot != string::npos && dot > at); // kiểm tra định dạng cơ bản của email
}


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
        if (!isdigit(c)) return false; // kiểm tra tất cả ký tự có phải số không
    }
    return true;
}

// Ham validate CCCD
bool kiemTraCCCD(const string& cccd) {
    if (cccd.length() != 12) return false;
    for (char c : cccd) {
        if (!isdigit(c)) return false; // kiểm tra tất cả ký tự có phải số không
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
}

// Ham hien thi danh sach ga tau
void danhsachgatau(const string& ten, const string& diachi) {
    cout << "\n=== DANH SACH GA TAU ===\n";
    cout << left << setw(15) << "Ma ga"
         << setw(25) << "Ten ga"
         << setw(40) << "Dia chi" << endl;
    cout << string(80, '-') << endl;
    
    bool hasStation = false;
    for (size_t i = 0; i < dsgatau.size(); i++) {
        const GaTau &gt = dsgatau[i];
        if ((ten.empty() || gt.tenGa.find(ten) != string::npos) &&
            (diachi.empty() || gt.diaChi.find(diachi) != string::npos)) {
            
            cout << left << setw(15) << gt.maGa
                 << setw(25) << gt.tenGa
                 << setw(40) << gt.diaChi << endl;  
            hasStation = true;
        }
    }
    
    if (!hasStation) {  
        cout << "Khong tim thay ga tau nao phu hop.\n";
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
        if (dsgatau[i].getmaGa() == maGa) {
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

// Tao ma xac nhan ngau nhien 6 chu so
string taoMaXacNhan() {
    srand(time(0));
    string ma = "";
    for (int i = 0; i < 6; i++) {
        ma += to_string(rand() % 10);
    }
    return ma;
}


// hàm đặt vé tàu 
void datveta() {
    if (dschuyentau.empty()) {
        cout << "Khong co chuyen tau nao de dat ve.\n";
        return;
    }
    
    // Nhập thông tin khách hàng
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
    
    do {
        cout << "Nhap email: ";
        getline(cin, email);
        if (!kiemTraEmail(email)) {
            cout << "Email khong hop le!\n";
        }
    } while (!kiemTraEmail(email));
    
    // Tạo đối tượng HanhKhach
    HanhKhach hk("KH" + cccd, cccd, sdt, ten, gioitinh, "", sdt, email); // thông tin hành khách 
    
    // Tìm chuyến tàu
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
    
    // Đặt vé với số lượng
    cout << "\nNhap ma tau muon dat: ";
    string matau;
    getline(cin, matau);
    
   // Tìm chuyến tàu
    LichTrinh* chuyenTauChon = nullptr;
    for (auto& ct : dschuyentau) {
        if (ct.maTau == matau && ct.GaDi == gaDi && 
            ct.GaDen == gaDen && ct.ngay == ngay) {
            chuyenTauChon = &ct;
            break;
        }
    }
    
    if (chuyenTauChon == nullptr) {
        cout << "Khong tim thay chuyen tau " << matau << ".\n";
        return;
    } 
    
    // Nhập số lượng vé
    int soLuongVe;
    do {
        cout << "Nhap so luong ve can dat (Con " << chuyenTauChon->soGhe << " ghe): ";
        cin >> soLuongVe;
        
        if (soLuongVe <= 0) {
            cout << "So luong ve phai lon hon 0!\n";
        } else if (soLuongVe > chuyenTauChon->soGhe) {
            cout << "So luong ve vuot qua so ghe con lai!\n";
        } else {
            break;
        }
    } while (true);
    
    // Tính tổng tiền
    long tongTien = soLuongVe * chuyenTauChon->giaVe;
    
    cout << "\n=== THONG TIN DAT VE ===\n";
    cout << "Chuyen tau: " << matau << endl;
    cout << "Tuyen: " << gaDi << " -> " << gaDen << endl;
    cout << "Ngay: " << ngay << " - Gio: " << chuyenTauChon->gioChay << endl;
    cout << "So luong ve: " << soLuongVe << endl;
    cout << "Don gia: " << fixed << setprecision(0) << chuyenTauChon->giaVe << " VND\n";
    cout << "Tong tien: " << tongTien << " VND\n";
    cout << string(50, '-') << endl;
    
    // Xác nhận đặt vé
    cout << "\nBan co muon tiep tuc dat ve? (y/n): ";
    char xacNhan;
    cin >> xacNhan;
    cin.ignore();
    
    if (xacNhan != 'y' && xacNhan != 'Y') {
        cout << "Da huy dat ve.\n";
        return;
    }
    
    // Thanh toán
    cout << "\n=== THONG TIN THANH TOAN ===\n";
    cout << "Tong tien: " << fixed << setprecision(0) << tongTien << " VND\n";
    cout << "So tai khoan: 99999999999\n";
    cout << "Ngan hang: MB Bank\n";
    cout << "Chu tai khoan: Nguyen Van A\n";
    cout << "\nSau khi chuyen khoan, nhan Enter de tiep tuc...\n";
    cin.get();
    
    // Tạo và gửi mã xác nhận
    string maXacNhan = taoMaXacNhan();
    cout << "\nMa xac nhan da duoc gui den email " << email << endl;
    cout << "(Ma xac nhan demo: " << maXacNhan << ")\n";
    cout << "Nhap ma xac nhan: ";
    string maNhap;
    cin >> maNhap;
    
    if (maNhap == maXacNhan) {
        // Tạo phiếu đặt vé
        PhieuDatVe phieu(soLuongVe, chuyenTauChon->giaVe, hk);
        dsphieudatve.push_back(phieu);
        
        // Tạo các vé
        for (int i = 0; i < soLuongVe; i++) {
            string maVe = taoMaXacNhan();
            Ve veNew(maVe, chuyenTauChon->giaVe, *chuyenTauChon);
            veNew.hanhkhach = hk;
            dsveta.push_back(veNew); 
        }  
        
        // Giảm số ghế
        chuyenTauChon->soGhe -= soLuongVe;
        
        cout << "\n=== DAT VE THANH CONG ===\n";
        cout << "Da dat thanh cong " << soLuongVe << " ve cho chuyen tau " << matau << "!\n";
        cout << "\nThong tin phieu dat ve:\n";
        phieu.hienThiVe();
        
    } else {
        cout << "\nMa xac nhan khong dung! Dat ve that bai.\n";
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
        return;
    }
    
    cout << "\n=== DANH SACH VE CUA BAN ===\n";
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
    
    cout << "\nNhap ma tau can huy: ";
    string matau;
    getline(cin, matau);

       // ĐẾM SỐ LƯỢNG VÉ CỦA CHUYẾN TÀU NÀY
    int soLuongVe = 0;
    for (size_t idx : danhSachVe) {
        if (dsveta[idx].chuyentau.maTau == matau) {
            soLuongVe++;
        }
    }
    
    if (soLuongVe == 0) {
        cout << "Khong tim thay ve voi ma tau: " << matau << endl;
        return;
    }
    
    for (size_t idx : danhSachVe) {
        if (dsveta[idx].chuyentau.maTau == matau) {
            cout << "\n=== THONG TIN HOAN TIEN ===\n";
            cout << "So luong ve: " << soLuongVe << endl;
            // Tính tiền hoàn
            long tienHoan = dsveta[idx].chuyentau.giaVe * soLuongVe;
            cout << "Tong tien hoan: " << fixed << setprecision(0) << tienHoan << " VND\n";
            cout << string(50, '-') << endl;

            cout << "Nhap so tai khoan: ";
            string stk;
            getline(cin, stk);
            cout << "Nhap ten ngan hang: ";
            string nganHang;
            getline(cin, nganHang);
            
            // Hoan tra ghe
            for (auto& ct : dschuyentau) {
                if (ct.maTau == matau) {
                    ct.soGhe += soLuongVe;
                    break;
                }
            }
            
            // Xóa vé khỏi danh sách chuyến tàu
            for (int i = dsveta.size() - 1; i >= 0; i--) {
                if (dsveta[i].hanhkhach.getCCCD() == cccd && 
                    dsveta[i].chuyentau.maTau == matau) {
                    dsveta.erase(dsveta.begin() + i);
                }
            }
            
            cout << "\nDa huy thanh cong " << soLuongVe << " ve!\n";
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
        if (ve.hanhkhach.getCCCD() == cccd) {
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
                 << setw(12) << hk.getNgaySinh() 
                 << setw(30) << hk.getEmail() << endl;
            foundTrain = true;
        }
    }

    if (!foundTrain) {
        cout << "Khong co hanh khach nao tren chuyen tau nay.\n";
    }
}
// hàm thêm nhân viên 
void themNhanVien() {
    if (!xacminhmatkhau()) return;
    
    do {
        string username, password, hoTen, ngaySinh, diaChi, dienThoai, email;
        cin.ignore();
        
        cout << "=== THEM NHAN VIEN ===\n";
        cout << "Nhap username: ";
        getline(cin, username);
        
        // kiểm tra xem username đã tồn tại chưa
        bool exists = false;
        for (const auto& nv : dsnhanvien) {
            if (nv.getUsername() == username) {
                cout << "Username da ton tai!\n";
                exists = true;
                break;
            }
        }
        if (exists) continue;
        
        cout << "Nhap password: ";
        getline(cin, password);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        
        do {
            cout << "Nhap so dien thoai (10-11 so): ";
            getline(cin, dienThoai);
            if (!kiemTraSDT(dienThoai)) {
                cout << "So dien thoai khong hop le!\n";
            }
        } while (!kiemTraSDT(dienThoai));
        
        do {
            cout << "Nhap email: ";
            getline(cin, email);
            if (!kiemTraEmail(email)) {
                cout << "Email khong hop le!\n";
            }
        } while (!kiemTraEmail(email));
        
        dsnhanvien.push_back(NhanVien(username, password, hoTen, ngaySinh, diaChi, dienThoai, email));
        cout << "Da them nhan vien thanh cong!\n";
        
        cout << "Nhap 'a' de them nhan vien khac hoac phim bat ky de quay ve menu: ";
        string choice;
        cin >> choice;
        if (choice != "a" && choice != "A") break;
    } while (true);
}
// Hiển thị danh sách nhân viên
void danhSachNhanVien() {
    if (!xacminhmatkhau()) return;
    
    if (dsnhanvien.empty()) {
        cout << "Danh sach nhan vien trong!\n";
        return;
    }
    
    cout << "\n=== DANH SACH NHAN VIEN ===\n";
    cout << left << setw(20) << "Username"
         << setw(30) << "Ho Ten"
         << setw(15) << "Ngay Sinh"
         << setw(40) << "Dia Chi"
         << setw(15) << "Dien Thoai"
         << "Email" << endl;
    cout << string(100, '-') << endl;
    
    for (const auto& nv : dsnhanvien) {
        cout << left << setw(20) << nv.getUsername()
             << setw(30) << nv.getHoTen()
             << setw(15) << nv.getNgaySinh()
             << setw(40) << nv.getDiaChi()
             << setw(15) << nv.getDienThoai()
             << nv.getEmail() << endl;
    }
}

// Hàm xem danh sách phiếu đặt vé theo CCCD
void xemPhieuDatVe() {
    string cccd;
    cin.ignore();
    cout << "Nhap CCCD de xem phieu dat ve: ";
    getline(cin, cccd);
    
    bool found = false;
    cout << "\n=== DANH SACH PHIEU DAT VE ===\n";
    
    for (size_t i = 0; i < dsphieudatve.size(); i++) {
        // Lấy CCCD từ hành khách trong phiếu
        if (dsphieudatve[i].getHanhKhach().getCCCD() == cccd) {
            cout << "\n--- Phieu thu " << (i+1) << " ---\n";
            cout << endl;
            dsphieudatve[i].hienThiVe();
            cout << "\nThong tin hanh khach:\n";
            dsphieudatve[i].xemThongTinHanhKhach();
            cout << string(80, '-') << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Khong tim thay phieu dat ve nao voi CCCD: " << cccd << "\n";
    }
}
int main() {
    // Khởi tạo ngẫu nhiên 
    srand(time(0));
    loadData("loadData.txt", dsgatau, dschuyentau);
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
        cout << "11. Them nhan vien\n";
        cout << "12. Xem danh sach nhan vien\n";
        cout << "13. Xem phieu dat ve\n";
        cout << "14. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        
        switch(choice) {
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
                        break;
                    }
                }
                if (!found) {
                    cout << "Khong tim thay hanh khach voi CCCD nay.\n";
                }
                break;
            }
            case 11:
                themNhanVien();
                break;
            case 12:
                danhSachNhanVien();
                break;
            case 13: 
                xemPhieuDatVe();
                break;
            case 14:
                cout << "\nCam on ban da su dung he thong!\n";
                cout << "Hen gap lai!\n";
                break;
            default:
                cout << "\nLua chon khong hop le! Vui long chon lai.\n";
        }
        
        if (choice != 14) {
            cout << "\nNhan Enter de tiep tuc...";
            cin.ignore();
            cin.get(); // Đợi người dùng nhấn Enter
        }
        
    } while(choice != 14); 
    saveData("saveData.txt", dsgatau, dschuyentau, dsveta);
    return 0;
}

