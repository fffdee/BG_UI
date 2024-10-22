#include "input_handle.h"
#include <termios.h>
#include <fcntl.h>  
#include <unistd.h>  
#include <stdio.h>

char keyboaed_Loop();
void keyboaed_Init();
void keyboaed_DeInit();



BG_Input_Handle BG_input_handle = {
    
    .KeyBoardInit = keyboaed_Init,
    .KeyBoardInit = keyboaed_DeInit,
    .KeyBoardLoop = keyboaed_Loop,
    

};

char keyboaed_Loop()
{      
       char ch;
       int bytes_read = read(STDIN_FILENO, &ch, 1);

       if(ch==' ') ch=0;
       if (bytes_read > 0)
        {
            // 处理键盘输入
            printf("Key pressed: %c\n", ch);
     
        }
        return ch;
}

void keyboaed_Init()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO); // 设置非规范模式，禁用回显
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

void keyboaed_DeInit()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO); // 恢复规范模式，启用回显
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    fcntl(STDIN_FILENO, F_SETFL, 0); // 清除非阻塞标志
}

