#include <conio.h>
#include <stdio.h>
#include <string.h>
  
// Driver Code
int main()
{
    // Substitute the full file path
    // for the string file_path
    FILE* fp = fopen("arquivo.txt", "r");
  
    if (!fp)
        printf("Can't open file\n");
  
    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;
  
        while (fgets(buffer,1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, "%d\n");
  
            while (value) {
                // Column 1
                if (column == 0) {
                    printf("Rating:");
                }
  
                // Column 2
                if (column == 1) {
                    printf("Review:");
                }
  
                printf("%s", value);
                value = strtok(NULL, "%d\n");
                column++;
            }
  
            printf("\n");
        }
  
        // Close the file
        fclose(fp);
    }
    return 0;
}