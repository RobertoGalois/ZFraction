#ifndef		__ZFRACTION_HPP__
#define		__ZFRACTION_HPP__

class	ZFraction
{
	
	/*************
	* ATTRIBUTES *
	**************/
	private :
	int		m_num;
	int		m_denom;

	/***************
	* CONSTRUCTORS *
	****************/
	public :
			ZFraction(int p_num = 0, int p_denom = 1);

	/**************
	* DESTRUCTORS *
	***************/
	public :
			~ZFraction(void);
	/************
	*  GETTERS  *
	*************/
	public :
	int		getNumerator(void)		const;
	int		getDenominator(void)	const;

	/************
	*  SETTERS  *
	*************/
	public :
	void	setNumerator(int p_num);
	void	setDenominator(int p_denom);
	void	setValue(int p_num, int p_denom);

	/*****************
	*  OTHER METHODS *
	******************/
	public :
	std::string		toString(void)	const;
	private :
	void			simplify(void);

	/*********************
	* OVERLOAD OPERATORS *
	**********************/
	public :
	bool			operator==(ZFraction b)		const;
	bool			operator!=(ZFraction b)		const;
	bool			operator>(ZFraction b)		const;
	bool			operator>=(ZFraction b)		const;
	bool			operator<(ZFraction b)		const;
	bool			operator<=(ZFraction b)		const;

	ZFraction		operator+(ZFraction b)		const;
	ZFraction		operator-(ZFraction b)		const;
	ZFraction		operator*(ZFraction b)		const;
	ZFraction		operator/(ZFraction b)		const;

	ZFraction		&operator+=(ZFraction b);
	ZFraction		&operator-=(ZFraction b);
	ZFraction		&operator*=(ZFraction b);
	ZFraction		&operator/=(ZFraction b);
};

std::ostream&	operator<<(std::ostream& stream, ZFraction a);
std::string		intToString(int nb);
int				pgcd(int a, int b);
#endif
