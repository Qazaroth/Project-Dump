#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

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

void displayWord(const char* word, const bool guessed[]) {
    printf("Word: ");
    
    for (int i = 0; word[i] != '\0'; i++) {
        if (guessed[word[i] - 'a']) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
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
    bool guessedLetters[26] = { false };

    int tries = 0;

    while (tries < MAX_TRIES) {
        printf("\n");
        displayWord(guessedWord, guessedLetters);
        drawHangman(tries);

        char guess;
        printf("Enter a letter: ");
        scanf("%c", &guess);
        guess = tolower(guess);

        if (guessedLetters[guess - 'a']) {
            printf("\nYou've already guessed that letter. \nTry again.\n");
            continue;
        }

        guessedLetters[guess - 'a'] = true;

        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                found = 1;
                guessedWord[i] = guess;
            }
        }

        if (found) {
            printf("Good guess!\n");
        } else {
            printf("Sorry, letter %c is not in the word.\n", guess);
            tries++;
        }

        if (strcmp(word, guessedWord) == 0) {
            printf("\nCongratulations. You've guessed the word: %s", word);
            break;
        }
    }

    if (tries >= MAX_TRIES) {
        printf("Sorry, you've run out of tries. The word was: %s\n", word);
    }
}
