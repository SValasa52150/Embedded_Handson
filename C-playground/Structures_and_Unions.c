
#include <stdio.h>
#include<string.h>
// ---------------- Global Struct Definition ----------------
struct GlobalStruct {
    int id;
    char name[20];
} globalInstance = {100, "GlobalUser"};

// ---------------- Enum Demo ----------------
enum Status { ACTIVE = 1, INACTIVE, BLOCKED };
enum Status currentStatus = ACTIVE;

// ---------------- Union Demo ----------------
union Data {
    int i;
    float f;
    char str[20];
};

// ---------------- Packed Struct ----------------
#pragma pack(push, 1) // Disable padding.... Tells the compiler to save the current packing alignment (push) And set alignment to 1 byte (i.e., no padding between members)
struct PackedStruct {
    char a;
    int b;
};
#pragma pack(pop) //restore to prev allignment

// ---------------- Normal Struct (with padding) ----------------
struct PaddedStruct {
    char a;
    int b;
};

// ---------------- Main Function ----------------
int main(void) {
    printf("----- Global Struct -----\n");
    printf("ID: %d, Name: %s\n", globalInstance.id, globalInstance.name);

    printf("\n----- Enum Example -----\n");
    printf("Current Status: %d\n", currentStatus);

    printf("\n----- Union Example -----\n");
    union Data data;
    union Data* dataPtr = &data;

    dataPtr->i = 42;
    printf("Union int: %d\n", dataPtr->i);
    dataPtr->f = 3.14f;
    printf("Union float (overwrites int): %.2f\n", dataPtr->f);
    strcpy(dataPtr->str, "UnionDemo");
    printf("Union string (overwrites float): %s\n", dataPtr->str);

    printf("\n----- Padded vs Packed Struct -----\n");
    printf("Size of PaddedStruct: %zu bytes\n", sizeof(struct PaddedStruct)); // %zu format specifier tells printf to expect a size_t value and print it in an appropriate format.
    printf("Size of PackedStruct: %zu bytes\n", sizeof(struct PackedStruct));

    printf("\n----- Pointer to Struct -----\n");
    struct GlobalStruct local = {200, "LocalUser"};
    struct GlobalStruct* ptr = &local;
    printf("Using pointer - ID: %d, Name: %s\n", ptr->id, ptr->name);

    printf("\n----- Designated Initialization -----\n");
    struct GlobalStruct designated = {.name = "Designated", .id = 300};
    printf("ID: %d, Name: %s\n", designated.id, designated.name);

    return 0;
}
