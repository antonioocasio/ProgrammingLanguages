/*
Tony Ocasio
Module Project One: Clock.cpp
*/

#include<iostream>
using namespace std;

// declare class for 24 hour time
class _24HourTime;

// enum tracks AM or PM for the 12 hour clock
enum AMPM { AM , PM } ampm;

// Abstract class used to track time
class Time {
	public:
	// declare variables
	int hour, minute, second;
	virtual void addHour() = 0;
	virtual void addMinute() = 0;
	virtual void addSecond() = 0;
};

// _12HourTime class which inherits the Time class
class _12HourTime : public Time {
	// Method to manage the 12 hour time
    public:
    _12HourTime(int h , int m , int s) {
    	hour = h;
    	minute = m;
    	second = s;
    	ampm = PM;
    }

    // Method that adds a hour to the clock
    void addHour() {
			// if hour is 11
    	if(hour == 11) {
				// set the hour to 12
    		hour = 12;
				// switch am to pm vise versa
    		ampm = ampm == PM ? AM : PM;
    	} else {
				// add 1 hour
    		hour += 1;
    	}
			// if the hour is greater than 10
			if(hour > 12){
				// set the hour to 1
				hour = 1;
			}
    }

    // Method that adds a minute to the clcok
    void addMinute() {
			// if minute is 59
    	if(minute == 59) {
				// set minute to 0
    		minute = 0;
				// call add hour method
    		addHour();
    	}else {
				// add 1 minute
    		minute += 1;
    	}
    }

    // Method that adds a second to the clock
    void addSecond() {
			// if seconds is 59
    	if(second == 59) {
				// set seconds to 0
    		second = 0;
				// call add minute method
    		addMinute();
    	}else {
				// add 1 second
    		second += 1;
    	}
    }

// Declare friend to give proper access
friend void displayTime(const _12HourTime& ,const _24HourTime&);
};

// _24HourTime class which inherits the Time class
class _24HourTime : public Time {
	// Method to manage 24 hour time
	public:
	_24HourTime(int h , int m , int s) {
		hour = h;
		minute = m;
		second = s;
	}

// Method that adds a hour to the clcok
	void addHour() {
		// if the hour is 23
		if(hour == 23) {
			// set the hour to 0
			hour = 0;
		}else {
			// else add 1 hour
			hour += 1;
		}
	}

// Method that adds a minute to the clcok
	void addMinute() {
		// if minute = 59
		if(minute == 59) {
			// set minute to 0
			minute = 0;
			// call the add hour method
			addHour();
		}else {
			// otherwise add 1 minute
			minute += 1;
		}
	}

// Method that adds a second to the clock
	void addSecond() {
		// if seconds is 59
		if(second == 59) {
			// set second back to 0
			second = 0;
			// add 1 minute
			addMinute();
		}else {
			second += 1;
		}
	}

	// Declaring friend to give access
	friend void displayTime(const _12HourTime& ,const _24HourTime&);
	};

	// displays time format for each clock
	void displayTime(const _12HourTime& time12 ,const _24HourTime& time24) {
		cout << "*************************** ***************************\n";
		cout << "*     12-Hour Clock       * *      24-Hour Clock      *\n";
		cout << "*     ";

		// if hour is less than 10
		if(time12.hour < 10)
				// add 0 before the hour
		    cout << "0"; cout << time12.hour << ":";

		// if minute is less than 10
		if(time12.minute < 10 )
				// add a 0 before the minute
		    cout << "0" ; cout << time12.minute << ":";

		// if seconds is less than 10
		if(time12.second < 10)
				// add a 0 before the secondd
		    cout << "0"; cout << time12.second;

		if(ampm == PM )
		    cout << " P M";
				else
					cout << " A M";
          cout << "        * *         ";

		// if hour is less than 10
		if(time24.hour < 10)
				// add 0 before the hour
    		cout << "0"; cout << time24.hour << ":";

		// if minute is less than 10
		if(time24.minute < 10 )
				// add a 0 before the minute
    		cout << "0" ; cout << time24.minute << ":";

		// if seconds is less than 10
		if(time24.second < 10)
				// add a 0 before the second
    		cout << "0"; cout << time24.second;
    		cout << "        *\n";
    		cout << "*************************** ***************************\n";
	}

	// Create the interface
	void displayMenu() {
		cout << "***************************\n";
		cout << "* 1 - Add One Hour        *\n";
		cout << "* 2 - Add One Minute      *\n";
		cout << "* 3 - Add One Second      *\n";
		cout << "* 4 - Exit Program        *\n";
		cout << "***************************\n";
	}

	// Declare main method
	int main() {
		// Create 12 hour time clock
		_12HourTime time_12_Clock(1, 0, 0);

		// Create 24 hour time clock
		_24HourTime time_24_Clock(13, 0 ,0);

		// display time for both clocks
		displayTime(time_12_Clock , time_24_Clock);

		// while user wants to continue
		while(true) {
			// display time clock
			displayMenu();

			// declare variable for user userChoice
			int userChoice;

			// get the choice from the user and store in userChoice
			cin >> userChoice;

			// Add interface functionality
			switch (userChoice) {
			// if user choice is 1
			case 1:
				// add 1 hour to the 12 hour clcok
				time_12_Clock.addHour();
				// add 1 hour to the 24 hour clock
				time_24_Clock.addHour();
				// display time clocks
				displayTime(time_12_Clock , time_24_Clock);
				// exit the cases
				break;

			// if userChoice is 2
			case 2:
				// add 1 minute to the 12 hour clock
				time_12_Clock.addMinute();
				// add 1 minute to the 24 hour clock
				time_24_Clock.addMinute();
				// display time clocks
				displayTime(time_12_Clock , time_24_Clock);
				// exit the cases
				break;

			// if userChoice is 3
			case 3:
				// add 1 second to the 12 hour clock
				time_12_Clock.addSecond();
				// add 1 second to the 24 hour clock
				time_24_Clock.addSecond();
				// display time clcoks
				displayTime(time_12_Clock , time_24_Clock);
				// exit cases
				break;

			// if userChoice is 4
			case 4:
				// display "quit"
				cout << "Quit";
				// exit the while statement
				exit(1);
				break;

			// if userChoice is anything else
			default:
				// display error message
				cout << "Please enter a valid input.\n";
				break;
		}
	}
}
