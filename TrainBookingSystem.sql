CREATE DATABASE TrainBookingSystem;
GO

USE TrainBookingSystem;
GO

-- Tạo bảng Stations 
CREATE TABLE Stations (
    StationID INT PRIMARY KEY IDENTITY(1,1),
    Code NVARCHAR(10) UNIQUE NOT NULL,
    Name NVARCHAR(100) NOT NULL,
    Address NVARCHAR(200),
    Description NVARCHAR(500),
    CreatedDate DATETIME DEFAULT GETDATE()
);
GO

-- Tạo bảng Schedules 
CREATE TABLE Schedules (
    ScheduleID INT PRIMARY KEY IDENTITY(1,1),
    TrainCode NVARCHAR(20) NOT NULL,
    FromStationCode NVARCHAR(10) NOT NULL,
    ToStationCode NVARCHAR(10) NOT NULL,
    DepartureDate DATE NOT NULL,
    DepartureTime TIME NOT NULL,
    ArrivalTime TIME NOT NULL,
    Price DECIMAL(18,2) NOT NULL,
    AvailableSeats INT NOT NULL,
    TotalSeats INT NOT NULL,
    Status NVARCHAR(20) DEFAULT N'Active',
    CreatedDate DATETIME DEFAULT GETDATE(),
    FOREIGN KEY (FromStationCode) REFERENCES Stations(Code),
    FOREIGN KEY (ToStationCode) REFERENCES Stations(Code)
);
GO

-- Insert dữ liệu vào bảng Stations
INSERT INTO Stations (Code, Name, Address, Description) VALUES
(N'HN', N'Hà Nội', N'120 Lê Duẩn, Hoàn Kiếm, Hà Nội', N'Ga trung tâm thủ đô'),
(N'DN', N'Đà Nẵng', N'202 Hải Phòng, Thanh Khê, Đà Nẵng', N'Ga lớn miền Trung'),
(N'SG', N'Sài Gòn', N'1 Nguyễn Thông, Q3, TP.HCM', N'Ga trung tâm TP.HCM'),
(N'HUE', N'Huế', N'2 Bùi Thị Xuân, Huế', N'Ga cố đô Huế'),
(N'NT', N'Nha Trang', N'17 Thái Nguyên, Nha Trang', N'Ga thành phố biển'),
(N'HP', N'Hải Phòng', N'1 Lương Khánh Thiện, Hải Phòng', N'Ga lớn tại thành phố cảng'),
(N'PT', N'Phan Thiết', N'1 Nguyễn Du, Phan Thiết', N'Ga gần biển Phan Thiết'),
(N'QN', N'Quy Nhơn', N'2 Nguyễn Huệ, Quy Nhơn', N'Ga trung tâm thành phố Quy Nhơn'),
(N'TH', N'Thanh Hóa', N'3 Lê Lợi, Thanh Hóa', N'Ga lớn khu vực Bắc Trung Bộ'),
(N'VI', N'Vinh', N'4 Nguyễn Sỹ Sách, Vinh', N'Ga trung chuyển miền Trung'),
(N'NB', N'Ninh Bình', N'10 Hoàng Hoa Thám, Ninh Bình', N'Ga gần Tràng An, Tam Cốc'),
(N'QB', N'Quảng Bình', N'15 Trần Hưng Đạo, Đồng Hới', N'Ga gần động Phong Nha'),
(N'QT', N'Quảng Trị', N'8 Lê Duẩn, Đông Hà', N'Ga lịch sử Quảng Trị'),
(N'QG', N'Quảng Ngãi', N'12 Phan Đình Phùng, Quảng Ngãi', N'Ga trung tâm Quảng Ngãi'),
(N'BT', N'Bình Thuận', N'5 Ngô Quyền, La Gi', N'Ga tỉnh Bình Thuận'),
(N'CT', N'Cần Thơ', N'25 Mậu Thân, Cần Thơ', N'Ga trung tâm miền Tây'),
(N'VT', N'Vũng Tàu', N'88 Nam Kỳ Khởi Nghĩa, Vũng Tàu', N'Ga thành phố biển Vũng Tàu'),
(N'BN', N'Biên Hòa', N'45 Phạm Văn Thuận, Biên Hòa', N'Ga tỉnh Đồng Nai'),
(N'DL', N'Đà Lạt', N'1 Quang Trung, Đà Lạt', N'Ga thành phố ngàn hoa'),
(N'PY', N'Pleiku', N'30 Hùng Vương, Pleiku', N'Ga Tây Nguyên');
GO

