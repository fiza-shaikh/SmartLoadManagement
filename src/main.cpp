#include "ChargingManager.h"

int main() {
    ChargingManager manager;

    int choice;
    std::string userId;
    std::string date, time;
    double amountSpent;

    while (true) {
        std::cout << "\n1. Schedule Charging\n2. Apply Incentives\n3. Analyze Data\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter User ID: ";
                std::cin >> userId;
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::cin >> date;
                std::cout << "Enter time (HH:MM): ";
                std::cin >> time;
                manager.scheduleCharging(userId, date, time);
                break;
            case 2:
                std::cout << "Enter User ID: ";
                std::cin >> userId;
                std::cout << "Enter amount spent: ";
                std::cin >> amountSpent;
                manager.applyIncentives(userId, amountSpent);
                break;
            case 3:
                std::cout << "Enter User ID: ";
                std::cin >> userId;
                manager.analyzeData(userId);
                break;
            case 4:
                std::cout << "Thankyou,Have a great Day!!.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
