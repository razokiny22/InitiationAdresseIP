#include <iostream>
#include "Menu.h"
#include <vector>
#include <string>
#include <cctype>
using namespace std;


Menu::Menu() : choice(-1) 
{
    options.push_back("1-Apprendre a convertir un nombre a base decimal en binaire (8bits)");
    options.push_back("2-Apprendre a convertir un binaire (8bits) en nombre a base decimal");
    options.push_back("3-Apprendre la notion d'adresse IP");
    options.push_back("4-Passer aux exercices");
    options.push_back("0-Pour quitter le progamme ");

    tailleOptoins = options.size();
}

void Menu::getChoice()
{
    choice = -1;
    string str;
    while(choice<0 || choice > 5)
    {
        cout << "Tapez :" << endl;
        for(int i(0); i< tailleOptoins; i++)
            cout << "\t" << options[i] << endl;
        cout << "Votre choix SVP : ";
        cin >> str;
// on verifie que l'entree est bien un nombre
        if(isdigit(str[0])){
            choice = stoi(str);
        }

    }
    
 }
 void Menu::manageChoice(bool& done)
 {
     switch(choice){
        case 1: myConvertisseur.learnDecimalToBinary();
                break;
        case 2: myConvertisseur.learnBinaryToDecimal();
                break;
        case 3: myIPAddress.tableContent();
                break;
        case 4: myIPAddress.tableExercise();
                break;
        case 0: done = true;
                break;
        
     }
 }