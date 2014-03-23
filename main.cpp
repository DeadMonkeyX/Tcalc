#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
	Define color codes for Linux and Mac OS X
*/

#if defined(__APPLE__) || defined(__linux__)
#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#endif


/*
	Define color codes for windows, Please note !
	This tool is not "Specially made" for Windows
	So i have used the colors that almost match
	the colors from Linux / Mac ! - DONT HATE!
	OH YE AND WINDOWS REQUIRES A FUCKING LIBERY DEAL WITH IT !
*/

#if defined(_WIN32)
#include <windows.h>
#define RESET "0x07"  /* Reset to default color */
#define BOLDRED "0x0C" /* Red */
#define BOLDCYAN "0x0B" /* Cyan */
#define BOLDWHITE "0x0F" /* White */

/*
	Because we simply cant "print" colors in windows commandprompt
	we need to write a function to make our life easyere!
*/



	void winColor(string colorcode)
	{
        if(colorcode == "0x07")   SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
        if(colorcode == "0x0C") SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0C );
        if(colorcode == "0x0B") SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE), 0x0B );
        if(colorcode == "0x0F") SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE), 0x0F );
	}

#endif

/*
	Because i dont want to write my ascii logo more than once!
	I'm lazy and making a function for printing it !
*/

void logo()
{
   	// Now if we are running Linux or Mac OS X
   	#if defined(__APPLE__) || defined(__linux__) 
   		cout << BOLDCYAN;
   	#endif

   	// Now if we are running Windows
   	#if defined(_WIN32)
   		winColor(BOLDCYAN);
   	#endif

   	// Lets Print the Ascii Logo !
    cout << " _____          _        _____  ___  " << endl;
    cout << "/__   \\___ __ _| | ___  |___ / / _ \\ " << endl;
    cout << "  / /\\/ __/ _` | |/ __|   |_ \\| | | |" << endl;
    cout << " / / | (_| (_| | | (__   ___) | |_| |" << endl;
    cout << " \\/   \\___\\__,_|_|\\___| |____(_)___/ " << endl;
	cout << "====================================" << endl;

	//Reset color for Linux and Mac OS X
	#if defined(__APPLE__) || defined(__linux__)
		cout << RESET;
	#endif

	//Reset color for Windows
	#if defined(_WIN32)
		winColor(RESET);
	#endif

}


//function to print usage
void usage(char *argv[], int argc)
{
    //print the logo
    logo();

    //if there is more parameters than "3"
    if(argc < 3)
    {

    	// Set color to RED for OSX and Linux 
		#if defined(__APPLE__) || defined(__linux__)
			cout << BOLDRED;
 		#endif

		//Set Color to RED for Windows
		#if defined(_WIN32)
			winColor(BOLDRED);
		#endif

		// Print Error
		cout << "E: Missing Arguments";
		
		// Reset color for Linux and OS X
		#if defined(__APPLE__) || defined(__linux__)
			cout << RESET;
		#endif

		// Reset color for Windows
		#if defined(_WIN32)
			winColor(RESET);
		#endif

		cout << "\n" << endl;

	}

	// Print usage
    cout << "Usage: " << argv[0] << " <Speed in Mbit> <Size in GB> [overhead]\n " << endl;
    exit(1);

}


int main (int argc, char *argv[])
{
    //Lets check if the argv count if 3 else show usage
    if(argc < 3)
    {
        usage(argv, argc);
    }


    //set and get values from argv and convert if needed.
    double s, t, kb, kbit, speedInSec, ohs, ohsec;
    int sec, minutes, hours, days, years, overhead;
    sscanf(argv[2], "%lf", &t);
    sscanf(argv[1], "%lf", &s);
	if(argv[3] != 0)
	{
		sscanf(argv[3], "%i", &overhead);
	}


    //get size in kb
    kb = t * 1024 * 1024;

    //get speed in kbit
	if(argv[3] != 0)
	{
		if(overhead > 99)
		{
			overhead = 99;
		}

		ohs = s * overhead / 100;
		ohs = s - ohs;
		s = ohs / 8;
	}
	else
	{
		s = s / 8;
	}
	kbit = s * 1000;
    speedInSec = kb / kbit;

    //Do the calculation

    minutes = (int)speedInSec / 60;
    sec =  (int)speedInSec % 60;

    hours = minutes / 60;
    minutes = minutes % 60;

    days = hours / 24;
    hours = hours % 24;

    years = days / 365;
    days = days % 365;

    string transferFormat = "";
    if(t >= 1000 )
    {
        t = t / 1024;
        transferFormat = " TB\n";
    }else
    {
        transferFormat = " GB\n";
    }


    //Now lets print the logo and the result
    logo();

    cout.precision(3);


	#if defined(__APPLE__) || defined(__linux__)
    cout << BOLDWHITE <<  "Size: " << RESET << t << transferFormat << BOLDWHITE << "Speed: " << RESET << s << " MB/s" << BOLDWHITE << "\nOverhead: "<< RESET <<  overhead << "%\n\n" << BOLDWHITE << "ETA: " << RESET;
    #endif

	#if defined(_WIN32)
	winColor(BOLDWHITE);
	cout << "Size: ";
	winColor(RESET);
	cout << t << transferFormat;
	winColor(BOLDWHITE);
	cout << "Speed: ";
	winColor(RESET);
	cout << s << " MB/s\n";
	winColor(BOLDWHITE);
	cout << "Overhead: ";
	winColor(RESET);
	cout << overhead << "%\n\n";
	winColor(BOLDWHITE);
	cout << "ETA: ";
	winColor(RESET);
	#endif

	if(years != 0)
    {
    cout << years << " Years - ";
    }

    if(days != 0 || years != 0){
    cout << days << " Days - ";
    }

    if(hours
        != 0 || days != 0 || years != 0)
    {
        cout << hours << " Hours - ";

    }

    if(minutes != 0 || hours !=0 || days != 0 || years != 0)
    {
        cout << minutes << " Minutes - ";
    }

    cout << sec << " Seconds\n" <<endl;




    return 0;
}

