/*Krzysztof Wójcik 
  248919
  TODO:
  -KOREKTY WG SEKWOJI MUCHY
  -DOKUMENTACJA ITP
  -DODATKOWE USPRAWNIENIA FUNKCI ODCZYT*/
  
#include <stdio.h>
float odczyt()
{
  int l_dz = 0, l_jd = 0, cz_d = 0, cz_s = 0;
  float ost_liczba = 0;
  char znak[25] = {88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88};
  int a = 24;
  fgets(znak, sizeof znak, stdin);

  while(!((znak[a] -48) > -1 && (znak[a] -48 < 10)) && a != -1) /*jeśli znak nie jest cyfrą i nr. tablicy jest ok*/
    {
      a--;
    }
  /*a - nr tab ostatniej cyfry w wierszu, -1 to brak cyfr w wierszu*/
  /*ASCII 57 - '9' => -48 analogicznie mniejsze pozostałe, 46 - '.'*/
  /*program prawidłowo rozpoznaje tylko ZCC.CC lub ZC.CC*/
  cz_s = znak[a--] -48; /*na pewno cyfra*/
  cz_d = znak[a--] -48; /*przeskok nad kropką */
  l_jd = znak[--a] -48;
  if((znak[--a] -48) > -1 && (znak[a] -48 < 10 )) l_dz = znak[a] - 48; /* else nie potrzebne*/
  ost_liczba = l_dz * 10 + l_jd * 1 + cz_d * 0.1 + cz_s * 0.01;
  if(znak[a] == 45) ost_liczba = -ost_liczba; /* - c.cc = -c.cc -> błąd do poprawy*/
  else if(znak[--a] == 45) ost_liczba = -ost_liczba;
  /*printf("%f\n", ost_liczba); */
  return ost_liczba;
}
int main()
{
  float od1 = 0, od2 = 0;
  short int przec = 0, licz = 0;
  printf("PROGRAM DZIAŁA POPRAWNIE DLA LICZB ZAPISANYCH W FORMACIE:\nZCC.CC lub ZC.CC gdzie Z - Znak, C - Cyfra\nNa przykład wartość -1 należy zapisać jako -1.00\n");
  while(1)
    {
        while(licz != 100) /* co z pustym wierszem? - pusty wiersz zwraca błędną, ujemną wartość ok -101, więc jest również wliczany jako odczyt, stąd 100 - od zera do 99 bo 100 nie jest != 100*/
	  {
	    od2 = odczyt(); 
	    if(od2 < -10 || od2 > 10)
	      {
		if(od2 != 99) printf("Błąd\n");
		else return 0; /*?*/
	      }
	    licz++;
	    if((od1 * od2) < 0) przec++;
	    if(od2 !=0 && (od2 > -10 && od2 < 10)) od1 = od2;
	  }
	if(przec > 7 && przec < 15) printf("%hd\n", przec); /*co 99 odczytów + pusty wiersz*/
	else printf("NIEPOPRAWNA CZĘSTOTLIWOŚĆ\n");
	licz = 0;
	przec = 0;
    }
  return 0;
}
