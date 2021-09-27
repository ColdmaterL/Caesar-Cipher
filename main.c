#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


char *soLetras(char word[]){
    char c;
    int i = 0;
    do{
        c = getch();
        if(isalpha(c) != 0 || c == 32){
            word[i] = c;
            i++;
            printf("%c", c);
        }
        else if(c == 8 && i){
            word[i] = '\0';
            i--;
            printf("\b \b");
        }
    }while(c != 13);
    word[i] = '\0';
    printf("\n");
    return word;
}


int soNumeros(){
    char word[50];
    char c;
    int i = 0;
    int num;
    do{
        c = getch();
        if(isdigit(c) != 0){
            word[i] = c;
            i++;
            printf("%c", c);
        }
        else if(c == 8 && i){
            word[i] = '\0';
            i--;
            printf("\b \b");
        }
    }while(c != 13);
    word[i] = '\0';
    num = atoi(word);
    printf("\n");
    return num;
}


char *caesarEncode(char word[]){
    int i;
    for(i = 0; i < strlen(word); i++){
        word[i] = toupper(word[i]);
        word[i] = word[i] + 3;
        switch(word[i]){
            case '#':
                word[i] = word[i] - 3;
            break;
            case '[':
                word[i] = word[i] - 26;
            break;
            case '\\':
                word[i] = word[i] - 26;
            break;
            case ']':
                word[i] = word[i] - 26;
            break;
        }
    }
    return word;
}


char *caesarDecode(char word[]){
    int i;
    for(i = 0; i < strlen(word); i++){
        word[i] = toupper(word[i]);
        word[i] = word[i] - 3;
        switch(word[i]){
            case 29:
                word[i] = word[i] + 3;
            break;
            case '>':
                word[i] = word[i] + 26;
            break;
            case '?':
                word[i] = word[i] + 26;
            break;
            case '@':
                word[i] = word[i] + 26;
            break;
        }
    }
    return word;
}


char *chooseEncrypt(char word[], int shift){
    int i;
    shift = shift % 26;
    for(i = 0; i <  strlen(word); i++){
        switch(word[i]){
            case ' ':
                word[i] = word[i] - shift;
            break;
        }
        word[i] = toupper(word[i]);
        word[i] = word[i] + shift;
        if(word[i] > 90)
            word[i] = word[i] - 26;
    }
    return word;
}


char *chooseDecrypt(char word[], int shift){
    int i;
    shift = shift % 26;
    for (i = 0; i < strlen(word); i++){
        switch(word[i]){
            case 32:
                word[i] = word[i] + shift;
            break;
        }
        word[i] = toupper(word[i]);
        word[i] = word[i] - shift;
        if(word[i] < 65 && word[i] != 32){
            word[i] = word[i] + 26;
        }
    }
    return word;
}


int main(){
    int i = 1, shift;
    char word[50];
    while(i != 0){
        printf("(1)Encrypt Caesar.\n");
        printf("(2)Decrypt Caesar.\n");
        printf("(3)Encrypt with a chosen shift.\n");
        printf("(4)Decrypt with a chosen shift.\n");
        printf("(0)Exit.\n");
        i = soNumeros();
        switch(i){
            case 1:
                system("cls");
                printf("Type some message of a maximum of 50 characters.\n");
                soLetras(word);
                strcpy(word, caesarEncode(word));
                printf("%s\n", word);
                system("pause");
            break;
            case 2:
                system("cls");
                printf("Type some message of a maximum of 50 characters.\n");
                soLetras(word);
                strcpy(word, caesarDecode(word));
                printf("%s\n", word);
                system("pause");
            break;
            case 3:
                system("cls");
                printf("Type  how many characters do you want to shift.\n");
                shift = soNumeros();
                printf("Type some message of a maximum of 50 characters.\n");
                soLetras(word);
                strcpy(word, chooseEncrypt(word, shift));
                printf("%s\n", word);
                system("pause");
            break;
            case 4:
                system("cls");
                printf("Type  how many characters do you want to shift.\n");
                shift = soNumeros();
                printf("Type some message of a maximum of 50 characters.\n");
                soLetras(word);
                strcpy(word, chooseDecrypt(word, shift));
                printf("%s\n", word);
                system("pause");
            break;
        }
        system("cls");
    }
    return 0;
}
