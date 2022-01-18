#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#include<dos.h>
class footballer
{
protected:
char id[10],name[30];
int per;
public:
footballer()
{
per=100;
}
void getid()
{
cout<<"ENTER THE FOOTBALLER ID:  ";
cin>>id;
cout<<"\nENTER THE FOOTBALLER NAME: ";
cin>>name;
};
};

class fileinfoot:public footballer
{
public:
void fil()
{
fstream x("FOOT.txt",ios::out|ios::app);
x.width(30);
x<<endl;
x<<name;
x.width(20);
x<<id;
x.close();
}
} ;
class goalkeeper: public fileinfoot{
int save;
int loss;
public:
void performance()
{
getid();
cout<<"\nENTER HOW MANY GOAL HE WAS ABLE TO SAVE:\n";
cin>>save;
save=save*89;
cout<<"\nENTER HOW MANY GOAL HE WAS NOT ABLE TO SAVE\n:";
cin>>loss;
loss=loss*5;
per=per+save-loss;
if(per<0)
per=0;
file();
}
void file();
};
void  goalkeeper::file()
{
char fil[20];
strcpy(fil,id);
strcat(fil,".txt");
ofstream x(fil);
x<<"NAME: "<<name<<endl;
x<<"ID: "<<id<<endl;
x<<"POSITION: GOALKEEPER\n";
x<<"PERFORMANCE POINT: "<<per<<endl;
x.close();
fstream y("GOALKEEP.txt",ios::out|ios::app);
y<<endl;
y.width(30);
y<<name;
y.width(20);
y<<id;
y.close();
}
class defender: public fileinfoot
{
int defend;
int loss;
public:
void performance()
{
getid();
cout<<"\nENTER HOW MANY DEFEND HE MADE:\n";
cin>>defend;
defend=defend*5;
cout<<"\nENTER HOW MANY MISS DEFENCE HE MADE:\n";
cin>>loss;
loss=loss*2;
per=per+defend-loss;
if(per<0)
per=0;
file();
}
void file();
};
void defender::file()
{
char fil[20];
strcpy(fil,id);
strcat(fil,".txt");
ofstream x(fil);
x<<"NAME: "<<name<<endl;
x<<"ID: "<<id<<endl;
x<<"POSITION: DEFENDER\n ";
x<<"PERFORMANCE POINT: "<<per<<endl;
x.close();
fstream y("DEFENDER.txt",ios::out|ios::app);
y<<endl;
y.width(30);
y<<name;
y.width(20);
y<<id;
y.close();
}
class midfielder:public fileinfoot
{
int passing;
int mispass;
public:
void performance()
{
getid();
cout<<"\nENTER HOW MANY PASSES HE MADE?\n";
cin>>passing;
passing=passing*5;
cout<<"\nENTER HOWMANY PASSES HE MISSED\n";
cin>>mispass;
mispass=mispass*6;
per=per+passing-mispass;
if(per<0)
per=0;
file();
}
void file();
};
void midfielder:: file()
{
char fil[20];
strcpy(fil,id);
strcat(fil,".txt");
ofstream x(fil);
x<<"NAME: "<<name<<endl;
x<<"ID: "<<id<<endl;
x<<"POSITION: MIDFIELDER\n";
x<<"PERFORMANCE POINT: "<<per<<endl;
x.close();
fstream y("MIDFIELD.txt",ios::out|ios::app);
y<<endl;
y.width(30);
y<<name;
y.width(20);
y<<id;
y.close();
}
class striker: public fileinfoot
{
int goal;
int loss;
public:
void performance()
{
getid();
cout<<"\nENTER HOW MANY GOALHE SAVED?\n";
cin>>goal;
goal=goal*5;
cout<<"\nENTER THE NO.OF GOAL HE MISSED\n";
cin>>loss;
loss=loss*6;
per=per+goal-loss;
if(per<0)
per=0;
file();
}
void file();
};
void striker:: file()
{
char fil[20];
strcpy(fil,id);
strcat(fil,".txt");
ofstream x(fil);
x<<"NAME: "<<name<<endl;
x<<"ID: "<<id<<endl;
x<<"POSITION: STRIKER\n";
x<<"PERFORMANCE POINT: "<<per<<endl;
x.close();
fstream y("STRIKER.txt",ios::out|ios::app);
y<<endl;
y.width(30);
y<<name;
y.width(20);
y<<id;
y.close();
}
class add
{
public:
add();
};
add::add()
{
goalkeeper g;
defender d;
striker s;
midfielder m;
int co;
while(1)
{
clrscr();
cout<<"\n\n\n\n\n\n\n******************************************************************************";
cout<<"                             ADD A PLAYER                                      ";
cout<<"\n******************************************************************************";

sleep(1);
clrscr();

cout<<"\n******************************************************************************";
cout<<"                             ADD A PLAYER                                      ";
cout<<"\n******************************************************************************";
cout<<"\n\n\n1.FOR ADDING A GOAL KEEPER ( PRESS 1 )";
cout<<"\n2.FOR ADDINGA DEFENDER ( PRESS 2 )";
cout<<"\n3.FOR ADDING A STRIKER ( PRESS 3 )";
cout<<"\n4.FORADDING A MIDFIELDER ( PRESS 4 )";
cout<<"\n\n************************FOR EXIT ( PRESS 5 )********************************\n";
cout<<"\n\n WHICH TYPE OF FOOTBALLER WOULD YOU LIKE TO ADD";
cout<<"\nENTER YOUR CHOICE";
cin>>co;
if(co==5)
break;
if(co==1)
{
g.performance();
g.fil();
}
if(co==2)
{
d.performance();
d.fil();
}
if(co==3)
{
s.performance();
s.fil();
}
if(co==4)
{
m.performance();
m.fil();
}
}
}
class search
{
public:
void find();
};
void search::find()
{
int i;
char id[20],c;
while(1)
{
clrscr();
cout<<"\n\n\n\n\n\n\n*****************************************************************************";
cout<<"                               SEARCH A PLAYER                              ";
cout<<"\n*****************************************************************************";
sleep(1);
clrscr();

cout<<"\n*****************************************************************************";
cout<<"                               SEARCH A PLAYER                              ";
cout<<"\n*****************************************************************************";
cout<<"\n\n1. TO SEARCH ALL FOOTBALLER ( PRESS 1 )";
cout<<"\n2. TO SEARCH ALL GOALKEEPER ( PRESS 2 )";
cout<<"\n3. TO SEARCH ALL DEFENDER ( PRESS 3 )\n";
cout<<"4. TO SEARCH ALL MIDFIELDER ( PRESS 4 )";
cout<<"\n5. TO SEARCH ALL STRIKER ( PRESS 5 )";
cout<<"\n6. TO SEARCH BY ID( PRESS 6 )";
cout<<"\n\n\n******************************* FOR EXIT ( PRESS 7 )*************************";
cout<<"\n\nWHICH FOOTBALLER WOULD YOU LIKE TO SEARCH";
cout<<"\nENTER YOUR CHOICE";
cin>>i;
if(i==7)
break;
if(i==1)
{
ifstream x("FOOTBALL.txt");
cout<<"\n\nFOOTBALLER'S NAME AND ID \n\n";
while(x)
{
x.get(c);
cout<<c;
}
getch();
x.close();
}
if(i==2)
{
ifstream x("GOALKEEP.txt");
cout<<"\n\nGOALKEEPER'S NAME AND ID \n\n";
while(x)
{
x.get(c);
cout<<c;
}
getch();
x.close();
}
if(i==3)
{
ifstream x("DEFENDER.txt");
cout<<"\n\nDEFENDER'S NAME AND ID \n\n";
while(x)
{
x.get(c);
cout<<c;
}
getch();
x.close();
}
if(i==4)
{
ifstream x("MIDFIELD.txt");
cout<<"\n\nMIDFIELDER'S NAME AND ID \n\n";
while(x)
{
x.get(c);
cout<<c;
}
getch();
x.close();
}
if(i==5)
{
ifstream x("STRIKER.txt");
cout<<"\n\nSTRIKER'S NAME AND ID \n\n";
while(x)
{
x.get(c);
cout<<c;
}
getch();
x.close();
}
if(i==6)
{
clrscr();
cout<<"  \n\nENTER THE FOOTBALLER ID ";
cin>>id;
char fil[20];
strcpy(fil,id);
strcat(fil,".txt");
ifstream x(fil);
while(x)
{
x.get(c);
cout<<c;
}
getch();
x.close();
}
}
}
int main()
{
int c;
clrscr();
while(1)
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n*************************************************************************";
cout<<"\n                      FOOTBALL MANAGEMENT SYSTEM";
cout<<"\n**************************************************************************";
sleep(1);
clrscr();
cout<<"**************************************************************************";
cout<<"\n                  FOOTBALL MANAGEMENT SYSTEM";
cout<<"\n***************************************************************************";
cout<<"\n\n    WELCOME TO  THE FOOTBALL MANAGEMENT SYSTEM";
cout<<"\n\n\t1.FOR ADDING A FOOTBALL PLAYER ( PRESS 1 )";
cout<<"\n\t2.TO SEARCH A FOOTBALL PLAYER ( PRESS 2 )";
cout<<"\n\n*************************** FOR EXIT ( PRESS 3 )****************************\n\n";
cout<<"\n\nENTER YOUR CHOICE";
cin>>c;
if(c==3)
break;
else
if(c==1)
{
add a;
}
else
if(c==2)
{
search f;
f.find();
}
}

	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t   THANKS";
	sleep(1);
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t   THANKS";
	sleep(1);
	clrscr();
	cout<<"\n\n\n\n\n\n\nMADE BY:\n\n\nRATNESH KUMAR SINGH \n\n& \n\nRONY roy";
	sleep(1);
	 return 0;

}
