#include <iostream>
#include <string>
#include <cmath>

using namespace std;

float fungsi(float x){
   return (x*x)-x-2;
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

int main(){
   cout 	<< "Pilih Metode yang akan digunakan : \n"
			<< "1. Metode tabel\n"
			<< "2. Biseksi\n"
			<< "3. Regula Falsi\n"
			<< "4. Exit\n"
			<< "\nPilihan : "; cin >> sel;

   if (sel == 1){
      tabel();    
   }
   else if (sel == 2){
      biseksi();
   }
   else if (sel == 3){
      regula();
   }
   else if (sel == 4){
      exit;
   }
   else{
      main();
   }
   return 0;
}