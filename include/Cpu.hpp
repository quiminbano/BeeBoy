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

#include "CpuRegisters.hpp"

class Cpu : public CpuRegisters
{
public:
	Cpu();
	Cpu(const Cpu &other);
	Cpu(Cpu &&other) noexcept;
	~Cpu();

	Cpu		&operator=(const Cpu &other);
	Cpu		&operator=(Cpu &&other) noexcept;

	void	add(u_int16_t value);
	void	addHL(u_int16_t value);
	void	adc(u_int8_t value);
	void	sub();
	void	sbc(u_int8_t value);
	void	andbw(u_int8_t value);
	void	orbw(u_int8_t value);
	void	xorbw(u_int8_t value);
	void	cp(u_int8_t value);
	void	inc(u_int8_t &reg);
	void	dec(u_int8_t &reg);
	void	ccf();
	void	scf();
	void	rra();
	void	rla();
	void	rrca();
	void	rrla();
	void	cpl();
	void	bit();
	void	reset(u_int8_t &reg, unsigned char bit);
	void	set(u_int8_t &reg, unsigned char bit);
	void	srl(u_int8_t &reg);
	void	rr(u_int8_t &reg);
	void	rl(u_int8_t &reg);
	void	rrc(u_int8_t &reg);
	void	rlc(u_int8_t &reg);
	void	sra(u_int8_t &reg);
	void	sla(u_int8_t &reg);
	void	swap(u_int8_t &reg);
};

#endif
