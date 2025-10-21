

// Class Xe gửi lên tàu
class XeGuiTau {
private:
    string maXe;
    string bienSo;
    string loaiXe; // Xe may, Xe dap
    string cccdChuXe;
    string maTau;
    double phiGui;
    static int demXe;


public:
    XeGuiTau(string bs, string loai, string cccd, string ma) {
        demXe++;
        maXe = "XE" + to_string(demXe);
        bienSo = bs;
        loaiXe = loai;
        cccdChuXe = cccd;
        maTau = ma;
        phiGui = (loai == "Xe may") ? 50000 : 20000;
    }
   
    string getMaXe() const { return maXe; }
    string getBienSo() const { return bienSo; }
    string getLoaiXe() const { return loaiXe; }
    string getCCCD() const { return cccdChuXe; }
    string getMaTau() const { return maTau; }
    double getPhiGui() const { return phiGui; }
};


int XeGuiTau::demXe = 0;


vector<XeGuiTau> dsxegui;




// Ham kiem tra bien so hop le
bool kiemTraBienSo(const string& bienSo) {
    if (bienSo.length() < 7 || bienSo.length() > 10) {
        return false;
    }
    bool coChu = false, coSo = false;
    for (char c : bienSo) {
        if (isalpha(c)) coChu = true;
        if (isdigit(c)) coSo = true;
    }
    return coChu && coSo;
}


// Ham lay ma tau tu ve da mua
string layMaTauTuVe(const string& cccd) {
    for (const auto& ve : dsveta) {
        if (ve.getCCCD() == cccd) {
            return ve.getMaTau();
        }
    }
    return "";
}


// Ham kiem tra xe da gui
bool kiemTraXeDaGui(const string& bienSo, const string& maTau) {
    for (const auto& xe : dsxegui) {
        if (xe.getBienSo() == bienSo && xe.getMaTau() == maTau) {
            return true;
        }
    }
    return false;
}




// Ham gui xe len tau
void guiXeLenTau() {
    if (dsveta.empty()) {
        cout << "Ban chua dat ve tau nao!\n";
        return;
    }
   
    string cccd;
    cin.ignore();
    cout << "=== DICH VU GUI XE LEN TAU ===\n";
    cout << "Nhap CCC
    D cua ban: ";
    getline(cin, cccd);
   
    // Kiem tra da mua ve chua
    if (!kiemTraDaMuaVe(cccd)) {
        cout << "Ban chua mua ve tau! Vui long mua ve truoc khi gui xe.\n";
        return;
    }
   
    // Lay ma tau tu ve da mua
    string maTau = layMaTauTuVe(cccd);
    cout << "Ban da mua ve tau " << maTau << ". Xe se duoc gui len tau nay.\n";
   
    // Nhap thong tin xe
    string bienSo, loaiXe;
   
    do {
        cout << "Nhap bien so xe: ";
        getline(cin, bienSo);
        if (!kiemTraBienSo(bienSo)) {
            cout << "Bien so khong hop le! Vui long nhap lai.\n";
        } else if (kiemTraXeDaGui(bienSo, maTau)) {
            cout << "Bien so nay da duoc gui len tau " << maTau << " roi!\n";
            return;
        } else {
            break;
        }
    } while (true);
   
    cout << "Chon loai xe:\n";
    cout << "1. Xe may (Phi gui: 50,000 VND)\n";
    cout << "2. Xe dap (Phi gui: 20,000 VND)\n";
    cout << "Lua chon cua ban: ";
    int chon;
    cin >> chon;
    cin.ignore();
   
    if (chon == 1) {
        loaiXe = "Xe may";
    } else if (chon == 2) {
        loaiXe = "Xe dap";
    } else {
        cout << "Lua chon khong hop le!\n";
        return;
    }
   
    // Tao phieu gui xe
    XeGuiTau xeMoi(bienSo, loaiXe, cccd, maTau);
    dsxegui.push_back(xeMoi);
   
    cout << "\n=== GUI XE THANH CONG ===\n";
    cout << "Ma phieu gui: " << xeMoi.getMaXe() << endl;
    cout << "Bien so: " << xeMoi.getBienSo() << endl;
    cout << "Loai xe: " << xeMoi.getLoaiXe() << endl;
    cout << "Phi gui: " << fixed << setprecision(0) << xeMoi.getPhiGui() << " VND\n";
    cout << "Vui long thanh toan phi gui xe tai quay truoc khi len tau.\n";
}


