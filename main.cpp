#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<fstream>
#include<cstdlib>
using namespace std;
class Student{
    private:
    int Roll_no;
    string Name;
    int arr[5];
    int total=0;
    float percentage;
    char Grade;
    public:
        Student()
        {
            cout<<"ENTER STUDENT Roll No and Name\n";
            int temp;cin>>temp;
            Roll_no=temp;
            string name;cin>>name;
            this->Name=name;
            cout<<"Enter Marks in order(sub1,sub2,.....sub5) for 100 Total"<<endl;
            for(int i=0;i<5;i++)
            {
                cin>>arr[i];
                if(arr[i]<0){cout<<"NO Negetive marks should be allocated\nPlease Re-enter marks for sub"<<i+1<<endl;i--;continue;}
                total+=arr[i];
            }
            percentage=round((total/500.0)*100);
            if(percentage>=90){Grade='O';}
            else if(percentage>=80){Grade='A';}
            else if(percentage>=70){Grade='B';}
            else if(percentage>=60){Grade='C';}
            else if(percentage>=50){Grade='D';}
            else if(percentage>=40){Grade='E';}
            else{Grade='F';}
            cout<<"Student added Successfully"<<endl;
        }
        void show()
        {
            
            cout<<Roll_no<<"      "<<Name<<"         ";
            for(int i=0;i<5;i++)
            {
                cout<<arr[i]<<"  ";
            }
            cout<<total<<"  "<<percentage<<"  "<<Grade<<endl;
        }
        friend void updation(vector<Student>&arr,int find);
        friend void deletion(vector<Student>&arr,int find);
        friend void saving(vector<Student>&arr);
};
void updation(vector<Student>&arr,int find)
{
    int i;
    for( i=0;i<arr.size();i++)
    {
        if(find==arr[i].Roll_no){break;}
    }
    if(i==arr.size()){cout<<"This no Student with Roll no"<<find<<endl;return ;}
    else{
        cout<<"Re-Enter the details of the Student"<<endl;
        Student temp;
        arr[i]=temp;
    }
}
void deletion(vector<Student>&arr,int find)
{
    int i;
    for(i=0;i<arr.size();i++)
    {
        if(find==arr[i].Roll_no){break;}
    }
    if(i==arr.size()){cout<<"There is no such Student with Roll no"<<find<<endl;}
    else{
        arr.erase(arr.begin()+i);
        cout<<"The Student details with Roll no is deleted"<<endl;
    }
}
void saving(vector<Student>&arr)
{
    ofstream save_point;
    save_point.open("Record.CSV");
    save_point<<"Roll_no,Name,Subject_1,Subject_2,Subject_3,Subject_4,Subject_5,Total,Percentaile,Grade\n";
    for(int i=0;i<arr.size();i++)
    {
        save_point<<arr[i].Roll_no<<','<<arr[i].Name<<',';
        for(int j=0;j<5;j++)
        {
            save_point<<arr[i].arr[j]<<',';
        }
        save_point<<arr[i].total<<','<<arr[i].percentage<<','<<arr[i].Grade<<'\n';
    }
    
}

int main()
{
    vector<Student>log;
    while(1)
    {
        int choice;
        cout<<"1.Add Student Result\n2.Show Student Result\n3.Update Student details\n4.Delete Student Record\n5.Save data into CSV"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
             system("cls");
             log.emplace_back();
            break;
        
        case 2:
            system("cls");
            cout<<"ROLL NO        NAME          sub1   sub2  sub3  sub4  sub5 total percentage Grade"<<endl;
            for(int i=0;i<log.size();i++)
            {
                log[i].show();
            }
            break;
        case 3:
            system("cls");
            cout<<"Enter the Roll No to Update data";
            int find;cin>>find;
            updation(log,find);
            break;
        case 4:
          system("cls");
            cout<<"Enter the Roll no of student to delete";
            cin>>find;
            deletion(log,find);
            break;
        case 5:
            system("cls");
            saving(log);
            break;
        default:
            return 0;
        }
    }
}