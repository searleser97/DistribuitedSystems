#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <thread>
#include <chrono>

using namespace std;



int main()
{

    struct tm *info;
    time_t rawtime;
    char timestring[80];
    char final_time[80];
    struct timeval tv;
    while(true)
    {
        gettimeofday(&tv, NULL);
        
        info = localtime(&tv.tv_sec);

        strftime(timestring, 80, "%H:%M:%S.%%06u", info);
        snprintf(final_time, 80, timestring, tv.tv_usec);
        printf("%s\n", final_time);
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}