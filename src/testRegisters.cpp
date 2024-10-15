/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testRegisters.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:13:13 by corellan          #+#    #+#             */
/*   Updated: 2024/10/15 13:10:59 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cpu_registers.hpp"
#include <iostream>
#include <vector>
#include <unistd.h>

template <typename T>
static void	assert_eq(T expected, T actual)
{
	std::cout << "Expected: " << expected << ", Actual: " << actual << ", ";
	if (expected != actual)
		std::cout << "\x1b[0;31m" << "KO" << "\x1b[0m"  << std::endl;
	else
		std::cout << "\x1b[0;32m" << "OK" << "\x1b[0m" << std::endl;	
	usleep(500);
}

int main(void)
{
	Cpu_registers	test_registers;
	std::vector<u_int16_t>	test_values_16_bits = {0x1234, 0x5678, 0x9ABC, 0xDEF0, 0xFF00, 0x00FF, 0x0000, 0xFFFF};
	std::vector<std::pair<u_int8_t, u_int8_t>>	pairs_8_bits = {{0x12, 0x34}, {0x56, 0x78}, {0x9A, 0xBC}, {0xDE, 0xF0}, {0xFF, 0x00}, {0x00, 0xFF}, {0x00, 0x00}, {0xFF, 0xFF}};
	size_t	index = 0;

	std::cout << "Testing pair of registers BC, DE, HL and AF, setting values of 16 bits: " << std::endl;
	while (index < 8)
	{	std::cout << "Test " << index + 1 << "." << std::endl;
		test_registers.setBC(test_values_16_bits[index]);
		std::cout << "Checking BC register." << std::endl;
		assert_eq<u_int16_t>(test_values_16_bits[index], test_registers.getBC());
		std::cout << "Checking B and C registers separately." << std::endl;
		assert_eq<u_int8_t>(pairs_8_bits[index].first, test_registers.getB());
		assert_eq<u_int8_t>(pairs_8_bits[index].second, test_registers.getC());
		test_registers.setDE(test_values_16_bits[index]);
		std::cout << "Checking DE register." << std::endl;
		assert_eq<u_int16_t>(test_values_16_bits[index], test_registers.getDE());
		std::cout << "Checking D and E registers separately." << std::endl;
		assert_eq<u_int8_t>(pairs_8_bits[index].first, test_registers.getD());
		assert_eq<u_int8_t>(pairs_8_bits[index].second, test_registers.getE());
		test_registers.setHL(test_values_16_bits[index]);
		std::cout << "Checking HL register." << std::endl;
		assert_eq<u_int16_t>(test_values_16_bits[index], test_registers.getHL());
		std::cout << "Checking H and L registers separately." << std::endl;
		assert_eq<u_int8_t>(pairs_8_bits[index].first, test_registers.getH());
		assert_eq<u_int8_t>(pairs_8_bits[index].second, test_registers.getL());
		test_registers.setAF(test_values_16_bits[index]);
		std::cout << "Checking AF register." << std::endl;
		assert_eq<u_int16_t>(test_values_16_bits[index], test_registers.getAF());
		std::cout << "Checking A and F registers separately." << std::endl;
		assert_eq<u_int8_t>(pairs_8_bits[index].first, test_registers.getA());
		assert_eq<u_int8_t>(pairs_8_bits[index].second, test_registers.getF());
		index++;
		std::cout << std::endl;
	}
	std::cout << "Testing flag setup (Register F) and correct checking of these." << std::endl;
	test_registers.setF(0);
	test_registers.setCarryFlag();
	std::cout << "Setting Carry flag." << std::endl;
	std::cout << "Checking Carry flag as boolean." << std::endl;
	assert_eq<bool>(true, test_registers.isCarryFlag());
	std::cout << "Checking Carry flag as u_int8_t." << std::endl;
	assert_eq<u_int8_t>(0x10, test_registers.getF());
	test_registers.unsetCarryFlag();
	std::cout << "Unsetting Carry flag." << std::endl;
	std::cout << "Checking Carry flag as boolean after unsetting." << std::endl;
	assert_eq<bool>(false, test_registers.isCarryFlag());
	std::cout << "Checking Carry flag as u_int8_t." << std::endl;
	assert_eq<u_int8_t>(0x00, test_registers.getF());
	test_registers.setF(0);
	test_registers.setHalfCarryFlag();
	std::cout << std::endl << "Setting Half Carry flag." << std::endl;
	std::cout << "Checking Half Carry flag as boolean." << std::endl;
	assert_eq<bool>(true, test_registers.isHalfCarryFlag());
	std::cout << "Checking Carry Half flag as u_int8_t." << std::endl;
	assert_eq<u_int8_t>(0x20, test_registers.getF());
	test_registers.unsetHalfCarryFlag();
	std::cout << "Unsetting Half Carry flag." << std::endl;
	std::cout << "Checking Half Carry flag as boolean after unsetting." << std::endl;
	assert_eq<bool>(false, test_registers.isHalfCarryFlag());
	std::cout << "Checking Half Carry flag as u_int8_t." << std::endl;
	assert_eq<u_int8_t>(0x00, test_registers.getF());
	test_registers.setF(0);
	test_registers.setSubtractFlag();
	std::cout << std::endl << "Setting Substract flag." << std::endl;
	std::cout << "Checking Substract flag as boolean." << std::endl;
	assert_eq<bool>(true, test_registers.isSubtractFlag());
	std::cout << "Checking Substract flag as u_int8_t." << std::endl;
	assert_eq<u_int8_t>(0x40, test_registers.getF());
	test_registers.unsetSubtractFlag();
	std::cout << "Unsetting Substract flag." << std::endl;
	std::cout << "Checking Substract flag as boolean after unsetting." << std::endl;
	assert_eq<bool>(false, test_registers.isSubtractFlag());
	std::cout << "Checking Substract flag as u_int8_t." << std::endl;
	assert_eq<u_int8_t>(0x00, test_registers.getF());
	test_registers.setF(0);
	test_registers.setZeroFlag();
	std::cout << std::endl << "Setting Zero flag." << std::endl;
	std::cout << "Checking Zero flag as boolean." << std::endl;
	assert_eq<bool>(true, test_registers.isZeroFlag());
	std::cout << "Checking Zero flag as u_int8_t." << std::endl;
	assert_eq<u_int8_t>(0x80, test_registers.getF());
	test_registers.unsetZeroFlag();
	std::cout << "Unsetting Zero flag." << std::endl;
	std::cout << "Checking Zero flag as boolean after unsetting." << std::endl;
	assert_eq<bool>(false, test_registers.isZeroFlag());
	std::cout << "Checking Zero flag as u_int8_t." << std::endl;
	assert_eq<u_int8_t>(0x00, test_registers.getF());
	std::cout << std::endl << "Testing unset flags when more than one flag is setted to true" << std::endl;
	test_registers.setF(0xF0);
	std::cout << "Setting all flags to true and Checking one by one." << std::endl;
	std::cout << "Checking Carry flag as boolean." << std::endl;
	assert_eq<bool>(true, test_registers.isCarryFlag());
	std::cout << "Checking Half Carry flag as boolean." << std::endl;
	assert_eq<bool>(true, test_registers.isHalfCarryFlag());
	std::cout << "Checking Substract flag as boolean." << std::endl;
	assert_eq<bool>(true, test_registers.isSubtractFlag());
	std::cout << "Checking Zero flag as boolean." << std::endl;
	assert_eq<bool>(true, test_registers.isZeroFlag());
	std::cout << "Unsetting Substract flag." << std::endl;
	test_registers.unsetSubtractFlag();
	std::cout << "Checking Carry flag after unsetting Substract flag" << std::endl;
	assert_eq<bool>(true, test_registers.isCarryFlag());
	std::cout << "Checking Half Carry flag after unsetting Substract flag" << std::endl;
	assert_eq<bool>(true, test_registers.isHalfCarryFlag());
	std::cout << "Checking Substract flag after unsetting Substract flag" << std::endl;
	assert_eq<bool>(false, test_registers.isSubtractFlag());
	std::cout << "Checking Zero flag after unsetting Substract flag" << std::endl;
	assert_eq<bool>(true, test_registers.isZeroFlag());
	std::cout << "Checking F register after unsetting Substract flag as number." << std::endl;
	assert_eq<u_int8_t>(0xB0, test_registers.getF());
	return (0);
}