// Class Mon an/uong
class MonAn {
private:
    string maMon;
    string tenMon;
    string loaiMon; // Do an, Do uong, Combo
    double giaTien;


public:
    MonAn(string ma, string ten, string loai, double gia) {
        maMon = ma;
        tenMon = ten;
        loaiMon = loai;
        giaTien = gia;
    }
   
    string getMaMon() const { return maMon; }
    string getTenMon() const { return tenMon; }
    string getLoaiMon() const { return loaiMon; }
    double getGiaTien() const { return giaTien; }
   
    void hienThiThongTin() const {
        cout << left << setw(10) << maMon
             << setw(25) << tenMon
             << setw(15) << loaiMon
             << right << setw(12) << fixed << setprecision(0) << giaTien << " VND\n";
    }
};


// Class Don dat do
class DonDatDo {
private:
    string maDon;
    string maTau;
    string soGhe;
    string tenKhach;
    string sdtKhach;
    vector<pair<string, int>> danhSachMon; // <maMon, soLuong>
    double tongTien;
    string trangThai; // Cho xu ly, Dang giao, Da giao
    static int demDon;


public:
    DonDatDo(string ma, string ghe, string ten, string sdt) {
        demDon++;
        maDon = "DD" + to_string(demDon);
        maTau = ma;
        soGhe = ghe;
        tenKhach = ten;
        sdtKhach = sdt;
        tongTien = 0;
        trangThai = "Cho xu ly";
    }
   
    void themMon(string maMon, int soLuong) {
        danhSachMon.push_back({maMon, soLuong});
    }
   
    void tinhTongTien(const vector<MonAn>& menu) {
        tongTien = 0;
        for (const auto& item : danhSachMon) {
            for (const auto& mon : menu) {
                if (mon.getMaMon() == item.first) {
                    tongTien += mon.getGiaTien() * item.second;
                    break;
                }
            }
        }
    }
   
    string getMaDon() const { return maDon; }
    string getMaTau() const { return maTau; }
    string getSoGhe() const { return soGhe; }
    string getTenKhach() const { return tenKhach; }
    string getSDT() const { return sdtKhach; }
    double getTongTien() const { return tongTien; }
    string getTrangThai() const { return trangThai; }
    vector<pair<string, int>> getDanhSachMon() const { return danhSachMon; }
   
    void setTrangThai(string tt) { trangThai = tt; }
};


int DonDatDo::demDon = 0;


vector<MonAn> menu;
vector<DonDatDo> dsDonDat;




// Khoi tao menu mac dinh
void khoiTaoMenu() {
    menu.clear();
    // Do an
    menu.push_back(MonAn("MA01", "Com suon", "Do an", 45000));
    menu.push_back(MonAn("MA02", "Pho bo", "Do an", 50000));
    menu.push_back(MonAn("MA03", "Banh mi thit", "Do an", 25000));
    menu.push_back(MonAn("MA04", "Xoi ga", "Do an", 30000));
    menu.push_back(MonAn("MA05", "Mi tom trung", "Do an", 35000));
   
    // Do uong
    menu.push_back(MonAn("DU01", "Nuoc suoi", "Do uong", 10000));
    menu.push_back(MonAn("DU02", "Coca Cola", "Do uong", 15000));
    menu.push_back(MonAn("DU03", "Ca phe sua", "Do uong", 20000));
    menu.push_back(MonAn("DU04", "Tra dao", "Do uong", 25000));
    menu.push_back(MonAn("DU05", "Nuoc cam", "Do uong", 20000));
   
    // Combo
    menu.push_back(MonAn("CB01", "Combo 1: Com + Nuoc", "Combo", 50000));
    menu.push_back(MonAn("CB02", "Combo 2: Pho + Tra", "Combo", 65000));
    menu.push_back(MonAn("CB03", "Combo 3: Banh mi + Cafe", "Combo", 40000));
}




// Ham hien thi menu
void hienThiMenu() {
    cout << "\n========== MENU DO AN - DO UONG ==========\n";
    cout << left << setw(10) << "Ma Mon"
         << setw(25) << "Ten Mon"
         << setw(15) << "Loai"
         << right << setw(12) << "Gia\n";
    cout << string(62, '-') << endl;
   
    for (const auto& mon : menu) {
        mon.hienThiThongTin();
    }
    cout << string(62, '=') << endl;
}


