#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check_2 (int tmp){
    int check;
    while(tmp >1){
        check = tmp%10;
        if (check==2){
            return 1;
        }
        tmp= (tmp-check)/10;
    }
    return 0;
}

int check_4(int tmp){
    if(tmp%4 == 0){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    string line;
    int size;
    while(getline(cin,line)){
        size = stoi(line);
        for(int tmp= size; tmp > 0; tmp--){
            if(check_2(tmp)&&check_4(tmp)){
                cout <<"OUTTHINK";
            }else if(check_2(tmp)){
                cout << "OUT";
            }else if(check_4(tmp)){
                cout << "THINK";
            }else{
                cout << tmp;
            }
            if(tmp != 1){
                cout << ",";    
            }
        }
        cout << endl;
    }
   return 0;
}
