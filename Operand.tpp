#include "IOperand.hpp"
#include <string>
#include <algorithm>
#include <functional>

template <class T> class Operand : public IOperand
{
	public:

		Operand(T value, eOperandType type)
			:_value(value), _type(type), _str(std::to_string(value)) { }
		Operand(Operand const& o) : Operand(o._value, o._type) { }

		virtual ~Operand(void) {}

		virtual int getPrecision(void) const
		{
			return static_cast<int>(_type);
		}

		virtual eOperandType getType(void) const { return _type; }
		virtual T getValue(void) const { return _value; }

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"
#pragma clang diagnostic ignored "-Wdouble-promotion"
		virtual IOperand const *operator+(IOperand const& rhs) const
		{
			if (std::min(_type, rhs.getType()) != _type)
				return rhs + *this;
			return new Operand(_value + std::stod(rhs.toString()), _type);
		}

		virtual IOperand const *operator-(IOperand const& rhs) const
		{
			if (std::min(_type, rhs.getType()) != _type)
				return rhs - *this;
			return new Operand(_value - std::stod(rhs.toString()), _type);
		}

		virtual IOperand const *operator*(IOperand const& rhs) const
		{
			if (std::min(_type, rhs.getType()) != _type)
				return rhs * *this;
			return new Operand(_value * std::stod(rhs.toString()), _type);
		}
		virtual IOperand const *operator/(IOperand const& rhs) const
		{
			//if (std::min(_type, rhs.getType()) != _type)
			//	return rhs / *this;
			return new Operand(_value / std::stod(rhs.toString()), _type);
		}
		virtual IOperand const *operator%(IOperand const& rhs) const
		{
			if (_type >= eOperandType::Float || rhs.getType() >= eOperandType::Float)
				throw new std::exception();//TODO FAIRE UN EXECPTION sPeCiALEe
			if (std::min(_type, rhs.getType()) != _type)
				return rhs % *this;
			return new Operand(_value / std::stoll(rhs.toString()), _type);
		}

#pragma clang diagnostic pop

		virtual std::string const& toString(void) const
		{
			return (_str);
		}

	private:
		const T				_value;
		const eOperandType	_type;
		const std::string	_str;

		Operand(void);
		Operand(IOperand& o);
};
