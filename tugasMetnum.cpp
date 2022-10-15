#include <iostream>
#include <string>
#include <cmath>

using namespace std;

float fungsi(float x){
   return (x*x*x)-6*(x*x)+(11*x)-5.9;
}

float fungsitrn(float x)
{
   return 3*(x*x)-(12*x)+11;
}

bool cekTanda(float x){
   if(x >= 0){
      return true;
   } else{
      return false;
   }
}

int main();
float a,b,c,eror,sel,step=0,epsilon,count;

void wrt(float a,float b,float c) {
   cout << "-----Iterasi ke " << count << endl;
   cout << "a = " << a << endl;
   cout << "b = " << b << endl;
   cout << "f(a) = " << fungsi(a) << endl;
   cout << "f(b) = " << fungsi(b) << endl;
   cout << "c = " << c << endl;
   cout << "f(c) = " << fungsi(c) << endl;
}

void wrtnwt( float x, float x1 ) {
   cout << "-----Iterasi ke " << count << endl;
   cout << "x = " << x << endl;
   cout << "x+1 = " << x1 << endl;
   cout << "f(x) = " << fungsi(x) << endl;
   cout << "f'(x) = " << fungsitrn(x) << endl;
   cout << "f(x+1) = " << fungsi(x1) << endl;
   
}

void tabel(){
   a = 0;b = 0;
   while(fungsi(a)*fungsi(b) >= 0 || b <= a){
      cout << "Masukkan nilai a : ";cin >> a;
      cout << "Masukkan nilai b : ";cin >> b;
   }
   count = 1;
   cout << "\na = " << a << endl;
   cout << "b = " << b << endl;
   cout << "Masukkan step yang ingin dilakukan : ";cin >> step;
   if (step > b-a){
      tabel();
   } else{
      float i = a,temp;
      while (i < b){
         cout << count << ". x = " << i << " f(x) = " << fungsi(i) << endl;
         temp = i;
         i = i+step;
         count++;
         if (cekTanda(fungsi(temp)) != cekTanda(fungsi(i))){
            cout << count << ". x = " << i << " f(x) = " << fungsi(i) << endl;
            cout << "Aproksimari error ada pada iterasi ke " << count << " : " << min(abs(fungsi(temp)), abs(fungsi(i))) << endl << endl;
            break;
         }
      }
   }
   main();
}
void biseksi(){
   a = 0;b = 0;
   while(fungsi(a)*fungsi(b) >= 0 || b <= a){
      cout << "Masukkan nilai a : ";cin >> a;
      cout << "Masukkan nilai b : ";cin >> b;
   }
   count = 1;
   c = (a+b)/2;
   cout << "\nMasukkan epsilon : ";cin >> epsilon;
   while (abs(fungsi(c)) > epsilon){
      wrt(a,b,c);

      if (cekTanda(fungsi(c)) != cekTanda(fungsi(a))){
         b = c;
      } else {
         a = c;
      }
      c= (a+b)/2;
      count++;
   }
   wrt(a,b,c);
   cout << "\nPersamaan non linier : " << c << endl << endl;
   
   main();
}
void regula(){
   a = 0;b = 0;
   while(fungsi(a)*fungsi(b) >= 0 || b <= a){
      cout << "Masukkan nilai a : ";cin >> a;
      cout << "Masukkan nilai b : ";cin >> b;
   }
   count = 1;
   c = b-((fungsi(b)*(b-a))/(fungsi(b)-fungsi(a)));
   cout << "\nMasukkan epsilon : ";cin >> epsilon;
   while (abs(fungsi(c)) > epsilon){
      wrt(a,b,c);
      
      if (cekTanda(fungsi(c)) != cekTanda(fungsi(a))){
         b = c;
      } else {
         a = c;
      }
      c= b-((fungsi(b)*(b-a))/(fungsi(b)-fungsi(a)));
      count++;
   }
   wrt(a,b,c);
   cout << "\nPersamaan non linier : " << c << endl << endl;
   
   main();
}

void newtonraphson()
{
   float x;
   cout << "Masukkan nilai x : "; cin >> x;
   cout << "Masukkan epsilon : "; cin >> epsilon;

   float x1 = x - (fungsi(x)/fungsitrn(x));

   count = 1;
   while ( abs(fungsi(x1)) > epsilon )
   {
      wrtnwt ( x, x1 );
      x = x1;
      x1 = x - (fungsi(x)/fungsitrn(x));
      count++;
   }
   wrtnwt ( x, x1 );
   cout << "\nAkar persamaan = " << x1 << "\n\n";
   main();
}

int main(){
   int sel;

   cout 	<< "Pilih Metode yang akan digunakan : \n"
			<< "1. Metode tabel\n"
			<< "2. Biseksi\n"
			<< "3. Regula Falsi\n"
         	<< "4. Newton-Raphson\n"
         	<< "5. Secant\n"
         	<< "6. Iterasi\n"
			<< "7. Exit\n"
			<< "\nPilihan : "; cin >> sel;

   switch(sel)
   {
      case 1 : tabel(); break;
      case 2 : biseksi(); break;
      case 3 : regula(); break;
      case 4 : newtonraphson(); break;
      case 5 : break;
      case 6 : break;
      case 7 : break;
      default : main(); break;
   }

   return 0;
}
