#include "iostream"
//#define n 4
using namespace std;
struct student
{
	char book[10];
	char Fam[40];
	char name[20];
	int day1;
	int month1;
	int year1;
	int day2;
	int month2;
	int year2;
};

void student_in(student *st)
{
	
		cout<< "Заполните сведения о студенте."<<endl<<"Номер зачетной книжки u Дата поступления,  ";
	puts("зачетная книжка="); scanf("%s",&(*st).book);
//	cin>>st.book;
		cout<<endl<< "Фамилия"<<endl;
	scanf("%s",&(*st).Fam);
		cout<<endl<< "Имя"<<endl;
	scanf("%s",&(*st).name);
		cout<<endl<< "Дата рождения: день"<<endl;
	scanf("%d",&(*st).day1);
		cout<<endl<< "месяц"<<endl;
	scanf("%d",&(*st).month1);
		cout<<endl<< "год"<<endl;
	scanf("%d",&(*st).year1);
	cout<<endl<< "Дата поступления"<<endl<<"День ";
	scanf("%d",&(*st).day2);
		cout<<endl<< "Месяц"<<endl;
	scanf("%d",&(*st).month2);
		cout<<endl<< "Год"<<endl;
	scanf("%d",&(*st).year2);	
	
}

void student_out(student st)
{
	cout<< "Cведения о студенте:"<<"  "<<st.Fam<<"  "<<st.name<<"  Дата рожждения  "<<st.day1<<"  "<< st.month1<<"   "<<st.year1<<"  ";
	cout<< "Номер зачетной книжки:   "<<st.book<< "  ";
	cout<< "Дата поступления,  ";
	cout<< st.day2<< "   "<<st.month2<< "  "<<st.year2<< endl;

}

// Заполнение массива данными сессии по студентам группы.
void inp_massiv_group(student *mas, int nn)//а это массив сессий 
{
	int  i;
	for(i=0;i<nn;i++)
	{
	student_in(&mas[i]);
	}
}

void out_massiv_group(student *mas, int nn)//а это массив сессий 
{
	int  i;
	for(i=0;i<nn;i++)
	{
	student_out(mas[i]);
	}
}

int  mass( student st)
{ int a;

   a=st.day1+st.month1*10e3+st.year1*10e5;
//  cout<<a<<"\t";
 
	return a;
}

void selectionSort( int size, student *st)
{
  int min;
  student temp; // для поиска минимального элемента и для обмена
  for (int i = 0; i < size ; i++) 
  {
    min = i; // запоминаем индекс текущего элемента
    // ищем минимальный элемент чтобы поместить на место i-ого
    for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
    {
	  if (mass(st[j]) < mass(st[min]))// если элемент меньше минимального,
        min = j;       // запоминаем его индекс в min
    }
    temp = st[i];      // меняем местами i-ый и минимальный элементы
    st[i] = st[min];
    st[min] = temp;
  }
}


void new_mass( student *st, int nn, int g, int &l )
{int j=0;
	for (int i = 0; i < nn; i++) 
  { 
  	 if (st[i].year2 >g )
  	 {
   		st[j]=st[i];
   		j++;
   	 }
  }
  l=j;
	
}

int main()
{int a;
	int n=0;
	setlocale(LC_ALL, "rus");

	
	cout<< " Введите количество студентов";
	cin>>n;
	student st[n];
	inp_massiv_group(st, n);
	out_massiv_group(st, n);
	
	selectionSort ( n, st);
	cout<<"Sort"<<endl<<endl;
	out_massiv_group(st, n);

	int g;
	g=2018-6;
	int l;
	new_mass(st, n, g, l);
	cout<<"Delit"<<endl;
	out_massiv_group(st, l);
	

}

