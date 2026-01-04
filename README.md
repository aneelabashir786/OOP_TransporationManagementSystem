# Transport Management System (TMS)

A comprehensive console-based Transport Management System developed in C++ for managing drivers, customers, vehicles, and transportation services.

##  Features

### 1. **User Authentication**
- Secure login system with password protection
- Account lockout after 5 failed attempts
- Password change functionality

### 2. **Customer Management**
- Add new customers with personal details
- Update customer information
- Search customers by ID
- Delete customer records
- View all customers
- Payment method tracking

### 3. **Driver Management**
- Add drivers with license type information
- Driver ranking system (1-5 stars)
- Salary calculation based on performance
- Support for multiple license types:
  - MOTORCAR_JEEP
  - MOTORBIKE_RICKSHAW
  - LTV (Light Transport Vehicle)
  - HTV (Heavy Transport Vehicle)
  - TRACTOR
  - PSV (Public Service Vehicle)
  - INTERNATIONAL
- CRUD operations (Create, Read, Update, Delete)

### 4. **Vehicle Management**
- Two main categories:
  - **Ride Vehicles**
    - Small: bike, scooter, car, rickshaw
    - Large: van, bus, APV, campervans, caravan
  - **Transportation Vehicles**
    - Light: Shahzor, Mazda Titan
    - Heavy: trucks, tractor-trailer, car transporter, tanker truck
- Track hiring dates
- Complete vehicle inventory management

### 5. **Service Management**
- Distance-based fare calculation
- Fuel type selection (petrol/diesel)
- Air conditioning option
- Comfort level preferences
- Booking date tracking
- Dynamic pricing based on:
  - Distance traveled
  - Fuel type
  - Air conditioning
  - Comfort level

### 6. **Reporting System**
- View comprehensive reports for:
  - All customers
  - All drivers
  - All vehicles
  - All services

##  System Requirements

- **Operating System**: Windows (uses Windows.h library)
- **Compiler**: GCC (MinGW) or any C++ compiler supporting C++11 or later
- **IDE**: Visual Studio Code, Code::Blocks, Dev-C++, or any C++ IDE
- **RAM**: Minimum 2GB
- **Storage**: 50MB free space

##  Installation

1. **Clone or Download the Project**
   ```bash
   git clone https://github.com/aneelabashir786/OOP_TransporationManagementSystem
   cd transport-management-system
   ```

2. **Ensure you have the following files:**
   - `Header.h` - Contains all class declarations
   - `implementation.cpp` - Contains all function implementations
   - `main.cpp` - Contains the main program logic

##  Compilation Instructions

### Using Command Line (GCC/MinGW)

**Method 1: Compile all files together**
```bash
g++ main.cpp implementation.cpp -o TMS.exe
```

**Method 2: Compile separately and link**
```bash
g++ -c main.cpp -o main.o
g++ -c implementation.cpp -o implementation.o
g++ main.o implementation.o -o TMS.exe
```

**Method 3: Using wildcard**
```bash
g++ *.cpp -o TMS.exe
```

### Using Visual Studio Code

1. Install the C/C++ extension
2. Install Code Runner extension (optional)
3. Modify `.vscode/settings.json`:
   ```json
   {
       "code-runner.executorMap": {
           "cpp": "cd $dir && g++ *.cpp -o TMS && .\\TMS"
       }
   }
   ```
4. Press `Ctrl + Alt + N` to compile and run

### Using Code::Blocks or Dev-C++

1. Create a new project
2. Add all three files to the project
3. Build and run (F9 or Ctrl+F9)

##  Usage

1. **Run the Program**
   ```bash
   ./TMS.exe
   ```

2. **Login**
   - Enter Admin ID: `1234`
   - Enter Password: `abc`
   - You have 5 attempts before account lockout

3. **Navigate the Dashboard**
   - Choose from 7 main options:
     1. Manage Customer
     2. Manage Driver
     3. Manage Vehicle
     4. Manage Service
     5. View Reports
     6. Change Password
     7. Logout

4. **Perform Operations**
   - Each management section offers:
     - Add new records
     - Delete existing records
     - Search by ID
     - Update information
     - View all records

##  Project Structure

```
transport-management-system/
│
├── Header.h                 # Class declarations and enums
├── implementation.cpp       # Function implementations
├── main.cpp                # Main program logic
│
├── LoginClass.txt          # Stores login credentials
├── customer.txt            # Customer database
├── driver.txt              # Driver database
├── vehicle.txt             # Vehicle database
├── service.txt             # Service records
│
└── README.md               # Project documentation
```

## Default Login Credentials

- **Admin ID**: `1234`
- **Password**: `abc`

**Note**: You can change the password using the "Change Password" option in the dashboard.

##  Class Hierarchy

```
TMS (Abstract Base Class)
│
├── customer
├── driver
├── vehicle
└── service

Login (Standalone Authentication Class)

Date (Helper Class)

Enums:
├── LicenseType
├── smallvehicle
├── largevehicle
├── heavyvehicle
└── lightvehicle
```

##  Technologies Used

- **Language**: C++
- **File Handling**: fstream (for data persistence)
- **Windows API**: Windows.h (for console manipulation)
- **OOP Concepts**:
  - Inheritance
  - Polymorphism
  - Abstraction
  - Encapsulation
  - Virtual Functions

##  Future Enhancements

- [ ] Database integration (MySQL/SQLite) instead of text files
- [ ] GUI implementation using Qt or wxWidgets
- [ ] Cross-platform compatibility (Linux/Mac support)
- [ ] Data encryption for sensitive information
- [ ] Report generation in PDF format
- [ ] Email notifications for bookings
- [ ] Real-time GPS tracking integration
- [ ] Mobile app integration
- [ ] Multi-user support with different access levels
- [ ] Payment gateway integration
- [ ] Booking history and analytics
- [ ] Driver attendance tracking
- [ ] Vehicle maintenance scheduling

##  Known Issues

1. Program is Windows-specific due to `Windows.h` dependency
2. Data stored in plain text files (security concern)
3. No data validation for some inputs
4. Date validation limited (doesn't check actual calendar dates)
5. No backup mechanism for data files


This project is created for educational purposes as part of an Object-Oriented Programming course.
tact the author through the provided email.
