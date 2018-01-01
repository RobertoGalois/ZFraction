#include	<iostream>
#include	<string>
#include	"ZFraction.hpp"


/***************
* CONSTRUCTORS *
****************/

		ZFraction::ZFraction(int p_num, int p_denom)
{
	m_num = p_num;

	if (p_denom == 0)
		p_denom = 1;

	m_denom = p_denom;

	(*this).simplify();
}

/**************
* DESTRUCTORS *
***************/

		ZFraction::~ZFraction(void)
{
	//do nothing
}

/************
*  GETTERS  *
*************/

int		ZFraction::getNumerator(void)		const
{
	return (m_num);
}

int		ZFraction::getDenominator(void)		const
{
	return (m_denom);
}

/************
*  SETTERS  *
*************/

void	ZFraction::setNumerator(int p_num)
{
	m_num = p_num;
	(*this).simplify();
}

void	ZFraction::setDenominator(int p_denom)
{
	if (p_denom == 0)
		p_denom = 1;

	m_denom = p_denom;
	(*this).simplify();
}

void	ZFraction::setValue(int p_num, int p_denom)
{
	if (p_denom == 0)
		p_denom = 1;

	m_num = p_num;
	m_denom = p_denom;
	(*this).simplify();
}

/*****************
*  OTHER METHODS *
******************/

std::string	ZFraction::toString(void)		const
{
	std::string		ret("");

	ret += intToString(m_num);

	if ((m_num != 0) && (m_denom != 1))
	{
		ret += "/";
		ret += intToString(m_denom);
	}

	return (ret);
}

void		ZFraction::simplify()
{
	int		div;

	/* Reduction */
	div = pgcd(m_num, m_denom);
	m_num /= div;
	m_denom /= div;

	/* Minus sign managment */
	if (m_denom < -1)
	{
		m_num *= (-1);
		m_denom *= (-1);
	}
}

/*********************
* OVERLOAD OPERATORS *
**********************/
bool		ZFraction::operator==(ZFraction b)	const
{
	if (((*this).getNumerator() == b.getNumerator())
		&& ((*this).getDenominator() == b.getDenominator()))
		return (true);

	return (false);
}

bool		ZFraction::operator!=(ZFraction b)	const
{
	if (!((*this).operator==(b)))
		return (true);

	return (false);
}

bool		ZFraction::operator>(ZFraction b)	const
{
	int		val_this;
	int		val_b;

	val_this = ((*this).getNumerator() * b.getDenominator());
	val_b = (b.getNumerator() * (*this).getDenominator());

	if (val_this > val_b)
		return (true);

	return (false);
}

bool		ZFraction::operator>=(ZFraction b)	const
{
	if (((*this).operator==(b)) || (*this).operator>(b))
		return (true);

	return (false);
}

bool		ZFraction::operator<(ZFraction b)	const
{
	if (!((*this).operator>=(b)))
		return (true);

	return (false);
}

bool		ZFraction::operator<=(ZFraction b)	const
{
	if (!((*this).operator>(b)))
		return (true);

	return (false);
}

ZFraction	ZFraction::operator+(ZFraction b)	const
{
	ZFraction	ret;
	int			ret_denom;
	int			ret_num;

	if ((*this).getDenominator() == b.getDenominator())
	{
		ret_denom = (*this).getDenominator();
		ret_num = (*this).getNumerator() + b.getNumerator();
	}

	else
	{
		ret_denom = (((*this).getDenominator())
					* (b.getDenominator()));

		ret_num = ((((*this).getNumerator()) * ret_denom)
			+ ((b.getNumerator()) * ret_denom));
	}

	ret.setValue(ret_num, ret_denom);
	return (ret);
}

ZFraction	ZFraction::operator-(ZFraction b)	const
{
	ZFraction	ret;

	b.setNumerator(b.getNumerator() * (-1));
	ret = (*this).operator+(b);
	return (ret);
}

ZFraction	ZFraction::operator*(ZFraction b)	const
{
	ZFraction	ret;
	int			num;
	int			denom;

	num = (((*this).getNumerator()) * (b.getNumerator()));
	denom = (((*this).getDenominator()) * (b.getDenominator()));
	ret.setValue(num, denom);
	return (ret);
}

ZFraction	ZFraction::operator/(ZFraction b)	const
{
	ZFraction	ret;
	ZFraction	calc;

	if (b.getNumerator() == 0)
		ret = (*this);

	else
	{
		calc.setValue(b.getDenominator(), b.getNumerator());
		ret = (*this).operator*(calc);
	}

	return (ret);
}

ZFraction&	ZFraction::operator+=(ZFraction b)
{
	(*this) = (*this).operator+(b);
	return (*this);
}

ZFraction&	ZFraction::operator-=(ZFraction b)
{
	(*this) = (*this).operator-(b);
	return (*this);
}

ZFraction&	ZFraction::operator*=(ZFraction b)
{
	(*this) = (*this).operator*(b);
	return (*this);
}

ZFraction&	ZFraction::operator/=(ZFraction b)
{
	(*this) = (*this).operator/(b);
	return (*this);
}


/******************
*   OUT OF CLASS  *
*******************/

std::ostream&	operator<<(std::ostream &stream, ZFraction a)
{
	std::cout << a.toString();
	return (stream);
}

int		pgcd(int a, int b)
{
	int	t;

	t = b;
	while (b != 0)
	{
		t = b;
		b = (a % t);
		a = t;
	}

	return (a);
}

std::string		intToString(int	nb)
{
	std::string		ret("");
	std::string		temp;
	char			digit[1];
	int				magnitude(1);

	if (nb == 0)
	{
		ret = "0";
		return (ret);
	}

	if (nb < 0)
	{
		ret.push_back('-');
		nb = (nb * (-1));
	}

	while ((nb / magnitude) > 0)
		magnitude *= 10;

	magnitude /= 10;
	while (magnitude > 0)
	{
		digit[0] = (nb / magnitude);
		nb = (nb % magnitude);
		ret.push_back(48 + digit[0]);
		magnitude /= 10;
	}

	return (ret);
}
