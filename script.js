// Dữ liệu mẫu từ code C++
const sampleData = {
    stations: [
        { code: "HN", name: "Hà Nội", address: "120 Lê Duẩn, Hoàn Kiếm, Hà Nội", description: "Ga trung tâm thủ đô" },
        { code: "DN", name: "Đà Nẵng", address: "202 Hải Phòng, Thanh Khê, Đà Nẵng", description: "Ga lớn miền Trung" },
        { code: "SG", name: "Sài Gòn", address: "1 Nguyễn Thông, Q3, TP.HCM", description: "Ga trung tâm TP.HCM" },
        { code: "HUE", name: "Huế", address: "2 Bùi Thị Xuân, Huế", description: "Ga cố đô Huế" },
        { code: "NT", name: "Nha Trang", address: "17 Thái Nguyên, Nha Trang", description: "Ga thành phố biển" },
        { code: "HP", name: "Hải Phòng", address: "1 Lương Khánh Thiện, Hải Phòng", description: "Ga lớn tại thành phố cảng" },
        { code: "PT", name: "Phan Thiết", address: "1 Nguyễn Du, Phan Thiết", description: "Ga gần biển Phan Thiết" },
        { code: "QT", name: "Quy Nhon", address: "2 Nguyễn Huệ, Quy Nhơn", description: "Ga trung tâm thành phố Quy Nhơn" },
        { code: "TH", name: "Thanh Hóa", address: "3 Lê Lôi, Thanh Hóa", description: "Ga lớn khu vực Bắc Trung Bộ" },
        { code: "Vinh", name: "Vinh", address: "4 Nguyễn Sỹ Sách, Vinh", description: "Ga trung chuyển miền Trung" }
    ],
    schedules: [
        { trainCode: "SE1", fromStation: "Hà Nội", toStation: "Đà Nẵng", date: "20/10/2025", departureTime: "19:00", arrivalTime: "10:30", price: 550000, seats: 50 },
        { trainCode: "SE2", fromStation: "Hà Nội", toStation: "Sài Gòn", date: "20/10/2025", departureTime: "19:30", arrivalTime: "16:00", price: 850000, seats: 40 },
        { trainCode: "SE3", fromStation: "Hà Nội", toStation: "Huế", date: "20/10/2025", departureTime: "06:00", arrivalTime: "18:00", price: 450000, seats: 60 },
        { trainCode: "SE4", fromStation: "Sài Gòn", toStation: "Nha Trang", date: "21/10/2025", departureTime: "07:00", arrivalTime: "15:00", price: 320000, seats: 45 },
        { trainCode: "SE5", fromStation: "Đà Nẵng", toStation: "Sài Gòn", date: "21/10/2025", departureTime: "08:00", arrivalTime: "18:30", price: 420000, seats: 55 },
        { trainCode: "SE6", fromStation: "Huế", toStation: "Hà Nội", date: "22/10/2025", departureTime: "09:00", arrivalTime: "21:00", price: 470000, seats: 48 },
        { trainCode: "SE7", fromStation: "Sài Gòn", toStation: "Đà Nẵng", date: "22/10/2025", departureTime: "20:00", arrivalTime: "09:00", price: 800000, seats: 35 },
        { trainCode: "SE8", fromStation: "Nha Trang", toStation: "Sài Gòn", date: "23/10/2025", departureTime: "05:30", arrivalTime: "13:00", price: 350000, seats: 40 },
        { trainCode: "SE9", fromStation: "Hải Phòng", toStation: "Hà Nội", date: "23/10/2025", departureTime: "06:00", arrivalTime: "09:00", price: 200000, seats: 60 },
        { trainCode: "SE10", fromStation: "Phan Thiết", toStation: "Sài Gòn", date: "24/10/2025", departureTime: "14:00", arrivalTime: "19:00", price: 300000, seats: 30 },
        { trainCode: "SE11", fromStation: "Quy Nhon", toStation: "Đà Nẵng", date: "24/10/2025", departureTime: "07:00", arrivalTime: "15:00", price: 400000, seats: 25 },
        { trainCode: "SE12", fromStation: "Thanh Hóa", toStation: "Vinh", date: "25/10/2025", departureTime: "10:00", arrivalTime: "13:00", price: 180000, seats: 50 }
    ],
    // Dữ liệu menu 
    menu: [
        { id: "MA01", name: "Phở bò", category: "Do an", price: 50000 },
        { id: "MA02", name: "Bánh mì thịt", category: "Do an", price: 25000 },
        { id: "MA03", name: "Cơm sườn", category: "Do an", price: 45000 },
        { id: "MA04", name: "Xôi gà", category: "Do an", price: 30000 },
        { id: "MA05", name: "Mì tôm trứng", category: "Do an", price: 35000 },
        { id: "DU01", name: "Nước lọc", category: "Do uong", price: 5000 },
        { id: "DU02", name: "Coca Cola", category: "Do uong", price: 15000 },
        { id: "DU03", name: "Cà phê sữa", category: "Do uong", price: 20000 },
        { id: "DU04", name: "Trà đào", category: "Do uong", price: 25000 },
        { id: "DU05", name: "Nước cam", category: "Do uong", price: 20000 },
        { id: "CB01", name: "Combo 1: Cơm + Nước", category: "Combo", price: 50000 },
        { id: "CB02", name: "Combo 2: Phở + Trà", category: "Combo", price: 65000 },
        { id: "CB03", name: "Combo 3: Bánh mì + Cafe", category: "Combo", price: 40000 }
    ]
};

// Biến toàn cục
let currentBooking = null;
let bookings = JSON.parse(localStorage.getItem('bookings')) || [];
let stations = [...sampleData.stations]; // Fallback data
let schedules = [...sampleData.schedules]; // Fallback data
let menu = [...sampleData.menu]; // Fallback data
let vehicleOrders = JSON.parse(localStorage.getItem('vehicleOrders')) || [];
let foodOrders = JSON.parse(localStorage.getItem('foodOrders')) || [];
let currentOrder = { items: [] };
let currentVerificationCode = null; // Lưu mã xác nhận hiện tại
let dataLoadedFromDB = false; // Flag để biết dữ liệu đã load từ DB chưa

// EmailJS Configuration
const EMAILJS_SERVICE_ID = 'service_dfwzj6i'; 
const EMAILJS_TEMPLATE_ID = 'template_zo2qlx8'; 
const EMAILJS_PUBLIC_KEY = '3UwgHWItm4iiojX1L'; 

// Khởi tạo ứng dụng
document.addEventListener('DOMContentLoaded', function() {
    initializeApp();
    loadDataFromDatabase(); 
    setupEventListeners();
    initializeEmailJS();
});


