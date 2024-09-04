#ifndef CHARGINGMANAGER_H
#define CHARGINGMANAGER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>

class ChargingManager {
public:
    void scheduleCharging(const std::string& userId, const std::string& date, const std::string& time);
    void applyIncentives(const std::string& userId, double amountSpent);
    void analyzeData(const std::string& userId) const;
    void displaySchedule(const std::string& userId) const;

private:
    bool isSlotAvailable(const std::string& date, const std::string& time) const;
    std::string incrementTime(const std::string& time, int minutes) const;
    void displayAvailableSlots(const std::string& date) const;

    std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> scheduleData;
    std::unordered_map<std::string, int> incentivePoints;
};

#endif // CHARGINGMANAGER_H
