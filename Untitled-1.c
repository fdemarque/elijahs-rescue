#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

struct Character {
    char name[50];
    int sanity;
    int will;
    int knoledge;
    int keys;
};

struct Rooms {
    char description[100];
};

struct game {
    struct Character mainChar;
    struct Rooms room[12];
    int thisPhase;
};

void runGame(struct game *game) {
    printf("Welcome, Elijah!\n");

    strcpy(game->mainChar.name, "Elijah");
    game->mainChar.sanity = 100;
    game->mainChar.will = 10;
    game->mainChar.knoledge = 5;
    game->mainChar.keys = 0;
    game->thisPhase = 1;

    printf("My name is Crowley...\n");
    printf("I offer you an opportunity, like never seen before...\n");
    printf("Let's not talk about the tragedy, or the past, but your future.\n");
    printf("Oh, yes! You can earn a future, if you succeed\n");
    printf("This is your rescue, your chance to become stronger than ever, fulfilled and renewed\n");
    printf("Be brave and smart as I know you are, do not surrender, do not give up.\n");
    printf("Good luck at the challenges ahead\n");
    printf("...\n");
}

void play(struct game *game) {
//----------------------------------------------------------------------------Archetype of the Rejected--------------------------------------------------------------------------------------------------//
    while (game->thisPhase == 1) {
        int controll = 0;
        if (controll == 0){
            printf("You are in a room, there is a door... and a mysterious being holding a key.\n");
            printf("...\n");
            printf("You feel rejected...\n\n");
            printf("misterious being: You feel, therefore you are... This is the Archetype of the Rejected.\n\n");
        }

        printf("1. You feel Crowley's presence in your mind, ask him for help.\n");
        printf("2. Talk with the mysterious being.\n");
        printf("3. Surrender to the endless darkness.\n");

        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                controll++;
                printf("You decide to talk to Crowley. He says:\n");

                char *crowleyResponses[] = {
                    "Small one, do not ask me questions, find your own answers.\n",
                    "The man who seeks his own salvation in others is already condemned.\n",
                    "Persistence, young grasshopper, trees do not appear fully grown, they grow.\n"
                };

                int randomResponse = rand() % 3;
                printf("Crowley: %s\n", crowleyResponses[randomResponse]);
                break;
            case 2:
                controll++;
                printf("The mysterious presence says:\n");
                printf("You are lost and about to lose everything. Answer the riddle to find knowledge:\n");
                printf("I am that which comes before, before greatness I was small, in nature I fell, to rise from the ground, there is no fruit without me, and I would never be without fruit, who am I?\n");

                int answer;
                int correct = 0;
                int chances = 2;
                
                while (correct == 0) {
                    printf("Who am I?\n\n");
                    printf("1. I am the tree\n");
                    printf("2. I am nothing\n");
                    printf("3. I am the seed\n");
                    scanf("%d", &answer);
                    if ((answer == 1) || (answer == 2)){
                        if (chances > 0){
                            printf("You are wrong. Try again.\n");
                            chances--;
                        }
                        if (chances == 0){
                            printf("You are gone, there is only darkness.\n");
                            system("PAUSE");
                            return;
                        }
                    }else if(answer == 3){
                        printf("You see? The seed that germinates is the one rejected by the tree. Growth only comes to those who fall.\n");
                        printf("The next room are waiting, continue your journey.\n");
                        correct++;
                        game->thisPhase = 2;
                    }else{
                        printf("Invalid option.\n");
                    }
                }
                break;
            case 3:
                controll++;
                printf("You gave up. There's only darkness.\n");
                system("PAUSE");
                return;
            default:
                controll++;
                printf("Invalid option. Choose again.\n");
        }
    }
//----------------------------------------------------------------------------Archetype of the Hungry--------------------------------------------------------------------------------------------------//
     while (game->thisPhase == 2) {
        int controll = 0;
        if (controll == 0){
            printf("You made it to the next room... a table lies ahead.\n");
            printf("There is also a door... of course it is locked.\n");
            printf("...\n");
            printf("You feel hungry...\n\n");
            printf("'You feel, therefore you are...'\n\n");
        }

        printf("1. You feel Crowley's presence in your mind, ask him for help.\n");
        printf("2. Talk with the mysterious being.\n");
        printf("3. Surrender to the endless darkness.\n");

        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                controll++;
                printf("You decide to talk to Crowley. He says:\n");

                char *crowleyResponses[] = {
                    "Small one, do not ask me questions, find your own answers.\n",
                    "The man who seeks his own salvation in others is already condemned.\n",
                    "Persistence, young grasshopper, trees do not appear fully grown, they grow.\n"
                };

                int randomResponse = rand() % 3;
                printf("Crowley: %s\n", crowleyResponses[randomResponse]);
                break;
            case 2:
                controll++;
                printf("The mysterious presence says:\n");
                printf("You are lost and about to lose everything. Answer the riddle to find knowledge:\n");
                printf("I am that which comes before, before greatness I was small, in nature I fell, to rise from the ground, there is no fruit without me, and I would never be without fruit, who am I?\n");

                int answer;
                int correct = 0;
                int chances = 2;
                
                while (correct == 0) {
                    printf("Who am I?\n\n");
                    printf("1. I am the tree\n");
                    printf("2. I am nothing\n");
                    printf("3. I am the seed\n");
                    scanf("%d", &answer);
                    if ((answer == 1) || (answer == 2)){
                        if (chances > 0){
                            printf("You are wrong. Try again.\n");
                            chances--;
                        }
                        if (chances == 0){
                            printf("You are gone, there is only darkness.\n");
                            system("PAUSE");
                            return;
                        }
                    }else if(answer == 3){
                        printf("You see? The seed that germinates is the one rejected by the tree. Growth only comes to those who fall.\n");
                        printf("The next room are waiting, continue your journey.\n");
                        correct++;
                        game->thisPhase = 3;
                    }else{
                        printf("Invalid option.\n");
                    }
                }
                break;
            case 3:
                controll++;
                printf("You gave up. There's only darkness.\n");
                system("PAUSE");
                return;
            default:
                controll++;
                printf("Invalid option. Choose again.\n");
        }
    }
}

int main() {
    srand(time(0));
    struct game game;

    runGame(&game);
    play(&game);

    return 0;
}
