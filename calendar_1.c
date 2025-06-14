#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EVENT_LENGTH 100
#define MAX_EVENTS 100
#define FILENAME "events.txt"

typedef struct {
    int year;
    int month;
    int day;
    char description[MAX_EVENT_LENGTH];
} Event;


int is_leap_year(int year);
int get_days_in_month(int month, int year);
int get_start_day(int month, int year);
void display_calendar(int month, int year);
void display_full_year(int year);
void add_event_to_file(int year, int month,int day,const char*desc);
void view_events_from_file(int year, int month);


int main(){
     int year, month, choice, day;
    char description[MAX_EVENT_LENGTH];
    printf("Enter month(1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d",&year);
        while(1) {
        printf("\nMenu:\n");
        printf("1.View Calendar\n");
        printf("2.View Full Year\n");
        printf("3.Add Event\n");
        printf("4.View Events\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d",&choice);
        getchar();

        switch(choice) {
            case 1: display_calendar(month, year);
            break;
            case 2: display_full_year(year);
            break;
            case 3: printf("Enter day: ");
            scanf("%d", &day);
            getchar();
            printf("Enter event description: ");
            fgets(description, MAX_EVENT_LENGTH, stdin);

            description[strcspn(description,"\n")]='\0';
            add_event_to_file(year, month, day, description);
            break;
            case 4: view_events_from_file(year, month);
            break;
            
            case 5: exit(0);
            default:
            printf("Invalid option.\n");
        }
    }
    return 0;


}


int is_leap_year(int year){
    return ((year % 4 == 0 && year % 100 !=0) || (year % 400 == 0));
}


int get_days_in_month(int month, int year){
    switch (month) {
        case 1: return 31;
        case 2: return is_leap_year(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}
    
int get_start_day(int month, int year){
    if(month < 3) {
        month += 12;
        year--;
    }
    int q = 1;
    int k = year % 100;
    int j = year / 100;
    int h =(q + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + 5 * j) % 7;
    return (h + 5) % 7; // Adjusting to make Sunday = 0}
}

void display_calendar(int month, int year){
    char *months[] = { "", "January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December" };

    printf("\n  ------------%s %d------------\n", months[month], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int start_day = get_start_day(month, year);
    int days = get_days_in_month(month, year);

    for (int i = 0; i < start_day; i++) {
        printf("     ");
    }

    for (int day = 1; day <= days; day++) {
        printf("%5d", day);
        if ((start_day + day) % 7 == 0)
            printf("\n");
    }
    printf("\n");
}
void display_full_year(int year) {
    for (int month = 1; month <= 12; month++) {
        display_calendar(month, year);
        printf("\n");
    }
}