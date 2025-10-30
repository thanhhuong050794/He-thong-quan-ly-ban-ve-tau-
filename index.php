<?php
header('Content-Type: text/html; charset=UTF-8');
mb_internal_encoding('UTF-8');

include 'ketnoi.php';

// Hàm lấy dữ liệu ga tàu từ database
function getStationsFromDB() {
    global $conn;
    $stations = [];
    
    $sql = "SELECT * FROM Stations ORDER BY Name";
    $result = sqlsrv_query($conn, $sql);
    
    if ($result === false) {
        error_log("Error loading stations: " . print_r(sqlsrv_errors(), true));
        return $stations;
    }
    
    while ($row = sqlsrv_fetch_array($result, SQLSRV_FETCH_ASSOC)) {
        $stations[] = [
            'code' => $row['Code'],
            'name' => mb_convert_encoding($row['Name'], 'UTF-8', 'auto'),
            'address' => mb_convert_encoding($row['Address'] ?? '', 'UTF-8', 'auto'),
            'description' => mb_convert_encoding($row['Description'] ?? '', 'UTF-8', 'auto')
        ];
    }
    
    return $stations;
}

// Hàm lấy lịch trình tàu từ database
function getSchedulesFromDB() {
    global $conn;
    $schedules = [];
    
    $sql = "SELECT s.*, 
                   fs.Name as FromStationName,
                   ts.Name as ToStationName
            FROM Schedules s
            LEFT JOIN Stations fs ON s.FromStationCode = fs.Code
            LEFT JOIN Stations ts ON s.ToStationCode = ts.Code
            WHERE s.Status = 'Active'
            ORDER BY s.DepartureDate, s.DepartureTime";
    $result = sqlsrv_query($conn, $sql);
    
    if ($result === false) {
        error_log("Error loading schedules: " . print_r(sqlsrv_errors(), true));
        return $schedules;
    }
    
    while ($row = sqlsrv_fetch_array($result, SQLSRV_FETCH_ASSOC)) {
        $departureDate = $row['DepartureDate'];
        $departureTime = $row['DepartureTime'];
        $arrivalTime = $row['ArrivalTime'];
        
        // Format date
        $formattedDate = $departureDate->format('d/m/Y');
        $formattedDepartureTime = $departureTime->format('H:i');
        $formattedArrivalTime = $arrivalTime->format('H:i');
        
        $schedules[] = [
            'trainCode' => $row['TrainCode'],
            'fromStation' => mb_convert_encoding($row['FromStationName'], 'UTF-8', 'auto'),
            'toStation' => mb_convert_encoding($row['ToStationName'], 'UTF-8', 'auto'),
            'date' => $formattedDate,
            'departureTime' => $formattedDepartureTime,
            'arrivalTime' => $formattedArrivalTime,
            'price' => (int)$row['Price'],
            'seats' => (int)$row['AvailableSeats']
        ];
    }
    
    return $schedules;
}

// Hàm lấy menu từ database
function getMenuFromDB() {
    global $conn;
    $menu = [];
    
    $sql = "SELECT * FROM Menu WHERE IsAvailable = 1 ORDER BY Category, ItemName";
    $result = sqlsrv_query($conn, $sql);
    
    if ($result === false) {
        error_log("Error loading menu: " . print_r(sqlsrv_errors(), true));
        return $menu;
    }
    
    while ($row = sqlsrv_fetch_array($result, SQLSRV_FETCH_ASSOC)) {
        $menu[] = [
            'id' => $row['ItemCode'],
            'name' => mb_convert_encoding($row['ItemName'], 'UTF-8', 'auto'),
            'category' => mb_convert_encoding($row['Category'], 'UTF-8', 'auto'),
            'price' => (int)$row['Price']
        ];
    }
    
    return $menu;
}

// Xử lý AJAX request
if (isset($_GET['action'])) {
    header('Content-Type: application/json; charset=UTF-8');
    
    try {
        switch ($_GET['action']) {
            case 'get_stations':
                echo json_encode(['success' => true, 'data' => getStationsFromDB()]);
                break;
                
            case 'get_schedules':
                echo json_encode(['success' => true, 'data' => getSchedulesFromDB()]);
                break;
                
            case 'get_menu':
                echo json_encode(['success' => true, 'data' => getMenuFromDB()]);
                break;
                
            case 'get_all_data':
                echo json_encode([
                    'success' => true, 
                    'data' => [
                        'stations' => getStationsFromDB(),
                        'schedules' => getSchedulesFromDB(),
                        'menu' => getMenuFromDB()
                    ]
                ]);
                break;
                
            default:
                echo json_encode(['success' => false, 'message' => 'Invalid action']);
        }
    } catch (Exception $e) {
        echo json_encode(['success' => false, 'message' => 'Database error: ' . $e->getMessage()]);
    }
    exit;
}
?>

