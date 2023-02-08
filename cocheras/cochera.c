
#include <stdio.h>
#include <stdlib.h>
#include "../../../pi/libreria/getnum.h"

#define MONTHS 12
#define CARS 18
#define COL 2
#define ROW 8

int ** moveToRight(int **distribution);

void printCars(int **distribution, char * cars[]);

int main(void){
    
    int **distribution = malloc(ROW * sizeof(int *));
    
    for (int i = 0; i < ROW; i++) {
        distribution[i] = malloc(COL * sizeof(int));
    }

    int initial[ROW][COL] = {{3,15},{4,14},{6,2},{5,1},{13,0},{12,7},{11,8},{10,9}};
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            distribution[i][j] = initial[i][j];
        }
    }

    char * cars[CARS] = {"1A","3B","7B","7A","9B","PBA","2A","8A","10B","4A","1B","5B","10A","4B","2B","3A"};
    char * month[MONTHS] = {"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"};
    
    puts("Distribucion del mes de Octubre:");
    printCars(distribution, cars);
    puts("-----\t\t\t\t-----");
    puts("\t |   |  |   |  |   |");
    puts("\t | L |  | L |  | L |");
    puts("\t -----  -----  -----");



    int num = getint("Ingrese mes actual (ej: Abril = 4): ");
    puts("");
    int nNum;

    nNum = (num + 2) % 12;

    
    for (int i=0; i<nNum; i++){
        distribution = moveToRight(distribution);        
    }

    printf("Distribucion del mes de %s:\n\n", month[num-1]);
    printCars(distribution, cars);
    puts("-----\t\t\t\t-----");
    puts("\t |   |  |   |  |   |");
    puts("\t | L |  | L |  | L |");
    puts("\t -----  -----  -----");



    for(int i = 0; i < ROW; i++) {
        free(distribution[i]);
    }
    free(distribution);

    printf("\n\nPresione Enter para finalizar el programa...");
    getchar();

    return 0;
}

void printCars(int **distribution, char * cars[]){

    printf("  \\   \\    ------   ------    /   /\n");
    printf("   \\%s \\  |  6A  | | PB B |  /   /\n", cars[distribution[0][1]]);
    printf("    \\%s \\ |      | |      | /   /\n", cars[distribution[0][0]]);


    for (int i=1, j=1; i<ROW+1; i++){
        puts("-----\t\t\t\t-----");
        if (i < ROW)
            printf("|%s\t\t\t\t  %s|\n", cars[distribution[i][0]], cars[distribution[i][1]]);
        else{ 
            printf("|LIBRE\t\t\t\tLIBRE|\n");
            j++;
        }
    }

}


int ** moveToRight(int **distribution) {
    int **newDis = malloc(ROW * sizeof(int *));

    for(int i = 0; i < ROW; i++) {
        newDis[i] = malloc(COL * sizeof(int));
    }

    for (int i = 0; i<ROW; i++) {
        for (int j=0; j<COL; j++){
            if (!i && j){
                newDis[i][j] = distribution[i][0];
            }else if (i== ROW-1 && !j){
                newDis[ROW-1][j] = distribution[i][COL-1];
            }else if (!j && i != ROW-1){
                newDis[i][j] = distribution[i+1][j];
            }else if (j && i){
                newDis[i][j] = distribution[i-1][j];
            }
        }
    }

     for(int i = 0; i < ROW; i++) {
        free(distribution[i]);
    }
    free(distribution);

    return newDis;
}

