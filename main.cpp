#include <iostream>

using namespace std;

void naslowa(int liczba)
{
 string licz[4][9]{
 {"jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"},
 {"dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"},
 {"sto", "dwiescie", "trzysta", "czterysta","piecset", "szescset", "siedemset", "osiemset", "dziewiecset"},
 {"jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie" }
 };
 string tys[3]{"tysiace","tysiecy","tysiac"};
 string ostat;
 int nr[6];
 if (liczba==0) cout<<"zero";
 for (int i=0;i<6;i++)
 {
 	nr[i]=liczba%10;
 	liczba=liczba/10;
 }
if (nr[5]!=0)
{	
	if(nr[4]==0&&nr[3]==0)ostat+=licz[2][nr[5]-1]+" "+tys[1]+" ";
 	else ostat=licz[2][nr[5]-1]+" ";
}
 if (nr[4]!=0)
 {
	if(nr[3]==0){ostat+=licz[1][nr[4]-1]+" "+tys[1]+" ";}
	else if (nr[4]==1){ostat+=licz[3][nr[3]-1]+" "+tys[1]+" ";nr[3]=0;}
	else {ostat+=licz[1][nr[4]-1]+" ";}
 }
if (nr[3]!=0)
{	
	if ((nr[3]==1)&&(nr[4]==0)&&(nr[5]==0)) ostat+=tys[2]+" ";
	else if (nr[3]==1) ostat+=licz[0][nr[3]-1]+" "+tys[1]+" "+tys[2]+" ";
	else if ((nr[3]==2)||(nr[3]==3)||(nr[3]==4))
		ostat+=licz[0][nr[3]-1]+" "+tys[0]+" ";
	else ostat+=licz[0][nr[3]-1]+" "+tys[1]+" ";
}
if (nr[2]!=0)
	ostat+=licz[2][nr[2]-1]+" ";
if (nr[1]!=0)
{
	if ((nr[1]==1)&&(nr[0]!=0))
		{ostat+=licz[3][nr[0]-1];nr[0]=0;}
	else 
	{
			ostat+=licz[1][nr[1]-1]+" ";
	if (nr[0]!=0)
		ostat+=licz[0][nr[0]-1];nr[0]=0;
	}
}	
if (nr[0]!=0)
	ostat+=licz[0][nr[0]-1];


cout<<ostat;
} 
int wynik=0;
int binarne(int liczba1)
{	
int k=0;
int nr[6];
while (wynik<999999)
{	
 	k++;
 	int spr=0;
 	 	wynik=liczba1*k;
	  for(int i = 0; i < 6; i++)
		{
 			nr[i] = wynik%10;
			if (nr[i]==0||nr[i]==1) spr++; else break;
 			wynik = (wynik/10);
		}
	wynik=liczba1*k;
	if (spr==6) break;	
 }
return k;      
}
int main(int argc, char* argv[])
{
int n=atoi(argv[1]);
cout<<endl<<"liczba poczatkowa: ";naslowa(n);
binarne(n);
if (wynik<1000000)
{
cout<<endl<<"k to: ";naslowa(binarne(n));
cout<<endl<<"wynik mnozenia to: ";naslowa(wynik);
}
else 
	cout<<endl<<"za duzy wynik mnozenia,nie mozna go wyswietlic";
	
}
