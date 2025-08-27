#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_HINT_LENGTH 100
#define MAX_TRIES 10

struct WordData {
    char Word[MAX_WORD_LENGTH];
    char Hint[MAX_HINT_LENGTH];
};

struct WordData words[] = {
    { "hello", "A greeting" },
    { "dog", "Man best friend" },
    { "human", "Our species" }
};

void displayWord(const char* word, const size_t length) {
    printf("Word: ");
    
    for (int i = 0; i < length; i++) {
        printf(word[i]);
    }
    printf("\n");
}

void drawHangman(int tries) {
    const char* hangmanParts[]
        = { "     _________",    "    |         |",
            "    |         O",   "    |        /|\\",
            "    |        / \\", "    |" };

    printf("\n");
    for (int i = 0; i <= tries; i++) {
        printf("%s\n", hangmanParts[i]);
    }
}

int main() {
    srand(time(NULL));
    
    size_t wordsArraySize = sizeof(words) / sizeof(words[0]);
    int selectedWordIndex = rand() % wordsArraySize;
    const char* word = words[selectedWordIndex].Word;
    const char* hint = words[selectedWordIndex].Hint;
    size_t wordLength = strlen(word);

    char guessedWord[MAX_WORD_LENGTH] = { 0 };
    int guessedLetters[26] = { 0 };

    int tries = 0;

    //printf("Selected Index: %d\n", selectedWordIndex);

    printf("Hanged man.\n");
    printf("Word: %s\n", word);
    printf("Hint: %s\n", hint);

    displayWord(word, wordLength);
    drawHangman(tries);
}
