// BANK MANAGEMENT SYSTEM
// Features:    1) New consumer can open their bank account using name phone number and password
//              2) Employees with their Id and Password can enter transaction of consumer in database
//              3) Consumer can also print their passbook using customer id and password

#include "bits/stdc++.h"
#include <ctime>
#include<string.h>
using namespace std;

class CustomerdatabaseNode{     // Customers Transactions Node
public:
    int date,month,year;
    CustomerdatabaseNode* customerNext;
    CustomerdatabaseNode* employeeNext;
    int debited,credited,employeeId,customerId;
    int old_balance;
    CustomerdatabaseNode(int debited,int credited,int employeeId,int customerId,CustomerdatabaseNode* previouscustomer,CustomerdatabaseNode* previousemployee,tm* local_time){
        this->debited = debited;
        this->credited = credited;
        this->employeeId = employeeId;
        this->customerId = customerId;
        date = local_time->tm_mday;
        month = local_time->tm_mon;
        year = local_time->tm_year;
        if(previouscustomer!=NULL){
            old_balance = previouscustomer->old_balance-debited+credited;
        }
        else{
            old_balance = credited-debited;
        }    
        customerNext = previouscustomer;
        employeeNext = previousemployee;
    }
};

class CustomerNode{          // Customers Node
private:
    string phoneNumber;
    string password,name;
public:
    int customerId;
    CustomerdatabaseNode* passbook;
    CustomerNode(int customer_customerId,string customer_name,string customer_phoneNumber,string customer_password){
        customerId = customer_customerId;
        name = customer_name;
        phoneNumber = customer_phoneNumber;
        password = customer_password;
        passbook=NULL;
    }
    bool ConfirmPassword(string password){    // Function in class to confirm the password entered!
        if(this->password==password){
            return true;
        }
        else{
            return false;
        }
    }
};

class EmployeeNode{            // Employees data Node
private:
    int EmployeeId;
    string EmployeePassword,EmployeeName;
public:
    CustomerdatabaseNode* toptransaction;
    EmployeeNode(int EmployeeId,string EmployeePassword,string EmployeeName){
        this->EmployeeId = EmployeeId;
        this->EmployeePassword = EmployeePassword; 
        this->EmployeeName = EmployeeName;
        toptransaction=NULL;
    }
    bool ConfirmPassword(string password){    // Function in class to confirm the password entered!
        if(password==EmployeePassword){
            return true;
        }
        else{
            return false;
        }
    }
};

