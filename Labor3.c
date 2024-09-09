#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10007  

int hashTable[ARRAY_SIZE];

void initializeHashTable() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        hashTable[i] = -1; 
    }
}

int hash(int key) {
    return key % ARRAY_SIZE;
}

void insert(int key) {
    int index = hash(key);
    int start_index = index;

    while (hashTable[index] != -1) {
        printf("Einfuegen von Wert %d an Position %d ....Kollision: neue Position ", key, index);
        index = hash(index+1);
        if (index == start_index) 
        {  
            printf("Tabelle voll.\n");
            return;
        }
        printf("%d....\n", index);
    }
    hashTable[index] = key;
}

void search(int key) {
    int index = hash(key);
    int start_index = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("Wert %d gefunden an Position %d!\n", key, index);
            return;
        }
        else{
            printf("anderer Wert  \n");
            index = hash(index+1);
        }
    }
    printf("Wert %d nicht gefunden.\n", key);
}

int main() {
    initializeHashTable();

    for (int i = 0; i < 5000; i++) {
        insert(rand() % 10000); 
    }

    int value;
    while (1) {
        printf("Welcher Wert soll gesucht werden? (Mit 0 abbrechen): ");
        scanf("%d", &value);
        if (value == 0) break;
        search(value);
    }

    return 0;
}
