#include<iostream>
#include<string.h>
using namespace std;

int choice()
{
int ch;
	cout<<"1.BORROW BOOK\n2.RETURN BOOKS\n3.SEARCH\n4.DISPLAY AVAILABLE COPIES\n5.SHOW ALL AVAILABLE BOOKS\n6.MY BORROWED BOOKS\n7.EXIT"<<endl;
cin>>ch;
return ch;

}
class book
{
	public:
		int b_id;
		string b_name;
		string a_name;
		string genre;
		string title;
		int available;
		int totalcopy;
		
		book()
		{
			b_id=0;
			b_name=" ";
			a_name=" ";
			genre=" ";
			title=" ";
			available=0;
			totalcopy=0;
		
		}
		
		void display()
		{
			cout<<"BOOK ID:"<<b_id<<endl<<"BOOK NAME:"<<b_name<<endl<<"AUTHOR NAME:"<<a_name<<endl<<"TITLE:"<<title<<endl<<"GENRE:"<<genre<<endl<<"AVAILABLE COPIES:"<<available<<endl<<"TOTAL COPIES:"<<totalcopy<<endl;
		cout<<"=========================="<<endl;
		}
};
struct node
{
	book data;
	node *link;
};
class booklist
{
	public:
	node*start,*cur,*temp;
	
	booklist()
	{
		start=NULL;
	}
	
	void append(book n)
	{
		if(start==NULL)
		{
			start=new node;
			start->data=n;
			start->link=NULL;
		}
		else
		{
			cur=start;
			while(cur->link!=NULL)
			{
				cur=cur->link;
			}
			temp=new node;
			temp->data=n;
			temp->link=NULL;
			cur->link=temp;
		}
		
	}
	
	void print()
	{
		if(start==NULL)
		{
			cout<<"NO BOOK FOUND!"<<endl;
		}
		else
		{
		
		cur=start;
		while(cur!=NULL)
		{
			cur->data.display();
			cout<<"==================================="<<endl;
			cur=cur->link;
		}
	}
	}
	
	void search(int id)
	{
		if(start==NULL)
		{
			cout<<"NOTHING FOUND!\nITS EMPTY"<<endl;
		}
		else
		{
		
		bool found=false;
		cur=start;
		while(cur!=NULL)
		{
			if(cur->data.b_id==id)
			{
				cout<<"BOOK FOUND!"<<endl;
				found=true;
				cur->data.display();
				break;
			}
			cur=cur->link;
		}
		if(found==false)
		{
			cout<<"BOOK NOT FOUND!"<<endl;
		}
	}
	}
	
	void deletebook(int id)
	{
			if(start==NULL)
		{
			cout<<"NOTHING FOUND!\nITS EMPTY"<<endl;
		}
		else if(start->data.b_id==id)
		{
			temp=start;
			start=start->link;
			delete temp;
			cout<<"BOOK DELETED SUCCESSFULLY!"<<endl;
		}
		else
		{
			cur=start;
			while(cur!=NULL)
			{
			
				if(cur->data.b_id==id)
				{
					temp->link=cur->link;
					delete cur;
					cout<<"BOOK DELETED SUCCESSFULLY!"<<endl;
					break;
				}
					temp=cur;
				cur=cur->link;
				
			}
			
		}
		
		
	}
	void issuebook(int id)
		{
			cur=start;
			while(cur!=NULL)
			{
				if(cur->data.b_id==id)
				{
					if(cur->data.available>0)
					{
						cur->data.available--;
						cout<<"BOOK ISSUED SUCCESSFULLY!"<<endl;
						cout<<"AVAILABLE BOOKS NOW:"<<cur->data.available<<endl;
					}
					else
					{
						cout<<"BOOK IS NOT AVAILABLE"<<endl;
					}
				}
				cur=cur->link;
			}
			
		}
				void returnaddbook(int id)
		{
			cur=start;
			while(cur!=NULL)
			{
				if(cur->data.b_id==id)
				{
					cur->data.available++;
					cout<<"BOOK IS RESTORED AGAIN!"<<endl;
					cout<<"========================"<<endl;
					break;
				}
				cur=cur->link;
			}
		}
		void searchname(string n)
		{
			bool check=false;
			cur=start;
			while(cur!=NULL)
			{
				if(cur->data.b_name==n)
				{
					check=true;
					cout<<"BOOK FOUND!"<<endl;
					cur->data.display();
					break;
				}
				cur=cur->link;
			}
			if(check==false)
			{
				cout<<"BOOK NOT FOUND!"<<endl;
			}
		}
		