INSERT INTO Stations (Code, Name, Address, Description) VALUES
(N'LC', N'Lào Cai', N'306 Khánh Yên, TP. Lào Cai, Lào Cai', N'Ga cửa ngõ đi du lịch Sa Pa, tuyến Hà Nội – Lào Cai'),
(N'ND', N'Nam Định', N'27 Hoàng Hoa Thám, TP. Nam Định', N'Ga lớn vùng đồng bằng sông Hồng'),
(N'HD', N'Hải Dương', N'32 Hồng Quang, TP. Hải Dương', N'Ga trung tâm tỉnh Hải Dương'),
(N'GL', N'Gia Lâm', N'481 Ngọc Lâm, Long Biên, Hà Nội', N'Ga quốc tế nối Trung Quốc'),
(N'YB', N'Yên Bái', N'23 Lý Thường Kiệt, TP. Yên Bái', N'Ga trung chuyển tuyến Hà Nội – Lào Cai'),
(N'PTB', N'Phủ Lý', N'Nguyễn Văn Trỗi, TP. Phủ Lý, Hà Nam', N'Ga tỉnh Hà Nam, nằm giữa Hà Nội và Nam Định'),
(N'TQ', N'Tuyên Quang', N'Thị trấn Tuyên Quang, Tuyên Quang', N'Ga kết nối miền núi phía Bắc'),
(N'TY', N'Tuy Hòa', N'149 Lê Trung Kiên, TP. Tuy Hòa, Phú Yên', N'Ga tỉnh Phú Yên, trên tuyến Bắc – Nam'),
(N'DT', N'Diêu Trì', N'Thị trấn Diêu Trì, Tuy Phước, Bình Định', N'Ga trung chuyển lớn của Bình Định'),
(N'QNA', N'Quảng Nam', N'Phường Tân Thạnh, TP. Tam Kỳ, Quảng Nam', N'Ga Tam Kỳ – trung tâm tỉnh Quảng Nam'),
(N'KH', N'Khánh Hòa', N'17 Thái Nguyên, Nha Trang, Khánh Hòa', N'Ga du lịch lớn miền Trung'),
(N'QB2', N'Đồng Hới', N'15 Trần Hưng Đạo, Đồng Hới, Quảng Bình', N'Ga gần khu du lịch Phong Nha – Kẻ Bàng'),
(N'QT2', N'Đông Hà', N'8 Lê Duẩn, Đông Hà, Quảng Trị', N'Ga lịch sử miền Trung'),
(N'BD', N'Bình Định', N'2 Nguyễn Huệ, TP. Quy Nhơn', N'Ga trung tâm Quy Nhơn'),
(N'LD', N'Long Định', N'Huyện Châu Thành, Tiền Giang', N'Ga tỉnh Tiền Giang trên tuyến nối Sài Gòn – Cần Thơ (dự kiến)'),
(N'TN', N'Tây Ninh', N'20 Cách Mạng Tháng 8, TP. Tây Ninh', N'Ga giả lập mô phỏng tuyến cao tốc tương lai'),
(N'CM', N'Cà Mau', N'1 Phan Ngọc Hiển, TP. Cà Mau', N'Ga dự kiến mở rộng trong tương lai miền cực Nam');
GO


