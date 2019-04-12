/* Takes a .tsv file, displays it as a table.
 * Wed Mar 20 22:28:06 CDT 2019
 *
 * issues: won't format correctly if you use non-ascii characters or if your
 * file contains carriage returns.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define TOP_LEFT "."
// #define TOP_RIGHT ","
// #define BOTTOM_LEFT "\'"
// #define BOTTOM_RIGHT "\'"
// #define HOR "-"
// #define VER "|"

#define TOP_LEFT "┌"
#define TOP_RIGHT "┐"
#define BOTTOM_LEFT "└"
#define BOTTOM_RIGHT "┘"
#define HOR "─"
#define VER "│"








// Returns length of a str, including punctuation attached to it.
unsigned strlenpunc(char *str){
    if(str[0] == '\0')
        return 0;
    unsigned i = 0;
    while(str[i++] != '\0');
    return (i - 1);
}

int main(int argc, char **argv){
    FILE *fp;
    unsigned sz, i, j, rows, cols;
    char ch, *str, ***array;

    // If user didn't call with file name, explain usage.
    if(argc != 2){
        printf("USAGE: %s <filename.tsv>\n", argv[0]);
        exit(0);
    }

    // Open file.
    if((fp = fopen(argv[1], "r")) == NULL){ puts("can't open file."); exit(1); }

    // Count characters in file. If empty file, exit.
    sz = 0;
    while((ch = fgetc(fp)) != EOF) sz++;
    if(sz == 0) { puts("empty file."); exit(1); }

    // rewind file.
    rewind(fp);

    // Malloc buffer for the file. Exit on fail.
    if((str = malloc(sz + 1)) == NULL){ puts("malloc fail"); exit(1); }

    // Read file into buffer, close file.
    fread(str, 1, sz, fp);
    fclose(fp);

    // null-terminate file content.
    str[sz] = '\0';

    // count columns by counting tabs on first line.
    for(i = cols = 0; str[i] != '\n'; i++){
        if(str[i] == '\t') cols++;
    }
    cols++;

    // count rows by counting newlines. Assume every line ends with a newline.
    for(i = rows = 0; str[i]; i++){
        if(str[i] == '\n')
            rows++;
    }

    // build a 2d array to hold strings.
    if((array = malloc(rows * sizeof(char **))) == NULL) { puts("malloc fail"); exit(1); }
    for(i = 0; i < rows; i++){
        if((array[i] = malloc(cols * sizeof(char *))) == NULL) { puts("malloc fail"); exit(1); }
    }

    // Put the strings into the array, mallocing space for each string along the way.
    unsigned str_index = 0;
    unsigned wordscout = 0;
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){

            // Find the end of the next word.
            while(str[wordscout] && str[wordscout] != '\t' && str[wordscout] != '\n')
                wordscout++;

            // Now I know the word length. Malloc space for it.
            if((array[i][j] = malloc((1 + wordscout - str_index) * sizeof(char))) == NULL){ puts("malloc fail"); exit(1); }

            // Copy the word into the new space.
            unsigned cell_index = 0;
            while(str_index < wordscout) {
                    array[i][j][cell_index] = str[str_index];
                    cell_index++;
                    str_index++;
            }

            // Terminate the string in the cell.
            array[i][j][cell_index] = '\0';

            // Move indexes to the beginning of the next word.
            wordscout++;
            str_index++;
        }
    }

    free(str);

    // Find the largest width for each column.
    unsigned *col_width = malloc(cols * sizeof(unsigned));
    for(i = 0; i < cols; i++){
        unsigned largest = 0;
        for(j = 0; j < rows; j++){
            unsigned len = strlenpunc(array[j][i]);
            if(len > largest)
                largest = len;
        }
        col_width[i] = largest;
    }

    // calculate table width.
    unsigned table_width = 0;
    for(i = 0; i < cols; i++)
        table_width += col_width[i];
    table_width += 3 * cols + 1;

    // draw top of table.
    printf("\n%s", TOP_LEFT);
    for(i = 0; i < table_width - 2; i++)
        printf(HOR);
    printf("%s\n", TOP_RIGHT);

    // display table.
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("%s %s", VER, array[i][j]);
            unsigned pad = col_width[j] - strlenpunc(array[i][j]) + 1;

            for(unsigned k = 0; k < pad; k++){
                putchar(' ');
            }
        }
        puts(VER);

        // if last row, print bottom line underneath.
        if(i == rows - 1){
            printf(BOTTOM_LEFT);
            for(j = 0; j < table_width - 2; j++){
                printf(HOR);
            }
            printf(BOTTOM_RIGHT);
        }

        // if not last row, print line between rows.
        else{
            printf(VER);
            for(j = 0; j < table_width - 2; j++){
                printf(HOR);
            }
            puts(VER);
        }
    }
    putchar('\n');
}
