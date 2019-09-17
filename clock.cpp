#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <ctime>

std::string ex_ec(const char* cmd){
    FILE* pipe;
	char path[128];
	std::string result = "";

	/* open pipe (POSIX Dependant*/
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
    std::tm * tm; // Datetime of target (Competition day at 12:00 EST)
    bool openssl, zip, tar;
	std::string out;

	// check the local time 
    tm = std::localtime(&t); 
	
    openssl = contains(ex_ec("which openssl"),"openssl");
    zip = contains(ex_ec("which zip"),"zip");
    tar = contains(ex_ec("which tar"),"tar");

	std::cout << openssl << std::endl;
	std::cout << zip << std::endl;
	std::cout << tar << std::endl;

/*
    //tm->tm_year = 2019;
    //tm->tm_mon = 11;
    //tm->tm_mday = 30;
    std::cout << "Sleeping..." << std::endl;
    printf("sec: %o \n",tm->tm_sec % 15);
    printf("sec: %d \n",tm->tm_sec % 15);

    while (tm->tm_sec % 15 != 0){
        t = std::time(nullptr);
        tm = std::localtime(&t);
        std::system("sleep 1");
        printf("sec: %d \n",tm->tm_sec % 16);
    }
*/

    //printf("seconds past the minute: %d\n", tm->tm_sec);
    //std::cout << std::endl;
    //tm->tm_hour = 12;
    //std::cout  << std::put_time( &tm, "%c" ) << std::endl;
    //std::cout  << std::asctime(tm) << std::endl;

    /* Run various system commands as root */
	/* Open the command for reading. */
    return 0;
}
