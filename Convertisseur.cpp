#include "Convertisseur.h"
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
// Constructeur
Convertisseur::Convertisseur(){
    decimal = 0;
// on declare une valeur temporaire pour le push_back
    int temp(0);
// on va travailles dans un systeme octet c'est a dire 8 bits

// On va générer des valeur aléatoire de 0 et 1 pour avoir un nombre binaire aléatore
    for(int i(0); i<8 ; i++){

        binary.push_back(0);

// on affecte la valeur de 2^7 dans la premiere case du tableau et ainsi de suite jusqu'à 2^0
        temp=pow(2,7-i);
        puissanceDeDeux.push_back(temp);
       
        
    }

}
void Convertisseur::afficheTableau(){
    for (int i(0); i<8 ; i++){
         std::cout << puissanceDeDeux[i] << "\t";
    }
    std::cout <<"\n------------------------------------------------------------\n";
     for(int i(0); i<8 ; i++){
        std::cout<< binary[i] << "\t";
    }
    
}

int Convertisseur::randomNumber(int min,int max){
    int num(0);
    int range(0);
// pour determiner l'amplitude de l'intervalle
    range = max - min + 1;
// pour generer un nombre dans cette intervalle
    num = (rand() % range) + min;
    return num;

}


void Convertisseur::learnBinaryToDecimal(){
    std::cout << "**************************************************************************************************\n";
    std::cout << "Dans ce cours, nous allons apprendre a convertir un nombre a base decimal en binaire " << std::endl;
// prenons un nombre binaire au hasard
    std::cout << "\n\nPrenons par exemple le binaire suivant : ";
    for(int i(0) ; i<8 ; i++){
         binary[i]=randomNumber(0,1);
         std::cout << binary[i];
    }
    std::cout << "\n\nPlacons ce nombre binaire dans un tabeau de puissance de deux en respectant cet ordre\n\n";
       


    int temporaire(0);
    afficheTableau();
    
    std::cout << "\n\nPour convertir un nombre binaire en decimal en fait la somme du produit de chaque colone du colone ci-dessus"<< std::endl;
    std::cout << "nombreDecimal = ";
    for (int i(0); i<8 ; i++){
// pour affichage du methode de convertion
        std::cout << puissanceDeDeux[i] << " * " << binary[i] ;
// pour ne pas affiche signe + a la fin 
        if(i<7){
            std::cout << " + ";
        }
// pour la converstion
        temporaire += puissanceDeDeux[i]*binary[i];
    }

    std::cout << "\nnombreDecimal = " << temporaire << std::endl;
    std::cout << "**************************************************************************************************\n";
}

void Convertisseur::learnDecimalToBinary(){
    std::cout << "**************************************************************************************************\n";
       
    std::cout << "Bienvenue, dans ce cours nous allons apprendre a convertir un nombre a base decimal en binaire"<< std::endl;
    int decimalNumber(0);
    decimalNumber = randomNumber(0,255);
    std::cout << "Prenons un tableau initial"<< std::endl;
    for(int i(0); i<8 ; i++)
        binary[i]=0;
    afficheTableau();

    std::cout << "\n\nPour convertir un nombre a base decimal en binaire, il suffit de soustraire le nombre par \nla puissance de deux la plus proche et inferieur a lui"<< std::endl;
    std::cout << "\n\nPuis remplacer par 1 la valeur du puissance de deux utilisee dans le tableau ce-dessus\n\n"<< std::endl;
    std::cout << "Par exemple pour "<< decimalNumber << " on fait l'operation :" << std::endl;
    
    for(int i(0);i<8;i++)
    {
        if(decimalNumber >= puissanceDeDeux[i] )
        {
            int temp =decimalNumber;
            decimalNumber -= puissanceDeDeux[i];
             std::cout <<"\n" <<  temp << " - " << puissanceDeDeux[i] << " = " << decimalNumber << std::endl;
            binary[i]= 1;
        }
        else if(decimalNumber!=0){
                std::cout << "\ncomme " << puissanceDeDeux[i] << " est superieure a "<< decimalNumber << " on passe a "<< puissanceDeDeux[i+1]<< std::endl;
                binary[i] = 0;
        }   
             else{
                binary[i] = 0;
             }
    }
    
    std::cout << "On obtient ainsi le tableau suivant" << std::endl;
    afficheTableau();
    std::cout << "\n\nOn obtient ainsi le binaire  : ";
    
    for(int i(0);i<8;i++){
         std::cout << binary[i];
    }
       
    std::cout<< std::endl;
    std::cout << "**************************************************************************************************\n";
}

