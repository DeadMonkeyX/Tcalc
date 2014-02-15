#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


//Add color support
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


void usage(char *argv[])
{
    printf("\n===DM0nk's Tcalc 3.0 ===\n\nUsage: %s <Speed in Mbit> <Size in GB>\n", argv[0]);
    exit(1);

}


int main (int argc, char *argv[])
{
    //Lets check if the argv count if 3 else show usage
    if(argc != 3)
    {
        usage(argv);
    }


    //set and get values from argv and convert if needed.
    double s, t, kb, kbit, speedInSec;
    int sec, minutes, hours, days, years;
    sscanf(argv[2], "%lf", &t);
    sscanf(argv[1], "%lf", &s);


    //get size in kb
    kb = t * 1024 * 1024;

    //get speed in kbit
    s = s / 8;
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


    //Lets write the Result
    cout.precision(3);
    cout << "\n===DM0nk's Tcalc 3.0 ===\n\n" << "Size: " << t << transferFormat << "Speed: " << s << " MB/s\n\n" << "ETA: ";
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

