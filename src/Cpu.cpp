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
	rr(A);
}

void	Cpu::rla()
{
	rl(A);
}

void	Cpu::rrca()
{
	rrc(A);
}

void	Cpu::rrla()
{
	rlc(A);
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

void	Cpu::reset(u_int8_t &reg, u_int8_t bit)
{
	reg = reg & ~(1 << bit);
}

void	Cpu::set(u_int8_t &reg, u_int8_t bit)
{
	reg = reg | (1 << bit);
}

void	Cpu::srl(u_int8_t &reg)
{
	u_int8_t	leastSignificantBit;

	leastSignificantBit = reg & 1;
	setF(0);
	if (leastSignificantBit)
		setCarryFlag();
	reg = (reg >> 1);
	if (!reg)
		setZeroFlag();
}

void	Cpu::rr(u_int8_t &reg)
{
	u_int8_t	carryBit;
	u_int8_t	leastSignificantBit;

	carryBit = static_cast<u_int8_t>(isCarryFlag());
	leastSignificantBit = reg & 1;
	setF(0);
	if (leastSignificantBit)
		setCarryFlag();
	reg = ((reg >> 1) | (carryBit << 7));
}

void	Cpu::rl(u_int8_t &reg)
{
	u_int8_t	carryBit;
	u_int8_t	mostSignificantBit;

	carryBit = static_cast<u_int8_t>(isCarryFlag());
	mostSignificantBit = static_cast<u_int8_t>((((reg >> 7) & 1) == 1));
	setF(0);
	if (mostSignificantBit)
		setCarryFlag();
	reg = ((reg << 1) | carryBit);
}

void	Cpu::rrc(u_int8_t &reg)
{
	u_int8_t	leastSignificantBit;

	leastSignificantBit = (reg & 1);
	reg = ((reg >> 1) | (leastSignificantBit << 7));
}

void	Cpu::rlc(u_int8_t &reg)
{
	u_int8_t	mostSignificantBit;

	mostSignificantBit = static_cast<u_int8_t>((((reg >> 7) & 1) == 1));
	reg = ((reg << 1) | mostSignificantBit);
}

void	Cpu::sra(u_int8_t &reg)
{
	u_int8_t	mostSignificantBit;
	u_int8_t	leastSignificantBit;

	mostSignificantBit = ((reg >> 7) & 1);
	leastSignificantBit = (reg & 1);
	setF(0);
	reg = (reg >> 1) | (mostSignificantBit << 7);
	if (leastSignificantBit)
		setCarryFlag();
	if (reg == 0)
		setZeroFlag();
}

void	Cpu::sla(u_int8_t &reg)
{
	u_int8_t	mostSignificantBit;

	mostSignificantBit = ((reg >> 7) & 1);
	reg = (reg << 1);
	setF(0);
	if (reg == 0)
		setZeroFlag();
	if (mostSignificantBit)
		setCarryFlag();
}

void	Cpu::swap(u_int8_t &reg)
{
	reg = (reg << 4 | reg >> 4);
}