int* Convertisseur::toBinary(int octet)
{
    int *pBinary = new int[8];
    for(int i(0);i<8;i++)
    {
        if(octet >= puissanceDeDeux[i] )
        {
            octet -= puissanceDeDeux[i];
            *(pBinary+i)= 1;
        }
        else{
            *(pBinary+i)=0;
        }
    }
    
    return pBinary;
}
int Convertisseur::toDecimal(std::vector<int> binaryNumber){
    int temporaire(0);
    for(int i(0); i<8 ; i++){
        temporaire += puissanceDeDeux[i] * binaryNumber[i];
    }
    return temporaire;
}

void Convertisseur::exercisesBinaryToDecimal(){
    int userAnswer(0);
    std::string str;
    int strLength(0);
    int i(0);
    std::cout << "Converitssez le nombre binaire (8bits) suivant en nombre a base decimal : ";
// pour generer aleatoirement un nombre binaire 8bits
     for(int i(0) ; i<8 ; i++){
         binary[i]=randomNumber(0,1);
         std::cout << binary[i];
    }

    std::cout << "\n->";
    std::cin  >> str;
    strLength = str.size();
// pour s'assurer que l'entrer est bien un entier
    while(i<strLength){
        if(isdigit(str[i])){
            i++;
        }
        else{
            std::cout <<"veillez entrer un nombre \n ->";
            std::cin >> str;
            strLength = str.size();
            i=0;
        }

    }
    userAnswer = stoi(str);
    if(userAnswer==toDecimal(binary)){
        std::cout << "Vous avez trouve la bonne reponse !" << std::endl;
    }
    else{
        std::cout << "Mauvaise reponse! le cours vous aidera mieux a comprendre les methodes a suivre"<< std::endl;
    }
}
void Convertisseur::exercisesDecimalToBinary(){
    int j(0);
// ce temporaire contiendra le nombre decimal generer aleatoirement
    int temporaire(0);
// on va stocker la reponse de l'utilisateur dans un tableau
    std::vector<int>userAnswer;

// ce pointeur prendra la vraie reponse en convertissant le decimal generer aleatoirelent
    int * trueAnswer = nullptr;

// on va stocker provisoirement l'entrer dans un string pour verifier si c'est vraiment un nombre a base decimal
    std::string str;
    int i(0);

    temporaire = randomNumber(0,255);
    trueAnswer = toBinary(temporaire);
 

    std::cout << "Converitssez en binaire le nombre a base decimal suivant :" << temporaire << std::endl;
    std::cout << "\n->";
    std::cin  >> str;
    int strLength = str.size();
    while(i<strLength){
        if(isdigit(str[i])){
// si c'est un nombre on va entrer le chiffre 0 ou 1 dans la reponse de l'utilisateur
// pour convertir le caractere en int en va utilisier la methode par "casting"
// Dans la table ASCII la valeur int de chiffre 0-9 commence par 48
//c'est-a-dire on ASCII '0' vaut 48 et '1' vaut 49
            userAnswer.push_back(str[i] - 48);
            i++;
        }
        else{
          
// on recommence si le l'utilisateur fait un erreur d'entree
            std::cout <<"veillez entrer un nombre \n ->";
            std::cin >> str;
            strLength = str.size();
            userAnswer.clear();
            i=0;
        }
    }
     
      
// maintenant on va verifier si l'utilisateur a trouver la bonne reponse
    for(j=0; userAnswer[j]==trueAnswer[j] && j<8 ; j++);
// si chaque des deux tableau sont identique
    if(j==8){
        std::cout << "Vous avez trouve la bonne reponse" << std::endl;
    }
    else{
        std::cout << "Mauvaise reponse, le cours vous aidera mieux a comprendre les methodes a suivre"<<std::endl;
    }
}