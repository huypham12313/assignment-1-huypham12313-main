#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void insertNode(struct Node** p_head, struct Node* position, int data) 
{
    // your implementation
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (*p_head == NULL) {
        *p_head = new_node;
        new_node->next = NULL;
    } else if (position == NULL) {
        struct Node* temp = *p_head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    } else {
        new_node->next = position->next;
        position->next = new_node;
    }
}

void pushBack(struct Node** p_head, int data)
{
    // your implementation
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*p_head == NULL) {
        *p_head = new_node;
    } else {
        struct Node* temp = *p_head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

}

void deleteNode(struct Node** p_head, struct Node* position) 
{
    // your implementation
    if (*p_head == NULL || position == NULL) {
        return;
    }

    struct Node* temp;

    if (*p_head == position) {
        temp = *p_head;
        *p_head = (*p_head)->next;
        free(temp);
        return;
    }

    struct Node* current = *p_head;
    while (temp->next != NULL && temp->next != position) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        return;
    }

    temp = temp->next;
    temp->next = temp->next->next;
    free(temp);
}

void deleteList(struct Node **p_head)
{
    // your implementation
    struct Node* temp = *p_head;
    struct Node* next;

    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }

    *p_head = NULL;
}

int sizeOfList (struct Node* head) {
    // your implementation
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// display the linked list to a string output
void displayListToString(struct Node* head, char* output) {
    sprintf(output, "%s", "");
    struct Node* temp = head;
    while (temp != NULL) {
        char temp_str[100];
        sprintf(temp_str, "%d -> ", temp->data);
        strcat(output, temp_str);
        temp = temp->next;
    }
    // concatenate NULL to the output string
    sprintf(output, "%sNULL", output);
}