-- Insert dữ liệu vào bảng Schedules (Tháng 10-11/2025)
INSERT INTO Schedules (TrainCode, FromStationCode, ToStationCode, DepartureDate, DepartureTime, ArrivalTime, Price, AvailableSeats, TotalSeats, Status) VALUES
(N'SE1', N'HN', N'DN', '2025-10-20', '19:00', '10:30', 550000, 50, 80, N'Active'),
(N'SE2', N'HN', N'SG', '2025-10-20', '19:30', '16:00', 850000, 40, 100, N'Active'),
(N'SE3', N'HN', N'HUE', '2025-10-20', '06:00', '18:00', 450000, 60, 90, N'Active'),
(N'SE1R', N'DN', N'HN', '2025-10-20', '20:00', '11:30', 550000, 52, 80, N'Active'),
(N'SE2R', N'SG', N'HN', '2025-10-20', '20:00', '16:30', 850000, 38, 100, N'Active'),
(N'SE3R', N'HUE', N'HN', '2025-10-20', '07:00', '19:00', 450000, 58, 90, N'Active'),

(N'SE4', N'SG', N'NT', '2025-10-21', '07:00', '15:00', 320000, 45, 70, N'Active'),
(N'SE5', N'DN', N'SG', '2025-10-21', '08:00', '18:30', 420000, 55, 85, N'Active'),
(N'SE4R', N'NT', N'SG', '2025-10-21', '16:00', '00:00', 320000, 43, 70, N'Active'),
(N'SE5R', N'SG', N'DN', '2025-10-21', '09:00', '19:30', 420000, 53, 85, N'Active'),

(N'SE6', N'HUE', N'HN', '2025-10-22', '09:00', '21:00', 470000, 48, 90, N'Active'),
(N'SE7', N'SG', N'DN', '2025-10-22', '20:00', '09:00', 800000, 35, 100, N'Active'),
(N'SE6R', N'HN', N'HUE', '2025-10-22', '10:00', '22:00', 470000, 46, 90, N'Active'),
(N'SE7R', N'DN', N'SG', '2025-10-22', '21:00', '10:00', 800000, 33, 100, N'Active'),

(N'SE8', N'NT', N'SG', '2025-10-23', '05:30', '13:00', 350000, 40, 70, N'Active'),
(N'SE9', N'HP', N'HN', '2025-10-23', '06:00', '09:00', 200000, 60, 80, N'Active'),

(N'SE8R', N'SG', N'NT', '2025-10-23', '14:00', '22:00', 350000, 38, 70, N'Active'),
(N'SE9R', N'HN', N'HP', '2025-10-23', '10:00', '13:00', 200000, 58, 80, N'Active'),

(N'SE10', N'PT', N'SG', '2025-10-24', '14:00', '19:00', 300000, 30, 60, N'Active'),
(N'SE11', N'QN', N'DN', '2025-10-24', '07:00', '15:00', 400000, 25, 65, N'Active'),
(N'SE10R', N'SG', N'PT', '2025-10-24', '08:00', '13:00', 300000, 28, 60, N'Active'),
(N'SE11R', N'DN', N'QN', '2025-10-24', '16:00', '00:00', 400000, 23, 65, N'Active'),

(N'SE12', N'TH', N'VI', '2025-10-25', '10:00', '13:00', 180000, 50, 75, N'Active'),
(N'SE13', N'HN', N'NB', '2025-10-25', '08:00', '10:30', 150000, 65, 80, N'Active'),
(N'SE12R', N'VI', N'TH', '2025-10-25', '14:00', '17:00', 180000, 48, 75, N'Active'),
(N'SE13R', N'NB', N'HN', '2025-10-25', '11:00', '13:30', 150000, 63, 80, N'Active'),

(N'SE14', N'HN', N'VI', '2025-10-26', '07:30', '12:00', 280000, 55, 85, N'Active'),
(N'SE15', N'SG', N'PT', '2025-10-26', '06:00', '10:30', 280000, 48, 70, N'Active'),

(N'SE14R', N'VI', N'HN', '2025-10-26', '13:00', '17:30', 280000, 53, 85, N'Active'),
(N'SE15R', N'PT', N'SG', '2025-10-26', '11:00', '15:30', 280000, 46, 70, N'Active'),

