#include<conio.h>
#include<fstream.h>
#include<iostream.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
class student
{
 private:
   int roll;
   char name[30];
   float GPA;
 public:
   mainWindow()
   {
    clrscr();
    cout<<"\t\t\t====================\n\t\t\tSE-2016 Class Record\n\t\t\t====================\n\n\n1.Add/Over write a record\n2.See All records\n3.View w.r.t GPA\n4.Search by Name\n5.Search by Roll no\n6.Search by GPA\n7.Delete by name\n8.Delete by roll no\n9.Exit\n\nSelect the operation: ";
    int choice,a;
    cin>>choice;
     if(choice == 1)
  { setData();
    storeData();
    mainWindow();   }
 else if(choice == 2)
   {
     showAll();
     mainWindow();}
 else if(choice == 3)
 {
  GP();
 }
 else if(choice == 4)
   { searchData();
     mainWindow(); }
 else if(choice == 5)
   { searchRoll();
   mainWindow(); }
 else if(choice == 6)
   { searchGPA();
     mainWindow(); }
 else if(choice == 7)
 {  deleteData();
    mainWindow();
 }
 else if(choice==8)
 {  del();
    mainWindow();
 }
 else if(choice == 9)
   exit(0);
 else
  { cout<<"Choose among the selected options";
    delay(500);
    mainWindow();  } }
   void setData()
   {
    clrscr();
    cout<<"Enter roll no,name and GPA\n";
    cin>>roll;
    cin.ignore();
    cin.getline(name,29);
    cin>>GPA;
   }
   void getData()
   {
    cout<<"\nRoll no: "<<roll<<"\tName: "<<name<<"\tGPA: "<<GPA; }
   int GP()
   {
    int a;
    clrscr();
    cout<<"Select the GPA range\n\n1.4 GPA\n2.Between 3.5 and 3.9\n3.Between 3 and 3.4\n4.Between 2.5 and 2.9\n5.Between 2.4 and 2\n6.Back\n\nSelect the option: ";
    cin>>a;
     if(a==1)
    GPA4();
  else if(a==2)
    GPA35();
  else if(a==3)
    GPA3();
  else if(a==4)
    GPA25();
  else if(a==5)
    GPA2();
  else if(a==6)
   mainWindow();
  else
     { cout<<"Choose among the given option";
       delay(500);}
    GP();
   }
   void GPA4()
   {
    clrscr();
    char a; int counter=0;
    ifstream fin;
    fin.open("ClassRecord.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
     if(GPA == 4.0)
       {  getData();  a='a'; counter++; }
     fin.read((char*)this,sizeof(*this));
    }
    if(a !='a')
       cout<<"Record not found";
    else
      cout<<"\n\n\t\t\tDISPALYING "<<counter<<" RECORDS\n\t\t\t------------------";
    getch();
   }
   void GPA35()
   {
    clrscr();
    char a; int counter=0;;
    ifstream fin;
    fin.open("ClassRecord.dat",ios::in | ios::binary);
    fin.read((char*)this,sizeof(*this));
  while(!fin.eof())
    {
     if(GPA >=3.5 && GPA<4)
       { getData(); a='a'; counter++;}
     fin.read((char*)this,sizeof(*this));
    }
    fin.close();
    if(a !='a')
       cout<<"Record not found";
      else
      cout<<"\n\n\t\t\tDISPALYING "<<counter<<" RECORDS\n\t\t\t---------------------";
    getch();
   }
    void GPA3()
   {
    clrscr();
    char a;ifstream fin;  int counter=0;
    fin.open("ClassRecord.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
     if(GPA >=3.0 && GPA <3.5)
       {  getData();  a='a'; counter++; }
     fin.read((char*)this,sizeof(*this));
    }
    if(a !='a')
       cout<<"Record not found";
    else
      cout<<"\n\n\t\t\tDISPALYING "<<counter<<" RECORDS\n\t\t\t---------------------";
    getch();
   }
       void GPA25()
   {
    clrscr();
    char a;ifstream fin;  int counter=0;
    fin.open("ClassRecord.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
     if(GPA >=2.5 && GPA <3)
       {  getData();  a='a'; counter++; }
     fin.read((char*)this,sizeof(*this));
    }
    if(a !='a')
       cout<<"Record not found";
    else
      cout<<"\n\n\t\t\tDISPALYING "<<counter<<" RECORDS\n\t\t\t--------------------";
    getch();
   }
      void GPA2()
   {
    clrscr();
    char a;ifstream fin;  int counter=0;
    fin.open("ClassRecord.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
     if(GPA>=2 && GPA <2.5)
       {  getData();  a='a'; counter++; }
     fin.read((char*)this,sizeof(*this));
    }
    if(a !='a')
       cout<<"Record not found";
    else
      cout<<"\n\n\t\t\tDISPALYING "<<counter<<" RECORDS\n\t\t\t--------------------";
     getch();
   }
   void storeData()
   {
    char b;
    int a;
    student s,*p;
    s=*this;
    p=&s;
    a=checkData(this->roll);
    if(a==1)
    { ofstream fout;
      fout.open("ClassRecord.dat",ios::app|ios::binary);
      fout.write((char*)p,sizeof(*p));
      fout.close();  }
    else if(a==0)
    { cout<<"Record Already Exists, Do you want to overwrite?\nPress Y to overwrite.";
      b=getch();
      if(b=='y')
     {
       updateData(s);
      }
       }

   }
   void showAll()
   {
    clrscr();
    ifstream fin;
    fin.open("ClassRecord.dat",ios::in | ios::binary);
    fin.read((char*)this,sizeof(*this));
  while(!fin.eof())
    {
     getData();
     fin.read((char*)this,sizeof(*this));
    }
    fin.close();
    getch();
   }
  void searchData()
  {
   int b;
   char a,*p;
   unsigned char nam[30];
   clrscr();
   cout<<"\nEnter the name you want to search: ";
   cin.ignore();
   cin.getline(nam,29);
   b=strlen(nam);
   strlwr(nam);
   if(nam[0]>=97 && nam[0]<=123)
	nam[0]=nam[0]-32;
   p=strchr(nam,' ');
   p++;
   if(*p >= 97 && *p<= 123)
     *p = *p-32;
   p=strrchr(nam,' ');
   p++;
   if(*p >= 97 && *p<= 123)
     *p = *p-32;
   ifstream fin;
   fin.open("ClassRecord.dat",ios::in | ios::binary);
   fin.read((char*)this,sizeof(*this));
   while(!fin.eof())
    {
     if(!strncmp(name,nam,b))
       { getData(); a='a'; }
     fin.read((char*)this,sizeof(*this));  }
    if(a !='a')
     cout<<"Record not found";

   fin.close();
   getch();
  }
  void searchRoll()
  {
   int a;
   char b;
   clrscr();
   cout<<"Enter  the Roll no ";
   cin>>a;
   ifstream fin;
   fin.open("ClassRecord.dat",ios::in | ios::binary);
   fin.read((char*)this,sizeof(*this));
   while(!fin.eof())
    {
     if(a==roll)
       {	getData(); b='a';   break;}
     else
      { fin.read((char*)this,sizeof(*this));
    }       }
    if(b !='a')
     cout<<"Record not found";
   fin.close();
   getch();
  }
  void searchGPA()
  {
   clrscr();
   float a;
   char b;
   cout<<"Enter GPA ";
   cin>>a;
   ifstream fin;
   fin.open("ClassRecord.dat",ios::in | ios::binary);
   fin.read((char*)this,sizeof(*this));
   while(!fin.eof())
    {
     if(a== GPA)
       {   getData(); b='a';          }
	   fin.read((char*)this,sizeof(*this));
	       }
    if(b !='a')
     cout<<"Record not found";
  fin.close();
  getch();                    }

