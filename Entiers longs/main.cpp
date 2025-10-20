#include <iostream>
#include "lit_ecrit.h"
#include "utilitaires.h"
#include "operations.h"
using namespace std;

int main(){
  cout << "========================================" << endl;
    cout << "        Section 1: Tests de base" << endl;
    cout << "========================================" << endl;
    t_EntierLong n2 = convertToLong(150);
    n2.negatif = false;
    t_EntierLong n1 = convertToLong(134);
    n1.negatif = true;
    cout << "n1 : ";
    afficheEntierLong(n1);
    cout << "n2 : ";
    afficheEntierLong(n2);
    // Execution des tests des fonctions dans utilitaires.cpp
    cout << "|n1| <= |n2| ? : " << compvalabs(n1,n2) << endl;
    cout << "|n1| = |n2| ? : "<< EqualTest(n1,n2) << endl;
    cout << "|n1| = |n2| and sign(n1) = sign(n2) ? : "<< FullTest(n1,n2) << endl;
    cout << "n1 + n2 = ? (-134 + 150) : ";
    afficheEntierLong(sum(n1,n2));
    cout << "n1 - n2 = ? (-134 - 150) : ";
    afficheEntierLong(sub(n1,n2));
    
    cout << "\n========================================" << endl;
    cout << "     Section 2: Exemples simples" << endl;
    cout << "========================================" << endl;

    // Test 1: Addition simple avec retenue
    t_EntierLong ex1a = convertToLong(999);
    t_EntierLong ex1b = convertToLong(1);
    cout << "Exemple 1: 999 + 1 = ";
    afficheEntierLong(sum(ex1a, ex1b));

    // Test 2: Soustraction simple avec "emprunt"
    t_EntierLong ex2a = convertToLong(10000);
    t_EntierLong ex2b = convertToLong(1);
    cout << "Exemple 2: 10000 - 1 = ";
    afficheEntierLong(sub(ex2a, ex2b));

    // Test 3: Soustraction résultant en un nombre négatif
    t_EntierLong ex3a = convertToLong(123);
    t_EntierLong ex3b = convertToLong(456);
    cout << "Exemple 3: 123 - 456 = ";
    afficheEntierLong(sub(ex3a, ex3b));

    // Test 4: Addition de signes mixtes
    t_EntierLong ex4a = convertToLong(500);
    ex4a.negatif = true; // -500
    t_EntierLong ex4b = convertToLong(200);
    cout << "Exemple 4: -500 + 200 = ";
    afficheEntierLong(sum(ex4a, ex4b));
    

    cout << "\n================================================================" << endl;
    cout << "     Section 3: Calcule des termes de la suite de Fibonacci" << endl;
    cout << "================================================================" << endl;

    // Initialisation des deux premiers termes
    t_EntierLong fib_a = convertToLong(0); // F(0)
    t_EntierLong fib_b = convertToLong(1); // F(1)
    t_EntierLong fib_c; // Pour stocker le terme suivant F(n) = F(n-1) + F(n-2)
    t_EntierLong u59;
    t_EntierLong u58;
    t_EntierLong u60;
    // Affichage des termes de départ
    cout << "F(0) = ";
    afficheEntierLong(fib_a);
    cout << "F(1) = ";
    afficheEntierLong(fib_b);

    // Boucle pour calculer et afficher les termes suivants
    for (int i = 2; i <= 20001; i++) {
        // Le nouveau terme est la somme des deux précédents
        fib_c = sum(fib_a, fib_b);
        if (i <= 60){
            // Affichage du terme calcule
            cout << "F(" << i << ") = ";
            afficheEntierLong(fib_c);
        }
        if (i == 20000  ){ // Affichage du 20 000eme terme
                cout << "\n=======================================================================" << endl;
                cout << "     Section 4: Calcule du 20 000eme terme de la suite de Fibonacci" << endl;
                cout << "=======================================================================" << endl;
            cout << "F(" << i << ") = ";
            afficheEntierLong(fib_c);
        }
        if (i == 60){ // Recuperation des valeurs a verifier
            u59 = fib_b;
            u58 = fib_a;
            u60 = fib_c;
        }
        

        // Mise à jour pour la prochaine iteration
        fib_a = fib_b; // L'ancien F(n-1) devient le nouveau F(n-2)
        fib_b = fib_c; // Le F(n) calculé devient le nouveau F(n-1)
    }

    cout << "\n===========================================================================" << endl;
    cout << "     Section 5: Verification du 60eme terme de la suite de Fibonacci" << endl;
    cout << "===========================================================================" << endl;

    t_EntierLong verif;
    verif = sub(u60,u59); // On applique la soustraction u60 - u59
    if (EqualTest(verif,u58)){ // On verifie si la soustraction est correcte
        cout << "La verification est un succes !"<<endl;
    }
    else{
        cout << "Il y a une erreur quelque part."<<endl;
    }
    return 0;
}

