// FCI � Programming 1 � 2018 - Assignment 3
// Program Name: Word.cpp    v0.2
// Last Modification Date: 01/04/2018
// Author1 and ID and Group: Youssef adel elsayed 20170345
// Author2 and ID and Group: yousef ismail okasha 20170336
// Author3 and ID and Group: ahmed mohamed hanfy 20170357
// Teaching Assistant: eng.mohamed atta & eng.ibrahim zidan


#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
string srr;

void create_file();

void showMenu(int &option);

void loadData(vector<char> &data,fstream &myfile,int option);

void makeCommand(int &option, fstream &myfile,vector<char>&data);

void open_file(fstream &myfile);

void add_data(fstream &myfile,vector <char> &data); // point 8 in individual task

void toUpper(fstream &myfile, vector<char> &data);  // point 10 in individual task

void replaceword (fstream &myfile, vector<char> &data); // point 9 in individual task

int main(){
    vector<char>data;
    fstream myfile;

    int option = 0;


    while(true){





        showMenu(option);

        makeCommand(option,myfile,data);

    }



}

void open_file(fstream &myfile){     // open file
    cout<<"give me the name of the file you want to open : ";
    cin>>srr;
    srr+=".txt";
    myfile.open(srr.c_str());
}

void create_file(){

    string srr;

    cout<<"enters the new file name \n";

    cin>>srr;

    srr +=".txt";

    ofstream out_file (srr.c_str());

    // out_file<<"hello,world "<<srr;

   // showMenu();

    out_file.close();

}

void loadData(vector<char>&data,fstream &myfile,int option,string fword){
    int i = 0,characters =0, word =0;
    if(!myfile.is_open()){
        data.clear();
        cout<<"loadData\n";
        open_file(myfile);
    }
    if(!myfile.is_open()){
        cerr<<"error while loading file\n";
        return;
    }
    else{
        char x;
        while(myfile>>noskipws>>x){
            data.push_back(x);
        }
    }
    
    if(option ==3){
        cout<<"\n\n=====================================\n\n";
        for(int j =0 ;j<data.size();j++)
            cout<<data[j];
        cout<<"\n\n=====================================\n\n";
        myfile.close();
    }
    else if(option ==5){
        for(int i=0;i<data.size();i++){
            if(isalpha(data[i]))
                characters++;
            if(isalpha(data[i])&& !isalpha(data[i-1]))
                word++;
        }
	    cout<<"\n\nThe number of characters in the file = "<<characters<<endl;
        cout<<"\n\nThe number of words in the file = "<<word<<endl;
        myfile.close();
    }
    else if(option == 4){
        cout <<"give me the name of file you want to save to"<<endl;
        string F_name;
        cin>>F_name;
        F_name +=".txt";
        ofstream anotherfile;
        anotherfile.open(F_name.c_str());
        for (int j = 0 ; j<data.size();j++)
            anotherfile.put(data[j]);
        anotherfile.close();
        myfile.close();
    }
    else if(option == 6){
        string newword;
        for(int h=0;h<data.size();h++){
            newword+=data[h];
        }
        transform(newword.begin(),newword.end(),newword.begin(),tolower());
        transform(fword.begin(),fword.end(),fword.begin(),tolower());
        // transform(newword.begin(),newword.end(),newword.begin(),::ptr_fun<int , int>(tolower()));
        // transform(fword.begin(),fword.end(),fword.begin(),::ptr_fun<int , int>(tolower()));
        if(newword.find(fword) != string::npos){
            cout<<"found"<<endl;
        }
        else{
            cout<<"not found"<<endl;
        }
        myfile.close();

    }
    else if(option == 7){
        /*ofstream anotherfile;
        anotherfile.open(srr);
        data.clear();
        anotherfile.close();
        myfile.close();
        */
        fstream myfile(srr,ios::out | ios::trunc);
    }
    else if(option==8){
        add_data(myfile,data);
    }
    else if(option == 9){
        replaceword(myfile,data);
    }
    else if(option == 10){
        toUpper(myfile,data);
    }
    else if(option == 13){   //rot13 encryption
        string newword,str2;
        for(int h=0;h<data.size();h++){
            newword+=data[h];
        }
        for (int i=0; i<newword.length();++i){
                if(isalpha(newword[i])){
                    int ch=newword[i]+13;
                    char ch2=newword[i];
                    if (newword[i]==' '){
                        str2.append(" ");
                        continue;
                    }
                    if (int(ch)>122&&int(ch2)<=122){
                        int fix =122-newword[i];
                        fix =13-fix; //6
                        ch=96+fix;//102
                        str2=str2+char(ch);
                    }
                    else if (int(ch)>90&&int(ch2)<=90){
                        int fix =90-newword[i];
                        fix =13-fix;
                        ch=64+fix;
                        str2=str2+char(ch);
                    }
                    else {
                        str2=str2+char(ch);
                    }
                    }
                else{
                    str2+=newword[i];
                }

        }
        data.clear();
        for(int i=0;i<str2.length();++i){
            data.push_back(str2[i]);
        }
        ofstream outfile;
        outfile.open(srr.c_str());
        for (int j = 0 ; j<data.size();j++)

            outfile.put(data[j]);

        outfile.close();
        myfile.close();


    }
     else if(option == 14){   //rot13 decryption
        string newword,str2;
        for(int h=0;h<data.size();h++){
            newword+=data[h];
        }
        for (int i=0; i<newword.length();++i){
                if(isalpha(newword[i])){
                    int ch=newword[i]-13;
                    char ch2=newword[i];
                    if (newword[i]==' '){
                        str2.append(" ");
                        continue;
                    }
                    if (int(ch)<97&&int(ch2)>=97){
                        int fix =int(newword[i])-97;
                        fix =13-fix; //6
                        ch=123-fix;//102
                        str2=str2+char(ch);
                    }
                    else if (int(ch)<65&&int(ch2)<=90){
                        int fix =int(newword[i])-65;
                        fix =13-fix;
                        ch=91-fix;
                        str2=str2+char(ch);
                    }
                    else 
                        str2=str2+char(ch);
                    
                }
                else
                    str2+=newword[i];
                

        }
        data.clear();
        for(int i=0;i<str2.length();++i){
            data.push_back(str2[i]);
        }
        ofstream outfile;
        outfile.open(srr.c_str());
        //for (int j = 0 ; j<data.size();j++)
     }

}

