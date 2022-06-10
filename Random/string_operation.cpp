#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
    string s,s1;
/******** How to accept a string ********/
    //Method 1: Use Cin but string must not have any space!!
   /* cin>>s;
    cout<<s<<endl;*/

    //Method 2: *****Use getline() . No problem even if string has any space in between!!*****
    // getline(cin,s1);
    // cout<<s1<<endl;

/********String concatination********/
    string s2,s3;
    s2="Fam",s3="ily";
    // cout<<s2+s3<<endl;// s2+s3=s2.append(s3)

/********Accessing String Character********/
    string s4=s2.append(s3);
    // cout<<s4<<endl;
    // cout<<s4[1]<<s4[3]<<endl;  // Since string is basically character array 
                                  //we can access the string elements using square brackets

/********Comparison between two string***/
    // if (s2.compare(s3)==1){
    //     cout<<"Equal";
    // }

    // else cout<<"Not Equal";

/******Insert another String******/
    // s4.insert(2,"Lol");
    // cout<<s4;

/************String To Integer***************/
    // string s5="1989";
    // int my_num=stoi(s5);
    // cout<<my_num;

/************Integer to string***************/
    // int num=91;
    // string s6=to_string(num);
    // cout<<s6<<endl;
    // cout<<s6+"Akash";

/*********Sorting a string***************/
    // string s7="QWERTYUI";
    // sort(s7.begin(),s7.end());
    // cout<<s7;

// Other operations on string: s.empty(), s.erase(), s.clear()


    return 0;
}