 int checkData(int r)
 {
  ifstream fin;
  fin.open("ClassRecord.dat",ios::in| ios::binary);
  fin.read((char*)this,sizeof(*this));
  while(!fin.eof())
  {
   if(r == roll)
     return 0;
   fin.read((char*)this,sizeof(*this));
  }
 return 1;
 }
 updateData(student s)
 {
  student *p;
  p=&s;
  fstream file;
  file.open("ClassRecord.dat",ios::in| ios::out| ios::ate| ios::binary);
  file.seekp(0);
  file.read((char*)this,sizeof(*this));
  while(!file.eof())
  {
   if(s.roll == roll)
   {
    file.seekp(file.tellp()-sizeof(*p));
    file.write((char*)p,sizeof(*p));
   }
   file.read((char*)this,sizeof(*this));
  }
 }
 deleteData()
 {
  clrscr();
  char nam[30],a;
  cout<<"Enter the name you want to delete: ";
  cin.ignore();
  cin.getline(nam,29);
  ofstream fout;
  ifstream fin;
  fin.open("ClassRecord.dat",ios::in|ios::binary);
  fout.open("temp.dat",ios::out|ios::binary);
  fin.read((char*)this,sizeof(*this));
  while(!fin.eof())
  {
   if(strcmpi(nam,name))
      fout.write((char*)this,sizeof(*this));
   fin.read((char*)this,sizeof(*this));
  }
  fout.close();
  fin.close();
  remove("ClassRecord.dat");
  rename("temp.dat","ClassRecord.dat");
 }
 del()
 {
  clrscr();
  int a;
  cout<<"Enter roll no: ";
  cin>>a;
  ofstream fout;
  ifstream fin;
  fin.open("ClassRecord.dat",ios::in|ios::binary);
  fout.open("temp.dat",ios::out|ios::binary);
  fin.read((char*)this,sizeof(*this));
  while(!fin.eof())
  {
   if(a !=roll)
      fout.write((char*)this,sizeof(*this));
   fin.read((char*)this,sizeof(*this));
  }
  fout.close();
  fin.close();
  remove("ClassRecord.dat");
  rename("temp.dat","ClassRecord.dat");
 }
};
/*void mainWindow(void);
void setData(void);
void getData(void); */
void storeData(void);
void showAll(void);
/*int GP(void);
void GPA4(void);
void GPA35(void);
void GPA3(void);
void GPA25(void);
void GPA2(void);  */
void updateData(student);
void searchData(void);
void searchRoll(void);
void searchGPA(void);
int checkData(int);
void deleteData(void);
void del(void);

void main()
{
 student s1;
 s1.mainWindow();
}