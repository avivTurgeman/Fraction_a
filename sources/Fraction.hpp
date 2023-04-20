#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <cmath> 
#include <iomanip> 

namespace ariel{
    class Fraction
    {
        private:
            int numerator_;
            int denominator_;
            void reduce();
            static Fraction doubleToFraction(const double);
            

        public:
            //Constructors
            Fraction():
            numerator_(0), denominator_(1){}

            Fraction(int numerator):
            numerator_(numerator), denominator_(1){}

            Fraction(int numerator, int denominator):
            numerator_(numerator), denominator_(denominator){
                if(denominator_ == 0){
                    throw new std::invalid_argument("denominator cannot be 0");
                }
                reduce();
            }
            
            //copy Constructor
            Fraction(const Fraction& other):
            numerator_(other.numerator_), denominator_(other.denominator_){}

            //destructor
            ~Fraction();

            //Arithmetic Operators
            Fraction operator+(const Fraction&) const;
            friend Fraction operator+(const double, const Fraction&);
            friend Fraction operator+(const Fraction&, const double);
 
            Fraction operator-(const Fraction&) const;
            friend Fraction operator-(const double, const Fraction&);
            friend Fraction operator-(const Fraction&, const double);
 
            Fraction operator*(const Fraction&) const;
            friend Fraction operator*(const double, const Fraction&);
            friend Fraction operator*(const Fraction&, const double);
            
            Fraction operator/(const Fraction&) const;
            friend Fraction operator/(const double, const Fraction&);
            friend Fraction operator/(const Fraction&, const double);

            //Comparison Operators
            bool operator==(const Fraction&) const;
            friend bool operator==(const Fraction&, const double);
            friend bool operator==(const double, const Fraction&);
            
            bool operator>(const Fraction&) const;
            friend bool operator>(const Fraction&, const double);
            friend bool operator>(const double, const Fraction&);

            bool operator<(const Fraction&) const;
            friend bool operator<(const Fraction&, const double);
            friend bool operator<(const double, const Fraction&);

            bool operator>=(const Fraction&) const;
            friend bool operator>=(const Fraction&, const double);
            friend bool operator>=(const double, const Fraction&);
            
            bool operator<=(const Fraction&) const;
            friend bool operator<=(const Fraction&, const double);
            friend bool operator<=(const double, const Fraction&);

            //Assignment Operator
            Fraction& operator=(const Fraction& other){
                if(this != &other){
                    this->numerator_ = other.numerator_;
                    this->denominator_ = other.denominator_;
                }
                reduce();
                return *this;
            }

            //prefix
            Fraction& operator++(){
                numerator_+= denominator_;
                return *this;
            }
            Fraction& operator--(){
                numerator_-= denominator_;
                return *this;
            }

            //postfix
            Fraction operator++(int flag_to_overload){
                Fraction copy = *this;
                numerator_+= denominator_;
                return copy;
            }
            Fraction operator--(int flag_to_overload){
                Fraction copy = *this;
                numerator_-= denominator_;
                return copy;
            }

            int getNumerator() const{
                return numerator_;
            }
            
            int getDenominator() const{
                return denominator_;
            }
            
            friend std::ostream& operator<< (std::ostream& output, const Fraction& frac);
            friend std::istream& operator>> (std::istream& input , Fraction& frac);
    };
}

#endif