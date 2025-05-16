#include <stdio.h>

void calcAverage(int notes[3])
{
    int average ;
    average = (notes[0] + notes[1] + notes[2]) / 3 ;

    printf("Average of %i, %i, %i is: %i \n", notes[0], notes[1], notes[2],  average);
}

void manualTest()
{
    int inputNotes[3];
    int i = 0;

    while ( i < 3 ) {
        int note ;
        printf("Enter note %i : ", i+1);
    
        if (scanf("%d", &note) != 1) {
            printf("Invalid input. \n");
            continue; 
        }

        inputNotes[i] = note;
        i++;
    }

    calcAverage(inputNotes);
}

int main()
{
    manualTest();
    printf("\nAUTOMATED TESTS\n\n");

    int cases[][3] = { {1, 2, 3}, {5, 6, 7}, {9, 10, 11}, {9, 10, 1} };
    int i ;

    for (i = 0 ; i < 4 ; i++ ) {
        calcAverage(cases[i]) ;
    }

    return 0; 
}
