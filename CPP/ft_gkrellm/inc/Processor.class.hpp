#ifndef PROCESSOR_CLASS_H
# define PROCESSOR_CLASS_H

# include "ft_gkrellm.hpp"

class Processor
{
	public:
		Processor(void);
		virtual ~Processor(void);

		unsigned int getActiveCoreNumber(void) const;
		std::string getProcessorModel(void) const;
		std::string getProcessorName(void) const;
		unsigned int getCoreNumber(void) const;
		std::string getName(void) const;

		void determineActiveCoreNumber(void);
		void determineProcessorModel(void);
		void determineProcessorName(void);
		void determineCoreNumber(void);

	private:
		Processor(Processor const & inst);

		unsigned int _activeCoreNumber;
		std::string _processorModel;
		std::string _processorName;
		unsigned int _coreNumber;
		std::string _name;

		Processor const & operator=(Processor const & inst);
};

#endif
