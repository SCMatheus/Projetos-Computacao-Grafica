#include<iostream>
#include<Winuser.h>
#include <windows.h>

int main(){

    int x = 555 , y = 614;

    Sleep(3000);
    while(1){

        x = 555;
        y = 614;
        SetCursorPos(x,y);
        mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
        Sleep(250);
        // ENTER key down
        keybd_event(VK_RETURN, 0x9C, 0, 0);

        // ENTER key up
        keybd_event(VK_RETURN, 0x9C, KEYEVENTF_KEYUP, 0);
        Sleep(250);
        x = 555;
        y = 813;
        SetCursorPos(x,y);
        mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
        Sleep(250);

        if(GetKeyState(VK_ESCAPE) & 0x8000){
            break;
        }

    }

}
