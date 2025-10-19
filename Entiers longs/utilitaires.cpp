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

bool EqualTest(t_EntierLong a , t_EntierLong b) {
    bool iseq = false; // Initialisation de la variable de vérification d'égalité
    for (int i = 0; i< MAXCHIFFRES; i++){ // On vérifie ensuite les égalités termes a termes
        if (a.chiffres[i]==b.chiffres[i]) {
            iseq = true; // a et b sont bien egaux 
        }
    }
    return iseq; // Réponse du code
}

bool FullTest(t_EntierLong a , t_EntierLong b) {
    bool iseq = false; // Initialisation de la variable de vérification d'égalité
    if (a.negatif == b.negatif) {
        bool SameSign = true;  // On vérifie d'abord si ils ont le même signe
        for (int i = 0; i< MAXCHIFFRES; i++){ // On vérifie ensuite les égalités termes a termes
            if (a.chiffres[i]==b.chiffres[i]) {
                iseq = true; // a et b sont bien egaux 
            }
        }
    }
    return iseq; // Réponse du code
}

bool compvalabs(t_EntierLong n1, t_EntierLong n2){ 
    bool comp = false; // Reponse finale de la comparaison |n1| < |n2|
    int n10 = 0; // Nombre de zero de droite a gauche pour n1
    int n20 = 0; // Nombre de zero de droite a gauche pour n2
    bool iseq = false; // Initialisation de la variable d'égalité

    for (int i = 0; i < MAXCHIFFRES; i++){          // Comptage des zeros
        if (n1.chiffres[MAXCHIFFRES-i] == 0){
            n10++;
        }
        if (n2.chiffres[MAXCHIFFRES-i]==0){
            n20++;
        }
    }

    if (n10 == n20){ // On etudie le cas ou il y a le même nombre de zero
        // On etudie le sous cas où |n1|=|n2|
        for (int i = 0; i<MAXCHIFFRES; i++){
            while (n1.chiffres[i] == n2.chiffres[i]){
                iseq = true;
            }
        }
        if (iseq == false){
            for (int i = 0; i<MAXCHIFFRES; i++){
            // On regarde ensuite si n1 < n2 terme a terme
            if (n1.chiffres[MAXCHIFFRES-i] < n2.chiffres[MAXCHIFFRES-i]){
                comp = true;
            }
            else {
                comp = false;
            }  
            }
            return comp;
        }
        else {
            return iseq; // Renvoie vrai si n1=n2
        }
    } // On regarde les cas plus simple 
    else    {
            if (n10 < n20){
                return true;
            }
            if (n10 > n20){
                return false;
            }
    }
    return 0;
}