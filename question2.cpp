#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int checking(string list, string check, int index, int size){
    for(int tmp=0; tmp<size; tmp++){
        if(!(check[tmp]==list[tmp])){
            return 0;
        }    
    }
    return 1;
}

int main()
{
    string line;
    string check;
    vector <string> list;
    int pivot = 0;
    /*
    while(getline(cin,line)){
        stringstream c(line);  //trick part!!!!!!!!!!!!!!!!!!!!!!!
        if(!(c>>checker)){     ////trick part!!!!!!!!!!!!!!!!!!!!!!!
            cout << "got break"<<endl;
        }
        list.push_back(line);
        cout << list[i]<<endl;
        i++;
    }
    */
    
    while(getline(cin,line)){
        stringstream c(line);
        if(pivot){
            check = line;
            break;
        }
        if(!(c>>check)){
            list.push_back(" ");
            pivot++;
            //cout << "Get the empty line" << endl;
        }else{
            list.push_back(line);    
        }
    }
    
    int index = 0;
    int size = check.length();
    //cout << check << endl;
    //cout << size << endl;
    
    int record_index=-1;
    
    while(list[index]!=" "){
        if(checking(list[index],check,index,size)){
            record_index = index;
        }
        index++;
    }
    
    //cout << index << endl;
    
    if(record_index == -1){
        cout << "NONE";
    }else if(record_index <= (index-1)){
        cout << list[record_index] << endl;
        cout << list[record_index+1];
    }else{
        list[record_index];
    }
    
   return 0;
}
