#include <iostream>
#include "entierlong.h"
#include "utilitaires.h"
using namespace std;

/*Fonction usum : addition n1+n2 de deux entiers longs de même signe*/
t_EntierLong usum(t_EntierLong n1, t_EntierLong n2){
    t_EntierLong n3;
    n3.negatif = false;
    int retenue= 0 ;
    for (int i = 0; i<MAXCHIFFRES; i++){
        n3.chiffres[i]=0; // Initialisation du resultat n1+n2 = n3
    }
    for (int i = 0; i<MAXCHIFFRES; i++){ // On somme termes a termes les chiffres
        n3.chiffres[i] = (n1.chiffres[i] + n2.chiffres[i] + retenue) % 10; // Ajout du nouveau chiffre dans la i eme colonne
        retenue = (n1.chiffres[i] + n2.chiffres[i] + retenue) / 10; // Affectation de la nouvelle retenue
    }
    return n3;
}

/*Fonction usub : soustraction n1-n2 de deux entiers longs n1 et n2 de même signe et tels que |n1| >= |n2|*/
t_EntierLong usub(t_EntierLong n1, t_EntierLong n2){
    t_EntierLong n3;// Initialisation du resultat de n1-n2=n3
    n3.negatif = false;
    int retenue= 0 ; // Initialisation de la retenue
    for (int i = 0; i<MAXCHIFFRES; i++){
        n3.chiffres[i]=0; // Initialisation du resultat n1-n2 = n3
    }
    if (EqualTest(n1,n2)){ // Verification de la proposition : |n1|=|n2| en appelant la fonction Test dans utilitaires.cpp
        for (int i=0; i<MAXCHIFFRES; i++){ 
            n3.chiffres[i-1]=0; // Le resultat est nul
        }
        n3.negatif = false;
        return n3;
    }
    if (not(compvalabs(n1,n2))){ // Verification de la proposition : |n1| > |n2| (l'inverse du retour de la fonction compvalabs)
        for (int i = 0; i < MAXCHIFFRES; i++){ 
            if (n1.chiffres[i]-n2.chiffres[i] - retenue<0){ // Cas où la soustraction terme à termes est négative
                n3.chiffres[i] = 10 + n1.chiffres[i] - n2.chiffres[i] - retenue; // Ajout d'un report 
                retenue = 1; // Ajout de la retenue dans le prochain chiffre
            }
            else{ // Cas où la soustraction terme à terme est positive
                n3.chiffres[i]=n1.chiffres[i]-n2.chiffres[i] - retenue;
                retenue = 0;
            }
        }
        return n3; // Retour du resultat de la soustraction
    }    
    else {
        cout << "Impossible |n1| < |n2|";
        exit(1);
    }
}

/*Fonction sum : Addition de deux entiers longs de signes quelconques*/
t_EntierLong sum(t_EntierLong n1, t_EntierLong n2){
    t_EntierLong n3;
    if (EqualTest(n1,n2) && (n1.negatif != n2.negatif)){ // Verification de la proposition : |n1|=|n2| en appelant la fonction Test dans utilitaires.cpp
        for (int i=0; i<MAXCHIFFRES; i++){ 
            n3.chiffres[MAXCHIFFRES-i-1]=0; // Le resultat est nul
        }
        n3.negatif = false;
    }
    else {
        if (n1.negatif && n2.negatif){ // Cas ou n1 et n2 sont négatifs
        n3 = usum(n1,n2); // 
        n3.negatif = true;
        }
        if (not(n1.negatif) && not(n2.negatif)){ // Cas ou n1 et n2 sont positifs
            n3 = usum(n1,n2);// Somme n1 et n2
            n3.negatif = false; // n3 est positif car n1>0 et n2>0
        }
        if (n1.negatif && not(n2.negatif)){ // Cas ou n1 est négatif et n2 positif
            if (compvalabs(n1,n2)){ // Verifie si |n1| <= |n2|
                n3=usub(n2,n1); // Somme n1 et n2
                n3.negatif = false; // n3 est positif car |n1|<=|n2|, n1<0 et n2>0
            }
            else{
                n3=usub(n1,n2); // Somme n1 et n2
                n3.negatif = true;// n3 est negatif car |n1|>|n2|, n1<0 et n2>0
            }
        }
        if (not(n1.negatif) && n2.negatif){ // Cas ou n1 est positif et n2 négatif
            if (compvalabs(n1,n2)){// Verifie si |n1| <= |n2|
                n3=usub(n2,n1);
                n3.negatif = true; // n3 est negatif car |n1| <= |n2|, n1 > 0 et n2 < 0
            }
            else{
            n3=usub(n1,n2);
            n3.negatif = false; // n3 est positif car |n1| > |n2|, n1 > 0 et n2 < 0
            }
        }
    }     
    return n3;// Renvoie le resultat final
}

/*Fonction sub : Soustraction de deux entiers longs de signes quelconques*/
t_EntierLong sub(t_EntierLong n1, t_EntierLong n2){
    t_EntierLong n3;//Inititalisation du resultat
    for (int i = 0; i<MAXCHIFFRES; i++){
        n3.chiffres[i]=0; // Initialisation du resultat n1-n2 = n3
    } 
    if (FullTest(n1,n2)){ // Cas ou |n1|=|n2|
        if ((n1.negatif != n2.negatif)){ // Et n1 et n2 sont de signes différents 
            for (int i=0; i<MAXCHIFFRES; i++){
                n3.chiffres[i] = 0; // Le resultat est nul
            }
        }
        n3.negatif = false;
    }
    else {
        if (n1.negatif && n2.negatif){ // Cas ou n1 et n2 sont négatifs
            if (compvalabs(n1,n2)){ // Verifie si |n1|<=|n2|
                n3 = usub(n2,n1); // n1-n2 revient dans ce cas a faire |n2|-|n1| car n1<0 et n2<0
                n3.negatif = false; // n2-n1>0 car |n1|<=|n2|
            }
            else{
                n3 = usub(n1,n2); // n1-n2 revient dans ce cas a faire |n2|-|n1| car n1<0 et n2<0
                n3.negatif = true; // n2-n1<0 car |n1|>|n2|
            }
        }

        if (not(n1.negatif) && not(n2.negatif)){// Cas ou n1 et n2 sont positifs
            if (compvalabs(n1,n2)){// Verifie si |n1|<=|n2|
                n3 = usub(n2,n1);// n1-n2 revient dans ce cas a faire |n1|-|n2| car n1>0 et n2>0
                n3.negatif = true;// n1-n2<0 car |n1|<=|n2|
            }
            else{
                n3 = usub(n1,n2);// n1-n2 revient dans ce cas a faire |n1|-|n2| car n1>0 et n2>0
                n3.negatif = false;// n1-n2>0 car |n1|>|n2|
            }
        }
        
        if (n1.negatif && not(n2.negatif)) { // Cas ou n1<0 et n2>0
            n3 = usum(n1,n2);// n1-n2 revient dans ce cas a faire -(|n1|+|n2|) car n1<0 et n2>0
            n3.negatif = true;// -(|n1|+|n2|) < 0
        }

        if (not(n1.negatif) && n2.negatif){ // Cas ou n1>0 et n2<0
            n3 = usum(n1,n2);// n1-n2 revient dans ce cas a faire |n1|+|n2| car n1>0 et n2<0
            n3.negatif = false;// |n1|+|n2| > 0
        }
    } 
    return n3;// Renvoie le resultat final
}