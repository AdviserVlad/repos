#pragma once
#ifndef RFRACT_H
#define RFRACT_H
#include <iostream>

class RationalFraction {
private:
	
	int mNumerator, mDenominator;
	
	// ��� ��������� ������. ������������ �� ����� �� ��������.
	void simplify();
	void check() const;

public:
	RationalFraction();
	RationalFraction(int numerator);
	RationalFraction(int numerator, int denominator);

	int toInt() const;		// ���������� � ������ �����
	double toReal() const;  // ���������� � ���������� �����
	RationalFraction getInverse() const; // ����������� �����

	// lhs => left hand side, rhs => right hand side
	// �������� ����������� ������ � � ������ �������

	bool operator==(const RationalFraction& rhs) const;
	bool operator!=(const RationalFraction& rhs) const;
	bool operator>(const RationalFraction& rhs) const;
	bool operator>=(const RationalFraction& rhs) const;
	bool operator<(const RationalFraction& rhs) const;
	bool operator<=(const RationalFraction& rhs) const;

	// ����������, ����� ����� � � ����� �� ��������� ����� RationalFraction.
	// ����������� �����. �� ������ ��� ������. ����� �������� ��� ����������� ��������.
	
	RationalFraction operator+(const RationalFraction& rhs) const; 
	RationalFraction operator-(const RationalFraction& rhs) const;
	RationalFraction operator*(const RationalFraction& rhs) const;
	RationalFraction operator/(const RationalFraction& rhs) const;

	// �� ����������� �����. ������ ��� ������. ������ �������� ��� ����������� ��������.

	RationalFraction operator+=(const RationalFraction& rhs);
	RationalFraction operator-=(const RationalFraction& rhs);
	RationalFraction operator*=(const RationalFraction& rhs);
	RationalFraction operator/=(const RationalFraction& rhs);

	RationalFraction operator-() const; // ������� �����
	RationalFraction operator++();		// ���������� ���������� �����
	RationalFraction operator++(int);	// ���������� ����������� �����
	RationalFraction operator--();
	RationalFraction operator--(int);

	// ���������� ����������� ����� ������������� �������.

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

