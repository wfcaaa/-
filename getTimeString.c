#include<stdio.h>
#include<time.h>
#include<sys/time.h>
static char *getTimeString(void)
{
    static char theTimeString[64];
    struct tm theLocaltime;
    time_t theTime;
    struct timeval getTime;
    
    gettimeofday(&getTime, NULL);
    theTime = (time_t) getTime.tv_sec;
    localtime_r(&theTime, &theLocaltime);
    sprintf(theTimeString, "%4d/%02d/%02d %02d:%02d:%02d.%04d",
	theLocaltime.tm_year + 1900,
	theLocaltime.tm_mon + 1,
	theLocaltime.tm_mday,
	theLocaltime.tm_hour,
	theLocaltime.tm_min,
	theLocaltime.tm_sec,
	(int)(getTime.tv_usec));

    return theTimeString;	
}

int main()
{

    printf("%s\n",getTimeString());
     printf("%s\n",getTimeString());
   
    
    return 0;
}
