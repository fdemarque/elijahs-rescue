#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

struct Character
{
    char name[50];
    int sanity;
    int will;
    int knowledge;
    char **phrases;
    int numPhrases;
};

struct game
{
    struct Character elijah;
    struct Character crowley;
    struct Character wizard;
    struct Character mother;
    struct Character hajile;
    int thisPhase;
    int index;
};

void typeText(char *text)
{
    int i = 0;
    for (i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        fflush(stdout);
#ifdef _WIN32
        Sleep(50);
#else
        usleep(50000);
#endif
    }
}

void customPause(const char *message)
{
    printf("%s", message);
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}


void printGameTitle()
{
    printf("=======================================================================================================================================\n");
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("|####################################################------------------------------###################################################|\n");
    Sleep(200);
    printf("|####################################################----------WELCOME TO----------###################################################|\n");
    Sleep(200);
    printf("|####################################################------------------------------###################################################|\n");
    Sleep(200);
    printf("|####################################################-------ELIJAH'S RESCUE--------###################################################|\n");
    Sleep(200);
    printf("|####################################################------------------------------###################################################|\n");
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("=======================================================================================================================================\n");
}

void printEndScreen()
{
    system('cls');
    printf("=======================================================================================================================================\n");
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("|####################################################------------------------------###################################################|\n");
    Sleep(200);
    printf("|####################################################------------THANKS------------###################################################|\n");
    Sleep(200);
    printf("|####################################################-------------FOR--------------###################################################|\n");
    Sleep(200);
    printf("|####################################################-----------PLAYING------------###################################################|\n");
    Sleep(200);
    printf("|####################################################------------------------------###################################################|\n");
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("=======================================================================================================================================\n");
}

void runGame(struct game *game)
{
    strcpy(game->elijah.name, "Elijah");
    game->elijah.sanity = 100;
    game->elijah.will = 10;
    game->elijah.knowledge = 5;
    game->elijah.phrases = (char **)malloc(4 * sizeof(char *));
    game->elijah.numPhrases = 4;

    game->elijah.phrases[0] = "Elijah: We rejected ourselves, we... I must accept myself.\n";
    game->elijah.phrases[1] = "Elijah: And how WE see ourselves? We... I should be fighting FOR me!.\n";
    game->elijah.phrases[2] = "Elijah: She is gone, and this is the hardest part of our fight, but it's also a reason to stand FOR her because she fought for me!\n";
    game->elijah.phrases[3] = "Elijah: You can face EVERYTHING, I can face EVERYTHING, WE ARE ONE, AND WE DESERVE OUR PLACE UNDERNEATH THE SUN!\n";

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
    game->mother.phrases = (char **)malloc(9 * sizeof(char *));
    game->mother.numPhrases = 9;

    game->mother.phrases[0] = "Martha: You know who I am.\n",
    game->mother.phrases[1] = "Martha: I missed you so much my son.\n",
    game->mother.phrases[2] = "Martha: Look what they've done to you my boy.\n",
    game->mother.phrases[3] = "Martha: Don't blame on you for it's not your fault, but listen to me...\n",
    game->mother.phrases[4] = "Martha: You were loved with a love I didn't even knew I could feel... And you'll always be.\n",
    game->mother.phrases[5] = "Martha: Mom wants you to be brave, and fight for us up there.\n",
    game->mother.phrases[6] = "Martha: Life is beautiful and meaningful because it ends.\n",
    game->mother.phrases[7] = "Martha: There's is one last thing I want you to know before our last goodbye.\n",
    game->mother.phrases[8] = "Martha: ...\n";

    strcpy(game->hajile.name, "Hajile");
    game->hajile.sanity = 100;
    game->hajile.will = 10;
    game->hajile.knowledge = 10;
    game->hajile.phrases = (char **)malloc(4 * sizeof(char *));
    game->hajile.numPhrases = 4;

    game->hajile.phrases[0] = "Hajile: THE WORLD OF THE LIVING HAS REJECTED ME!\n",
    game->hajile.phrases[1] = "Hajile: THE WORLD OF THE LIVING SEES ME AS A FOOL!\n",
    game->hajile.phrases[2] = "Hajile: OUR MOTHER IS GONE, I AM NOTHING WITHOUT HER!\n",
    game->hajile.phrases[3] = "Hajile: I CAN'T NO LONGER FACE THE WORLD OF THE LIVING!\n";

    game->thisPhase = 1;
    
    system("cls");
    typeText("Welcome, Elijah!\n");
    typeText("My name is Crowley...\n");
    typeText("We don't have much time for explanations, just know your suffering was noticed...\n");
    typeText("Be brave and smart as I know you are, and good luck at the challenges ahead.\n");
    typeText("...\n");
    Sleep(3000);
}

