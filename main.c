/**
 * Created by Perttu Vanharanta on 19.12.2016.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 15
#define PULSARSIZE 15
#define TRUE 1
#define FALSE 0

#define ALIVE 1
#define DEAD 0

void initArray(int array[MAXSIZE][MAXSIZE]){
    int i, j, n;

    for(i = 0; i < MAXSIZE; i++) {
        for(j = 0; j < MAXSIZE; j++) {
            n = rand() % 100 + 1;
            if(n > 60){
                array[i][j] = ALIVE;
            }else{
                array[i][j] = DEAD;
            }
        }
    }
}


/**
 * CP-Pulsar init
 * Check MAXSIZE and PULSARSIZE is same(15).
 */
void initArrayForPulsar(int array[MAXSIZE][MAXSIZE]){
    int pulsar[PULSARSIZE][PULSARSIZE]={
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
        {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
        {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
        {0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
        {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
        {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
        {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

    memcpy(array,pulsar,sizeof(pulsar));
}


void printArray(int array[MAXSIZE][MAXSIZE]){
    int i, j;

    for(i = 0; i < MAXSIZE; i++) {
        for(j = 0; j < MAXSIZE; j++) {
            printf("%d ", array[i][j]);
        }
    printf("\n");
    }
    printf("\n");
}

int deadOrAliveStatus(int dotStatus, int aliveDots){
    int status = DEAD;

    if(dotStatus == ALIVE){
        if(aliveDots == 2 || aliveDots == 3){
                status = ALIVE;
        }else{
            status = DEAD;
        }
    }else{
        if(aliveDots == 3){
            status = ALIVE;
        }else{
            status = DEAD;
        }
    }

    return status;
}

int firstColumnfirstRowDot(int array[MAXSIZE][MAXSIZE], int i, int j){
    int k,l;
    int aliveDots = 0;
    int status, ownState;

    for(k = i; k <= i+1; k++) {
        for(l = j; l <= j+1; l++) {
            if(array[k][l] == ALIVE){
                if(k==i && l==j){

                }else{
                    aliveDots++;
                }
            }
        }
    }
    ownState = array[i][j];
    status = deadOrAliveStatus(ownState, aliveDots);
    return status;
}

int firstColumnDot(int array[MAXSIZE][MAXSIZE], int i, int j){
    int k,l;
    int aliveDots = 0;
    int status, ownState;

    for(k = i-1; k <= i+1; k++) {
        for(l = j; l <= j+1; l++) {
            if(array[k][l] == ALIVE){
                if(k==i && l==j){

                }else{
                    aliveDots++;
                }
            }
        }
    }
    ownState = array[i][j];
    status = deadOrAliveStatus(ownState, aliveDots);
    return status;
}

int firstColumnlastRowDot(int array[MAXSIZE][MAXSIZE], int i, int j){
    int k,l;
    int aliveDots = 0;
    int status, ownState;

    for(k = i-1; k <= i; k++) {
        for(l = j; l <= j+1; l++) {
            if(array[k][l] == ALIVE){
                if(k==i && l==j){

                }else{
                    aliveDots++;
                }
            }
        }
    }
    ownState = array[i][j];
    status = deadOrAliveStatus(ownState, aliveDots);
    return status;
}

int lastColumnfirstRowDot(int array[MAXSIZE][MAXSIZE], int i, int j){
    int k,l;
    int aliveDots = 0;
    int status, ownState;

    for(k = i; k <= i+1; k++) {
        for(l = j-1; l <= j; l++) {
            if(array[k][l] == ALIVE){
                if(k==i && l==j){

                }else{
                    aliveDots++;
                }
            }
        }
    }
    ownState = array[i][j];
    status = deadOrAliveStatus(ownState, aliveDots);
    return status;
}

int lastColumnDot(int array[MAXSIZE][MAXSIZE], int i, int j){
    int k,l;
    int aliveDots = 0;
    int status, ownState;

    for(k = i-1; k <= i+1; k++) {
        for(l = j-1; l <= j; l++) {
            if(array[k][l] == ALIVE){
                if(k==i && l==j){

                }else{
                    aliveDots++;
                }
            }
        }
    }
    ownState = array[i][j];
    status = deadOrAliveStatus(ownState, aliveDots);
    return status;
}

int lastColumnlastRowDot(int array[MAXSIZE][MAXSIZE], int i, int j){
    int k,l;
    int aliveDots = 0;
    int status, ownState;

    for(k = i-1; k <= i; k++) {
        for(l = j-1; l <= j; l++) {
            if(array[k][l] == ALIVE){
                if(k==i && l==j){

                }else{
                    aliveDots++;
                }
            }
        }
    }
    ownState = array[i][j];
    status = deadOrAliveStatus(ownState, aliveDots);
    return status;
}

int lastRowDot(int array[MAXSIZE][MAXSIZE], int i, int j){
    int k,l;
    int aliveDots = 0;
    int status, ownState;

    for(k = i-1; k <= i; k++) {
        for(l = j-1; l <= j+1; l++) {
            if(array[k][l] == ALIVE){
                if(k==i && l==j){

                }else{
                    aliveDots++;
                }
            }
        }
    }
    ownState = array[i][j];
    status = deadOrAliveStatus(ownState, aliveDots);
    return status;
}

int firstRowDot(int array[MAXSIZE][MAXSIZE], int i, int j){
    int k,l;
    int aliveDots = 0;
    int status, ownState;

    for(k = i; k <= i+1; k++) {
        for(l = j-1; l <= j+1; l++) {
            if(array[k][l] == ALIVE){
                if(k==i && l==j){

                }else{
                    aliveDots++;
                }
            }
        }
    }
    ownState = array[i][j];
    status = deadOrAliveStatus(ownState, aliveDots);
    return status;
}

int otherDot(int array[MAXSIZE][MAXSIZE], int i, int j){
    int k,l;
    int aliveDots = 0;
    int status, ownState;

    for(k = i-1; k <= i+1; k++) {
        for(l = j-1; l <= j+1; l++) {
            if(array[k][l] == ALIVE){
                if(k==i && l==j){

                }else{
                    aliveDots++;
                }
            }
        }
    }
    ownState = array[i][j];
    status = deadOrAliveStatus(ownState, aliveDots);
    return status;
}


int calcArrayDot(int array[MAXSIZE][MAXSIZE], int i, int j){
    int firstColumn = FALSE;
    int firstRow = FALSE;
    int lastColumn = FALSE;
    int lastRow = FALSE;
    int value = 0;

    if(i == 0){
        firstRow = TRUE;
    }
    if(j == 0){
        firstColumn = TRUE;
    }
    if(i == (MAXSIZE-1)){
        lastRow = TRUE;
    }
    if(j == (MAXSIZE-1)){
        lastColumn = TRUE;
    }

    if(firstColumn == TRUE || firstRow == TRUE || lastColumn == TRUE || lastRow == TRUE){
        if(firstColumn == TRUE || lastColumn == TRUE){

            if(firstColumn == TRUE){
                if(firstRow == TRUE){
                    value = firstColumnfirstRowDot(array ,i ,j);
                }else if(lastRow == TRUE){
                        value = firstColumnlastRowDot(array , i ,j);
                    }else{
                        value = firstColumnDot(array ,i ,j);
                    }
            } else if(lastColumn == TRUE){
                if(firstRow == TRUE){
                    value = lastColumnfirstRowDot(array ,i ,j);
                }else if(lastRow == TRUE){
                    value = lastColumnlastRowDot(array ,i ,j);
                }else{
                    value = lastColumnDot(array ,i ,j);
                }
            }
        }else{
            if(firstRow == TRUE){
                value = firstRowDot(array ,i ,j);
            }else{
                value = lastRowDot(array ,i ,j);
            }
        }
    }else{
        value = otherDot(array ,i ,j);
    }

    return value;
}

void calcArray(int array[MAXSIZE][MAXSIZE]){
    int calc_array[MAXSIZE][MAXSIZE];
    int i,j;

    for(i = 0; i < MAXSIZE; i++) {
        for(j = 0; j < MAXSIZE; j++) {
            calc_array[i][j] = calcArrayDot(array, i, j);
        }
    }
    memcpy(array,calc_array,sizeof(calc_array));
}


/**
 * Main
 * Exit from while loop e + enter.
 */
int main()
{
    int show_field[MAXSIZE][MAXSIZE];
    char c;

    initArray(show_field);
    //initArrayForPulsar(show_field);
    printArray(show_field);

    while(c != 'e'){
        c = getc(stdin);
        calcArray(show_field);
        printArray(show_field);
    }

    return 0;
}
