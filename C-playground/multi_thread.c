/*
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
Parameters:
pthread_t *thread:
A pointer to a pthread_t variable that will hold the ID of the newly created thread.

const pthread_attr_t *attr:
A pointer to a structure that specifies the attributes for the new thread.
Attributes include things like whether the thread is joinable or detached, stack size, etc.

void *(*start_routine) (void *):
A pointer to the function that the thread will execute once it starts.
The function must match the following signature: void *function_name(void *arg).
The argument (arg) can be used to pass data to the thread function.

void *arg:
A pointer to any data you want to pass to the thread function (can be NULL if no data is needed).

*/
#include <stdio.h>
#include <pthread.h>

// Function 1
void *function1(void *arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Function 1: %d\n", i);
    }
    return NULL;
}

// Function 2
void *function2(void *arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Function 2: %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create the first thread
    if (pthread_create(&thread1, NULL, function1, NULL) != 0) {
        printf("Error creating thread 1\n");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL, function2, NULL) != 0) {
        printf("Error creating thread 2\n");
        return 1;
    }

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have finished execution\n");
    return 0;
}
