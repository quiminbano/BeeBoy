#include "Cpu.hpp"
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

void	Cpu::inc(u_int8_t &reg)
{
    u_int8_t	result;

    result = reg + 1;
    setF(0);
    if (result == 0)
    	setZeroFlag();
    if ((((reg & 0xF) + (1 & 0xF)) & 0x10) == 0x10)
     	setHalfCarryFlag();
    reg = result;
}

void	Cpu::dec(u_int8_t &reg)
{
	u_int8_t	result;

	result = reg - 1;
	setF(0);
	if (result == 0)
		setZeroFlag();
	if ((((reg & 0xF) - (1 & 0xF)) & 0x10) == 0x10)
		setHalfCarryFlag();
	setSubtractFlag();
}

//I wonder if I should write these wrappers for ccf and scf or not
void	Cpu::ccf()
{
	setCarryFlag();
}

//Same story here
void	Cpu::scf()
{
	unsetCarryFlag();
}

void	Cpu::rra()
{
	u_int8_t	carryBit;
	u_int8_t	leastSignificantBitA;

	carryBit = static_cast<u_int8_t>(isCarryFlag());
	leastSignificantBitA = A & 1;
	unsetCarryFlag();
	if (leastSignificantBitA)
		setCarryFlag();
	A = ((A >> 1) | (carryBit << 7));
}

void	Cpu::rla()
{
	u_int8_t	carryBit;
	u_int8_t	mostSignificantBitA;

	carryBit = static_cast<u_int8_t>(isCarryFlag());
	mostSignificantBitA = static_cast<u_int8_t>((((A >> 7) & 1) == 1));
	unsetCarryFlag();
	if (mostSignificantBitA)
		setCarryFlag();
	A = ((A << 1) | carryBit);
}

void	Cpu::rrca()
{
	u_int8_t	leastSignificantBitA;

	leastSignificantBitA = A & 1;
	A = ((A >> 1) | (leastSignificantBitA << 7));
}

void	Cpu::rrla()
{
	u_int8_t	mostSignificantBitA;

	mostSignificantBitA = static_cast<u_int8_t>((((A >> 7) & 1) == 1));
	A = ((A << 1) | mostSignificantBitA);
}

void	Cpu::cpl()
{
	A = ~A;
	setHalfCarryFlag();
	setSubtractFlag();
}

void	Cpu::bit(u_int8_t &reg, u_int8_t bit)
{
	if (((reg >> bit) & 1) == 0)
		setZeroFlag();
	setHalfCarryFlag();
	unsetSubtractFlag();
}
