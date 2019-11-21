#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <thread>
#include <chrono>
#include "Reply.h"

using namespace std;


int main()
{

    struct tm *info;
    time_t rawtime;
    char timestring[80];
    char final_time[80];
    struct timeval tv;

    uint16_t puerto;
	cout << "Puerto en el que se va a escuchar: ";
	cin >> puerto;
    Reply reply(puerto);
    /*while(true)
    {
        gettimeofday(&tv, NULL);
        info = localtime(&tv.tv_sec);

        strftime(timestring, 80, "%H:%M:%S.%%06u", info);
        snprintf(final_time, 80, timestring, tv.tv_usec);
        printf("%s\n", final_time);
        //this_thread::sleep_for(chrono::seconds(1));
    }*/

    while (1) {
		Message *msg = reply.getRequest();
		if (msg->operationId == Message::allowedOperations::getTime) {
            gettimeofday(&tv, NULL);
			reply.sendReply((char*)&tv, sizeof(tv));
		}
    }

    return 0;
}