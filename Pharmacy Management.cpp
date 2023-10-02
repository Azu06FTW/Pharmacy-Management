#include <bits/stdc++.h>
using namespace std;


class store{
protected:
    int drugid;
    float price;
    float dis;
    string sorv;
    string dname;
    string edate;

public:

    void menu();
};

class Admin : public store {
public:
    void admin();
    void add();
    void edit();
    void rem();
};

class Buyer : public store {
public:
    void buyer();
    void lst();
    void receipt();
};


void store::menu(){
    a:
    Admin a;
    Buyer c;
    int choice;
    string email;
    string pass;
    string text = "Pharmacy MENU";
    int length = text.length();//what does the above 40 codes mean?
    int totalWidth = 40;
    int spaces = (totalWidth - length) / 2;
    cout <<"\t\t\t\t"<<string(totalWidth, '*') << endl;
    cout <<"\t\t\t\t"<<string(spaces, ' ') << text << endl;
    cout <<"\t\t\t\t" <<string(totalWidth, '*') << endl;
    cout <<"\t\t\t\t 1) Admin\n";
    cout <<endl;
    cout <<"\t\t\t\t 2) Buyer\n";
    cout <<endl;
    cout <<"\t\t\t\t 3) Exit\n";
    cout <<endl;
    cout <<"\t\t\t\t Enter your choice : ";
    cin >> choice;
    cout << endl;
    switch(choice){
        case 1:
        cout <<"\t\t\t\t Please Login \n";
        cout << endl;
        cout <<"\t\t\t\t Enter your username : ";
        cin >> email;
        cout <<"\t\t\t\t Enter your password : ";
        cin >> pass;
        if (email=="Azfar101" && pass=="1234"){
            a.admin();
        }
        else{
            cout << "Incorrect username/password. Please try again\n";
        }
        break;

        case 2:
        c.buyer();
        break;

        case 3:
        exit(0);
        break;

        default:
        cout << "Invalid choice. Please try again\n";
    }
    goto a;
}

void Admin::admin(){
    a:
    int choice;
    cout <<"\n\n\n\t\t\t\t Admin Menu\n";
    cout << endl;
    cout <<"\t\t\t\t 1) Add drug\n";
    cout << endl;
    cout <<"\t\t\t\t 2) Modify drug\n";
    cout << endl;
    cout <<"\t\t\t\t 3) Delete drug\n";
    cout << endl;
    cout <<"\t\t\t\t 4) Back to main menu\n";
    cout << endl;

    cout <<"\t\t\t\t Enter choice: \n";
    cin >> choice;
    cout << endl;

    switch(choice){
        case 1:
        add();
        break;

        case 2:
        edit();
        break;

        case 3:
        rem();
        break;

        case 4:
        menu();
        break;

        default:
        cout << "Invalid choice. Please try again\n";
    }
    goto a;
}

void Buyer:: buyer(){
    a:
    int choice;
    cout <<"\n\n\n\t\t\t\t Buyer Menu\n";
    cout << endl;
    cout <<"\t\t\t\t 1) View drugs\n";
    cout << endl;
    cout <<"\t\t\t\t 2) Back to main menu\n";
    cout << endl;
    cout <<"\t\t\t\t Enter choice: \n";
    cin >> choice;
    cout << endl;
    switch(choice){
        case 1:
        receipt();
        break;

        case 2:
        menu();
        break;

        default:
        cout << "Invalid choice. Please try again\n";
    }
    goto a;
}

