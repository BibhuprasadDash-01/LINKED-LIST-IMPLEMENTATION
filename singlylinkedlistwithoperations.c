#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning.\n", value);
}

// Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at end.\n", value);
}

// Delete a node by value
void deleteNode(int value) {
    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printf("Deleted %d from list.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from list.\n", value);
}

// Display the linked list
void displayList() {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search for a value
void search(int value) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value %d not found in the list.\n", value);
}

// Main function
int main() {
    int choice, value;

    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display List\n");
        printf("5. Search Value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                displayList();
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
