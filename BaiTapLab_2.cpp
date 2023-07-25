#include <iostream>
using namespace std;

//Bài 1:
bool isConditionSatisfied(int num) {
    int tensDigit = num / 10;
    int unitsDigit = num % 10;

    return (tensDigit * unitsDigit == 2 * (tensDigit + unitsDigit));
}

//Bài 2:
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void printPrimesLessThanN(int n) {
    cout << "Cac so nguyen to nho hon " << n << " la: ";
    for (int i = 2; i < n; ++i) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

//Bài 3:
void printASCIITable() {
    for (int i = 0; i < 256; ++i) {
        cout << "Ky tu: " << char(i) << ", Ma ASCII: " << i << endl;
    }
}

//Bài 4:
int reverseDigits(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

//Bài 5:
void countDigitsAndSum(int n) {
    int count = 0, sum = 0;
    while (n > 0) {
        count++;
        sum += n % 10;
        n /= 10;
    }
    cout << "So chu so: " << count << endl;
    cout << "Tong cac chu so: " << sum << endl;
}

//Bài 6:
double calculateInternetBill(int startHour, int endHour) {
    double rate = 0.0;
    double duration = static_cast<double>(endHour - startHour);

    if (startHour >= 7 && endHour <= 17) {
        rate = 400.0;
        if (duration > 6.0) rate *= 0.9;
    } else if (startHour >= 17 && endHour <= 24) {
        rate = 350.0;
        if (duration > 4.0) rate *= 0.88;
    } else if (startHour >= 0 && endHour <= 7) {
        rate = 300.0;
        if (duration > 7.0) rate *= 0.85;
    }

    return rate * duration;
}

//Bài 7:
double calculateRoomRentalFee(int numDays, char roomType) {
    double dailyRate = 0.0;
    if (roomType == 'A') dailyRate = 250000;
    else if (roomType == 'B') dailyRate = 200000;
    else if (roomType == 'C') dailyRate = 150000;

    double totalFee = dailyRate * numDays;
    if (numDays > 12) {
        double discountPercentage = 0.0;
        if (roomType == 'A') discountPercentage = 0.1;
        else if (roomType == 'B' || roomType == 'C') discountPercentage = 0.08;

        totalFee -= totalFee * discountPercentage;
    }
    return totalFee;
}

int getDaysInMonth(int month);

//Bài 8: 
bool isValidDate(int day, int month) {
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > getDaysInMonth(month)) return false;

    if (month == 2 && day == 29) {
        int year;
        cout << "Nhap nam: ";
        cin >> year;
        if ((year % 400 != 0 && (year % 100 == 0 || year % 4 != 0))) return false;
    }

    return true;
}

int getDaysInMonth(int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return 28;  // Hoặc 29 nếu là năm nhuận
        default:
            return 0;   // Trả về 0 nếu tháng không hợp lệ
    }
}

void nextDay(int& day, int& month) {
    if (day == getDaysInMonth(month)) {
        day = 1;
        month++;
    } else {
        day++;
    }

    if (month > 12) month = 1;
}

void previousDay(int& day, int& month) {
    if (day == 1) {
        if (month == 1) {
            day = getDaysInMonth(12);
            month = 12;
        } else {
            day = getDaysInMonth(month - 1);
            month--;
        }
    } else {
        day--;
    }
}

//Bài 9:
double calculateTaxiFee(int km) {
    double totalFee = 0.0;

    if (km > 120) {
        totalFee = 120 * 15000 + 5 * 13500 + (km - 125) * 11000;
        totalFee *= 0.9;
    } else if (km > 5) {
        totalFee = 5 * 15000 + (km - 5) * 13500;
    } else {
        totalFee = km * 15000;
    }

    return totalFee;
}

//Bài 10:
double calculateAverageScore(double toan, double ly, double hoa) {
    return (toan + ly + hoa) / 3;
}

