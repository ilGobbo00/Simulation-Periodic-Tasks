#include "utilities.h"


// Structs
struct th_info {
    unsigned long id;
    int period;
    int exetime;
    int priority;
    // float utilization;
};

struct thread {
    struct th_info info;     // Thread info
    pthread_t * thread;
    int check_period;   // Count to check the execution within each period
    int rem_time;       // Remaining time
}threads[MAX_THREADS];

int lcm(int index, int mcm){
    if(index == active_threads-1) return mcm;

    int b = threads[++index].info.period;

    int max = (mcm > b) ? mcm : b;
    while((max % mcm != 0) || (max % b != 0))
        max++;
    
    printf("found %d\n", max);

    return lcm(index, max);
}

int is_RM(){
    float tot_utilization;

    for(int i=0; i<active_threads; i++)
        tot_utilization += threads[i].info.exetime / threads[i].info.period;

    return (tot_utilization < log(2)) ? 1 : 0;
}

int is_schedulable(){
    // TODO: implement scheduler
    return 0;
}

int create_server(int port){
    // TODO: implement server
    return 0;
}

int listen(int socket){
    // TODO: implement messages receiving
    return 0;
}