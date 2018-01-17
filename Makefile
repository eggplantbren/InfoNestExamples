CC = g++
CCFLAGS = -std=c++17 -O3 -Wall -Wextra -pedantic
INFONEST_PATH = ./InfoNest/cpp

default:
	# Build the dependency
	make -C InfoNest/cpp

	# Compile the cpp files
	$(CC) $(CFLAGS) -I include -I$(INFONEST_PATH) -c src/BetaBinomial.cpp
	$(CC) $(CFLAGS) -I include -I$(INFONEST_PATH) -c src/main.cpp

	# Link executables
	$(CC) -L$(INFONEST_PATH) -o main *.o -linfonest

	# Remove object files
	rm -f *.o

