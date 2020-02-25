#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int givenlength,j=0;
    cout<<"\nEnter the Length of the URL : "<<endl;
    cin>>givenlength;
    string st1;
    char url[givenlength];
    cout<<"\nEnter the URL : ";
    getline(cin,st1);
    
    for(int i=0;i<givenlength;i++){
        if(st1[i]!=' '){
            url[j++]=st1[i];
        }else{
            url[j++]='%';
            url[j++]='2';
            url[j++]='0';
        }
    }
    cout<<"Modified URL : "<<url<<endl;
    return 0;
}