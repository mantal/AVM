#include "IOperand.hpp"
#include <string>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <limits>
#include <cstdint>
#include <math.h>

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

		virtual IOperand const *operator+(IOperand const& rhs) const
		{
			if (std::max(_type, rhs.getType()) != _type)
				return rhs + *this;
			auto b = std::stod(rhs.toString());
			if (_value + b >= std::numeric_limits<T>::max())
				throw std::overflow_error("Overflow detected: " + toString() + " + " + rhs.toString());
			return new Operand(_value + b, _type);
		}

		virtual IOperand const *operator-(IOperand const& rhs) const
		{
			if (std::max(_type, rhs.getType()) != _type)
				return rhs - *this;
			auto b = std::stod(rhs.toString());
			if (_value - b <= std::numeric_limits<T>::lowest())
				throw std::underflow_error("Underflow detected: " + toString() + " - " + rhs.toString());

			return new Operand(_value - std::stod(rhs.toString()), _type);
		}

		virtual IOperand const *operator*(IOperand const& rhs) const
		{
			if (std::max(_type, rhs.getType()) != _type)
				return rhs * *this;

			auto b = std::stod(rhs.toString());
			if (_value * b >= std::numeric_limits<T>::max())
				throw std::overflow_error("Overflow detected: " + toString() + " * " + rhs.toString());

			return new Operand(_value * std::stod(rhs.toString()), _type);
		}

		virtual IOperand const *operator/(IOperand const& rhs) const
		{
			auto const b = std::stod(rhs.toString());
			if (fabs(b) < std::numeric_limits<double>::epsilon())
				throw std::domain_error("Divider operand can not be 0");

			return new Operand(_value / std::stod(rhs.toString()), _type);
		}

		virtual IOperand const *operator%(IOperand const& rhs) const
		{
			if (_type >= eOperandType::Float || rhs.getType() >= eOperandType::Float)
				throw std::domain_error("Modulus operator require integer operands");
			if (std::max(_type, rhs.getType()) != _type)
				return rhs % *this;
			return new Operand(static_cast<intmax_t>(_value) % static_cast<intmax_t>(std::stod(rhs.toString())), _type);
		}

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
