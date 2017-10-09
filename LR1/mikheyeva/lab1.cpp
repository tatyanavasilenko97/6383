#include<iostream>
using namespace std;
//вещественное_число::= Целое_число . целое_без_знака | Целое_число . целое_без_знакаЕцелое число | Целое_числоЕцелое_число
//Целое_без_знака::=цифра | цифра целое_без_знака
//целое_число::=целое_без_знака | + целое_без_знака | - целое_без_знака
enum fail_type
{

    good,
    u_int_expeced,
    s_int_expeced,
    exp_or_point_expected

};

bool digit(istream &in){
    return isdigit(in.peek());
}


void read_digit(istream &in){
    if(!digit(in))return;
    cout<<((char)in.get());
    read_digit(in);
}

bool unsigned_int(istream &in){
    if(!digit(in))return false;
    read_digit(in);
    return true;
}

bool signed_int(istream &in){
    if(in.peek()=='-'||in.peek()=='+') cout<<((char)in.get());
    return unsigned_int(in);
}

bool end_of_line(char c){

    return c=='\n';
}

fail_type real(istream &in){
  if(!signed_int(in))return s_int_expeced;

    switch(in.peek()){
        case 'e':

            cout<<((char)in.get());
            if(!signed_int(in)){

               return s_int_expeced;
            }
            if(!end_of_line(in.peek())){

                return s_int_expeced;
            }
            cout<<((char)in.get());
            return good;
        case '.':
            cout<<((char)in.get());
            if(!unsigned_int(in))return u_int_expeced;
            if(end_of_line(in.peek()))return good;
            if(in.peek()!='e')return u_int_expeced;
            cout<<((char)in.get());
            if(!signed_int(in))return u_int_expeced;
            if(!end_of_line(in.peek()))return u_int_expeced;
            std::cout<<((char)in.get());
            return good;

        default:

        return exp_or_point_expected;

}
}
void print_res(fail_type res)
{
    cout<<endl;
    if (res == good) cout<<"good";
    if (res == u_int_expeced) cout<<"fail! Ожидалось unsigned int"<<endl;
    if (res == s_int_expeced) cout<<"fail! Ожидалось signed int"<<endl;
    if (res == exp_or_point_expected) cout<<"fail! Ожидалось e или точка"<<endl;
}

int main(){
   // fail_type res;
cout<<"Введите строку"<<endl;
       print_res(real(cin));
    return 0;
}
