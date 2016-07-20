#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip.h>
struct date
{
	int dd, mm, yy;
};
int checkdate(date dt)
{
  	int maxdays[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  	if (dt.yy%100!=0 && dt.yy%4==0 || dt.yy%400==0)
   	maxdays[1]=29;
  	if (dt.mm>=1 && dt.mm<=12)
  	{
    	if (dt.dd>=1 && dt.dd<=maxdays[dt.mm-1])
      	return 1;
    	else
      	return 0;
  	}
  	else
    	return 0;
}
void inputdate(date& dt)
{
   int valid;
   do
   {
      cout<<"Enter Day [1-31]  ? "; cin>>dt.dd;
      cout<<"Enter Month [1-12]? "; cin>>dt.mm;
      cout<<"Enter Year [YYYY] ? "; cin>>dt.yy;
      valid=checkdate(dt);
      if (valid==0)
      	cout<<"Invalid date. Input again.\n";
   }
   while(valid==0);
}
int nodays(date dt, date dt1)
{
int days=0;
int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	 if(dt.dd==dt1.dd && dt.mm==dt1.mm && dt.yy==dt1.yy)
     {
    		days=0;
     }
    else
    if(dt.yy == dt1.yy)
    {
        if(dt.mm == dt1.mm)
            days = dt1.dd - dt.dd;
        else
        {
            for(int i = dt.mm; i < dt1.mm-1;i++)
                {days += month_days[i];
                cout<<days<<endl;}
            days += month_days[dt.mm-1] - dt.dd + dt1.dd;
        }
    }
    else
    {
        for(int i = 0; i < dt1.mm-1; i++)
            {days += month_days[i];
            cout<<days<<endl;}
        for(int i = dt.mm; i < 12; i++)
            {days += month_days[i];cout<<days<<endl;}
        if(dt1.yy - dt.yy >= 0)
        days += (dt1.yy - dt.yy - 1)*365 +
            month_days[dt.mm-1] - dt.dd + dt1.dd;
    }

    return days;
}
void displaydate(date dt)
{
   printf("%02i-%02i-%04i\n", dt.dd, dt.mm, dt.yy);
}
class book
{
	char acno[6];
	char bname[30];
	char aname[30];
   char pname[20];
   double price;
  public:
  	char* genacno()
	{
     acno[0]=char(49+rand()%9);
     for(int k=1;k<5;k++)
      acno[k]=char(48+rand()%10);
     acno[5]='\0';
     return acno;
	}
	void createbook()
	{
		cout<<"\nNEW BOOK ENTRY...\n";
      genacno();
		cout<<"\n\nEnter The Name of The Book ";
		gets(bname);
		cout<<"\n\nEnter The Author's Name ";
		gets(aname);
      cout<<"\n\nEnter The Publisher's Name ";
		gets(pname);
      cout<<"\n\nEnter The Price of book ";cin>>price;
		cout<<"\n\n\nBook Created..";
	}

	void showbook()
	{
		cout<<"\nAC no. : "<<acno;
		cout<<"\nBook Name : ";
		puts(bname);
		cout<<"Author Name : ";
		puts(aname);
      cout<<"Publisher Name : ";
		puts(pname);
      cout<<"Price : "<<price;
	}

	void modifybook()
	{
		cout<<"\nModify Book Name : ";
		gets(bname);
		cout<<"\nModify Author's Name of Book : ";
		gets(aname);
      cout<<"\nModify Publisher's Name of Book : ";
		gets(pname);
      cout<<"\nModify Price of book : ";cin>>price;
	}
   char* retacno()
   {
		return acno;
   }
   char* retbname()
   {return bname;}
   char* retaname()
   {return aname;}
   double retprice()
   {
   	return price;
   }
   void dispacno()
   {
   	cout<<acno<<endl;
   }
	void report()
	{
   	cout<<"  "<<acno<<setw(25)<<bname<<setw(23)<<aname<<setw(14)<<pname<<setw(8)<<price<<"\n";
   }


};
class member
{
	char mcode[6];
	char name[20];
   char phone[10];
	char macno[6];
   int maxissue;
	int issue;
public:
	void createmem()
	{
		clrscr();
      int ch;
	 	cout<<"\nNEW MEMBER ENTRY...\n";
		cout<<"\nEnter The member code ";
		cin>>mcode;
		cout<<"\n\nEnter The Name of The Member ";
		gets(name);
      cout<<"\n\nEnter The Phone number of The Member ";
		cin>>phone;
      do
      {
         cout<<"\n\nEnter the type of membership : ";
      	cout<<"\n\n1. Standard Member(Max Issues=3)";
     	 	cout<<"\n\n2. Premier Member(Max Issues=5)";
      	cout<<"\n\n3. Royal Member(Max Issues=7)";
         cout<<"\n\n3. Deluxe Member(Max Issues=10)";
      	cout<<"\n\nEnter your choice ";cin>>ch;
         switch(ch)
         {
           case 1:maxissue=3;break;
           case 2:maxissue=5;break;
           case 3:maxissue=7;break;
           case 4:maxissue=10;break;
           default:cout<<"\a";
         }
      }
      while(ch<1||ch>4);
      issue=0;
		macno[0]='/0';
		cout<<"\n\nMember Record Created..";
	}

	void showmem()
	{
		cout<<"\nMember Code : "<<mcode;
		cout<<"\nMember Name : ";
		puts(name);
      cout<<"\nMember Phone number : "<<phone;
		cout<<"\nNo of Book issued : "<<issue;
		if(issue>0)
			cout<<"\nLast book issued, AC NO: "<<macno;
	}

	void modifymem()
	{
		cout<<"\nMember Code : ";cin>>mcode;
		cout<<"\nModify Member Name : ";
		gets(name);
      cout<<"\nModify Member Phone number : ";cin>>phone;
      cout<<"\nModify Member maximum issue limit : ";cin>>maxissue;
	}

	char* retmcode()
	{
		return mcode;
	}

	char* retmacno()
	{
		return macno;
	}

	int retmaxissue()
	{
		return maxissue;
	}
   int retissue()
	{
		return issue;
	}

	void addissue()
	{
   	issue+=1;
   }
	void resetissue()
	{
   	issue=0;
   }
	void getmacno(char t[])
	{
		strcpy(macno,t);
	}

	void report()
	{cout<<"\t"<<mcode<<setw(20)<<name<<setw(18)<<phone<<setw(15)<<maxissue<<setw(10)<<issue<<endl;}

};
fstream fp,fp1;
book bk;
member mem;
date dt,dt1;
void write_book()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);
	do
	{
		clrscr();
		bk.createbook();
		fp.write((char*)&bk,sizeof(book));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void write_member()
{
	char ch;
	fp.open("member.dat",ios::out|ios::app);
	do
	{
		mem.createmem();
		fp.write((char*)&mem,sizeof(member));
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void display_spb(char n[])
{
	cout<<"\nBOOK DETAILS\n";
	int flag=0;
	fp.open("book.dat",ios::in);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if (strcmpi(bk.retacno(),n)==0)
		{
			bk.showbook();
		 	flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\nBook does not exist";
	getch();
}

void display_spm(char n[])
{
	cout<<"\nMEMBER DETAILS\n";
	int flag=0;
	fp.open("member.dat",ios::in);
	while(fp.read((char*)&mem,sizeof(member)))
	{
		if((strcmpi(mem.retmcode(),n)==0))
		{
			mem.showmem();
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
    		cout<<"\n\nMember does not exist";
 	getch();
}
void modify_book()
{
	char ac[6];
	int found=0;
	clrscr();
	cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
	cout<<"\n\n\tEnter The AC no. of The book ";cin>>ac;
   cout<<ac<<endl;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if (strcmpi(bk.retacno(),ac)==0)
		{
			bk.showbook();
			cout<<"\nEnter The New Details of book"<<endl;
			bk.modifybook();
			int pos=-1*sizeof(bk);
		    	fp.seekp(pos,ios::cur);
		    	fp.write((char*)&bk,sizeof(book));
		    	cout<<"\n\n\t Record Updated";
		    	found=1;
		}
	}

    	fp.close();
    	if(found==0)
    		cout<<"\n\n Record Not Found ";
    	getch();
}


void modify_member()
{
	char mc[6];
	int found=0;
	clrscr();
	cout<<"\n\n\tMODIFY MEMBER RECORD... ";
	cout<<"\n\n\tEnter The member code of The member ";
	cin>>mc;
	fp.open("member.dat",ios::in|ios::out);
	while(fp.read((char*)&mem,sizeof(member)) && found==0)
	{
		if(strcmpi(mem.retmcode(),mc)==0)
		{
			mem.showmem();
			cout<<"\nEnter The New Details of member"<<endl;
			mem.modifymem();
			int pos=-1*sizeof(mem);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&mem,sizeof(member));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}
void delete_member()
{
	char n[6];
	int flag=0;
	clrscr();
    	cout<<"\n\n\n\tDELETE MEMBER...";
    	cout<<"\n\nEnter The Member code of member that is to be deleted : ";
    	cin>>n;
    	fp.open("member.dat",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp.dat",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&mem,sizeof(member)))
	{
		if(strcmpi(mem.retmcode(),n)!=0)
	     		fp2.write((char*)&mem,sizeof(member));
		else
	   		flag=1;
	}

	fp2.close();
    	fp.close();
    	remove("member.dat");
    	rename("Temp.dat","member.dat");
    	if(flag==1)
     		cout<<"\n\n\tRecord Deleted ..";
    	else
     		cout<<"\n\nRecord not found";
    	getch();
}


void delete_book()
{
	char ac[6];
   int flag=0;
	clrscr();
	cout<<"\n\n\n\tDELETE BOOK ...";
	cout<<"\n\nEnter The Accession n. of the Book that is to be deleted : ";
	cin>>ac;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if (strcmpi(bk.retacno(),ac)!=0)
		{
			fp2.write((char*)&bk,sizeof(book));
		}
      else
      	flag=1;
	}

	fp2.close();
   fp.close();
   remove("book.dat");
   rename("Temp.dat","book.dat");
   if(flag==1)
   	cout<<"\n\n\tRecord Deleted ..";
   else
   	cout<<"\n\n\tRecord not found...";
   getch();
}
void display_allm()
{
	clrscr();
     	fp.open("member.dat",ios::in);
     	if(!fp)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tMEMBER LIST\n\n";
	cout<<"================================================================================\n";
	cout<<"      Member Code"<<setw(10)<<"Name"<<setw(20)<<"Phone"<<setw(20)<<"Limit"<<setw(10)<<"Issued\n";
	cout<<"================================================================================\n";

	while(fp.read((char*)&mem,sizeof(member)))
	{
		mem.report();
	}

	fp.close();
	getch();
}
void display_allb()
{
	clrscr();
	fp.open("book.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"================================================================================\n";
   cout<<"  AC NO"<<setw(20)<<"Book Name"<<setw(20)<<"Author"<<setw(20)<<"Publisher"<<setw(12)<<"Price(KD)\n";
   cout<<"================================================================================\n";

	while(fp.read((char*)&bk,sizeof(book)))
	{
		bk.report();
	}
     	fp.close();
     	getch();
}
void book_issue()
{
	char mc[6],ac[6];
	int found=0,flag=0;
   fstream f;
	clrscr();
	cout<<"\n\nBOOK ISSUE : ";
	cout<<"\n\n\tEnter The Member's code. ";cin>>mc;
   f.open("book.dat",ios::in);
	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"=============================================================\n";
   cout<<"  AC NO"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
   cout<<"=============================================================\n";
	while(f.read((char*)&bk,sizeof(book)))
	{
     cout<<"  "<<bk.retacno()<<setw(25)<<bk.retbname()<<setw(23)<<bk.retaname()<<"\n";
	}
   f.close();
	fp.open("member.dat",ios::in|ios::out);
    	fp1.open("book.dat",ios::in|ios::out);
    	while(fp.read((char*)&mem,sizeof(member)) && found==0)
      {
			if(strcmpi(mem.retmcode(),mc)==0)
			{
				found=1;
            if(mem.retissue()==mem.retmaxissue())
              {
                char ch;
              	 cout<<"\n\n\tYou have already issued books upto your maximum limit\n";
                cout<<"\nIf you wish to renew your subscription, please pay Rs.50";
                cout<<"\n\nDo you wish to renew?(Y,y) ";cin>>ch;
                if(ch=='Y'||ch=='y')
                	{
                  	mem.resetissue();
                     int pos=-1*sizeof(mem);
                     fp.seekp(pos,ios::cur);
                     fp.write((char*)&mem,sizeof(member));
                     break;
                  }
                else
                	{cout<<"\n\nYou cannot issue any books ..";break;}
              }
            else
               {
                  if(mem.retissue()<mem.retmaxissue())
                     {
                        cout<<"\n\n\tEnter the book no. ";
                        cin>>ac;
                        cout<<"\n\nEnter date of issue\n\n";
                        inputdate(dt);
                        while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                        {
                           if(strcmpi(bk.retacno(),ac)==0)
                           {
                              bk.showbook();
                              flag=1;
                              mem.addissue();
                              mem.getmacno(bk.retacno());
                              int pos=-1*sizeof(mem);
                              fp.seekp(pos,ios::cur);
                              fp.write((char*)&mem,sizeof(member));
                              cout<<"\n\n\t Book issued successfully\n\n";
                              cout<<"You issued book on: "; displaydate(dt);cout<<endl;
                           }
                        }
                     if(flag==0)
                        cout<<"Book does not exist";
                     }
                  else
                     cout<<"You have not returned the last book ";
               }
      }
	}
      	if(found==0)
		cout<<"Member record does not exist...";
	getch();
  	fp.close();
  	fp1.close();
}
void book_deposit()
{
    char mc[6],opt;
    int found=0,flag=0,day,fine=0;
    clrscr();
    cout<<"\n\nBOOK DEPOSIT : ";
    cout<<"\n\nEnter Member code ";cin>>mc;
       fp.open("member.dat",ios::in|ios::out);
       fp1.open("book.dat",ios::in|ios::out);
       while(fp.read((char*)&mem,sizeof(member)) && found==0)
          {
            if(strcmpi(mem.retmcode(),mc)==0)
            {
               found=1;
               if(mem.retissue()!=0)
               {
                  while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                  {
                     if(strcmpi(bk.retacno(),mem.retmacno())==0)
                     {
                        cout<<"\n\nISSUED BOOK.....\n\n";
                        bk.showbook();
                        flag=1;
                         cout<<"\n\nIf the issued book is damaged or lost,press(y/n)? ";cin>>opt;
                         if(opt=='Y'||opt=='y')
                           {
                        		double fine=bk.retprice();
                        		cout<<"\n\nFine to be deposited: "<<fine<<endl<<endl;
                              break;
                           }
                        cout<<"\n\nEnter date of deposit\n";
               			inputdate(dt1);
               			cout<<"\nYou deposited book on ";displaydate(dt1);cout<<endl;
               			day=nodays(dt,dt1);
                        cout<<"\n\nYou returned the book after "<<day<<" days\n\n";
                        if(day>7 && day<=15)
                        {
                           fine=(day-7)*0.5;
                           cout<<"\n\nFine has to deposited Rs. "<<fine;
                        }
                        if(day>15)
                        {
                           fine=(day-15)*3;
                           cout<<"\n\nFine has to deposited Rs. "<<fine;
                        }

                        int pos=-1*sizeof(mem);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&mem,sizeof(member));
                        cout<<"\n\n\t Book deposited successfully";
                     }
                  }
                  if(flag==0)
                     cout<<"Book does not exist";
               }
               else
                  cout<<"No book is issued..please check!!";
            }
         }
         if(found==0)
      cout<<"Member record does not exist...";
      getch();
     fp.close();
     fp1.close();
  }
void admin_menu()
{
	clrscr();
	int opt;
	cout<<"\n\n\n\tADMINISTRATOR MENU";
	cout<<"\n\n\t1.Create member record";
	cout<<"\n\n\t2.Display all member records ";
	cout<<"\n\n\t3.Search specific member record ";
	cout<<"\n\n\t4.Modify member record";
	cout<<"\n\n\t5.Delete member record";
	cout<<"\n\n\t6.Create book ";
	cout<<"\n\n\t7.Display all books ";
	cout<<"\n\n\t8.Search specific book ";
	cout<<"\n\n\t9.Modify book ";
	cout<<"\n\n\t10.Delete book ";
	cout<<"\n\n\t11.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-11) ";
	cin>>opt;
	switch(opt)
	{
    		case 1: clrscr();
                 write_member();break;
    		case 2: display_allm();break;
    		case 3:
         		{
                  char mc[6];
                  clrscr();
                  cout<<"\n\n\tPlease Enter The Member code ";
                  cin>>mc;
                  display_spm(mc);
                  break;
               }
         case 4: modify_member();break;
         case 5: delete_member();break;
			case 6: clrscr();
      			  write_book();break;
			case 7: display_allb();break;
		   case 8: {
                  char acn[6];
                  clrscr();
                  cout<<"\n\n\tPlease Enter The book No. ";
                  cin>>acn;
                  display_spb(acn);
                  break;
                 }
         case 9: modify_book();break;
         case 10: delete_book();break;
     		case 11: return;
         default:cout<<"\a";
   }
   	admin_menu();
}

void enter()
{
   clrscr();
	char ch[]="CIFH";
   int k=0;
	for(int i=0;i<4;i++)
		ch[i]=char(ch[i]-17);
   char p[5];
	do
	{
      clrscr();
      cout<<"Enter Password ";cin>>p;
		if(strcmpi(p,ch)!=0)
      	k++;
      else
      	k=0;
	}
	while(k!=0);
   admin_menu();
}
void main()
{
   srand(time(NULL));
	int opt;
	do
	{
		clrscr();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t1. Book Issue";
		cout<<"\n\n\t2. Book Deposit";
	  	cout<<"\n\n\t3. Administrator menu";
	  	cout<<"\n\n\t4. EXIT";
	  	cout<<"\n\n\tPlease Select Your Option (1-4) ";cin>>opt;
	  	switch(opt)
	  	{
			case 1:clrscr();
				    	book_issue();
			   	 	break;
		  	case 2:book_deposit();
			    	 	break;
		  	case 3:enter();
         			break;

		  	case 4:exit(0);
		  	default :cout<<"\a";
		}
   }
   while(opt!=4);
}