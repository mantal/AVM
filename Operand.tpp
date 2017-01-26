//#include "IOperand.hpp"
#include <string>
#include <boost/lexical_cast.hpp>

#include <iostream>

enum eOperandType { int8 };

class IOperand
{
public:

	virtual int getPrecision(void) = 0;

	virtual std::string const& toString(void) const = 0;

	virtual ~IOperand(void) { }
};

template <class T> class Operand : public IOperand
{
public:

	Operand(void) { value = 0; }
	Operand(T v) : value(v) { }
	Operand(Operand const& o) { value = o.value; }
	Operand(IOperand& o)
	{

	}

	virtual int getPrecision(void)
	{
		return static_cast<int>(type);
	}

	virtual eOperandType getType(void) { return type; }

	virtual IOperand const *operator+( IOperand const& rhs )
	{
		auto b = dynamic_cast<Operand const&>(rhs);
		return new Operand(value + b.value);
	}

	virtual IOperand const *operator-( IOperand const& rhs ) { return this; }
	virtual IOperand const *operator*( IOperand const& rhs ) { return this; }
	virtual IOperand const *operator/( IOperand const& rhs ) { return this; }
	virtual IOperand const *operator%( IOperand const& rhs ) { return this; }

	virtual std::string const& toString(void) const
	{
		std::string const* s = new std::string("test");
		std::string const sr = *s;
		return sr;
		//return boost::lexical_cast<std::string>(value);
	}

	virtual ~Operand(void) {}

private:
	T value;
	eOperandType type;
};
