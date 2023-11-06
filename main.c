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
    int knowledge;
};

struct game {
    struct Character elijah;
    struct Character crowley;
    struct Character wizard;
    struct Character mother;
    struct Character hajile;
    int thisPhase;
};

void typeText(char *text) {
    int i = 0;
    for (i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
#ifdef _WIN32
        Sleep(50);
#else
        usleep(50000);
#endif
    }
}

void runGame(struct game *game) {
    typeText("Welcome, Elijah!\n");

    strcpy(game->elijah.name, "Elijah");
    game->elijah.sanity = 100;
    game->elijah.will = 10;
    game->elijah.knowledge = 5;

    strcpy(game->crowley.name, "Crowley");
    game->crowley.sanity = 1000;
    game->crowley.will = 1000;
    game->crowley.knowledge = 1000;

    strcpy(game->wizard.name, "Unknown");
    game->wizard.sanity = 1000;
    game->wizard.will = 1000;
    game->wizard.knowledge = 1000;

    strcpy(game->mother.name, "Martha");
    game->mother.sanity = 0;
    game->mother.will = 10;
    game->mother.knowledge = 1000;

    strcpy(game->hajile.name, "Hajile");
    game->hajile.sanity = 100;
    game->hajile.will = 10;
    game->hajile.knowledge = 10;

    game->thisPhase = 1;

    typeText("My name is Crowley...\n");
    typeText("I offer you an opportunity, like never seen before...\n");
    typeText("Let's not talk about the tragedy, or the past, but your future.\n");
    typeText("Oh, yes! You can earn a future, if you succeed\n");
    typeText("This is your rescue, your chance to become stronger than ever, fulfilled and renewed\n");
    typeText("Be brave and smart as I know you are, do not surrender, do not give up.\n");
    typeText("Good luck at the challenges ahead\n");
    typeText("...\n");
    
    system("PAUSE");
}

void play(struct game *game) {

//----------------------------------------------------------------------------Trial of the Rejected--------------------------------------------------------------------------------------------------//
    while (game->thisPhase == 1) {
        int control = 0;
        if (control == 0){
        typeText("You are in a room, there is a door... and a mysterious being holding a key.\n\n");
        printf("...\n");
        typeText("You feel rejected...\n");
        typeText("misterious being: You feel, therefore you are... This is the Trial of the Rejected.\n");
        }      

        printf("1. You feel Crowley's presence in your mind, ask him for help.\n");
        printf("2. Talk to the mysterious being.\n");
        printf("3. Surrender to the endless darkness.\n");

        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            control++;
                typeText("You decide to talk to Crowley. He says:\n");

                char *crowleyResponses[] = {
                    "Small one, do not ask me questions, find your own answers.\n",
                    "The man who seeks his own salvation in others is already condemned.\n",
                    "Persistence, young grasshopper, trees do not appear fully grown, they grow.\n"
                };

                int randomResponse = rand() % 3;
                printf("Crowley: %s", crowleyResponses[randomResponse]);
                break;
            case 2:
            control++;
                typeText("The mysterious presence says:\n");
                typeText("You are lost and about to lose everything. Answer the riddle to find knowledge:\n");
                typeText("In nature I fell, to rise from the earth, there is no fruit without me, and no chance to ribirth, who am I?\n");

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
                        printf("You see? The seed that germinates is the one rejected by the tree. Growth only comes for those who fall.\n");
                        system("PAUSE");
                        typeText("The next room are waiting, continue your journey.\n");
                        correct++;
                        system("PAUSE");
                        game->elijah.knowledge = game->elijah.knowledge+5;
                        game->thisPhase = 2;
                    }else{
                        printf("Invalid option.\n");
                    }
                }
                break;
            case 3:
                printf("You gave up. There's only darkness.\n");
                system("PAUSE");
                return;
            default:
            control++;
                printf("Invalid option. Choose again.\n");
        }
    }
