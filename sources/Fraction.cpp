#include "Fraction.hpp"

using namespace std;

namespace ariel{

    Fraction::~Fraction(){}

    void Fraction::reduce(){
        int gcd = __gcd(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;
    }

    Fraction Fraction::doubleToFraction(const double  num){
        int integer_part = (int) num;
        double dummy;
        double frac = modf(num, &dummy);
        int fractional_part = round(frac * 1000);

        Fraction rv(fractional_part + (integer_part * 1000), 1000);
        
        return rv;    
    }

    Fraction Fraction::operator+(const Fraction& other) const{
        int numerator1 = this->numerator_ * other.denominator_;
        int numerator2 = other.numerator_ * this->denominator_;
        int rv_numerator = numerator1 + numerator2;
        int rv_denominator = this->denominator_ * other.denominator_;

        Fraction rv(rv_numerator, rv_denominator);
        return rv; 
    }

    Fraction operator+(const double  num, const Fraction& frac){
        Fraction numF = Fraction::doubleToFraction(num) ;
        Fraction rv = numF + frac;
        return rv;
    }

    Fraction operator+(const Fraction& frac, const double  num){
        Fraction numF = Fraction::doubleToFraction(num);
        Fraction rv = numF + frac;
        return rv;
    }

    Fraction Fraction::operator-(const Fraction& other) const{
        Fraction negative_other = other * (-1);
        Fraction rv = *this + negative_other;
        return rv;
    }

    Fraction operator-(const double num, const Fraction& frac){
        Fraction numF = Fraction::doubleToFraction(num);
        Fraction rv = numF - frac;
        return rv;
    }

    Fraction operator-(const Fraction& frac, const double num){
        Fraction numF = Fraction::doubleToFraction(num);
        Fraction rv = frac - numF;
        return rv;
    }

    Fraction Fraction::operator*(const Fraction& other) const{
        int rv_numerator = this->numerator_ * other.numerator_;
        int rv_denominator = this->denominator_ * other.denominator_;
        Fraction rv(rv_numerator, rv_denominator);
        return rv;
    }

    Fraction operator*(const double num, const Fraction& frac){
        Fraction numF = Fraction::doubleToFraction(num) ;
        Fraction rv = numF * frac;
        return rv;
    }

    Fraction operator*(const Fraction& frac, const double num){
        Fraction numF = Fraction::doubleToFraction(num) ;
        Fraction rv = numF * frac;
        return rv;
    }

    Fraction Fraction::operator/(const Fraction& other) const{
        Fraction other_flipped(other.denominator_, other.numerator_);
        Fraction rv = *this * other_flipped;
        return rv;
    }

    Fraction operator/(const double num, const Fraction& frac){
        Fraction numF = Fraction::doubleToFraction(num) ;
        Fraction frac_flipped(frac.denominator_, frac.numerator_);
        Fraction rv = numF * frac_flipped;
        return rv;
    }

    Fraction operator/(const Fraction& frac, const double num){
        Fraction numF = Fraction::doubleToFraction(num) ;
        Fraction numF_flipped(numF.denominator_, numF.numerator_);
        Fraction rv = numF_flipped * frac;
        return rv;
    }

    bool Fraction::operator==(const Fraction& other) const{
        if((this->numerator_ == other.numerator_) && (this->denominator_ == other.denominator_)){
            return true;
        }
        return false;
    }

    bool operator==(const Fraction& frac, const double num){
        Fraction numF = Fraction::doubleToFraction(num);
        return (frac == numF);
    }

    bool operator==(const double num, const Fraction& frac){
        Fraction numF = Fraction::doubleToFraction(num);
        return (frac == numF);
    }

    bool Fraction::operator>(const Fraction& other) const{
        int common_denominator = this->denominator_ * other.denominator_;
        Fraction new_this(this->numerator_ * other.denominator_, common_denominator);
        Fraction new_other(other.numerator_ * this->denominator_, common_denominator);
        if(new_this.numerator_ > new_other.numerator_){
            return true;
        }
        return false;
    }

    bool operator>(const Fraction& frac, const double num){
        Fraction numF = Fraction::doubleToFraction(num);
        return (frac > numF);
    }

    bool operator>(const double num, const Fraction& frac){
        Fraction numF = Fraction::doubleToFraction(num);
        return (numF > frac);
    }

    bool Fraction::operator<(const Fraction& other) const{
        int common_denominator = this->denominator_ * other.denominator_;
        Fraction new_this(this->numerator_ * other.denominator_, common_denominator);
        Fraction new_other(other.numerator_ * this->denominator_, common_denominator);
        if(new_this.numerator_ < new_other.numerator_){
            return true;
        }
        return false;
    }

    bool operator<(const Fraction& frac, const double num){
        Fraction numF = Fraction::doubleToFraction(num);
        return (frac < numF);
    }

    bool operator<(const double num, const Fraction& frac){
        Fraction numF = Fraction::doubleToFraction(num);
        return (numF < frac);
    }

    bool Fraction::operator>=(const Fraction& other) const{
        int common_denominator = this->denominator_ * other.denominator_;
        Fraction new_this(this->numerator_ * other.denominator_, common_denominator);
        Fraction new_other(other.numerator_ * this->denominator_, common_denominator);
        if(new_this.numerator_ >= new_other.numerator_){
            return true;
        }
        return false;
    }

    bool operator>=(const Fraction& frac, const double num){
        Fraction numF = Fraction::doubleToFraction(num);
        return (frac >= numF);
    }

    bool operator>=(const double num, const Fraction& frac){
        Fraction numF = Fraction::doubleToFraction(num);
        return (numF >= frac);
    }

    bool Fraction::operator<=(const Fraction& other) const{
        int common_denominator = this->denominator_ * other.denominator_;
        Fraction new_this(this->numerator_ * other.denominator_, common_denominator);
        Fraction new_other(other.numerator_ * this->denominator_, common_denominator);
        if(new_this.numerator_ <= new_other.numerator_){
            return true;
        }
        return false;
    }

    bool operator<=(const Fraction& frac, const double num){
        Fraction numF = Fraction::doubleToFraction(num);
        return (frac <= numF);
    }

    bool operator<=(const double num, const Fraction& frac){
        Fraction numF = Fraction::doubleToFraction(num);
        return (numF <= frac);
    }

    ostream& operator<<(ostream& output, const Fraction& frac) {
        return output << frac.getNumerator() << '/' << frac.getDenominator();
    }

    istream& operator>>(istream& input, Fraction& frac){
        char c;
        int numerator ,denominator;

        input >> numerator >> c >> denominator;

        if(c == '/'){
            frac = Fraction(numerator, denominator);
        }
        else{
            input.setstate(ios::failbit);
        }
        return input;
    }
}