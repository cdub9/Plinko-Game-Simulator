/*
Purpose: This program simulates the game of plinko.
Input:
    1. Menu option - quit, drop single chip, drop multiple chips in one slot or drop multiple chips in each slot
    2. How many chips to drop, where applicable
    3. Which slot to drop the chip(s) in, where applicable
Output:
    1. Path of the chip during a single chip drop
    2. Winnings from the chip(s) dropped
    3. Average winnings per chip when multiple chips are dropped
    4. Average winnings per slot when multiple chips are dropped in each slot
Test Case 1
Input:
    Menu: 5
Output:
    Invalid selection. Please enter 0, 1 or 2.
Test Case 2
Input:
    Menu: 2, Chips to drop: 500, Slot: 9, Slot (re-prompt): 7
Output:
    Dropping chips into slot 7.
    Total winnings on 500 chips: $561300.00
    Average winnings per chip: $1122.60
Test Case 3
Input:
    Menu: 3, Chips to drop: 163
Output:
    Total winnings on slot 0 chips: $107500.00
    Average winnings per chip: $659.51


    Total winnings on slot 1 chips: $154700.00
    Average winnings per chip: $949.08


    Total winnings on slot 2 chips: $275200.00
    Average winnings per chip: $1688.34


    Total winnings on slot 3 chips: $434000.00
    Average winnings per chip: $2662.58


    Total winnings on slot 4 chips: $436700.00
    Average winnings per chip: $2679.14


    Total winnings on slot 5 chips: $364500.00
    Average winnings per chip: $2236.20


    Total winnings on slot 6 chips: $239500.00
    Average winnings per chip: $1469.33


    Total winnings on slot 7 chips: $176800.00
    Average winnings per chip: $1084.66


    Total winnings on slot 8 chips: $95300.00
    Average winnings per chip: $584.66
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
const int SLOT_3 = 3;
const int SLOT_4 = 4;
const int SLOT_5 = 5;
const int SLOT_6 = 6;
const int SLOT_7 = 7;
const int SLOT_8 = 8;
const int NUMBER_OF_SLOTS = 9;

/**
    Computes the amount of prize money
    @param slot - the slot that the chip ends up in
    @return the winnings for that chip
*/
double compute_winnings(int slot) {
    double winnings = 0;
    if (slot == SLOT_0) {
        winnings = 100;
    }
    else if (slot == SLOT_1) {
        winnings = 500;
    }
    else if (slot == SLOT_2) {
        winnings = 1000;
    }
    else if (slot == SLOT_4) {
        winnings = 10000;
    }
    else if (slot == SLOT_6) {
        winnings = 1000;
    }
    else if (slot == SLOT_7) {
        winnings = 500;
    }
    else if (slot == SLOT_8) {
        winnings = 100;
    }
    else {
        winnings = 0;
    }
    return winnings;
}

/**
    Simulates one chip falling
    @param starting_slot - identifies the slot that the chip was dropped into
    @return winnings from the chip
*/
double drop_single_chip(double starting_slot, int number_of_chips) {
    if (number_of_chips == 1) {
        cout << "PATH: [" << starting_slot;
    }
    for (int i = 1; i < 13; i++) {
        if (starting_slot == SLOT_0) {
            starting_slot += 0.5;
        }
        else if (starting_slot == SLOT_8) {
            starting_slot -= 0.5;
        }
        else {
            if (rand() % 2 == 0) {
                starting_slot -= 0.5;
            }
            else {
                starting_slot += 0.5;
            }
        }
        if (number_of_chips == 1) {
            cout << fixed << setprecision(1) << " " << starting_slot;
        }
    }
    if (number_of_chips == 1) {
        cout << "]" << endl;
    }
    int ending_slot = static_cast<int>(starting_slot);
    double single_chip_winnings = 0;
    single_chip_winnings = compute_winnings(ending_slot);
    return single_chip_winnings;
}

/**
    Simulates multiple chips falling
    @param number_of_chips - the number of chips that are being dropped
    @param starting_slot - identifies the slot that the chips were dropped into
    @return the winnings from all of the chips that were dropped
*/
double drop_multiple_chips(int number_of_chips, double starting_slot) {
    double multiple_chip_winnings = 0;
    for (int i = 0; i < number_of_chips; i++) {
        multiple_chip_winnings += drop_single_chip(starting_slot, number_of_chips);
    }
    return multiple_chip_winnings;
}

