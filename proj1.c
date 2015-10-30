/* IZP Projekt 1
 * Frantisek Farkas 164835
 */
#include<stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {

    return 0;

}


int is_number() {

    int number;
    if (scanf("%d", &number) == 1) {
        return 1;
    } else {
        return 0;
    }

}


int is_prime(int number_to_test) {
    int i;

    for (i = 3; i < number_to_test; i++) {
        if (((i ^ (number_to_test - 1)) % number_to_test) == 1);
        else {
            return 0;
        }
    }
    return 1;

}

int is_palindrome(char *sentence) {

    int length;
    int j;
    int mid;

    length = sizeof(sentence);
    mid = length / 2;

    for (j = 0; j < mid; j++) {
        char left = sentence[j];
        char right = sentence[length - j - 1];

        if (left != right) {
            return 0;
        }
    }
    return 1;

}

void time_format(int year, int month, int day) {
    /*TODO zistenie casu z stdin */
    struct tm timestr;

    timestr.tm_year = year;
    timestr.tm_mon = month;
    timestr.tm_mday = day;

    printf("%d-%d-%d", timestr.tm_year, timestr.tm_mon, timestr.tm_mday);


}

void format_output() {


}






