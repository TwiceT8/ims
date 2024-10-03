#ifndef SIMULATION_H
#define SIMULATION_H

#include "Inventory.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class Simulation {
private:
    Inventory& inventory; // Reference na objekt zásob
    int totalDays;        // Počet dní simulace

public:
    Simulation(Inventory& inv, int days) : inventory(inv), totalDays(days) {
        std::srand(static_cast<unsigned>(std::time(nullptr))); // Inicializace náhodného generátoru
    }

    // Funkce pro generování poptávky
    std::vector<int> generateDemand() {
        std::vector<int> demands;
        for (const auto& product : inventory.getProducts()) {
            // Náhodná poptávka mezi 0 a maximální zásobou
            int demand = std::rand() % (product.maxStock + 1);
            demands.push_back(demand);
        }
        return demands;
    }

    // Simulace jednoho dne
    void simulateDay() {
        std::vector<int> dailyDemand = generateDemand(); // Generování poptávky
        inventory.demand(dailyDemand);
    }

    // Simulace po dobu několika dnů
    void run() {
        for (int i = 0; i < totalDays; i++) {
            std::cout << "\nDen " << i + 1 << ":" << std::endl;
            simulateDay();
        }
        std::cout << "\nCelkové náklady za " << totalDays << " dní: " << inventory.getTotalCost() << std::endl;
    }
};

#endif // SIMULATION_H
