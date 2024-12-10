/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Memory.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:42:00 by corellan          #+#    #+#             */
/*   Updated: 2024/11/13 17:14:38 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Memory.hpp"
#include <cstddef>

Memory::Memory() : m_memory_block({ 0 })
{

}

Memory::~Memory()
{

}

Memory::Memory(const Memory &other)
{
	size_t	index;

	index = 0;
	while (index < 0xFFFF)
	{
		m_memory_block[index] = other.m_memory_block[index];
		index++;
	}
}

Memory::Memory(Memory &&other) noexcept
{
	size_t	index;

	index = 0;
	while (index < 0xFFFF)
	{
		m_memory_block[index] = other.m_memory_block[index];
		index++;
	}
	index = 0;
	while (index < 0xFFFF)
	{
		other.m_memory_block[index] = 0;
		index++;
	}
}

Memory	&Memory::operator=(const Memory &other)
{
	size_t	index;

	index = 0;
	if (this == &other)
		return (*this);
	while (index < 0xFFFF)
	{
		m_memory_block[index] = other.m_memory_block[index];
		index++;
	}
	return (*this);
}

Memory	&Memory::operator=(Memory &&other) noexcept
{
	size_t	index;

	index = 0;
	if (this == &other)
		return (*this);
	while (index < 0xFFFF)
	{
		m_memory_block[index] = other.m_memory_block[index];
		index++;
	}
	index = 0;
	while (index < 0xFFFF)
	{
		other.m_memory_block[index] = 0;
		index++;
	}
	return (*this);
}