void Admin::add(){
    a:
    fstream data;
    int cnt = 0;
    int di;
    string dn;
    string dsv;
    string ded;
    float dprice;
    float ddis;

    cout << "\n\n\t\t\t Add new drug\n\n";
    cout << "\n\n\t\t\t Enter drug id: ";
    cin >> drugid;
    cout << "\n\n\t\t\t Enter drug name: ";
    cin >> dname;
    cout << "\n\n\t\t\t Enter drug strength/volume: ";
    cin >> sorv;
    cout << "\n\n\t\t\t Enter drug cost: ";
    cin >> price;
    cout << "\n\n\t\t\t Discount: ";
    cin >> dis;
    cout << "\n\n\t\t\t Enter drug expiry date: ";
    cin >> edate;

    data.open("drugs.txt",ios::in);
    if(!data){
        cout << "File not found. Creating new file\n";
        data.open("drugs.txt",ios::app|ios::out);
        data <<" "<<drugid<<" "<<dname<<" "<<sorv <<" "<<edate<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        while(data >> di >> dn >> dsv >> ded >> dprice >> ddis){
            if(di == drugid){
                cnt++;
            }
        }
        data.close();
        if (cnt>0){
            goto a;
        }
        else{
            data.open("drugs.txt",ios::app|ios::out);
            data <<" "<<drugid<<" "<<dname<<" "<<sorv <<" "<<edate<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
    }
    cout <<"\n\n\t\t Record Updated! ";
}

void Admin :: edit(){
    a:
    fstream data,tdata;
    int cnt = 0;
    int di,c;
    string dn;
    string dsv;
    string ded;
    float dprice;
    float ddis;

    cout <<"\n\t\t\t Modify the record";
    cout <<"\n\t\t\t Drug id: ";
    cin >> di;

    data.open("drugs.txt",ios::in);
    if (!data){
        cout << "File not found.\n";
    }
    else{
        tdata.open("tdrugs.txt",ios::app|ios::out);
        while(data >> drugid >> dname >> sorv >> edate >> price >> dis){
            if(di == drugid){
                cout << "\n\t\t Drug new code :";
                cin >> c;
                cout <<"\n\t\t Drug name: ";
                cin >> dn;
                cout <<"\n\t\t Drug strength or volume: ";
                cin >> dsv;
                cout <<"\n\t\t Drug expiry date: ";
                cin >> ded;
                cout <<"\n\t\t Price: ";
                cin >> dprice;
                cout <<"\n\t\t Discount: ";
                cin >> ddis;
                tdata <<" " <<c<<" "<<dn<<" "<<dsv<<" "<<ded<<" "<<dprice<<" "<<ddis<<"\n";
                cout <<"\n\t\t Record edited!";
                cnt++;
            }
            else{
                tdata <<" "<<drugid<<" "<<dname<<" "<<sorv <<" "<<edate<<" "<<price<<" "<<dis<<"\n";
            }
        }
        data.close();
        tdata.close();

        remove("drugs.txt");
        rename("tdrugs.txt","drugs.txt");

        if (cnt==0){
            cout <<"\n\t\t Record not found! Try Another Drug id";
            goto a;
        }

    }
}

void Admin::rem(){
    a:
     fstream data,tdata;
     int di;
     int cnt = 0;
     cout <<"\n\t\t Delete Drug";
     cout <<"\n\t\t Drug id: ";
     cin >> di;
     data.open("drugs.txt",ios::in);
     if (!data){
        cout << "File not found.\n";
     }
     else{
        tdata.open("tdrugs.txt",ios::app|ios::out);
        while(data >> drugid >> dname >> sorv >> edate >> price >> dis){
            if(di == drugid){
                cout <<"\n\t\t Drug deleted successfully";
                cnt++;
            }
            else{
                tdata <<" "<<drugid<<" "<<dname<<" "<<sorv <<" "<<edate<<" "<<price<<" "<<dis<<"\n";
            }
        }
        data.close();
        tdata.close();

        remove("drugs.txt");
        rename("tdrugs.txt","drugs.txt");

        if (cnt==0){
            cout <<"\n\t\t Record not found! Try Another Drug id";
            goto a;
        }
     }
}

void Buyer::lst(){
    fstream data;
    data.open("drugs.txt",ios::in);
    cout <<string(120, '-') << endl;
    cout <<"\tDrug_ID\t\tDrug_Name\t\tDrug_Strength/volume\t\tExpiry Date\t\tPrice\n";
    cout <<string(120, '-') << endl;
    while(data>>drugid>>dname>>sorv>>edate>>price>>dis){
        cout <<"\t"<<drugid<<"\t\t"<<dname<<"\t\t\t"<<sorv<<"\t\t\t\t"<<edate<<"\t\t\t"<<price<<endl;
    }
    data.close();
}

void Buyer::receipt(){
    fstream data;
    vector <int> c;
    vector <int> q;
    char choice;
    int chce;
    int cnt = 0;
    float amount=0;
    float tdis=0;
    float total = 0;
    data.open("drugs.txt",ios::in);
    if (!data){
        cout << "\n\n\t\tNO data yet"<<endl;
    }
    else{
        data.close();
        lst();//Reads all the medicine name from file and shows it to the console
        cout <<"\t\t\t\t"<<string(40, '-') << endl;
        cout << endl;
        cout <<"\t\t\t\t"<<string(12, ' ') << "1) Place The Order" << endl;
        cout << endl;
        cout <<"\t\t\t\t"<<string(12, ' ') << "2) Cancel" << endl;
        cout <<"\t\t\t\t"<<string(40, '-') << endl;
        cout <<"\t\t\t\t"<<string(12, ' ') << "Enter choice: " << endl;
        cin >> chce;

        switch(chce)
        {
        case 1:
            do{
            a:
            cout <<"\n\t\t Enter Drug id: ";
            int x;cin >> x;
            c.push_back(x);
            cout <<"\n\t\t Enter Drug quantity: ";
            int y;cin >> y;
            q.push_back(y);
            for (int i=0;i<c.size()-1;i++){
                if (c[i]==c[c.size()-1]){
                    cout <<"\n\t\t Drug id already exists"<<endl;
                    goto a;
                }
            }
                cout <<"\n\n Do you need anything else? If yes then press y else n\n";
                cin >> choice;
            }while(choice=='y');
            break;
        case 2:
            menu();
            break;
        }

        string text = "RECEIPT";
        int length = text.length();
        int totalWidth = 120;
        int spaces = (totalWidth - length) / 2;
        cout << endl;
        cout <<string(totalWidth, '^') << endl;
        cout <<string(spaces, ' ') << text << endl;
        cout <<string(totalWidth, '~') << endl;

        cout <<"\n\tDrug_ID\t\tDrug_Name\tDrug_Strength/volume\tQuantity\tTotal_Price\tPrice_after_discount\n";

        for (int i=0;i<c.size();i++){
            data.open("drugs.txt",ios::in);
            while(data>>drugid>>dname>>sorv>>edate>>price>>dis){
                if (c[i]==drugid){
                    amount = price*q[i];
                    tdis = amount - (amount*dis/100);
                    total += tdis;
                    cout <<"\n\t"<<drugid <<"\t\t"<<dname<<"\t\t"<<sorv<<"\t\t\t"<<q[i]<<"\t\t"<<amount<<"\t\t"<<tdis<<endl;
                }
            }
            data.close();
        }
    }
    cout << endl;
    cout <<string(120, '-') << endl;
    cout <<"\n\t\t\t\t\t\t\t\t\t\t Total Amount: " << total;
}

int main() {
    store s;
    s.menu();
    return 0;
}
