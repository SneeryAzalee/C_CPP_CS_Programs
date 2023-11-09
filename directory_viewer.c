#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() {
    char path[100]; // Assuming the path won't be longer than 100 characters
    struct dirent *entry;
    DIR *dp;

    while (1) {
        printf("\n\nCurrent Directory: %s\n", getcwd(path, sizeof(path)));
        printf("\nContents of current directory:\n\n");

        dp = opendir(".");
        if (dp == NULL) {
            perror("\nopendir");
            return 1;
        }

        while ((entry = readdir(dp)) != NULL) {
            printf("%s\n", entry->d_name);
        }
        closedir(dp);

        printf("\nEnter a directory name to change to (or 'q' to quit): ");
        scanf("%s", path);

        if (strcmp(path, "q") == 0) {
            break;
        } else if (chdir(path) != 0) {
            perror("\nchdir");
        }
    }

    return 0;
}
