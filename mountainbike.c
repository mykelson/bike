#include <stdio.h>
#include <bicycle.h>
#include <string.h>


int seat_height;
char* set_height(int new_value);
void set_bike_control(void);
char* flow_control(int* speed, int* gear, int* cadence, int flow_value);


int main (int argc, char* argv[])
{
    if ( (argc == 3) && ((strcmp(argv[1], "start") == 0) &&(strcmp(argv[2], "engine") == 0)))
    {
        set_bike_control();
    }
    else if (argc != 3)
    {
        printf("Please input the words \"start engine\" \n");
        
        char start_command[30];
        scanf(" %[^\n]s", start_command);

        if (strcmp(start_command, "start engine") == 0)
        {
            set_bike_control();
        }
        else
        {
            printf("Goodbye...");
        }
        
    }
    else
    {
        printf("\nRe- run the program again and input the words \"start engine\" after the program name\n");
    }
}

char* set_height(int new_value)
{
    seat_height = new_value;
}


void set_bike_control(void)
{

     bicycle my_bike;
    my_bike.speed = 0;
    my_bike.gear = 1;
    my_bike.cadence = 1;

    printf("Welcome pick a function: \n*Press 1 to Speedup\n*Press 2 Change Gear\n*Press 3 to Set Cadence\n*Press 4 to Apply Brakes\n*Press 5 to Quit\n");

    int new_value;
 scanf("%i", &new_value);

    while(new_value <=0 || new_value >= 6)
    {
        printf("Retry: ");
        scanf("%i", &new_value);
  }

    switch (new_value)
 {
        case 1:
        case 2:
        case 3:
        case 4:
        flow_control(&my_bike.speed, &my_bike.gear, &my_bike.cadence, new_value);
      break;
        case 5:printf("Goodbye....\n");
        break;
        default: printf("Invalid Entry, Goodbye....\n");
    }


}

char* flow_control(int* speed, int* gear, int* cadence, int flow_value)
{
    int recall = 10;


    if (flow_value == 1)
    {
    printf("\nIncrease by how many kmps (NOTE MAX ACCELERATION IS 50KMPS): ");
    int new_value;
    scanf(" %i", &new_value);

    while(new_value <= 0 || new_value > 50)
        {
            printf("Retry: ");
            scanf("%i", &new_value);
        }

    speed_up(speed, new_value);
    }
    else if (flow_value == 2)
    {
        printf("\nChange to gear: ");
        int new_value;
        scanf(" %i", &new_value);

        while(new_value <= 0 || new_value >= 5)
        {
            printf("Retry: ");
            scanf("%i", &new_value);
        }
        change_gear(gear, new_value);
    }
    else if (flow_value == 3)
    {
        printf("\nChange to cadence: ");
        int new_value;
        scanf(" %i", &new_value);

        while(new_value <= 0 || new_value >= 5)
        {
            printf("Retry: ");
            scanf("%i", &new_value);
        }
        change_cadence(cadence, new_value);
    }
    else if (flow_value == 4)
    {
        printf("\nDecrease speed by how many kmps: ");
        int new_value;
        scanf(" %i", &new_value);

        while(new_value <= 0 || new_value >= 50)
        {
            printf("Retry: ");
            scanf("%i", &new_value);
        }
        apply_brakes(speed, new_value);
    }
    else if (flow_value == 5)
    {
        return (char*)printf("\nEngine Off, Goodbye......");
    }
    else
    {
        printf("Invalid Entry, Goodbye....\n");
    }



    printf("\n*Press 5 to Quit or Continue: ");

    int new_value;
    scanf(" %i", &new_value);

    while(new_value <= 0 || new_value >= 6)
        {
            printf("Retry: ");
            scanf("%i", &new_value);
        }

    flow_control(speed, gear, cadence,new_value);

}