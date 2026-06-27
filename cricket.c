#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int toss, num, choice;
    int userScore = 0, botScore = 0;
    int userBall, botBall;

    srand(time(0));

    printf("=====================================\n");
    printf("     WELCOME TO HAND CRICKET!\n");
    printf("=====================================\n");

    printf("Enter 1 for Heads and 2 for Tails: ");
    scanf("%d", &toss);

    printf("\nThe coin is in the air...\n");

    num = (rand() % 2) + 1;

    if(num == 1)
        printf("It's HEADS!\n");
    else
        printf("It's TAILS!\n");

    int userWinsToss = (toss == num);

    if (userWinsToss) {
        printf("You won the toss!\n");
        printf("Enter 3 for Batting and 4 for Bowling: ");
        scanf("%d", &choice);

        if(choice == 3)
            printf("You chose to BAT first.\n");
        else
            printf("You chose to BOWL first.\n");

    } else {
        printf("You lost the toss!\n");
        choice = (rand() % 5) + 6;

        if (choice==5)
        {
            printf("Bot chose batting.\n");
        }
        else
        {
            printf("Bot chose bowling.\n");
        }
    }

    /* ================= FIRST INNINGS ================= */

    if (choice == 3) {

        printf("\n=====================================\n");
        printf("        FIRST INNINGS STARTS\n");
        printf("=====================================\n");

        printf("\n--- You are Batting ---\n");

        while (1) {

            botBall = rand() % 7;

            printf("\nCrowd is cheering...\n");
            printf("Enter your shot (0-6): ");
            scanf("%d", &userBall);

            if (userBall < 0 || userBall > 6) {
                printf("Invalid shot! Play between 0 and 6.\n");
                continue;
            }

            printf("Bot bowled: %d\n", botBall);

            if (userBall == botBall) {
                printf("OH NOOO! Clean bowled!\n");
                printf("Your innings ends at %d runs.\n", userScore);
                break;
            }

            if(userBall == 0)
                printf("Dot ball.\n");
            else if(userBall == 4)
                printf("FOUR! Beautiful shot!\n");
            else if(userBall == 6)
                printf("SIX!!! Massive hit into the crowd!\n");
            else
                printf("Good running between the wickets.\n");

            userScore += userBall;

            printf("Current Score: %d\n", userScore);
        }

        printf("\nTarget for Bot: %d\n", userScore + 1);

        printf("\n=====================================\n");
        printf("        SECOND INNINGS STARTS\n");
        printf("=====================================\n");

        printf("\n--- Bot is Batting ---\n");

        while (1) {

            botBall = rand() % 7;

            printf("\nGet ready to bowl...\n");
            printf("Enter your bowl (0-6): ");
            scanf("%d", &userBall);

            if (userBall < 0 || userBall > 6) {
                printf("Invalid bowl! Bowl between 0 and 6.\n");
                continue;
            }

            printf("Bot played: %d\n", botBall);

            if (userBall == botBall) {
                printf("WICKETTTT! You got the bot out!\n");
                break;
            }

            if(botBall == 0)
                printf("Dot ball. Excellent bowling!\n");
            else if(botBall == 4)
                printf("Bot smashes a FOUR!\n");
            else if(botBall == 6)
                printf("That's a gigantic SIX from the bot!\n");
            else
                printf("Bot takes quick runs.\n");

            botScore += botBall;

            printf("Bot Score: %d\n", botScore);

            if(botScore > userScore) {
                printf("Bot has chased the target!\n");
                break;
            }
        }

    } else {

        printf("\n=====================================\n");
        printf("        FIRST INNINGS STARTS\n");
        printf("=====================================\n");

        printf("\n--- Bot is Batting ---\n");

        while (1) {

            botBall = rand() % 7;

            printf("\nBowl carefully...\n");
            printf("Enter your bowl (0-6): ");
            scanf("%d", &userBall);

            if (userBall < 0 || userBall > 6) {
                printf("Invalid bowl! Bowl between 0 and 6.\n");
                continue;
            }

            printf("Bot played: %d\n", botBall);

            if (userBall == botBall) {
                printf("What a delivery! BOT OUT!\n");
                printf("Bot innings ends at %d runs.\n", botScore);
                break;
            }

            if(botBall == 0)
                printf("Dot ball.\n");
            else if(botBall == 4)
                printf("Bot hits a classy FOUR!\n");
            else if(botBall == 6)
                printf("Huge SIX from the bot!\n");
            else
                printf("Bot rotates the strike.\n");

            botScore += botBall;

            printf("Bot Score: %d\n", botScore);
        }

        printf("\nYour target: %d\n", botScore + 1);

        printf("\n=====================================\n");
        printf("        SECOND INNINGS STARTS\n");
        printf("=====================================\n");

        printf("\n--- You are Batting ---\n");

        while (1) {

            botBall = rand() % 7;

            printf("\nThe field is set...\n");
            printf("Enter your shot (0-6): ");
            scanf("%d", &userBall);

            if (userBall < 0 || userBall > 6) {
                printf("Invalid shot! Play between 0 and 6.\n");
                continue;
            }

            printf("Bot bowled: %d\n", botBall);

            if (userBall == botBall) {
                printf("OUT! That's heartbreaking!\n");
                break;
            }

            if(userBall == 0)
                printf("Dot ball.\n");
            else if(userBall == 4)
                printf("FOUR! Timed perfectly!\n");
            else if(userBall == 6)
                printf("SIX!!! What a strike!\n");
            else
                printf("Nicely played for %d runs.\n", userBall);

            userScore += userBall;

            printf("Current Score: %d\n", userScore);

            if(userScore > botScore) {
                printf("You have chased the target successfully!\n");
                break;
            }
        }
    }

    /* ================= RESULT ================= */

    printf("\n=====================================\n");
    printf("            MATCH RESULT\n");
    printf("=====================================\n");

    printf("FINAL SCORE:\n");
    printf("You: %d\n", userScore);
    printf("Bot: %d\n", botScore);

    if (userScore > botScore)
        printf("\nCongratulations! YOU WIN THE MATCH!\n");
    else if (userScore < botScore)
        printf("\nBot Wins the Match! Better luck next time.\n");
    else
        printf("\nWhat a game! MATCH TIED!\n");

    printf("\nThanks for playing Hand Cricket!\n");

    return 0;
}