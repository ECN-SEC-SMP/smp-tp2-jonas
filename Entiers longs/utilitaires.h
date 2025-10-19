#include "lit_ecrit.h"
#include "entierlong.h"

/*Fonction convertToLong : convertit un entier standard en entier long*/
t_EntierLong convertToLong(int n);
/*Fonction FullTest : vérifie si |n1|=|n2| et que n1 et n2 soient de même signe */
bool FullTest(t_EntierLong a, t_EntierLong b);
/*Fonction compvalabs : compare en valeur absolue deux entiers longs n1 et n2 : |n1| <= |n2|*/
bool compvalabs(t_EntierLong n1, t_EntierLong n2);
/*Fonction EqualTest : verifie si |n1|=|n2| */
bool EqualTest(t_EntierLong a , t_EntierLong b);