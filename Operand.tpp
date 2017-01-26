//#include "IOperand.hpp"
#include <string>
//#include <boost/lexical_cast.hpp>

#include <iostream>

enum eOperandType { Int8 };

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

		Operand(T value, eOperandType type)
			:_value(value), _type(type), _str(std::to_string(value)) { }
		virtual ~Operand(void) {}

		virtual int getPrecision(void)
		{
			return static_cast<int>(_type);
		}

		virtual eOperandType getType(void) { return _type; }

		virtual IOperand const *operator+( IOperand const& rhs )
		{
			auto b = dynamic_cast<Operand const&>(rhs);
			return new Operand(_value + b._value, _type);
		}

		virtual IOperand const *operator-( IOperand const& rhs ) { return this; }
		virtual IOperand const *operator*( IOperand const& rhs ) { return this; }
		virtual IOperand const *operator/( IOperand const& rhs ) { return this; }
		virtual IOperand const *operator%( IOperand const& rhs ) { return this; }

		virtual std::string const& toString(void) const
		{
			return (this->_str);

			//std::string const* s = new std::string("test");
			//std::string const sr = *s;
			//return boost::lexical_cast<std::string>(_value);
		}


	private:
		T					_value;
		eOperandType		_type;
		const std::string	_str;

		Operand(void);
		//Operand(Operand const& o);
		Operand(IOperand& o);
};
