#include "Cpu.hpp"
#include <sys/_types/_u_int16_t.h>
#include <sys/_types/_u_int8_t.h>
#include <utility>

Cpu::Cpu() : CpuRegisters()
{

}

Cpu::Cpu(const Cpu &other) : CpuRegisters(other)
{

}

Cpu::Cpu(Cpu &&other) noexcept : CpuRegisters(std::move(other))
{

}

Cpu::~Cpu()
{

}

Cpu		&Cpu::operator=(const Cpu &other)
{
	if (this != &other)
	{
		CpuRegisters::operator=(other);
	}
	return (*this);
}

Cpu		&Cpu::operator=(Cpu &&other) noexcept
{
	if (this != &other)
	{
		CpuRegisters::operator=(std::move(other));
	}
	return (*this);
}

void	Cpu::ld(u_int8_t &reg, u_int8_t value)
{
	reg = value;
}

void	Cpu::add(u_int8_t value)
{
	u_int8_t	result;

	result = A + value;
	setF(0);
	if (result < A)
		setCarryFlag();
	if ((((A & 0xF) + (value & 0xF)) & 0x10) == 0x10)
		setHalfCarryFlag();
	if (result == 0)
		setZeroFlag();
	unsetSubtractFlag();
	A = result;
}

void	Cpu::addHL(u_int16_t value)
{
	u_int16_t	result;

	result = getHL() + value;
	setF(0);
	if (result < getHL())
		setCarryFlag();
	if ((((getHL() & 0xFFF) + (value & 0xFFF)) & 0x1000) == 0x1000)
		setHalfCarryFlag();
	if (result == 0)
		setZeroFlag();
	unsetSubtractFlag();
	setHL(result);
}

void	Cpu::adc(u_int8_t value)
{
	u_int8_t	result;

	result = A + value + isCarryFlag();
	unsetZeroFlag();
	unsetSubtractFlag();
	unsetHalfCarryFlag();
	if ((((A & 0xF) + (value & 0xF) + (isCarryFlag())) & 0x10) == 0x10)
		setHalfCarryFlag();
	if (result < A)
		setCarryFlag();
	else
		unsetCarryFlag();
	if (result == 0)
		setZeroFlag();
	unsetSubtractFlag();
	A = result;
}

void	Cpu::sub(u_int8_t value)
{
	u_int8_t	result;

	cp(value);
	result = A - value;
	A = result;
}

void	Cpu::sbc(u_int8_t value)
{
	u_int8_t	result;

	result = A - value - isCarryFlag();
	unsetZeroFlag();
	unsetHalfCarryFlag();
	if ((((A & 0xF) - (value & 0xF) - (isCarryFlag())) & 0x10) == 0x10)
		setHalfCarryFlag();
	if (A > result)
		setCarryFlag();
	else
		unsetCarryFlag();
	if (result == 0)
		setZeroFlag();
	setSubtractFlag();
	A = result;
}

void	Cpu::andbw(u_int8_t value)
{
	A = A & value;
	setF(0);
	if (A == 0)
		setZeroFlag();
	setHalfCarryFlag();
}

void	Cpu::orbw(u_int8_t value)
{
	A = A | value;
	setF(0);
	if (A == 0)
		setZeroFlag();
}

void	Cpu::xorbw(u_int8_t value)
{
	A = A ^ value;
	setF(0);
	if (A == 0)
		setZeroFlag();
}

void	Cpu::cp(u_int8_t value)
{
	u_int8_t	result;

	result = A - value;
	setF(0);
	if (A > result)
		setCarryFlag();
	if ((((A & 0xF) - (value & 0xF)) & 0x10) == 0x10)
		setHalfCarryFlag();
	if (result == 0)
		setZeroFlag();
	setSubtractFlag();
}
