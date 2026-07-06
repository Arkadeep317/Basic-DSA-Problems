#include <stdio.h>

#define MAX 100

int arr[MAX];
int n = 0;  


void insertAtBeginning(int val);
void insertAtEnd(int val);
void insertAtPosition(int pos, int val);
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromPosition(int pos);
void replaceElement(int pos, int val);
void searchElement(int val);
void displayArray();

int main() {
    int choice, val, pos;

    printf("Enter number of initial elements: ");
    scanf("%d", &n);

    if(n > MAX) {
        printf("Too many elements!!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    	for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Replace element at position\n");
        printf("8. Search element\n");
        printf("9. Display array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 3:
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtPosition(pos, val);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position (0 to %d): ", n-1);
                scanf("%d", &pos);
                deleteFromPosition(pos);    
                break;
            case 7:
                printf("Enter position (0 to %d): ", n-1);
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &val);
                replaceElement(pos, val);

                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &val);
                searchElement(val);
                break;
            case 9:

                displayArray();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    while(choice != 0);

    return 0;
}

void insertAtBeginning(int val) {
    if (n >= MAX) {
        printf("Array full!\n");
        return;
    }
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = val;
    n++;
}

void insertAtEnd(int val) {
    if (n >= MAX) {
        printf("Array full!\n");
        return;
    }
    arr[n] = val;
    n++;
}

void insertAtPosition(int pos, int val) {
    if (n >= MAX || pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
}

void deleteFromBeginning() {
    if (n == 0) {
        printf("Array empty!\n");
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void deleteFromEnd() {
    if (n == 0) {
        printf("Array empty!\n");
        return;
    }
    n--;
}

void deleteFromPosition(int pos) {
    if (n == 0 || pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void replaceElement(int pos, int val) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }
    arr[pos] = val;
}

void searchElement(int val) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Element not found.\n");
}

void displayArray() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
