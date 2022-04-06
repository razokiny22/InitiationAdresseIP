
#include <vector>
#include "Convertisseur.h"
#include "IPAddress.h"
class Menu{
    private :
        int choice;
        std::vector<std::string> options;
        int tailleOptoins;
        Convertisseur myConvertisseur;
        IPAddress myIPAddress;
    public :
        Menu();

        void getChoice();
        void manageChoice(bool& done);

};