// AirlineBookingSystem.cpp : Defines the entry point for the console application.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <cstddef>
#include<iomanip>
#include<cmath>
#include "stdafx.h"


using std::string;
using std::cin;

using namespace std;

static int fromIndexNumber = 0;
static int toIndexNumber = 0;
static int firstIndexNumber = 0;
static int lastIndexNumber = 0;
static int dateIndexNumber = 0;
static int classIndexNumber = 0;
static int paymentIndexNumber = 0;
static int cardNoIndexNumber = 0;
static int ticketNoIndexNumber = 0;
static int seatIndexNumber = 0;
static int fareIndexNumber = 0;

std::string bookedTicketNumber;
std::string bookedTicketClassType;

// To get the length of string array


// Base class
class AirLineSystemOption {
public:
	// pure virtual function providing interface framework.
	virtual void showMenu() = 0;
	
protected:
	
	
};

class AirLineSystemBook {
public:
	// pure virtual function providing interface framework.
	virtual void bookTicket() = 0;

	std::string fromStation[10];
	std::string toStation[10];
	std::string firstName[10];
	std::string lastName[10];
	std::string ticketdate[10];
	std::string ticketClass[10];
	std::string paymentOption[10];
	std::string cardNumber[10];
	std::string ticketNumber[10];
	std::string seatNumber[10];
	std::string fareAmount[10];


};

// Derived classes
class ShowOption : public AirLineSystemOption {
public:
	void showMenu() {
		cout << "\n-------Main Menu--------\n\n";
		cout << "1. Book a ticket\n";
		cout << "2. Cancel a ticket\n";
		cout << "3. View a ticket\n";
		cout << "4. Modify Ticket\n";
		cout << "5. Exit\n\n";
	}

};

// Derived classes
class BookTicket: public AirLineSystemBook {
public:

	int from_opt;
	int to_opt;
	int class_opt;
	int card_opt;

	
	void bookTicket() {

		// Get the from station detail
		do {
			cout << "\nFrom City:\n";
			cout << "1. Toronto\n";
			cout << "2. Waterloo\n";
			cout << "3. Montreal\n";

			cout << "\nEnter your choice : ";
			cin >> from_opt;

		

				switch (from_opt) {
				case 1:
					fromStation[fromIndexNumber++] = "Toronto";
					break;
				case 2:
					fromStation[fromIndexNumber++] = "Waterloo";
					break;
				case 3:
					fromStation[fromIndexNumber++] = "Montreal";
					break;
				default:
					cout << "Invalid option";
					break;
				}
			} while (from_opt > 3);

			// Get the to-station detail
			do {
				cout << "\nDestination City:\n";
				cout << "1. New York\n";
				cout << "2. Sydney\n";
				cout << "3. Dubai\n";
				cout << "4. London\n";
				cout << "5. New Delhi\n";

				cout << "\nEnter your choice : ";
				cin >> to_opt;

				switch (to_opt) {
				case 1:
					toStation[toIndexNumber++] = "New York";
					break;
				case 2:
					toStation[toIndexNumber++] = "Sydney";
					break;
				case 3:
					toStation[toIndexNumber++] = "Dubai";
					break;
				case 4:
					toStation[toIndexNumber++] = "London";
					break;
				case 5:
					toStation[toIndexNumber++] = "New Delhi";
					break;
				default:
					cout << "Invalid option";
					break;
				}
			} while (to_opt > 5);


			// Get the First Name
			cout << "Enter your first name : ";
			cin.ignore();
			//std::getline(std::cin, firstName[firstIndexNumber++]);
			cin >> firstName[firstIndexNumber++];

			// Get the Last Name
			cout << "Enter your last name : ";
			cin.ignore();
			//std::getline(std::cin, lastName[lastIndexNumber++]);
			cin >> lastName[lastIndexNumber++];
			

			//Get the date of ticket
			cout << "Date of flight : (DD-MM--YYYY) : ";
			cin.ignore();
			cin >> ticketdate[dateIndexNumber++];

			//Get the type of class
			do {
				cout << "\nTicket class:\n";
				cout << "1. Economy\n";
				cout << "2. Business\n";

				cout << "\nEnter your choice : ";
				cin >> class_opt;

			
				switch (class_opt) {
				case 1:
					ticketClass[classIndexNumber++] = "Economy";
					bookedTicketClassType = "Economy";
					break;
				case 2:
					ticketClass[classIndexNumber++] = "Business";
					bookedTicketClassType = "Business";
					break;
				default:
					cout << "Invalid option";
					break;
				}
			} while (class_opt > 2);

			//Get the payment option
			do {
				cout << "\nPayment Option:\n";
				cout << "1. Credit card\n";
				cout << "2. Debit card\n";
				cout << "3. Master card\n";
				
				cout << "\nEnter your choice : ";
				cin >> card_opt;


				switch (card_opt) {
				case 1:
					paymentOption[paymentIndexNumber++] = "Credit card";
					break;
				case 2:
					paymentOption[paymentIndexNumber++] = "Debit card";
					break;
				case 3:
					paymentOption[paymentIndexNumber++] = "Master card";
					break;
				default:
					cout << "Invalid option";
					break;
				}
			} while (card_opt > 3);


			//Get the card number
			cout << "Enter card number (16-digit) : ";
			cin.ignore();
			cin >> cardNumber[cardNoIndexNumber++];


			//Generate random seat number
			srand(time(0));

			long int k = 0;
			k = 10 + (rand() % 90);

			seatNumber[seatIndexNumber++] = std::to_string(k);

			//Generate random ticket number
			srand(time(0));

			long int j = 0;
			j = 10000000 + (rand() % 90000000);

			ticketNumber[ticketNoIndexNumber++] = std::to_string(j);
	
			bookedTicketNumber = std::to_string(j);

			if (bookedTicketClassType == "Economy") {
				fareAmount[fareIndexNumber++] = "680 $";
			}
			else {
				fareAmount[fareIndexNumber++] = "1200 $";
			}
	}
};

