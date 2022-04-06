#include "IPAddress.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>


IPAddress::IPAddress()
{
    // L'APIPA fourni une adresse IP  provisoire de la forme : 169.254. . si le DHCP n'est pas encore active
    octet.push_back(169);
    octet.push_back(254);
    octet.push_back(3);
    octet.push_back(255);
    //option dans l'apprentissage
    options.push_back("1-Definition d'une adresse IP");
    options.push_back("2-Les adresse masque");
    options.push_back("3-Notion de CIDR");
    options.push_back("4-Nombre magique");
    options.push_back("5-Les differente classe d'adresse IP");
    options.push_back("0-Revenir au menu principal");
    tailleOptoins = options.size();
    //option dans les exercices
    exercisesOptions.push_back("1-S'exercer dans la conversion d'un nombre binaire en nombre a base decimal");
    exercisesOptions.push_back("2-S'exercer dans la conversion d'un nombre a base decimal en nombre binaire (8bits)");
    exercisesOptions.push_back("3-Excercie sur la notion de CIDR");
    exercisesOptions.push_back("4-Excercie sur les classes d'adresse IP");
    exercisesOptions.push_back("0-Revenir au menu principal");
    

}
void IPAddress::openFile(std::string File){
    std::ifstream inFile;
    std::string line;
    inFile.open(File);
    if(inFile){
        while(std::getline(inFile,line))
            std::cout << line <<std::endl;
    }
    else{
        std::cout << "Erreur sur l'ouverture du fichier"<< std::endl;
    }
    inFile.close();
  
  
}

void IPAddress::learnClassIPAddress(){
    openFile("fichier/class.txt");
}
void IPAddress::defineIPAddress(){
    openFile("fichier/defineIPAddress.txt");
}
void IPAddress::learnMaskAddress(){
    openFile("fichier/maskAddress.txt");
}
void IPAddress::learnMagicNumber(){
    openFile("fichier/magicNumber.txt");
}
void IPAddress::learnCIDR(){
    openFile("fichier/notationCIDR.txt");
}
void IPAddress::tableContent(){ 
    bool done(false);
    int choice(0);
    while(!done){
        choice = -1;
        std::string str;
        while(choice<0 || choice > 6 ){
        std::cout << "\n\n\tTapez :" << std::endl;
            for(int i(0); i< tailleOptoins; i++)
                std::cout << "\t\t" << options[i] << std::endl;
            std::cout << "\tVotre choix SVP : ";
            std::cin >> str;
        if(isdigit(str[0])){
            choice = stoi(str);
        }

    }

    switch(choice){
        case 1 :  defineIPAddress();
                  break;
        case 2 :  learnMaskAddress();
                  break;
        case 3 :  learnCIDR(); 
                  break;
        case 4:   learnMagicNumber();
                  break;
        case 5:   learnClassIPAddress();
                  break;
        case 0  : done =true;
                  break; 
        }
    }
}
void IPAddress::exercisesCIDR(){
    std::cout << "\n\n**************************************************************************************\n\n";
    std::vector<int>trueAnswer;
    int *userAnswer;
    int tab[32];
    std::vector<int>temp;
    int temporaire;
    int j(0);
    temporaire = myConvertisseur.randomNumber(1,32);
    std::cout << "Entrer l'adresse masque (X.X.X.X) correspondant a : /" << temporaire << std::endl;
// on utilisera cette algorithme pour trouver la reponse a la question
     for(int i(0); i<32 ; i++){
        if(i<temporaire)
            tab[i]=1;
        else
            tab[i]=0;
        
    }
   
    for(int i(0); i<4 ; i++){
// on utilisera cette index pour pouvoir pacourir tab octet par octet
        int k = 8*i;
        for(int j(k); j<(k+8) ; j++){
// on va prendre les valeurs binaire octet par octet
            temp.push_back(tab[j]);
            
        }
// on va mettre la valeur deja converti dans le tableu bonne reponse
        trueAnswer.push_back(myConvertisseur.toDecimal(temp));
        temp.clear();
    }
    getIPAddress();
    userAnswer = getOctet();
    
    for(j=0; userAnswer[j]==trueAnswer[j] && j<4 ; j++);
    if(j==4){
       
        std::cout << "Vous avez trouve la bonne reponse!" << std::endl;
    }else{
        std::cout << "Mauvaise reponse!, le cours sur la notion de CIDR vous aidera mieux a comprendre la methode a suivre" << std::endl;

    }
     std::cout << "\n\n**************************************************************************************\n\n";
}

void IPAddress::randomIPaddress(std::vector<int>adresse){
    
    
}

void IPAddress::exercisesClasseIP(){
     std::cout << "\n\n**************************************************************************************\n\n";
    int temporaire(0);
    std::vector<int>adresseIPTemporaire;
    std::string userAnswer;
    std::string trueAnswer;
    std::cout << "Choisissez parmi les choix ci-dessous la classe de cet adresse IP : ";
// on va generer un adresseIP au hasard
    for(int i(0); i<4 ; i++){
        temporaire = myConvertisseur.randomNumber(0,255);
        adresseIPTemporaire.push_back(temporaire);
        std::cout << adresseIPTemporaire[i];
        if(i<3){
            std::cout << ".";
        }
        
    }
        
    
    std::cout << "\nA.Classe A\tB.Classe B\tC.classe C\tD.ClasseD\tE.Classe E\n->";
    std::cin >> userAnswer;
//pour verifier la classe on va juste voir le premier octet et le comparer dans le tabkeau dans le cours   
    if(adresseIPTemporaire[0]>=0 && adresseIPTemporaire[0]<=126){
            trueAnswer = "A";
            
    }else if(adresseIPTemporaire[0]>=128 && adresseIPTemporaire[0]<=191){
                trueAnswer = "B";
            
        }else if(adresseIPTemporaire[0]>=192 && adresseIPTemporaire[0]<=223){
                    trueAnswer = "C";
                
            }else if(adresseIPTemporaire[0]>=224 && adresseIPTemporaire[0]<=239){
                        trueAnswer = "D";
                        
                }else if(adresseIPTemporaire[0]>=240 && adresseIPTemporaire[0]<=255){
                         trueAnswer ="E";
                        }
                           
                            
                     
    if(userAnswer==trueAnswer){
        std::cout << "Vous avez trouve la reponse!" << std::endl;
    }
    else{
        std::cout <<"Mauvaise reponse! le cours sur les differente classes IP vous aidera mieux a comprendre la methode a suivre";
    } 

     std::cout << "\n\n**************************************************************************************\n\n";
           
}


void IPAddress::tableExercise(){ 
    bool done(false);
    int choice(0);
    int tailleOption = exercisesOptions.size();
    while(!done){
        choice = -1;
        std::string str;
        while(choice<0 || choice > 6 ){
        std::cout << "\n\n\tTapez :" << std::endl;
            for(int i(0); i< tailleOption; i++)
                std::cout << "\t\t" << exercisesOptions[i] << std::endl;
            std::cout << "\tVotre choix SVP : "; 
// on va verifier si l'entree est bien un entier
            std::cin >> str;
        if(isdigit(str[0])){
            choice = stoi(str);
        }

    }

    switch(choice){
        case 1  : myConvertisseur.exercisesBinaryToDecimal();
                  break;
        case 2  : myConvertisseur.exercisesDecimalToBinary();
                  break;
        case 3 :  exercisesCIDR();
                  break;
        case 4 :  exercisesClasseIP();
                  break;       
        
        case 0  : done =true;
                  break; 
        }
    }
}

