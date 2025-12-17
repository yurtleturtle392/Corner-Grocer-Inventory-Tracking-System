#include <iostream>
using namespace std;
#include "Inventory.h"
#include <fstream>
#include <string>
int main() {
	ifstream file("CS210_Project_Three_Input_File.txt"); // Open the input file
	if (!file.is_open()) {  // Check if the file was opened successfully
		cout << "Error opening file." << endl;
		return 1; // Exit with an error code if the file couldn't be opened
    }
	Inventory inv;  // Create an instance of Inventory to store objects

    string itemName;

    while (file >> itemName) {  
		inv.addItem(itemName, 1); // Add each item to the inventory
    }
    file.close();

	inv.saveData("frequency.dat");  // Save the frequency data to a file

	inv.printMenu(); // Display the menu to the user
    int choice; 

	cin >> choice; // Get the user's menu choice
    while (choice != 4) {
        switch (choice) {
        case 1:
			inv.printData(); // Print all items in the inventory
            break;
        case 2:
			inv.searchWord(); // Search for a specific item in the inventory
            break;
        case 3:
			inv.printHistogram();  // Print a histogram of item frequencies
            break;
        default:
			cout << "Invalid choice. Please try again." << endl; // Handle invalid menu choices
            
        }
		inv.printMenu();
        cin >> choice;




    }
}

