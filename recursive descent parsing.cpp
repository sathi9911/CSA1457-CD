#include<stdio.h>
#include<string.h>

char input[100];
int i = 0, l;

// Function prototypes
int E();
int EP();
int T();
int TP();
int F();

int main() {
    printf("\nRecursive descent parsing for the following grammar:\n");
    printf("\nE -> TE'\nE' -> +TE'/@\nT -> FT'\nT' -> *FT'/@\nF -> (E)/ID\n");
    printf("\nEnter the string to be checked: ");
    gets(input);
    l = strlen(input);
    
    if (E() && i == l) {
        printf("\nString is accepted\n");
    } else {
        printf("\nString is not accepted\n");
    }

    return 0;
}

int E() {
    if (T()) {
        if (EP())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int EP() {
    if (input[i] == '+') {
        i++;
        if (T()) {
            if (EP())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else
        return 1; // Epsilon transition
}

int T() {
    if (F()) {
        if (TP())
            return 1;
        else
            return 0;
    } else
        return 0;
}

int TP() {
    if (input[i] == '*') {
        i++;
        if (F()) {
            if (TP())
                return 1;
            else
                return 0;
        } else
            return 0;
    } else
        return 1; // Epsilon transition
}

int F() {
    if (input[i] == '(') {
        i++;
        if (E()) {
            if (input[i] == ')') {
                i++;
                return 1;
            } else
                return 0;
        } else
            return 0;
    } else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
        i++;
        return 1;
    } else
        return 0;
}

