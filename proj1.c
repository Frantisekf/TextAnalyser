/* IZP Projekt 1
 * Frantisek Farkas 164835
 */
#include<stdio.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    int num = 4;
    if (is_prime(num) == 1) {
        printf("je prime\n");
    }
    else {
        printf("nieje prime\n");
    }
    char sent[100] = "wow";

    is_palindrome(sent);

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
    for (i = 2; i < number_to_test; i++) {
        if (number_to_test % i == 0 && i != number_to_test)
            return 0;

    }
    return 1;

}

int is_palindrome(char sentence[100]) {


    int begin, middle, end, length = 0;


    while (sentence[length] != '\0')
        length++;

    end = length - 1;
    middle = length / 2;

    for (begin = 0; begin < middle; begin++) {
        if (sentence[begin] != sentence[end]) {
            printf("Not a palindrome.\n");
            break;
        }
        end--;
    }
    if (begin == middle)
        printf("Palindrome.\n");

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






