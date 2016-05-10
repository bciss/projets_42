#include "../inc/Processor.class.hpp"

Processor::Processor(void)
{
	this->determineActiveCoreNumber();
	this->determineProcessorModel();
	this->determineProcessorName();
	this->determineCoreNumber();
}

Processor::~Processor(void)
{
}

std::string Processor::getProcessorModel(void) const { return (this->_processorModel); }
unsigned int Processor::getActiveCoreNumber(void) const { return (this->_activeCoreNumber); }
std::string Processor::getProcessorName(void) const { return (this->_processorName); }
unsigned int Processor::getCoreNumber(void) const { return (this->_coreNumber); }
std::string Processor::getName(void) const { return (this->_name); }

void Processor::determineProcessorModel(void)
{
	char s[1024];
	size_t len;

	len = 1024;
	if (sysctlbyname("hw.model", s, &len, NULL, 0) == -1) {
	} else {
		this->_processorModel = s;
	}
}

void Processor::determineProcessorName(void)
{
	char s[1024];
	size_t len;

	len = 1024;
	if (sysctlbyname("machdep.cpu.brand_string", s, &len, NULL, 0) == -1) {
	} else {
		this->_processorName = s;
	}
}

void Processor::determineCoreNumber(void)
{
	unsigned int n;
	size_t len;

	len = sizeof(unsigned int);
	if (sysctlbyname("hw.ncpu", &n, &len, NULL, 0) == -1) {
	} else {
		this->_coreNumber = n;
	}
}

void Processor::determineActiveCoreNumber(void)
{
	unsigned int n;
	size_t len;

	len = sizeof(unsigned int);
	if (sysctlbyname("hw.activecpu", &n, &len, NULL, 0) == -1) {
	} else {
		this->_activeCoreNumber = n;
	}
}
