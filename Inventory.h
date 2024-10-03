#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Product.h"
#include "Supplier.h"

class Inventory {
private:
    std::vector<Product> products;   // Seznam produktů
    std::vector<Supplier> suppliers;  // Seznam dodavatelů
    double totalCost;                 // Celkové náklady

public:
const std::vector<Product>& getProducts() const {
        return products;
    }
    // Přidání produktů a dodavatelů
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void addSupplier(const Supplier& supplier) {
        suppliers.push_back(supplier);
    }

    // Simulace poptávky a doplňování pro každý produkt
    void demand(std::vector<int> demands) {
        for (size_t i = 0; i < products.size(); i++) {
            if (demands[i] <= products[i].currentStock) {
                products[i].currentStock -= demands[i];
                std::cout << products[i].name << ": Zákazník koupil " << demands[i] << " kusů. Zbyvá: " << products[i].currentStock << std::endl;
            } else {
                std::cout << products[i].name << ": Nedostatečné zásoby pro objednávku." << std::endl;
            }

            // Kontrola doplnění
            if (products[i].currentStock <= products[i].reorderPoint) {
                restock(i);
            }

            // Náklady na skladování
            totalCost += products[i].currentStock * products[i].holdingCost; 
        }
    }

    void restock(int productIndex) {
        std::cout << "Objednávání nových zásob pro " << products[productIndex].name << "..." << std::endl;
        totalCost += products[productIndex].orderingCost; // Přidání nákladů na objednání
        products[productIndex].currentStock += products[productIndex].reorderAmount;

        if (products[productIndex].currentStock > products[productIndex].maxStock) {
            products[productIndex].currentStock = products[productIndex].maxStock;
        }

        std::cout << "Zásoby byly doplněny na: " << products[productIndex].currentStock << std::endl;
    }

    // Získání celkových nákladů
    double getTotalCost() {
        return totalCost;
    }
};

#endif // INVENTORY_H
