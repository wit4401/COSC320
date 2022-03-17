Task 2:
lab_07.cpp:
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<locale>
#include"d_hash.h"
#include"d_hashf.h"

ifstream& getWord(ifstream& fin, string& w)
{
        char c;

        w = ""; // clear the string of characters

        while (fin.get(c) && !isalpha(c))
		; // do nothing. just ignore c

        // return on end-of-file
        if (fin.eof())
                return fin;

        // record first letter of the word
        w += tolower(c);
	
	// collect letters and digits
        while (fin.get(c) && (isalpha(c) || isdigit(c)))
                w += tolower(c);

        return fin;
}

int main(){
        puts("Lab 07:");
        std::ifstream dict, user, full;
        std::string name,text;

        //user inputs file name
        printf("Please enter the file name:");
        getline(std::cin,name);
        user.open(name,std::fstream::in);
        full.open(name,std::fstream::in);

        //checks if the file is in the directory
        //if yes continues::if no prints error message
        if(user.is_open()){
                dict.open("dict.dat",std::fstream::in);
                myhash<string,hFstring> diction(1373);//initializes hash table with 1373 buckets

                //inserts all the words from dict.dat file
                while(dict){
                        getWord(dict,text);
                        diction.insert(text);
                }
                dict.close();

                //prints out the entire statement in the user's file
                puts("\nText in file:");
                while(getline(full,text))
                        std::cout<<text<<std::endl;
                full.close();
                puts("=====================================================");

                //searches through the hash table for correctly spelled word
                //if not found in the table->prints the current word
                puts("Misspelled words:");
                while(user){
                        getWord(user,text);
                        if(diction.find(text)==diction.end())
                                std::cout<<text<<std::endl;
                }
                puts("");
                user.close();
        }
        else
                puts("ERROR! Could not open file.");
        return 0;
}

Output w/test1.txt:
Lab 07:
Please enter the file name:test1.txt

Text in file:
Hello! My nmae si Will Townsend.
I lvei in Salisbury Maryland and
I lvoe ot fode
=====================================================
Misspelled words:
nmae
si
lvei
lvoe
ot
fode

Output w/test2.txt:
Lab 07:
Please enter the file name:test2.txt

Text in file:
Clhoe si a dear friend of
mnie who lives ni Pennsylvania
Seh sese me every os otfne at
chsool
=====================================================
Misspelled words:
clhoe
si
mnie
lives
ni
seh
sese
os
otfne
chsool

Output w/test3.txt:
Lab 07:
Please enter the file name:test3.txt

Text in file:
I have fun
She and I have fun
He and I have fun
We have fun
=====================================================
Misspelled words:

