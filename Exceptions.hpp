#pragma once

#include <exception>
#include <string>

class UnknowOperatorException : public std::runtime_error
{
public:
	UnknowOperatorException(std::string const&);
};

class UnknowOperandException : public std::runtime_error
{
public:
	UnknowOperandException(std::string const&);
};

class SyntaxErrorException : public std::runtime_error
{
public:
	SyntaxErrorException(std::string const&);
};

class OperandsMismatchException : public std::runtime_error
{
public:
	OperandsMismatchException(std::string const&, size_t expected, size_t found);
};

class AssertionFailedException : public std::runtime_error
{
public:
	AssertionFailedException(std::string const&, std::string const& found);
};
