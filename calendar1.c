#include<stdio.h>
//functions
int is_leap_year(int year);
int get_days_in_month(int month,int year);
int get_start_day(int month,int year);

int main() {
    int month,year;
    printf("Enter month(1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    if(month < 1 || month > 12) {
        printf("Invalid month!\n");
        return 1;
    }else {
        printf("Start day of month: %d\n", get_start_day(month,year));
        printf("Days in month: %d\n", get_days_in_month(month,year));
    }
    if(is_leap_year(year)) {
        printf("%d is a leap year.\n",year);
    }else {
        printf("%d is not a leap year.\n",year);
    }
    return 0;
}

int is_leap_year(int year) {
    return((year % 4 == 0 && year % 100 != 0)||year % 400 == 0);
}

int get_days_in_month(int month,int year) {
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

int get_start_day(int month, int year) {
    if(month < 3) {
        month += 12;
        year--;
    }
    int q = 1;
    int k = year % 100;
    int j = year / 100;
    int h = (q + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    int day = (h + 6) % 7;
    return day;

}