// Load dữ liệu từ database với fallback
async function loadDataFromDatabase() {
    try {
        console.log('Đang tải dữ liệu từ database...');
        
        const response = await fetch('index.php?action=get_all_data');
        
        if (!response.ok) {
            throw new Error(`HTTP error! status: ${response.status}`);
        }
        
        const result = await response.json();
        
        if (result.success && result.data) {
            // Cập nhật dữ liệu từ database
            if (result.data.stations && result.data.stations.length > 0) {
                stations = result.data.stations;
                console.log(`Đã load ${stations.length} ga tàu từ database`);
            }
            
            if (result.data.schedules && result.data.schedules.length > 0) {
                schedules = result.data.schedules;
                console.log(`Đã load ${schedules.length} lịch trình từ database`);
            }
            
            if (result.data.menu && result.data.menu.length > 0) {
                menu = result.data.menu;
                console.log(`Đã load ${menu.length} món ăn từ database`);
            }
            
            dataLoadedFromDB = true;
            console.log(' Dữ liệu đã được tải thành công từ database');
            updateDBStatus(true, 'Kết nối database thành công');
            
        } else {
            throw new Error(result.message || 'Không thể tải dữ liệu từ database');
        }
        
    } catch (error) {
        console.warn('⚠️ Không thể kết nối database, sử dụng dữ liệu mẫu:', error.message);
        dataLoadedFromDB = false;
        updateDBStatus(false, 'Sử dụng dữ liệu mẫu');
        
        // Hiển thị thông báo cho user
        showMessage('Đang sử dụng dữ liệu mẫu. Một số tính năng có thể bị hạn chế.', 'warning');
    }
    
    // Load UI với dữ liệu hiện tại (từ DB hoặc fallback)
    loadStations();
    loadSchedules();
    loadMenu();
}

// Load dữ liệu riêng lẻ từ database
async function loadStationsFromDB() {
    try {
        const response = await fetch('index.php?action=get_stations');
        const result = await response.json();
        
        if (result.success && result.data) {
            stations = result.data;
            loadStations();
            return true;
        }
    } catch (error) {
        console.warn('Không thể load stations từ DB:', error);
    }
    return false;
}

async function loadSchedulesFromDB() {
    try {
        const response = await fetch('index.php?action=get_schedules');
        const result = await response.json();
        
        if (result.success && result.data) {
            schedules = result.data;
            loadSchedules();
            return true;
        }
    } catch (error) {
        console.warn('Không thể load schedules từ DB:', error);
    }
    return false;
}

async function loadMenuFromDB() {
    try {
        const response = await fetch('index.php?action=get_menu');
        const result = await response.json();
        
        if (result.success && result.data) {
            menu = result.data;
            loadMenu();
            return true;
        }
    } catch (error) {
        console.warn('Không thể load menu từ DB:', error);
    }
    return false;
}

// Refresh dữ liệu từ database
async function refreshDataFromDB() {
    console.log('Đang làm mới dữ liệu từ database...');
    updateDBStatus(null, 'Đang làm mới...');
    await loadDataFromDatabase();
    showMessage('Dữ liệu đã được làm mới!', 'success');
}

// Cập nhật trạng thái database
function updateDBStatus(connected, message) {
    const statusIcon = document.getElementById('dbStatusIcon');
    const statusText = document.getElementById('dbStatusText');
    
    if (!statusIcon || !statusText) return;
    
    if (connected === true) {
        statusIcon.style.color = '#27ae60'; // Xanh lá
        statusIcon.className = 'fas fa-circle';
        statusText.textContent = message || 'Kết nối database thành công';
    } else if (connected === false) {
        statusIcon.style.color = '#e74c3c'; // Đỏ
        statusIcon.className = 'fas fa-circle';
        statusText.textContent = message || 'Sử dụng dữ liệu mẫu';
    } else {
        statusIcon.style.color = '#f39c12'; // Vàng
        statusIcon.className = 'fas fa-spinner fa-spin';
        statusText.textContent = message || 'Đang kết nối...';
    }
}

// Khởi tạo ứng dụng
function initializeApp() {
    // Thiết lập ngày hiện tại cho input date
    const today = new Date();
    const tomorrow = new Date(today);
    tomorrow.setDate(tomorrow.getDate() + 1);
    document.getElementById('bookingDate').min = tomorrow.toISOString().split('T')[0];
    document.getElementById('travelDate').min = tomorrow.toISOString().split('T')[0];
    
    // Hiển thị section mặc định
    showSection('home');
}

// Thiết lập event listeners
function setupEventListeners() {
    // Navigation
    document.querySelectorAll('.nav-btn').forEach(btn => {
        btn.addEventListener('click', function() {
            const section = this.getAttribute('data-section');
            showSection(section);
        });
    });

    // Tab management
    document.querySelectorAll('.tab-btn').forEach(btn => {
        btn.addEventListener('click', function() {
            const tab = this.getAttribute('data-tab');
            showTab(tab);
        });
    });

    // Sub-tab management for services
    document.querySelectorAll('.sub-tab-btn').forEach(btn => {
        btn.addEventListener('click', function() {
            const subTab = this.getAttribute('data-sub-tab');
            showSubTab(subTab);
        });
    });

    // Menu category filters
    document.querySelectorAll('.category-btn').forEach(btn => {
        btn.addEventListener('click', function() {
            const category = this.getAttribute('data-category');
            filterMenuByCategory(category);
        });
    });

    // Order status filters
    document.querySelectorAll('.status-btn').forEach(btn => {
        btn.addEventListener('click', function() {
            const status = this.getAttribute('data-status');
            filterOrdersByStatus(status);
        });
    });

    // Station search
    const stationSearch = document.getElementById('stationSearch');
    if (stationSearch) {
        stationSearch.addEventListener('input', searchStations);
    }
    
    // Booking form validation
    const passengerCCCD = document.getElementById('passengerCCCD');
    const passengerPhone = document.getElementById('passengerPhone');
    const passengerEmail = document.getElementById('passengerEmail');
    
    if (passengerCCCD) passengerCCCD.addEventListener('input', validateCCCD);
    if (passengerPhone) passengerPhone.addEventListener('input', validatePhone);
    if (passengerEmail) passengerEmail.addEventListener('input', validateEmail);
    
    // Vehicle service events
    const vehicleType = document.getElementById('vehicleType');
    if (vehicleType) {
        vehicleType.addEventListener('change', updateVehicleFee);
    }
}

// Hiển thị section
function showSection(sectionName) {
    // Ẩn tất cả sections
    document.querySelectorAll('.section').forEach(section => {
        section.classList.remove('active');
    });
    
    // Hiển thị section được chọn
    document.getElementById(sectionName).classList.add('active');
    
    // Cập nhật navigation
    document.querySelectorAll('.nav-btn').forEach(btn => {
        btn.classList.remove('active');
    });
    document.querySelector(`[data-section="${sectionName}"]`).classList.add('active');
    
    // Load dữ liệu cho section
    switch(sectionName) {
        case 'stations':
            loadStations();
            break;
        case 'schedule':
            loadSchedules();
            break;
        case 'manage':
            loadManageData();
            break;
        case 'services':
            // Refresh menu data khi vào services
            if (dataLoadedFromDB) {
                loadMenuFromDB();
            }
            break;
    }
}

// Hiển thị tab
function showTab(tabName) {
    document.querySelectorAll('.tab-btn').forEach(btn => {
        btn.classList.remove('active');
    });
    document.querySelectorAll('.tab-panel').forEach(panel => {
        panel.classList.remove('active');
    });
    
    document.querySelector(`[data-tab="${tabName}"]`).classList.add('active');
    document.getElementById(tabName).classList.add('active');
}

