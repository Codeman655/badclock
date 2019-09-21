#include <iostream>
#include <iomanip>
#include <ctime>

int main()
{
    std::time_t t = std::time(nullptr);
    std::tm trigger;
    trigger.tm_year = 2019;
    trigger.tm_mon = 10;
    trigger.tm_mday = 16;
    trigger.tm_hour = 12; //+4 for UTC/EST
    trigger.tm_min = 0;
    trigger.tm_sec = 0;

    std::time_t t1 = std::mktime(&trigger);

    std::cout << "UTC:   " << std::put_time(std::gmtime(&t1), "%c %Z") << '\n';
    std::cout << "UTC (raw):   " << t1 << '\n';
    std::cout << "local: " << std::put_time(std::localtime(&t1), "%c %Z") << '\n';
}
