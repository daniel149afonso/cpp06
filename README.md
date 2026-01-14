📘 CPP Module 06 – README
🎯 Objectif du module

Le module cpp06 a pour but de comprendre :

- les conversions de types

- le cast en C++

- le polymorphisme à l’exécution

- la différence entre type statique et type dynamique

- la manipulation bas niveau des pointeurs

🟦 EX00 – Scalar Conversion
🔹 Objectif

Convertir une chaîne de caractères en :

char, int, float, double

En gérant :

nan, nanf, +inf, -inf, +inff, -inff

les erreurs (impossible)

les caractères non affichables

🔹 Définitions importantes
std::strtod
```bash
double strtod(const char* str, char** endptr);
```

- Convertit une string en double

- endptr pointe vers le premier caractère non converti

- Permet de détecter les erreurs, caractères restants et overflows

🟦 EX01 – Serializer
🔹 Objectif

Convertir un pointeur en un entier, puis revenir au pointeur original.

⚠️ Ce n’est PAS une vraie sérialisation.

🔹 uintptr_t

Type entier garanti assez grand pour stocker une adresse

- reinterpret_cast: est un cast C++ qui permet de réinterpréter les bits d’une valeur comme un autre type, sans aucune conversion réelle.

static_cast	conversions numériques	❌ ici
dynamic_cast	héritage polymorphe	❌
const_cast	retirer const	❌
reinterpret_cast	réinterprétation brute	✅ ex01

🟦 EX02 – Identify real type

## Principe clé
L’identification repose sur le **polymorphisme à l’exécution**.

La classe `Base` possède un **destructeur virtuel**, ce qui permet au programme
de connaître le type réel de l’objet à l’exécution.

- dynamic_cast: permet de vérifier à l’exécution le type réel d’un objet
polymorphe.