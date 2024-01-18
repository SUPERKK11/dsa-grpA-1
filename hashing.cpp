#include<iostream>
using namespace std ;
class person{
public:
long long int phonenumber;
string name;
};
person hashtable[10];
class linearprobing{

public:

void insert(long long int phonenumber,string name){

    int hash_index=phonenumber%10;
    while(hashtable[hash_index].phonenumber!=0){
    hash_index=(hash_index+1)%10;
    cout<<"probing is done"<<endl;
    }
    hashtable[hash_index].phonenumber=phonenumber;
    hashtable[hash_index].name=name;
}
void search(long long int phonenumber){
     int hash_index=phonenumber%10;
     while(hashtable[hash_index].phonenumber!=phonenumber){
        hash_index=(hash_index+1)%10;  
        }  
        
     cout<<hashtable[hash_index].name<<"at index"<<hash_index<<endl;
}
void deletee(long long int phonenumber){
     int hash_index=phonenumber%10;
     while(hashtable[hash_index].phonenumber!=phonenumber){
        hash_index=(hash_index+1)%10;  
        } 
    cout<<hashtable[hash_index].name<<" is deleted from the hash table "<<endl;
    hashtable[hash_index].phonenumber=0;
    hashtable[hash_index].name="";
   
}

void modify(long long int phonenumber,long long int newphonenumber){
    int hash_index=phonenumber%10;
     while(hashtable[hash_index].phonenumber!=phonenumber){
        hash_index=(hash_index+1)%10;  
        } 
    hashtable[hash_index].phonenumber=newphonenumber;
   
}
void display(){
    cout<<"_____________________------Display--------_____________________"<<endl;
    for(int i=0;i<10;i++){
      cout<<hashtable[i].name<<"--phonenumber->"<<hashtable[i].phonenumber<<endl;
    }
}
};
int main(){
    linearprobing lp;
    lp.insert(12,"kashyap");
    
    lp.display();
    return 0;
}