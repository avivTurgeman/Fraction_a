#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

namespace ariel{
    class Fraction
    {
        private:
            int numerator_;
            int denominator_;

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
            Fraction& operator=(const Fraction&);

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
                numerator_++;
                return copy;
            }
            Fraction operator--(int flag_to_overload){
                Fraction copy = *this;
                numerator_--;
                return copy;
            }
            
            friend std::ostream& operator<< (std::ostream& output, const Fraction& c);
            friend std::istream& operator>> (std::istream& input , Fraction& c);
    };
}

#endif