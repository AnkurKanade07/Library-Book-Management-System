#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int available;
    struct Book* next;
};

struct Book* head = NULL;

void addBook(int id, char title[], char author[], int available) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->available = available;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        struct Book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
    printf("Book added successfully!\n");
}

void deleteBook(int id) {
    struct Book* temp = head;
    struct Book* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book not found!\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Book deleted successfully!\n");
}

void searchBook(int id) {
    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Book Found: ID=%d, Title=%s, Author=%s, Available=%s\n",
                   temp->id, temp->title, temp->author,
                   temp->available ? "Yes" : "No");
            return;
        }
        temp = temp->next;
    }
    printf("Book not found!\n");
}

void displayBooks() {
    struct Book* temp = head;
    if (temp == NULL) {
        printf("No books in the library.\n");
        return;
    }
    printf("\n--- Library Books ---\n");
    while (temp != NULL) {
        printf("ID=%d | Title=%s | Author=%s | Available=%s\n",
               temp->id, temp->title, temp->author,
               temp->available ? "Yes" : "No");
        temp = temp->next;
    }
}

int main() {
    int choice, id, available;
    char title[50], author[50];

    while (1) {
        printf("\n--- Library Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Display Books\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                printf("Enter Title: ");
                scanf(" %[^\n]", title);
                printf("Enter Author: ");
                scanf(" %[^\n]", author);
                printf("Available (1=Yes, 0=No): ");
                scanf("%d", &available);
                addBook(id, title, author, available);
                break;
            case 2:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;
            case 3:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                searchBook(id);
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
