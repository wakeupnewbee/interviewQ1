#include <iostream>
#include <string>
#include <vector>

using namespace std;

class daily_file{
    public:
    //2016-08-06, avrage, total types
    string date;
    
    int total;
    double average;
    
    vector<string> products;
    int num_pro;
    
    daily_file(){}
    //public:
    void set(int _total, string _name);
    
    void set_date(string _date){date = _date; return;}
    
    
    void update_avg(){
        average = total / num_pro;
        return;
    }
    
    void check_total(int income){
        total = total + income;
        update_avg();
        return;
    }
    
    
    int check_products(string name){
        for(int tmp = 0; tmp < num_pro; tmp ++){
            if(products[tmp] == name){
                cout << "111"<<endl;
                return num_pro;
            }
        }
        products.push_back(name);
        num_pro ++;
        return num_pro;
    }
    
    void update_num(string name){
        num_pro = check_products(name);
        return;
    }
    
    void print_file();
    
    void test_print(){cout << total << "," << products[0] << endl;}
    
};

 void daily_file::set(int _total, string _name){ 
    products.push_back(_name);
    num_pro = 1;
    total= _total;
    average = total;
    return;
    
 }

void daily_file::print_file(){
    cout << date << "," << average << "," << num_pro << endl;
    return;
}

int check_exist(string name, daily_file *hash){
    for(int dum = 0; dum <10; dum ++){
        if(hash[dum].date == name){
            cout << "returned" << endl;
            return dum;
        }
    }
    cout << "not returned" << endl;
    return 0;
}

int main () {
    
    string _date;
    string _total;
    string _name;
    /* how to iniliatize the hash
    daily_file *hash;
    for(int dum = 0; dum < 30; dum ++){
        (hash+dum) = new daily_file;
    }
    */
    
    daily_file hash[10];
    int check;
    int index = 0;
    int total;
    
    while(getline(cin,_date,',')){
        check=check_exist(_date,hash);
        getline(cin,_total,',');
        total = stoi(_total);
        getline(cin,_name,'\n');
        _name.erase(_name.size() - 1);
        if(check==0){
            hash[index].set(total,_name);
            //hash[index].test_print();
            hash[index].set_date(_date);
            index++;
        }else{
            hash[check].check_products(_name);
            hash[check].check_total(total);
        }
    }
    for(int tmp = 0; tmp <index; tmp ++){
        hash[tmp].print_file();
    }
    
    /*
    */
    
    return 0;
}
