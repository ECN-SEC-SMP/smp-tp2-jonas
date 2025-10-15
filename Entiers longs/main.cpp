#include <iostream>
#include "lit_ecrit.h"
#include "utilitaires.h"
using namespace std;

int main(){
    // obtenir la valeur et l'afficher proprement
    t_EntierLong v = convertToLong(54989890);
    cout << "Convert: ";
    afficheEntierLong(v); // utilise la fonction fournie pour afficher
    return 0;
    
}
