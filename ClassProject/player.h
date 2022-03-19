#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

class player{
    public:
        player(){health=100;}
        
        int health;
        bool def;
        
        int getHealth(){return health;}
        
        void setHealth(int h){
            if(h<0)
                health=0;
            else
                health=h;
        }
        
        bool defState(){return def;}
        
        int actionMenu(bool c){
            char val='0';
            def=false;
            bool redo=true;
            while(redo){
                puts("1.Attack");
                puts("2.Sp Attack");
                puts("3.Defend");
                puts("4.Heal");
                std::cout<<"What will you do: ";
                std::cin>>val;
            
                switch(val){
                    case '1':
                        return attack(c);
                        redo=false;
                        break;
                    case '2':
                        return spAttack(c);
                        redo=false;
                        break;
                    case '3':
                        std::cout<<"You guard yourself";
                        defend();
                        redo=false;
                        return 0;
                        break;
                    case '4':
                        if(health!=100){
                            heal();
                            redo=false;
                            return 0;
                            break;
                        }
                        else{
                            std::cout<<"Full Health! Pick Again...\n";
                            std::cout<<"=============================\n";
                            break;
                        }
                    default:
                        std::cout<<"Invalid choice!";
                        std::cout<<"=============================\n";
                }
            }
        }
    private:
        int tempHit;
        int attack(bool cpu){
            srand(time(0));
            if (health>0){
                tempHit=(rand()%6)+10;
                puts("You attack.");
                if(cpu){
                    std::cout<<"They took "<<tempHit<<" damage.";
                    return tempHit;
                }
                std::cout<<"They blocked the attack!";
                return 0;
            }
	    return 0;
        }
        
        int spAttack(bool cpu){
            srand(time(0));
            if(health>0){
                tempHit=(rand()%16)+15;
                puts("You use a special attack.");
                if(!cpu){
                    std::cout<<"They took "<<tempHit<<" damage.";
                    return tempHit;
                }
                std::cout<<"They blocked the attack!";
                return 0;
            }
	    return 0;
        }
        void defend(){
            if(health>0)
                def=true;
        }
        void heal(){
            if (health+25>100){
                health=health+25;
                std::cout<<"You heal "<<health-100<<" HP";
                health=health-(health-100);
            }
            else if(health>0&&health!=0){
               health=health+25;
               std::cout<<"You heal 25 HP";
            }
        }
};
#endif
