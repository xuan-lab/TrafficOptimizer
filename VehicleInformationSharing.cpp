/*
 * Copyright (C) 2024, Your Name
 * Email: xiexuan@kernel-dev.com
 * All rights reserved.
 *
 * This code simulates a traffic system that shares vehicle information
 * using a simplified CAN communication model.
 */

#include <iostream>
#include <vector>

class Vehicle {
public:
    Vehicle(const std::string& id) : id(id), speed(0) {}

    void updateSpeed(int newSpeed) {
        speed = newSpeed;
    }

    std::string sendInfo() const {
        return "Vehicle ID: " + id + " | Speed: " + std::to_string(speed) + " km/h";
    }

private:
    std::string id;
    int speed;
};

class TrafficSystem {
public:
    void addVehicle(const std::string& id) {
        vehicles.emplace_back(id);
    }

    void updateVehicleSpeed(const std::string& id, int newSpeed) {
        for (auto& vehicle : vehicles) {
            if (vehicle.sendInfo().find(id) != std::string::npos) {
                vehicle.updateSpeed(newSpeed);
                break;
            }
        }
    }

    void broadcastInfo() const {
        for (const auto& vehicle : vehicles) {
            std::string info = vehicle.sendInfo();
            std::cout << info << std::endl;
            sendCANMessage(info);
        }
    }

private:
    std::vector<Vehicle> vehicles;

    void sendCANMessage(const std::string& message) {
        std::cout << "CAN Message Sent: " << message << std::endl;
    }
};

int main() {
    TrafficSystem trafficSystem;
    trafficSystem.addVehicle("V1");
    trafficSystem.addVehicle("V2");

    trafficSystem.updateVehicleSpeed("V1", 60);
    trafficSystem.updateVehicleSpeed("V2", 70);

    trafficSystem.broadcastInfo();

    return 0;
}
