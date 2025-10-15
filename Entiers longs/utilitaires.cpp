#include <iostream>
#include "lit_ecrit.h"
#include <cmath>
#include "entierlong.h"
#include "stdio.h"
using namespace std;


t_EntierLong convertToLong(int n){
    t_EntierLong nlong;
    int temp;
    
    // Vérification d'abord si l'entiers est negatif ou non
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


bool Test(t_EntierLong a , t_EntierLong b) {
    bool iseq = false; // Initialisation de la variable de vérification
    if (a.negatif == b.negatif) {  // On vérifie d'abord si c'est négatif ou non
        for (int i = 0; i< MAXCHIFFRES; i++){ // On vérifie ensuite les égalités termes a termes
            if (a.chiffres[i]==b.chiffres[i]) {
                iseq = true; // a et b sont bien egaux 
            }
        }
    }
    return iseq; // Réponse du code
}

bool compvalabs(t_EntierLong n1, t_EntierLong n2){ 
    bool comp = false;
    for (int i = 0; i<MAXCHIFFRES; i++){
        if (n1.chiffres[MAXCHIFFRES-i] <= n2.chiffres[MAXCHIFFRES-i]){
            comp = true;
        }
        else {
            comp = false;
        }
    }
    return comp;
}