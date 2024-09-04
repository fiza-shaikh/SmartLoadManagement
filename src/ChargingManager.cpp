#include "ChargingManager.h"

void ChargingManager::scheduleCharging(const std::string& userId, const std::string& date, const std::string& time) {
    if (isSlotAvailable(date, time)) {
        scheduleData[userId].emplace_back(date, time);
        std::cout << "Charging for user " << userId << " scheduled on " << date << " at " << time << ".\n";
    } else {
        std::string newTime = incrementTime(time, 5); // Increment time by 5 minutes
        std::cout << "The Slot at " << time << " is busy. ";
        std::cout << "Do you want to schedule your charging at " << newTime << " instead? (Yes/No): ";
        std::string response;
        std::cin >> response;
        if (response == "Yes" || response == "yes") {
            scheduleData[userId].emplace_back(date, newTime);
            std::cout << "Scheduling your charging at " << newTime << " instead.\n";
        } else {
            displayAvailableSlots(date);
        }
    }
}

bool ChargingManager::isSlotAvailable(const std::string& date, const std::string& time) const {
    for (const auto& entry : scheduleData) {
        for (const auto& schedule : entry.second) {
            if (schedule.first == date && schedule.second == time) {
                return false;
            }
        }
    }
    return true;
}

std::string ChargingManager::incrementTime(const std::string& time, int minutes) const {
    int hour = std::stoi(time.substr(0, 2));
    int min = std::stoi(time.substr(3, 2));
    min += minutes;
    if (min >= 60) {
        min -= 60;
        hour += 1;
        if (hour >= 24) {
            hour -= 24;
        }
    }
    char newTime[6];
    snprintf(newTime, sizeof(newTime), "%02d:%02d", hour, min);
    return std::string(newTime);
}

void ChargingManager::displayAvailableSlots(const std::string& date) const {
    std::cout << "Available slots on " << date << ":\n";
    std::map<std::string, bool> bookedTimes;
    for (const auto& entry : scheduleData) {
        for (const auto& schedule : entry.second) {
            if (schedule.first == date) {
                bookedTimes[schedule.second] = true;
            }
        }
    }

    for (int hour = 0; hour < 24; ++hour) {
        for (int minute = 0; minute < 60; minute += 15) {
            char timeSlot[6];
            snprintf(timeSlot, sizeof(timeSlot), "%02d:%02d", hour, minute);
            if (bookedTimes.find(timeSlot) == bookedTimes.end()) {
                std::cout << timeSlot << " ";
            }
        }
    }
    std::cout << std::endl;
}

void ChargingManager::applyIncentives(const std::string& userId, double amountSpent) {
    int pointsEarned = static_cast<int>(amountSpent) / 5 * 5;
    incentivePoints[userId] += pointsEarned;
    std::cout << "User " << userId << " earned " << pointsEarned << " points. Total points: " << incentivePoints[userId] << ".\n";
}

void ChargingManager::analyzeData(const std::string& userId) const {
    auto it = scheduleData.find(userId);
    if (it != scheduleData.end()) {
        std::cout << "User " << userId << " has charged on the following dates:\n";
        for (const auto& entry : it->second) {
            std::cout << "Date: " << entry.first << ", Time: " << entry.second << "\n";
        }
    } else {
        std::cout << "No charging data found for user " << userId << ".\n";
    }
}

void ChargingManager::displaySchedule(const std::string& userId) const {
    auto it = scheduleData.find(userId);
    if (it != scheduleData.end()) {
        const auto& nextSchedule = it->second.front();
        std::cout << "Next scheduled charging for user " << userId << ":\n";
        std::cout << "Date: " << nextSchedule.first << ", Time: " << nextSchedule.second << "\n";
    } else {
        std::cout << "No scheduled charging found for user " << userId << ".\n";
    }
}
