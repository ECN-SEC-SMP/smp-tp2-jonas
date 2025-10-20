#include <iostream>
#include "lit_ecrit.h"
#include <cmath>
#include "entierlong.h"
#include "stdio.h"
using namespace std;

/*Fonction convertToLong : convertit un entier standard en entier long*/
t_EntierLong convertToLong(int n){
    t_EntierLong nlong;
    int temp;
    
    // Vérification d'abord si l'entier est negatif ou non
    if (n<0){          
        nlong.negatif = true; // negatif est vrai car l'entier est negatif 
    }
    else{
        nlong.negatif = false; // negatif est faux car l'entier est positif
    }

    for (int i=0; i < MAXCHIFFRES; i++){
        temp =  n % 10;         // Prendre la dernière decimale de n
        nlong.chiffres[i] = temp; // On associe le tableau d'indice i au resultat du modulo
        n = n/10; //on divise par 10 pour prendre prendre la prochaine decimale
    }

    return nlong;
};

/*Fonction EqualTest : vérifie si |n1|=|n2| */
bool EqualTest(t_EntierLong a , t_EntierLong b) {
    bool iseq = true; // Initialisation de la variable de vérification d'égalité
    for (int i = 0; i< MAXCHIFFRES; i++){ // On vérifie ensuite les égalités termes a termes
        if (a.chiffres[i] != b.chiffres[i]) {
            iseq = false; // a et b sont differents
        }
    }
    return iseq; // Réponse de l'affirmation : |n1|=|n2|
}
/*Fonction FullTest : vérifie si |n1|=|n2| et que n1 et n2 soient de même signe */
bool FullTest(t_EntierLong a , t_EntierLong b) {
    bool iseq = false; // Initialisation de la variable de vérification d'égalité
    if (a.negatif == b.negatif) { // On vérifie d'abord si ils ont le même signe
        iseq = true;
        for (int i = 0; i< MAXCHIFFRES; i++){ // On vérifie ensuite les égalités termes a termes
            if (a.chiffres[i] != b.chiffres[i]) {
                iseq = false; // a et b sont differents 
            }
        }
    }
    return iseq; // Réponse de l'affirmation : |n1|=|n2| et sign(n1)=sign(n2)
}
/*Fonction compvalabs : compare en valeur absolue deux entiers longs n1 et n2 : |n1| <= |n2|*/
bool compvalabs(t_EntierLong n1, t_EntierLong n2) {
    // On parcourt les chiffres du plus significatif au moins significatif
    for (int i = 0; i < MAXCHIFFRES; i++) {
        // Si le chiffre de n1 est plus petit, alors |n1| < |n2| est vrai
        if (n1.chiffres[MAXCHIFFRES - i - 1]< n2.chiffres[MAXCHIFFRES - i - 1]) {
            return true;
        }
        // Si le chiffre de n1 est plus grand, alors |n1| > |n2| est vrai.
        if (n1.chiffres[MAXCHIFFRES - i - 1]> n2.chiffres[MAXCHIFFRES - i - 1]) {
            return false;
        }
    }
    // Si on sort de la boucle, cela signifie que tous les chiffres étaient égaux
    return true;
}