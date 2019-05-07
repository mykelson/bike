
#ifndef bicycle




#include <stdio.h>

char* change_cadence(int* current_cadence, int new_value);
char* change_gear(int* current_gear, int new_value);
char* speed_up(int* current_speed, int increment);
char* apply_brakes(int* current_speed, int decrement);



struct bicycle
{
    // variables for our struct
    int cadence;
    int speed;
    int gear;
    
};
typedef struct bicycle bicycle;

// a function that changes the cadence
char* change_cadence(int* current_cadence, int new_value)
{
    *current_cadence = new_value;
    return (char*)printf("you are now on cadence %i\n", new_value);
}

char* change_gear(int* current_gear, int new_value)
{
    *current_gear = new_value; 
    return (char*)printf("you are now on gear %i\n", new_value);
}

char* speed_up(int* current_speed, int increment)
{
    int temp = *current_speed;
    temp = temp + increment;
    *current_speed = temp;
    return (char*)printf("You are now moving at %i kmps\n", temp);
}

char* apply_brakes(int* current_speed, int decrement)
{
    int temp = *current_speed;
    temp = temp - decrement;
    *current_speed = temp;
    return (char*)printf("you are now moving at %ikmps\n", temp);
}


#endif 