(N'SE16', N'DN', N'HUE', '2025-10-27', '09:00', '12:00', 220000, 58, 80, N'Active'),
(N'SE17', N'HUE', N'DN', '2025-10-27', '14:00', '17:00', 220000, 62, 80, N'Active'),
(N'SE18', N'HN', N'TH', '2025-10-28', '06:30', '09:30', 200000, 70, 90, N'Active'),
(N'SE19', N'VI', N'HN', '2025-10-28', '15:00', '19:30', 290000, 45, 85, N'Active'),
(N'SE18R', N'TH', N'HN', '2025-10-28', '10:00', '13:00', 200000, 68, 90, N'Active'),
(N'SE19R', N'HN', N'VI', '2025-10-28', '08:00', '12:30', 290000, 43, 85, N'Active'),
(N'SE20', N'SG', N'VT', '2025-10-29', '07:00', '09:30', 180000, 55, 75, N'Active'),
(N'SE20R', N'VT', N'SG', '2025-10-29', '10:00', '12:30', 180000, 53, 75, N'Active'),
(N'SE21', N'HN', N'SG', '2025-11-01', '19:00', '15:30', 850000, 38, 100, N'Active'),
(N'SE22', N'SG', N'HN', '2025-11-01', '19:30', '16:00', 850000, 42, 100, N'Active'),
(N'SE23', N'DN', N'NT', '2025-11-02', '08:00', '14:00', 350000, 50, 70, N'Active'),
(N'SE24', N'NT', N'DN', '2025-11-02', '16:00', '22:00', 350000, 48, 70, N'Active'),
(N'SE25', N'HN', N'HP', '2025-11-03', '07:00', '10:00', 200000, 65, 80, N'Active'),
(N'SE26', N'HP', N'HN', '2025-11-03', '14:00', '17:00', 200000, 58, 80, N'Active'),
(N'SE27', N'HUE', N'SG', '2025-11-04', '18:00', '10:00', 680000, 45, 95, N'Active'),
(N'SE28', N'SG', N'HUE', '2025-11-04', '19:00', '11:00', 680000, 40, 95, N'Active'),
(N'SE29', N'HN', N'QB', '2025-11-05', '06:00', '14:00', 420000, 52, 85, N'Active'),
(N'SE30', N'QB', N'HN', '2025-11-05', '16:00', '00:00', 420000, 48, 85, N'Active'),
(N'TN1', N'HN', N'NB', '2025-11-06', '06:00', '08:30', 150000, 70, 80, N'Active'),
(N'TN2', N'NB', N'HN', '2025-11-06', '16:00', '18:30', 150000, 68, 80, N'Active'),
(N'TN3', N'TH', N'VI', '2025-11-07', '07:00', '10:00', 180000, 60, 75, N'Active'),
(N'TN4', N'VI', N'TH', '2025-11-07', '15:00', '18:00', 180000, 55, 75, N'Active'),
(N'TN5', N'DN', N'QN', '2025-11-08', '08:00', '12:00', 280000, 45, 65, N'Active'),
(N'TN6', N'QN', N'DN', '2025-11-08', '14:00', '18:00', 280000, 42, 65, N'Active'),
(N'TN7', N'SG', N'BN', '2025-11-09', '07:00', '08:30', 120000, 75, 80, N'Active'),
(N'TN8', N'BN', N'SG', '2025-11-09', '17:00', '18:30', 120000, 72, 80, N'Active'),
(N'TN9', N'PT', N'NT', '2025-11-10', '06:00', '11:00', 320000, 38, 60, N'Active'),
(N'TN10', N'NT', N'PT', '2025-11-10', '14:00', '19:00', 320000, 35, 60, N'Active'),
(N'SP1', N'HN', N'SG', '2025-11-15', '08:00', '04:00', 920000, 30, 120, N'Active'),
(N'SP2', N'SG', N'HN', '2025-11-15', '08:30', '04:30', 920000, 28, 120, N'Active'),
(N'SP3', N'HN', N'DN', '2025-11-16', '10:00', '20:00', 580000, 45, 100, N'Active'),
(N'SP4', N'DN', N'HN', '2025-11-16', '10:30', '21:00', 580000, 42, 100, N'Active'),
(N'SP5', N'SG', N'NT', '2025-11-17', '06:00', '14:00', 350000, 55, 85, N'Active'),
(N'SP6', N'NT', N'SG', '2025-11-17', '15:00', '23:00', 350000, 52, 85, N'Active'),
(N'SE31', N'HN', N'QG', '2025-11-20', '07:00', '18:00', 520000, 48, 80, N'Active'),
(N'SE32', N'QG', N'HN', '2025-11-20', '19:00', '06:00', 520000, 45, 80, N'Active'),
(N'SE33', N'SG', N'CT', '2025-11-21', '08:00', '12:00', 280000, 60, 90, N'Active'),
(N'SE34', N'CT', N'SG', '2025-11-21', '15:00', '19:00', 280000, 58, 90, N'Active'),
(N'SE35', N'HN', N'DL', '2025-11-22', '06:00', '22:00', 780000, 35, 70, N'Active'),
(N'SE36', N'DL', N'HN', '2025-11-22', '07:00', '23:00', 780000, 32, 70, N'Active');
GO