// Function to print passbook of consumer's transaction
void PassbookPrint(int customerId,CustomerdatabaseNode* required_passbook){
    CustomerdatabaseNode*temp = required_passbook;
    ostringstream ss;                                   // For left padding these attributes!
    ss<<left<<setfill(' ')<<setw(15)<<"Date";
    cout<<ss.str();
    ss.str("");
    ss<<left<<setfill(' ')<<setw(20)<<"Customer ID";
    cout<<ss.str();
    ss.str("");
    ss<<left<<setfill(' ')<<setw(20)<<"Employee ID";
    cout<<ss.str();
    ss.str("");
    ss<<left<<setfill(' ')<<setw(25)<<"Debited Amount";
    cout<<ss.str();
    ss.str("");
    ss<<left<<setfill(' ')<<setw(25)<<"Credited amount";
    cout<<ss.str();
    ss.str("");
    ss<<left<<setfill(' ')<<setw(25)<<"Total Balance";
    cout<<ss.str()<<endl;
    ss.str("");

    if(temp!=NULL){
        while(temp!=NULL){
            string s = to_string(temp->date)+'/'+to_string(1+temp->month)+'/'+to_string(1900+temp->year);
            ostringstream ss;
            ss<<left<<setfill(' ')<<setw(15)<<s;
            cout<<ss.str();
            ss.str("");
            ss<<left<<setfill(' ')<<setw(20)<<customerId;
            cout<<ss.str();
            ss.str("");
            ss<<left<<setfill(' ')<<setw(20)<<temp->employeeId;
            cout<<ss.str();
            ss.str("");
            ss<<left<<setfill(' ')<<setw(25)<<temp->debited;
            cout<<ss.str();
            ss.str("");
            ss<<left<<setfill(' ')<<setw(25)<<temp->credited;
            cout<<ss.str();
            ss.str("");
            ss<<left<<setfill(' ')<<setw(25)<<temp->old_balance;
            cout<<ss.str()<<endl;
            ss.str("");
            temp = temp->customerNext;
        }
    }    
    else{
        ostringstream ss;
        ss<<left<<setfill(' ')<<setw(15)<<"--";
        cout<<ss.str();
        ss.str("");
        ss<<left<<setfill(' ')<<setw(20)<<customerId;
        cout<<ss.str();
        ss.str("");
        ss<<left<<setfill(' ')<<setw(20)<<"--";
        cout<<ss.str();
        ss.str("");
        ss<<left<<setfill(' ')<<setw(15)<<"--";
        cout<<ss.str();
        ss.str("");
        ss<<left<<setfill(' ')<<setw(15)<<"--";
        cout<<ss.str();
        ss.str("");
        ss<<left<<setfill(' ')<<setw(15)<<"--";
        cout<<ss.str()<<endl;
        ss.str("");
    }
}
// Function to print transactions entered by Employee 
void EmployeePassbookPrint(int employeeId,CustomerdatabaseNode* required_employeepassbook){
    CustomerdatabaseNode*temp = required_employeepassbook;
    ostringstream ss;                                       // For left padding the attributes required to print!
    ss<<left<<setfill(' ')<<setw(15)<<"Date";
    cout<<ss.str();
    ss.str("");
    ss<<left<<setfill(' ')<<setw(20)<<"Customer ID";
    cout<<ss.str();
    ss.str("");
    ss<<left<<setfill(' ')<<setw(20)<<"Employee ID";
    cout<<ss.str();
    ss.str("");
    ss<<left<<setfill(' ')<<setw(25)<<"Debited Amount";
    cout<<ss.str();
    ss.str("");
    ss<<left<<setfill(' ')<<setw(25)<<"Credited amount";
    cout<<ss.str();
    ss.str("");
    ss<<left<<setfill(' ')<<setw(25)<<"Total Balance";
    cout<<ss.str()<<endl;
    ss.str("");

    if(temp!=NULL){
        while(temp!=NULL){
            string s = to_string(temp->date)+'/'+to_string(1+temp->month)+'/'+to_string(1900+temp->year);
            ostringstream ss;
            ss<<left<<setfill(' ')<<setw(15)<<s;
            cout<<ss.str();
            ss.str("");
            ss<<left<<setfill(' ')<<setw(20)<<temp->customerId;
            cout<<ss.str();
            ss.str("");
            ss<<left<<setfill(' ')<<setw(20)<<temp->employeeId;
            cout<<ss.str();
            ss.str("");
            ss<<left<<setfill(' ')<<setw(25)<<temp->debited;
            cout<<ss.str();
            ss.str("");
            ss<<left<<setfill(' ')<<setw(25)<<temp->credited;
            cout<<ss.str();
            ss.str("");
            ss<<left<<setfill(' ')<<setw(25)<<temp->old_balance;
            cout<<ss.str()<<endl;
            ss.str("");
            temp = temp->employeeNext;
        }
    }    
    else{
        ostringstream ss;
        ss<<left<<setfill(' ')<<setw(15)<<"--";
        cout<<ss.str();
        ss.str("");
        ss<<left<<setfill(' ')<<setw(20)<<temp->customerId;
        cout<<ss.str();
        ss.str("");
        ss<<left<<setfill(' ')<<setw(20)<<"--";
        cout<<ss.str();
        ss.str("");
        ss<<left<<setfill(' ')<<setw(15)<<"--";
        cout<<ss.str();
        ss.str("");
        ss<<left<<setfill(' ')<<setw(15)<<"--";
        cout<<ss.str();
        ss.str("");
        ss<<left<<setfill(' ')<<setw(15)<<"--";
        cout<<ss.str()<<endl;
        ss.str("");
    }
}

