#include <iostream>
#include "Inventory.h"
#include "Supplier.h"
#include "Product.h"
#include "Simulation.h"

int main()
{
    Inventory myInventory;

    // Přidání produktů
    myInventory.addProduct(Product("Produkt A", 100, 20, 50, 20.0, 1.0));
    myInventory.addProduct(Product("Produkt B", 150, 30, 70, 25.0, 1.5));
    myInventory.addProduct(Product("Produkt C", 200, 40, 100, 30.0, 2.0));
    myInventory.addProduct(Product("Produkt D", 120, 25, 60, 15.0, 0.8));
    myInventory.addProduct(Product("Produkt E", 80, 15, 40, 10.0, 0.5));

    // Přidání dodavatelů
    myInventory.addSupplier(Supplier("Dodavatel 1", 2.0, 15.0));
    myInventory.addSupplier(Supplier("Dodavatel 2", 3.0, 20.0));
    myInventory.addSupplier(Supplier("Dodavatel 3", 1.0, 10.0));
    myInventory.addSupplier(Supplier("Dodavatel 4", 4.0, 25.0));

    // Vytvoření simulace a spuštění na 30 dní
    Simulation sim(myInventory, 30);
    sim.run();

    return 0;
}
