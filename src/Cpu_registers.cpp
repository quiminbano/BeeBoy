/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu_registers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:35:16 by corellan          #+#    #+#             */
/*   Updated: 2024/10/09 15:28:01 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cpu_registers.hpp"

Cpu_registers::Cpu_registers()
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

Cpu_registers::Cpu_registers(const Cpu_registers &other)
{

}

Cpu_registers::Cpu_registers(const Cpu_registers &&other)
{

}

Cpu_registers::~Cpu_registers()
{
	
}

Cpu_registers	&Cpu_registers::operator=(const Cpu_registers &other)
{

}

Cpu_registers	&&Cpu_registers::operator=(const Cpu_registers &&other)
{
	
}

bool	Cpu_registers::isCarry() const
{
	return (((F >> 4) & 1) != 0);
}

bool	Cpu_registers::isHalfCarry() const
{
	return (((F >> 5) & 1) != 0);
}

bool	Cpu_registers::isSubtract() const
{
	return (((F >> 6) & 1) != 0);
}

bool	Cpu_registers::isZero() const
{
	return (((F >> 7) & 1) != 0);
}

u_int16_t	Cpu_registers::getBC() const
{
	return (((static_cast<u_int16_t>(B)) << 8) | (static_cast<u_int16_t>(C)));
}

u_int16_t	Cpu_registers::getDE() const
{
	return (((static_cast<u_int16_t>(D)) << 8) | (static_cast<u_int16_t>(E)));
}

u_int16_t	Cpu_registers::getHL() const
{
	return (((static_cast<u_int16_t>(H)) << 8) | (static_cast<u_int16_t>(L)));
}

u_int16_t	Cpu_registers::getAF() const
{
	return (((static_cast<u_int16_t>(A)) << 8) | (static_cast<u_int16_t>(F)));
}

u_int8_t	Cpu_registers::getA() const
{
	return (A);
}

u_int8_t	Cpu_registers::getB() const
{
	return (B);
}

u_int8_t	Cpu_registers::getC() const
{
	return (C);
}

u_int8_t	Cpu_registers::getD() const
{
	return (D);
}

u_int8_t	Cpu_registers::getE() const
{
	return (E);
}

u_int8_t	Cpu_registers::getF() const
{
	return (F);
}

u_int8_t	Cpu_registers::getH() const
{
	return (H);
}

u_int8_t	Cpu_registers::getL() const
{
	return (L);
}

void	Cpu_registers::setA(u_int8_t value)
{
	A = value;
}

void	Cpu_registers::setB(u_int8_t value)
{
	B = value;
}

void	Cpu_registers::setC(u_int8_t value)
{
	C = value;
}

void	Cpu_registers::setD(u_int8_t value)
{
	D = value;
}

void	Cpu_registers::setE(u_int8_t value)
{
	E = value;
}

void	Cpu_registers::setF(u_int8_t value)
{
	F = value;
}

void	Cpu_registers::setH(u_int8_t value)
{
	H = value;
}

void	Cpu_registers::setL(u_int8_t value)
{
	L = value;
}

void	Cpu_registers::setBC(u_int16_t value)
{
	B = static_cast<u_int8_t>((value & 0xFF00) >> 8);
	C = static_cast<u_int8_t>((value & 0xFF));
}

void	Cpu_registers::setDE(u_int16_t value)
{
	D = static_cast<u_int8_t>((value & 0xFF00) >> 8);
	E = static_cast<u_int8_t>((value & 0xFF));
}

void	Cpu_registers::setHL(u_int16_t value)
{
	H = static_cast<u_int8_t>((value & 0xFF00) >> 8);
	L = static_cast<u_int8_t>((value & 0xFF));
}

void	Cpu_registers::setAF(u_int16_t value)
{
	H = static_cast<u_int8_t>((value & 0xFF00) >> 8);
	L = static_cast<u_int8_t>((value & 0xFF));
}

void	Cpu_registers::setCarry()
{
	F = (F | 0b00010000);
}

void	Cpu_registers::setHalfCarry()
{
	F = (F | 0b00100000);
}

void	Cpu_registers::setSubtract()
{
	F = (F | 0b01000000);
}

void	Cpu_registers::setZero()
{
	F = (F | 0b10000000);
}

void	Cpu_registers::unsetCarry()
{
	F = ~((~F | 0b00010000));
}

void	Cpu_registers::unsetHalfCarry()
{
	F = ~((~F | 0b00100000));
}

void	Cpu_registers::unsetSubtract()
{
	F = ~((~F | 0b01000000));
}

void	Cpu_registers::unsetZero()
{
	F = ~((~F | 0b10000000));
}
