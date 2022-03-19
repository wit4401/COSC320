#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "DTnode.h"

class enemy{
    public:
        //The constructor which builds the Decision Tree
        //when the enemy object is created
        enemy(){
            health=100;
            node<std::string>* n6=new node<std::string>("Sp Attack");
            node<std::string>* n5=new node<std::string>("Normal Att");
            node<std::string>* n4=new node<std::string>("Defend");
            node<std::string>* n3=new node<std::string>("Which",n5,NULL,n6);
            node<std::string>* n2=new node<std::string>("Attack",n3,NULL,n4);
            node<std::string>* n1=new node<std::string>("Yes Heal");
            root=new node<std::string>("Heal",n1,NULL,n2);
        }
        int health;//health of cpu
        bool def;//defending or not
        
        int getHealth(){return health;} //standard return function
        //standard set function
        void setHealth(int h){
            if(h<0)
                health=0;
            else
                health=h;
        }
        bool defState(){return def;}//returns whether the cpu is defending or not
        
        //This is the bulk of where the Decision Tree works
        //it requires the state of the user blocking for
        //the attack() and spAttack() functions and the
        //int value of the damage done by the user
        int action(bool user,int userHealth){
            int random;
            int attVal=50;
            srand(time(0));
            def=false;
            
            //This is the part of the Algorithm that
            //makes this machine learning taking the user
            //input and modifying the percentage of attack
            //very simply based on user and cpu health and
            //the user's previous move (0 Defended or Healed !0 attacked)
            //in a more complicated setting the computer
            //could be programmed to use the last multiple
            //inputs to come out with an output or plan of attack
            if(health<50&&userHealth>50)
                attVal=20;
            else if(user&&health<50)
                attVal=40;
            else if(userHealth>50&&health>50)
                attVal=70;
            else if(userHealth<50&&!user)
                attVal=85;
            
            //This part traverses through the Decision Tree iteratively
            //and uses the percentages to come to an output/decision
            //One could code a tree with objects to better and more concisely
            //use the percentages but my implementation does it outside
            //to make it more visual
            for(node<std::string>* curr=root;root->left&&root->right;curr){
                if(curr->nodeValue=="Heal"&&health>50){
                    random=(rand()%100)+1;
                    if(random>10)
                        curr=curr->right;
                    else
                        curr=curr->left;
                }
                else if(curr->nodeValue=="Heal"){
                    random=(rand()%100)+1;
                    if(random>40)
                        curr=curr->right;
                    else
                        curr=curr->left;
                }
                else if(curr->nodeValue=="Yes Heal"){
                    heal();
                    std::cout<<"Enemy gains 25 health\n";
                    return 0;
                }
                else if(curr->nodeValue=="Attack"){
                    random=(rand()%100)+1;
                    if(random<attVal)
                        curr=curr->left;
                    else
                        curr=curr->right;
                }
                else if(curr->nodeValue=="Defend"){
                    std::cout<<"The enemy guards.\n";
                    defend();
                    return 0;
                }
                else if(curr->nodeValue=="Which"){
                    random=(rand()%100)+1;
                    if(random>30)
                        curr=curr->left;
                    else
                        curr=curr->right;
                }
                else if(curr->nodeValue=="Normal Att"){
                    random=(rand()%100)+1;
                    if(random>5)
                        return attack(user);
                    else{
                        std::cout<<"The enemy swung at you but missed!"<<std::endl;
                        return 0;
                    }
                }
                else if(curr->nodeValue=="Sp Attack"){
                    random=(rand()%100)+1;
                    if(random>5)
                        return spAttack(user);
                    else{
                        std::cout<<"The enemy went for a special and missed!"<<std::endl;
                        return 0;
                    }
                }
            }
        }
    private:
        //the damage the cpu does (the return of the attack() and
        //spAttack() functions)
        int tempHit; 
        node<std::string>* root;
        
        //the attack function returns damage done
        int attack(bool user){
            srand(time(0));
            if(health>0){
                tempHit=(rand()%6)+10;
                puts("The enemy attacks.");
                if(!user){
                    std::cout<<"You took "<<tempHit<<" damage.\n";
                    return tempHit;
                }
                std::cout<<"You blocked the attack!\n";
                return 0;
            }
	    return 0;
        }
        //the special attack function returns damage done
        int spAttack(bool user){
            srand(time(0));
            if (health>0){
                tempHit= (rand()%16)+15;
                puts("The enemy uses a special attack.");
                if(!user){
                    std::cout<<"You took "<<tempHit<<" damage.\n";
                    return tempHit;
                }
                std::cout<<"You blocked the attack!\n";
                return 0;
            }
            return 0;
        }
        //defend function changes defence state
        void defend(){
            if(health>0)
                def=true;
        }
        //heals the cpu
        void heal(){
            if (health+25>100){
                health=health+25;
                health=health-(health-100);
            }
            else
               health=health+25;
        }
};
#endif
