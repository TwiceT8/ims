#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
public:
    std::string name;         // Název produktu
    int currentStock;         // Aktuální zásoby
    int maxStock;             // Maximální kapacita
    int reorderPoint;         // Kdy začít objednávat nové zásoby
    int reorderAmount;        // Kolik zásob objednat
    double orderingCost;      // Náklady na objednání
    double holdingCost;       // Náklady na skladování

    Product(std::string name, int maxStock, int reorderPoint, int reorderAmount, double orderingCost, double holdingCost)
        : name(name), maxStock(maxStock), reorderPoint(reorderPoint), reorderAmount(reorderAmount), 
          orderingCost(orderingCost), holdingCost(holdingCost) {
        currentStock = maxStock; // Začínáme s plnými zásobami
    }
};

#endif // PRODUCT_H
