/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuRegisters.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:00:31 by corellan          #+#    #+#             */
/*   Updated: 2024/11/13 15:47:38 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_REGISTERS_HPP
# define CPU_REGISTERS_HPP

# include <cstdlib>

class CpuRegisters
{
protected:
	u_int8_t	A;
	u_int8_t	B;
	u_int8_t	C;
	u_int8_t	D;
	u_int8_t	E;
	u_int8_t	F;
	u_int8_t	H;
	u_int8_t	L;

	bool		isCarryFlag() const;
	bool		isHalfCarryFlag() const;
	bool		isSubtractFlag() const;
	bool		isZeroFlag() const;
	u_int16_t	getBC() const;
	u_int16_t	getDE() const;
	u_int16_t	getHL() const;
	u_int16_t	getAF() const;
	u_int8_t	getA() const;
	u_int8_t	getB() const;
	u_int8_t	getC() const;
	u_int8_t	getD() const;
	u_int8_t	getE() const;
	u_int8_t	getF() const;
	u_int8_t	getH() const;
	u_int8_t	getL() const;
	void		setA(u_int8_t value);
	void		setB(u_int8_t value);
	void		setC(u_int8_t value);
	void		setD(u_int8_t value);
	void		setE(u_int8_t value);
	void		setF(u_int8_t value);
	void		setH(u_int8_t value);
	void		setL(u_int8_t value);
	void		setBC(u_int16_t value);
	void		setDE(u_int16_t value);
	void		setHL(u_int16_t value);
	void		setAF(u_int16_t value);
	void		setCarryFlag();
	void		setHalfCarryFlag();
	void		setSubtractFlag();
	void		setZeroFlag();
	void		unsetCarryFlag();
	void		unsetHalfCarryFlag();
	void		unsetSubtractFlag();
	void		unsetZeroFlag();

public:
	CpuRegisters();
	CpuRegisters(const CpuRegisters &other);
	CpuRegisters(CpuRegisters &&other) noexcept;
	~CpuRegisters();

	CpuRegisters	&operator=(const CpuRegisters &other);
	CpuRegisters	&operator=(CpuRegisters &&other) noexcept;

};

#endif
