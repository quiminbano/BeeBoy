/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:42:00 by corellan          #+#    #+#             */
/*   Updated: 2024/11/13 17:14:38 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
# define CPU_HPP

# include "CpuRegisters.hpp"
# include "Memory.hpp"
#include <sys/types.h>

class Cpu : public CpuRegisters
{
private:
	u_int16_t	SP;
	u_int16_t	CP; //Program counter
	Memory		m_memory;
public:
	Cpu();
	Cpu(const Cpu &other);
	Cpu(Cpu &&other) noexcept;
	~Cpu();

	Cpu		&operator=(const Cpu &other);
	Cpu		&operator=(Cpu &&other) noexcept;

	void		ld(u_int8_t &reg, u_int8_t value);
	void		add(u_int8_t value);
	void		addHL(u_int16_t value);
	void		adc(u_int8_t value);
	void		sub(u_int8_t value);
	void		sbc(u_int8_t value);
	void		andbw(u_int8_t value);
	void		orbw(u_int8_t value);
	void		xorbw(u_int8_t value);
	void		cp(u_int8_t value);
	void		inc(u_int8_t &reg);
	void		dec(u_int8_t &reg);
	void		ccf();
	void		scf();
	void		rra();
	void		rla();
	void		rrca();
	void		rrla();
	void		cpl();
	void		bit(u_int8_t &reg, u_int8_t bit);
	void		reset(u_int8_t &reg, u_int8_t bit);
	void		set(u_int8_t &reg, u_int8_t bit);
	void		srl(u_int8_t &reg);
	void		rr(u_int8_t &reg);
	void		rl(u_int8_t &reg);
	void		rrc(u_int8_t &reg);
	void		rlc(u_int8_t &reg);
	void		sra(u_int8_t &reg);
	void		sla(u_int8_t &reg);
	void		swap(u_int8_t &reg);
	u_int16_t	getSP() const;
	void		setSP(u_int16_t value);
	u_int16_t	getCP() const;
	void		setCP(u_int16_t value);
};

#endif
