#include <algorithm>
#include <iostream>
#include <list>
#include "morpion.cpp"
using namespace std;



int main() {
    cout<<<<"\n";
    cout<<"|a1|a2|a3|"<<"\n";
    cout<<"|b1|b2|b3|"<<"\n";
    cout<<"|c1|c2|c3|"<<"\n";
    cout<<"\n\n\n"<<endl;
    Morpion m;
    m.begin();
    

    m.affichage();
    m.update();
	
}
