#include <stdio.h>
#include <stdlib.h>

// Δομή για τον παίκτη
typedef struct {
    int strength;
    int intelligence;
    int dexterity;
    int vitality;
    int carisma;
    int level;
} Player;

// Συνάρτηση για αρχικοποίηση του παίκτη
void initializePlayer(Player *p) {
    p->strength = 0;
    p->intelligence = 0;
    p->dexterity = 0;
    p->vitality = 0;
    p->carisma = 0;
    p->level = 1;
}

// Συνάρτηση για εμφάνιση των χαρακτηριστικών του παίκτη σε πίνακα
void displayPlayer(const Player *p) {
    printf("\n---Player---\n");
    printf("+-----------+------------+\n");
    printf("| Level   | %-10d |\n", p->level);
    printf("+-----------+------------+\n");
    printf("| Strength  | %-10d |\n", p->strength);
    printf("| Intelligence | %-7d |\n", p->intelligence);
    printf("| Dexterity | %-10d |\n", p->dexterity);
    printf("| Vitality  | %-10d |\n", p->vitality);
    printf("| Carisma  | %-10d |\n", p->carisma);
    printf("+-----------+------------+\n");
}

// Συνάρτηση για κατανομή πόντων κατά την αύξηση επιπέδου
void allocatePoints(Player *p) {
    int choice;
    printf("You leveled up.You can add 1 point to your talents.\n");
    for(int i = 0; i < 4; i++) {
        while(1) {
            printf("Choose a talent to put 1 point:\n");
            printf("1. Strength\n");
            printf("2. Intelligence\n");
            printf("3. Dexterity\n");
            printf("4. Vitality\n");
            printf("5. Carisma\n");
            printf("Choice: ");
            scanf("%d", &choice);

            if(choice == 1) {
                if(p->strength < 10) {
                    p->strength += 1;
                    printf("Add 1 point to Strength.\n");
                    break;
                } else {
                    printf("Strength is 10(max points).\n");
                }
            }
            else if(choice == 2) {
                if(p->intelligence < 10) {
                    p->intelligence += 1;
                    printf("Add 1 point to Intelligence.\n");
                    break;
                } else {
                    printf("Intelligence is 10(max points).\n");
                }
            }
            else if(choice == 3) {
                if(p->dexterity < 10) {
                    p->dexterity += 1;
                    printf("Add 1 point to Dexterity.\n");
                    break;
                } else {
                    printf("Dexterity is 10(max points).\n");
                }
            }
            else if(choice == 4) {
                if(p->vitality < 10) {
                    p->vitality += 1;
                    printf("Add 1 point to Vitality.\n");
                    break;
                } else {
                    printf("Vitality is 10(max points).\n");
                }
            }
            if(choice == 5){
            	if(p->carisma < 10)
            	{
                    p->carisma +=1;
            	    printf("Add 1 point to Carisma.\n");
            	    break;
		}else{
		   printf("Carisma is 10(max points).");
	        }
	     }
            else {
                printf("Wrong choice try again.\n");
            }
        }
    }
    displayPlayer(p);
}

// Συνάρτηση για προσθήκη πόντων στα χαρακτηριστικά
void addPoints(Player *p) {
    int choice, points;
    printf("Choose a talent to upgrade:\n");
    printf("1. Strength\n");
    printf("2. Intelligence\n");
    printf("3. Dexterity\n");
    printf("4. Vitality\n");
    printf("5. Carisma\n");
    printf("Choice: ");
    scanf("%d", &choice);

    printf("How many points you want to add? ");
    scanf("%d", &points);

    int added = 0;

    if(choice == 1) {
        if(p->strength + points > 10) {
            printf("You can add points %d to Strength.\n", 10 - p->strength);
            p->strength = 10;
        } else {
            p->strength += points;
            printf("%d Points added to Strength.\n", points);
        }
    }
    else if(choice == 2) {
        if(p->intelligence + points > 10) {
            printf("You can add points %d toIntelligence.\n", 10 - p->intelligence);
            p->intelligence = 10;
        } else {
            p->intelligence += points;
            printf("%d Points added to Intelligence.\n", points);
        }
    }
    else if(choice == 3) {
        if(p->dexterity + points > 10) {
            printf("You can add points %d to Dexterity.\n", 10 - p->dexterity);
            p->dexterity = 10;
        } else {
            p->dexterity += points;
            printf("%d Points added to Dexterity.\n", points);
        }
    }
    else if(choice == 4) {
        if(p->vitality + points > 10) {
            printf("You can add points %d to Vitality.\n", 10 - p->vitality);
            p->vitality = 10;
        } else {
            p->vitality += points;
            printf("%d Points added to Vitality.\n", points);
        }
    }
    else if(choice == 4) {
        if(p->carisma + points > 10) {
            printf("You can add points %d to Carisma.\n", 10 - p->carisma);
            p->carisma = 10;
        } else {
            p->carisma += points;
            printf("%d Points added to Carisma.\n", points);
        }
    }else {
        printf("Wrong choice!!Please try again.\n");
        return;
    }

    // Έλεγχος για αύξηση επιπέδου
    if(p->strength >= 10 || p->intelligence >= 10 || p->dexterity >= 10 || p->vitality >= 10 || p->carisma >= 10) {
        p->level += 1;
        printf("Congratulation!You reached the maximum level %d.\n", p->level);
        allocatePoints(p);
    } else {
        displayPlayer(p);
    }
}

int main() {
    Player player;
    initializePlayer(&player);
    int option;

    printf("Welcome Player!\n");
    displayPlayer(&player);

    while(1) {
        printf("\n--- Menu ---\n");
        printf("1. Add points to talents\n");
        printf("2. Exit\n");
        printf("Choice: ");
        scanf("%d", &option);

        if(option == 1) {
            addPoints(&player);
        }
        else if(option == 2) {
            printf("Exit.\n");
            exit(0);
        }
        else {
            printf("Invalid choice.Try again.\n");
        }
    }

    return 0;
}
