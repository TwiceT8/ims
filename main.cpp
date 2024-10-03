#include <iostream>
#include "Inventory.h"
#include "Supplier.h"
#include "Product.h"
#include "Simulation.h"

int main() {
    Inventory myInventory;

    // Přidání produktů
    myInventory.addProduct(Product("Produkt A", 100, 20, 50, 20.0, 1.0));
    myInventory.addProduct(Product("Produkt B", 150, 30, 70, 25.0, 1.5));

    // Přidání dodavatelů
    myInventory.addSupplier(Supplier("Dodavatel 1", 2.0, 15.0));
    myInventory.addSupplier(Supplier("Dodavatel 2", 3.0, 20.0));

    // Vytvoření simulace a spuštění na 30 dní
    Simulation sim(myInventory, 30);
    sim.run();

    return 0;
}
