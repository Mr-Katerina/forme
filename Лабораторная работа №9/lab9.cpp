#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
setlocale(0, "Rus");
int N1, N2, len, words;
string safe, safe2;
ifstream file1("F1.txt");
ofstream file2("F2.txt");
if (!(file1.is_open() and file2.is_open())) {
cout<< "Один из файлов не открыт";
return 0;
    }
cout<< "Введите N1: ";
cin>> N1;
cout<< "Введите N2: ";
cin>> N2;
while (!(N1 > 0 and N2 > 0 and N2 > N1)) {
cout<< "Неверно. Введите N1 и N2: ";
cin>> N1 >> N2;
    }
for (inti = 1; !file1.eof(); i++)
    {
getline(file1, safe);

if ((i> N1 and i<N2) and((safe[0] == 'a' or safe[0] == 'A') ))  {
        file2 << safe <<endl;
        safe2 = safe;
    }
if (i>= N2 + 3)
    {
        file2 << safe <<endl;
safe2 = safe;
    }
}

file1.close();
file2.close();

len = safe2.length();
words = 1;
for (inti = 0; i<len; i++) {
if ( safe2[i] == ' ') {
words++;
}
    }
cout<< "Количество слов в последней строке в F2.txt: " <<words;
}
