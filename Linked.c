#include "linked.h"
#include <string.h>  // untuk fungsi strcpy dan strcmp

// Inisialisasi linked list kosong
void createList(LinkedList *L) {
    L->head = NULL;
}

// Membuat node baru
Node* createNode(char value[]) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        strcpy(newNode->info, value);  // untuk nyalin string nya ke field info
        newNode->next = NULL;
    }
    return newNode;
}

// Insert di awal list
void insertFirst(LinkedList *L, char value[]) {
    Node *newNode = createNode(value);
    newNode->next = L->head;
    L->head = newNode;
}

// Insert di akhir list
void insertLast(LinkedList *L, char value[]) {
    Node *newNode = createNode(value);
    if (L->head == NULL) {
        L->head = newNode;
    } else {
        Node *temp = L->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Insert setelah nilai tertentu
void insertValueAfter(LinkedList *L, char afterValue[], char value[]) {
    Node *temp = L->head;
    while (temp != NULL && strcmp(temp->info, afterValue) != 0) {
        temp = temp->next;
    }
    if (temp != NULL) {
        Node *newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Insert sebelum nilai tertentu
void insertValueBefore(LinkedList *L, char beforeValue[], char value[]) {
    Node *newNode = createNode(value);
    if (L->head == NULL || strcmp(L->head->info, beforeValue) == 0) {
        insertFirst(L, value);
        return;
    }
    Node *temp = L->head;
    while (temp->next != NULL && strcmp(temp->next->info, beforeValue) != 0) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Hapus node pertama
void deleteFirst(LinkedList *L) {
    if (L->head != NULL) {
        Node *temp = L->head;
        L->head = L->head->next;
        free(temp);
    }
}

// Hapus node terakhir
void deleteLast(LinkedList *L) {
    if (L->head == NULL) return;
    if (L->head->next == NULL) {
        free(L->head);
        L->head = NULL;
        return;
    }
    Node *temp = L->head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Hapus node dengan nilai tertentu
void deleteValue(LinkedList *L, char value[]) {
    if (L->head == NULL) return;
    if (strcmp(L->head->info, value) == 0) {
        deleteFirst(L);
        return;
    }
    Node *temp = L->head;
    while (temp->next != NULL && strcmp(temp->next->info, value) != 0) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        Node *delNode = temp->next;
        temp->next = temp->next->next;
        free(delNode);
    }
}

// Modifikasi nilai node pertama
void modifyFirst(LinkedList *L, char newValue[]) {
    if (L->head != NULL) {
        strcpy(L->head->info, newValue);
    }
}

// Modifikasi nilai node terakhir
void modifyLast(LinkedList *L, char newValue[]) {
    if (L->head != NULL) {
        Node *temp = L->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        strcpy(temp->info, newValue);
    }
}

// Modifikasi node dengan nilai tertentu
void modifyValue(LinkedList *L, char oldValue[], char newValue[]) {
    Node *temp = L->head;
    while (temp != NULL) {
        if (strcmp(temp->info, oldValue) == 0) {
            strcpy(temp->info, newValue);
            return;
        }
        temp = temp->next;
    }
}

// Cetak isi linked list
void printList(LinkedList L) {
    Node *temp = L.head;
    while (temp != NULL) {
        printf("%s -> ", temp->info);  
        temp = temp->next;
    }
    printf("NULL\n");
}
