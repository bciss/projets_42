#ifndef HOST_CLASS_H
# define HOST_CLASS_H

# include "ft_gkrellm.hpp"

class Host
{
	public:
		Host(void);
		virtual ~Host(void);

		std::string getHostName(void) const;
		std::string getUserName(void) const;
		std::string getName(void) const;

		void determineHostName(void);
		void determineUserName(void);

	private:
		Host(Host const & inst);

		std::string _hostName;
		std::string _userName;
		std::string _name;

		Host const & operator=(Host const & inst);
};

#endif
