#include<iostream>
#include<stdio.h>
#include"enemy.h"
#include"player.h"

int main()
{
    srand(time(0));
    player user;
    enemy cpu;
    int dam;
    int move=1;
    
    while(user.getHealth()>0&&cpu.getHealth()>0)
    {   
        if(user.getHealth()>0&&cpu.getHealth()>0)
        {
            std::cout<<"=============================\n";
            std::cout<<"User Health: "<<user.getHealth()<<" HP\n";
            std::cout<<"CPU Health: "<<cpu.getHealth()<<" HP\n";
            std::cout<<"=============================\n";
            printf("User Move %d:|\n",move);
            puts("=============");
            dam=user.actionMenu(cpu.defState());
            cpu.setHealth(cpu.getHealth()-dam);
        }
        puts("");
        if(user.getHealth()>0&&cpu.getHealth()>0)
        {
            std::cout<<"=============================\n";
            std::cout<<"User Health: "<<user.getHealth()<<" HP\n";
            std::cout<<"CPU Health: "<<cpu.getHealth()<<" HP\n";
            std::cout<<"=============================\n";
            printf("CPU Move %d:|\n",move++);
            puts("============");
            dam=cpu.action(user.defState(),user.getHealth());
            user.setHealth(user.getHealth()-dam);
        }
    }
    std::cout<<"=============================\n";
    std::cout<<"User Health: "<<user.getHealth()<<" HP\n";
    std::cout<<"CPU Health: "<<cpu.getHealth()<<" HP\n";
    std::cout<<"=============================\n";
    if(cpu.getHealth()<=0)
        std::cout<<"You Win!\n";
    if(user.getHealth()<=0)
        std::cout<<"You Lose!\n";
    return 0;
}

