#include <stdio.h>
#include <stdlib.h>

// Definition of a node (self-referential structure)
struct Node {
    int data;
    struct Node *next;
};

// Function to count the number of elements in the list
int count_elements(struct Node *head) {
    int count = 0;
    struct Node *ptr = head;

    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    printf("Total number of elements in the list: %d\n", count);
    return count;
}

// Function to traverse and print the elements of the list
void traverse_list(struct Node *head) {
    struct Node *ptr = head;

    if (ptr == NULL) 
	{
        printf("The list is empty.\n");
        return;
    }

    printf("Traversing the list:\n");
    while (ptr != NULL) 
	{
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to insert an element at the end of the list
void insert_at_end(struct Node *head, int data)
{
    struct Node *ptr = head;
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    
    new_node->data = data;
    new_node->next = NULL;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = new_node;
}

// Function to insert an element at the beginning of the list
struct Node *insert_at_start(struct Node *head, int data) 
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    
    new_node->data = data;
    new_node->next = head;

    //*******88Since head is passed by value, we return the new head to reflect the change***************
    return new_node;
}

int main() {
    // Creating the first node (head)
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 833;
    head->next = NULL;
    printf("Created head node with data: %d\n", head->data);

    // Manually adding more nodes
    struct Node *current = (struct Node *)malloc(sizeof(struct Node));
    current->data = 844;
    current->next = NULL;
    head->next = current;

    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = 855;
    current->next = NULL;
    head->next->next = current;

    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = 866;
    current->next = NULL;
    head->next->next->next = current;

    // Count and traverse before insertion
    count_elements(head);
    traverse_list(head);

    // Insert element at the end
    insert_at_end(head, 877);
    printf("After insertion at the end:\n");
    traverse_list(head);

    // Insert element at the beginning
    head = insert_at_start(head, 888); // Important: head is updated to new node
    printf("\nAfter insertion at the beginning:\n");
    traverse_list(head);

    return 0;
}
