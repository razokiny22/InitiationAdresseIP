#include "Address.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>

Address::Address()
{
    // L'APIPA fourni une adresse IP  provisoire de la forme : 169.254. . si le DHCP n'est pas encore active
    octet.push_back(169);
    octet.push_back(254);
    octet.push_back(3);
    octet.push_back(255);

}

// cette methode va nous permettre de stocker l'adresse IP entrer par l'utilisateur
void Address::getIPAddress(){
  std::vector <int> octet;
    int temp;
    int j(0);
    char str[255];
    char* p;
    std::cout << "Entrez votre reponse : ";
    std::cin >> str;
//on va prendre la valeur pour chaque octet
    p = strtok(str,".");
    while(p!= NULL){
// cette methode prendre chaque octet et le transformer en int
        std::stringstream ss;
        ss << p;
        ss >> temp;
        octet.push_back(temp);
        p = strtok(NULL, ".");
    }
    setIPAdress(octet[j],octet[j+1],octet[j+2],octet[j+3]);
    
}
// un getteur du vecteur octet
int* Address::getOctet(){
    int *p = new int[8];
    for(int i(0) ; i<4 ; i++){
        p[i]=octet[i];
    }
    return p;

}