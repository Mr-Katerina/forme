#include <iostream>
#include <string>
using namespace std;
struct Film {
string nazvanie;
string namerezh;
int year;
int price;
};
Film* films;
constint z = 1;
voidproverka(int&num) {
cin>>num;
while(true)
	   {
		if (num<=0) {
	cout<< "некорректный ввод, введите заново: ";
cin>>num;
} else break;}}

voidzapolnenie(Film filmsar[], int k) {
cout<< "Введите данные о фильмах: ";
for (inti = 0; i< k; i++) {
cout<< "введите название фильма: " <<endl; 
getline(cin, filmsar[i].nazvanie,',');

cout<< "введите имя режиссера: " <<endl; 
getline(cin,filmsar[i].namerezh,','); 

cout<< "введите год выпуска фильма: " <<endl; 
proverka(filmsar[i].year);
cout<< "введитестоимость: " <<endl; 
proverka(filmsar[i].price);
cout<<endl;

    }
}
voidvivod(int k) {
if (k == 0)
cout<< "фильмовнет!";
else {
cout<<endl;
cout<< "Информация о фильмах: ";
for (inti = 0; i< k; i++) {

cout<<"введитеназваниефильма: "<<films[i].nazvanie<<endl;
		cout<<"введитеимярежиссера: "<<films[i].namerezh<<endl;
		cout<<"введитегод: "<<films[i].year<<endl;
		cout<<"введитецену: "<<films[i].price<<endl;
        }
    }
}
voiddobavlenie(int& k) {
    Film* kino = new Film[k + z];
zapolnenie(kino,z);
for (inti = 0; i< k; i++)
kino[i + z] = films[i];
    k += z;
films =kino;
}
void deleted(int& k, unsigned intneedprice) {

for (inti = 0; i< k; i++)

		if (films[i].price >needprice) {

			while (i< k - 1) {

				films[i] = films[i + 1];
				i++;
			}

			k--;

			Film* kino = new Film[k];

			for (inti = 0; i< k; i++)

				kino[i] = films[i];

			films = kino;

		}
}

int main()
{
setlocale(LC_ALL, "rus");
system("chcp 1251>nul");
cout<< "Введите количество фильмов: ";
int n = 0;
proverka(n);
films = new Film[n];
zapolnenie(films, n);
vivod(n);
cout<< "сокращние списка фильмов: ";
cout<< "Введите определенную стоимость: ";
intneedprice;
proverka(needprice);
deleted(n,needprice);
vivod(n);
cout<< "добавление нового элемента";
dobavlenie(n);
cout<< "обновленный список фильмов: ";
vivod(n);
system("pause");
return 0;
}
