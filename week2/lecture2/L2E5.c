#include <stdio.h>


void safety_check()
{
        printf("Safety_Check!\n");
}
void fire_boosters()
{
        printf("Boosters Fired!\n");
}
int main()
{
        int launch_state=0;
        if(launch_state)
                safety_check();
        fire_boosters();
        return(0);
}
