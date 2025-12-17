#include "Inventory.h"
#include <fstream>
#include <map>
#include <iostream>
#include <string>
Inventory::Inventory() {}

void Inventory::addItem(std::string itemName, int itemCount) { //Adds item to the map
	itemCounts[itemName] += itemCount;
}

void Inventory::printData() { //Prints all data
	for (const auto& pair : itemCounts) {
		std::cout << pair.first << ":" << pair.second << std::endl;
	}
}

void Inventory::printMenu() { //Prints the menu for the user

	std::cout << "1. Print all items" << std::endl;
	std::cout << "2. Search for an item" << std::endl;
	std::cout << "3. Print histogram" << std::endl;
	std::cout << "4. Exit" << std::endl;
}

void Inventory::searchWord() {  //Searches for a specific word 
	std::string userWord;
	std::cout << "Enter an item to search for." << std::endl;
	std::cin >> userWord;

	auto it = itemCounts.find(userWord); 
	if (it != itemCounts.end()) {
		std::cout << it->first << " " << it->second << std::endl;
	}
	else {
		std::cout << userWord << " not found" << std::endl;
	}
}

	void Inventory::printHistogram() {  //Prints the word frequencies using a histogram
		for (auto& pair : itemCounts) {
			std::cout << pair.first << " ";
			for (int i = 0; i < pair.second; ++i){
				std::cout << "+";
			}
			std::cout << std::endl;
		}
	}

	void Inventory::saveData(const std::string& filename) { //Makes a backup file of the word frequencies
		std::ofstream outFile(filename);
		if (!outFile.is_open()) {
			std::cout << "Error creating file: " << filename << std::endl;
			return;
		}

		for (const auto& pair : itemCounts) {
			outFile << pair.first << pair.second << std::endl;
		}

		outFile.close();
	}










	