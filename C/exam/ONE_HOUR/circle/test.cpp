/*
#include <iostream>

using namespace std;

int main()
{
float y,k;
cout<< " Enter the Radius of the desired circle size";
cin>> y;
float m = 2;

for (int i = -y; i <= y; i++)
{
for (int j = -y; j <= y; j++)
{
k = ((i*m)/y)*((i*m)/y) + (j/y)*(j/y);

if (k >0.95 && k<1.08)
{
cout << "*";
}
else
{
cout << " ";
}
}
cout << endl;
}
//	getch();
}
 */
#include <iostream> 
#include <math.h> 

using namespace std; 

int pth (int x,int y)  { 
	return sqrt (pow(x,2)+pow(y,2)); 
} 

int main (int ac, char **av)  { 

	int c=0; 
	int r=atoi(av[1]); 

	const int width=r; 
	const int length=r*1.5; 

	for (int y=width;y >= -width;y-=2)  { 
		for (int x=-length;x <= length;x++)  { 

			if ((int) pth(x,y)==r) cout << "*"; 
			else cout << " "; 

		} 
		cout << "\n"; 
	} 

	return 0; 
} 
