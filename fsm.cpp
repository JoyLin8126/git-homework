#include <iostream>
using namespace std;

int main()
{
    string name;
    cout << "FSM Example"<< endl << endl;
    int state = 0; 	//起始狀態 
    int input;		//輸入 
    while(1)
    {
        switch(state)
        {
            case 0://狀態 0:跑步 
                cout << "Current State : Running"<< endl;
                cout << "Input Option : 0.See Money 1.See stores" << endl; 
                cout << "Input : ";
                cin >> input; //讀取輸入 
                if(input == 0) //看到錢
                {
                    state = 10; //吸錢+跑 
                }
                else if(input == 1)//遇到商店
                {
                    state = 20; //買武器
                }
                break;
                
            case 10://狀態 10:吸錢+跑 
                cout << "Current State : Running + Collecting Money"<< endl;
                cout << "Input Option : 1. See stores" << endl; 
                cout << "Input : ";
                cin >> input;
                if(input == 1)
                {
                    state = 20; //買武器
                }
                break;
                
            case 20://狀態 20:買武器 
                cout << "Current State : Buy Weapons"<< endl;
                cout << "Input Option : 0. See Giant" << endl; 
                cout << "Input : ";
                cin >> input;
                if(input == 0)//看到巨人
                {
                    state = 30;//攻擊
                }
                break;
                
            case 30://狀態 30:攻擊 
                cout << "Current State : Attack"<< endl;
                cout << "Input Option : 0. Win 1. Can't win" << endl; 
                cout << "Input : ";
                cin >> input;
                if(input == 0) //贏 
                {
                    state = 40;//等級提升
                }
                else if(input==1)//打不贏
                {
                    state = 0;//跑
                }
                break;
                
                case 40://等級提升
                cout << "Current State : Level up"<< endl;
                cout << "Input Option : 0.New Level" << endl; 
                cout << "Input : ";
                cin >> input;
                if(input == 0) //新關卡 
                {
                    state = 0;//等級提升
                }
                break;
        }
        cout << endl;
    }
}

