#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/storage/emulated/0/Download/CodingC/directory_viewer.h"

// Function to create a new file
void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("\ncreateFile");
        return;
    }
    fclose(file);
    printf("\nFile '%s' created successfully.\n\n", filename);
}

// Function to delete a file
void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("\nFile '%s' deleted successfully.\n\n", filename);
    } else {
        perror("\ndeleteFile");
    }
}

// Function to move a file
void moveFile(const char *src, const char *dest) {
    if (rename(src, dest) == 0) {
        printf("\nFile '%s' moved to '%s' successfully.\n\n", src, dest);
    } else {
        perror("\nmoveFile");
    }
}

// Function to copy a file
void copyFile(const char *src, const char *dest) {
    FILE *sourceFile = fopen(src, "rb");
    FILE *destinationFile = fopen(dest, "wb");
    if (sourceFile == NULL || destinationFile == NULL) {
        perror("\ncopyFile");
        return;
    }

    int ch;
    while ((ch = fgetc(sourceFile) ) != EOF) {
        fputc(ch, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);
    printf("\nFile '%s' copied to '%s' successfully.\n\n", src, dest);
}

int main() {
    while (1) {
        int choice;
        char filename[100];
        char destination[100];

        printf("\n\nFile Operations Menu:\n\n");
        printf("1. Create a new file\n");
        printf("2. Delete a file\n");
        printf("3. Move a file\n");
        printf("4. Copy a file\n");
        printf("5. Directory Viewer\n");
        printf("6. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 6) {
            break;
        }

        if (choice != 5) {
            printf("\nEnter filename: ");
            scanf("%s", filename);
        }

        if (choice >= 1 && choice <= 5) {
            if (choice == 1) {
                createFile(filename);
            } else if (choice == 2) {
                deleteFile(filename);
            } else if (choice == 3) {
                printf("\nEnter destination: ");
                scanf("%s", destination);
                moveFile(filename, destination);
            } else if (choice == 4) {
                printf("\nEnter destination: ");
                scanf("%s", destination);
                copyFile(filename, destination);
            } else if (choice == 5) {
                directory_viewer(1);
            }
        } else {
            printf("\nInvalid choice. Please enter a valid option.\n\n");
        }
    }

    return 0;
}
