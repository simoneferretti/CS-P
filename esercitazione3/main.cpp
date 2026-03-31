#include <iostream>
#include "rational.hpp"


int main() {
    std::cout << "Inserisci il numeratore della prima frazione: \n";
    int num1_;
    std::cin >> num1_;

    std::cout << "Inserisci il denominatore della prima frazione: \n";
    int den1_;
    std::cin >> den1_; 
	
	rational<int> f1(num1_, den1_);
	int nf1 = f1.num();
	int df1 = f1.den();
	std::cout << "Il numeratore è " << nf1 << ", il denominatore è " << df1 << "\n";
		std::cout << "Stampa con operatore<<: "<< f1 << "\n";


    std::cout << "Inserisci il numeratore della seconda frazione: \n";
    int num2_;
    std::cin >> num2_;

    std::cout << "Inserisci il denominatore della seconda frazione: \n";
    int den2_;
    std::cin >> den2_; 
	
	rational<int> f2(num2_,den2_);
	int nf2 = f2.num();
	int df2 = f2.den();
	std::cout << "Il numeratore è " << nf2 << ", il denominatore è " << df2 << "\n";
	std::cout << "Stampa con operatore<<: " << f2 << "\n";
	
	rational<int> somma = f1+f2;
	rational<int> sottr = f1-f2;
	rational<int> p = f1*f2;
	rational<int> di = f1/f2;
	
	std:: cout << "La somma è " << somma << "\n";
	std:: cout << "La differenza è " << sottr << "\n";
	std:: cout << "Il prodotto è " << p << "\n";
	std:: cout << "La divisione è " << di << "\n";
    return 0;
}