#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct SymbolTableEntry {
    char identifier[256];
    char type[256];
    struct SymbolTableEntry *next;
} SymbolTableEntry;
SymbolTableEntry* createEntry(char* identifier, char* type) {
    SymbolTableEntry* newEntry = (SymbolTableEntry*) malloc(sizeof(SymbolTableEntry));
    if(newEntry == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newEntry->identifier, identifier);
    strcpy(newEntry->type, type);
    newEntry->next = NULL;
    return newEntry;
}
void insert(SymbolTableEntry** headRef, char* identifier, char* type) {
    SymbolTableEntry* newEntry = createEntry(identifier, type);
    newEntry->next = *headRef;
    *headRef = newEntry;
}
SymbolTableEntry* lookup(SymbolTableEntry* head, char* identifier) {
    SymbolTableEntry* current = head;
    while (current != NULL) {
        if (strcmp(current->identifier, identifier) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
void display(SymbolTableEntry* head) {
    SymbolTableEntry* current = head;
    printf("Symbol Table:\n");
    while (current != NULL) {
        printf("Identifier: %s, Type: %s\n", current->identifier, current->type);
        current = current->next;
    }
}
int main() {
    SymbolTableEntry* symbolTable = NULL;

    insert(&symbolTable, "x", "int");
    insert(&symbolTable, "y", "float");
    insert(&symbolTable, "func", "function");

    display(symbolTable);

    char* searchFor = "y";
    SymbolTableEntry* found = lookup(symbolTable, searchFor);
    if(found != NULL) {
        printf("\nFound %s in symbol table with type %s\n", searchFor, found->type);
    } else {
        printf("\n%s not found in symbol table\n", searchFor);
    }

    return 0;
}

