/*
 * Copyright (C) 2024, Your Name
 * Email: xiexuan@kernel-dev.com
 * All rights reserved.
 *
 * This code simulates a traffic signal control system 
 * that adjusts the traffic light based on vehicle density.
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

class TrafficLight {
public:
    enum State { RED, GREEN, YELLOW };
    
    TrafficLight() : state(RED) {}
    
    void changeLight() {
        state = static_cast<State>((state + 1) % 3);
    }

    void display() const {
        switch (state) {
            case RED: std::cout << "Traffic Light is RED\n"; break;
            case GREEN: std::cout << "Traffic Light is GREEN\n"; break;
            case YELLOW: std::cout << "Traffic Light is YELLOW\n"; break;
        }
    }

private:
    State state;
};

class TrafficControlSystem {
public:
    void optimizeSignal(int trafficDensity) {
        if (trafficDensity > 10) { // Example threshold for high traffic
            trafficLight.changeLight(); // Switch to GREEN
        } else {
            trafficLight = TrafficLight(); // Reset to RED
        }
    }

    void displayTrafficLight() {
        trafficLight.display();
    }

private:
    TrafficLight trafficLight;
};

// Simulating CAN message (simplified)
void sendCANMessage(const std::string& message) {
    std::cout << "CAN Message Sent: " << message << std::endl;
}

int main() {
    std::srand(std::time(0));
    TrafficControlSystem trafficControl;

    for (int i = 0; i < 10; ++i) {
        int currentTrafficDensity = std::rand() % 20; // Simulate random traffic density
        std::cout << "Current traffic density: " << currentTrafficDensity << std::endl;

        trafficControl.optimizeSignal(currentTrafficDensity);
        trafficControl.displayTrafficLight();

        // Simulate sending a CAN message with the traffic density
        sendCANMessage("Traffic Density: " + std::to_string(currentTrafficDensity));

        std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait for a second before the next update
    }

    return 0;
}
