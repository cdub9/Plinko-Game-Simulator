/*
Purpose: This program simulates the game of plinko.
Input: 
    1. Menu Selection
    2. How many chips to drop (for multiple-chip-drop only)
    3. Which slot to drop the chip(s) into
Output:
    1. Total amount of money earned from dropping the chip(s)
    2. Average amount of money earned per chip (for multiple-chip-drop only)
Test Case 1
Input:
    Menu: 7
Output:
    Invalid selection. Please enter 0, 1 or 2.
Test Case 2
Input:
    Menu: 1, Slot: 8 
Output:
    Dropping chip into slot 8.
    PATH: [8 7.5 7 6.5 7 6.5 7 7.5 7 7.5 8 7.5 8]
    WINNINGS: $100.00
Test Case 3
Input:
    Menu: 2, Number of chips: 100000, Slot: 0
Output:
    Dropping chips into slot 0.00
    Total winnings on 100000 chips: $79373100.00
    Average winnings per chip: $793.73
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SLOT_0 = 0;
const int SLOT_1 = 1;
const int SLOT_2 = 2;
const int SLOT_4 = 4;
const int SLOT_6 = 6;
const int SLOT_7 = 7;
const int SLOT_8 = 8;

int main() {
    for (;;) {
        srand(time(0));
        int menu_selection = -1;
        while (menu_selection < 0 || menu_selection > 2) {
            cout << "Welcome to the plinko simulator!" << endl;
            cout << "MENU: Please select one of the following options:" << endl;
            cout << "0 - Quit the program" << endl;
            cout << "1 - Drop a single chip into one slot" << endl;
            cout << "2 - Drop multiple chips into one slot" << endl;
            cin >> menu_selection;
            if (menu_selection < 0 || menu_selection > 2) {
                cout << endl;
                cout << "Invalid selection. Please enter 0, 1 or 2." << endl << endl;
            }
        }
        if (menu_selection == 0) {
            cout << "Goodbye!" << endl;
            system("pause");
            return 0;
        }
        else if (menu_selection == 1) {
            cout << "***DROP SINGLE CHIP***" << endl;
            cout << "Which slot do you want to drop the chip into (0-8)? ";
            double single_chip_slot;
            cin >> single_chip_slot;
            if (single_chip_slot < 0 || single_chip_slot > 8) {
                cout << endl;
                cout << "Invalid slot." << endl << endl;
                continue;
            }
            else {
                cout << "Dropping chip into slot " << single_chip_slot << "." << endl;
                cout << "PATH: [" << single_chip_slot;
                for (int i = 1; i < 13; i++) {
                    if (single_chip_slot == SLOT_0) {
                        single_chip_slot += 0.5;
                    }
                    else if (single_chip_slot == SLOT_8) {
                        single_chip_slot -= 0.5;
                    }
                    else {
                        if (rand() % 2 == 0) {
                            single_chip_slot -= 0.5;
                        }
                        else {
                            single_chip_slot += 0.5;
                        }
                    }
                    cout << " " << single_chip_slot;
                }
                cout << "]" << endl;
            }
            double winnings = 0;
            if (single_chip_slot == SLOT_0) {
                winnings = 100;
            }
            else if (single_chip_slot == SLOT_1) {
                winnings = 500;
            }
            else if (single_chip_slot == SLOT_2) {
                winnings = 1000;
            }
            else if (single_chip_slot == SLOT_4) {
                winnings = 10000;
            }
            else if (single_chip_slot == SLOT_6) {
                winnings = 1000;
            }
            else if (single_chip_slot == SLOT_7) {
                winnings = 500;
            }
            else if (single_chip_slot == SLOT_8) {
                winnings = 100;
            }
            cout << fixed << setprecision(2) << "WINNINGS: $" << winnings << endl;
        }
        else if (menu_selection == 2) {
            cout << "***DROP MULTIPLE CHIPS***" << endl;
            int number_of_chips_to_drop = 0;
            cout << "How many chips do you want to drop (>0)? ";
            cin >> number_of_chips_to_drop;
            if (number_of_chips_to_drop <= 0) {
                cout << endl;
                cout << "INVALID NUMBER OF CHIPS. Please enter a number greater than 0!" << endl << endl;
                continue;
            }

            cout << "Which slot do you want to drop the chips into (0-8)? ";
            double multiple_chip_slot = 0;
            cin >> multiple_chip_slot;
            if (multiple_chip_slot < 0 || multiple_chip_slot > 8) {
                cout << endl;
                cout << "INVALID SLOT. Please enter a slot number from 0 to 8." << endl << endl;
                continue;
            }
            cout << "Dropping chips into slot " << multiple_chip_slot << endl;
            double multiple_chip_winnings = 0;
            for (int i = 0; i < number_of_chips_to_drop; i++) {
                for (int j = 0; j < 13; j++) {
                    if (multiple_chip_slot == SLOT_0) {
                        multiple_chip_slot += 0.5;
                    }
                    else if (multiple_chip_slot == SLOT_8) {
                        multiple_chip_slot -= 0.5;
                    }
                    else {
                        if (rand() % 2 == 0) {
                            multiple_chip_slot -= 0.5;
                        }
                        else {
                            multiple_chip_slot += 0.5;
                        }
                    }
                }
                if (multiple_chip_slot == 0) {
                    multiple_chip_winnings += 100;
                }
                else if (multiple_chip_slot == SLOT_1) {
                    multiple_chip_winnings += 500;
                }
                else if (multiple_chip_slot == SLOT_2) {
                    multiple_chip_winnings += 1000;
                }
                else if (multiple_chip_slot == SLOT_4) {
                    multiple_chip_winnings += 10000;
                }
                else if (multiple_chip_slot == SLOT_6) {
                    multiple_chip_winnings += 1000;
                }
                else if (multiple_chip_slot == SLOT_7) {
                    multiple_chip_winnings += 500;
                }
                else if (multiple_chip_slot == SLOT_8) {
                    multiple_chip_winnings += 100;
                }
            }
            cout << "Total winnings on " << number_of_chips_to_drop << " chips: $" << fixed << setprecision(2) << multiple_chip_winnings << endl;
            double average_winnings_per_chip = multiple_chip_winnings / number_of_chips_to_drop;
            cout << fixed << setprecision(2) << "Average winnings per chip: $" << average_winnings_per_chip << endl;
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
