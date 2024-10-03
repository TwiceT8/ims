#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>

class Supplier {
public:
    std::string name;                // Název dodavatele
    double deliveryTime;              // Čas dodání v dnech
    double deliveryCost;              // Náklady na dopravu

    Supplier(std::string name, double deliveryTime, double deliveryCost)
        : name(name), deliveryTime(deliveryTime), deliveryCost(deliveryCost) {}
};

#endif // SUPPLIER_H
