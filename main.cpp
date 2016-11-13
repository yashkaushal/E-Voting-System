//
//  main.cpp
//  oop project unleashed
//
//  Created by yash kaushal on 19/04/15.
//  Copyright (c) 2015 yash kaushal. All rights reserved.
//

#include <iostream>
#include "string"
#include"stdio.h"
#include"stdlib.h"
#include <unistd.h>
using namespace std;

class voter
{
public:

    string fname;
    string lname;
    string phone;
    string email;
    int r_number;
    string pass;
    int flag=0;
    int status=0;
    
    voter();
   
    void reg_voter_rno()
    {
        cout<<"roll number:";
        cin>>r_number;
    }
    void reg_voter()                            //requesting all details
    {
        cout<<"\nenter details- \nfirst name:";
        cin>>fname;
        cout<<"\nlast name:";
        cin>>lname;
        
        cout<<"\nphone number:";
        cin>>phone;
        cout<<"email address:";
        cin>>email;

    }
    void reg_voter_pass()
    {
        cout<<"\npassword:";
        cin>>pass;
    }
   
    
    void disp_voter()                                   //display details
    {
        cout<<"\nname:"<<fname<<" "<<lname<<"\nroll number:"<<r_number<<"\nphone number:"<<phone<<"\nemail address:"<<email;
    }
};

voter voters[50];
voter a;
voter b;

voter::voter()                                          //sorting voters in acending order of r.no.
{
    for(int j=0;j<50;j++)
    {
    for (int i = 0; i<50; i++)
    {
        if (voters[i].r_number>voters[i+1].r_number)
        {
            a=voters[i+1];
            voters[i+1]=voters[i];
            voters[i]=a;
            
        }
        else if (voters[i].r_number==voters[i+1].r_number)
        {
            break;
        }
    }
    }
};

int n=0;
int user;


    void add_voter()                                                //adds voter to database
    {
        while(1)
        {
        cout<<"\nwant to add new voter?\nenter 1 for yes,0 for no?:";
        int a;
        cin>>a;
        if (a==1)
        {
            voters[n].reg_voter();
            voters[n].reg_voter_rno();
            cout<<"your roll number will be used for login";
            voters[n].reg_voter_pass();
            n++;
        }
        
        else{
            break;
            }
        }
    }

class voter_login:public voter
{
public:
    int id;
    void login()                                    //search
    {
        string temp_pass;

        cout<<"\nenter roll number:";
        cin>>id;
        for (user = 0; user<50;)
        {
            if (id==voters[user].r_number)
            {
                cout<<"\nenter password:";
                cin>>temp_pass;
                if (temp_pass==voters[user].pass)
                {
                    cout<<"\nlogged in";
                    voters[user].status=1;
                    break;                              //break to preserve user's int value
                }
                else
                {
                    cout<<"\nincorrect password";
                }
            }
            else if(user==49)
            {
                cout<<"\nnot found\nlogin failed";
            }
            user++;
        }
    }
    
    void logout()                                               //status used for login flag
    {
        voters[user].status=0;
        user=0;                                                     //user value returned to 0
        cout<<"\nyou have successfully logged out.";
        
    }
    
};

class voter_features:public voter_login
{
public:
    void see_details()
    {
        if (voters[user].status==0)                     //make proper function to check login
        {
            cout<<"not authorised";
        }
        else if (voters[user].status==1)
        {
            voters[user].disp_voter();
        }
    }
    
    void update_details()
    {
        if (voters[user].status==0)
        {
            cout<<"not authorised";
        }
        else if (voters[user].status==1)
        {
            voters[user].reg_voter();
            logout();
        }

    }
    void change_voter_pass()
    {
        if (voters[user].status==0)
        {
            cout<<"not authorised";
        }
        else if (voters[user].status==1)
        {
            voters[user].reg_voter_pass();
            logout();
        }
    }
    
    void delete_voter()
    {
        b.fname = "deleted";
        b.lname = "";
        b.phone = "deleted";
        b.email = "deleted";
        b.r_number = 999999;        //999999 so that it goes to the last of array and doesn't slow upcoming fast search
        b.pass = "deleted";
        b.flag = 0;
        b.status = 0;
        
        if (voters[user].status==0)
        {
            cout<<"not authorised";
        }
        else if (voters[user].status==1)
        {
            voters[user] = b;
            logout();
            cout<<"\naccount has been deleted";
        }
        
    }
};
int uidc=01;
string fieldvalue[20];
string fieldname[20];
int fieldnumber=0;

class candidate
{
public:
   

