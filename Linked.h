#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // untuk fungsi strcpy dan strcmp

// Struktur Node
typedef struct Node {
    char info[50];  // untuk nyimpen nama kota 
    struct Node *next; // pointer ke node berikutnya di linked list
} Node;

// Struktur Linked List
typedef struct {
    Node *head;   // pointer untuk ke node pertama (head)
} LinkedList;

// Prototipe fungsi
void createList(LinkedList *L);
Node* createNode(char value[]);
void insertFirst(LinkedList *L, char value[]);
void insertLast(LinkedList *L, char value[]);
void insertBetweenBefore(LinkedList *L, char beforeValue[], char value[]);
void insertBetweenAfter(LinkedList *L, char afterValue[], char value[]);
void insertValueBefore(LinkedList *L, char beforeValue[], char value[]);
void insertValueAfter(LinkedList *L, char afterValue[], char value[]);
void deleteFirst(LinkedList *L);
void deleteLast(LinkedList *L);
void deleteValue(LinkedList *L, char value[]);
void modifyFirst(LinkedList *L, char newValue[]);
void modifyLast(LinkedList *L, char newValue[]);
void modifyValue(LinkedList *L, char oldValue[], char newValue[]);
void modifyBetweenBefore(LinkedList *L, char beforeValue[], char newValue[]);
void modifyBetweenAfter(LinkedList *L, char afterValue[], char newValue[]);
void printList(LinkedList L);

#endif
