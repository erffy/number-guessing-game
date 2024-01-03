#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void setColor(const char *color)
{
  printf("%s", color);
}

int main()
{
  int playAgain = 1;
  while (playAgain)
  {
    int number, guess, attempts = 0, maxRange = 100, difficulty;
    srand(time(0)); // Seed for random number generation

    printf("Welcome to the Number Guessing Game!\n");
    printf("Choose difficulty level:\n");
    printf("1. Easy (Numbers between 1 and 50)\n");
    printf("2. Medium (Numbers between 1 and 100)\n");
    printf("3. Hard (Numbers between 1 and 200)\n");
    printf("Enter your choice: ");
    scanf("%d", &difficulty);

    switch (difficulty)
    {
    case 1:
      maxRange = 50;
      break;
    case 2:
      maxRange = 100;
      break;
    case 3:
      maxRange = 200;
      break;
    default:
      printf("Invalid choice. Setting to Medium difficulty.\n");
    }

    number = rand() % maxRange + 1;
    int maxAttempts = maxRange == 50 ? 10 : (maxRange == 100 ? 7 : 5);

    printf("I'm thinking of a number between 1 and %d. Can you guess it in %d attempts?\n", maxRange, maxAttempts);

    while (attempts < maxAttempts)
    {
      printf("Attempts left: %d\n", maxAttempts - attempts);
      printf("Enter your guess: ");
      scanf("%d", &guess);
      attempts++;

      if (guess > number)
      {
        setColor(ANSI_COLOR_RED);
        printf("Too high! Try a lower number.\n");
        setColor(ANSI_COLOR_RESET);
      }
      else if (guess < number)
      {
        setColor(ANSI_COLOR_BLUE);
        printf("Too low! Try a higher number.\n");
        setColor(ANSI_COLOR_RESET);
      }
      else
      {
        setColor(ANSI_COLOR_GREEN);
        printf("Congratulations! You guessed the number in %d attempts!\n", attempts);
        setColor(ANSI_COLOR_RESET);
        break;
      }

      if (attempts == maxAttempts)
      {
        setColor(ANSI_COLOR_YELLOW);
        printf("Out of attempts! The number was %d. Game over!\n", number);
        setColor(ANSI_COLOR_RESET);
      }
      else if (attempts == maxAttempts / 2)
      {
        setColor(ANSI_COLOR_CYAN);
        printf("Hint: The number is between %d and %d.\n", number - 10, number + 10);
        setColor(ANSI_COLOR_RESET);
      }
    }

    printf("Do you want to play again? (1 for Yes, 0 for No): ");
    scanf("%d", &playAgain);
  }

  return 0;
}