#pragma once
#include <concepts>
#include <string>
template<typename I> requires std::integral<I>
class rational
{
 I num_;
 I den_;
public: 

	 /* costruttore di default */
	 rational()
		: num_(I{0}), den_(I{1})
	 {}
	 
	 /* costruttore user defined */
	 rational(I unum, I uden) {//user input
		num_ = unum;
		den_ = uden;
		exceptions();
		simplify();
		}
		
	/* lettura di num e den */
	I num() const {return num_;}
	I den() const {return den_;}
	
	/* incremento */
	rational& operator+=(const rational& other) {
		if (den_ == I{0} && other.den() == I{0}) {
			if (num_ == other.num()) {/* passa, sommo infiniti*/}
			else {
				num_ = 0; // la frazione diventa 0/0, ovvero NaN
			}
		}
		else if (den_ == I{0} || other.den() == I{0}) {
			if (num_ == I{0} || other.num() == I{0}) {
				num_ = I{0}; //NaN
			}    
			else if (other.den() == I{0}){
				num_ = other.num(); // allora la mia frazione diventa infinito
			}
		}
		else {
			num_ = (num_*other.den()) + (other.num() *den_);
            den_ = den_*other.den();
			simplify();
		}
		return *this;
	}
	
	/* somma  */
	rational operator+(const rational& other) const {
		rational sum = *this; // creo copia
		sum += other;         
		return sum;           
	}
	
	/* decremento */
	rational& operator-=(const rational& other) {
		rational opp(-other.num(), other.den()); // inverto segno di other
		*this += opp; 
		return *this;
	}

	/* sottrazione canonica */
	rational operator-(const rational& other) const {
		rational dif = *this;
		dif -= other;
		return dif;
	}
	
	/* prodotto incrementale */
	rational& operator*=(const rational& other) {
		if ((den_ == I{0} && num_ == I{0}) || (other.den() == I{0} && other.num() == I{0})) {
			num_ = I{0};  // se uno dei due è NaN, allora lo è il prodotto
			den_ = I{0}; // per coprire tutti i casi
		}
		else if ((den_ == I{0} && other.num() == I{0}) || (num_ == I{0} && other.den() == I{0})) {
			num_ = I{0}; // Inf*0 è indeterminato
			den_ = I{0};
		}
		else if (den_ == I{0} || other.den() == I{0}) {
			if ((num_ > I{0} && other.num() > I{0}) || (num_ < I{0} && other.num() < I{0})) {
				num_ = I{1}; // se segni concordi allora +
			} else {
				num_ = I{-1}; // se discordi allora -
			}
			den_ = I{0}; // di nuovo per coprire tutti i casi
		}
		else {
			num_ = num_ * other.num();
			den_ = den_ * other.den();
			simplify();
		}
		return *this;
	}
	
	/* prodotto */
	rational operator*(const rational& other) const {
		rational prod = *this;
		prod *= other;
		return prod;
	}
	
	/* divisione incrementale */
	rational& operator/=(const rational& other) {
		rational inv(other.den(), other.num()); // se other aveva num = 0, il caso è automaticamente gestito dal mio costruttore user defined (perché faccio l'inverso)
		*this *= inv; 
		return *this;
	}

	/* divisione */
	rational operator/(const rational& other) const {
		rational div = *this;
		div /= other;
		return div;
	}
	
private:
	I calcola_mcd(I n, I d) {
		if (d!= I{0}) {
			if (n < I{0}) {n = -n;} // valore assoluto
			if (d < I{0}) {d = -d;}
			// algoritmo di Euclide
			while (d != I{0}) {
				I resto = n%d; // calcolo resto
				n = d;           
				d = resto;
				}
		}
	return n;
	}
	void simplify(){
		if (den_ != I{0}){
			I MCD = calcola_mcd(num_,den_);
			num_ = num_/MCD;
			den_ = den_/MCD;
			// gestire i segni di num e den
			if (den_ < I{0}) {
				num_ = - num_;
				den_ = -den_;
			}
		}
	}

	void exceptions(){
		if (den_ == I{0}) {
			if (num_ == I{0}) {
				 // niente, equivale a NaN
				}
			else {
				if (num_ > I{0}) {
					num_ = I{1} ; // equivale a +inf
				}
				else {
					num_ = I{-1}; // equivale a -inf
				}
			}
		}
	}
 };
 
template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& f) {
	I n = f.num();
	I d = f.den();
	if (d == 0) { // eccezione
		if (n == 0) { // NaN
				os << "NaN";
		}
		else {
			if (n == 1) { // +inf
				os << "+inf";
				}
			else { // -inf
				os << "-inf";
			}
		}
	}
	else { // no eccezione
		os << f.num() << "/" << f.den();
	}
	return os;
}