// Load danh sách ga tàu
function loadStations() {
    const stationsGrid = document.getElementById('stationsGrid');
    if (!stationsGrid) return;
    
    stationsGrid.innerHTML = '';
    
    stations.forEach(station => {
        const stationCard = document.createElement('div');
        stationCard.className = 'station-card';
        stationCard.innerHTML = `
            <h3>${station.name}</h3>
            <p><strong>Mã ga:</strong> ${station.code}</p>
            <p><strong>Địa chỉ:</strong> ${station.address}</p>
            <p><strong>Mô tả:</strong> ${station.description}</p>
            <div class="station-actions">
                <button class="btn btn-secondary" onclick="editStation('${station.code}')">
                    <i class="fas fa-edit"></i> Sửa
                </button>
                <button class="btn btn-danger" onclick="deleteStation('${station.code}')">
                    <i class="fas fa-trash"></i> Xóa
                </button>
            </div>
        `;
        stationsGrid.appendChild(stationCard);
    });
}

// Tìm kiếm ga tàu
function searchStations() {
    const searchTerm = document.getElementById('stationSearch').value.toLowerCase();
    const filteredStations = stations.filter(station => 
        station.name.toLowerCase().includes(searchTerm) ||
        station.address.toLowerCase().includes(searchTerm) ||
        station.code.toLowerCase().includes(searchTerm)
    );
    
    const stationsGrid = document.getElementById('stationsGrid');
    stationsGrid.innerHTML = '';
    
    filteredStations.forEach(station => {
        const stationCard = document.createElement('div');
        stationCard.className = 'station-card';
        stationCard.innerHTML = `
            <h3>${station.name}</h3>
            <p><strong>Mã ga:</strong> ${station.code}</p>
            <p><strong>Địa chỉ:</strong> ${station.address}</p>
            <p><strong>Mô tả:</strong> ${station.description}</p>
            <div class="station-actions">
                <button class="btn btn-secondary" onclick="editStation('${station.code}')">
                    <i class="fas fa-edit"></i> Sửa
                </button>
                <button class="btn btn-danger" onclick="deleteStation('${station.code}')">
                    <i class="fas fa-trash"></i> Xóa
                </button>
            </div>
        `;
        stationsGrid.appendChild(stationCard);
    });
}

// Load lịch trình tàu
function loadSchedules() {
    // Populate station dropdowns
    const fromStationSelect = document.getElementById('fromStation');
    const toStationSelect = document.getElementById('toStation');
    const bookingFromSelect = document.getElementById('bookingFromStation');
    const bookingToSelect = document.getElementById('bookingToStation');
    
    [fromStationSelect, toStationSelect, bookingFromSelect, bookingToSelect].forEach(select => {
        if (select) {
            select.innerHTML = '<option value="">Tất cả</option>';
            stations.forEach(station => {
                const option = document.createElement('option');
                option.value = station.name;
                option.textContent = station.name;
                select.appendChild(option);
            });
        }
    });
    
    // Load schedule table
    loadScheduleTable();
}

// Load bảng lịch trình
function loadScheduleTable() {
    const tableBody = document.getElementById('scheduleTableBody');
    if (!tableBody) return;
    
    tableBody.innerHTML = '';
    
    schedules.forEach(schedule => {
        const row = document.createElement('tr');
        row.innerHTML = `
            <td>${schedule.trainCode}</td>
            <td>${schedule.fromStation}</td>
            <td>${schedule.toStation}</td>
            <td>${schedule.date}</td>
            <td>${schedule.departureTime}</td>
            <td>${schedule.arrivalTime}</td>
            <td>${formatCurrency(schedule.price)}</td>
            <td>${schedule.seats}</td>
            <td>
                <button class="btn btn-primary" onclick="bookTrain('${schedule.trainCode}')">
                    <i class="fas fa-ticket-alt"></i> Đặt vé
                </button>
            </td>
        `;
        tableBody.appendChild(row);
    });
}

// Lọc lịch trình
function filterSchedule() {
    const fromStation = document.getElementById('fromStation').value;
    const toStation = document.getElementById('toStation').value;
    const travelDate = document.getElementById('travelDate').value;
    
    let filteredSchedules = schedules;
    
    if (fromStation) {
        filteredSchedules = filteredSchedules.filter(s => s.fromStation === fromStation);
    }
    if (toStation) {
        filteredSchedules = filteredSchedules.filter(s => s.toStation === toStation);
    }
    if (travelDate) {
        const formattedDate = formatDateForDisplay(travelDate);
        filteredSchedules = filteredSchedules.filter(s => s.date === formattedDate);
    }
    
    const tableBody = document.getElementById('scheduleTableBody');
    tableBody.innerHTML = '';
    
    filteredSchedules.forEach(schedule => {
        const row = document.createElement('tr');
        row.innerHTML = `
            <td>${schedule.trainCode}</td>
            <td>${schedule.fromStation}</td>
            <td>${schedule.toStation}</td>
            <td>${schedule.date}</td>
            <td>${schedule.departureTime}</td>
            <td>${schedule.arrivalTime}</td>
            <td>${formatCurrency(schedule.price)}</td>
            <td>${schedule.seats}</td>
            <td>
                <button class="btn btn-primary" onclick="bookTrain('${schedule.trainCode}')">
                    <i class="fas fa-ticket-alt"></i> Đặt vé
                </button>
            </td>
        `;
        tableBody.appendChild(row);
    });
}

// Tìm kiếm chuyến tàu cho đặt vé
function searchTrips() {
    const fromStation = document.getElementById('bookingFromStation').value;
    const toStation = document.getElementById('bookingToStation').value;
    const date = document.getElementById('bookingDate').value;
    
    if (!fromStation || !toStation || !date) {
        showMessage('Vui lòng điền đầy đủ thông tin tìm kiếm!', 'error');
        return;
    }
    
    const formattedDate = formatDateForDisplay(date);
    const availableTrips = schedules.filter(schedule => 
        schedule.fromStation === fromStation && 
        schedule.toStation === toStation && 
        schedule.date === formattedDate &&
        schedule.seats > 0
    );
    
    const tripResults = document.getElementById('tripResults');
    tripResults.innerHTML = '';
    
    if (availableTrips.length === 0) {
        tripResults.innerHTML = '<p class="message info">Không tìm thấy chuyến tàu phù hợp!</p>';
        return;
    }
    
    availableTrips.forEach(trip => {
        const tripCard = document.createElement('div');
        tripCard.className = 'trip-card';
        tripCard.innerHTML = `
            <h4>Chuyến tàu ${trip.trainCode}</h4>
            <div class="trip-info">
                <div>
                    <strong>Ga đi:</strong>
                    <span>${trip.fromStation}</span>
                </div>
                <div>
                    <strong>Ga đến:</strong>
                    <span>${trip.toStation}</span>
                </div>
                <div>
                    <strong>Ngày:</strong>
                    <span>${trip.date}</span>
                </div>
                <div>
                    <strong>Giờ đi:</strong>
                    <span>${trip.departureTime}</span>
                </div>
                <div>
                    <strong>Giờ đến:</strong>
                    <span>${trip.arrivalTime}</span>
                </div>
                <div>
                    <strong>Giá vé:</strong>
                    <span>${formatCurrency(trip.price)}</span>
                </div>
                <div>
                    <strong>Số ghế còn:</strong>
                    <span>${trip.seats}</span>
                </div>
            </div>
            <button class="btn btn-primary" onclick="selectTrip('${trip.trainCode}')">
                <i class="fas fa-check"></i> Chọn chuyến này
            </button>
        `;
        tripResults.appendChild(tripCard);
    });
}

