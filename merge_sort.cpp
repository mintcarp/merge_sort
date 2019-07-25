#include<iostream>
#include<math.h>
using namespace std;

void Union(int *a, int b, int e)
{
	int m,s,f,j;
	int *buf = new int[e+1];
	m = (b + e)/2;
	s = b;
	f = m + 1;
	cout << m << "  " << s << " " << f << endl;
	for( j = b; j < e +1; j++)
	{
		if((s <= m) && ((f > e) || (a[s] < a[f])))
		{
			buf[j] = a[s];
			s++;
		}
		else
		{
			buf[j] = a[f];
			f++;	
		}
	}
	for(j = b; j < e +1; j++)
		a[j] = buf[j];
	
	delete[]buf;
	
}

void Sort (int *a,int b, int e)
{
	if(b < e)
	{
		int m = (b + e)/2;
		Sort(a,b,m);
		Sort(a,m + 1, e);
		Union(a,b,e);
	}
}
int main(){
	int array[9] = {2,4,3,9,7,8,1,5,6};
	cout << "Array before sort:" << endl;
	for(int i = 0; i < 9; i++)
		cout << array[i] << " ";
		
	cout << endl;
	
	Sort(array,0,8);
	cout << "Array after sort:" << endl;
	for(int i = 0; i < 9; i++)
		cout << array[i] << " ";	

	return 0;
}
