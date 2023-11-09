#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int directory_viewer(int input) {
    char path[100]; // Assuming the path won't be longer than 100 characters
    struct dirent *entry;
    DIR *dp;

    while (1) {
        if(input == 1)
        {
            chdir("/data/data/com.kvassyu.coding2.c/files/home");
            input = 0;
        }
        
        dp = opendir(".");
        printf("\n\nContents of current directory:\n\n");

        if (dp == NULL) {
            perror("\nopendir");
            return 1;
        }

        while ((entry = readdir(dp)) != NULL) {
            printf("%s\n", entry->d_name);
        }
        closedir(dp);

        printf("\nCurrent Directory: %s\n", getcwd(path, sizeof(path)));
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
