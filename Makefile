# Definice proměnných
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SRC = main.cpp Product.cpp Supplier.cpp Inventory.cpp Simulation.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = inventory_simulation

# Hlavní cíl
all: 
	g++ main.cpp -o inventory_simulation
# Čistící cíl
clean:
	rm -f $(OBJ) $(TARGET)
	rm -f output.txt
run:
	./inventory_simulation > output.txt

# Phony cíle
.PHONY: all clean