// Chọn chuyến tàu
function selectTrip(trainCode) {
    const selectedTrip = schedules.find(s => s.trainCode === trainCode);
    if (!selectedTrip) return;
    
    currentBooking = {
        trip: selectedTrip,
        passenger: null,
        bookingId: generateBookingId()
    };
    
    goToStep(2);
}

// Chuyển bước trong form đặt vé
async function goToStep(step) {
    document.querySelectorAll('.form-step').forEach(step => {
        step.classList.remove('active');
    });
    document.getElementById(`step${step}`).classList.add('active');
    
    if (step === 3) {
        updateBookingSummary();
        // Gửi email xác nhận
        const verificationCode = generateVerificationCode();
        await sendConfirmationEmail(currentBooking.passenger.email, verificationCode, currentBooking);
    }
}

// Cập nhật tóm tắt đặt vé
function updateBookingSummary() {
    if (!currentBooking) return;
    
    const tripSummary = document.getElementById('tripSummary');
    const passengerSummary = document.getElementById('passengerSummary');
    const totalAmount = document.getElementById('totalAmount');
    
    // Trip summary
    tripSummary.innerHTML = `
        <p><strong>Mã tàu:</strong> ${currentBooking.trip.trainCode}</p>
        <p><strong>Tuyến:</strong> ${currentBooking.trip.fromStation} → ${currentBooking.trip.toStation}</p>
        <p><strong>Ngày:</strong> ${currentBooking.trip.date}</p>
        <p><strong>Giờ đi:</strong> ${currentBooking.trip.departureTime}</p>
        <p><strong>Giờ đến:</strong> ${currentBooking.trip.arrivalTime}</p>
    `;
    
    // Passenger summary
    const passenger = {
        name: document.getElementById('passengerName').value,
        cccd: document.getElementById('passengerCCCD').value,
        phone: document.getElementById('passengerPhone').value,
        email: document.getElementById('passengerEmail').value,
        gender: document.getElementById('passengerGender').value
    };
    
    currentBooking.passenger = passenger;
    
    passengerSummary.innerHTML = `
        <p><strong>Họ tên:</strong> ${passenger.name}</p>
        <p><strong>CCCD:</strong> ${passenger.cccd}</p>
        <p><strong>SĐT:</strong> ${passenger.phone}</p>
        <p><strong>Email:</strong> ${passenger.email}</p>
        <p><strong>Giới tính:</strong> ${passenger.gender}</p>
    `;
    
    // Total amount
    totalAmount.innerHTML = `
        <p><strong>Tổng tiền:</strong> ${formatCurrency(currentBooking.trip.price)}</p>
    `;
}

// Xác nhận đặt vé
async function confirmBooking() {
    const verificationCode = document.getElementById('verificationCode').value;
    
    if (!verificationCode) {
        showMessage('Vui lòng nhập mã xác nhận!', 'error');
        return;
    }
    
    // Kiểm tra mã xác nhận với mã đã lưu
    if (verificationCode !== currentVerificationCode) {
        showMessage('Mã xác nhận không đúng! Vui lòng kiểm tra lại.', 'error');
        return;
    }
    
    // Create booking
    const booking = {
        id: currentBooking.bookingId,
        trip: currentBooking.trip,
        passenger: currentBooking.passenger,
        status: 'confirmed',
        bookingDate: new Date().toISOString(),
        verificationCode: verificationCode
    };
    
    // Add to bookings
    bookings.push(booking);
    localStorage.setItem('bookings', JSON.stringify(bookings));
    
    // Update seat count
    const scheduleIndex = schedules.findIndex(s => s.trainCode === currentBooking.trip.trainCode);
    if (scheduleIndex !== -1) {
        schedules[scheduleIndex].seats--;
    }
    
    showMessage('Đặt vé thành công! Mã vé: ' + booking.id, 'success');
    
    // Reset form
    currentBooking = null;
    currentVerificationCode = null;
    document.getElementById('addStationForm').reset();
    document.querySelectorAll('.form-step').forEach(step => step.classList.remove('active'));
    document.getElementById('step1').classList.add('active');
}

// Load dữ liệu quản lý
function loadManageData() {
    loadBookingManagement();
    loadPassengerList();
    loadStationManagement();
}

// Load quản lý vé
function loadBookingManagement() {
    const bookingResults = document.getElementById('bookingResults');
    if (!bookingResults) return;
    
    bookingResults.innerHTML = `
        <div class="search-section">
            <input type="text" id="bookingSearch" placeholder="Nhập CCCD để tra cứu vé...">
            <button onclick="searchBookings()">
                <i class="fas fa-search"></i> Tìm kiếm
            </button>
        </div>
        <div id="bookingList"></div>
    `;
}

// Tìm kiếm vé
function searchBookings() {
    const searchTerm = document.getElementById('bookingSearch').value;
    if (!searchTerm) {
        showMessage('Vui lòng nhập CCCD!', 'error');
        return;
    }
    
    const userBookings = bookings.filter(booking => 
        booking.passenger.cccd === searchTerm
    );
    
    const bookingList = document.getElementById('bookingList');
    bookingList.innerHTML = '';
    
    if (userBookings.length === 0) {
        bookingList.innerHTML = '<p class="message info">Không tìm thấy vé nào!</p>';
        return;
    }
    
    userBookings.forEach(booking => {
        const bookingCard = document.createElement('div');
        bookingCard.className = 'booking-card';
        bookingCard.innerHTML = `
            <div class="booking-info">
                <h4>Mã vé: ${booking.id}</h4>
                <p><strong>Chuyến tàu:</strong> ${booking.trip.trainCode}</p>
                <p><strong>Tuyến:</strong> ${booking.trip.fromStation} → ${booking.trip.toStation}</p>
                <p><strong>Ngày:</strong> ${booking.trip.date}</p>
                <p><strong>Giờ đi:</strong> ${booking.trip.departureTime}</p>
                <p><strong>Hành khách:</strong> ${booking.passenger.name}</p>
                <p><strong>Giá vé:</strong> ${formatCurrency(booking.trip.price)}</p>
                <p><strong>Trạng thái:</strong> <span class="status confirmed">Đã xác nhận</span></p>
            </div>
            <div class="booking-actions">
                <button class="btn btn-danger" onclick="cancelBooking('${booking.id}')">
                    <i class="fas fa-times"></i> Hủy vé
                </button>
            </div>
        `;
        bookingList.appendChild(bookingCard);
    });
}

// Load danh sách hành khách
function loadPassengerList() {
    const passengerList = document.getElementById('passengerList');
    if (!passengerList) return;
    
    const uniquePassengers = [];
    const passengerMap = new Map();
    
    bookings.forEach(booking => {
        const key = booking.passenger.cccd;
        if (!passengerMap.has(key)) {
            passengerMap.set(key, booking.passenger);
            uniquePassengers.push(booking.passenger);
        }
    });
    
    passengerList.innerHTML = '';
    
    uniquePassengers.forEach(passenger => {
        const passengerCard = document.createElement('div');
        passengerCard.className = 'passenger-card';
        passengerCard.innerHTML = `
            <div class="passenger-info">
                <h4>${passenger.name}</h4>
                <p><strong>CCCD:</strong> ${passenger.cccd}</p>
                <p><strong>SĐT:</strong> ${passenger.phone}</p>
                <p><strong>Email:</strong> ${passenger.email}</p>
                <p><strong>Giới tính:</strong> ${passenger.gender}</p>
            </div>
        `;
        passengerList.appendChild(passengerCard);
    });
}