signed main(){
    int ManagerId;              // Bank Manager information
    string ManagerPassword;
    cout<<"Enter ManagerId: ";
    cin>>ManagerId;  
    cout<<"Enter ManagerPassword: ";
    cin>>ManagerPassword;

    int EmployeesNumber;        
    cout<<"Enter number of Employees in bank: ";
    cin>>EmployeesNumber;           // Employees in bank
    EmployeeNode**  Employeearray;
    Employeearray = new EmployeeNode*[EmployeesNumber];
    for(int i=0;i<EmployeesNumber;i++){
        int EmployeeId;
        string EmployeeName,EmployeePassword;
        cout<<"Enter Employee Name and Employee Password: ";
        cin>>EmployeeName>>EmployeePassword;
        EmployeeNode* n = new EmployeeNode(i+1,EmployeePassword,EmployeeName);      // Employee Id is 1 greater than location of that id in array!
        Employeearray[i] = n;
    }

    bool done;
    int customerNumber = 0;
    vector<CustomerNode*> CustomerVector;
    while(done!=true){
        int function_required;
        cout<<"New User->Press 1 ; For passbook->Press 2 ; For entering new Transaction(for office use only)->Press 3:  ; If manager->Press 4: ";
        cin>>function_required;


        if(function_required==1){
            string phoneNumber;
            string password,name;
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Phone Number: ";
            cin>>phoneNumber;
            cout<<"Enter password: ";
            cin>>password;
            CustomerNode* c = new CustomerNode(customerNumber+1,name,phoneNumber,password);                 // NOTE: > CustomerID is 1 greater than array location
            // cout<<c->customerId<<endl;
            cout<<"Customer Id: "<<customerNumber+1<<"  Name: "<<name<<"  Phone Number: "<<phoneNumber<<endl;
            // Allocate node pointer in CustomerVector
            CustomerVector.push_back(c);    //
            customerNumber++;
        }

        if(function_required==2){
            int CustomerId;
            string CustomerPassword;
            cout<<"Enter Customer ID: ";
            cin>>CustomerId;
            cout<<"Enter Password: ";
            cin>>CustomerPassword;

            int low=0,high=CustomerVector.size();
            bool find=false;
            if(CustomerId>0 and CustomerId<=customerNumber){
                CustomerdatabaseNode* passbook_required;
                bool invalidPassword=false;
                while(find!=true and invalidPassword!=true){
                    if( CustomerVector.at((low+high)/2)->customerId==CustomerId ){
                        if(CustomerVector.at((low+high)/2)->ConfirmPassword(CustomerPassword)==true){
                            passbook_required = CustomerVector.at((low+high)/2)->passbook;
                            find=true;
                        }    
                        else{
                            invalidPassword=true;
                        }
                    }
                    else if(CustomerVector.at((low+high)/2)->customerId > CustomerId){
                        high = (low+high)/2;
                    }
                    else{
                        low = (low+high)/2;
                    }
                }
                if(find==true and invalidPassword!=true){
                    PassbookPrint(CustomerId,passbook_required);
                }
                else{
                    cout<<"OOPS! Invalid Password!"<<endl;
                }
            }
            else{
                cout<<"OOPS! Invalid Customer Id or Password!"<<endl;
            }    
        }

        if(function_required==3){
            int EmployeeId;
            string EmployeePassword;
            cout<<"Enter Employee Id: ";
            cin>>EmployeeId;
            cout<<"Enter Employee Password: ";
            cin>>EmployeePassword;
            if( EmployeeId>0 and EmployeeId<=EmployeesNumber and Employeearray[EmployeeId-1]->ConfirmPassword(EmployeePassword)==true ){
                int CustomerId,amount;
                int debcre=0;;
                cout<<"Enter Customer Id: ";
                cin>>CustomerId;
                if(CustomerId>0 and CustomerId<=customerNumber){
                    cout<<"Either amount debited or credited? (1->debited ; 2->credited): ";
                    cin>>debcre;

                    time_t ttime = time(0);
                    tm *local_time = localtime(&ttime);
                    if(debcre==1){
                        // for entering debited transaction!
                        int low=0,high=CustomerVector.size();
                        while(CustomerId!=CustomerVector.at((low+high)/2)->customerId){
                            if(CustomerId>CustomerVector.at((low+high)/2)->customerId){
                                low = (low+high)/2;
                            }
                            else{
                                high = (low+high)/2;
                            }
                        }
                        cout<<"Enter the amount debited: ";
                        cin>>amount;
                        if(CustomerVector.at((low+high)/2)->passbook!=NULL and amount < CustomerVector.at((low+high)/2)->passbook->old_balance){
                            CustomerdatabaseNode* current = new CustomerdatabaseNode(amount,0,EmployeeId,CustomerId,CustomerVector.at((low+high)/2)->passbook,Employeearray[EmployeeId-1]->toptransaction,local_time);
                            CustomerVector.at((low+high)/2)->passbook = current;
                            Employeearray[EmployeeId-1]->toptransaction = current;
                        }
                        else{
                            cout<<"OOPS! Required amount is greater than Balance"<<endl;
                        }    
                    }
                    else if(debcre==2){
                        // for entering credited transaction!
                        int low=0,high=CustomerVector.size();
                        while(CustomerId!=CustomerVector.at((low+high)/2)->customerId){
                            if(CustomerId>CustomerVector.at((low+high)/2)->customerId){
                                low = (low+high)/2;
                            }
                            else{
                                high = (low+high)/2;
                            }
                        }
                        cout<<"Enter the amount credited: ";
                        cin>>amount;
                        CustomerdatabaseNode* current = new CustomerdatabaseNode(0,amount,EmployeeId,CustomerId,CustomerVector.at((low+high)/2)->passbook,Employeearray[EmployeeId-1]->toptransaction,local_time);
                        CustomerVector.at((low+high)/2)->passbook = current;
                        Employeearray[EmployeeId-1]->toptransaction = current;
                    }
                    else{
                        cout<<"OOPS! Invalid number entered!"<<endl;
                    }
                }
                else{
                    cout<<"OOPS! Invalid customer Id entered"<<endl;
                }
            }  
            else{
                cout<<"OOPS! Invalid Employee Id or Password"<<endl;
            }  
        }

        if(function_required==4){
            int manager_required;
            cout<<"For Customer passbook->Press 1 ; For Employee Passbook->Press 2 ";
            cin>>manager_required;
            if(manager_required==1){
                int customerId;
                cout<<"Enter the Customer Id: ";
                cin>>customerId;

                int low=0,high=CustomerVector.size();
                bool find=false;
                if(customerId>0 and customerId<=customerNumber){
                    CustomerdatabaseNode* passbook_required;
                    bool invalidPassword=false;
                    while(find!=true and invalidPassword!=true){
                        if( CustomerVector.at((low+high)/2)->customerId==customerId and invalidPassword!=true){
                            passbook_required = CustomerVector.at((low+high)/2)->passbook;
                            PassbookPrint(customerId,passbook_required);
                            find=true;
                        }
                        else if(CustomerVector.at((low+high)/2)->customerId > customerId){
                            high = (low+high)/2;
                        }
                        else{
                            low = (low+high)/2;
                        }
                    }
                }
                else{
                    cout<<"OOPS! Invalid Customer Id !"<<endl;
                } 
            }
            if(manager_required==2){
                int employeeId;
                cout<<"Enter Employee Id: ";
                cin>>employeeId;
                if(employeeId>0 and employeeId<=EmployeesNumber){
                    EmployeePassbookPrint(employeeId,Employeearray[employeeId-1]->toptransaction);
                }
                else{
                    cout<<"OOPS! invalid employee ID "<<endl;
                }
            }
        }

        int completed;
        cout<<"Are you done? Press 1 for yes and 2 for no:  ";
        cin>>completed;
        if(completed!=2){
            done=true;
        }
    }

    int release=0;
    while(release<CustomerVector.size()){
        while(CustomerVector[release]->passbook!=NULL){
            CustomerdatabaseNode* temp = CustomerVector[release]->passbook;
            CustomerVector[release]->passbook = CustomerVector[release]->passbook->customerNext;
            free(temp);
        }
        release++;
    }
    delete []Employeearray;
    CustomerVector.shrink_to_fit();
    return 0;
}