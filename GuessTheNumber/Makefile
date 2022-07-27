.PHONY = all build run clean

CC = gcc

all: build run

build:
	@echo "Compiling..."
	@[ -f GuessTheNumber ] || ${CC} GuessTheNumber.c -o GuessTheNumber

run:
	@echo "Executing Program..."
	@./GuessTheNumber

clean:
	@echo "Deleting Binaries..."
	@rm GuessTheNumber
