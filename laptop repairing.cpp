#include<iostream>
#include<fstream>
using namespace std;
class lpshop
{
	static int id;
	static string passwd;
	char cname[25],make[10],cadd[50],model[10],issue[25];
	int service_code,date_accept,date_of_return;
	float cost;
	char cust_contact_no[11];
	public:
	void login();
	void mainmenu();
	void get();
	void add();
	void display();
	void put();
	void search();
	void update();
	void replap();
	void del();
};
int lpshop::id=1234;
string lpshop::passwd="login";
void lpshop::login()
{
	int id1;
	string password2;
	cout<<"Enter 1 to LOGIN :"<<endl;       ///////for loging in
	cout<<"Enter 2 to EXIT"<<endl;
	int opt;
	cin>>opt;
	if(opt==1)           //// if first option is selected
	{
	cout<<"\t Enter user id:";
	 cin>>id1;
	 cout<<"\t Enter password:";
	 cin>>password2;
	 if(id1==id && password2==passwd)
	 {
	 	cout<<"successfull login:"<<endl;
	 	mainmenu();     //// mainmenu function called if user is  logined
	 }
	 else
	 {
	 	cout<<"invalid entry"<<endl;
	 }
	}
}
void lpshop::mainmenu()
{
	system("CLS");
	cout<<"\t \t \t \t \t WELCOME TO LAPTOP DOCTOR \t \t \t \t \t "<<endl;
	cout<<"\t \t \t \t \t \t \t an authorized laptop repairing shop \t \t \t \t \t \t"<<endl;
	cout<<"--------------------------------------------------MAIN MENU------------------------------------------------------"<<endl;
	cout<<"ENTER 1 TO ACCEPT A LAPTOP FOR REPAIR"<<endl;
	cout<<"ENTER 2 DISPLAY ALL LAPTOP PRESENT IN SHOP"<<endl;
	cout<<"ENTER 3 TO SEARCH A LAPTOP"<<endl;
	cout<<"ENTER 4 TO MODIFY DETAILS OF A LAPTOP"<<endl;
	cout<<"ENTER 5 TO RETURN BACK REPAIRED LAPTOP TO CUSTOMER AND GENERATE BILL"<<endl;
	cout<<"ENTER 6 TO VIEW DETAILS OF ALL LAPTOPS ALREADY REPAIRED IN THE SHOP"<<endl;
	int opt2;
	cin>>opt2;

		if(opt2==1)
		{
			system("color 1a");
		//	system("CLS");
			add(); // calling function to enter details of a laptop
		}
		if(opt2==2)
		{//system("CLS");
		display();
		}
		if(opt2==3)
		{
			search();
		}
		if(opt2==4)
		{
		//	system("CLS");
			update();
		}
		if(opt2==5)
		{
		//	system("CLS");
			del();
		}
		if(opt2==6)
		{
			//system("CLS");
			replap();
		}
}
void lpshop::get()
	{
			cout<<"ENTER CUSTOMER'S NAME: ";
	cin.ignore();
	cin.getline(cname,25);
//	cout<<endl;
	cout<<"ENTER CUSTOMER'S ADDRESS: ";
	cin>>ws;
//	cin.ignore();
	cin.getline(cadd,50);
	cout<<"ENTER CUSTOMER'S CONTACT NUMBER: ";
	cin>>cust_contact_no;
	cout<<"ENTER TODAY'S DATE in format of(DD/MM/YY): ";
	cin>>date_accept;
	cout<<"ENTER LAPTOP'S BRAND NAME: ";
	cin>>make;
	cout<<"ENTER LAPTOP'S MODEL: ";
	cin>>model;
	cout<<"ENTER PROBLEM IN LAPTOP: ";
	cin.ignore();
	cin.getline(issue,25);
	cout<<"ENTER SERVICE CODE: ";
	cin>>service_code; 
	cout<<"ENTER COST REPAIR: ";
	cin>>cost;
		 }
	void  lpshop::put()
	{
		cout<<"\t CUSTOMER'S NAME: "<<cname<<endl<<"\t CUSTOMER'S ADDRESS: "<<cadd<<endl<<"\t CUSTOMER'S CONTACT NO. : "<<cust_contact_no<<endl<<"\t DATE OF ENTRY: "<<date_accept<<endl<<"\t LAPTOP'S BRAND: "<<make<<endl<<"\t LAPTOP'S MODEL: "<<model<<endl<<"\t ISSUE IN LAPTOP: "<<issue<<endl<<"\t SERVICE CODE: "<<service_code<<endl<<"\t COST OF REPAIR IS:"<<cost<<endl;
		//cout<<cname<<ends<<cadd<<ends<<cust_contact_no<<ends<<date_accept<<ends<<make<<ends<<model<<ends<<issue<<ends<<service_code<<endl;
		}	
	void lpshop::add()	
	{
		system("CLS");
	
	lpshop o1;
	ofstream op;
	op.open("repair.txt",ios::app);
	if(op)
	{
	//	for(int i=0;i<3;i++)
	//	{
			o1.get();
			op.write((char *)&o1,sizeof(o1));
			
	//	}
	}
	op.close();
	cout<<"PRESS 1 TO RETURN TO MAIN MENU AND 2 TO EXIT";
	int rt=0;
	cin>>rt;
	if(rt==1)
	mainmenu();
	}	
	void lpshop::display()
	{
		system("CLS");
		lpshop o1;
	ifstream in;
	in.open("repair.txt");
	while(in.read((char *)&o1,sizeof(o1)))
	{
			o1.put();
			cout<<"\n";
	}
	in.close();
	cout<<"PRESS 1 TO RETURN TO MAIN MENU AND 2 TO EXIT";
	int rt=0;
	cin>>rt;
	if(rt==1)
	mainmenu();
	}
	/*void lpshop::search()
	{
	lpshop o1;
	ifstream in;
	in.open("repair.txt");
	int srvno;
	cout<<"Enter service code to be searched:";
	cin>>srvno;
	while(in.read((char *)&o1,sizeof(o1)))
	{
		if(o1.service_code==srvno)
			o1.put();
			//cout<<"\n";
	}
	in.close();
	mainmenu();
	}*/
	void lpshop::search()
	{
		system("cls");
		lpshop l;
		ifstream in;
		in.open("repair.txt");
		cout<<"Enter the service code of laptop to be searched: ";
		int srvno;
		cin>>srvno;
		while(in.read((char*)&l,sizeof(l)))
		{
			if(srvno==l.service_code)
			l.put();
		}
		in.close();
		cout<<"PRESS 1 TO RETURN TO MAIN MENU AND 2 TO EXIT";
	int rt=0;
	cin>>rt;
	if(rt==1)
	mainmenu();
	}
	void lpshop::update()
	{
		system("CLS");
		lpshop l1;
		ifstream in;
		in.open("repair.txt");
		
		int servno;
		cout<<"Enter the srvice code to be updated:";
		cin>>servno;
		int ct=0;
			while(in.read((char *)&l1,sizeof(l1)))
		{
			ct++;
			if(l1.service_code==servno)
			break;
		}
		//cout<<endl<<ct<<endl;
		in.close();
		lpshop p5,p6;
			ifstream ou1;
			ofstream in1;
			ou1.open("repair.txt");
			in1.open("repair2.txt");
			//int srvno;
			//cout<<"Enter service code: ";
			//cin>>srvno;
			int check=0;
			int count=0;
			int obno;
			obno=ct;
			int nob=ou1.tellg()/sizeof(p5);
			while(ou1.read((char*)&p5,sizeof(p5)))
			{
				count++;
				if(count!=obno)
				{
					//cout<<"hello";
					in1.write((char*)&p5,sizeof(p5));
				}
				else
				{
					p5.get();
					in1.write((char*)&p5,sizeof(p5));
				}
			}
			ou1.close();
			in1.close();
			system("CLS");
			ifstream in2;
			in2.open("repair2.txt");
			while(in2.read((char*)&p6,sizeof(p6)))
			{
				p6.put();
			}
			in2.close();
			remove("repair.txt");
			rename("repair2.txt","repair.txt");
			cout<<"PRESS 1 TO RETURN TO MAIN MENU AND 2 TO EXIT";
			int rt=0;
			cin>>rt;
			if(rt==1)
			mainmenu();
}
	void lpshop::del()
	{
		system("cls");
			lpshop p3,p4;
			ifstream ou;
			ofstream in;
			ou.open("repair.txt");
			in.open("repair3.txt",ios::app);
			int srvno;
			cout<<"Enter service code: ";
			cin>>srvno;
			int ct=0;
			//int amount;
			while(ou.read((char*)&p3,sizeof(p3)))
			{
				ct++;
				if(srvno==p3.service_code)
				{
					cout<<"DEAR CUSTOMER YOU NEED TO PAY Rs: "<<p3.cost<<endl;
				in.write((char*)&p3,sizeof(p3));
				break;
				}
				//p4.out();
			}
			in.close();
			ou.close();
				//cout<<ct++;
			/*ifstream io;
			io.open("lptry2.txt");
			while(io.read((char*)&p4,sizeof(p4)))
			{
				p4.put();
			}
			io.close();*/
			//cout<<endl<<ct<<endl;
	
//mainmenu();
//}
//void lpshop::dol()
//{
		lpshop p5,p6;
			ifstream ou1;
			ofstream in1;
			ou1.open("repair.txt");
			in1.open("repair4.txt");
			//int srvno;
			//cout<<"Enter service code: ";
			//cin>>srvno;
			int check=0;
			int count=0;
			int obno;
			obno=ct;
			int nob=ou1.tellg()/sizeof(p5);
			while(ou1.read((char*)&p5,sizeof(p5)))
			{
				count++;
				if(count!=obno)
				{
					//cout<<"hello";
					in1.write((char*)&p5,sizeof(p5));
				}
				else
				{
					continue;
				}
			}
			ou1.close();
			in1.close();
			/*ifstream in2;
			in2.open("repair4.txt");
			while(in2.read((char*)&p6,sizeof(p6)))
			{
				p6.put();
			}
			in2.close();*/
			remove("repair.txt");
			rename("repair4.txt","repair.txt");
			//mainmenu();
			cout<<"PRESS 1 TO RETURN TO MAIN MENU AND 2 TO EXIT";
			int rt=0;
			cin>>rt;
			if(rt==1)
			mainmenu();
}
void lpshop::replap()
{
		system("cls");
	lpshop p4;
	ifstream io;
			io.open("repair3.txt");
			while(io.read((char*)&p4,sizeof(p4)))
			{
				p4.put();
				cout<<endl;
			}
			io.close();
			cout<<"PRESS 1 TO RETURN TO MAIN MENU AND 2 TO EXIT";
			int rt=0;
			cin>>rt;
			if(rt==1)
			mainmenu();
}

int main()
{
	cout<<"\t \t \t \t \t WELCOME TO LAPTOP MECHANIC \t \t \t \t \t "<<endl;
	cout<<"\t \t \t \t \t \t \t an authorized laptop repairing shop \t \t \t \t \t \t"<<endl;
	lpshop c;
	c.login();
	return 0;
}
