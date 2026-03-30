#include<bits/stdc++.h>
using namespace std;
class student
{
    public:
    char rollno[50];
    char name[50];
};
int lenofstudent()
{
    int n = 0;
    ifstream file("studentdata.bin",ios::binary);
    if(!file.is_open())
    {
        cerr<<"error"<<endl;
        return -1;
    }
    student temp;
    while(file.read((char*)&temp,sizeof(temp)))
    {
        n++;
    }
    return n;
}
//Function for adding student
void addStudent()
{
    student s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Enter roll no :\n";
    cin.getline(s.rollno,50);
    cout<<"Enter Name :\n";
    cin.getline(s.name,50);
    ofstream file("studentdata.bin",ios::app|ios::binary);
    if(!file.is_open())
    {
        cerr<<"error"<<endl;
        return ;
    }
    file.write((char *)&s,sizeof(s));
    cout<<"Student Added successfully"<<endl;
    file.close();
}
//Function for see all
void viewAll()
{
    ifstream read("studentdata.bin",ios::binary);
    if(!read.is_open())
    {
        cerr<<"error"<<endl;
        return;
    }
    student temp;
    bool used = 0;
    cout<<"Here is the details of students \n";
    cout<<"RollNo"<<" | "<<"Name"<<endl;
    while(read.read((char*)&temp,sizeof(temp)))
    {
        used = 1;
        cout<<temp.rollno<<" | "<<temp.name<<endl;
    }
    if(!used)
    {
        cout<<"-----NO DATA AVAILABLE-----"<<endl;
    }
    read.close();
}
//Function for view one student
void viewOne()
{
    viewAll();
    int n = lenofstudent();
    cout<<"Enter the index you want to see ("<<"1-"<<n<<")"<<endl;
    int val;
    cin>>val;
    if(val<=0||val>n) {
        cout<<"enter from 1"<<endl;
        return;
    }
    ifstream point("studentdata.bin",ios::binary);
    if(!point.is_open())
    {
        cerr<<"ERROR"<<endl;
        return;
    }
    student temp;
    point.seekg((val-1)*sizeof(temp),ios::beg);
    cout<<"THE STUDENT:"<<endl;
    if(point.read((char*)&temp,sizeof(temp)))
    {
        cout<<"RollNo: "<<temp.rollno<<" | "<<"Name: "<<temp.name<<endl;

    }
    else{
        cerr<<"we failed to read"<<endl;
    }
    
   
    point.close();
}
//Function for updating student
void updateStudent()
{
    viewAll();
    int n = lenofstudent();
    cout<<"Enter the index you want to update ("<<"1-"<<n<<")"<<endl;
    int val;
    cin>>val;
    if(val<=0||val>n) {
        cout<<"enter from 1"<<endl;
        return;
    } 
    fstream update("studentdata.bin",ios::binary|ios::in|ios::out);  
    if(!update.is_open())
    {
        cerr<<"error"<<endl;
        return;
    }
    student temp;
    update.seekp((val -1)*sizeof(temp),ios::beg);
    cout<<"Enter the details of student :"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Enter roll no :\n";
    cin.getline(temp.rollno,50);
    cout<<"Enter Name :\n";
    cin.getline(temp.name,50);
    if(update.write((char*)&temp,sizeof(temp)))
    {
        cout<<"Student Updated successfully"<<endl;
    }
    else{
        cerr<<"Error"<<endl;
        return;
    }
    update.close();
}
// Function for delete student
void deleteStudent()
{
    viewAll();
    int n = lenofstudent();
    cout<<"Enter the index you want to update ("<<"1-"<<n<<")"<<endl;
    int val;
    cin>>val;
    if(val<=0||val>n) {
        cout<<"enter from 1"<<endl;
        return;
    } 
    ifstream file("studentdata.bin",ios::binary);
    ofstream copy("copy.bin",ios::binary);
    if(!file || !copy)
    {
        cerr<<"error"<<endl;
        return;
    }
    student temp;
    int count = 1;
    while(file.read((char *)&temp,sizeof(temp)))
    {
        if(count!=val)
        {
            copy.write((char *)&temp,sizeof(temp));
        }
        count++;
    }
    file.close();
    copy.close();
    remove("studentdata.bin");
    rename("copy.bin","studentdata.bin");
    cout<<"Deleted succesfully"<<endl; 
}
int main() {
    int choice;

    do {
        cout << "\n1.Add\n2.View All\n3.View One\n4.Update\n5.Exit\n";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewAll(); break;
            case 3: viewOne(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
        }
    } while(choice != 6);
}