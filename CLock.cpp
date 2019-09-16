//#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <ctime>

int main(){
    /* Check for current time */
    std::time_t t = std::time(nullptr);
    std::tm * tm; //Datetime of target (Competition day at 12:00 EST)
    tm = std::localtime(&t);
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
    printf("seconds past the minute: %d\n", tm->tm_sec);
    std::cout << std::endl;
    //tm->tm_hour = 12;
    //std::cout  << std::put_time( &tm, "%c" ) << std::endl;
    std::cout  << std::asctime(tm) << std::endl;

    /* Run various system commands as root */
    std::system("echo done");

    return 0;
}
