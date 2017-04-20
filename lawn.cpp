// Anthony Ho
// 260501840
// lawn mower question 
// Solution decoded 

////////////////////////////////////////
// Logic Implementation of the program
////////////////////////////////////////
//
// Instead of using dynamic programming and greedy algorithm to check if all the position on field has been explore 
// we just have to sort all the trim position
// and then check if the distance between each trim is bigger than the machine cut width
// and if it does, it means that it will never going to trim the field perfectly
// we dont have to take care of the over lap between the cuts since we sorted the trim position
// then we only have to take care of the first and last edge cut
// we need to check if the first trim is more than half of the cut width
// if it does, it means that the person will never completely cover the field
// same logic applies to the last trim 
// we just need to substract it with 100 or 75 and check if the distance of it is more than 1/2 of the cut width
// if it does, it also means an uncomplete trim of the field
// 
////////////////////////////////////////




#include <iostream>
#include <algorithm>


using namespace std;

void lawn (int n1, int n2, double cut)
{
	// flag for x direction
	int flagx = 1;
	// flag for y director
	int flagy = 1;
	// for number of trim in x direction
	double length[n1];
	// scan through all the position in the x direction
	for (int i = 0; i < n1; i++)
	{
		cin >> length[i];
	}
	// sort the position of the trim in order
	sort(length, length + n1);

	// check if the position of the each trim doesnt not exceed the cut width of the machine
	for (int i = 1; i <= n1; i++)
	{
		if (length[i] -length[i-1] > cut)
		{
			flagx = 0;
			break;
		}
	}

	// same logic apply for the y direction
	double width[n2];
	for (int i = 0; i < n2; i++)
	{
		cin >> width[i];
	}
	sort(width, width+n2);
	for (int i = 1; i <=n2; i++)
	{
		if (width[i] -width[i-1] > cut)
		{
			flagy = 0;
			break;
		}
	}


	// check for end cases

	// check if the position of the first cut is more than half of the cut
	// coz u want to cover the last bit of the field
	// and also check of the final trim cover half of the cut width

	// initialize the flag and assume to be true
	int flag = 1;
	// check for the end cut and see if it exceed
	// if it does , it means uncomplete trim 
	// check for shorter side
	if ( (length[0] - cut/2) > 0  || (75 -length[n1 -1]) > (cut/2) )
	{
			flag = 0;
	}
	// same with the other direction
	if ((width[0] -cut/2) > 0 || (100 -width[n2 -1] > cut/2))
	{
		flag = 0;
	}

	// check if it pass all the flag test
	if (flagx == 1 && flagy == 1 && flag == 1)
	{
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main()
{
	int n1, n2;
	double cut;
	cin >> n1 >> n2 >> cut;
	while ( n1 != 0 && n2 != 0 && cut != 0)
	{
		lawn(n1, n2, cut);
		cin >> n1 >> n2 >> cut;
	}

	return 0;
}