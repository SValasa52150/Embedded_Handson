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