// Load quản lý ga tàu
function loadStationManagement() {
    const stationManagementList = document.getElementById('stationManagementList');
    if (!stationManagementList) return;
    
    stationManagementList.innerHTML = '';
    
    stations.forEach(station => {
        const stationCard = document.createElement('div');
        stationCard.className = 'station-management-card';
        stationCard.innerHTML = `
            <div class="station-info">
                <h4>${station.name}</h4>
                <p><strong>Mã ga:</strong> ${station.code}</p>
                <p><strong>Địa chỉ:</strong> ${station.address}</p>
                <p><strong>Mô tả:</strong> ${station.description}</p>
            </div>
            <div class="station-actions">
                <button class="btn btn-secondary" onclick="editStation('${station.code}')">
                    <i class="fas fa-edit"></i> Sửa
                </button>
                <button class="btn btn-danger" onclick="deleteStation('${station.code}')">
                    <i class="fas fa-trash"></i> Xóa
                </button>
            </div>
        `;
        stationManagementList.appendChild(stationCard);
    });
}

// Hiển thị modal thêm ga tàu
function showAddStation() {
    document.getElementById('addStationModal').style.display = 'block';
}

// Thêm ga tàu
function addStation() {
    const code = document.getElementById('stationCode').value;
    const name = document.getElementById('stationName').value;
    const address = document.getElementById('stationAddress').value;
    const description = document.getElementById('stationDescription').value;
    
    if (!code || !name || !address) {
        showMessage('Vui lòng điền đầy đủ thông tin!', 'error');
        return;
    }
    
    // Check if station code already exists
    if (stations.find(s => s.code === code)) {
        showMessage('Mã ga đã tồn tại!', 'error');
        return;
    }
    
    const newStation = { code, name, address, description };
    stations.push(newStation);
    
    showMessage('Thêm ga tàu thành công!', 'success');
    closeModal('addStationModal');
    document.getElementById('addStationForm').reset();
    loadStations();
    loadStationManagement();
}

// Xóa ga tàu
function deleteStation(stationCode) {
    if (confirm('Bạn có chắc chắn muốn xóa ga tàu này?')) {
        stations = stations.filter(s => s.code !== stationCode);
        showMessage('Xóa ga tàu thành công!', 'success');
        loadStations();
        loadStationManagement();
    }
}

// Hủy vé
function cancelBooking(bookingId) {
    document.getElementById('cancelBookingModal').style.display = 'block';
    document.getElementById('cancelBookingModal').setAttribute('data-booking-id', bookingId);
}

// Xác nhận hủy vé
function confirmCancelBooking() {
    const bookingId = document.getElementById('cancelBookingModal').getAttribute('data-booking-id');
    const refundAccount = document.getElementById('refundAccount').value;
    const refundBank = document.getElementById('refundBank').value;
    
    if (!refundAccount || !refundBank) {
        showMessage('Vui lòng điền thông tin hoàn tiền!', 'error');
        return;
    }
    
    // Remove booking
    const bookingIndex = bookings.findIndex(b => b.id === bookingId);
    if (bookingIndex !== -1) {
        const booking = bookings[bookingIndex];
        
        // Restore seat
        const scheduleIndex = schedules.findIndex(s => s.trainCode === booking.trip.trainCode);
        if (scheduleIndex !== -1) {
            schedules[scheduleIndex].seats++;
        }
        
        bookings.splice(bookingIndex, 1);
        localStorage.setItem('bookings', JSON.stringify(bookings));
        
        showMessage('Hủy vé thành công! Tiền sẽ được hoàn trong 5 phút.', 'success');
        closeModal('cancelBookingModal');
        loadBookingManagement();
    }
}

// Đóng modal
function closeModal(modalId) {
    document.getElementById(modalId).style.display = 'none';
}

// Hiển thị thông báo
function showMessage(message, type = 'info') {
    const messageDiv = document.createElement('div');
    messageDiv.className = `message ${type}`;
    messageDiv.textContent = message;
    
    // Remove existing messages
    document.querySelectorAll('.message').forEach(msg => msg.remove());
    
    // Add new message
    const mainContent = document.querySelector('.main-content');
    mainContent.insertBefore(messageDiv, mainContent.firstChild);
    
    // Auto remove after 5 seconds
    setTimeout(() => {
        messageDiv.remove();
    }, 5000);
}

// Validation functions
function validateCCCD(input) {
    const cccd = input.value;
    if (cccd.length !== 12 || !/^\d+$/.test(cccd)) {
        input.style.borderColor = '#e74c3c';
        return false;
    } else {
        input.style.borderColor = '#27ae60';
        return true;
    }
}

function validatePhone(input) {
    const phone = input.value;
    if (phone.length < 10 || phone.length > 11 || !/^\d+$/.test(phone)) {
        input.style.borderColor = '#e74c3c';
        return false;
    } else {
        input.style.borderColor = '#27ae60';
        return true;
    }
}

function validateEmail(input) {
    const email = input.value;
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!emailRegex.test(email)) {
        input.style.borderColor = '#e74c3c';
        return false;
    } else {
        input.style.borderColor = '#27ae60';
        return true;
    }
}

// Utility functions
function formatCurrency(amount) {
    return new Intl.NumberFormat('vi-VN', {
        style: 'currency',
        currency: 'VND'
    }).format(amount);
}

function formatDateForDisplay(dateString) {
    const date = new Date(dateString);
    const day = date.getDate().toString().padStart(2, '0');
    const month = (date.getMonth() + 1).toString().padStart(2, '0');
    const year = date.getFullYear();
    return `${day}/${month}/${year}`;
}

function generateBookingId() {
    return 'BK' + Date.now().toString().slice(-8);
}

function generateVerificationCode() {
    return Math.floor(100000 + Math.random() * 900000).toString();
}

// Quick action functions
function showManageBooking() {
    showSection('manage');
    showTab('manage-bookings');
}

function bookTrain(trainCode) {
    showSection('booking');
    const trip = schedules.find(s => s.trainCode === trainCode);
    if (trip) {
        document.getElementById('bookingFromStation').value = trip.fromStation;
        document.getElementById('bookingToStation').value = trip.toStation;
        document.getElementById('bookingDate').value = trip.date.split('/').reverse().join('-');
        searchTrips();
    }
}

// ===================== EMAILJS FUNCTIONS =====================

// Khởi tạo EmailJS
function initializeEmailJS() {
    if (typeof emailjs !== 'undefined') {
        emailjs.init(EMAILJS_PUBLIC_KEY);
    }
}

