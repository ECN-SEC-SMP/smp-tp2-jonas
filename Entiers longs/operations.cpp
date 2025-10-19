#include <iostream>
#include "entierlong.h"
#include "utilitaires.h"
using namespace std;

/*Fonciton usum : addition n1+n2 de deux entiers longs de même signe*/
t_EntierLong usum(t_EntierLong n1, t_EntierLong n2){
    t_EntierLong n3; // Initialisation du resultat n1+n2 = n3
    for (int i = 0; i<MAXCHIFFRES; i++){ // On somme termes a termes les chiffres
        if (n1.chiffres[MAXCHIFFRES-i]+n2.chiffres[MAXCHIFFRES-i] > 9){ // Cas ou la somme est sup à 10
            n3.chiffres[MAXCHIFFRES-i+1]++; // Ajoute 1 en retenue 
            n3.chiffres[MAXCHIFFRES-i] = (n1.chiffres[MAXCHIFFRES-i]+n2.chiffres[MAXCHIFFRES-i]) % 10; // Ajoute l'unité dans n3
        } 
        else { // Le cas plus simple il n'y a pas de retenue
            n3.chiffres[MAXCHIFFRES- i ] = n1.chiffres[MAXCHIFFRES-i]+n2.chiffres[MAXCHIFFRES-i];
        }
    }
    return n3;
}

/*Fonciton usub : soustraction n1-n2 de deux entiers longs n1 et n2 de même signe et tels que |n1| >= |n2|*/
t_EntierLong usub(t_EntierLong n1, t_EntierLong n2){
    t_EntierLong n3; // Initialisation du resultat de n1-n2=n3
    if (EqualTest(n1,n2)){ // Verification de la proposition : |n1|=|n2| en appelant la fonction Test dans utilitaires.cpp
        for (int i=0; i<MAXCHIFFRES; i++){ 
            n3.chiffres[MAXCHIFFRES-i]=0; // Le resultat est nul
        }
        n3.negatif == false;
        return n3;
    }
    if (not (compvalabs(n1,n2))){ // Verification de la proposition : |n1| > |n2| (l'inverse du retour de la fonction compvalabs)
        for (int i = 0; i < MAXCHIFFRES; i++){ 
            if (n1.chiffres[MAXCHIFFRES-i]-n2.chiffres[MAXCHIFFRES-i]<0){ // Cas où la soustraction terme à termes est négative
                n3.chiffres[MAXCHIFFRES-i] = (10 + n1.chiffres[MAXCHIFFRES-i]) - n2.chiffres[MAXCHIFFRES-i]; // Ajout d'un report 
                n2.chiffres[MAXCHIFFRES-i+1]++; // Ajout de la retenue dans le prochain chiffre
            }
            else{ // Cas où la soustraction terme à terme est positive
                n3.chiffres[MAXCHIFFRES-i]=n1.chiffres[MAXCHIFFRES-i]-n2.chiffres[MAXCHIFFRES-i];
            }
        }
        return n3; // Retour du resultat de la soustraction
    }    
    else {
        cout << "|n1|>|n2|"; // Arrêt du code si la condition |n1| <= |n2| n'est pas validé
        return;
    }
}

/*Fonction sum : Addition de deux entiers longs de signes quelconques*/
t_EntierLong sum(t_EntierLong n1, t_EntierLong n2){
    t_EntierLong n3;
    if (n1.negatif && n2.negatif){ // Cas ou n1 et n2 sont négatifs
        n3 = usum(n1,n2);
        n3.negatif = true;
        return n3;
    }
    if (not(n1.negatif) && not(n2.negatif)){ // Cas ou n1 et n2 sont positifs
        n3 = usum(n1,n2);
        n3.negatif = false;
        return n3;
    }
    if (n1.negatif && not(n2.negatif)){ // Cas ou n1 est négatif et n2 positif
        if (compvalabs(n1,n2)){ // Verifie si |n1| <= |n2|
            n3=usum(n1,n2); // Somme n1 et n2
            n3.negatif = false; // n3 est positif car |n1| <= |n2|, n1 < 0 et n2 > 0
        }
        else{
            n3=usum(n1,n2); // Somme n1 et n2
            n3.negatif = true;// n3 est negatif car |n1| > |n2|, n1 < 0 et n2 > 0
        }
        return n3;
    }
     if (not(n1.negatif) && n2.negatif){ // Cas ou n1 est positif et n2 négatif
        if (compvalabs(n1,n2)){// Verifie si |n1| <= |n2|
            n3=usum(n1,n2);
            n3.negatif = true; // n3 est negatif car |n1| <= |n2|, n1 > 0 et n2 < 0
        }
        else{
            n3=usum(n2,n1);
            n3.negatif = false; // n3 est positif car |n1| > |n2|, n1 > 0 et n2 < 0
        }
        return n3;
    }
}

/*Fonction sub : Soustraction de deux entiers longs de signes quelconques*/
t_EntierLong sub(t_EntierLong n1, t_EntierLong n2){
    t_EntierLong n3;
    if (EqualTest(n1,n2)){
        if ((n1.negatif != n2.negatif)){
            for (int i=0; i<MAXCHIFFRES; i++){
                n3.chiffres[MAXCHIFFRES-i] = 0;
            }
        }
    }
    if (n1.negatif && n2.negatif){ // Cas ou n1 et n2 sont négatifs
        if (compvalabs(n1,n2)){
            n3 = usub(n2,n1);
            n3.negatif = false;
        }
        else{
            n3 = usub(n2,n1);
            n3.negatif = true;
        } 
    }
    if (not(n1.negatif) && not(n2.negatif)){ // Cas ou n1 et n2 sont positifs
        if (compvalabs(n1,n2)){
            n3 = usub(n1,n2);
            n3.negatif = true;
        }
        else{
            n3 = usub(n1,n2);
            n3.negatif = false;
        }
    }
    if (n1.negatif && not(n2.negatif)) { // Cas ou n1 <0 et n2>0
        n3 = usum(n1,n2);
        n3.negatif = true;
    }
    if (not(n1.negatif) && n2.negatif){ // Cas ou n1>0 et n2<0
        n3 = usum(n1,n2);
        n3.negatif = false;
    }
}