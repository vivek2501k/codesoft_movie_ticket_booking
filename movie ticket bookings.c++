#include <iostream>
#include <vector>
using namespace std;

// Constants for the number of rows and seats per row
const int NUM_ROWS = 5;
const int SEATS_PER_ROW = 10;

// Function to display the seating chart
void displaySeats(const vector<vector<char>>& seats) {
    cout << "Seating Chart:" << endl;
    for (int row = 0; row < NUM_ROWS; row++) {
        cout << "Row " << (row + 1) << ": ";
        for (int seat = 0; seat < SEATS_PER_ROW; seat++) {
            cout << seats[row][seat] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a seat is available
bool isSeatAvailable(const vector<vector<char>>& seats, int row, int seat) {
    return seats[row][seat] == 'A';
}

// Function to book a seat
bool bookSeat(vector<vector<char>>& seats, int row, int seat) {
    if (isSeatAvailable(seats, row, seat)) {
        seats[row][seat] = 'B'; // Booked
        return true;
    }
    return false;
}

// Function to calculate the total cost based on the number of booked seats
int calculateTotalCost(const vector<vector<char>>& seats, int numBookedSeats) {
    const int PRICE_PER_TICKET = 10; // Price per ticket
    return numBookedSeats * PRICE_PER_TICKET;
}

int main() {
    vector<vector<char>> seats(NUM_ROWS, vector<char>(SEATS_PER_ROW, 'A')); // 'A' represents available seats

    cout << "MOVIE TICKET BOOKING SYSTEM" << endl;

    while (true) {
        displaySeats(seats);

        cout << "Options:" << endl;
        cout << "1. View Movie Listings" << endl;
        cout << "2. Book Tickets" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Display movie listings (replace this with your actual movie listings)
                cout << "Movie Listings:" << endl;
                cout << "1. Movie 1" << endl;
                cout << "2. Movie 2" << endl;
                break;
            }
            case 2: {
                int row, seat;
                cout << "Enter row and seat number (e.g., 2 5): ";
                cin >> row >> seat;

                // Validate row and seat input
                if (row >= 1 && row <= NUM_ROWS && seat >= 1 && seat <= SEATS_PER_ROW) {
                    row--; // Convert to 0-based index
                    seat--;

                    // Check seat availability and book if available
                    if (isSeatAvailable(seats, row, seat)) {
                        if (bookSeat(seats, row, seat)) {
                            cout << "Seat booked successfully!" << endl;
                        } else {
                            cout << "Seat is already booked. Please choose another seat." << endl;
                        }
                    } else {
                        cout << "Seat is not available. Please choose another seat." << endl;
                    }
                } else {
                    cout << "Invalid row or seat number. Please try again." << endl;
                }
                break;
            }
            case 3: {
                // Calculate and display total cost
                int numBookedSeats = 0;
                for (int row = 0; row < NUM_ROWS; row++) {
                    for (int seat = 0; seat < SEATS_PER_ROW; seat++) {
                        if (seats[row][seat] == 'B') {
                            numBookedSeats++;
                        }
                    }
                }
                int totalCost = calculateTotalCost(seats, numBookedSeats);
                cout << "Total cost: $" << totalCost << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    return 0;
}

