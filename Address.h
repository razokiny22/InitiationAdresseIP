#ifndef ADDRESS_H
#define ADDRESS_H
#include <vector>
#include "Convertisseur.h"
class Address{
    private :
        std::vector<int> octet;
        std::vector<int> binaire;
        Convertisseur myConvertisseur;
    public :
        Address();
        

       
        void setIPAdress(int octet1,int octet2,int octet3, int octet4);
        void getIPAddress();
        int * getOctet();
        

};
#endif