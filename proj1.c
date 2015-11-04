/*
 * Subor: proj1.c
 * Datum 2015/11/2
 * Autor: Frantisek Farkas, xfarka04@stud.feec.vutbr.cz
 * Projekt: Praca s textom, projekt cislo 1 pre predmet IZP
 * Popis: Program spracovava vstupne data z stdin ktore nasledne
 *        vyhodnoti a vypise na prikazovy riadok.
 */

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>


#define MAX_SIZE 256
#define TIME_BUFFER_SIZE 80

/* test prvociselnosti */
int is_prime(int number_to_test) {
    int i;
    for (i = 2; i < number_to_test; i++) {
        if (number_to_test % i == 0 && i != number_to_test)
            return 0;

    }
    return 1;

}
/*funkcia zistuje ci je dane slovo palindrom*/
bool is_palindrome(char sentence[100]) {


    int begin, middle, end, length = 0;


    while (sentence[length] != '\0')
        length++;

    end = length - 1;
    middle = length / 2;

    for (begin = 0; begin < middle; begin++) {
        if (sentence[begin] != sentence[end]) {
            return false;

        }
        end--;
    }
    if (begin == middle)
        return true;

    return false;
}

void time_format(int year, int month, int day) {
    struct tm timestr;
    time_t time;
    char buffer[TIME_BUFFER_SIZE];

    timestr.tm_year = year - 1900;
    timestr.tm_mon = month - 1;
    timestr.tm_mday = day;
    timestr.tm_hour = 0;
    timestr.tm_min = 0;
    timestr.tm_sec = 1;
    timestr.tm_isdst = -1;

    time = mktime(&timestr);

    if (time == -1) {
        printf("neplatny datum\n");
    } else {

        strftime(buffer, sizeof(buffer), "date: %a %Y-%m-%d\n", &timestr);
        printf(buffer);
    }

    
}


bool is_number(char *str) {


    for (int i = 0; str[i] != 0; i++) {

        if (!isdigit(str[i])) {
            return false;
        }

    }

    return true;

}

int main(int argc, char *argv[]) {

    int number, day, month, year;

    char buffer[MAX_SIZE];

    if (argc > 1) {
        printf("Program %s spracovava text ktory mu je zadany cez stdin a nasledne ho vyhodnocuje,\n"
                       "a vystup vypise na prikazovy riadok\n", argv[0]);
        return 0;
    }

    while (scanf("%s", buffer) != EOF) {
        if (sscanf(buffer, "%4d-%2d-%2d", &year, &month, &day) == 3) {
            time_format(year, month, day);
        }

        else if (is_number(buffer)) {
            sscanf(buffer, "%d", &number);
            if (is_prime(number) && number < INT_MAX && number > 0) {
                printf("number: %d " "(prime)\n", number);
            } else {
                printf("number: %d\n", number);
            }
        } else {
            if (is_palindrome(buffer)) {
                printf("word: %s " "(palindrome)\n", buffer);
            } else {
                printf("word: %s\n", buffer);
            }

        }


    }


    return 0;

}












