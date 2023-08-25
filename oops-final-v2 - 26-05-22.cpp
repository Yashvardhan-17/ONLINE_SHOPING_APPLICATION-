#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//implementation of factory method
enum producttype {casual,formal,sports };
//base class products

class products
{
public:
    int p_id,rating,price;
    string p_name;
    float size_d;
    string gender;
    producttype type;
    static products* create(producttype type);
    virtual void set_product(int i,int r,int p,string n,int s,string g)=0;
    virtual void sort_product(products *p[],int s)=0;
    virtual void print_product()=0;

};


//payment class~
class Payment
{
public:

    bool status;
    Payment() {}
    void details_buyed(products *p[],int s,int total_price)
    {
        status=false;
        for(int i=0; i<s; i++)
        {
            cout<<"product name   "<<p[i]->p_name<<endl;
            cout<<"product id     "<<p[i]->p_id<<endl;
            cout<<"product size   "<<p[i]->size_d<<endl;
            cout<<"product rating "<<p[i]->rating<<endl;
            cout<<"Total price of the products"<<total_price<<endl;
        }
        cout<<"All items are purchased successfully"<<endl;
    }
};


//shopping cart class~
class shopping_cart
{
public:
    int choice;
    Payment pay;
    int total_price=0;
    static int counter;
    products *p[100];
    void add_item(products *prod)
    {
        p[counter] = prod;
        counter++;
    }

    void get_total()
    {
        for(int i=0; i<counter; i++)
        {
            total_price=total_price+p[i]->price;
        }
        cout<<total_price<<endl;
    }

    void purchase()
    {
        cout<<"Purchasing all items"<<endl;
        cout<<"To make payment press 1"<<endl;
        cin>>choice;
        if(choice==1)
        {
            pay.details_buyed(p,counter,total_price);
        }
    }

};
int shopping_cart::counter=0;

//customer class ~
class Customer
{
public:
    int customerId;
    string custName;
    string address;
    long phoneNumber;
    string gender;
    Customer() {}
    void setProfile(int i,string n,string a,string g,int p)
    {
        gender = g;
        address = a;
        custName = n;
        customerId = i;
        phoneNumber = p;
    }
    //getProfile- implementing it as display function
    void getProfile()
    {
        cout<<customerId<<" -- "<<custName<<endl;
        cout<<gender<<endl;
        cout<<address<<" -- "<<phoneNumber<<endl;
    }

    void updateProfile()
    {
        int choice;
        cout<<"Edit your profile"<<endl;
        cout<<"1- To edit name"<<endl;
        cout<<"2- To edit gender"<<endl;
        cout<<"3- To edit address"<<endl;
        cout<<"4- To edit Ph.Number"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter new name"<<endl;
            cin>>custName;
            cout<<"Changes Saved"<<endl;
            break;
        case 2:
            cout<<"Enter new gender"<<endl;
            cin>>gender;
            cout<<"Changes Saved"<<endl;
            break;
        case 3:
            cout<<"Enter new address"<<endl;
            cin>>address;
            cout<<"Changes Saved"<<endl;
            break;
        case 4:
            cout<<"Enter new Ph.Number"<<endl;
            cin>>phoneNumber;
            cout<<"Changes Saved"<<endl;
            break;
        default:
            cout<<"Wrong choice"<<endl;
            break;
        }
    }

    void update_cart(products* p[],int no)
    {
        shopping_cart sc;
        int ch;
        cout<<"To add the product"<<endl;
        for(int i=0; i<no; i++)
        {
            cout<<"product name"<<p[i]->p_name<<endl;
            cout<<"product id"<<p[i]->p_id<<endl;
            cout<<"product size"<<p[i]->size_d<<endl;
            cout<<"product rating"<<p[i]->rating<<endl;
            cout<<"To add product to cart press 1"<<endl;
            cin>>ch;
            if(ch==1)
            {
                sc.add_item(p[i]);
            }
        }
    }
};

//online_shopping class ~
class online_shopping
{
public:
    string app_name;
    Customer c[100];
    static int counter;
    online_shopping(string app_name) {
        this->app_name=app_name;
    }

    void add_customers(Customer &c1)
    {
        c[counter]=c1;
        counter++;
    }

    void display_list_of_customers()
    {
        cout<<endl;
        cout<<"List Of All Customers"<<endl;
        for(int i=0; i<counter; i++)
        {
            c[i].getProfile();
        }
    }
};
int online_shopping::counter=0;

//inherited classes
class casual_product:public products
{
public:
    products *temp;
    void set_product(int i,int r,int p,string n,int s,string g)
    {
        p_id=i; rating=r; price=p;
        p_name=n; size_d=s; gender=g;
        type=casual;
    }

