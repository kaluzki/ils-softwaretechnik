// Bei der ersten Aufgabe soll ein Programm in C geschrieben werden, dass eine beliebige Zahl
// kleiner als 1000, in Hunderter, Zehner und Einser zerlegt und jeweils als Wort ausgibt.
// Das ganze soll folgendermaßen aussehen:
// 17 wird zu ONE SEVEN
// 717 wird zu SEVEN ONE SEVEN
// 7
// wird zu SEVEN
// Die Eingabe- und Ausgabe soll folgendermaßen erfolgen:
// Please enter a number between 0 and 999: 777
// SEVEN SEVEN SEVEN

#include <stdio.h>
#include <math.h>

#define ZERO "ZERO"
#define ONE "ONE"
#define TWO "TWO"
#define THREE "THREE"
#define FOUR "FOUR"
#define FIVE "FIVE"
#define SIX "SIX"
#define SEVEN "SEVEN"
#define EIGHT "EIGHT"
#define NINE "NINE"

void printNumberInWords(unsigned int number);
const char* digitAsWord(unsigned int digit);

int main() {
    int number;
    printf("Please enter a number between 0 and 999: ");
    scanf("%d", &number);
    if (number < 0 || number > 999) {
        printf("Invalid number! Please enter a number between 0 and 999.\n");
        return 1;
    }
    printNumberInWords(number);
    return 0;
}

void printNumberInWords(unsigned int number) {
    int digit, digitSum, power;
    for (int i = 2; i >= 0; i--) {
        power = (int)pow(10, i);
        digit = number / power;
        digitSum += digit;
        if (digitSum || !i) {
            printf("%s ", digitAsWord(digit));
        }
        number %= power;
    }
    return;
}

const char* digitAsWord(unsigned int digit) {
    switch(digit) {
        case 0: return ZERO;
        case 1: return ONE;
        case 2: return TWO;
        case 3: return THREE;
        case 4: return FOUR;
        case 5: return FIVE;
        case 6: return SIX;
        case 7: return SEVEN;
        case 8: return EIGHT;
        case 9: return NINE;
        default: return "";
    }
}