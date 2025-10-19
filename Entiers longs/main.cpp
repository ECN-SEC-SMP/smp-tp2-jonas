#include <iostream>
#include "lit_ecrit.h"
#include "utilitaires.h"
#include "operations.h"
using namespace std;

int main(){
    t_EntierLong n2 = convertToLong(15);
    n2.negatif = false;
    t_EntierLong n1 = convertToLong(14);
    n1.negatif = true;
    cout << "n1 : ";
    afficheEntierLong(n1);
    cout << "n2 : ";
    afficheEntierLong(n2);
    cout << "|n1| <= |n2| ? : " << compvalabs(n1,n2) << endl;
    cout << "|n1| = |n2| ? : "<< EqualTest(n1,n2) << endl;
    cout << "|n1| = |n2| and sign(n1) = sign(n2) ? : "<< FullTest(n1,n2) << endl;
    cout << "n1 + n2 = ? : ";
    afficheEntierLong(sum(n1,n2));
    cout << "n1 - n2 = ? : ";
    afficheEntierLong(sub(n1,n2));
}