void classifyStudent(double averageScore) {
    cout << "Diem trung binh: " << averageScore << ", Loai hoc luc: ";
    if (averageScore >= 9.0) {
        cout << "Xuat sac" << endl;
    } else if (averageScore >= 8.0) {
        cout << "Gioi" << endl;
    } else if (averageScore >= 6.5) {
        cout << "Kha" << endl;
    } else if (averageScore >= 5.0) {
        cout << "Trung binh" << endl;
    } else if (averageScore >= 3.0) {
        cout << "Yeu" << endl;
    } else {
        cout << "Kem" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\nDanh sach cac bai tap: " << endl;
        cout << "1. Tim cac so co tich cua hai chu so bang 2 lan tong hai chu so." << endl;
        cout << "2. In ra cac so nguyen to nho hon so n." << endl;
        cout << "3. Xuat ra bang ma ASCII." << endl;
        cout << "4. Tim chu so dao nguoc cua so nguyen duong n." << endl;
        cout << "5. Dem so chu so va tinh tong cac chu so cua so nguyen duong n." << endl;
        cout << "6. Tinh tien cuoc truy cap Internet." << endl;
        cout << "7. Tinh tien thue phong." << endl;
        cout << "8. Xu ly ngay thang." << endl;
        cout << "9. Tinh tien taxi." << endl;
        cout << "10. Xep loai hoc sinh." << endl;
        cout << "0. Thoat." << endl;

        cout << "Nhap lua chon (0-10): ";
        cin >> choice;

        switch (choice) {
            case 1:
                 int num;
                cout << "Nhap mot so nguyen trong pham vi tu 10 den 99 de thoa man dieu kien: ";
                cin >> num;
                if (num >= 10 && num <= 99) {
                    if (isConditionSatisfied(num)) {
                        cout << num << " so nay thoa man dieu kien." << endl;
                    } else {
                        cout << num << " So nay khong thoa man dieu kien." << endl;
                    }
                } else {
                    cout << "So da nhap khong nam trong pham vi tu 10 den 99." << endl;
                }
                break;
            case 2: {
                int n;
                cout << "Nhap so n: ";
                cin >> n;
                printPrimesLessThanN(n);
                break;
            }
            case 3:
                printASCIITable();
                break;
            case 4: {
                int n;
                cout << "Nhap so n: ";
                cin >> n;
                int reversed = reverseDigits(n);
                cout << "Chu so dao nguoc cua " << n << " la: " << reversed << endl;
                break;
            }
            case 5: {
                int n;
                cout << "Nhap so n: ";
                cin >> n;
                countDigitsAndSum(n);
                break;
            }
            case 6: {
                int startHour, endHour;
                cout << "Nhap gio bat dau truy cap: ";
                cin >> startHour;
                cout << "Nhap gio ket thuc truy cap: ";
                cin >> endHour;
                double totalBill = calculateInternetBill(startHour, endHour);
                cout << "Tong cuoc truy cap Internet la: " << totalBill << " VND" << endl;
                break;
            }
            case 7: {
                int numDays;
                char roomType;
                cout << "Nhap so ngay thue phong: ";
                cin >> numDays;
                cout << "Nhap loai phong (A, B hoac C): ";
                cin >> roomType;
                double totalFee = calculateRoomRentalFee(numDays, roomType);
                cout << "Tien thue phong la: " << totalFee << " VND" << endl;
                break;
            }
            case 8:{
                int day, month;
                cout << "Nhap ngay va thang: ";
                cin >> day >> month;

                if (isValidDate(day, month)) {
                    cout << "Ngay hop le!" << endl;
                    cout << "Thang " << month << " co " << getDaysInMonth(month) << " ngay." << endl;
                    nextDay(day, month);
                    cout << "Ngay hom sau la: " << day << "/" << month << endl;
                    previousDay(day, month);
                    cout << "Ngay hom truoc la: " << day << "/" << month << endl;
                } else {
                    cout << "Ngay khong hop le!" << endl;
                }
                break;
            }
            case 9: {
                int km;
                cout << "Nhap so km di taxi: ";
                cin >> km;
                double totalFee = calculateTaxiFee(km);
                cout << "Tong tien taxi la: " << totalFee << " VND" << endl;
                break;
            }
            case 10: {
                string name;
                double toan, ly, hoa;
                cout << "Nhap ten hoc sinh: ";
                cin.ignore();
                getline(cin, name);
                cout << "Nhap diem Toan: ";
                cin >> toan;
                cout << "Nhap diem Ly: ";
                cin >> ly;
                cout << "Nhap diem Hoa: ";
                cin >> hoa;
                double averageScore = calculateAverageScore(toan, ly, hoa);
                classifyStudent(averageScore);
                break;
            }
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }

    } while (choice != 0);

    cout << "Thoat chuong trinh." << endl;

    return 0;
}
