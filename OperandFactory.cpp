#include "OperandFactory.hpp"
#include "Operand.tpp"
#include <string>
#include <cstdint>
#include <boost/numeric/conversion/cast.hpp>

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const& value) const
{
	switch (type)
	{
		case eOperandType::Int8:
			return createInt8(value);
		case eOperandType::Int16:
			return createInt16(value);
		case eOperandType::Int32:
			return createInt32(value);
		case eOperandType::Float:
			return createFloat(value);
		case eOperandType::Double:
			return createDouble(value);
	}
	//TODO
	//static const auto fs =
	/*IOperand const *(OperandFactory::*fs[])(std::string const&) const =
	{
		&OperandFactory::createInt16,
		&OperandFactory::createInt32,
	};
	auto f = &OperandFactory::createInt16;
	(this).*(f)(value);*/
	//return std::invoke(this, fs[static_cast<int>(type)], value);
}

IOperand const *OperandFactory::createInt8(std::string const& value) const
{
	return new Operand<int8_t>(boost::numeric_cast<int8_t>(std::stoll(value)), eOperandType::Int8);
}

IOperand const *OperandFactory::createInt16(std::string const& value) const
{
	return new Operand<int16_t>(boost::numeric_cast<int8_t>(std::stoll(value)), eOperandType::Int16);
}

IOperand const *OperandFactory::createInt32(std::string const& value) const
{
	return new Operand<int32_t>(boost::numeric_cast<int32_t>(std::stoll(value)), eOperandType::Int32);
}

IOperand const *OperandFactory::createFloat(std::string const& value) const
{
	return new Operand<float>(std::stof(value), eOperandType::Float);
}

IOperand const *OperandFactory::createDouble(std::string const& value) const
{
	return new Operand<double>(std::stod(value), eOperandType::Double);
}