INSERT INTO Schedules 
(TrainCode, FromStationCode, ToStationCode, DepartureDate, DepartureTime, ArrivalTime, Price, AvailableSeats, TotalSeats, Status)
VALUES
(N'MB01', N'HN', N'LC', '2025-10-20', '06:00', '12:00', 350000, 70, 100, N'Active'),
(N'MB01R', N'LC', N'HN', '2025-10-20', '14:00', '20:00', 350000, 68, 100, N'Active'),

(N'MB02', N'HN', N'YB', '2025-10-22', '07:00', '11:00', 250000, 80, 90, N'Active'),
(N'MB02R', N'YB', N'HN', '2025-10-22', '13:00', '17:00', 250000, 78, 90, N'Active'),

(N'MB03', N'HD', N'ND', '2025-10-24', '08:00', '09:30', 120000, 60, 70, N'Active'),
(N'MB03R', N'ND', N'HD', '2025-10-24', '15:00', '16:30', 120000, 59, 70, N'Active'),

(N'MB04', N'HN', N'TQ', '2025-10-26', '06:30', '09:30', 180000, 75, 80, N'Active'),
(N'MB04R', N'TQ', N'HN', '2025-10-26', '14:00', '17:00', 180000, 73, 80, N'Active'),

(N'MB05', N'HN', N'PTB', '2025-10-28', '07:00', '08:30', 100000, 85, 90, N'Active'),
(N'MB05R', N'PTB', N'HN', '2025-10-28', '17:00', '18:30', 100000, 84, 90, N'Active'),

(N'MB06', N'GL', N'LC', '2025-10-30', '05:30', '11:30', 320000, 68, 85, N'Active'),
(N'MB06R', N'LC', N'GL', '2025-10-30', '13:00', '19:00', 320000, 67, 85, N'Active'),

(N'MT01', N'DT', N'KH', '2025-11-01', '08:00', '10:00', 150000, 55, 70, N'Active'),
(N'MT01R', N'KH', N'DT', '2025-11-01', '15:00', '17:00', 150000, 53, 70, N'Active'),

(N'MT02', N'QNA', N'DN', '2025-11-03', '07:00', '09:30', 130000, 60, 80, N'Active'),
(N'MT02R', N'DN', N'QNA', '2025-11-03', '13:00', '15:30', 130000, 58, 80, N'Active'),

(N'MT03', N'KH', N'TY', '2025-11-05', '09:00', '11:00', 140000, 65, 75, N'Active'),
(N'MT03R', N'TY', N'KH', '2025-11-05', '14:00', '16:00', 140000, 63, 75, N'Active'),

(N'MT04', N'QB2', N'QT2', '2025-11-07', '06:00', '08:00', 160000, 68, 80, N'Active'),
(N'MT04R', N'QT2', N'QB2', '2025-11-07', '10:00', '12:00', 160000, 66, 80, N'Active'),

(N'MT05', N'KH', N'BD', '2025-11-09', '08:30', '10:30', 170000, 72, 90, N'Active'),
(N'MT05R', N'BD', N'KH', '2025-11-09', '14:30', '16:30', 170000, 70, 90, N'Active'),

