#ifndef IPADDRESS_H
#define IPADDRESS_H
#include <vector>
#include "Address.h"
#include <string>
#include "Convertisseur.h"
class IPAddress : public Address{
    private :
        std::vector<int> octet;
        std::vector<std::string>options;
        std::vector<std::string>exercisesOptions;
        int tailleOptoins;
        Convertisseur myConvertisseur;
    public :
        IPAddress();

        void defineIPAddress();
        void learnMaskAddress();
        void learnClassIPAddress();
        void learnMagicNumber();
        void learnCIDR();
        void randomIPaddress(std::vector<int> address);
        void openFile(std::string file);
        void tableContent();
        void tableExercise();
        void exercisesClasseIP();
        void exercisesCIDR();
};
#endif