#include <stdio.h>
#include <Windows.h>
#include <conio.h>

void logo_win(){
printf("              .-=========-.\n");
printf("              \\'-=======-'/\n");
printf("              _|   .=.   |_\n");
printf("             ((|  {{1}}  |))\n");
printf("              \\|   /|\\   |/\n");
printf("               \\__ '`' __/\n");
printf("                 _`) (`_\n");
printf("               _/_______\\_\n");
printf("              /___________\\\n\n");
}

void logo_tomato(){
printf("                  ,                       \n");                  
printf("                 /.\\                          \n");              
printf("                //_`\\                              \n");         
printf("           _.-`| \\ ``._                             \n");    
printf("       .-''`-.       _.'`.      WHAT GETS\n");
printf("     .'      / /'\\/`.\\    `.     MEASURED,\n");
printf("    /   .    |/         `.  \\     GETS    \n");
printf("   '   /                  \\  ;    MANAGED. \n");
printf("  :   '            \\       : :       -Peter Drucher \n");                       
printf("  ;  ;             ;      /  .                      \n");   
printf("   ' :             .     '  /                       \n");
printf("    \\ \\           /       .'                        \n");
printf("     `.`        .'      .'                          \n");
printf("       `-..___....----`                             \n\n");
}

void logo_pomodoro(){
printf(" ______                      _                     _______ _        \n");           
printf("(_____ \\                    | |                   (_______|_)             \n");      
printf(" _____) )__  ____   ___   __| | ___   ____ ___        _    _ ____  _____  ____\n");  
printf("|  ____/ _ \\|    \\ / _ \\ / _  |/ _ \\ / ___) _ \\      | |  | |    \\| ___ |/ ___)\n"); 
printf("| |   | |_| | | | | |_| ( (_| | |_| | |  | |_| |     | |  | | | | | ____| |    \n"); 
printf("|_|    \\___/|_|_|_|\\___/ \\____|\\___/|_|   \\___/      |_|  |_|_|_|_|_____)_|    \n\n"); 
}

void logo_shortB(){
printf("  ______ _                          ______                    _     \n");
printf(" / _____) |                  _     (____  \\                  | |    \n");
printf("( (____ | |__   ___   ____ _| |_    ____)  ) ____ _____ _____| |  _ \n");
printf(" \\____ \\|  _ \\ / _ \\ / ___|_   _)  |  __  ( / ___) ___ (____ | |_/ )\n");
printf(" _____) ) | | | |_| | |     | |_   | |__)  ) |   | ____/ ___ |  _ ( \n");
printf("(______/|_| |_|\\___/|_|      \\__)  |______/|_|   |_____)_____|_| \\_)\n\n\n");                                                                    
}

void logo_longB(){
printf(" _                           ______                    _     \n");
printf("(_)                         (____  \\                  | |    \n");
printf(" _       ___  ____   ____    ____)  ) ____ _____ _____| |  _ \n");
printf("| |     / _ \\|  _ \\ / _  |  |  __  ( / ___) ___ (____ | |_/ )\n");
printf("| |____| |_| | | | ( (_| |  | |__)  ) |   | ____/ ___ |  _ ( \n");
printf("|_______)___/|_| |_|\\___ |  |______/|_|   |_____)_____|_| \\_)\n");
printf("                   (_____|                                   \n\n\n");
}

void logo_work(){
printf(" _  _  _             _     \n");
printf("(_)(_)(_)           | |    \n");
printf(" _  _  _  ___   ____| |  _ \n");
printf("| || || |/ _ \\ / ___) |_/ )\n");
printf("| || || | |_| | |   |  _ ( \n");
printf(" \\_____/ \\___/|_|   |_| \\_)     \n\n\n");                      
}

void beep(int i,int f,int t){
    while(i>0){
        Beep(f,t);
        i--;
    }
}
void run(int sec, int min, char ch)
{
    while (min >= 0)
    {
        while (sec > 0)
        {
            Sleep(1000);
            system("cls");
            sec--;
            switch(ch){
                case 'w': logo_work();
                break;
                case 's': logo_shortB();
                break;
                case 'l': logo_longB();
                break;
            }
            printf("Time left  %d:%d", min, sec);
        }
        sec = 59;
        min--;
    }
}
void cycle(int work_min,int break_min,int ch){
        int min=0,sec=0;
        printf("\nLet do a work for %d min\n",work_min);
        system("pause");
        sec = 59;
        min = work_min;
        run(sec,min,'w');
        beep(2,600,300);
        beep(1,750,500);
        system("cls");
        logo_pomodoro();
        printf("\nTake a %d min break\n",break_min);
        system("pause");
        sec = 59;
        min = break_min;
        run(sec,min,ch);
        beep(1,750,500);
        beep(2,600,300);
        system("cls");
        logo_pomodoro();
}
int main()
{
    SetConsoleTitle("Pomodaro");
    logo_pomodoro();
    printf("\n*** Welcome to pomodoro timer work ***\n");
    char ch=' ';
    do{
    for (int i = 1; i <= 3; i++)
    {
        cycle(25,5,'s');
        printf("\n%d cycle completed!\n",i);
    }
    cycle(25,15,'l');
    logo_win();
    printf("\nWell done you completed your pomodoro session\n");
    beep(3,600,300);
    beep(3,700,300);
    beep(3,800,300);
    printf("\nDo you have more work , start it again OwO....\n\nPress 'y' for continue or any other key to exit\n");
    ch = getch();
    system("cls");
    }while(ch == 'y');
    logo_tomato();
    printf("\nThanks for using OwO\n***DEBU creation***\n\n");
    system("pause");
}