    void sort_product(products *p[],int s)
    {
        int choice;
        cout<<"To sort based on size press 1 \n to based on rating 2"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"sorting based on size"<<endl;
            int i, j;
            for (i = 0; i < s - 1; i++)
            {
                for (j = 0; j < s - i - 1; j++)
                {
                    if (p[j]->size_d> p[j + 1]->size_d)
                    {
                        temp= p[j];
                        p[i]=p[j+1];
                        p[j+1]=temp;

                    }
                }
            }
            int c;
            cout<<"enter 1 to display"<<endl;
            cin>>c;
            if(c==1)
            {
                for(int i=0; i<s; i++)
                {
                    cout<<"product name"<<p[i]->p_name<<endl;
                    cout<<"product id"<<p[i]->p_id<<endl;
                    cout<<"product size"<<p[i]->size_d<<endl;
                    cout<<"product rating"<<p[i]->rating<<endl;
                    cout<<endl;
                }
            }
            break;
        case 2:
            cout<<"sorting based on rating"<<endl;
            for (i = 0; i < s -1; i++)
            {
                for (j = 0; j < s - i - 1; j++)
                {
                    if (p[j]->rating > p[j + 1]->rating)
                    {
                        temp=p[j];
                        p[i]=p[j+1];
                        p[j+1]=temp;

                    }
                }
            }
            int ch;
            cout<<"enter 1 to display"<<endl;
            cin>>ch;
            if(ch==1)
            {
                for(int i=0; i<s; i++)
                {
                    cout<<"product name"<<p[i]->p_name<<endl;
                    cout<<"product id"<<p[i]->p_id<<endl;
                    cout<<"product size"<<p[i]->size_d<<endl;
                    cout<<"product rating"<<p[i]->rating<<endl;
                    cout<<endl;
                }
            }
            break;
        }
    }

    void print_product()
    {
        cout<<"product name   "<<p_name<<endl;
        cout<<"product id     "<<p_id<<endl;
        cout<<"product size   "<<size_d<<endl;
        cout<<"product rating "<<rating<<endl;
    }
};

class formal_product:public products
{
public:
    products *temp;

    void set_product(int i,int r,int p,string n,int s,string g)
    {
        p_id=i; rating=r; price=p;
        p_name=n; size_d=s; gender=g;
        type=formal;
    }

    void sort_product(products *p[],int s)
    {
        int choice;
        cout<<"To sort based on size press 1 \n to based on rating 2"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"sorting based on size"<<endl;
            int i, j;
            for (i = 0; i < s -1; i++)
            {
                for (j = 0; j < s - i - 1; j++)
                {
                    if (p[j]->size_d > p[j + 1]->size_d)
                    {
                        temp=p[j];
                        p[i]=p[j+1];
                        p[j+1]=temp;

                    }
                }
            }
            int c;
            cout<<"enter 1 to display"<<endl;
            cin>>c;
            if(c==1)
            {
                for(int i=0; i<s-1; i++)
                {
                    cout<<"product name"<<p[i]->p_name<<endl;
                    cout<<"product id"<<p[i]->p_id<<endl;
                    cout<<"product size"<<p[i]->size_d<<endl;
                    cout<<"product rating"<<p[i]->rating<<endl;
                    cout << endl;
                }
            }
            break;
        case 2:
            cout<<"sorting based on rating"<<endl;
            for (i = 0; i < s; i++)
            {
                for (j = 0; j < s - i - 1; j++)
                {
                    if (p[j]->rating > p[j + 1]->rating)
                    {
                        temp=p[j];
                        p[i]=p[j+1];
                        p[j+1]=temp;

                    }
                }
            }
            int ch;
            cout<<"enter 1 to display"<<endl;
            cin>>ch;
            if(ch==1)
            {
                for(int i=0; i<s; i++)
                {
                    cout<<"product name"<<p[i]->p_name<<endl;
                    cout<<"product id"<<p[i]->p_id<<endl;
                    cout<<"product size"<<p[i]->size_d<<endl;
                    cout<<"product rating"<<p[i]->rating<<endl;
                    cout << endl;
                }
            }
            break;
        }
    }

    void print_product()
    {
        cout<<"product name   "<<p_name<<endl;
        cout<<"product id     "<<p_id<<endl;
        cout<<"product size   "<<size_d<<endl;
        cout<<"product rating "<<rating<<endl;
    }
};


class sports_product:public products
{
public:
    products *temp;
    void set_product(int i,int r,int p,string n,int s,string g)
    {
        p_id=i; rating=r; price=p;
        p_name=n; size_d=s; gender=g;
        type=sports;
    }

