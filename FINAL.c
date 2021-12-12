#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//FUNCTION
    //REMOVE SPACE
int RemoveSpace(char input[], int length){
    for(int i=0; i<length; i++){
        if(input[i]==' '){
            for(int j=i; j<length; j++){
                input[j]=input[j+1];
            }
        }
    }
    //printf("%s \n", input); // OUTPUT INPUTAN TANPA SPASI
    return *input;
}
    //VALIDATE INPUT (JIKA SETELAH ANGKA BUKAN '+'/'-', AKAN INVALID)
int ValidateInput(char input[], int length){
    for(int i = 0; i<length; i++){
        if(!isdigit(input[i])){
            if(!isdigit(input[i+1]) || i == 0 || !(input[i] == '+' || input[i] == '-')){
                printf("Format Input Salah!!");
                exit(0);
            }
        }
    }
}


//MAIN PROGRAM
int main(){
    int length;
    char input[512];
    printf("\nProgram Final Project: Kalkulator 'Sederhana'\nMxxxxxxx Ixxxxx Rxxx Sxxxxxx - 502421xxxx\nKelompok Dxxxxxxx\n");
    printf("\nMasukkan Perhitungan (CONTOH: 5 + 4 - 2 + 3):\n");
    scanf("%[^\n]s", &input); // INPUT PROGRAM (INPUT BERUPA STRING)
    length=strlen(input); // LENGTH ADALAH PANJANG DARI INPUT
    RemoveSpace(input, length);
    length=strlen(input); // LENGTH = PANJANG INPUT TANPA SPASI
    ValidateInput(input, length);

    //CHECK NUMBER & OPERATOR
    int i=0, NumCount=0, OpCount=0, IndRead=0; //NumCount=jumlah angka, OpCount=jumlah operator, IndRead=index keberapa yang dibaca
    int numbers[512];
    char operator[512];
    for(i=0; i<length; i++){
        if(i == length-1){ 
            numbers[NumCount] = atoi(input + IndRead);
            NumCount++;
        }
        if(!isdigit(input[i])){
            operator[OpCount] = input[i];
            OpCount++;
            numbers[NumCount] = atoi(input + IndRead);
            NumCount++;
            IndRead=i+1;
        }
    }

    //ADDITION AND SUBTRACTION
    int result = numbers[0];
    for(int j = 0; j < OpCount; j++){
        if(operator[j]=='+'){
            result += numbers[j+1];
        }
        else if(operator[j]=='-'){
            result -= numbers[j+1];
        }
    }

    //PRINT RESULT

    //printf("\nNumber Count: %d", NumCount);
    /*for(int OutputNum=0; OutputNum<NumCount; OutputNum++){
        printf("%d ", numbers[OutputNum]);
    } */

    //printf("\nOperator Count: %d", OpCount);
    /* for(int OutputOp=0; OutputOp<OpCount; OutputOp++){
        printf("%c ", operator[OutputOp]);
    } */
    printf("\nHasil: %d", result);
}
    