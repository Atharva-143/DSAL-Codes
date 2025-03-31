#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student
{
	typedef struct stud
	{
		int roll;
		char name[10];
		char div;
		char add[10];
	}stud;
	stud rec;
	
	public:
		 void create();
		 void display();
		 int search();
		
};

void student::create()
{
	char ans;
	ofstream fout;
	fout.open("stud.dat",ios::out | ios::binary);
	do
	{
		cout<<"\n\tEnter Roll No of student :";
		cin>>rec.roll;
		cout<<"\n\tEnter a Name of student :";
		cin>>rec.name;
		cout<<"\n\tEnter a Division of student :";
		cin>>rec.div;	
		cout<<"\n\tEnter a Address of student :";
		cin>>rec.add;	
		fout.write((char *)&rec,sizeof(stud))<<flush;
		cout<<"\n\tDo you want to Add more Records(type y/Y) : ";
		cin>>ans;
		
	}while(ans=='y' || ans=='Y');
	fout.close();
}

void student::display()															
{
	ifstream fin;
	fin.open("stud.dat", ios::in | ios::binary);
	fin.seekg(0,ios::beg);
	
	cout<<"\n\tThe Content of File are :\n";
	cout<<"\n\tRoll \tName \tDiv \tAddress ";
	while(fin.read((char *)&rec, sizeof(stud)))
	{
		if(rec.roll !=-1)
			cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
	}
	fin.close();
}
int student::search()
{
	int r,i=0;
	ifstream fin;
	fin.open("stud.dat",ios::in | ios::binary);
	fin.seekg(0,ios::beg);
	
	cout<<"\n\tEnter a Roll No :";
	cin>>r;
	while(fin.read((char *)&rec, sizeof(stud)))
	{
		if(rec.roll ==r)
		{
			cout<<"\n\tRecord Found ...\n";
			cout<<"\n\tRoll \tName \tDiv \tAddress";
			cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
			return i;
		}
		i++;
	}
	fin.close();
	return 0;
}

int main()
{
	student obj;
	int ch,key;
	char ans;
	do
	{
		cout<<"\n\t****Student Information*****";
		cout<<"\n\t1.Create \n\t2.Display \n\t3.Search \n\t4.Exit";
		cin>>ch;
		switch(ch)
		{
			case 1: 
			obj.create();
			break;
			
			case 2: 
			obj.display();
			break;	
			
			case 3: 
			key = obj.search();
			if(key == 0)
				cout<<"\n\tRecord not found...\n";
				break;
			case 4:
			break;
		}
		cout<<"\n\tDo you want to continue (type y/Y)";
		cin>>ans;
		}while(ans =='y' || ans == 'Y');
	return 1;
}						
													
