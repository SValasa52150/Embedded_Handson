#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch;
    char str[50];
    int number = 100;

    // ---------- Writing to a file ----------
    fp = fopen("sample.txt", "w");
    if (fp == NULL) 
	{
        perror("Unable to open file");
        return 1;
    }

    // fputc - write single character
    fputc('A', fp);

    // fputs - write string
    fputs("\nHello, world!", fp);

    // fprintf - formatted write
    fprintf(fp, "\nNumber: %d", number);

    fclose(fp);

    // ---------- Reading from the file ----------
    fp = fopen("sample.txt", "r");
    if (fp == NULL) 
	{
        perror("Unable to open file");
        return 1;
    }

    printf("Reading using fgetc:\n");
    while ((ch = fgetc(fp)) != EOF) 
	{
        putchar(ch);
    }

    rewind(fp); // reset file pointer

    printf("\n\nReading using fgets:\n");
    fgets(str, sizeof(str), fp);
    printf("%s\n", str);

    // Skip to number line and read using fscanf
    fgets(str, sizeof(str), fp); // skip 2nd line
    int value;
    fscanf(fp, "Number: %d", &value);
    printf("\nReading using fscanf:\nNumber = %d\n", value);

    fclose(fp);

    // ---------- Binary write and read ----------
    int data = 12345;
    int read_value;

    fp = fopen("binary.bin", "wb");
    fwrite(&data, sizeof(int), 1, fp);
    fclose(fp);

    fp = fopen("binary.bin", "rb");
    fread(&read_value, sizeof(int), 1, fp);
    fclose(fp);

    printf("\nBinary value read using fread: %d\n", read_value);

    return 0;
}
