/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:34:16 by corellan          #+#    #+#             */
/*   Updated: 2024/10/09 13:34:17 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ui.hpp"

int	main(void)
{
	UI ui = new UI();

	if (ui.init() == false)
	{
		return (1);
	}

	while (ui.isRunning())
	{
		ui.checkEvents();
	}

	return (0);
}
