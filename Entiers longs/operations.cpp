#include <iostream>
#include "entierlong.h"
using namespace std;


t_EntierLong usum(t_EntierLong a, t_EntierLong b){
    t_EntierLong c; // Initialisation du resultat a+b = c
    for (int i = 0; i<MAXCHIFFRES; i++){ // On somme termes a termes les chiffres
        if (a.chiffres[MAXCHIFFRES-i]+b.chiffres[MAXCHIFFRES-i] > 9){ // Cas ou la somme est sup à 10
            c.chiffres[MAXCHIFFRES-i+1]++; // Ajoute 1 en retenue 
            c.chiffres[MAXCHIFFRES-i] = (a.chiffres[MAXCHIFFRES-i]+b.chiffres[MAXCHIFFRES-i]) % 10; // Ajoute l'unité dans c
        } 
        else { // Le cas plus simple il n'y a pas de retenue
            c.chiffres[MAXCHIFFRES- i ] = a.chiffres[MAXCHIFFRES-i]+b.chiffres[MAXCHIFFRES-i];
        }
    }
    return c;
}