		void availablecopy(string n)
		{
			bool check=false;
			cur=start;
			while(cur!=NULL)
			{
				if(cur->data.b_name==n)
				{
					check=true;
					
					break;
			}
			cur=cur->link;
				
		}
		if(check==false)
		{
			cout<<"ERROR!\nTRY IT AGAIN"<<endl;
			cout<<"========================="<<endl;
		}
		else
		{
			cout<<"AVAILABLE COPIES:"<<cur->data.available<<endl;
					cout<<"==========================="<<endl;
		}
	
	}
	void addbook(int id,string n,string a,string t,string g,int avail,int tc)
{
	if(start==NULL)
	{
		
	temp=new node;
	temp->data.b_id=id;
	temp->data.b_name=n;
	temp->data.a_name=a;
	temp->data.title=t;
	temp->data.genre=g;
	temp->data.available=avail;
	temp->data.totalcopy=tc;
	temp->link=NULL;
	start=temp;
	cout<<"NEW BOOK ADD SUCCESSFULLY!"<<endl;
	}
	else
	{
	cur=start;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	temp=new node;
	temp->data.b_id=id;
	temp->data.b_name=n;
	temp->data.a_name=a;
	temp->data.title=t;
	temp->data.genre=g;
	temp->data.available=avail;
	temp->data.totalcopy=tc;
	temp->link=NULL;
	cur->link=temp;
	cout<<"NEW BOOK ADD SUCCESSFULLY!"<<endl;
	
}
}

		
	
};
class member
{
	public:
		int m_id;
		string name;
		string contact;
		int count;
		int borrowbook[3];
		
		member()
		{
			m_id=0;
			name=" ";
			contact=" ";
			count=0;
		}
		
		void display()
		{
			cout<<"MEMBER ID:"<<m_id<<endl;
			cout<<"MEMBER NAME:"<<name<<endl;
			cout<<"CONTACT NUMBER:"<<contact<<endl;
			cout<<"TOTAL BORROWED BOOKS:"<<count<<endl;
			if(count>0)
			{
				for(int i=0;i<count;i++)
				{
					cout<<borrowbook[i]<<endl;
				}
			}
		}
		
		bool hasborrowed(int id)
		{
			
			for(int i=0;i<count;i++)
			{
			if(borrowbook[i]==id)
			{
				return true;
				cout<<"YES!THIS BOOK IS BORROWED BY HIM!"<<endl;
			}
			
		}
		return false;
	}
		
		void borrowedbook(int id)
		{
			if(count<3)
			{
				borrowbook[count]=id;
				count++;
				cout<<"BOOK IS BORROWED SUCCESSFULLY!"<<endl;
				cout<<"================================"<<endl;
			}
			else
			{
				cout<<"LIMIT HAS REACHED.\nYOU CANNOT BORROW MORE BOOKS!"<<endl;
			}
		}
		
		void returnbook(int id)
		{
			bool check=false;
			for(int i=0;i<count;i++)
			{
				if(borrowbook[i]==id)
				{
				
				for(int j=i;j<count-1;j++)
				{
					borrowbook[j]=borrowbook[j+1];
				}
				count--;
				check=true;
			
			}
		}
		if(check==false)
		{
			cout<<"REMOVING ISSUE!\nCHECK IT AGAIN"<<endl;
			cout<<"================================="<<endl;
		}
		else
		{
			cout<<"BOOK IS RETURNED SUCCESSFULLY FROM A MEMBER!"<<endl;
					cout<<"================================="<<endl;
					
					
		}
	
		}
		

		
};
struct mnode
{
	member data;
	mnode*link;
};
class memberlist
{
	public:
		mnode *start,*cur,*temp;
		
		memberlist()
		{
			start=NULL;
		}
		void append(member n)
	{
		if(start==NULL)
		{
			start=new mnode;
			start->data=n;
			start->link=NULL;
		}
		else
		{
			cur=start;
			while(cur->link!=NULL)
			{
				cur=cur->link;
			}
			temp=new mnode;
			temp->data=n;
			temp->link=NULL;
			cur->link=temp;
		}
		
	}
	
	void printm()
	{
		if(start==NULL)
		{
			cout<<"NO MEMBER FOUND!"<<endl;
		}
		else
		{
		
		cur=start;
		while(cur!=NULL)
		{
			cur->data.display();
			cout<<"==================================="<<endl;
			cur=cur->link;
		}
	}
	}
	
