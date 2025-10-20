# Rapport TP2 - Jonas Maouche

# utilitaires.cpp

## 1) t_EntierLong convertToLong(int n)

- **Spécification :**
    - **Rôle :** Convertit un entier natif de type `int` en un `t_EntierLong`.
    - **Paramètres :** `int n` - l'entier à convertir.
    - **Retour :** Le `t_EntierLong` représentant `n`.
- **Principe de mise en œuvre :**
    1. Le signe de `n` est déterminé et stocké dans `nlong.negatif`.
    2. La fonction itère pour extraire chaque chiffre de `n` en utilisant l'opérateur modulo (`% 10`) et la division entière (`/ 10`).
    3. Les chiffres sont stockés dans le tableau `chiffres` de la structure, de l'indice 0 (unités) vers les indices supérieurs (dizaines, centaines...).
- Code : 
``` c++
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
        temp =  n % 10;         // Prendre la dernière decimale de n
        nlong.chiffres[i] = temp; // On associe le tableau d'indice i au resultat du modulo
        n = n/10; //on divise par 10 pour prendre prendre la prochaine decimale
    }
    return nlong;
};
```

## 2) bool EqualTest(t_EntierLong a, t_EntierLong b)

- **Spécification :**
    - **Rôle :** Vérifie si deux `t_EntierLong` ont la même valeur absolue (`|a| == |b|`).
    - **Paramètres :** `t_EntierLong a`, `t_EntierLong b`.
    - **Retour :** `true` si les valeurs absolues sont égales, `false` sinon.
- **Principe de mise en œuvre :** La fonction parcourt entièrement les deux tableaux `chiffres` et compare chaque élément. Le booléen `iseq` est mis à `false` si une différence est trouvée.
- **Code** :
``` c++
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
```

## 3) bool FullTest(t_EntierLong n1, t_EntierLong n2)

- **Spécification :**
    - **Rôle :** Vérifie si deux `t_EntierLong` sont strictement égaux `|n1|=|n2|` et que `sign(n1) = sign(n2)`.
    - **Paramètres :** `t_EntierLong n1`, `t_EntierLong n2`.
    - **Retour :** `true` si la vérification est vraie (`|n1|=|n2| et sign(n1) = sign(n2)`), `false` sinon.
- **Principe de mise en œuvre :** Vérifie d'abord l'égalité des signes. Si les signes sont identiques, la fonction compare ensuite chaque chiffre des deux nombres.
- **Code** :
```c++
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
```
## 4) bool compvalabs(t_EntierLong n1, t_EntierLong n2)

- **Spécification :**
    - **Rôle :** Compare les valeurs absolues de deux `t_EntierLong` et détermine si `|n1| <= |n2|`.
    - **Paramètres :** `t_EntierLong n1`, `t_EntierLong n2`.
    - **Retour :** `true` si `|n1| <= |n2|`, `false` sinon.
- **Principe de mise en œuvre :** La fonction vérifie terme a terme, en partant du chiffres le plus significatif au moins significatif, si la proposition `|n1| <=|n2|` est vrai
- **Code :**
```c++
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
```
# operations.cpp


## 1) t_EntierLong usum(t_EntierLong n1, t_EntierLong n2)

- **Spécification :**
    - **Rôle :** Calcule la somme des valeurs absolues de deux entiers longs (`|n1| + |n2|`). Précondition : `n1` et `n2` sont supposés de même signe par la fonction appelante.
    - **Paramètres :** `t_EntierLong n1`, `t_EntierLong n2`.
    - **Retour :** Le `t_EntierLong` résultant de l'addition, avec un signe positif.
- **Principe de mise en œuvre :** Implémente l'addition "scolaire" chiffre par chiffre avec une retenue.
    1. Initialise une retenue à 0 et le `t_EntierLong` résultat à zéro.
    2. Itère sur chaque indice `i` du tableau `chiffres`.
    3. Calcule `somme = n1.chiffres[i] + n2.chiffres[i] + retenue`.
    4. Le nouveau chiffre est `somme % 10`.
    5. La nouvelle retenue est `somme / 10`.
- **Code :**
```c++
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
```

## 2) t_EntierLong usub(t_EntierLong n1, t_EntierLong n2

- **Spécification :**
    - **Rôle :** Calcule la différence des valeurs absolues `|n1| - |n2|`.
    - **Précondition :** `|n1| >= |n2|`.
    - **Paramètres :** `t_EntierLong n1`, `t_EntierLong n2`.
    - **Retour :** Le `t_EntierLong` résultant de la soustraction, avec un signe positif.
- **Principe de mise en œuvre :** Implémente la soustraction "scolaire" avec retenue (emprunt).
    1. Gère le cas `|n1| == |n2|` où le résultat est 0.
    2. Vérifie la précondition `|n1| >= |n2|`. Si elle n'est pas respectée, le programme s'arrête.
    3. Itère sur chaque indice `i`, en calculant `diff = n1.chiffres[i] - n2.chiffres[i] - retenue`.
    4. Si `diff` est négatif, on "emprunte" à la colonne suivante : le chiffre résultat est `diff + 10` et la retenue pour le prochain calcul passe à 1. Sinon, le chiffre est `diff` et la retenue est 0.
- **Code : **
```c++
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
```

## 3) t_EntierLong sum(t_EntierLong n1, t_EntierLong n2

- **Spécification :**
    - **Rôle :** Calcule la somme de deux entiers longs de signes quelconques (`n1 + n2`).
    - **Paramètres :** `t_EntierLong n1`, `t_EntierLong n2`.
    - **Retour :** Le `t_EntierLong` résultant de `n1 + n2`.
- **Principe de mise en œuvre :** La fonction se ramène aux opérations `usum` et `usub` en fonction des signes :
    - **Signes identiques (`a+b` ou `-a-b`) :** Le résultat est `usum(n1, n2)` avec le signe commun.
    - **Signes différents (`a-b` ou `-a+b`) :**
        - On compare les valeurs absolues avec `compvalabs`.
        - Le calcul est `usub(plus_grand_en_abs, plus_petit_en_abs)`.
        - Le signe du résultat est celui du nombre qui avait la plus grande valeur absolue.
- **Code :**
```c++
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
```

## 4) t_EntierLong sub(t_EntierLong n1, t_EntierLong n2)

- **Spécification :**
    - **Rôle :** Calcule la différence de deux entiers longs de signes quelconques (`n1 - n2`).
    - **Paramètres :** `t_EntierLong n1`, `t_EntierLong n2`.
    - **Retour :** Le `t_EntierLong` résultant de `n1 - n2`.
- **Principe de mise en œuvre :** L'implémentation actuelle est très similaire à `sum`, avec une logique complexe pour chaque combinaison de signes. Une approche beaucoup plus simple et robuste consiste à transformer la soustraction en addition : `n1 - n2` est équivalent à `n1 + (-n2)`. Il suffit d'inverser le signe de `n2` et d'appeler la fonction `usum`.
- **Code :**
```c++
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
```

---