void showMenu(int &option){

    cout<<"*****************************\n";

    cout<<"What do you like to do today?\n";

    cout<<"\n\n1- Load an existing file\n";

    cout<<"2- Create a new file\n";

    cout<<"3- Display file contents\n";

    cout<<"4- load data from file to another file\n";

    cout<<"5- Count file word and characters\n";

    cout<<"6- Search for a word in a file\n";

    cout<<"7- Empty file content\n";

    cout<<"8- add data to the end of the file\n";

    cout<<"9-replace a word in the file\n";

    cout<<"10-to turn the file to upper case\n";

    cout<<"13-to encrypt the content of the file\n";

    cout<<"14-to decrypt the content of the file\n";

    option = 0;

    cout<<"your choice:";

    cin>>option;

}

void makeCommand(int &option,fstream &myfile,vector<char>&data){


    if(option == 1){
        loadData(data,myfile,1,"");
    }

    else if(option ==2){
        create_file();
    }

    else if(option ==3){
        loadData(data,myfile,3,"");
    }

    else if(option ==4){
        loadData(data,myfile,4,"");
    }


    else if(option ==5){
        loadData(data,myfile,5,"");
    }
    else if(option ==6){
        cout<<"enter the word you want to search:";
        string fword;
        cin>>fword;
        loadData(data,myfile,6,fword);
    }
    else if(option ==7){
        loadData(data,myfile,7,"");
    }
    else if(option ==8){
        add_data(myfile,data);
    }
    else if(option ==9){
        replaceword(myfile,data);
    }
    else if(option ==10){
        toUpper(myfile,data);
    }

    //showMenu(option);
}
void add_data(fstream &myfile,vector <char> &data){
    myfile.close();
    myfile.open(srr.c_str(), ios::in);
    if(myfile.fail() || !myfile.is_open()){
        cout<<" Error while opening file "<<endl;
        return;
    }
    string more_data;
    cout<<"Enter more data at the end of the file"<<endl;
    cin.ignore();
    getline(cin,more_data);
    myfile<<" "<<more_data;
}
void toUpper(fstream &myfile, vector<char> &data){
    char character;
    myfile.close();
    myfile.open(srr.c_str(),ios::in);
    while(!myfile.eof ()&& !myfile.fail()){
        myfile >> noskipws >> character;
        if(!isalpha(character) ){
            cout << character;
            continue;
        }
        else{
            character=toupper(character);
        }
        cout<< character;
    }
    cout << endl;
}
void replaceword (fstream &myfile, vector<char> &data){
        myfile.close();
        string line, word, repword ;
        int pos;
        myfile.open(srr.c_str());
        if(!myfile.is_open() || myfile.fail()){
            cout<<"Error while opening file"<<endl;
            return;
        }
        cout<<"Enter a word: ";
        cin>>word;
        cout<<"Enter a word you want to replace: ";
        cin>>repword;
        if(myfile.is_open()){
            while(!myfile.eof() && !myfile.fail()){
                getline (myfile,line);
                if ((pos=line.find(word))!=string::npos){
                    line.replace(pos,word.size(),repword);
                    cout<<line<<endl;
                }
                else
                    cout<< "The existing word you have entered is not in the file please try another word!"<<endl;
            }
            cout<<endl;
        }
}

