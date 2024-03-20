#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


struct ThreeAddressCode {
    char result[20];
    char op;
    char arg1[20];
    char arg2[20];
};


void generateThreeAddressCode(char *expression) {
    struct ThreeAddressCode code[50]; 
    int codeIndex = 0;
    char tempResult[20];
    int tempIndex = 0;

    
    for (int i = 0; expression[i] != '\0'; i++) {
        
        if (expression[i] == ' ') {
            continue;
        }
        
        else if (isalpha(expression[i])) {
            tempResult[tempIndex++] = expression[i];
        }
        
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            tempResult[tempIndex] = '\0'; 
            strcpy(code[codeIndex].result, tempResult);
            code[codeIndex].op = expression[i];
            code[codeIndex].arg1[0] = '\0'; 
            code[codeIndex].arg2[0] = '\0'; 
            tempIndex = 0;
            codeIndex++;
        }
        
        else if (expression[i] == '(' || expression[i] == ')') {
            continue;
        }
    }

   
    if (tempIndex > 0) {
        tempResult[tempIndex] = '\0'; 
        strcpy(code[codeIndex].result, tempResult);
        code[codeIndex].op = '\0'; 
        code[codeIndex].arg1[0] = '\0'; 
        code[codeIndex].arg2[0] = '\0';
        codeIndex++;
    }

   
    printf("Three-address code representation:\n");
    for (int i = 0; i < codeIndex; i++) {
        if (code[i].op != '\0') {
            printf("%s = %s %c %s\n", code[i].result, code[i].arg1, code[i].op, code[i].arg2);
        } else {
            printf("%s\n", code[i].result);
        }
    }
}

int main() {
    char expression[100];
    printf("Enter the arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);
    
    
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    generateThreeAddressCode(expression);

    return 0;
}
