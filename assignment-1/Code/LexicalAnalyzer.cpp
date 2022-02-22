#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
using namespace std;

//Prototypes
int isReserved(string str);
int isTypeRef(string str);
int isIdentifier(string str);
int isNumber(string str);
int isAssignmentLex(string str);
int isRangeSep(string str);
int isComma(string str);
int isLCurly(string str);
int isRCurly(string str);
int isLParen(string str);
int isRParen(string str);
int isBar(string str);


int main () {
    
    //Creating input file to read from
    ifstream myfile;
    myfile.open("input.txt");
    string s;

    //making sure file opens
    if (myfile.is_open())
    {
        //Looping until end of file
        while(!myfile.eof()){
            //Read file line by line
            getline(myfile,s);
            istringstream line(s);

            //Loop thru line by space
            while(getline(line, s, ' ')){
                if(isReserved(s)){
                    cout << s << " is reserved." << endl;
                    continue;
                }
                if(isTypeRef(s)){
                    cout << s << " is a type reference." << endl;
                }
                if(isIdentifier(s)){
                    cout << s << " is an identifier." << endl;
                }
                if(isNumber(s)){
                    cout << s << " is a number." << endl;
                }
                if(isAssignmentLex(s)){
                    cout << s << " is an assignment lexical item." << endl;
                }
                if(isRangeSep(s)){
                    cout << s << " is a range separator." << endl;
                }
                if(isComma(s)){
                    cout << s << " is a comma." << endl;
                }
                if(isLCurly(s)){
                    cout << s << " is a left curly brace." << endl;
                }
                if(isRCurly(s)){
                    cout << s << " is a right curly brace." << endl;
                }
                if(isLParen(s)){
                    cout << s << " is a left parenthesis." << endl;
                }
                if(isRParen(s)){
                    cout << s << " is a right parenthesis." << endl;
                }
                if(isBar(s)){
                    cout << s << " is a vertical bar." << endl;
                }
                
            }

        }
    }
    else{
        cout << "Error opening file" << endl;
        exit(0);
    }
    cout << "SUCCESS" << endl;
    myfile.close();
    return 0;
}

////Helper functions/////


int isReserved(string str){
    //Reserved word list
    string reserved[6] = {"TAGS", "BEGIN", "SEQUENCE", "INTEGER", "DATE", "END"};
    //Flag
    int flag = 0;
    //Loop thru list
    for(int i = 0; i < 6; i++)
    {   
        //If string is a reserved word
        if(str.compare(reserved[i]) == 0)
        {
            //Set flag 
            flag = 1;
        }
    }

    //Returning flag for check
    return flag;
}

int isTypeRef(string str){
    //Regex for this
    regex r("^[A-Z][a-zA-Z0-9-]*");
    //Bool search for 
    bool const flag = regex_search(str, r);
    //Returning true if word given is Typereg
    return flag;
}

int isIdentifier(string str){
    //Regex for this
    regex r("^[a-z][a-zA-Z0-9-]*");
    //Bool search for 
    bool const flag = regex_search(str, r);
    //Returning true if word given is Typereg
    return flag;
}

int isNumber(string str){
    //Regex for this
    regex r("\\d");
    //Bool search for 
    bool const flag = regex_search(str, r);
    //Returning true if word given is Typereg
    return flag;
}

int isAssignmentLex(string str){
    //Regex for this
    regex r("\\:\\:\\=");
    //Bool search for 
    bool const flag = regex_search(str, r);
    //Returning true if word given is Typereg
    return flag;
}
int isRangeSep(string str){
    //Regex for this
    regex r("\\.\\.");
    //Bool search for 
    bool const flag = regex_search(str, r);
    //Returning true if word given is Typereg
    return flag;
}
int isComma(string str){
    //Regex for this
    regex r("\\,");
    //Bool search for 
    bool const flag = regex_search(str, r);
    //Returning true if word given is Typereg
    return flag;
}
int isLCurly(string str){
    //Regex for this
    regex r("\\{");
    //Bool search for 
    bool const flag = regex_search(str, r);
    //Returning true if word given is Typereg
    return flag;
}
int isRCurly(string str){
    //Regex for this
    regex r("\\}");
    //Bool search for 
    bool const flag = regex_search(str, r);
    //Returning true if word given is Typereg
    return flag;
}
int isLParen(string str){
    //Regex for this
    regex r("\\(");
    //Bool search for 
    bool const flag = regex_search(str, r);
    //Returning true if word given is Typereg
    return flag;
}
int isRParen(string str){
    //Regex for this
    regex r("\\)");
    //Bool search for 
    bool const flag = regex_search(str, r);
    //Returning true if word given is Typereg
    return flag;
}
int isBar(string str){
    //Regex for this
    regex r("\\|");
    //Bool search for 
    bool const flag = regex_search(str, r);
    //Returning true if word given is Typereg
    return flag;
}


