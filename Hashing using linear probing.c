#include <stdio.h>

#define SIZE 10
#define EMPTY -1

int hashTable[SIZE];

// Division hash function
int hash(int key) {
    return key % SIZE;
}

// Insert with linear probing
void insert(int key) {
    if (key < 0) {
        printf("Please enter a positive number!\n");
        return;
    }
    
    int index = hash(key);
    int i = 0;
    
    // Linear probing
    while (hashTable[(index + i) % SIZE] != EMPTY) {
        if (i >= SIZE) {
            printf("Hash table is full!\n");
            return;
        }
        i++;
    }
    
    int pos = (index + i) % SIZE;
    hashTable[pos] = key;
    printf("Inserted %d at index %d\n", key, pos);
}


void display() {
	int i;
    printf("\nHash Table:\n");
    for ( i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("[%d]: EMPTY\n", i);
        else
            printf("[%d]: %d\n", i, hashTable[i]);
    }
    printf("\n");
}

int main() {
	int i;
    
    for (i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
    
    int choice, key;
    
    printf("Hash Table with Linear Probing\n\n");
    
    while (1) {
        printf("1. Insert\n2. Display\n3. Exit\n");
        printf("Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'); 
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter key: ");
                if (scanf("%d", &key) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'); 
                } else {
                    insert(key);
                }
                break;
                
            case 2:
                display();
                break;
                
            case 3:
                printf("Exiting program.\n");
                return 0;
                
            default:
                printf("Invalid choice.Please choose within option 1, 2, or 3.\n");
        }
    }
    
    return 0;
}