(N'MN01', N'SG', N'TN', '2025-11-10', '07:00', '09:30', 190000, 60, 80, N'Active'),
(N'MN01R', N'TN', N'SG', '2025-11-10', '16:00', '18:30', 190000, 59, 80, N'Active'),

(N'MN02', N'SG', N'CM', '2025-11-12', '06:30', '13:30', 400000, 55, 100, N'Active'),
(N'MN02R', N'CM', N'SG', '2025-11-12', '15:00', '22:00', 400000, 52, 100, N'Active'),

(N'MN03', N'SG', N'LD', '2025-11-15', '09:00', '11:00', 100000, 75, 85, N'Active'),
(N'MN03R', N'LD', N'SG', '2025-11-15', '15:00', '17:00', 100000, 74, 85, N'Active'),

(N'MN04', N'TN', N'CM', '2025-11-18', '08:00', '15:00', 350000, 50, 80, N'Active'),
(N'MN04R', N'CM', N'TN', '2025-11-18', '16:00', '23:00', 350000, 48, 80, N'Active'),

(N'MN05', N'LD', N'CM', '2025-11-22', '07:30', '13:00', 320000, 45, 70, N'Active'),
(N'MN05R', N'CM', N'LD', '2025-11-22', '14:30', '20:00', 320000, 44, 70, N'Active');
GO

INSERT INTO Schedules 
(TrainCode, FromStationCode, ToStationCode, DepartureDate, DepartureTime, ArrivalTime, Price, AvailableSeats, TotalSeats, Status)
VALUES
(N'SE37', N'HN', N'DN', '2025-11-04', '07:00', '20:00', 550000, 60, 100, N'Active'),
(N'SE38', N'DN', N'HN', '2025-11-04', '21:00', '10:00', 550000, 58, 100, N'Active'),
(N'SE39', N'SG', N'NT', '2025-11-05', '06:30', '13:00', 320000, 50, 80, N'Active'),
(N'SE40', N'NT', N'SG', '2025-11-05', '14:00', '20:30', 320000, 48, 80, N'Active'),
(N'SE41', N'HUE', N'DN', '2025-11-06', '09:00', '12:00', 220000, 65, 85, N'Active'),
(N'SE42', N'DN', N'HUE', '2025-11-06', '13:00', '16:00', 220000, 63, 85, N'Active'),
(N'SE43', N'HN', N'SG', '2025-11-11', '19:00', '16:00', 850000, 40, 100, N'Active'),
(N'SE44', N'SG', N'HN', '2025-11-11', '19:30', '16:30', 850000, 38, 100, N'Active'),
(N'SE45', N'HN', N'HUE', '2025-11-12', '06:00', '18:00', 470000, 55, 90, N'Active'),
(N'SE46', N'HUE', N'HN', '2025-11-12', '07:00', '19:00', 470000, 52, 90, N'Active'),
(N'SE47', N'SG', N'DN', '2025-11-13', '20:00', '09:00', 800000, 35, 100, N'Active'),
(N'SE48', N'DN', N'SG', '2025-11-13', '21:00', '10:00', 800000, 33, 100, N'Active'),
(N'SE49', N'HN', N'HP', '2025-11-16', '06:30', '09:30', 200000, 68, 80, N'Active'),
(N'SE50', N'HP', N'HN', '2025-11-16', '14:00', '17:00', 200000, 64, 80, N'Active'),
(N'SE51', N'SG', N'VT', '2025-11-18', '07:00', '09:30', 180000, 60, 75, N'Active'),
(N'SE52', N'VT', N'SG', '2025-11-18', '10:00', '12:30', 180000, 58, 75, N'Active'),
(N'SE53', N'HN', N'TH', '2025-11-19', '06:30', '09:30', 200000, 72, 90, N'Active'),
(N'SE54', N'TH', N'HN', '2025-11-19', '10:00', '13:00', 200000, 70, 90, N'Active'),
(N'SE55', N'SG', N'CT', '2025-11-21', '08:00', '12:00', 280000, 65, 90, N'Active'),
(N'SE56', N'CT', N'SG', '2025-11-21', '15:00', '19:00', 280000, 60, 90, N'Active'),
(N'SE57', N'HN', N'QG', '2025-11-22', '07:00', '18:00', 520000, 48, 80, N'Active'),
(N'SE58', N'QG', N'HN', '2025-11-22', '19:00', '06:00', 520000, 45, 80, N'Active'),
(N'SE59', N'SG', N'PT', '2025-11-23', '07:00', '11:00', 300000, 52, 70, N'Active'),
(N'SE60', N'PT', N'SG', '2025-11-23', '14:00', '18:00', 300000, 50, 70, N'Active'),
(N'SE61', N'HN', N'DN', '2025-11-26', '07:00', '20:00', 550000, 55, 100, N'Active'),
(N'SE62', N'DN', N'HN', '2025-11-26', '21:00', '10:00', 550000, 52, 100, N'Active'),
(N'SE63', N'SG', N'HUE', '2025-11-27', '19:00', '10:00', 680000, 45, 95, N'Active'),
(N'SE64', N'HUE', N'SG', '2025-11-27', '19:30', '11:00', 680000, 43, 95, N'Active'),
(N'SE65', N'HN', N'SG', '2025-11-29', '19:00', '15:30', 850000, 40, 100, N'Active'),
(N'SE66', N'SG', N'HN', '2025-11-29', '19:30', '16:00', 850000, 38, 100, N'Active'),
(N'SE67', N'HN', N'HP', '2025-11-30', '06:00', '09:00', 200000, 60, 80, N'Active'),
(N'SE68', N'HP', N'HN', '2025-11-30', '14:00', '17:00', 200000, 58, 80, N'Active');
GO