// Derived classes
class CancelTicket {
public:
	std::string enteredNumber;
	int counter = 0;

	void cancelDetail(BookTicket &BookTicketObject) {
		cout << "\nEnter your ticket number : ";
		cin >> enteredNumber;

		for (int i = 0; i < ticketNoIndexNumber; i++) {

			if (BookTicketObject.ticketNumber[i] == enteredNumber) {
				counter = 1;

				BookTicketObject.firstName[i] = "";
				BookTicketObject.lastName[i] = "";
				BookTicketObject.fromStation[i] = "";
				BookTicketObject.toStation[i] = "";
				BookTicketObject.ticketdate[i] = "";
				BookTicketObject.ticketNumber[i] = "";
				BookTicketObject.ticketClass[i] = "";
				BookTicketObject.cardNumber[i] = "";

				break;
			}
		}

		if (counter == 0) {
			cout << "\nTicket number not valid! Try again.\n";
		}
		else {
			cout << "\nTicket canceled.\n";
			counter = 0;
		}
	}

};

// Derived classes
class ViewTicket {
public:
	std::string enteredNumber;
	int counter = 0;
	
	void viewDetail(BookTicket &BookTicketObject) {
		cout << "\nEnter your ticket number : ";
		cin >> enteredNumber;

		for (int i = 0 ; i < ticketNoIndexNumber ; i++) {

			if (BookTicketObject.ticketNumber[i] == enteredNumber) {
				counter = 1;
				cout << "\n\n------------------Your Ticket------------------";
				cout << "\n-----------------------------------------------";
				cout << "\n\t\t---Air Canada---";
				cout << "\n   Your Name : " << BookTicketObject.firstName[i] << " " << BookTicketObject.lastName[i];
				cout << "\n   From : " << BookTicketObject.fromStation[i];
				cout << "\t\tTo : " << BookTicketObject.toStation[i];
				cout << "\n   Date : " << BookTicketObject.ticketdate[i] << "\t" << "Seat number : B" << BookTicketObject.seatNumber[i]; 
				cout << "\n   Ticket Class : " << BookTicketObject.ticketClass[i];
				cout << "\n   Ticket number : " << BookTicketObject.ticketNumber[i] << "\tFare : " << BookTicketObject.fareAmount[i];

				cout << "\n-----------------------------------------------\n";
				cout << "-----------------------------------------------\n";
				break;
			}
		}

		if (counter == 0) {
			cout << "\nTicket number not valid! Try again.\n";
		}
		else {
			counter = 0;
		}
	}
};

// Derived classes
class ModifyTicket{
public:
	std::string enteredNumber;
	int counter = 0;