void play(struct game *game)
{
    //----------------------------------------------------------------------------Trial of Acceptance--------------------------------------------------------------------------------------------------//
    system("cls");
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("|######################################################---------PHASE %d---------######################################################|\n", game->thisPhase);
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    customPause("");
    customPause("Press Enter to continue...");
    typeText("You are in a room, there is a door... and a mysterious being holding a key.\n\n");
    printf("...\n");
    typeText("You feel rejected...\n");
    typeText("misterious being: You feel, therefore you are... This is the Trial of the Acceptance.\n");

    while (game->thisPhase == 1)
    {
        printf("1. You feel Crowley's presence in your mind, ask him for help.\n");
        printf("2. Talk to the mysterious being.\n");
        printf("3. Surrender to the endless darkness.\n");

        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            typeText("You decide to talk to Crowley. He says:\n");

            char *crowleyResponses[] = {
                "Small one, do not ask me questions, find your own answers.\n",
                "The man who seeks his own salvation in others is already condemned.\n",
                "Persistence, young grasshopper, even the greatest tree was once a tiny little seedling, or even a seed.\n"};

            int randomResponse = rand() % 3;
            printf("Crowley: %s", crowleyResponses[randomResponse]);
            break;
        case 2:
            typeText("The mysterious presence says:\n");
            typeText("You are lost and about to lose everything. Answer the riddle to find knowledge:\n");
            typeText("In nature I fell, to rise from the earth, there is no fruit without me, and no chance to ribirth, who am I?\n");

            int answer;
            int correct = 0;
            int chances = 2;

            while (correct == 0)
            {
                printf("Who am I?\n\n");
                printf("1. I am the tree\n");
                printf("2. I am nothing\n");
                printf("3. I am the seed\n");
                scanf("%d", &answer);
                if ((answer == 1) || (answer == 2))
                {
                    if (chances > 0)
                    {
                        printf("You are wrong. Try again.\n");
                        chances--;
                    }
                    if (chances == 0)
                    {
                        printf("You are gone, there is only darkness.\n");
                        customPause("");
                        customPause("Press Enter to leave.");
                        return;
                    }
                }
                else if (answer == 3)
                {
                    typeText("You see? The seed that germinates is the one rejected by the tree. Growth only comes for those who fall.\n");
                    typeText("The next room are waiting, continue your journey.\n");
                    correct++;
                    Sleep(3000);
                    game->elijah.knowledge = game->elijah.knowledge + 5;
                    game->thisPhase = 2;
                }
                else
                {
                    printf("Invalid option.\n");
                }
            }
            break;
        case 3:
            printf("You gave up. There's only darkness.\n");
            Sleep(3000);
            customPause("");
            customPause("Press Enter to leave.");
            return;
        default:
            printf("Invalid option. Choose again.\n");
        }
    }
    //----------------------------------------------------------------------------Trial of the Wise--------------------------------------------------------------------------------------------------//
    system("cls");
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("|######################################################---------PHASE %d---------######################################################|\n", game->thisPhase);
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    customPause("Press Enter to continue...\n");
    typeText("This is the next room.\n\n");
    printf("...\n");
    typeText("You feel foolish...\n");
    typeText("misterious being: You feel, therefore you are... This is the Trial of the Wise.\n");

    while (game->thisPhase == 2)
    {

        printf("1. You feel Crowley's presence in your mind, ask him for help.\n");
        printf("2. Talk to the mysterious being.\n");
        printf("3. Ask the mysterious being who he is.\n");
        printf("4. Surrender to the endless darkness.\n");

        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            typeText("You decide to talk to Crowley. He says:\n");
            typeText("Never felt that way, kiddo. Can't help ya with that one.\n");
        case 2:
            typeText("You decide to talk to the mysterious being. He says:\n");
            int times = 0;
            for (times = 0; times < 11; times++)
            {
                char *beingResponses[] = {
                    "Can you stand for what you trust?\n",
                    "Can you defend the ones you love?\n",
                    "Can you break the chains and run?\n"};

                int randomResponse = rand() % 3;
                printf("Misterious being: %s", beingResponses[randomResponse]);
                printf("[y] - yes || [n] - no\n");

                char answer;
                scanf(" %c", &answer);
            }

            typeText("Misterious being: See? Doens't matter what you say. Words can't define you.\n");
            typeText("Misterious being: Your actions do.\n");
            typeText("Misterious being: There will be times when the foolish will speak and the wise will act.\n");
            typeText("Misterious being: Make sure you will be on the right side of the coin.\n");
            typeText(".\n");
            typeText(".\n");
            typeText(".\n");
            typeText(".\n");
            typeText("...\n");
            typeText("The door opens.\n");
            Sleep(3000);
            game->elijah.knowledge = game->elijah.knowledge + 5;
            game->thisPhase = 3;
            break;
        case 3:
            typeText("mysterious being: I'm the one who asks, you are the one who answer.\n");
        case 4:
            printf("You gave up. There's only darkness.\n");
            Sleep(3000);
            customPause("");
            customPause("Press Enter to leave.\n");
            return;
        default:
            printf("Invalid option. Choose again.\n");
        }
    }
    //----------------------------------------------------------------------------Trial of the Brave--------------------------------------------------------------------------------------------------//
    system("cls");
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("|######################################################---------PHASE %d---------######################################################|\n", game->thisPhase);
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    customPause("Press Enter to continue...\n");
    typeText("This is the next room.\n\n");
    printf("...\n");
    typeText("You are... afraid!?\n");
    typeText("But something doesn't feel right... Where is the wizard?\n");
    
    customPause("");
    customPause("Press Enter to continue.\n");

    char *roomContent[] = {
        "A woman on a couch... It is dark and blurry, you can't see who it is, but somehow you know her.\n",
        "A mirror on the wall, and a silhuete of a woman within.\n",
        "A presence, like a shadow, seems like a woman or something like that.\n"};

    int theRoom = rand() % 3;
    printf("%s", roomContent[theRoom]);
    typeText("A cold silence fills the room, what you are going to do?\n\n");

    while (game->thisPhase == 3)
    {
        int choice;
        printf("1. Crowley's presence has faded, try to reach him.\n");
        printf("2. Ask who is she.\n");
        printf("3. Surrender to the endless darkness.\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            typeText("You're by your own.\n");
            break;
        case 2:
            game->index = 0;
            for (game->elijah.sanity = 90; game->elijah.sanity > 1; game->elijah.sanity = game->elijah.sanity-10){
                {
                    printf("----------------------------------------------------------------------------------------\n");
                    printf("%s\n", game->mother.phrases[game->index]);
                    printf("----------------------------------------------------------------------------------------\n");
                    int answer = 0;
                    {
                        typeText("Hear more?\n");
                        printf("1. Yes.\n");
                        printf("2. No.\n");
                        scanf("%d", &answer);

                        if (answer == 1 && game->elijah.sanity > 0)
                        {
                            typeText("You lose sanity.\n\n");
                            printf("Actual sanity is %d\n\n", game->elijah.sanity);
                            game->index++;
                        }
                        else if (answer == 2)
                        {
                            typeText("The fear consumes your soul, you are gone forevermore.\n");
                            customPause("Press Enter to leave.");
                            return;
                        }
                    }
                }

            }
            typeText("You are gone, there is only darkness.\n");
            typeText(".\n");
            typeText(".\n");
            typeText(".\n");
            typeText("...\n");
            typeText("Wait, you are still there... And somebody opens the door, it's the wizard!\n");
            customPause("Press Enter to continue.");
            typeText("mysterious being: That's bravery. Feel the fear, the risk, but stay loyal to your heart.\n");
            typeText("mysterious being: The door opens for you, go ahead and face your last challenge.\n");
            Sleep(3000);
            game->elijah.sanity = 100;
            game->thisPhase = 4;
            break;
        case 3:
            typeText("You can't surrender now.\n");
            break;
        default:
            printf("Invalid option. Choose again.\n");
        }
    }

    //----------------------------------------------------------------------------Archetype of the Hero--------------------------------------------------------------------------------------------------//
    system("cls");
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("|######################################################---------PHASE %d---------######################################################|\n", game->thisPhase);
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    customPause("Press Enter to continue...");

    typeText("You are in the last room.\n\n");
    typeText("...\n");
    typeText("You feel confused...\n");
    typeText("mysterious being whispers: It is anger, sadness, anguish, and a lot more you're feeling.\n");
    typeText("Now look ahead.\n");
    typeText(".\n");
    typeText(".\n");
    typeText(".\n");
    typeText("...\n");
    typeText("There is what looks like a boy, his eyes are filled with darkness and pain, he is long forgotten and so far gone.\n");
    typeText("And he looks like you.\n");

    while (game->thisPhase == 4)
    {
        printf("1. Try to contact with the wizard for instructions.\n");
        printf("2. Ask Crowley for help.\n");
        printf("3. Talk to the boy.\n");
        printf("4. Surrender to the endless darkness.\n");

        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            typeText("You try to contact the mysterious being...\n");
            typeText("...\n");
            Sleep(200);
            printf("He isn't there.\n");
            break;
        case 2:
            typeText("You try to contact Crowley...\n");
            typeText("...\n");
            Sleep(200);
            printf("He isn't there.\n");
            break;
        case 3:
            printf("What do you say?\n\n");
            printf("1. Hi!\n");
            printf("2. Who are you?\n");
            printf("3. Are you real?\n");
            int answer1;
            scanf("%d", &answer1);
            if ((answer1 == 2) || (answer1 == 3))
            {
                typeText("He stares at you angrily...\n");
            }
            else
            {
                typeText("He remains silent...\n");
            }

            int answer2;
            typeText("You just notice that your backpack is by your side on the ground...\n");
            printf("Grab it?\n\n");
            printf("1. Yes.\n");
            printf("2. No.\n");
            scanf("%d", &answer2);
            if (answer2 == 1)
            {
                typeText("He screams, with a guttural voice...\n");
                typeText("IT IS MINE, DON'T TOUCH IT!\n");
            }
            else
            {
                typeText("Ok.\n");
                typeText("IT IS MINE, DON'T LOOK AT IT!\n");
            }

            typeText("As he screams, you feel your sanity fading\n");
            typeText("This time is different, you really feel like you are losing yourself to darkness as you get insaner...\n");
            typeText("You must hurry.\n");

            int yourAnswer;
            for (game->index = 0; game->index < 4; game->index++)
            {
                printf("----------------------------------------------------------------------------------------\n");
                printf("%s\n", game->hajile.phrases[game->index]);
                printf("----------------------------------------------------------------------------------------\n");
                printf("1. Agree!\n");
                printf("2. Deny!\n");
                scanf("%d", &yourAnswer);
                if (yourAnswer == 2)
                {
                    game->elijah.knowledge = game->elijah.knowledge - 5;
                    printf("----------------------------------------------------------------------------------------\n");
                    printf("%s\n", game->elijah.phrases[game->index]);
                    printf("----------------------------------------------------------------------------------------\n");
                }
                else
                {
                    game->elijah.sanity = game->elijah.sanity - 25;
                    typeText("You feel your sanity fading.\n");
                }
            }

            if (game->elijah.sanity < 1)
            {
                typeText("You tried, but it's too late.\n");
                Sleep(200);
                typeText("You can't save him, and you are also gone...\n");
                typeText("Goodbye.\n");
                return;
            }
            else
            {
                Sleep(500);
                system('cls');
                typeText("Lights fade out...\n");
                Sleep(500);
                system('cls');
                typeText("You see nothing...\n");
                Sleep(500);
                system('cls');
                typeText(".\n");
                typeText(".\n");
                typeText(".\n");
                typeText(".\n");
                typeText(".\n");
                typeText("...\n");
                typeText("You hear the voice of the wizard.\n");
                typeText("mysterious being: He seems to be waking up...\n");
                Sleep(3000);
                customPause("Press Enter to continue...");
                game->thisPhase = 5;
                break;
            }
        case 4:
            printf("You gave up. There's only darkness.\n");
            Sleep(3000);
            customPause("Press Enter to leave.");
            return;
        default:
            printf("Invalid option. Choose again.\n");
        }
    }
//---------------------------------------------------------------------------------------FINALE---------------------------------------------------------------------------------------------------
    system("cls");
    printf("|#####################################################################################################################################|\n");
    Sleep(200);
    printf("|######################################################---------PHASE %d---------######################################################|\n", game->thisPhase);
    Sleep(200);
    printf("|#####################################################################################################################################|\n");
    customPause("Press Enter to continue...");

    typeText("You are awake.\n");
    typeText("...\n");
    Sleep(3000);
    system('cls');
    typeText("you are in the hospital... a man with sunglasses is watching you from the other side of the window...\n");
    typeText("something tells you that you know him...");
    typeText(".\n");
    typeText(".\n");
    typeText(".\n");
    typeText(".\n");
    typeText(".\n");
    typeText("...\n");
    typeText("He smiles for you and leave...");
    Sleep(5000);
}


int main()
{
    srand(time(0));
    struct game game;

    printGameTitle();
    customPause("|#######################################################--PRESS ENTER TO PLAY--#######################################################|\n");
    runGame(&game);
    play(&game);
    printEndScreen();

    return 0;
}

