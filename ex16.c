/*Elabore uma função em C que devolva a dimensão da menor palavra encontrada numa string passada
como argumento.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INT_MAX __INT_MAX__

int shortest_word(const char *str) {
    int shortest_length = INT_MAX; // Initialize with the largest possible value
    int current_word = 0;
    char input[]
    fgets()
    // Iterate through the string
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if it's an alphanumeric character
        if (isalnum(str[i])) {
            current_word++;
        } else if (current_word > 0) {
            // Update the shortest length if necessary
            shortest_length = (current_word < shortest_length) ? current_word : shortest_length;
            current_word = 0; // Reset the current word count
        }
    }

    // Check the last word
    if (current_word > 0) {
        shortest_length = (current_word < shortest_length) ? current_word : shortest_length;
    }

    return (shortest_length == INT_MAX) ? 0 : shortest_length; // Return 0 if no words are found
}

int main() {
    const char *str = "This is a test string";
    printf("Shortest word has length: %d\n", shortest_word(str));
    return 0;
}