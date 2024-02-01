#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define CODAGE 1
#define DECODAGE 2
#define KEY 3
#define ALPHABET 256
/**
 * @brief Génère un nombre aléatoire strictement compris entre un minimum et un maximum donné.
 *
 * @param min Borne inferieure de l'intervalle de génération du nombre aléatoire.
 * @param max Borne supérieure de l'intervalle de génération du nombre aléatoire.
 * @return Un nombre aléatoire strictement compris entre min et max.
 */
int generer_aleatoire_intervalle(int min, int max)
{
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
/**
 * @brief Permet d'ouvrir un fichier en prenant son chemin et son mode d'ouverture en paramètres.
 *
 * @param chemin Le chemin du fichier à ouvrir
 * @param mode  Le mode d'ouverture du fichier à ouvrir
 * @return FILE* Renvoie un flux correspondant au fichier ouvert. Si une erreur survient lors de l'ouverture du fichier, le programme affiche un message
 * d'erreur et quitte.
 */
FILE *ouvrir_fichier(char *chemin, char *mode)
{
    FILE *flux = fopen(chemin, mode);

    if (flux == NULL)
    {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", chemin);
        exit(1);
    }

    return flux;
}
/**
 * @brief Génère une clé de cryptage en fonction du message de l'utilisateur.
 *
 * @param chemin_msg Le chemin du fichier contenant le message.
 * @param chemin_clef Le chemin du fichier où sera stockée la clé générée.
 */
void generer_clef(char *chemin_msg, char *chemin_clef)
{
    FILE *message = ouvrir_fichier(chemin_msg, "r");
    FILE *key = ouvrir_fichier(chemin_clef, "w");
    while (fgetc(message) != EOF)
    {
        fputc(generer_aleatoire_intervalle(0, ALPHABET - 1), key);
    }
    fclose(key);
    fclose(message);
}
/**
 * @brief Permet de coder le message à partir d'une clé.
 *
 * @param chemin_msg Le chemin du fichier contenant le message.
 * @param chemin_clef Le chemin du fichier où sera stockée la clé générée.
 * @param chemin_resultat Le chemin du fichier où sera stocké le message codé.
 */
void coder_message(char *chemin_msg, char *chemin_clef, char *chemin_resultat)
{

    int c;
    int k1;
    int calcul;

    FILE *message = ouvrir_fichier(chemin_msg, "r");
    FILE *key = ouvrir_fichier(chemin_clef, "r");
    FILE *resultat = ouvrir_fichier(chemin_resultat, "w");

    while ((c = fgetc(message)) != EOF)
    {
        k1 = fgetc(key);
        calcul = (c + k1) % ALPHABET;
        fputc(calcul, resultat);
    }

    fclose(message);
    fclose(key);
    fclose(resultat);
}
/**
 * @brief Décode le message codé à l'aide de celui-ci et de la clé générée.
 *
 * @param chemin_msg_code  Le chemin du fichier contenant le message codé.
 * @param chemin_clef Le chemin du fichier où sera stockée la clé générée.
 * @param chemin_resultat Le chemin du fichier où sera stocké le message décodé.
 */
void decoder_message(char *chemin_msg_code, char *chemin_clef, char *chemin_resultat)
{
    int c;
    int k1;
    int calcul;

    FILE *message = ouvrir_fichier(chemin_msg_code, "r");
    FILE *key = ouvrir_fichier(chemin_clef, "r");
    FILE *resultat = ouvrir_fichier(chemin_resultat, "w");

    while ((c = fgetc(message)) != EOF)
    {
        k1 = fgetc(key);
        // calcul = c - k1 >= 0 ? c - k1 : ALPHABET - (c - k1);
        calcul = (c - k1) % ALPHABET;
        fputc(calcul, resultat);
    }

    fclose(message);
    fclose(key);
    fclose(resultat);
}

int main(int argc, char *argv[])
{
    FILE *message, *key, *resultat;
    srand(time(NULL));
    char usage_msg[1000];
    int mode = -1;
    int c;
    int k1;
    int calcul;

    sprintf(usage_msg, "Usage :\n"
                       "%s -c <fichier_msg> <fichier_clé> <fichier_msg_codé>\n"
                       "%s -d <fichier_msg_codé> <fichier_clé> <fichier_msg_décodé>\n"
                       "%s -k <fichier_msg> <fichier_clé>\n",
            argv[0], argv[0], argv[0]);

    if (argc < 4 || argc > 5)
    {
        printf("%s", usage_msg);
        return EXIT_FAILURE;
    }
    else
    {
        if (strcmp(argv[1], "-c") == 0)
        {
            if (argc != 5)
            {
                printf("%s", usage_msg);
                return EXIT_FAILURE;
            }
            else
                mode = CODAGE;
        }
        else if (strcmp(argv[1], "-d") == 0)
        {
            if (argc != 5)
            {
                printf("%s", usage_msg);
                return EXIT_FAILURE;
            }
            else
                mode = DECODAGE;
        }
        else if (strcmp(argv[1], "-k") == 0)
        {
            if (argc != 4)
            {
                printf("%s", usage_msg);
                return EXIT_FAILURE;
            }
            else
                mode = KEY;
        }
        else
        {
            printf("%s", usage_msg);
            return EXIT_FAILURE;
        }
    }

    if (mode == KEY)
    {
        generer_clef(argv[2], argv[3]);
    }
    else if (mode == DECODAGE)
    {
        decoder_message(argv[2], argv[3], argv[4]);
    }
    else if (mode == CODAGE)
    {
        coder_message(argv[2], argv[3], argv[4]);
    }

    return EXIT_SUCCESS;
}