#include <iostream>
#include <ctime>

#define TIMESTAMP 18

int	main(void)
{
	std::time_t	base_time;
	std::tm		*time;
	char		timestamp[TIMESTAMP];

	//Sets current time
	std::time(&base_time);
	//Passes current time to tm struct format (as local time)
	time = std::localtime(&base_time);
	//Formats output using tm struct fields
	strftime(timestamp, TIMESTAMP, "[%Y%m%d_%H%M%S]", time);
	std::cout << timestamp << std::endl;
	return (0);
}