<!-- HTML -->
<!DOCTYPE html>
<html lang="vi">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>HỆ THỐNG QUẢN LÝ VÉ TÀU</title>
    <link rel="stylesheet" href="styles.css?v=<?php echo filemtime('styles.css'); ?>">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css" rel="stylesheet">
</head>
<body>
    <div class="container">
        <!-- Header -->
        <header class="header">
            <div class="logo">
                <i class="fas fa-train"></i>
                <h1 class="gradient-text" style="text-align: center; width: 30%;">HỆ THỐNG <br> QUẢN LÝ VÉ TÀU</h1>
            <nav class="nav">
                <button class="nav-btn active" data-section="home">
                    <i class="fas fa-home"></i> Trang chủ
                </button>
                <button class="nav-btn" data-section="stations">
                    <i class="fas fa-building"></i> Ga tàu
                </button>
                <button class="nav-btn" data-section="schedule">
                    <i class="fas fa-clock"></i> Lịch trình
                </button>
                <button class="nav-btn" data-section="booking">
                    <i class="fas fa-ticket-alt"></i> Đặt vé
                </button>
                <button class="nav-btn" data-section="services">
                    <i class="fas fa-concierge-bell"></i> Dịch vụ
                </button>
                <button class="nav-btn" data-section="manage">
                    <i class="fas fa-cog"></i> Quản lý
                </button>
            </nav>
        </header>

        <!-- Main Content -->
        <main class="main-content">
            <!-- Home Section -->
            <section id="home" class="section active">
                <div class="hero">
                    <h2 id="heroTitle" aria-label="Chào mừng đến với Hệ thống quản lý vé tàu">Chào mừng đến với Hệ thống quản lý vé tàu</h2>
                    <p>Đặt vé tàu nhanh chóng, tiện lợi và an toàn</p>
                    <div class="hero-stats">
                        <div class="stat-card">
                            <i class="fas fa-train"></i>
                            <h3><span class="count-up" data-target="134">134</span></h3>
                            <p>Chuyến tàu</p>
                        </div>
                        <div class="stat-card">
                            <i class="fas fa-building"></i>
                            <h3><span class="count-up" data-target="37">37</span></h3>
                            <p>Ga tàu</p>
                        </div>
                        <div class="stat-card">
                            <i class="fas fa-users"></i>
                            <h3><span class="count-up" data-target="5000" data-suffix="+">5000+</span></h3>
                            <p>Hành khách</p>
                        </div>
                    </div>
                </div>
                
                <div class="quick-actions">
                    <h3>Thao tác nhanh</h3>
                    <div class="action-buttons">
                        <button class="action-btn" onclick="showSection('booking')">
                            <i class="fas fa-ticket-alt"></i>
                            Đặt vé ngay
                        </button>
                        <button class="action-btn" onclick="showSection('schedule')">
                            <i class="fas fa-search"></i>
                            Tra cứu lịch trình
                        </button>
                        <button class="action-btn" onclick="showManageBooking()">
                            <i class="fas fa-list"></i>
                            Quản lý vé
                        </button>
                        <button class="action-btn" onclick="showSection('services')">
                            <i class="fas fa-concierge-bell"></i>
                            Dịch vụ
                        </button>
                    </div>
                </div>
            </section>

            <!-- Stations Section -->
            <section id="stations" class="section">
                <div class="section-header">
                    <h2>Quản lý Ga Tàu</h2>
                    <button class="btn btn-primary" onclick="showAddStation()">
                        <i class="fas fa-plus"></i> Thêm ga tàu
                    </button>
                </div>
                
                <div class="search-bar">
                    <input type="text" id="stationSearch" placeholder="Tìm kiếm ga tàu...">
                    <button onclick="searchStations()">
                        <i class="fas fa-search"></i>
                    </button>
                </div>
                
                <div class="stations-grid" id="stationsGrid">
                    <!-- Stations will be loaded here -->
                </div>
            </section>

            <!-- Schedule Section -->
            <section id="schedule" class="section">
                <div class="section-header">
                    <h2>Lịch Trình Tàu</h2>
                </div>
                
                <div class="schedule-filters">
                    <div class="filter-group">
                        <label>Ga đi:</label>
                        <select id="fromStation">
                            <option value="">Tất cả</option>
                        </select>
                    </div>
                    <div class="filter-group">
                        <label>Ga đến:</label>
                        <select id="toStation">
                            <option value="">Tất cả</option>
                        </select>
                    </div>
                    <div class="filter-group">
                        <label>Ngày:</label>
                        <input type="date" id="travelDate">
                    </div>
                    <button class="btn btn-primary" onclick="filterSchedule()">
                        <i class="fas fa-search"></i> Tìm kiếm
                    </button>
                </div>
                
                <div class="schedule-table">
                    <table id="scheduleTable">
                        <thead>
                            <tr>
                                <th>Mã tàu</th>
                                <th>Ga đi</th>
                                <th>Ga đến</th>
                                <th>Ngày</th>
                                <th>Giờ đi</th>
                                <th>Giờ đến</th>
                                <th>Giá vé</th>
                                <th>Số ghế</th>
                                <th>Thao tác</th>
                            </tr>
                        </thead>
                        <tbody id="scheduleTableBody">
                            <!-- Schedule data will be loaded here -->
                        </tbody>
                    </table>
                </div>
            </section>

            <!-- Booking Section -->
            <section id="booking" class="section">
                <div class="section-header">
                    <h2>Đặt Vé Tàu</h2>
                </div>
                
                <div class="booking-form">
                    <div class="form-step active" id="step1">
                        <h3>Bước 1: Chọn chuyến tàu</h3>
                        <div class="trip-search">
                            <div class="form-group">
                                <label>Ga đi:</label>
                                <select id="bookingFromStation" required>
                                    <option value="">Chọn ga đi</option>
                                </select>
                            </div>
                            <div class="form-group">
                                <label>Ga đến:</label>
                                <select id="bookingToStation" required>
                                    <option value="">Chọn ga đến</option>
                                </select>
                            </div>
                            <div class="form-group">
                                <label>Ngày đi:</label>
                                <input type="date" id="bookingDate" required>
                            </div>
                            <button class="btn btn-primary" onclick="searchTrips()">
                                <i class="fas fa-search"></i> Tìm chuyến
                            </button>
                        </div>
                        
                        <div id="tripResults" class="trip-results">
                            <!-- Trip results will be shown here -->
                        </div>
                    </div>
                    
                    <div class="form-step" id="step2">
                        <h3>Bước 2: Thông tin hành khách</h3>
                        <div class="passenger-form">
                            <div class="form-row">
                                <div class="form-group">
                                    <label>Họ tên:</label>
                                    <input type="text" id="passengerName" required>
                                </div>
                                <div class="form-group">
                                    <label>CCCD:</label>
                                    <input type="text" id="passengerCCCD" maxlength="12" required>
                                </div>
                            </div>
                            <div class="form-row">
                                <div class="form-group">
                                    <label>Số điện thoại:</label>
                                    <input type="tel" id="passengerPhone" required>
                                </div>
                                <div class="form-group">
                                    <label>Email:</label>
                                    <input type="email" id="passengerEmail" required>
                                </div>
                            </div>
                            <div class="form-group">
                                <label>Giới tính:</label>
                                <select id="passengerGender">
                                    <option value="Nam">Nam</option>
                                    <option value="Nữ">Nữ</option>
                                </select>
                            </div>
                        </div>
                        <div class="form-actions">
                            <button class="btn btn-secondary" onclick="goToStep(1)">Quay lại</button>
                            <button class="btn btn-primary" onclick="goToStep(3)">Tiếp tục</button>
                        </div>
                    </div>
                    
                    <div class="form-step" id="step3">
                        <h3>Bước 3: Xác nhận và thanh toán</h3>
                        <div class="booking-summary">
                            <div class="summary-card">
                                <h4>Thông tin chuyến tàu</h4>
                                <div id="tripSummary"></div>
                            </div>
                            <div class="summary-card">
                                <h4>Thông tin hành khách</h4>
                                <div id="passengerSummary"></div>
                            </div>
                            <div class="summary-card">
                                <h4>Tổng tiền</h4>
                                <div id="totalAmount"></div>
                            </div>
                        </div>
                        
                        <div class="payment-section">
                            <h4>Thông tin thanh toán</h4>
                            <div class="payment-info">
                                <p><strong>Số tài khoản:</strong> 99999999999</p>
                                <p><strong>Ngân hàng:</strong> MB Bank</p>
                                <p><strong>Chủ tài khoản:</strong> Nguyễn Văn A</p>
                            </div>
                            
                            <div class="verification-section">
                                <label>Mã xác nhận (đã gửi qua email):</label>
                                <input type="text" id="verificationCode" placeholder="Nhập mã xác nhận">
                                <button class="btn btn-primary" onclick="confirmBooking()">
                                    <i class="fas fa-check"></i> Xác nhận đặt vé
                                </button>
                                <button class="btn btn-secondary" onclick="showDemoCode()" style="margin-left: 10px;">
                                    <i class="fas fa-eye"></i> Xem mã demo
                                </button>
                            </div>
                        </div>
                        
                        <div class="form-actions">
                            <button class="btn btn-secondary" onclick="goToStep(2)">Quay lại</button>
                        </div>
                    </div>
                </div>
            </section>

            <!-- Services Section -->
            <section id="services" class="section">
                <div class="section-header">
                    <h2>Dịch Vụ Bổ Sung</h2>
                </div>
                
                <div class="services-tabs">
                    <button class="tab-btn active" data-tab="vehicle-service">
                        <i class="fas fa-car-side tab-icon" aria-hidden="true"></i>
                        Gửi xe lên tàu
                    </button>
                    <button class="tab-btn" data-tab="food-service">
                        <i class="fas fa-utensils tab-icon" aria-hidden="true"></i>
                        Đặt đồ ăn
                    </button>
                    <button class="tab-btn" data-tab="service-management">
                        <i class="fas fa-tools tab-icon" aria-hidden="true"></i>
                        Quản lý dịch vụ
                    </button>
                </div>
                
                <div class="tab-content">
                    <!-- Vehicle Service Tab -->
                    <div class="tab-panel active" id="vehicle-service">
                        <div class="service-form">
                            <h3>Dịch Vụ Gửi Xe Lên Tàu</h3>
                            <div class="form-group">
                                <label>CCCD của bạn:</label>
                                <input type="text" id="vehicleCCCD" placeholder="Nhập CCCD" maxlength="12">
                                <button class="btn btn-secondary" onclick="checkVehicleBooking()">
                                    <i class="fas fa-search"></i> Kiểm tra vé
                                </button>
                            </div>
                            
                            <div id="vehicleBookingInfo" class="booking-info" style="display: none;">
                                <h4>Thông tin vé đã mua:</h4>
                                <div id="vehicleBookingDetails"></div>
                            </div>
                            
                            <div id="vehicleForm" class="vehicle-form" style="display: none;">
                                <h4>Thông tin xe gửi:</h4>
                                <div class="form-row">
                                    <div class="form-group">
                                        <label>Biển số xe:</label>
                                        <input type="text" id="vehiclePlate" placeholder="Nhập biển số xe">
                                    </div>
                                    <div class="form-group">
                                        <label>Loại xe:</label>
                                        <select id="vehicleType">
                                            <option value="">Chọn loại xe</option>
                                            <option value="Xe may">Xe máy (50,000 VND)</option>
                                            <option value="Xe dap">Xe đạp (20,000 VND)</option>
                                        </select>
                                    </div>
                                </div>
                                <div class="vehicle-summary">
                                    <div id="vehicleFeeInfo"></div>
                                </div>
                                <button class="btn btn-primary" onclick="submitVehicleService()">
                                    <i class="fas fa-car"></i> Gửi xe
                                </button>
                            </div>
                        </div>
                    </div>
                    
                    <!-- Food Service Tab -->
                    <div class="tab-panel" id="food-service">
                        <div class="food-service">
                            <h3>Đặt Đồ Ăn/Đồ Uống</h3>
                            <div class="order-form">
                                <div class="form-row">
                                    <div class="form-group">
                                        <label>Mã tàu:</label>
                                        <input type="text" id="foodTrainCode" placeholder="Nhập mã tàu">
                                    </div>
                                    <div class="form-group">
                                        <label>Số ghế:</label>
                                        <input type="text" id="foodSeatNumber" placeholder="Nhập số ghế">
                                    </div>
                                </div>
                                <div class="form-row">
                                    <div class="form-group">
                                        <label>Tên khách hàng:</label>
                                        <input type="text" id="foodCustomerName" placeholder="Nhập tên">
                                    </div>
                                    <div class="form-group">
                                        <label>Số điện thoại:</label>
                                        <input type="tel" id="foodCustomerPhone" placeholder="Nhập SĐT">
                                    </div>
                                </div>
                                
                                <div class="menu-section">
                                    <h4>Menu Đồ Ăn & Đồ Uống</h4>
                                    <div class="menu-categories">
                                        <button class="category-btn active" data-category="all">Tất cả</button>
                                        <button class="category-btn" data-category="Do an">Đồ ăn</button>
                                        <button class="category-btn" data-category="Do uong">Đồ uống</button>
                                        <button class="category-btn" data-category="Combo">Combo</button>
                                    </div>
                                    <div class="menu-grid" id="menuGrid">
                                        <!-- Menu items will be loaded here -->
                                    </div>
                                </div>
                                
                                <div class="order-summary">
                                    <h4>Đơn hàng của bạn</h4>
                                    <div id="orderItems"></div>
                                    <div class="order-total">
                                        <strong>Tổng tiền: <span id="orderTotal">0 VND</span></strong>
                                    </div>
                                    <button class="btn btn-primary" onclick="submitFoodOrder()">
                                        <i class="fas fa-utensils"></i> Đặt món
                                    </button>
                                </div>
                            </div>
                        </div>
                    </div>
                    
                    <!-- Service Management Tab -->
                    <div class="tab-panel" id="service-management">
                        <div class="service-management">
                            <h3>Quản Lý Dịch Vụ</h3>
                            <div class="management-tabs">
                                <button class="sub-tab-btn active" data-sub-tab="vehicle-orders">
                                    <i class="fas fa-car-side tab-icon" aria-hidden="true"></i>
                                    Đơn gửi xe
                                </button>
                                <button class="sub-tab-btn" data-sub-tab="food-orders">
                                    <i class="fas fa-utensils tab-icon" aria-hidden="true"></i>
                                    Đơn đồ ăn
                                </button>
                            </div>
                            
                            <div class="sub-tab-content">
                                <div class="sub-tab-panel active" id="vehicle-orders">
                                    <div class="search-section">
                                        <input type="text" id="vehicleSearch" placeholder="Tìm kiếm theo biển số xe...">
                                        <button onclick="searchVehicleOrders()">
                                            <i class="fas fa-search"></i> Tìm kiếm
                                        </button>
                                    </div>
                                    <div id="vehicleOrdersList"></div>
                                </div>
                                
                                <div class="sub-tab-panel" id="food-orders">
                                    <div class="search-section">
                                        <input type="text" id="foodSearch" placeholder="Tìm kiếm theo tên khách...">
                                        <button onclick="searchFoodOrders()">
                                            <i class="fas fa-search"></i> Tìm kiếm
                                        </button>
                                    </div>
                                    <div class="order-status-filters">
                                        <button class="status-btn active" data-status="all">Tất cả</button>
                                        <button class="status-btn" data-status="Cho xu ly">Chờ xử lý</button>
                                        <button class="status-btn" data-status="Dang giao">Đang giao</button>
                                        <button class="status-btn" data-status="Da giao">Đã giao</button>
                                    </div>
                                    <div id="foodOrdersList"></div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </section>

            <!-- Manage Section -->
            <section id="manage" class="section">
                <div class="section-header">
                    <h2>Quản Lý Hệ Thống</h2>
                </div>
                
                <div class="manage-tabs">
                    <button class="tab-btn active" data-tab="manage-bookings">
                        <i class="fas fa-receipt tab-icon" aria-hidden="true"></i>
                        Quản lý vé
                    </button>
                    <button class="tab-btn" data-tab="manage-passengers">
                        <i class="fas fa-user-friends tab-icon" aria-hidden="true"></i>
                        Hành khách
                    </button>
                    <button class="tab-btn" data-tab="manage-stations">
                        <i class="fas fa-landmark tab-icon" aria-hidden="true"></i>
                        Ga tàu
                    </button>
                </div>
                
                <div class="tab-content">
                    <div class="tab-panel active" id="manage-bookings">
                        <div class="search-section">
                            <input type="text" id="bookingSearch" placeholder="Nhập CCCD để tra cứu vé...">
                            <button onclick="searchBookings()">
                                <i class="fas fa-search"></i> Tìm kiếm
                            </button>
                        </div>
                        <div id="bookingResults"></div>
                    </div>
                    
                    <div class="tab-panel" id="manage-passengers">
                        <div class="passenger-list" id="passengerList">
                            <!-- Passenger list will be loaded here -->
                        </div>
                    </div>
                    
                    <div class="tab-panel" id="manage-stations">
                        <div class="station-management">
                            <button class="btn btn-primary" onclick="showAddStation()">
                                <i class="fas fa-plus"></i> Thêm ga tàu
                            </button>
                            <div id="stationManagementList">
                                <!-- Station management will be shown here -->
                            </div>
                        </div>
                    </div>
                </div>
            </section>
        </main>
    </div>

    <!-- Modals -->
    <div id="adminLoginModal" class="modal">
        <div class="modal-content">
            <div class="modal-header">
                <h3>Đăng Nhập Quản Trị</h3>
                <span class="close" onclick="closeModal('adminLoginModal')">&times;</span>
            </div>
            <div class="modal-body">
            <div class="form-group" style="position: relative;">
                <label>Mật khẩu quản trị:</label>
                <input type="password" id="adminPassword" placeholder="Nhập mật khẩu" style="padding-right:38px;" />
                <span id="toggleAdminPassword" tabindex="0" style="position: absolute; right: 12px; top: 38px; cursor: pointer; color: #666;">
                    <i class="fa fa-eye" id="adminPasswordEye"></i>
                </span>
            </div>
                <p class="mb-1" style="color:#6c757d; font-size: 0.9rem;">Chỉ quản trị viên mới được truy cập khu vực này.</p>
            </div>
            <div class="modal-footer">
                <button class="btn btn-secondary" onclick="closeModal('adminLoginModal')">Hủy</button>
                <button class="btn btn-primary" onclick="submitAdminLogin()">Đăng nhập</button>
            </div>
        </div>
    </div>
    <div id="addStationModal" class="modal">
        <div class="modal-content">
            <div class="modal-header">
                <h3>Thêm Ga Tàu</h3>
                <span class="close" onclick="closeModal('addStationModal')">&times;</span>
            </div>
            <div class="modal-body">
                <form id="addStationForm">
                    <div class="form-group">
                        <label>Mã ga:</label>
                        <input type="text" id="stationCode" required>
                    </div>
                    <div class="form-group">
                        <label>Tên ga:</label>
                        <input type="text" id="stationName" required>
                    </div>
                    <div class="form-group">
                        <label>Địa chỉ:</label>
                        <input type="text" id="stationAddress" required>
                    </div>
                    <div class="form-group">
                        <label>Mô tả:</label>
                        <textarea id="stationDescription"></textarea>
                    </div>
                </form>
            </div>
            <div class="modal-footer">
                <button class="btn btn-secondary" onclick="closeModal('addStationModal')">Hủy</button>
                <button class="btn btn-primary" onclick="addStation()">Thêm</button>
            </div>
        </div>
    </div>

    <div id="cancelBookingModal" class="modal">
        <div class="modal-content">
            <div class="modal-header">
                <h3>Hủy Vé</h3>
                <span class="close" onclick="closeModal('cancelBookingModal')">&times;</span>
            </div>
            <div class="modal-body">
                <p>Bạn có chắc chắn muốn hủy vé này?</p>
                <div class="refund-info">
                    <h4>Thông tin hoàn tiền:</h4>
                    <div class="form-group">
                        <label>Số tài khoản:</label>
                        <input type="text" id="refundAccount" required>
                    </div>
                    <div class="form-group">
                        <label>Tên ngân hàng:</label>
                        <input type="text" id="refundBank" required>
                    </div>
                </div>
            </div>
            <div class="modal-footer">
                <button class="btn btn-secondary" onclick="closeModal('cancelBookingModal')">Hủy</button>
                <button class="btn btn-danger" onclick="confirmCancelBooking()">Xác nhận hủy</button>
            </div>
        </div>
    </div>

    <!-- EmailJS SDK -->
    <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/@emailjs/browser@3/dist/email.min.js"></script>
    <script>
        (function() {
            try {
                if (window.emailjs && typeof emailjs.init === 'function') {
                    emailjs.init('3UwgHWItm4iiojX1L');
                }
            } catch (e) {
                console.warn('EmailJS init failed:', e);
            }
        })();
    </script>
    <script src="menu-images.js"></script>
    <script src="script.js"></script>
</body>
</html>

