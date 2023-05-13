#pragma once
#ifndef RFRACT_H
#define RFRACT_H
#include <iostream>

class RationalFraction {
private:
	
	int mNumerator, mDenominator;
	
	// Это служебные методы. Пользователь не будет их вызывать.
	void simplify();
	void check() const;

public:
	RationalFraction();
	RationalFraction(int numerator);
	RationalFraction(int numerator, int denominator);

	int toInt() const;		// приведение к целому числу
	double toReal() const;  // приведение к десятичной дроби
	RationalFraction getInverse() const; // перевернуть дробь

	// lhs => left hand side, rhs => right hand side
	// операнды находящиеся слевой и с правой стороны

	bool operator==(const RationalFraction& rhs) const;
	bool operator!=(const RationalFraction& rhs) const;
	bool operator>(const RationalFraction& rhs) const;
	bool operator>=(const RationalFraction& rhs) const;
	bool operator<(const RationalFraction& rhs) const;
	bool operator<=(const RationalFraction& rhs) const;

	// Вызываются, когда слева и с права от оператора стоят RationalFraction.
	// Константный метод. Не меняет сам объект. Можно вызывать для константных объектов.
	
	RationalFraction operator+(const RationalFraction& rhs) const; 
	RationalFraction operator-(const RationalFraction& rhs) const;
	RationalFraction operator*(const RationalFraction& rhs) const;
	RationalFraction operator/(const RationalFraction& rhs) const;

	// НЕ константный метод. Меняет сам объект. Нельзя вызывать для константных объектов.

	RationalFraction operator+=(const RationalFraction& rhs);
	RationalFraction operator-=(const RationalFraction& rhs);
	RationalFraction operator*=(const RationalFraction& rhs);
	RationalFraction operator/=(const RationalFraction& rhs);

	RationalFraction operator-() const; // унарный минус
	RationalFraction operator++();		// перегрузка префиксной формы
	RationalFraction operator++(int);	// перегрузка постфиксной формы
	RationalFraction operator--();
	RationalFraction operator--(int);

	// Перегрузки реализуются через Дружественные функции.

	friend std::istream& operator>>(std::istream&, RationalFraction& value);
	friend std::ostream& operator<<(std::ostream&, const RationalFraction& value);

	friend bool operator==(const int lhs, const RationalFraction& rhs);
	friend bool operator!=(const int lhs, const RationalFraction& rhs);
	friend bool operator>(const int lhs, const RationalFraction& rhs);
	friend bool operator>=(const int lhs, const RationalFraction& rhs);
	friend bool operator<(const int lhs, const RationalFraction& rhs);
	friend bool operator<=(const int lhs, const RationalFraction& rhs);

	friend RationalFraction operator+(const int lhs, const RationalFraction& rhs);
	friend RationalFraction operator-(const int lhs, const RationalFraction& rhs);
	friend RationalFraction operator*(const int lhs, const RationalFraction& rhs);
	friend RationalFraction operator/(const int lhs, const RationalFraction& rhs);

};

#endif // RFRACT_H

