#include <iostream>


using namespace std;

class Phone
{
private :
    string Type, Desc,PhoneNum;
public :
    Phone()
    {
        Type = "None" ;
        Desc = "None" ;
        PhoneNum = "None" ;
    }
    void SetType(string T)
    {
        Type = T ;
    }
    void SetPhoneNum(string num)
    {
        PhoneNum = num ;
    }
    void SetDesc(string Des)
    {
        Desc = Des ;
    }
    string GetType()
    {
        return Type;
    }
    string GetDesc()
    {
        return Desc;
    }
    string GetPhoneNum()
    {
        return PhoneNum;
    }
    void Display()
    {
        cout << "Phone Number : " << PhoneNum << endl ;
        cout << "Type : " << Type << endl ;
        cout << "Description : " << Desc << endl ;
    }
};
class Emails
{
private :
    string Type, Desc, Email;
public :
    Emails()
    {
        Type = "None" ;
        Desc = "None" ;
        Email = "None" ;
    }
    void SetType(string T)
    {
        Type = T ;
    }
    void SetEmail(string M)
    {
        Email = M ;
    }
    void SetDesc(string Des)
    {
        Desc = Des ;
    }
    string GetType()
    {
        return Type;
    }
    string GetDesc()
    {
        return Desc;
    }
    string GetEmail()
    {
        return Email;
    }
    void Display()
    {
        cout << "Email : " << Email << endl ;
        cout << "Type : " << Type << endl ;
        cout << "Description : " << Desc << endl ;
    }
};
class Addresses
{
private :
    string Type, Desc, Add;
public :
    Addresses()
    {
        Type = "None" ;
        Desc = "None" ;
        Add = "None" ;
    }
    void SetType(string T)
    {
        Type = T ;
    }
    void SetAddresses(string A)
    {
        Add = A ;
    }
    void SetDesc(string Des)
    {
        Desc = Des ;
    }
    string GetType()
    {
        return Type;
    }
    string GetDesc()
    {
        return Desc;
    }
    string GetAdd()
    {
        return Add;
    }
    void Display()
    {
        cout << "Addresses : " << Add << endl ;
        cout << "Type : " << Type << endl ;
        cout << "Description : " << Desc << endl ;
    }
};
class User
{
private :
    string ID ;
    string Name ;
    Phone *P;
    Emails *M;
    Addresses *A;
    int SzP,SzM,SzA;
public :
    User()
    {
        SzP = SzM = SzA =0 ;
        P = nullptr ;
        M = nullptr ;
        A = nullptr ;
    }
    User(int Szp,int Szm,int Sza)
    {
        SzP = Szp;
        SzM = Szm;
        SzA = Sza;


        P = new Phone[SzP];
        M = new Emails[SzM];
        A = new Addresses[SzA];
    }
    void SetBasicData(string Id,string N)
    {
        ID = Id ;
        Name = N ;
    }
    void SetPhoneData(int index,string p,string T,string D)
    {
        if(index>=0 && index<SzP)
        {
            P[index].SetPhoneNum(p);
            P[index].SetType(T);
            P[index].SetDesc(D);
        }
    }
    void SetEmailData(int index,string m,string T,string D)
    {
        if(index>=0 && index<SzM)
        {
            M[index].SetEmail(m);
            M[index].SetType(T);
            M[index].SetDesc(D);
        }
    }
    void SetAddressesData(int index,string a,string T,string D)
    {
        if(index>=0 && index<SzA)
        {
            A[index].SetAddresses(a);
            A[index].SetType(T);
            A[index].SetDesc(D);
        }
    }
    Phone* GetPhoneData()
    {
        return P ;
    }
    Emails* GetEmailData()
    {
        return M ;
    }
    Addresses* GetAddressesData()
    {
        return A ;
    }
    void DisplayUser()
    {
        cout << "=======================\n" ;
        cout << "Name : " << Name << endl ;
        cout << "ID : " << ID << endl ;
        cout << "\n--- Phone Numbers Data ---\n" << endl ;
        for (int i=0; i<SzP; i++)
        {
            P[i].Display();
            cout << "=================\n" ;
        }
        cout << "\n--- Emails Data ---\n" << endl ;
        for (int i=0; i<SzM; i++)
        {
            M[i].Display();
            cout << "=================\n" ;
        }
        cout << "\n--- Addresses Data ---\n" << endl ;
        for (int i=0; i<SzA; i++)
        {
            A[i].Display();
            cout << "=================\n" ;
        }
    }
    ~User()
    {
        delete[] P;
        delete[] M;
        delete[] A;
    }
};
class Contact
{
private :
    User** Users;    /**/
    int Size;
public :
    Contact(int s)
    {
        Size = s;
        Users = new User*[Size] ;     /**/
    }
    void SetUsers(int index, User* u)      /**/
    {
        if(index>=0 && index<Size)
        {
            Users[index] = u ;
        }
    }
    void Display()
    {
        for (int i=0; i<Size; i++)
        {
            cout << "\nUser " << i+1 << endl ;
            Users[i]->DisplayUser();  /**/
        }
    }
    ~Contact()
    {
        for(int i=0; i<Size; i++)
        {
            delete Users[i];
        }
        delete[] Users ;
    }
};
int main()
{
    int n,indx=1,SizeP,SizeM,SizeA;
    string iD,Nam,num,PhType,PhDescription,mail,MType,MDescription,add,AType,ADescription;
    cout << "Enter Number Of Contact You Want To Have : " ;
    cin >> n ;
    Contact C1(n) ;
    for(int i=0; i<n; i++)
    {
        cout << "\nEnter The How Many Phone Number The User " << indx << " Have : ";
        cin >> SizeP;
        cout << "\nEnter The How Many Email The User " << indx << " Have : ";
        cin >> SizeM;
        cout << "\nEnter The How Many Addresses The User " << indx << "  Have : ";
        cin >> SizeA;
        cout << "\n==================================\n\n";
        cout << "Enter The ID -> " ;
        cin >> iD ;
        cout << "Enter The Name -> " ;
        cin >> Nam ;
        cout << "\n==================================\n\n";
        User* u=new User(SizeP,SizeM,SizeA);
        for(int i=0; i<SizeP; i++)
        {
            cout << "Enter The Phone Number -> " ;
            cin >> num ;
            cout << "Enter The Type Of The Phone Number -> " ;
            cin >> PhType ;
            cout << "Enter The Phone Description -> ";
            cin >> PhDescription ;
            u->SetPhoneData(i,num,PhType,PhDescription);
        }
        cout << "\n==================================";
        for(int i=0; i<SizeM; i++)
        {
            cout << "\nEnter The Email -> " ;
            cin >> mail ;
            cout << "Enter The Type Of The Email -> " ;
            cin >> MType ;
            cout << "Enter The Email Description -> ";
            cin >> MDescription ;
            u->SetEmailData(i,mail,MType,MDescription);
        }
        cout << "\n==================================";
        for(int i=0; i<SizeA; i++)
        {
            cout << "\nEnter The Addresses -> " ;
            cin >> add ;
            cout << "Enter The Type Of The Addresses -> " ;
            cin >> AType ;
            cout << "Enter The Addresses Description -> ";
            cin >> ADescription ;
            u->SetAddressesData(i,add,AType,ADescription);
        }
        cout << "\n==================================";
        u->SetBasicData(iD,Nam);
        C1.SetUsers(i,u);
        indx++;
    }
    C1.Display();

    return 0;
}
