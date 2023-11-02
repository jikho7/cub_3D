# include <cub3d.h>

void error_msg(int option)
{
	if (option == 0)
		printf("Error: Doublon\n");
	if (option == 1)
		printf("Error: Wrong spelling\n");
	if (option == 2)
		printf("Error: Invalid extension\n");
	if (option == 3)
		printf("Error: Invalid texture extension\n");
	if (option == 4)
		printf("Error: Bad coordinates\n");
	if (option == 5)
		printf("Error: Excessive information\n");
	if (option == 6)
		printf("Error: Info after map\n");
	if (option == 7)
		printf("Error: More than one player\n");
	if (option == 8)
		printf("Error: Wrong map symbol\n");
	if (option == 9)
		printf("Error: A wall is missing\n");
	if (option == 10)
		printf("Error: Empty file\n");
	if (option == 11)
		printf("Error: No map\n");
	if (option == 12)
		printf("Error: Missing information\n");
	if (option == 13)
		printf("Error: Missing Player\n");
	if (option == 14)
		printf("Error: empty line in map\n");
	//free_ft();
	exit(0) ;
}
