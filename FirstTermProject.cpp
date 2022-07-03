#include <iostream>
#include <fstream> 
#include <string>
using namespace std;
struct student
{
	string name,lname,course;
	int age=0,number=0,score=0;
};
struct studentdelete
{
	string name, lname, course,age,number,score;
};
void addstudent(string n, string l, int id, int age, string course, int score);
string showlist();
void searchstudent();
void sortscore();
void deletestudent();
void editstudent();
int main()
{
	cout << "                                          UNIVERCITY STUDENTS MANAGEMENT SYSTEM " << endl << endl;
	cout << "                                        DEVELOPED BY AMIRHOSSEIN DAGHIGH KIA " << endl << endl;
	string search1, search2;
	bool off1 = true;
	int switchcase, howmanyids,search3;
	student s;
	while (off1 != false)
	{
		cout << "MENU:" << endl << endl;
		cout << "\t" << "1) Register new student" << endl;
		cout << "\t" << "2) Delete an student" << endl;
		cout << "\t" << "3) Print list of students" << endl;
		cout << "\t" << "4) Edit student information" << endl;
		cout << "\t" << "5) Search student" << endl;
		cout << "\t" << "6) Sort student scores" << endl;
		cout << endl << "Your choice (1 - 6) >>> ";
		cin >> switchcase;
		cout << endl << endl;
		switch (switchcase)
		{
		case 1:
		{
			cout << "how many IDs do u want to add? " << endl;
			cin >> howmanyids;
			for (int i = 0; i < howmanyids; i++)
			{
				cout << "Enter name of student" << endl;
				cin >> s.name;
				cout << "Enter last name of student" << endl;
				cin >> s.lname;
				cout << "Enter ID Number of student" << endl;
				cin >> s.number;
				cout << "Enter age of student" << endl;
				cin >> s.age;
				cout << "Enter course of student" << endl;
				cin >> s.course;
				cout << "Enter score of student" << endl;
				cin >> s.score;
				cout << "Student : " << s.name << " " << s.lname << " with ID : " << s.number << " on course of " << s.course << " added." << endl;
				addstudent(s.name, s.lname, s.number, s.age, s.course, s.score);
			}
			break;
		}
		case 2:
		{
			deletestudent();
			break;
		}
		case 3:
		{
			cout << showlist() << endl;
			break;
		}
		case 4:
		{
			editstudent();
			break;
		}
		case 5:
		{
			searchstudent();
			break;
		}
		case 6:
		{
			sortscore();
			break;
		}
		default:
		{
			off1 = false;
			break;
		}
		}
	}
	return 0;
}
void addstudent(string n,string l, int id, int age, string course, int score)
{
	ofstream fileout("records.txt", ios::app);
	if (fileout.is_open()) 
	{
		fileout << id << " " << n << " " << l << " " << course << " " << age << " " << score << endl;
		fileout.close();
	}
}
string showlist()
{
	ifstream filein("records.txt", ios::in);
	string line;
	while (getline(filein, line)) 
	{
		cout << line << endl;
	}
	filein.close();
	return line;
}
void searchstudent()
{
	ifstream filein("records.txt", ios::in);
	student s;
	int switchcase, search;
	string name,lname;
	cout << "what is your search base : 1-ID , 2-Name ? " << endl;
	cout << endl << "Your choice (1 - 2) >>> " << endl;
	cin >> switchcase;
	switch (switchcase)
	{
		case 1:
			{
			cout << "Enter Your ID To Search : " << endl;
			cin >> search;
			for (int i = 1; !filein.eof(); i++)
			{
				filein >> s.number >> s.name >> s.lname >> s.course >> s.age >> s.score;
				if (search == s.number)
				{
					cout << s.number << " " << s.name << " " << s.lname << " " << s.course << " " << s.age << " " << s.score << endl;
					break;
				}
			}
			break;
			}
		case 2:
			{
			cout << "Enter Your Name To Search : " << endl;
			cin >> name;
			cout << "Enter Your LastName To Search : " << endl;
			cin >> lname;
			for (int i = 1; !filein.eof(); i++)
			{
				filein >> s.number >> s.name >> s.lname >> s.course >> s.age >> s.score;
				if (name == s.name && lname == s.lname)
				{
					cout << s.number << " " << s.name << " " << s.lname << " " << s.course << " " << s.age << " " << s.score << endl;
					break;
				}
			}
			break;
			}
		default:
			break;
	}
}
void sortscore()
{
	ifstream filein("records.txt",ios::in);
	student array[100];
	string first, last, course;
	int id, age, score;
	int size = 0;
	while (!filein.eof())
	{
		filein >> array[size].number >> array[size].name >> array[size].lname >> array[size].course >> array[size].age >> array[size].score;
		size++;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size ; j++)
		{
			if (array[j].score > array[i].score)
			{
				first = array[i].name;
				last = array[i].lname;
				age = array[i].age;
				id = array[i].number;
				score = array[i].score;
				course = array[i].course;

				array[i].name = array[j].name;
				array[i].lname = array[j].lname;
				array[i].age = array[j].age;
				array[i].number = array[j].number;
				array[i].score = array[j].score;
				array[i].course = array[j].course;

				array[j].name = first;
				array[j].lname = last;
				array[j].age = age;
				array[j].number = id;
				array[j].course = course;
				array[j].score = score;
			}
		}
	}
	filein.close();
	for (int i = 0; i < size-1; i++)
	{
		cout << array[i].number << " " << array[i].name << " " << array[i].lname << " " << array[i].course << " " << array[i].age << " " << array[i].score << endl;
	}
}
void deletestudent()
{
	ifstream filein("records.txt", ios::in);
	studentdelete s[100];
	string delete1,search;
	int switchcase,linee=0,k;
	string name, lname;
	cout << "Enter Your ID To Delete : " << endl;
	cin >> search;
	for (int i = 0; !filein.eof(); i++)
	{
		filein >> s[i].number >> s[i].name >> s[i].lname >> s[i].course >> s[i].age >> s[i].score;
		linee++;
		if (search == s[i].number)
		{
			k = i;
		}
	}
	s[k].number = delete1;
	s[k].name = delete1;
	s[k].lname = delete1;
	s[k].course = delete1;
	s[k].age = delete1;
	s[k].score = delete1;
	filein.close();
	ofstream fileout("records.txt",ios::out);
	for (int i = 0; i < linee; i++)
	{
		fileout << s[i].number << " " << s[i].name << " " << s[i].lname << " " << s[i].course << " " << s[i].age << " " << s[i].score << endl;
	}
	fileout.close();
}
void editstudent()
{
	ifstream filein("records.txt", ios::in);
	studentdelete s[100];
	string search;
	int line = 0,j;
	cout << "Enter Your ID To Edit : " << endl;
	cin >> search;
	for (int i = 0; !filein.eof(); i++)
	{
		filein >> s[i].number >> s[i].name >> s[i].lname >> s[i].course >> s[i].age >> s[i].score;
		line++;
		if (search == s[i].number)
		{
			j = i;
			cout << "please enter new student ID: " << endl;
			cin >> s[j].number;
			cout << "please enter new student First Name: " << endl;
			cin >> s[j].name;
			cout << "please enter new student Last Name: " << endl;
			cin >> s[j].lname;
			cout << "please enter new student Age: " << endl;
			cin >> s[j].age;
			cout << "please enter new student score: " << endl;
			cin >> s[j].score;
		}
	}
	filein.close();
	ofstream fileout("records.txt");
	for (int i = 0; i < line; i++)
	{
		fileout << s[i].number << " " << s[i].name << " " << s[i].lname << " " << s[i].course << " " << s[i].age << " " << s[i].score << endl;
	}
	fileout.close();
}
