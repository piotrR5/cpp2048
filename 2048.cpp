#include <iostream>
#define FMT_HEADER_ONLY
#include <fmt/color.h>
#include <fmt/core.h>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <ncurses.h>

using namespace std;

void debug(vector<vector<int>>&plane){
    for(int i=0;i<plane.size();i++){
        for(int j=0;j<plane.size();j++){
            plane[i][j]=pow(2,i)*pow(2,j);
        }
    }
}



void debugShowPlane(vector<vector<int>>&plane){
    for(auto&i:plane){
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }
}

void showPlane(vector<vector<int>>&plane){
    for(auto&i:plane){
        for (auto j:i)
        {
            if(j<16){
                
                switch(j){
                    case 0:{
                        fmt::print(fg(fmt::color::white) |
                        fmt::emphasis::bold, "[   {}   ]", "0");
                    }
                    break;
                    case 2:{
                        fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255, 220, 0)) |
                        fmt::emphasis::bold, "[   {}   ]", to_string(j));
                    }
                    break;
                    case 4:{
                        fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255, 190, 0)) |
                        fmt::emphasis::bold, "[   {}   ]", to_string(j));
                    }
                    break;
                    case 8:{
                        fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255, 150, 0)) |
                        fmt::emphasis::bold, "[   {}   ]", to_string(j));
                    }
                    break;
                    default:{
                        fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255, 255, 0)) |
                        fmt::emphasis::bold, "[   {}   ]", to_string(j));
                    }
                }
            }
            else if(j<128){
                //fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255-j*2, 255-j, 0)) |
                //fmt::emphasis::bold, "[   {}  ]", to_string(j));
                switch(j){
                    case 16:{
                        fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255, 120, 0)) |
                        fmt::emphasis::bold, "[   {}  ]", to_string(j));
                    }
                    break;
                    case 32:{
                        fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255, 90, 0)) |
                        fmt::emphasis::bold, "[   {}  ]", to_string(j));
                    }
                    break;
                    case 64:{
                        fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255, 60, 0)) |
                        fmt::emphasis::bold, "[   {}  ]", to_string(j));
                    }
                    break;
                }
            }
            else if(j<1024){
                //fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255-j/4, 255-j/4, 0)) |
                //fmt::emphasis::bold, "[  {}  ]", to_string(j));
                switch(j){
                    case 128:{
                        fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(220, 60, 0)) |
                        fmt::emphasis::bold, "[  {}  ]", to_string(j));
                    }
                    break;
                    case 256:{
                        fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(200, 30, 0)) |
                        fmt::emphasis::bold, "[  {}  ]", to_string(j));
                    }
                    break;
                    case 512:{
                        fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(170, 0, 0)) |
                        fmt::emphasis::bold, "[  {}  ]", to_string(j));
                    }
                    break;
                }
            }
            else if(j<16384){
                //fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255-j, 255-j, 0)) |
                //fmt::emphasis::bold, "[  {} ]", to_string(j));
                switch(j){
                    case 1024:{
                        fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(150, 0, 0)) |
                        fmt::emphasis::bold, "[  {} ]", to_string(j));
                    }
                    break;
                    case 2048:{
                        fmt::print(fg(fmt::color::white) | bg(fmt::v9::rgb(120, 0, 0)) |
                        fmt::emphasis::bold, "[  {} ]", to_string(j));
                    }
                    break;
                    case 4096:{
                        fmt::print(fg(fmt::color::white) | bg(fmt::v9::rgb(120, 0, 30)) |
                        fmt::emphasis::faint, "[  {} ]", to_string(j));
                    }
                    break;
                    case 8192:{
                        fmt::print(fg(fmt::color::white) | bg(fmt::v9::rgb(100, 0, 60)) |
                        fmt::emphasis::faint, "[  {} ]", to_string(j));
                    }
                    break;
                }
            }
            else if(j<131072){
                //fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255-j, 255-j, 0)) |
                //fmt::emphasis::bold, "[ {} ]", to_string(j));
                switch (j){
                    case 16384:{
                        fmt::print(fg(fmt::color::white) | bg(fmt::v9::rgb(70, 0, 80)) |
                        fmt::emphasis::faint, "[ {} ]", to_string(j));
                    }
                    break;
                    case 32768:{
                        fmt::print(fg(fmt::color::white) | bg(fmt::v9::rgb(40, 0, 100)) |
                        fmt::emphasis::faint, "[ {} ]", to_string(j));
                    }
                    break;
                    case 65536:{
                        fmt::print(fg(fmt::color::white) | bg(fmt::v9::rgb(0, 0, 120)) |
                        fmt::emphasis::faint, "[ {} ]", to_string(j));
                    }
                    break;
                }
            }
            else if(j<1000000){
                //fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255-j, 255-j, 0)) |
                //fmt::emphasis::bold, "[ {}]", to_string(j));
                switch(j){
                    case 131072:{
                        fmt::print(fg(fmt::color::white) | bg(fmt::v9::rgb(0, 0, 160)) |
                        fmt::emphasis::faint, "[ {}]", to_string(j));
                    }
                    break;
                    case 262144:{
                        fmt::print(fg(fmt::color::white) | bg(fmt::v9::rgb(0, 0, 200)) |
                        fmt::emphasis::faint, "[ {}]", to_string(j));
                    }
                    break;
                    case 524288:{
                        fmt::print(fg(fmt::color::white) | bg(fmt::v9::rgb(0, 0, 250)) |
                        fmt::emphasis::faint, "[ {}]", to_string(j));
                    }
                }
            }
            else{
                fmt::print(fg(fmt::color::black) | bg(fmt::v9::rgb(255, 255, 255)) |
                fmt::emphasis::faint, "[{}]", to_string(j));
            }

        }
        cout<<"\n\r";
    }
}

