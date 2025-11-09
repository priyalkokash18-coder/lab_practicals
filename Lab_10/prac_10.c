#include <stdio.h>
int main() {
    FILE *src, *dest;
    char sourceFile[30], destFile[30];
    char ch;
    printf("Enter source file name (e.g., input.txt): ");
    scanf("%s", sourceFile);
    printf("Enter destination file name (e.g., output.txt): ");
    scanf("%s", destFile);
    src = fopen(sourceFile, "r");
    if (src == NULL) {
        printf("Cannot open source file!\n");
        return 1;
    }
    dest = fopen(destFile, "w");
    if (dest == NULL) {
        printf("Cannot create destination file!\n");
        fclose(src);
        return 1;
    }
    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);
    printf("File copied successfully!\n");

    fclose(src);
    fclose(dest);
    return 0;
}
