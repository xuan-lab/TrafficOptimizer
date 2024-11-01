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
        return "Vehicle " + id + " is moving at " + std::to_string(speed) + " km/h";
    }

private:
    std::string id;
    int speed;
};

class TrafficSystem {
public:
    void addVehicle(const Vehicle& vehicle) {
        vehicles.push_back(vehicle);
    }

    void broadcastInfo() const {
        for (const auto& vehicle : vehicles) {
            std::string info = vehicle.sendInfo();
            std::cout << info << std::endl;
            // Simulate sending info over CAN
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
    Vehicle vehicle1("V1");
    Vehicle vehicle2("V2");

    vehicle1.updateSpeed(60);
    vehicle2.updateSpeed(70);

    trafficSystem.addVehicle(vehicle1);
    trafficSystem.addVehicle(vehicle2);

    // Broadcast vehicle info
    trafficSystem.broadcastInfo();

    return 0;
}