/**
    Gets a valid number of chips to be dropped
    @return number_of_chips_to_drop - the number of chips to be dropped
*/
int how_many_chips() {
    int number_of_chips_to_drop = 0;
    while (number_of_chips_to_drop < 1) {
        cout << "How many chips would you like to drop (>0)? ";
        cin >> number_of_chips_to_drop;
        if (cin.fail()) {
            cout << "Invalid input. Please enter an integer greater than 0." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (number_of_chips_to_drop < 1) {
            cout << "Invalid input. Please enter an integer greater than 0." << endl;
        }
    }
    return number_of_chips_to_drop;
}

/**
    Gets a valid slot number for the chips to be dropped into
    @return slot_number the slot number that the chip(s) will be dropped into
*/
int which_slot() {
    int slot_number = -1;
    while (slot_number < 0 || slot_number > 8) {
        cout << "Which slot do you want to drop the chip(s) into (0-8)? ";
        cin >> slot_number;
        if (cin.fail()) {
            cout << "Invalid input. Please enter an integer from 0-8." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (slot_number < 0 || slot_number > 8) {
            cout << "Invalid input. Please enter an integer from 0-8." << endl;
        }
    }
    return slot_number;
}

int main() {
    for (;;) {
        srand(time(0));
        int menu_selection = -1;
        while (menu_selection < 0 || menu_selection > 3) {
            cout << "Welcome to the plinko simulator!" << endl;
            cout << "MENU: Please select one of the following options:" << endl;
            cout << "0 - Quit the program" << endl;
            cout << "1 - Drop a single chip into one slot" << endl;
            cout << "2 - Drop multiple chips into one slot" << endl;
            cout << "3 - Drop multiple chips into each slot" << endl;
            cin >> menu_selection;
            if (cin.fail()) {
                cout << endl;
                cout << "Invalid selection. Please enter 0, 1 or 2." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl;
            }
            else if (menu_selection < 0 || menu_selection > 3) {
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
            int number_of_chips = 1;
            cout << "***DROP SINGLE CHIP***" << endl;
            int single_chip_slot = 0;
            single_chip_slot = which_slot();
            cout << "Dropping chip into slot " << single_chip_slot << "." << endl;
            double single_chip_winnings = 0;
            single_chip_winnings = drop_single_chip(single_chip_slot,number_of_chips);
            cout << fixed << setprecision(2) << "Winnings: $" << single_chip_winnings << endl << endl;
        }
        else if (menu_selection == 2) {
            cout << "***DROP MULTIPLE CHIPS***" << endl;
            int number_of_chips_to_drop = 0;
            number_of_chips_to_drop = how_many_chips();
            int multiple_chip_slot = 0;
            multiple_chip_slot = which_slot();
            cout << "Dropping chips into slot " << multiple_chip_slot << "." << endl;

            double multiple_chips_winnings = 0;
            multiple_chips_winnings = drop_multiple_chips(number_of_chips_to_drop, multiple_chip_slot);
            cout << "Total winnings on " << number_of_chips_to_drop << " chips: $" << fixed << setprecision(2) << multiple_chips_winnings << endl;
            double average_winnings_per_chip = multiple_chips_winnings / number_of_chips_to_drop;
            cout << fixed << setprecision(2) << "Average winnings per chip: $" << average_winnings_per_chip << endl << endl;
        }
        else if (menu_selection == 3) {
            cout << "***SEQUENTIALLY DROP MULTIPLE CHIPS***" << endl;
            int number_of_chips_to_drop = 0;
            number_of_chips_to_drop = how_many_chips();
            double multiple_chips_winnings = 0;
            int slot_number = 0;
            
            for (int i = 0; i < NUMBER_OF_SLOTS; i++) {
                multiple_chips_winnings = drop_multiple_chips(number_of_chips_to_drop, slot_number);
                cout << endl << "Total winnings on slot " << slot_number << " chips: $" << multiple_chips_winnings << endl;
                double average_winnings_per_chip = 0;
                average_winnings_per_chip = multiple_chips_winnings / number_of_chips_to_drop;
                cout << fixed << setprecision(2) << "Average winnings per chip: $" << average_winnings_per_chip << endl << endl;
                multiple_chips_winnings = 0;
                slot_number++;
            }
        }
        else {
            cout << "INVALID SELECTION. Please enter 0, 1 or 2: " << endl;
        }
    }
    system("pause");
    return 0;
}
