#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Rational
{
private:
	int numerator;
	int denominator;
	//Finds GCD for numerator and denominator
	int gcd(int a, int b) {
		if (a == 0 || b == 0)
			return 0;
		else if (a == b)
			return a;
		else if (a > b)
			return gcd(a - b, b);
		else return gcd(a, b - a);
	}
	//Handles if both are negative or if the denom is negative it makes the numerator negative
	void normalize()
	{
		if (denominator < 0)
		{
			denominator *= -1;
			numerator *= -1;
		}

		if (numerator != 0)
		{
			int temp = gcd(abs(numerator), abs(denominator));
			numerator /= temp;
			denominator /= temp;
		}

	}
public:
	class ZeroDenominator 
	{
	private:
		string rational;
	public:
		ZeroDenominator()
		{}
		//Exception message
		ZeroDenominator(Rational r)
		{
			rational = r.toString();
		}

		string toString() 
		{
			return rational;
		}
	};
	//Default Constructor
	Rational()
	{
		numerator = 0;
		denominator = 1;
	}
	//converts to string
	string toString()
	{
		return to_string(numerator) + "/" + to_string(denominator);
	}
	// will throw and exception
	Rational(int newN, int newD)
	{
		numerator = newN;
		denominator = newD;
		if (denominator == 0)
			throw ZeroDenominator(*this);

		normalize();
	}
	//getter for numerator
	int getNumerator() const
	{
		return numerator;
	}
	//setter for numerator
	void setNumerator(int newN)
	{
		numerator = newN;
		normalize();
	}
	//getter for denominator
	int getDenominator() const
	{
		return denominator;
	}
	//setter for denominator throws exception if 0
	void setDenominator(int newD)
	{
		denominator = newD;
		if (denominator == 0)
			throw ZeroDenominator(*this);

		normalize();
	}

	friend Rational operator *(const Rational& obj1, const Rational& obj2)
	{
		int newNumerator = obj1.numerator * obj2.numerator;
		int newDenominator = obj1.denominator * obj2.denominator;
		return Rational(newNumerator, newDenominator);
	}

	//allows the Rationals to be compared -- see if they are equal
	friend bool operator ==(const Rational& obj1, const Rational& obj2)
	{
		return (obj1.numerator * obj2.denominator) == (obj2.numerator * obj1.denominator);
	}
	
	//allows the Rationals to be compared -- if one is less than the other
	friend bool operator <(const Rational& obj1, const Rational& obj2)
	{
		return (obj1.numerator * obj2.denominator) < (obj2.numerator * obj1.denominator);
	}
	// overloaded  cout << 
	friend ostream& operator << (ostream& out,  Rational obj)
	{
		out << obj.toString();
		return out;
	}


};