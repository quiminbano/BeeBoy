#include "Cpu.hpp"
#include <memory>

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


