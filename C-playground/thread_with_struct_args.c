#include <stdio.h>
#include <pthread.h>
#include<string.h>

// Structure to hold arguments
typedef struct {
    int thread_id;
    char message[50];
} ThreadArgs;

// Thread function
void *print_message(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg; // Cast void* to actual type

    printf("Thread ID: %d\n", args->thread_id);
    printf("Message: %s\n", args->message);

    return NULL;
}

int main() {
    pthread_t thread;
    ThreadArgs args;

    // Fill the structure
    args.thread_id = 1;
    strcpy(args.message,"Hello from the thread!");

    // Create thread and pass arguments
    if (pthread_create(&thread, NULL, print_message, (void *)&args) != 0) {
        printf("Error creating thread\n");
        return 1;
    }

    // Wait for thread to finish
    pthread_join(thread, NULL);

    printf("Main thread finished.\n");
    return 0;
}