// Gửi email xác nhận
async function sendConfirmationEmail(email, verificationCode, bookingInfo) {
    // Lưu mã xác nhận để kiểm tra sau
    currentVerificationCode = verificationCode;
    
    // Kiểm tra EmailJS có được cấu hình không
    if (EMAILJS_SERVICE_ID === 'service_1234567' || EMAILJS_PUBLIC_KEY === 'your_public_key_here') {
        console.log('EmailJS chưa được cấu hình, sử dụng chế độ demo');
        showMessage(`Mã xác nhận demo: ${verificationCode}`, 'info');
        return true;
    }

    if (typeof emailjs === 'undefined') {
        console.log('EmailJS not loaded, using demo mode');
        showMessage(`Mã xác nhận demo: ${verificationCode}`, 'info');
        return true;
    }

    try {
        const templateParams = {
            to_email: email,
            verification_code: verificationCode,
            customer_name: bookingInfo.passenger.name,
            train_code: bookingInfo.trip.trainCode,
            from_station: bookingInfo.trip.fromStation,
            to_station: bookingInfo.trip.toStation,
            departure_time: bookingInfo.trip.departureTime,
            total_amount: formatCurrency(bookingInfo.trip.price)
        };

        const result = await emailjs.send(EMAILJS_SERVICE_ID, EMAILJS_TEMPLATE_ID, templateParams);
        console.log('Email sent successfully:', result);
        showMessage('Mã xác nhận đã được gửi qua email!', 'success');
        return true;
    } catch (error) {
        console.error('Error sending email:', error);
        showMessage(`Lỗi gửi email. Mã xác nhận demo: ${verificationCode}`, 'error');
        return false;
    }
}

// ===================== VEHICLE SERVICE FUNCTIONS =====================

// Kiểm tra vé đã mua
function checkVehicleBooking() {
    const cccd = document.getElementById('vehicleCCCD').value;
    if (!cccd || cccd.length !== 12) {
        showMessage('Vui lòng nhập CCCD hợp lệ!', 'error');
        return;
    }

    const userBooking = bookings.find(booking => booking.passenger.cccd === cccd);
    if (!userBooking) {
        showMessage('Không tìm thấy vé đã mua với CCCD này!', 'error');
        return;
    }

    // Hiển thị thông tin vé
    const bookingInfo = document.getElementById('vehicleBookingInfo');
    const bookingDetails = document.getElementById('vehicleBookingDetails');
    
    bookingDetails.innerHTML = `
        <p><strong>Mã vé:</strong> ${userBooking.id}</p>
        <p><strong>Chuyến tàu:</strong> ${userBooking.trip.trainCode}</p>
        <p><strong>Tuyến:</strong> ${userBooking.trip.fromStation} → ${userBooking.trip.toStation}</p>
        <p><strong>Ngày:</strong> ${userBooking.trip.date}</p>
        <p><strong>Giờ đi:</strong> ${userBooking.trip.departureTime}</p>
    `;
    
    bookingInfo.style.display = 'block';
    document.getElementById('vehicleForm').style.display = 'block';
    
    // Lưu thông tin booking để sử dụng sau
    window.currentVehicleBooking = userBooking;
}

// Cập nhật phí gửi xe
function updateVehicleFee() {
    const vehicleType = document.getElementById('vehicleType').value;
    const feeInfo = document.getElementById('vehicleFeeInfo');
    
    if (vehicleType) {
        const fee = vehicleType === 'Xe may' ? 50000 : 20000;
        feeInfo.innerHTML = `
            <h4>Thông tin phí gửi xe:</h4>
            <p><strong>Loại xe:</strong> ${vehicleType}</p>
            <p><strong>Phí gửi:</strong> ${formatCurrency(fee)}</p>
            <p><strong>Lưu ý:</strong> Vui lòng thanh toán phí gửi xe tại quầy trước khi lên tàu.</p>
        `;
    } else {
        feeInfo.innerHTML = '';
    }
}

// Gửi xe lên tàu
function submitVehicleService() {
    const plateNumber = document.getElementById('vehiclePlate').value;
    const vehicleType = document.getElementById('vehicleType').value;
    
    if (!plateNumber || !vehicleType) {
        showMessage('Vui lòng điền đầy đủ thông tin!', 'error');
        return;
    }

    // Kiểm tra biển số đã gửi chưa
    const existingVehicle = vehicleOrders.find(order => 
        order.plateNumber === plateNumber && order.trainCode === window.currentVehicleBooking.trip.trainCode
    );
    
    if (existingVehicle) {
        showMessage('Biển số này đã được gửi lên tàu này rồi!', 'error');
        return;
    }

    // Tạo đơn gửi xe
    const vehicleOrder = {
        id: 'VE' + Date.now(),
        plateNumber: plateNumber,
        vehicleType: vehicleType,
        trainCode: window.currentVehicleBooking.trip.trainCode,
        cccd: window.currentVehicleBooking.passenger.cccd,
        fee: vehicleType === 'Xe may' ? 50000 : 20000,
        status: 'Đã xác nhận',
        orderDate: new Date().toISOString()
    };

    vehicleOrders.push(vehicleOrder);
    localStorage.setItem('vehicleOrders', JSON.stringify(vehicleOrders));

    showMessage('Gửi xe thành công! Mã phiếu: ' + vehicleOrder.id, 'success');
    
    // Reset form
    document.getElementById('vehicleCCCD').value = '';
    document.getElementById('vehiclePlate').value = '';
    document.getElementById('vehicleType').value = '';
    document.getElementById('vehicleBookingInfo').style.display = 'none';
    document.getElementById('vehicleForm').style.display = 'none';
}

// ===================== FOOD SERVICE FUNCTIONS =====================

// Load menu
function loadMenu() {
    const menuGrid = document.getElementById('menuGrid');
    if (!menuGrid) return;

    menuGrid.innerHTML = '';
    
    menu.forEach(item => {
        const menuItem = document.createElement('div');
        menuItem.className = 'menu-item';
        
        // Lấy hình ảnh từ menuImages hoặc sử dụng placeholder
        const imageUrl = (typeof menuImages !== 'undefined' && menuImages[item.id]) 
            ? menuImages[item.id] 
            : `data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMzAwIiBoZWlnaHQ9IjIwMCIgdmlld0JveD0iMCAwIDMwMCAyMDAiIGZpbGw9Im5vbmUiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyI+CjxyZWN0IHdpZHRoPSIzMDAiIGhlaWdodD0iMjAwIiBmaWxsPSIjRjVGNUY1Ii8+Cjx0ZXh0IHg9IjE1MCIgeT0iMTAwIiBmb250LWZhbWlseT0iQXJpYWwiIGZvbnQtc2l6ZT0iMTgiIGZpbGw9IiM2NjY2NjYiIHRleHQtYW5jaG9yPSJtaWRkbGUiPvCfjJcg${encodeURIComponent(item.name)}PC90ZXh0Pgo8L3N2Zz4K`;
        
        menuItem.innerHTML = `
            <div class="menu-item-image" style="background-image: url('${imageUrl}')">
                <div class="menu-category">${item.category}</div>
            </div>
            <div class="menu-item-content">
                <h4>${item.name}</h4>
                <div class="menu-price">${formatCurrency(item.price)}</div>
                <div class="menu-quantity">
                    <button onclick="decreaseQuantity('${item.id}')">-</button>
                    <input type="number" id="qty_${item.id}" value="0" min="0" max="10" onchange="updateOrderTotal()">
                    <button onclick="increaseQuantity('${item.id}')">+</button>
                </div>
            </div>
        `;
        menuGrid.appendChild(menuItem);
    });
}

// Tăng số lượng món
function increaseQuantity(itemId) {
    const input = document.getElementById(`qty_${itemId}`);
    const currentValue = parseInt(input.value) || 0;
    if (currentValue < 10) {
        input.value = currentValue + 1;
        updateOrderTotal();
    }
}

