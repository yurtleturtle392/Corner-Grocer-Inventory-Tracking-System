#pragma once
#include <map>
#include <string>


class Inventory{
private:
	std::map<std::string, int> itemCounts;

public:
	Inventory();

	void addItem(std::string, int itemCount);


	void printData();

	void searchWord();

	void printHistogram();

	void printMenu();

	void saveData(const std::string& filename);

	
};


