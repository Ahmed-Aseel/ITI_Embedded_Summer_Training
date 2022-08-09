#include "vote.h"

static unsigned int Ahmed_count = 0;
static unsigned int Omar_count = 0;
static unsigned int Zaki_count = 0;
static unsigned int Spoiled_count = 0;

void Cast_Vote()
{
	int candidate;
	printf("<<< Please choose your candidate >>>\n");
	printf("1: Ahmed \n");
	printf("2: Omar \n");
	printf("3: Zaki \n");
	printf("Note: Any other input will be considered as spoiled\n\n");
	printf("Please enter your choice (1:3) : ");
	scanf("%d", &candidate);	

	switch(candidate)
	{
	case 1:
		Ahmed_count++;
		break;

	case 2:
		Omar_count++;
		break;

	case 3:
		Zaki_count++;
		break;	
	
	default:
		Spoiled_count++;
		break;
	}

	printf("<<< THANKS For Your Voting >>>\n");
}
void Find_VoteCount()
{
	printf("<<< Voting Statistics >>>\n");
	printf("Ahmed - %d\n", Ahmed_count);
	printf("Omar - %d\n", Omar_count);
	printf("Zaki - %d\n", Zaki_count);
	printf("Spoiled Votes - %d\n", Spoiled_count);
}
void Find_Leading()
{
	if(Ahmed_count > Omar_count && Ahmed_count > Zaki_count)
	{
		printf("<<< Ahmed Is Leading >>>\n");			
	}
	else if(Omar_count > Ahmed_count && Omar_count > Zaki_count)
	{
		printf("<<< Omar Is Leading >>>\n");			
	}
	else if(Zaki_count > Ahmed_count && Zaki_count > Omar_count)
	{
		printf("<<< Zaki Is Leading >>>\n");
	}
	else
	{
		if(Ahmed_count == Omar_count && Ahmed_count == Zaki_count)
		{
			printf("<<< All Candidates Are Equal >>>\n");
		}		
		else if(Ahmed_count == Omar_count)
		{
			printf("<<< Ahmed And Omar Are Leading >>>\n");
		}	
		else if(Ahmed_count == Zaki_count)
		{
			printf("<<< Ahmed And Zaki Are Leading >>>\n");
		}		
		else
		{
			printf("<<< Omar And Zaki Are Leading >>>\n");
		}
	}
}
