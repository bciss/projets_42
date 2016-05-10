#include "../inc/Host.class.hpp"

Host::Host(void)
{
	this->determineHostName();
	this->determineUserName();
}

Host::~Host(void)
{
}

std::string Host::getHostName(void) const { return (this->_hostName); }
std::string Host::getUserName(void) const { return (this->_userName); }
std::string Host::getName(void) const { return (this->_name); }

void Host::determineHostName(void)
{
	char s[1024];
	size_t len;

	len = 1024;
	if (sysctlbyname("kern.hostname", s, &len, NULL, 0) == -1) {
	} else {
		this->_hostName = s;
	}
}

void Host::determineUserName(void)
{
	struct passwd *passwd;
	uid_t uid;

	uid = getuid();
	if ((passwd = getpwuid(uid)))
		this->_userName = passwd->pw_name;
}
