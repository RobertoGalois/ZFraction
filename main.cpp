#include	<iostream>
#include	"ZFraction.hpp"

int		main(void)
{
	ZFraction a(-42,5);	//Déclare une fraction valant -42/5
	ZFraction b(4,5);	//Déclare une fraction valant 4/5 
	ZFraction c, d;		//Déclare deux fractions valant 0

	c = a + b;
	d = a * b;

	std::cout << a << " + " << b << " = " << c << std::endl;
	std::cout << a << " - " << b << " = " << (a-b) << std::endl;
	std::cout << a << " * " << b << " = " << d << std::endl;
	std::cout << a << " \\ " << b << " = " << (a/b) << std::endl;
	std::cout << "--------------------" << std::endl;

	std::cout << a << " += " << b << " => ";
	a += b;
	std::cout << (a) << std::endl;

	std::cout << a << " -= " << b << " => ";
	a -= b;
	std::cout << (a) << std::endl;

	std::cout << a << " *= " << b << " => ";
	a *= b;
	std::cout << (a) << std::endl;

	std::cout << a << " /= " << b << " => ";
	a /= b;
	std::cout << (a) << std::endl;

	return (0);
}