// Giảm số lượng món
function decreaseQuantity(itemId) {
    const input = document.getElementById(`qty_${itemId}`);
    const currentValue = parseInt(input.value) || 0;
    if (currentValue > 0) {
        input.value = currentValue - 1;
        updateOrderTotal();
    }
}

// Lọc menu theo danh mục
function filterMenuByCategory(category) {
    document.querySelectorAll('.category-btn').forEach(btn => btn.classList.remove('active'));
    document.querySelector(`[data-category="${category}"]`).classList.add('active');
    
    const menuItems = document.querySelectorAll('.menu-item');
    menuItems.forEach(item => {
        const itemCategory = item.querySelector('.menu-category').textContent;
        if (category === 'all' || itemCategory === category) {
            item.style.display = 'block';
        } else {
            item.style.display = 'none';
        }
    });
}

// Cập nhật tổng tiền đơn hàng
function updateOrderTotal() {
    let total = 0;
    const orderItems = [];
    
    menu.forEach(item => {
        const quantity = parseInt(document.getElementById(`qty_${item.id}`).value) || 0;
        if (quantity > 0) {
            orderItems.push({
                id: item.id,
                name: item.name,
                price: item.price,
                quantity: quantity,
                total: item.price * quantity
            });
            total += item.price * quantity;
        }
    });
    
    currentOrder.items = orderItems;
    
    // Cập nhật hiển thị
    const orderItemsDiv = document.getElementById('orderItems');
    const orderTotalSpan = document.getElementById('orderTotal');
    
    if (orderItemsDiv && orderTotalSpan) {
        orderItemsDiv.innerHTML = '';
        
        if (orderItems.length === 0) {
            orderItemsDiv.innerHTML = '<p>Chưa có món nào được chọn</p>';
        } else {
            orderItems.forEach(item => {
                const orderItem = document.createElement('div');
                orderItem.className = 'order-item';
                orderItem.innerHTML = `
                    <div class="order-item-info">
                        <div class="order-item-name">${item.name}</div>
                        <div class="order-item-details">Số lượng: ${item.quantity}</div>
                    </div>
                    <div class="order-item-price">${formatCurrency(item.total)}</div>
                `;
                orderItemsDiv.appendChild(orderItem);
            });
        }
        
        orderTotalSpan.textContent = formatCurrency(total);
    }
}

// Đặt đồ ăn
function submitFoodOrder() {
    const trainCode = document.getElementById('foodTrainCode').value;
    const seatNumber = document.getElementById('foodSeatNumber').value;
    const customerName = document.getElementById('foodCustomerName').value;
    const customerPhone = document.getElementById('foodCustomerPhone').value;
    
    if (!trainCode || !seatNumber || !customerName || !customerPhone) {
        showMessage('Vui lòng điền đầy đủ thông tin!', 'error');
        return;
    }
    
    if (currentOrder.items.length === 0) {
        showMessage('Vui lòng chọn ít nhất một món!', 'error');
        return;
    }
    
    // Tạo đơn đặt đồ ăn
    const foodOrder = {
        id: 'FO' + Date.now(),
        trainCode: trainCode,
        seatNumber: seatNumber,
        customerName: customerName,
        customerPhone: customerPhone,
        items: [...currentOrder.items],
        totalAmount: currentOrder.items.reduce((sum, item) => sum + item.total, 0),
        status: 'Cho xu ly',
        orderDate: new Date().toISOString()
    };
    
    foodOrders.push(foodOrder);
    localStorage.setItem('foodOrders', JSON.stringify(foodOrders));
    
    showMessage('Đặt đồ ăn thành công! Mã đơn: ' + foodOrder.id, 'success');
    
    // Reset form
    document.getElementById('foodTrainCode').value = '';
    document.getElementById('foodSeatNumber').value = '';
    document.getElementById('foodCustomerName').value = '';
    document.getElementById('foodCustomerPhone').value = '';
    
    // Reset menu quantities
    menu.forEach(item => {
        document.getElementById(`qty_${item.id}`).value = 0;
    });
    
    currentOrder.items = [];
    updateOrderTotal();
}

// ===================== SERVICE MANAGEMENT FUNCTIONS =====================

// Hiển thị sub-tab
function showSubTab(subTabName) {
    document.querySelectorAll('.sub-tab-btn').forEach(btn => {
        btn.classList.remove('active');
    });
    document.querySelectorAll('.sub-tab-panel').forEach(panel => {
        panel.classList.remove('active');
    });
    
    document.querySelector(`[data-sub-tab="${subTabName}"]`).classList.add('active');
    document.getElementById(subTabName).classList.add('active');
    
    // Load dữ liệu cho sub-tab
    if (subTabName === 'vehicle-orders') {
        loadVehicleOrders();
    } else if (subTabName === 'food-orders') {
        loadFoodOrders();
    }
}

// Load đơn gửi xe
function loadVehicleOrders() {
    const vehicleOrdersList = document.getElementById('vehicleOrdersList');
    if (!vehicleOrdersList) return;
    
    vehicleOrdersList.innerHTML = '';
    
    if (vehicleOrders.length === 0) {
        vehicleOrdersList.innerHTML = '<p class="message info">Chưa có đơn gửi xe nào</p>';
        return;
    }
    
    vehicleOrders.forEach(order => {
        const orderCard = document.createElement('div');
        orderCard.className = 'vehicle-order-card';
        orderCard.innerHTML = `
            <h4>Mã phiếu: ${order.id}</h4>
            <div class="vehicle-info">
                <div>
                    <strong>Biển số xe:</strong>
                    <span>${order.plateNumber}</span>
                </div>
                <div>
                    <strong>Loại xe:</strong>
                    <span>${order.vehicleType}</span>
                </div>
                <div>
                    <strong>Mã tàu:</strong>
                    <span>${order.trainCode}</span>
                </div>
                <div>
                    <strong>Phí gửi:</strong>
                    <span>${formatCurrency(order.fee)}</span>
                </div>
                <div>
                    <strong>Trạng thái:</strong>
                    <span>${order.status}</span>
                </div>
                <div>
                    <strong>Ngày đặt:</strong>
                    <span>${new Date(order.orderDate).toLocaleDateString('vi-VN')}</span>
                </div>
            </div>
        `;
        vehicleOrdersList.appendChild(orderCard);
    });
}