    string canpass;
    void add_field()
    {
        cout<<"\nenter field name:";
        cin>>fieldname[fieldnumber];
        fieldnumber++;
    }
    void add_fieldvalue()
    {
        for (int f=0; f<fieldnumber; f++)
        {
            cout<<fieldname[f]<<":";
            cin>>fieldvalue[f];
        }
    }
    
    
    string cfname,clname;
    int canstatus=0;
    int uid;
    int votecount=0;
    candidate();
    
    void reg_candidate_uid()
    {
        uid=uidc;
        uidc++;
        cout<<"\nUID:";
        cout<<uid;
        
    }
    void reg_candidate()                            //requesting all details
    {
        cout<<"\nenter details- \nfirst name:";
        cin>>cfname;
        cout<<"\nlast name:";
        cin>>clname;
        add_fieldvalue();
       
    }
    void reg_candidate_pass()
    {
        cout<<"\npassword:(dont use space)";
        cin>>canpass;
    }
    
    
    void disp_candidate()                                   //display details
    {
        cout<<"\nname:"<<cfname<<" "<<clname<<"\nUID:"<<uid;
        for (int i=0; i<=fieldnumber; i++)
        {
            cout<<"\n"<<fieldname[i];
            cout<<"\n"<<fieldvalue[i];
            
        }
    }

    
  
};
int m;
candidate candidates[50];
candidate a1;
candidate b1;

candidate::candidate()                                      //sorting
{
    for(int j=0;j<50;j++)
    {
        for (int i = 0; i<m; i++)
        {
            if (candidates[i].uid>candidates[i+1].uid)
            {
                a1=candidates[i+1];
                candidates[i+1]=candidates[i];
                candidates[i]=a1;
                
            }
            
        }
    }

}

int can;

class candidate_login: public candidate
{
public:
    void canlogin()
    {
        string temp_pass;

        cout<<"\nenter UID:";
        cin>>uid;
        for (can = 0; can<50;)
        {
            if (uid==candidates[can].uid)
            {
                cout<<"\nenter password:";
                cin>>temp_pass;
                if (temp_pass==candidates[can].canpass)
                {
                    cout<<"\nlogged in";
                    candidates[can].canstatus=1;
                    break;
                }
                else
                {
                    cout<<"\nincorrect password";
                }
            }
            else if(can==49)
            {
                cout<<"\nnot found\nlogin failed";
            }
            can++;
        }
    }
    
    void canlogout()
    {
        candidates[can].canstatus=0;
        can=0;
        cout<<"\nyou have successfully logged out.";
        
    }
    void add_candidate()                                                //adds voter to database
    {
        while(1)
        {
            cout<<"\nwant to add new candidate?\nenter 1 for yes,0 for no?:";
            int a;
            cin>>a;
            if (a==1)
            {
                candidates[m].reg_candidate_uid();
                cout<<"\nyour UID will be used for login";
                candidates[m].reg_candidate();
                candidates[m].reg_candidate_pass();
                m++;
            }
            
            else{
                break;
            }
        }
    }
};
int deleted;
class candidate_features:public candidate_login
{
public:
    void see_can_details()
    {
        if (candidates[can].canstatus==0)                     //make proper function to check login
        {
            cout<<"not authorised";
        }
        else if (candidates[can].canstatus==1)
        {
            candidates[can].disp_candidate();
        }
    }
    
    void update_can_details()
    {
        if (candidates[can].canstatus==0)
        {
            cout<<"not authorised";
        }
        else if (candidates[can].canstatus==1)
        {
            candidates[can].reg_candidate();
            canlogout();
        }
        
    }
    void change_candidate_pass()
    {
        if (candidates[can].canstatus==0)
        {
            cout<<"not authorised";
        }
        else if (candidates[can].canstatus==1)
        {
            candidates[can].reg_candidate_pass();
            canlogout();
        }
    }
    
    void delete_candidate()
    {
        b1.cfname = "deleted";
        b1.clname = "";
        b1.uid = 999999;                //  goes to the last of array
        b1.canpass = "deleted";
        b1.canstatus = 0;
        
        
            candidates[deleted-1] = b1;
        m--;
        candidate();
        uidc--;
        }
        
    
};
int permission=0;
class admin:public candidate_features,public voter_features
{
public:
    string admin_name="admin";
    string admin_Pass="1234";
    int adstatus=0;
    void admin_login()                                   //search
        {
            string temp_pass,temp_name;
            
            cout<<"\nenter username:";
            cin>>temp_name;
            cout<<"\nenter password:";
            cin>>temp_pass;
            if (temp_pass==admin_Pass&&temp_name==admin_name)
                    {
                        cout<<"\nlogged in\nwelcome admin";
                        adstatus=1;
                    }
                    else
                    {
                        cout<<"\nincorrect usename or password";
                    }
                }
    
