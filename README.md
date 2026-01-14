# cpp06

## ex00
strtof, strtod ...etc
Ligne						Rôle
stringstream ss(str);	prépare la conversion
ss >> nb;				convertit
ss.fail()				vérifie erreur
!ss.eof()				refuse les caractères en trop

## ex01

- reinterpret_cast: est un cast C++ qui permet de réinterpréter les bits d’une valeur comme un autre type, sans aucune conversion réelle.

static_cast	conversions numériques	❌ ici
dynamic_cast	héritage polymorphe	❌
const_cast	retirer const	❌
reinterpret_cast	réinterprétation brute	✅ ex01