-- Tạo bảng Menu (Dịch vụ ăn uống)
CREATE TABLE Menu (
    MenuID INT PRIMARY KEY IDENTITY(1,1),
    ItemCode NVARCHAR(10) UNIQUE NOT NULL,
    ItemName NVARCHAR(100) NOT NULL,
    Category NVARCHAR(50) NOT NULL,
    Price DECIMAL(18,2) NOT NULL,
    IsAvailable BIT DEFAULT 1,
    CreatedDate DATETIME DEFAULT GETDATE()
);
GO

-- Insert dữ liệu vào bảng Menu
INSERT INTO Menu (ItemCode, ItemName, Category, Price) VALUES
-- Đồ ăn
(N'MA01', N'Phở bò', N'Do an', 50000),
(N'MA02', N'Bánh mì thịt', N'Do an', 25000),
(N'MA03', N'Cơm sườn', N'Do an', 45000),
(N'MA04', N'Xôi gà', N'Do an', 30000),
(N'MA05', N'Mì tôm trứng', N'Do an', 35000),
-- Đồ uống
(N'DU01', N'Nước lọc', N'Do uong', 5000),
(N'DU02', N'Coca Cola', N'Do uong', 15000),
(N'DU03', N'Cà phê sữa', N'Do uong', 20000),
(N'DU04', N'Trà đào', N'Do uong', 25000),
(N'DU05', N'Nước cam', N'Do uong', 20000),
-- Combo
(N'CB01', N'Combo 1: Cơm + Nước', N'Combo', 50000),
(N'CB02', N'Combo 2: Phở + Trà', N'Combo', 65000),
(N'CB03', N'Combo 3: Bánh mì + Cafe', N'Combo', 40000);
GO

-- Tạo bảng Bookings 
CREATE TABLE Bookings (
    BookingID INT PRIMARY KEY IDENTITY(1,1),
    ScheduleID INT NOT NULL,
    CustomerName NVARCHAR(100) NOT NULL,
    CustomerPhone NVARCHAR(20) NOT NULL,
    CustomerEmail NVARCHAR(100),
    NumberOfSeats INT NOT NULL,
    TotalAmount DECIMAL(18,2) NOT NULL,
    BookingDate DATETIME DEFAULT GETDATE(),
    Status NVARCHAR(20) DEFAULT N'Confirmed',
    FOREIGN KEY (ScheduleID) REFERENCES Schedules(ScheduleID)
);
GO

