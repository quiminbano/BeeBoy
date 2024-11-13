/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuRegisters.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:35:16 by corellan          #+#    #+#             */
/*   Updated: 2024/10/15 12:03:18 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuRegisters.hpp"

CpuRegisters::CpuRegisters()
{
	A = 0;
	B = 0;
	C = 0;
	D = 0;
	E = 0;
	F = 0;
	H = 0;
	L = 0;
	SP = nullptr;
	CP = nullptr;	
}

CpuRegisters::CpuRegisters(const CpuRegisters &other)
{
	A = other.A;
	B = other.B;
	C = other.C;
	D = other.D;
	E = other.E;
	F = other.F;
	H = other.H;
	L = other.L;
	SP = other.SP;
	CP = other.CP;
}

CpuRegisters::CpuRegisters(CpuRegisters &&other) noexcept
{
	A = other.A;
	B = other.B;
	C = other.C;
	D = other.D;
	E = other.E;
	F = other.F;
	H = other.H;
	L = other.L;
	SP = other.SP;
	CP = other.CP;
	other.SP = nullptr;
	other.CP = nullptr;
}

CpuRegisters::~CpuRegisters()
{
	
}

CpuRegisters	&CpuRegisters::operator=(const CpuRegisters &other)
{
	if (this != &other)
	{
		A = other.A;
		B = other.B;
		C = other.C;
		D = other.D;
		E = other.E;
		F = other.F;
		H = other.H;
		L = other.L;
		SP = other.SP;
		CP = other.CP;
	}
	return (*this);
}

CpuRegisters	&CpuRegisters::operator=(CpuRegisters &&other) noexcept
{
	if (this != &other)
	{
		A = other.A;
		B = other.B;
		C = other.C;
		D = other.D;
		E = other.E;
		F = other.F;
		H = other.H;
		L = other.L;
		SP = other.SP;
		CP = other.CP;
		other.SP = nullptr;
		other.CP = nullptr;
	}
	return (*this);
}

bool	CpuRegisters::isCarryFlag() const
{
	return (((F >> 4) & 1) != 0);
}

bool	CpuRegisters::isHalfCarryFlag() const
{
	return (((F >> 5) & 1) != 0);
}

bool	CpuRegisters::isSubtractFlag() const
{
	return (((F >> 6) & 1) != 0);
}

bool	CpuRegisters::isZeroFlag() const
{
	return (((F >> 7) & 1) != 0);
}

u_int16_t	CpuRegisters::getBC() const
{
	return (((static_cast<u_int16_t>(B)) << 8) | (static_cast<u_int16_t>(C)));
}

u_int16_t	CpuRegisters::getDE() const
{
	return (((static_cast<u_int16_t>(D)) << 8) | (static_cast<u_int16_t>(E)));
}

u_int16_t	CpuRegisters::getHL() const
{
	return (((static_cast<u_int16_t>(H)) << 8) | (static_cast<u_int16_t>(L)));
}

u_int16_t	CpuRegisters::getAF() const
{
	return (((static_cast<u_int16_t>(A)) << 8) | (static_cast<u_int16_t>(F)));
}

u_int8_t	CpuRegisters::getA() const
{
	return (A);
}

u_int8_t	CpuRegisters::getB() const
{
	return (B);
}

u_int8_t	CpuRegisters::getC() const
{
	return (C);
}

u_int8_t	CpuRegisters::getD() const
{
	return (D);
}

u_int8_t	CpuRegisters::getE() const
{
	return (E);
}

u_int8_t	CpuRegisters::getF() const
{
	return (F);
}

u_int8_t	CpuRegisters::getH() const
{
	return (H);
}

u_int8_t	CpuRegisters::getL() const
{
	return (L);
}

void	CpuRegisters::setA(u_int8_t value)
{
	A = value;
}

void	CpuRegisters::setB(u_int8_t value)
{
	B = value;
}

void	CpuRegisters::setC(u_int8_t value)
{
	C = value;
}

void	CpuRegisters::setD(u_int8_t value)
{
	D = value;
}

void	CpuRegisters::setE(u_int8_t value)
{
	E = value;
}

void	CpuRegisters::setF(u_int8_t value)
{
	F = value;
}

void	CpuRegisters::setH(u_int8_t value)
{
	H = value;
}

void	CpuRegisters::setL(u_int8_t value)
{
	L = value;
}

void	CpuRegisters::setBC(u_int16_t value)
{
	B = static_cast<u_int8_t>((value & 0xFF00) >> 8);
	C = static_cast<u_int8_t>((value & 0xFF));
}

void	CpuRegisters::setDE(u_int16_t value)
{
	D = static_cast<u_int8_t>((value & 0xFF00) >> 8);
	E = static_cast<u_int8_t>((value & 0xFF));
}

void	CpuRegisters::setHL(u_int16_t value)
{
	H = static_cast<u_int8_t>((value & 0xFF00) >> 8);
	L = static_cast<u_int8_t>((value & 0xFF));
}

void	CpuRegisters::setAF(u_int16_t value)
{
	A = static_cast<u_int8_t>((value & 0xFF00) >> 8);
	F = static_cast<u_int8_t>((value & 0xFF));
}

void	CpuRegisters::setCarryFlag()
{
	F = (F | 0b00010000);
}

void	CpuRegisters::setHalfCarryFlag()
{
	F = (F | 0b00100000);
}

void	CpuRegisters::setSubtractFlag()
{
	F = (F | 0b01000000);
}

void	CpuRegisters::setZeroFlag()
{
	F = (F | 0b10000000);
}

void	CpuRegisters::unsetCarryFlag()
{
	F = ~((~F | 0b00010000));
}

void	CpuRegisters::unsetHalfCarryFlag()
{
	F = ~((~F | 0b00100000));
}

void	CpuRegisters::unsetSubtractFlag()
{
	F = ~((~F | 0b01000000));
}

void	CpuRegisters::unsetZeroFlag()
{
	F = ~((~F | 0b10000000));
}