bool update(vector<vector<int>>&plane, int dir){
    bool didUpdate=false;
    switch(dir){
        case KEY_UP:{
            for(int i=1;i<plane.size();i++){
                for(int j=0;j<plane.size();j++){
                    int foo=plane[i][j];
                    plane[i][j]=0;
                    for(int k=i;k>=1;k--){
                        if(plane[k-1][j]!=foo && plane[k-1][j]!=0 && plane[k][j]==0){
                            plane[k][j]=foo;
                            didUpdate=true;
                            break;
                        }
                        else if(plane[k-1][j]==foo){
                            plane[k-1][j]*=2;
                            didUpdate=true;
                            break;
                        }
                        else if(k==1 && plane[k-1][j]==0){
                            plane[k-1][j]=foo;
                            didUpdate=true;
                            break;
                        }
                    }
                }
            }
        }
        break;
        case KEY_DOWN:{
            for(int i=plane.size()-2;i>=0;i--){
                for(int j=0;j<plane.size();j++){
                    int foo=plane[i][j];
                    plane[i][j]=0;
                    for(int k=i;k<plane.size()-1;k++){
                        if(plane[k+1][j]!=foo && plane[k+1][j]!=0 && plane[k][j]==0){
                            plane[k][j]=foo;
                            didUpdate=true;
                            break;
                        }
                        else if(plane[k+1][j]==foo){
                            plane[k+1][j]*=2;
                            didUpdate=true;
                            break;
                        }
                        else if(k==plane.size()-2 && plane[k+1][j]==0){
                            plane[k+1][j]=foo;
                            didUpdate=true;
                            break;
                        }
                    }
                }
            }
        }
        break;
        case KEY_RIGHT:{
            for(int i=0;i<plane.size();i++){
                for(int j=plane.size()-2;j>=0;j--){
                    int foo=plane[i][j];
                    plane[i][j]=0;
                    for(int k=j;k<plane.size()-1;k++){
                        if(plane[i][k+1]!=foo && plane[i][k+1]!=0 && plane[i][k]==0){
                            plane[i][k]=foo;
                            didUpdate=true;
                            break;
                        }
                        else if(plane[i][k+1]==foo){
                            plane[i][k+1]*=2;
                            didUpdate=true;
                            break;
                        }
                        else if(k==plane.size()-2 && plane[i][k+1]==0){
                            plane[i][k+1]=foo;
                            didUpdate=true;
                            break;
                        }
                    }
                }
            }

        }
        break;
        case KEY_LEFT:{
            for(int i=0;i<plane.size();i++){
                for(int j=1;j<plane.size();j++){
                    int foo=plane[i][j];
                    plane[i][j]=0;
                    for(int k=j;k>=1;k--){
                        if(plane[i][k-1]!=foo && plane[i][k-1]!=0 && plane[i][k]==0){
                            plane[i][k]=foo;
                            didUpdate=true;
                            break;
                        }
                        else if(plane[i][k-1]==foo){
                            plane[i][k-1]*=2;
                            didUpdate=true;
                            break;
                        }
                        else if(k==1 && plane[i][k-1]==0){
                            plane[i][k-1]=foo;
                            didUpdate=true;
                            break;
                        }
                    }
                }
            }

        }
    }
    return didUpdate;
}

bool gameOver(vector<vector<int>>&plane,bool didUpdate){
    bool isFull=true;
    for(int i=0;i<plane.size();i++){
        for(int j=0;j<plane.size();j++){
            if(plane[i][j]==0)return false;
        }
    }
    if(isFull && !didUpdate)return true;
    else return false;
}

int main(int argc, char* argv[]){

    initscr();
	keypad(stdscr, TRUE);
	noecho();	

    srand(time(NULL));
    int size=4;
    if(argc>1)size=stoi(argv[1]);
    if(size>16){
        system("stty sane");
        return 1;
    }
    cout<<"size: "<<size<<endl;

    //initialize game
    vector<vector<int>>plane(size,vector<int>(size,0));
    int randx,randy;
    /*do{
        randx=rand()%size;
        randy=rand()%size;
    }while(plane[randx][randy]);
    plane[randx][randy]=2;*/

    plane[rand()%size][rand()%size]=2;
    do{
        randx=rand()%size;
        randy=rand()%size;
    }while(plane[randx][randy]);
    plane[randx][randy]=2;


    //debug
    //debug(plane);
    //debug
    //showPlane(plane);
    //debugShowPlane(plane);
    int input=getch();
    while(true){
        showPlane(plane);
        //cout<<"\rInput: "<<input<<"\n\r";
        switch(input){
            case KEY_UP:{
                cout<<"\rInput: Key Up\n\r";
            }
            break;
            case KEY_DOWN:{
                cout<<"\rInput: Key Down\n\r";
            }
            break;
            case KEY_RIGHT:{
                cout<<"\rInput: Key Right\n\r";
            }
            break;
            case KEY_LEFT:{
                cout<<"\rInput: Key Left\n\r";
            }
            break;
            default:{
                cout<<"\rInput: "<<input<<"\n\r";
            }
        }
        input=getch();
        bool didUpdate=update(plane,input);
        if(gameOver(plane, didUpdate)){
            system("clear");
            cout<<"GAME OVER!\r\n";
            system("stty sane");
            return 0;
        }
        if(didUpdate){
            do{
                randx=rand()%size;
                randy=rand()%size;
            }while(plane[randx][randy]);
            plane[randx][randy]=2;
        }
        
        //usleep(20000);
        system("clear");
    }

    endwin();
    system("stty sane");
    return 0;
}