    void sort_product(products *p[],int s)
    {
        int choice;
        cout<<"To sort based on size press 1 \n to based on rating 2"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"sorting based on size"<<endl;
            int i, j;
            for (i = 0; i < s - 1 ; i++)
            {
                for (j = 0; j < s - i - 1 ; j++)
                {
                    if (p[j]->size_d > p[j + 1]->size_d)
                    {
                        temp=p[j];
                        p[j]=p[j+1];
                        p[j+1]=temp;

                    }
                }
            }
            int c;
            cout<<"enter 1 to display"<<endl;
            cin>>c;
            if(c==1)
            {
                for(int i=0; i<s; i++)
                {
                    cout<<"product name   "<<p[i]->p_name<<endl;
                    cout<<"product id     "<<p[i]->p_id<<endl;
                    cout<<"product size   "<<p[i]->size_d<<endl;
                    cout<<"product rating "<<p[i]->rating<<endl;
                    cout << endl;
                }
            }
            break;
        case 2:
            cout<<"sorting based on rating"<<endl;
            for (i = 0; i < s - 1; i++)
            {
                for (j = 0; j < s - i - 1; j++)
                {
                    if (p[j]->rating > p[j + 1]->rating)
                    {
                        temp=p[j];
                        p[i]=p[j+1];
                        p[j+1]=temp;

                    }
                }
            }
            int ch;
            cout<<"Enter 1 to display"<<endl;
            cin>>ch;
            if(ch==1)
            {
                for(int i=0; i<s; i++)
                {
                    cout<<"product name   "<<p[i]->p_name<<endl;
                    cout<<"product id     "<<p[i]->p_id<<endl;
                    cout<<"product size   "<<p[i]->size_d<<endl;
                    cout<<"product rating "<<p[i]->rating<<endl;
                    cout<<endl;
                }
            }
            break;
        default:
            cout<<"Invalid Input"<<endl;
            break;
        }

    }

    void print_product()
    {
        cout<<"product name   "<<p_name<<endl;
        cout<<"product id     "<<p_id<<endl;
        cout<<"product size   "<<size_d<<endl;
        cout<<"product rating "<<rating<<endl;
    }
};

products* products::create(producttype type)
{
    if(type==casual)
    {
        return new casual_product();
    }
    else if(type==formal)
    {
        return new formal_product();
    }
    else if(type==sports)
    {
        return new sports_product();
    }
    else return NULL;
}


//factory class
class product_list
{
public:
    products *ptypes;
    product_list()
    {
        int choice;
        producttype type;
        cout<<"To create \n formal press 1 \n casual press 2 \n sports press 3"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            type=formal;
            ptypes=products::create(type);
            break;

        case 2:
            type=casual;
            ptypes=products::create(type);
            break;

        case 3:
            type=sports;
            ptypes=products::create(type);
            break;

        default:
            cout<<"Invalid operator"<<endl;
            break;

        }
    }
    products* getproduct()
    {
        return ptypes;
    }

};


int main()
{
    //product 1 created
    product_list *plist1=new product_list();
    products *p1=plist1->getproduct();
    p1->set_product(101,5,2100,"blue jeans",32,"unisex");
    //product 2 created
    product_list *plist2=new product_list();
    products *p2=plist2->getproduct();
    p2->set_product(102,4,3200,"brown shirt",22,"male");
    //product 3 created
    product_list *plist3=new product_list();
    products *p3=plist3->getproduct();
    p3->set_product(103,5,1800,"t-shirt 777",22,"male");
    //product 4 created
    product_list *plist4=new product_list();
    products *p4=plist4->getproduct();
    p4->set_product(104,4,4500,"running boxer",33,"male");
    //product 5 created
    product_list *plist5=new product_list();
    products *p5=plist2->getproduct();
    p5->set_product(105,5,1200,"back tank top",24,"male");
    //product 6 created
    product_list *plist6=new product_list();
    products *p6=plist6->getproduct();
    p6->set_product(106,4,3800,"sweat shirt",24,"female");
    //product 7 created
    product_list *plist7=new product_list();
    products *p7=plist7->getproduct();
    p7->set_product(107,4,7700,"black jacket",31,"male");
    //product 8 created
    product_list *plist8=new product_list();
    products *p8=plist8->getproduct();
    p8->set_product(108,4,3200,"full sleves",28,"unisex");
    //product 9 created
    product_list *plist9=new product_list();
    products *p9=plist9->getproduct();
    p9->set_product(109,3,4900,"black shoes",11,"female");
    //product 10 created
    product_list *plist10=new product_list();
    products *p10=plist10->getproduct();
    p10->set_product(110,5,9900,"air jordan",11,"female");
    products* p[10] = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10};

    //printing all the products
    for(int i=0;i<10;i++) {
        p[i]->print_product();
    }
    ///sorting all the products
    p1->sort_product(p,10);

    //implementation of customers
    Customer c1;
    c1.setProfile(1001,"Kushagra","bvb-college, hubli","male",888888888);
    Customer c2;
    c2.setProfile(1002,"Depshree","sdm-college, hubli","female",999999999);
    c1.getProfile();
    c2.getProfile();
    c1.update_cart(p,10);
    c1.updateProfile();
    //

    //implementation of online shopping
    online_shopping os1("Meesho");
    os1.add_customers(c1);
    os1.add_customers(c2);
    os1.display_list_of_customers();
    //

    //implementation of shopping cart
    shopping_cart s1;
    s1.add_item(p1);
    s1.get_total();
    s1.purchase();
    //
}