	void modifyTicket(BookTicket &BookTicketObject) {
		cout << "\nEnter your ticket number : ";
		cin >> enteredNumber;

		for (int i = 0; i < ticketNoIndexNumber; i++) {

			if (BookTicketObject.ticketNumber[i] == enteredNumber) {

				counter = 1;
				cout << "\n\n------------------Your Ticket------------------";
				cout << "\n-----------------------------------------------";
				cout << "\n\t\t---Air Canada---";
				cout << "\n   Your Name : " << BookTicketObject.firstName[i] << " " << BookTicketObject.lastName[i];
				cout << "\n   From : " << BookTicketObject.fromStation[i];
				cout << "\t\tTo : " << BookTicketObject.toStation[i];
				cout << "\n   Date : " << BookTicketObject.ticketdate[i] << "\t" << "Seat number : B" << BookTicketObject.seatNumber[i];
				cout << "\n   Ticket Class : " << BookTicketObject.ticketClass[i];
				cout << "\n   Ticket number : " << BookTicketObject.ticketNumber[i] << "\tFare : " << BookTicketObject.fareAmount[i];

				cout << "\n-----------------------------------------------\n";


				//Get the new detail for the ticket

				int from_opt;
				int to_opt;
				int class_opt;
				int card_opt;


				do {
					cout << "\nFrom City:\n";
					cout << "1. Toronto\n";
					cout << "2. Waterloo\n";
					cout << "3. Montreal\n";

					cout << "\nEnter your choice : ";
					cin >> from_opt;

					
					switch (from_opt) {
					case 1:
						BookTicketObject.fromStation[i] = "Toronto";
						break;
					case 2:
						BookTicketObject.fromStation[i] = "Waterloo";
						break;
					case 3:
						BookTicketObject.fromStation[i] = "Montreal";
						break;
					default:
						cout << "Invalid option";
						break;
					}
				} while (from_opt > 3);

				// Get the to-station detail
				do {
					cout << "\nDestination City:\n";
					cout << "1. New York\n";
					cout << "2. Sydney\n";
					cout << "3. Dubai\n";
					cout << "4. London\n";
					cout << "5. New Delhi\n";

					cout << "\nEnter your choice : ";
					cin >> to_opt;

					switch (to_opt) {
					case 1:
						BookTicketObject.toStation[i] = "New York";
						break;
					case 2:
						BookTicketObject.toStation[i] = "Sydney";
						break;
					case 3:
						BookTicketObject.toStation[i] = "Dubai";
						break;
					case 4:
						BookTicketObject.toStation[i] = "London";
						break;
					case 5:
						BookTicketObject.toStation[i] = "New Delhi";
						break;
					default:
						cout << "Invalid option";
						break;
					}
				} while (to_opt > 5);


				// Get the First Name
				cout << "Enter your first name : ";
				cin.ignore();
				//std::getline(std::cin, firstName[firstIndexNumber++]);
				cin >> BookTicketObject.firstName[i];

				// Get the Last Name
				cout << "Enter your last name : ";
				cin.ignore();
				//std::getline(std::cin, lastName[lastIndexNumber++]);
				cin >> BookTicketObject.lastName[i];


				//Get the date of ticket
				cout << "Date of flight : (DD-MM--YYYY) : ";
				cin.ignore();
				cin >> BookTicketObject.ticketdate[i];

				//Get the type of class
				do {
					cout << "\nTicket class:\n";
					cout << "1. Economy\n";
					cout << "2. Business\n";

					cout << "\nEnter your choice : ";
					cin >> class_opt;


					switch (class_opt) {
					case 1:
						BookTicketObject.ticketClass[i] = "Economy";
						bookedTicketClassType = "Economy";
						break;
					case 2:
						BookTicketObject.ticketClass[i] = "Business";
						bookedTicketClassType = "Business";
						break;
					default:
						cout << "Invalid option";
						break;
					}
				} while (class_opt > 2);

				//Get the payment option
				do {
					cout << "\nPayment Option:\n";
					cout << "1. Credit card\n";
					cout << "2. Debit card\n";
					cout << "3. Master card\n";

					cout << "\nEnter your choice : ";
					cin >> card_opt;


					switch (card_opt) {
					case 1:
						BookTicketObject.paymentOption[i] = "Credit card";
						break;
					case 2:
						BookTicketObject.paymentOption[i] = "Debit card";
						break;
					case 3:
						BookTicketObject.paymentOption[i] = "Master card";
						break;
					default:
						cout << "Invalid option";
						break;
					}
				} while (card_opt > 3);


				if (bookedTicketClassType == "Economy") {
					BookTicketObject.fareAmount[i] = "680 $";
				}
				else {
					BookTicketObject.fareAmount[i] = "1200 $";
				}
			}
		}



		if (counter == 0) {
			cout << "\nTicket number not valid! Try again.\n";
		}
		else {
			cout << "\nTicket modified.\n";
			counter = 0;
		}
	}
};




int main()
{
	ShowOption ShowOptionObject;
	BookTicket BookTicketObject;
	ViewTicket viewTicketObject;
	CancelTicket CancelTicketObject;
	ModifyTicket ModifyTicketObject;
	
	while (true) {
		ShowOptionObject.showMenu();

		int opt;
		cout << "\nEnter your option : ";
		cin >> opt;

		switch(opt) {
		case 1:
			BookTicketObject.bookTicket();
			cout << "\nYour ticket booked";
			cout << "\nYour ticket number : " << bookedTicketNumber << "\n\n";
			break;
		case 2:
			CancelTicketObject.cancelDetail(BookTicketObject);
			break;
		case 3:
			viewTicketObject.viewDetail(BookTicketObject);
			break;
		case 4:
			ModifyTicketObject.modifyTicket(BookTicketObject);
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "\nInvalid option\n";
			break;
		}
	}

	system("PAUSE");
	return 0;
}

