#ifndef CONVERTISSEUR_H
#define CONVERTISSEUR_H
#include <vector>
#include <cmath>
class Convertisseur{
    private : 
// qui contiendra la valeur decimale
        int decimal;
// qui contiendra la valeur binaire qu'on contiendra dans un tableau 
        std::vector <int> binary;
// ce tableau contiendra les puissance de deux de 0 a 7 puisqu'on travaille en 8bits
        std::vector<int>puissanceDeDeux;
    public : 
        Convertisseur();

// pour apprendre a convertir du binaire en decimal
        void learnBinaryToDecimal();
// pour apprendre a convertir un nombre a base decimal en binaire
        void learnDecimalToBinary();

//ce Tableau nous sera utile au cours de l'apprentissage
        void afficheTableau();


//pour convertir un nombre binaire en nombre a base decimal
        int toDecimal(std::vector<int>binaire);
//pour convertir un nombre a base decimal en binare
        int* toBinary(int octet);
        
// cette methode nous est utile pour generer un nombre aleatoire dans un intervall
        int randomNumber(int min, int max);
        void exercisesBinaryToDecimal();
        void exercisesDecimalToBinary();
};
#endif