-- Tạo bảng OrderDetails 
CREATE TABLE OrderDetails (
    OrderID INT PRIMARY KEY IDENTITY(1,1),
    BookingID INT NOT NULL,
    MenuItemCode NVARCHAR(10) NOT NULL,
    Quantity INT NOT NULL,
    UnitPrice DECIMAL(18,2) NOT NULL,
    TotalPrice DECIMAL(18,2) NOT NULL,
    OrderDate DATETIME DEFAULT GETDATE(),
    FOREIGN KEY (BookingID) REFERENCES Bookings(BookingID),
    FOREIGN KEY (MenuItemCode) REFERENCES Menu(ItemCode)
);
GO

-- Index để tối ưu truy vấn
CREATE INDEX IX_Schedules_Date ON Schedules(DepartureDate);
CREATE INDEX IX_Schedules_Stations ON Schedules(FromStationCode, ToStationCode);
CREATE INDEX IX_Schedules_TrainCode ON Schedules(TrainCode);
CREATE INDEX IX_Bookings_Schedule ON Bookings(ScheduleID);
CREATE INDEX IX_Menu_Category ON Menu(Category);
CREATE INDEX IX_OrderDetails_Booking ON OrderDetails(BookingID);
GO

-- 1. Tìm lịch trình từ Hà Nội đến Sài Gòn
SELECT s.TrainCode, s.DepartureDate, s.DepartureTime, s.ArrivalTime, s.Price, s.AvailableSeats
FROM Schedules s
WHERE s.FromStationCode = N'HN' AND s.ToStationCode = N'SG' AND s.Status = N'Active'
ORDER BY s.DepartureDate, s.DepartureTime;

-- 2. Xem thông tin ga tàu và lịch trình của tàu
SELECT * FROM Stations ORDER BY Name;
SELECT * FROM Schedules

-- 3. Kiểm tra chỗ trống của tàu
SELECT s.TrainCode, s.DepartureDate, 
       st1.Name as FromStation, st2.Name as ToStation,
       s.AvailableSeats, s.TotalSeats,
       CAST(s.AvailableSeats * 100.0 / s.TotalSeats AS DECIMAL(5,2)) as PercentAvailable
FROM Schedules s
JOIN Stations st1 ON s.FromStationCode = st1.Code
JOIN Stations st2 ON s.ToStationCode = st2.Code
WHERE s.Status = N'Active'
ORDER BY s.DepartureDate;

-- 4. Xem menu theo danh mục
SELECT ItemCode, ItemName, Category, Price
FROM Menu
WHERE IsAvailable = 1
ORDER BY Category, Price;

-- 5. Xem menu đồ ăn
SELECT ItemCode, ItemName, Price
FROM Menu
WHERE Category = N'Do an' AND IsAvailable = 1
ORDER BY Price;

-- 6. Xem menu đồ uống
SELECT ItemCode, ItemName, Price
FROM Menu
WHERE Category = N'Do uong' AND IsAvailable = 1
ORDER BY Price;

-- 7. Xem các combo
SELECT ItemCode, ItemName, Price
FROM Menu
WHERE Category = N'Combo' AND IsAvailable = 1
ORDER BY Price;

-- 4. Xem menu theo danh mục
SELECT ItemCode, ItemName, Category, Price
FROM Menu
WHERE IsAvailable = 1
ORDER BY Category, Price;

-- 5. Xem menu đồ ăn
SELECT ItemCode, ItemName, Price
FROM Menu
WHERE Category = N'Do an' AND IsAvailable = 1
ORDER BY Price;

-- 6. Xem menu đồ uống
SELECT ItemCode, ItemName, Price
FROM Menu
WHERE Category = N'Do uong' AND IsAvailable = 1
ORDER BY Price;

-- 7. Xem các combo
SELECT ItemCode, ItemName, Price
FROM Menu
WHERE Category = N'Combo' AND IsAvailable = 1
ORDER BY Price;
GO