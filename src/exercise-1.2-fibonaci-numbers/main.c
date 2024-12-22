// Die zweite Teilaufgabe behandelt Fibonacci-Zahlen, genauer gesagt die Summe aller geraden
// bzw. ungeraden Fibonacci-Zahlen, welche ein vorgegebenes Limit nicht überschreiten.
// Die Fibonacci-Folge f1 , f2 , f3 , . . . ist durch das rekursive Bildungsgesetz fn = fn−1 + fn−2 für
// n ≥ 3 mit den Anfangswerten f1 = f2 = 1 definiert.
// Angefangen bei 1 und 2, ergeben sich die ersten zehn Zahlen zu:
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
// Hinweis: Wie am Beispiel erkennbar, werden nur voneinander verschiedene Fibonaccizahlen aufsummiert.
// Bei einem gegebenen Maximum von beispielsweise 20, lauten die Summe aller geraden-/
// ungeraden Fibonacci-Zahlen:
// Summegerade = 2 + 8 = 10;
// Summeungerade = 1 + 3 +5 +13 = 22
// Ihre Aufgabe wird es sein, ein Programm in C zu schreiben, dass nach einer Eingabeauf-
// forderung eine beliebige Zahl ∈ N einliest und die beiden Summen aller Fibonacci-Zahlen,
// welche den eingegebenen Wert nicht überschreiten ausgibt.
// Die Eingabe- und Ausgabe soll folgendermaßen erfolgen:
// Please enter the max value for calculating the even- and uneven sum of fibonacci-
// numbers: 20
// The sum of all Fibonacci-numbers not exceeding the entered max of 20 is 10 (even)
// and 22 (odd)

#include <stdio.h>

void calculateFibonacciSums(int maxValue, int* evenSum, int* oddSum);

int main (void) {
    int maxValue, evenSum, oddSum;
    printf("Please enter the max value for calculating the even- and uneven sum of fibonacci-numbers: ");
    scanf("%d", &maxValue);
    calculateFibonacciSums(maxValue, &evenSum, &oddSum);
    printf(
        "The sum of all Fibonacci-numbers not exceeding the entered max of %d is %d (even) and %d (odd)\n", 
        maxValue, 
        evenSum, 
        oddSum
    );
    return 0;
}

void calculateFibonacciSums(int maxValue, int* evenSum, int* oddSum)
{
    for (int f = 1, f1 = 1, f2 = 1; f <= maxValue; f = f1 + f2) {
        f1 = f2;
        f2 = f;
        if (f % 2) {
            *evenSum += f;
        } else {
            *oddSum += f;
        }
    }
}