// Ham dat do an/uong
void datDoAn() {
    cin.ignore();
    cout << "\n=== DAT DO AN/DO UONG ===\n";
   
    string maTau, soGhe, tenKhach, sdt;
   
    cout << "Nhap ma tau: ";
    getline(cin, maTau);
   
    cout << "Nhap so ghe cua ban: ";
    getline(cin, soGhe);
   
    cout << "Nhap ten khach hang: ";
    getline(cin, tenKhach);
   
    cout << "Nhap so dien thoai: ";
    getline(cin, sdt);
   
    // Tao don dat moi
    DonDatDo donMoi(maTau, soGhe, tenKhach, sdt);
   
    // Hien thi menu
    hienThiMenu();
   
    // Dat mon
    char tiepTuc;
    do {
        string maMon;
        int soLuong;
       
        cout << "\nNhap ma mon: ";
        getline(cin, maMon);
       
        // Kiem tra ma mon hop le
        bool hopLe = false;
        for (const auto& mon : menu) {
            if (mon.getMaMon() == maMon) {
                hopLe = true;
                break;
            }
        }
       
        if (!hopLe) {
            cout << "Ma mon khong hop le!\n";
            continue;
        }
       
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cin.ignore();
       
        if (soLuong <= 0) {
            cout << "So luong phai lon hon 0!\n";
            continue;
        }
       
        donMoi.themMon(maMon, soLuong);
        cout << "Da them mon vao don!\n";
       
        cout << "\nTiep tuc dat mon? (c/k): ";
        cin >> tiepTuc;
        cin.ignore();
       
    } while (tiepTuc == 'c' || tiepTuc == 'C');
   
    // Tinh tong tien
    donMoi.tinhTongTien(menu);
   
    // Luu don dat
    dsDonDat.push_back(donMoi);
   
    // Hien thi thong tin don
    cout << "\n========== XAC NHAN DON DAT ==========\n";
    cout << "Ma don: " << donMoi.getMaDon() << endl;
    cout << "Ma tau: " << donMoi.getMaTau() << endl;
    cout << "So ghe: " << donMoi.getSoGhe() << endl;
    cout << "Khach hang: " << donMoi.getTenKhach() << endl;
    cout << "SDT: " << donMoi.getSDT() << endl;
    cout << "\nChi tiet don hang:\n";
   
    for (const auto& item : donMoi.getDanhSachMon()) {
        for (const auto& mon : menu) {
            if (mon.getMaMon() == item.first) {
                cout << "- " << mon.getTenMon() << " x" << item.second
                     << " = " << fixed << setprecision(0)
                     << mon.getGiaTien() * item.second << " VND\n";
                break;
            }
        }
    }
   
    cout << string(38, '-') << endl;
    cout << "TONG TIEN: " << fixed << setprecision(0) << donMoi.getTongTien() << " VND\n";
    cout << "Trang thai: " << donMoi.getTrangThai() << endl;
    cout << string(38, '=') << endl;
    cout << "\nDo an/uong se duoc giao den cho ngoi cua ban!\n";
}




// Ham cap nhat trang thai don
void capNhatTrangThaiDon() {
    if (dsDonDat.empty()) {
        cout << "\nKhong co don dat nao!\n";
        return;
    }
   
    cin.ignore();
    string maDon;
    cout << "\n=== CAP NHAT TRANG THAI DON ===\n";
    cout << "Nhap ma don: ";
    getline(cin, maDon);
   
    bool timThay = false;
    for (auto& don : dsDonDat) {
        if (don.getMaDon() == maDon) {
            timThay = true;
            cout << "\nTrang thai hien tai: " << don.getTrangThai() << endl;
            cout << "\nChon trang thai moi:\n";
            cout << "1. Cho xu ly\n";
            cout << "2. Dang giao\n";
            cout << "3. Da giao\n";
            cout << "Lua chon: ";
           
            int chon;
            cin >> chon;
           
            if (chon == 1) {
                don.setTrangThai("Cho xu ly");
            } else if (chon == 2) {
                don.setTrangThai("Dang giao");
            } else if (chon == 3) {
                don.setTrangThai("Da giao");
            } else {
                cout << "Lua chon khong hop le!\n";
                return;
            }
           
            cout << "Da cap nhat trang thai thanh cong!\n";
            break;
        }
    }
   
    if (!timThay) {
        cout << "Khong tim thay ma don nay!\n";
    }
}





