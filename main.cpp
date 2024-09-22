#include"function.h"
#include<iostream>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<windows.h> 
#include<ctime>
#include<conio.h>
using namespace std;
/*
作者:吳澤延 
輸入: 無 
輸出: 瓶子倒水遊戲 
功能: 利用呼叫模組的函數，完成一整個瓶子倒水遊戲的系統 
使用模組:function.h以及其他函式庫 
*/
int main(){
	system("mode con cols=100 lines=35");//控制台寬高
	srand(time(0));// srand函數是隨機數生成器的初始化函數，常用時間(秒數)作為種子
	welcometogame();
	while(1){//倒水
		input();
		if(de_ch()==1){
			system("cls");
			startup();
			continue;
		}
		outinput();
		if(de_end()==1){//所有瓶子都整理好了 
			endgame();//過關 
		}
	}
	return 0;
}