    void admin_logout()
    {
        adstatus=0;
        cout<<"\nyou have succesfully logged out";
    }
    string req[100];
    int reqs=0;
    void reg_req()
    {
        getline(cin,req[reqs]);
        reqs++;

        }
            
    
    
        void show_req()
        {
            for (int i=0; i<reqs; i++) {
                cout<<"\n"<<req[i];

            }
        }
    void cast_vote()
    {
        int vote;
        for (int i=0; i<m; i++)
        {
            candidates[i].disp_candidate();
        }
        if (voters[user].flag==1)
        {
            cout<<"\nvote casted\nacces dinied";
        }
        else{
    cout<<"\nenter UID of selected candidate:";
        cin>>vote;
        candidates[vote-1].votecount++;
        voters[user].flag=1;
    }
    }
    void result()
    {
        for (int i = 0; i<uidc-1; i++)
        {
            cout<<"\n"<<candidates[i].cfname<<" "<<candidates[i].clname;
            cout<<"\t"<<candidates[i].votecount;
        }
    }
    void allow_result()
    {
        if(permission==0)
        {
            permission=1;
        }
        else
        {
            permission=0;
        }
    }
};



int main()
{
    int choice,exit=0;
    admin dummy;
    cout<<"\n\t\t^^^~~~~~~E-VOTING SYSTEM~~~~~~~^^^";
    
    while (exit==0) {
    cout<<"\n1.login voter\n2.login candidate\n3.admin login\n4.check result\n5.request to admin\n6.exit\nenter selection:";
    cin>>choice;
        
    switch (choice) {
            
    
  case 1:
    {
        dummy.login();
        while(voters[user].status==1)
        {
        cout<<"\n1.see details\n2.update details\n3.change password\n4.delete account\n5.logout\n6.see candidates and case vote\nenter selection:";
        cin>>choice;
        switch (choice) {
            case 1:
                dummy.see_details();
                break;
                
            case 2:
                dummy.update_details();
                break;
                
            case 3:
                dummy.change_voter_pass();
                break;
                
            case 4:
                dummy.delete_voter();
                break;
                
            case 5:
                dummy.logout();
                break;
                
            case 6:
                dummy.cast_vote();
                break;
                
            default:
                break;
        }
            
            
            
        }
        break;}
            case 2:
        {
            dummy.canlogin();
            while(candidates[can].canstatus==1)
            {
                cout<<"\n1.see details\n2.update details\n3.change password\n4.logout\nenter selection:";
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        dummy.see_can_details();
                        break;
                        
                    case 2:
                        dummy.update_can_details();
                        break;
                        
                    case 3:
                        dummy.change_candidate_pass();
                        break;
                        
                    
                        
                    case 4:
                        dummy.canlogout();
                        break;
                        
                    default:
                        break;
                }
            }
            break;}
        case 3:
        {
            dummy.admin_login();
            while (dummy.adstatus==1)
            {
                cout<<"\n1.create voter\n2.create candidate\n3.see candidates\n4.check messages/requests\n5.declare/hide result\n6.logout\n7.delete candidate\n8.add field\n9.result\nenter selection:";
                cin>>choice;
                switch (choice) {
                    case 1:
                    {
                        add_voter();

                        break;
                    }
                    case 2:
                    {
                        dummy.add_candidate();
                        break;
                    }
                        
                    case 3:
                    {
                        for (int i=0; i<m; i++)
                        {
                            candidates[i].disp_candidate();
                        }
                        
                        
                        break;
                    }
                        
                    case 4:
                    {
                        dummy.show_req();
                        break;
                    }
                        
                    case 5:
                    {
                        dummy.allow_result();
                        if (permission==0)
                        {
                            cout<<"result hidden";
                        }
                        else{
                            cout<<"result declared!";
                        }
                        break;
                    }
                    case 6:
                    {
                        dummy.admin_logout();
                        break;
                    }
                        
                    case 7:
                    {
                        for (int i=0; i<m; i++)
                        {
                            candidates[i].disp_candidate();
                        }
                        cout<<"\nenter UID of candidate to be deleted:";
                        cin>>deleted;
                        dummy.delete_candidate();
                        break;
                    }
                    case 8:
                    {
                        dummy.add_field();
                        break;
                    }
                    case 9:
                    {
                        dummy.result();
                        break;
                    }
                    default:
                        break;
                }
            }
            break;}
            
        case 4:
        {
            if(permission==0)
            {
                cout<<"\nresult not out yet!";
            }
            else
            {
            dummy.result();
            }
            break;
        }
        case 5:
        {
            cout<<"\nenter message:";
        
            cin.get();
            dummy.reg_req();
            break;
        }
        case 6:
        {
            exit=1;
            break;
        }
default:
    break;
}
}
}