	void searchm(int id)
	{
		if(start==NULL)
		{
			cout<<"NOTHING FOUND!\nITS EMPTY"<<endl;
		}
		else
		{
		
		bool found=false;
		cur=start;
		while(cur!=NULL)
		{
			if(cur->data.m_id==id)
			{
				cout<<"MEMBER FOUND!"<<endl;
				found=true;
				cur->data.display();
				break;
			}
			cur=cur->link;
		}
		if(found==false)
		{
			cout<<"MEMBER NOT FOUND!"<<endl;
		}
	}
	}
	
	void deletemember(int id)
	{
			if(start==NULL)
		{
			cout<<"NOTHING FOUND!\nITS EMPTY"<<endl;
		}
		else if(start->data.m_id==id)
		{
			temp=start;
			start=start->link;
			delete temp;
			cout<<"MEMBER DELETED SUCCESSFULLY!"<<endl;
		}
		else
		{
			cur=start;
			while(cur!=NULL)
			{
			
				if(cur->data.m_id==id)
				{
					temp->link=cur->link;
					delete cur;
					cout<<"MEMBER DELETED SUCCESSFULLY!"<<endl;
					break;
				}
					temp=cur;
				cur=cur->link;
				
			}
			
		}
		
	}
	void borrow(int mid,int id)
	{
		bool found=false;
		cur=start;
		while(cur!=NULL)
		{
			if(cur->data.m_id==mid)
			{
				found=true;
				cur->data.borrowedbook(id);
				break;
			}
			cur=cur->link;
			
		}
		if(found==false)
		{
			cout<<"MEMBER NOT FOUND!"<<endl;
		}
	}
	
