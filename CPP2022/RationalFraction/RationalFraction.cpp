#include "RationalFraction.h"
#include "MathLib.h"
#include <exception>

RationalFraction::RationalFraction()
	: mNumerator(0), mDenominator(1) {}

RationalFraction::RationalFraction(int numerator)
	: mNumerator(numerator), mDenominator(1) {}

RationalFraction::RationalFraction(int numerator, int denominator)
	: mNumerator(numerator), mDenominator(denominator)
{
	check();
	simplify();
}

void RationalFraction::simplify()
{
	int gcd = MathLib::greatestCommonDivisor(std::abs(mNumerator), std::abs(mDenominator));
	mNumerator /= gcd;
	mDenominator /= gcd;
	if (mDenominator < 0) {
		mDenominator *= -1;
		mNumerator *= -1;
	}
}

void RationalFraction::check() const
{
	try
	{
		if (mDenominator == 0)
		{
			throw std::overflow_error("Знаменатель не должен быть равен 0!");
		}
	}
	catch (std::overflow_error e)
	{
		std::cout << e.what() << std::endl;
		exit(0);
	}

}

int RationalFraction::toInt() const
{
	return mNumerator / mDenominator;
}

double RationalFraction::toReal() const
{
	return double(mNumerator) / mDenominator;
}

RationalFraction RationalFraction::getInverse() const
{
	return RationalFraction(mDenominator, mNumerator);
}

bool RationalFraction::operator==(const RationalFraction& rhs) const
{
	return mNumerator == rhs.mNumerator && mDenominator == rhs.mDenominator;
}

bool RationalFraction::operator!=(const RationalFraction& rhs) const
{
	return !(*this == rhs);
}

bool RationalFraction::operator>(const RationalFraction& rhs) const
{
	return toReal() > rhs.toReal();
}

bool RationalFraction::operator>=(const RationalFraction& rhs) const
{
	return *this > rhs || *this == rhs;
}

bool RationalFraction::operator<(const RationalFraction& rhs) const
{
	return toReal() < rhs.toReal();
}

bool RationalFraction::operator<=(const RationalFraction& rhs) const
{
	return *this < rhs || *this == rhs;
}

RationalFraction RationalFraction::operator+(const RationalFraction& rhs) const
{
	int a = mNumerator, b = mDenominator,
		c = rhs.mNumerator, d = rhs.mDenominator; // a= this->mNumerator

	RationalFraction result(a * d + b * c, b * d);
	return result;
}

RationalFraction RationalFraction::operator-(const RationalFraction& rhs) const
{
	return *this + (-rhs);
}

RationalFraction RationalFraction::operator*(const RationalFraction& rhs) const
{
	int a = mNumerator, b = mDenominator,
		c = rhs.mNumerator, d = rhs.mDenominator;

	RationalFraction result(a * c, b * d);
	return result;
}

RationalFraction RationalFraction::operator/(const RationalFraction& rhs) const
{
	int a = mNumerator, b = mDenominator,
		c = rhs.mNumerator, d = rhs.mDenominator;

	RationalFraction result(a * d, b * c);
	return result;
}

RationalFraction RationalFraction::operator+=(const RationalFraction& rhs)
{
	*this = *this + rhs;
	return *this;
}

RationalFraction RationalFraction::operator-=(const RationalFraction& rhs)
{
	*this = *this - rhs;
	return *this;
}

RationalFraction RationalFraction::operator*=(const RationalFraction& rhs)
{
	*this = *this * rhs;
	return *this;
}

RationalFraction RationalFraction::operator/=(const RationalFraction& rhs)
{
	*this = *this / rhs;
	return *this;
}

RationalFraction RationalFraction::operator-() const
{
	return RationalFraction(-mNumerator, mDenominator);
}

RationalFraction RationalFraction::operator++()
{
	mNumerator += mDenominator;
	check();
	simplify();
	return *this;
}

RationalFraction RationalFraction::operator++(int)
{
	RationalFraction old_value(*this);
	++* this;
	return old_value;
}

RationalFraction RationalFraction::operator--()
{
	mNumerator -= mDenominator;
	check();
	simplify();
	return *this;
}

RationalFraction RationalFraction::operator--(int)
{
	RationalFraction old_value(*this);
	--* this;
	return old_value;
}

// когда возвращаемое значение является ссылкой на объект потока,
//мы получаем возможность передавать данные "по цепочке"

std::istream& operator>>(std::istream& ist, RationalFraction& value)
{
	ist >> value.mNumerator >> value.mDenominator;

	value.check();
	value.simplify();

	return ist;
}

std::ostream& operator<<(std::ostream& ost, const RationalFraction& value)
{
	ost << "(" << value.mNumerator << "/" << value.mDenominator << ")";
	return ost;
}

RationalFraction operator+(const int lhs, const RationalFraction& rhs)
{
	return RationalFraction(lhs) + rhs;
}

RationalFraction operator-(const int lhs, const RationalFraction& rhs)
{
	return RationalFraction(lhs) - rhs;
}

RationalFraction operator*(const int lhs, const RationalFraction& rhs)
{
	return RationalFraction(lhs) * rhs;
}

RationalFraction operator/(const int lhs, const RationalFraction& rhs)
{
	return RationalFraction(lhs) / rhs;
}

bool operator==(const int lhs, const RationalFraction& rhs)
{
	return rhs == lhs;
}

bool operator!=(const int lhs, const RationalFraction& rhs)
{
	return rhs != lhs;
}

bool operator>(const int lhs, const RationalFraction& rhs)
{
	return rhs < lhs;
}

bool operator>=(const int lhs, const RationalFraction& rhs)
{
	return rhs <= lhs;
}

bool operator<(const int lhs, const RationalFraction& rhs)
{
	return rhs > lhs;
}

bool operator<=(const int lhs, const RationalFraction& rhs)
{
	return rhs >= lhs;
}