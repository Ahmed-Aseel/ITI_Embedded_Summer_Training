#include "vote.h"

int main()
{
	int choice;
	while(1)
	{
		printf("\n#### Welcome to Election/Voting 2022 #### \n\n");
		printf("Choose one of the following options \n");
		printf("1: Cast The Vote \n");
		printf("2: Find Vote Count \n");
		printf("3: Find Leading Candidate \n");
		printf("0: Exit \n\n");
		printf("Please enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			Cast_Vote();
			break;

		case 2:
			Find_VoteCount();
			break;

		case 3:
			Find_Leading();
			break;

		case 0:
			printf("<<< THANK YOU >>>\n");
			exit(0);

		default:
			printf("<<< Wrong Choice!!! >>>\n");
			break;
		}
	}
	
	return 0;
}