		void returnmembook(int mid,int id)
		{
			bool check=false;
			cur=start;
			while(cur!=NULL)
			{
				if(cur->data.m_id==mid)
				{
					check=true;
					cur->data.returnbook(id);
					
					break;
				}
				cur=cur->link;
			}
		
		if(check==false)
		{
			cout<<"MEMBER NOT FOUND!"<<endl;
		}
}
void borrowcount(int id)
{
	cur=start;
	while(cur!=NULL)
	{
		if(cur->data.m_id==id)
		{
			cout<<"YOUR TOTAL BORROWED BOOKS:"<<cur->data.count<<endl;
			cout<<"==============================="<<endl;
			break;
					}
					cur=cur->link;
	}
}
bool memcheck(int id)
{
	cur=start;
	while(cur!=NULL)
	{
		if(cur->data.m_id==id)
		{
			return true;
		}
		cur=cur->link;
	}
	return false;
}
bool admincheck(int p)
{
	int password=4867;
	if(p==password)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void addmember(int id,string n,string c)
{
	cur=start;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	temp=new mnode;
	temp->data.m_id=id;
	temp->data.name=n;
	temp->data.contact=c;
	temp->link=NULL;
	cur->link=temp;
	cout<<"NEW MEMBER ADD SUCCESSFULLY!"<<endl;
	if(start==NULL)
	{
		start=temp;
	}
	
}

	void signup(int id,string n,string c)
{
	cur=start;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	temp=new mnode;
	temp->data.m_id=id;
	temp->data.name=n;
	temp->data.contact=c;
	temp->link=NULL;
	cur->link=temp;
	cout<<"SIGNED UP SUCCESSFULLY!"<<endl;
	if(start==NULL)
	{
		start=temp;
	}
	
}


};


int main()
{
book obj1;
	obj1.b_id=100;
	obj1.b_name="OOPS";
	obj1.a_name="SHEHNAZ";
	obj1.genre="C++";
	obj1.title="INTRODUCTION TO OOPS";
	obj1.totalcopy=87;
	obj1.available=87;
	
	book obj2;
obj2.b_id=101;
obj2.b_name="Data Structures";
obj2.a_name="Mark Allen";
obj2.genre="Programming";
obj2.title="Mastering Data Structures";
obj2.totalcopy=65;
obj2.available=60;

book obj3;
obj3.b_id=102;
obj3.b_name="Database";
obj3.a_name="Thomas Connolly";
obj3.genre="SQL";
obj3.title="Database Management Systems";
obj3.totalcopy=50;
obj3.available=45;

book obj4;
obj4.b_id=103;
obj4.b_name="Operating System";
obj4.a_name="Abraham Silberschatz";
obj4.genre="Computer Science";
obj4.title="Operating System Concepts";
obj4.totalcopy=70;
obj4.available=66;

book obj5;
obj5.b_id=104;
obj5.b_name="Networking";
obj5.a_name="Andrew Tanenbaum";
obj5.genre="Networks";
obj5.title="Computer Networks";
obj5.totalcopy=55;
obj5.available=49;


	
	booklist obj;
	obj.append(obj1);
	obj.append(obj2);
	obj.append(obj3);
	obj.append(obj4);
	obj.append(obj5);
	
	member mobj1;
	mobj1.m_id=500;
	mobj1.name="SANA MIRZA";
	mobj1.contact="198282891";
	
	member mobj2;
mobj2.m_id=501;
mobj2.name="ALI KHAN";
mobj2.contact="03111222333";

member mobj3;
mobj3.m_id=502;
mobj3.name="AHMED RAZA";
mobj3.contact="03222333444";

member mobj4;
mobj4.m_id=503;
mobj4.name="FATIMA NOOR";
mobj4.contact="03333444555";

member mobj5;
mobj5.m_id=504;
mobj5.name="HAMZA ALI";
mobj5.contact="03444555666";
	
	memberlist mobj;
	mobj.append(mobj1);
	mobj.append(mobj2);
	mobj.append(mobj3);
	mobj.append(mobj4);
	mobj.append(mobj5);
	
int mem_id;
int sc;
string mem_name;
string btitle;
string bgenre;
string aname;
int btotal;
int bavail;
string contact;
int listchoice;
int id;
char bookname[20];
int u=0;
cout<<"========LIBRARY MANAGEMENT SYSTEM==============="<<endl;
while(u!=3)
{
cout<<"1.USER\n2.ADMIN\n3.EXIT"<<endl;
cin>>u;
if(u==1)
{
	listchoice=0;
	int c;
	cout<<"1.CREATE NEW ACCOUNT\n2.LOGIN"<<endl;
	cin>>c;
	int g;
	if(c==1)
	{
		cout<<"ENTER MEMBER ID:"<<endl;
		cin>>mem_id;
		cout<<"ENTER MEMBER NAME:"<<endl;
		cin>>mem_name;
		cout<<"ENTER CONTACT NUMBER:"<<endl;
		cin>>contact;
		mobj.signup(mem_id,mem_name,contact);
		cout<<"DO YOU WANT TO LOGIN RIGHT NOW\n1.YES\n2.NO"<<endl;
		cin>>g;
		if(g==1)
		{
			cout<<"LOGIN SUCCESSFULLY!"<<endl;
			
	cout<<"=========USER MENU========="<<endl;
	
	while(listchoice!=7)
	{
		listchoice=choice();
switch(listchoice)
{
	case 1:
		cout<<"ENTER BOOK ID:"<<endl;
		cin>>id;
		obj.issuebook(id);
		mobj.borrow(mem_id,id);
		break;
	case 2:
		cout<<"ENTER BOOK ID:"<<endl;
		cin>>id;
		
		mobj.returnmembook(mem_id,id);
		obj.returnaddbook(id);
		break;
	case 3:
		cout<<"1.BY NAME\n2.BY ID"<<endl;
		cin>>sc;
		if(sc==1)
		{
		cout<<"ENTER BOOK NAME:"<<endl;
		cin.ignore();
		cin.getline(bookname,20);
		obj.searchname(bookname);
		break;
	}
	else if(sc==2)
	{
		cout<<"ENTER BOOK ID:"<<endl;
		cin>>id;
		obj.search(id);
		break;
	}
	else
	{
		cout<<"INVALID!"<<endl;
		break;
	}

	case 4:
		cout<<"ENTER BOOK NAME:"<<endl;
		cin.ignore();
		cin.getline(bookname,20);
		obj.availablecopy(bookname);
		break;
	case 5:
		cout<<"ALL BOOKS!"<<endl;
		obj.print();
		break;
		
	case 6:
		mobj.borrowcount(mem_id);
		break;		
}
}
}
else
{
	return 0;
}
}

		
		
	
	else if(c==2)
	{
	cout<<"ENTER MEMBER ID:"<<endl;
	cin>>mem_id;
	if(!mobj.memcheck(mem_id))
{
    cout<<"INVALID MEMBER"<<endl;
}
else
{
	cout<<"=========USER MENU========="<<endl;
	
	while(listchoice!=7)
	{
		listchoice=choice();
switch(listchoice)
{
	case 1:
		cout<<"ENTER BOOK ID:"<<endl;
		cin>>id;
		obj.issuebook(id);
		mobj.borrow(mem_id,id);
		break;
	case 2:
		cout<<"ENTER BOOK ID:"<<endl;
		cin>>id;
		
		mobj.returnmembook(mem_id,id);
		obj.returnaddbook(id);
		break;
	case 3:
		cout<<"1.BY NAME\n2.BY ID"<<endl;
		cin>>sc;
		if(sc==1)
		{
		cout<<"ENTER BOOK NAME:"<<endl;
		cin.ignore();
		cin.getline(bookname,20);
		obj.searchname(bookname);
		break;
	}
	else if(sc==2)
	{
		cout<<"ENTER BOOK ID:"<<endl;
		cin>>id;
		obj.search(id);
		break;
	}
	else
	{
		cout<<"INVALID!"<<endl;
		break;
	}

	case 4:
		cout<<"ENTER BOOK NAME:"<<endl;
		cin.ignore();
		cin.getline(bookname,20);
		obj.availablecopy(bookname);
		break;
	case 5:
		cout<<"ALL BOOKS!"<<endl;
		obj.print();
		break;
		
	case 6:
		mobj.borrowcount(mem_id);
		break;		
}
}
}
}
}

else if(u==2)
{
	int pass;
	cout<<"ENTER PASSWORD:"<<endl;
	cin>>pass;
	if(!mobj.admincheck(pass))
	{
		cout<<"INVALID!"<<endl;
	}
	else
	{
	int listchoice;
	cout<<"======== ADMIN MENU=========="<<endl;
	while(listchoice!=9)
	{
		cout<<"========================"<<endl;
	cout<<"1.DISPLAY BOOKS\n2.SEARCH BOOKS\n3.DELETE BOOKS\n4.DISPLAY MEMBERS\n5.SEARCH MEMBERS\n6.ADD NEW MEMBER\n7.ADD NEW BOOK\n8.DELETE MEMBERS\n9.LOGOUT"<<endl;
cin>>listchoice;
switch(listchoice)
{
	case 1:
		cout<<"ALL BOOKS!"<<endl;
		obj.print();
		break;
	case 2:
			cout<<"1.BY NAME\n2.BY ID"<<endl;
		cin>>sc;
		if(sc==1)
		{
		cout<<"ENTER BOOK NAME:"<<endl;
		cin>>bookname;
		obj.searchname(bookname);
		break;
	}
	else if(sc==2)
	{
		cout<<"ENTER BOOK ID:"<<endl;
		cin>>id;
		obj.search(id);
		break;
	}
	else
	{
		cout<<"INVALID!"<<endl;
		break;
	}
	
	case 3:
		cout<<"ENTER BOOK ID:"<<endl;
		cin>>id;
		obj.deletebook(id);
		break;
		
	case 4:
		mobj.printm();
		break;
		
	case 5:
		cout<<"ENTER MEMBER ID:"<<endl;
		cin>>mem_id;
		mobj.searchm(mem_id);
		break;
	
	case 6:
		cout<<"ENTER MEMBER ID:"<<endl;
		cin>>mem_id;
		cout<<"ENTER MEMBER NAME:"<<endl;
		cin>>mem_name;
		cout<<"ENTER CONTACT NUMBER:"<<endl;
		cin>>contact;
		mobj.addmember(mem_id,mem_name,contact);
		break;
		
	case 7:
		cout<<"ENTER BOOK ID:"<<endl;
		cin>>id;
		cout<<"ENTER BOOK NAME:"<<endl;
		cin>>bookname;
		cout<<"ENTER AUTHOR NAME:"<<endl;
		cin>>aname;
		cout<<"ENTER TITLE:"<<endl;
		cin>>btitle;
		cout<<"ENTER GENRE:"<<endl;
		cin>>bgenre;
		cout<<"ENTER TOTAL COPIES:"<<endl;
		cin>>btotal;
		cout<<"ENTER AVAILABLE COPIES:"<<endl;
		cin>>bavail;
		obj.addbook(id,bookname,aname,btitle,bgenre,bavail,btotal);
		break;
		
		
	case 8:
		cout<<"ENTER MEMBER ID:"<<endl;
		cin>>mem_id;
		mobj.deletemember(mem_id);
		break;
	
		
}
}
}
}
}
}