//----------------------------------------------------------------------------Trial of the Fool--------------------------------------------------------------------------------------------------//
       while (game->thisPhase == 2) {
        int control = 0;
        if (control == 0){
            typeText("This is the next room.\n\n");
            printf("...\n");
            typeText("You feel foolish...\n");
            typeText("misterious being: You feel, therefore you are... This is the Trial of the Fool.\n");
        }

        printf("1. You feel Crowley's presence in your mind, ask him for help.\n");
        printf("2. Talk to the mysterious being.\n");
        printf("3. Ask the mysterious being who he is.\n");
        printf("4. Surrender to the endless darkness.\n");

        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                control++;
                typeText("You decide to talk to Crowley. He says:\n");
                typeText("Never felt that way, kiddo. Can't help ya with that one.\n");

            case 2:
                control++;
                int times = 0;
                typeText("You decide to talk to the mysterious being. He says:\n");
                for ( times = 0; times < 11; times++){
                    char *beingResponses[] = {
                        "Can you stand for what you trust?\n",
                        "Can you defend the ones you love?\n",
                        "Can you break the chains and run?\n"
                    };

                    int randomResponse = rand() % 3;
                    printf("Misterious being: %s", beingResponses[randomResponse]);

                    char answer;
                    scanf("%c", &answer);
                }

                typeText("Misterious being: See? Doens't matter what you say. Words can't define you.\n");
                typeText("Misterious being: Your actions do.\n");
                typeText("Misterious being: There will be times when the foolish will speak and the wise will act.\n");
                typeText("Misterious being: Make sure you will be on the right side of the coin.\n");
                
                system("PAUSE");
                char question = '?';
                printf("[?] - Asks wich coin.\n");
                scanf("%c", &question);
                typeText("Misterious being: This coin.\n");
                typeText("...\n");
                system("PAUSE");
                printf("You received a coin.\n");
                game->elijah.knowledge = game->elijah.knowledge+5;
                game->thisPhase = 3;
                break;
            case 3:
                control++;
                typeText("mysterious being: I'm the one who asks, you are the one who answer.\n");
            case 4:
                printf("You gave up. There's only darkness.\n");
                system("PAUSE");
                return;
            default:
                control++;
                printf("Invalid option. Choose again.\n");
        }
    }
//----------------------------------------------------------------------------Archetype of the Brave--------------------------------------------------------------------------------------------------//
while (game->thisPhase == 3) {
        int control = 0;
        if (control == 0){
            typeText("This is the next room.\n\n");
            printf("...\n");
            typeText("You are... afraid!?\n");
            typeText("But something doesn't feel right... Where is the wizard?\n");

            system("PAUSE");

            char *roomContent[] = {
            "A woman on a couch... It is dark and blurry, you can't see who it is, but somehow you know her.\n",
            "A mirror on the wall, and a silhuete of a woman within.\n",
            "A presence, like a shadow, seems like a woman or something like that.\n"
            };

            int randomIndex = rand() % 3;
            printf("%s", roomContent[randomIndex]);
        }

        

        char *phrases[] = {
            "You know who I am",
        }

        while (game->elijah.sanity > 0){

        }

        printf("1. You feel Crowley's presence in your mind, ask him for help.\n");
        printf("2. Talk to the mysterious being.\n");
        printf("3. Ask the mysterious being who he is.\n");
        printf("4. Surrender to the endless darkness.\n");

        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                control++;
                typeText("You decide to talk to Crowley. He says:\n");
                typeText("Never felt that way, kiddo. Can't help ya with that one.\n");

            case 2:
                control++;
                int times = 0;
                typeText("You decide to talk to the mysterious being. He says:\n");
                for ( times = 0; times < 11; times++){
                    char *beingResponses[] = {
                        "Can you stand for what you trust?\n",
                        "Can you defend the ones you love?\n",
                        "Can you break the chains and run?\n"
                    };

                    int randomResponse = rand() % 3;
                    printf("Misterious being: %s", beingResponses[randomResponse]);

                    char answer;
                    scanf("%c", &answer);
                }

                typeText("Misterious being: See? Doens't matter what you say. Words can't define you.\n");
                typeText("Misterious being: Your actions do.\n");
                typeText("Misterious being: There will be times when the foolish will speak and the wise will act.\n");
                typeText("Misterious being: Make sure you will be on the right side of the coin.\n");
                
                system("PAUSE");
                char question = '?';
                printf("[?] - Asks wich coin.\n");
                scanf("%c", &question);
                typeText("Misterious being: This coin.\n");
                typeText("...\n");
                system("PAUSE");
                printf("You received a coin.\n");
                game->elijah.knowledge = game->elijah.knowledge+5;
                game->thisPhase = 3;
                break;
            case 3:
                control++;
                typeText("mysterious being: I'm the one who asks, you are the one who answer.\n");
            case 4:
                printf("You gave up. There's only darkness.\n");
                system("PAUSE");
                return;
            default:
                control++;
                printf("Invalid option. Choose again.\n");
        }
    }

//----------------------------------------------------------------------------Archetype of the Fool--------------------------------------------------------------------------------------------------//
}

int main() {
    srand(time(0));
    struct game game;

    runGame(&game);
    play(&game);

    return 0;
}

