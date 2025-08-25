#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* plrChoices[] = {"Rock", "Paper", "Scissors"};

char *getChoice(int choiceInt, int isPlayer) {
    if (isPlayer == 1) {
        return ((choiceInt > 0 && choiceInt < 4) ? plrChoices[choiceInt-1] : "What?");
    } else if (isPlayer == 0) {
        if (choiceInt < 33) return "Rock";
        else if (choiceInt >= 33 && choiceInt < 67) return "Paper";
        else return "Scissors";
    }

    return "What?";
}   

int main() {
    printf("Simple Rock Paper Scissors game\n");

    srand(time(NULL));
    int maxNo = 100;
    int compChoiceInt = rand() % maxNo;

    printf("Rock, paper or scissors?\n");
    printf("1 => Rock\n2=> Paper\n3=> Scissors\n");

    int plrChoiceInt = 1;
    scanf("%d", &plrChoiceInt);

    char* plrChoice = getChoice(plrChoiceInt, 1);
    char* compChoice = getChoice(compChoiceInt, 0);

    printf("Your choice is: %s\n", plrChoice);
    printf("Computer Choice is: %s\n", compChoice);

    switch(plrChoiceInt) {
        // Rock
        case 1:
            {
                if (compChoice == "Paper") { printf("You lost!\n"); }
                else if (compChoice == "Rock") { printf("It's a tie.\n"); }
                else { printf("You won!"); }
                break;
            }
        // Paper
        case 2:
            {
                if (compChoice == "Paper") { printf("It's a tie.\n"); }
                else if (compChoice == "Rock") { printf("You won!"); }
                else { printf("You lost!\n"); }
                break;
            }
        // Scissors
        case 3:
            {
                if (compChoice == "Paper") { printf("You won!"); }
                else if (compChoice == "Rock") { printf("You lost!\n"); }
                else { printf("It's a tie.\n"); }
                break;
            }
        default:
            printf("No idea how you got here... actually, I do but I'll pretend I don't.\n");
            break;
    }
}
