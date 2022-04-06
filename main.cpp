#include <iostream>
#include <ctype.h>
#include "Menu.h"
using namespace std;

int main()
{
   cout << "Ce programme vous aidera a vous initier dans la notion d'adresse IP" << endl;
   srand(time(NULL));
   bool done = false;
   Menu myMenu;
   while(!done){
       myMenu.getChoice();
       myMenu.manageChoice(done);
   }
    return 0;
}
