/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Memory.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:42:00 by corellan          #+#    #+#             */
/*   Updated: 2024/11/13 17:14:38 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_CPP
# define MEMORY_CPP

# include <array>
# include <sys/types.h>

class Memory
{
private:
	std::array<u_int8_t, (0xFFFF + 1)>	m_memory_block;
public:
	Memory();
	Memory(const Memory &other);
	Memory(Memory &&other) noexcept;
	~Memory();

	Memory	&operator=(const Memory &other);
	Memory	&operator=(Memory &&other) noexcept;

	u_int8_t	read_memory(u_int16_t address);
};

#endif