// Load đơn đồ ăn
function loadFoodOrders() {
    const foodOrdersList = document.getElementById('foodOrdersList');
    if (!foodOrdersList) return;
    
    foodOrdersList.innerHTML = '';
    
    if (foodOrders.length === 0) {
        foodOrdersList.innerHTML = '<p class="message info">Chưa có đơn đồ ăn nào</p>';
        return;
    }
    
    foodOrders.forEach(order => {
        const orderCard = document.createElement('div');
        orderCard.className = 'food-order-card';
        orderCard.innerHTML = `
            <h4>Mã đơn: ${order.id}</h4>
            <div class="food-info">
                <div>
                    <strong>Khách hàng:</strong>
                    <span>${order.customerName}</span>
                </div>
                <div>
                    <strong>SĐT:</strong>
                    <span>${order.customerPhone}</span>
                </div>
                <div>
                    <strong>Mã tàu:</strong>
                    <span>${order.trainCode}</span>
                </div>
                <div>
                    <strong>Số ghế:</strong>
                    <span>${order.seatNumber}</span>
                </div>
                <div>
                    <strong>Tổng tiền:</strong>
                    <span>${formatCurrency(order.totalAmount)}</span>
                </div>
                <div>
                    <strong>Trạng thái:</strong>
                    <span class="order-status ${order.status.toLowerCase().replace(' ', '-')}">${order.status}</span>
                </div>
            </div>
            <div class="food-order-items">
                <h5>Chi tiết đơn hàng:</h5>
                ${order.items.map(item => `
                    <div class="food-order-item">
                        <div class="food-order-item-name">${item.name}</div>
                        <div class="food-order-item-details">Số lượng: ${item.quantity}</div>
                        <div class="food-order-item-price">${formatCurrency(item.total)}</div>
                    </div>
                `).join('')}
            </div>
            <div class="order-actions">
                <button class="btn btn-secondary" onclick="updateOrderStatus('${order.id}', 'Dang giao')">
                    <i class="fas fa-truck"></i> Đang giao
                </button>
                <button class="btn btn-primary" onclick="updateOrderStatus('${order.id}', 'Da giao')">
                    <i class="fas fa-check"></i> Đã giao
                </button>
            </div>
        `;
        foodOrdersList.appendChild(orderCard);
    });
}

// Cập nhật trạng thái đơn hàng
function updateOrderStatus(orderId, newStatus) {
    const orderIndex = foodOrders.findIndex(order => order.id === orderId);
    if (orderIndex !== -1) {
        foodOrders[orderIndex].status = newStatus;
        localStorage.setItem('foodOrders', JSON.stringify(foodOrders));
        showMessage('Cập nhật trạng thái thành công!', 'success');
        loadFoodOrders();
    }
}

// Tìm kiếm đơn gửi xe
function searchVehicleOrders() {
    const searchTerm = document.getElementById('vehicleSearch').value.toLowerCase();
    const filteredOrders = vehicleOrders.filter(order => 
        order.plateNumber.toLowerCase().includes(searchTerm)
    );
    
    // Hiển thị kết quả tìm kiếm
    const vehicleOrdersList = document.getElementById('vehicleOrdersList');
    vehicleOrdersList.innerHTML = '';
    
    if (filteredOrders.length === 0) {
        vehicleOrdersList.innerHTML = '<p class="message info">Không tìm thấy đơn gửi xe nào</p>';
        return;
    }
    
    filteredOrders.forEach(order => {
        const orderCard = document.createElement('div');
        orderCard.className = 'vehicle-order-card';
        orderCard.innerHTML = `
            <h4>Mã phiếu: ${order.id}</h4>
            <div class="vehicle-info">
                <div>
                    <strong>Biển số xe:</strong>
                    <span>${order.plateNumber}</span>
                </div>
                <div>
                    <strong>Loại xe:</strong>
                    <span>${order.vehicleType}</span>
                </div>
                <div>
                    <strong>Mã tàu:</strong>
                    <span>${order.trainCode}</span>
                </div>
                <div>
                    <strong>Phí gửi:</strong>
                    <span>${formatCurrency(order.fee)}</span>
                </div>
                <div>
                    <strong>Trạng thái:</strong>
                    <span>${order.status}</span>
                </div>
            </div>
        `;
        vehicleOrdersList.appendChild(orderCard);
    });
}

// Tìm kiếm đơn đồ ăn
function searchFoodOrders() {
    const searchTerm = document.getElementById('foodSearch').value.toLowerCase();
    const filteredOrders = foodOrders.filter(order => 
        order.customerName.toLowerCase().includes(searchTerm)
    );
    
    // Hiển thị kết quả tìm kiếm
    const foodOrdersList = document.getElementById('foodOrdersList');
    foodOrdersList.innerHTML = '';
    
    if (filteredOrders.length === 0) {
        foodOrdersList.innerHTML = '<p class="message info">Không tìm thấy đơn đồ ăn nào</p>';
        return;
    }
    
    filteredOrders.forEach(order => {
        const orderCard = document.createElement('div');
        orderCard.className = 'food-order-card';
        orderCard.innerHTML = `
            <h4>Mã đơn: ${order.id}</h4>
            <div class="food-info">
                <div>
                    <strong>Khách hàng:</strong>
                    <span>${order.customerName}</span>
                </div>
                <div>
                    <strong>SĐT:</strong>
                    <span>${order.customerPhone}</span>
                </div>
                <div>
                    <strong>Mã tàu:</strong>
                    <span>${order.trainCode}</span>
                </div>
                <div>
                    <strong>Số ghế:</strong>
                    <span>${order.seatNumber}</span>
                </div>
                <div>
                    <strong>Tổng tiền:</strong>
                    <span>${formatCurrency(order.totalAmount)}</span>
                </div>
                <div>
                    <strong>Trạng thái:</strong>
                    <span class="order-status ${order.status.toLowerCase().replace(' ', '-')}">${order.status}</span>
                </div>
            </div>
        `;
        foodOrdersList.appendChild(orderCard);
    });
}

// Lọc đơn hàng theo trạng thái
function filterOrdersByStatus(status) {
    document.querySelectorAll('.status-btn').forEach(btn => btn.classList.remove('active'));
    document.querySelector(`[data-status="${status}"]`).classList.add('active');
    
    let filteredOrders = foodOrders;
    if (status !== 'all') {
        filteredOrders = foodOrders.filter(order => order.status === status);
    }
    
    const foodOrdersList = document.getElementById('foodOrdersList');
    foodOrdersList.innerHTML = '';
    
    if (filteredOrders.length === 0) {
        foodOrdersList.innerHTML = '<p class="message info">Không có đơn hàng nào</p>';
        return;
    }
    
    filteredOrders.forEach(order => {
        const orderCard = document.createElement('div');
        orderCard.className = 'food-order-card';
        orderCard.innerHTML = `
            <h4>Mã đơn: ${order.id}</h4>
            <div class="food-info">
                <div>
                    <strong>Khách hàng:</strong>
                    <span>${order.customerName}</span>
                </div>
                <div>
                    <strong>SĐT:</strong>
                    <span>${order.customerPhone}</span>
                </div>
                <div>
                    <strong>Mã tàu:</strong>
                    <span>${order.trainCode}</span>
                </div>
                <div>
                    <strong>Số ghế:</strong>
                    <span>${order.seatNumber}</span>
                </div>
                <div>
                    <strong>Tổng tiền:</strong>
                    <span>${formatCurrency(order.totalAmount)}</span>
                </div>
                <div>
                    <strong>Trạng thái:</strong>
                    <span class="order-status ${order.status.toLowerCase().replace(' ', '-')}">${order.status}</span>
                </div>
            </div>
        `;
        foodOrdersList.appendChild(orderCard);
    });
}

// Hiển thị mã xác nhận demo
function showDemoCode() {
    if (currentVerificationCode) {
        document.getElementById('verificationCode').value = currentVerificationCode;
        showMessage('Đã điền mã xác nhận demo!', 'info');
    } else {
        showMessage('Chưa có mã xác nhận nào được tạo!', 'error');
    }
}

// Close modals when clicking outside
window.onclick = function(event) {
    if (event.target.classList.contains('modal')) {
        event.target.style.display = 'none';
    }
}

