#include "a.h" 
#include "function.h"
#include "bottle.h"
#include<iostream>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<windows.h> 
#include<ctime>
#include<conio.h>
using namespace std;
using namespace a;
using namespace b;
/*
作者:張嘉峰 
輸入:無 
輸出:無 
功能:最基礎的建構子 
*/
bottle::bottle(){};
/* 
作者:張嘉峰
輸入:無 
輸出:無 
功能:建立10個皆為c的資料 
*/ 
bottle::bottle(char c)
{//大瓶子 
	for(int i=0;i<10;i++)
	cap.push_back(c);
}
/* 
作者:張嘉峰
輸入:無 
輸出:無 
功能:建立10個皆為(a+'A')字元的資料 
*/ 
void bottle::set_color(int a)
{
	for(int i=0;i<10;i++)
	cap.push_back(char(a+'A'));
}
/* 
作者:張嘉峰
輸入:無 
輸出:無 
功能:將瓶子內容物清空 
*/ 
void bottle::allpop()
{
	cap.clear();
}

/* 
作者:張嘉峰
輸入:無 
輸出:無 
功能:回傳flag的值 
*/ 
int bottle::get_flag()
{
	return flag;
}
/* 
作者:張嘉峰
輸入:無 
輸出:無 
功能:回傳cap[a]
*/ 
char bottle::get(int a)
{
	return cap[a];
}
/* 
作者:張嘉峰
輸入:無 
輸出:無 
功能:將a個c字元丟進cap 
*/ 
void bottle::push(int a,char c)
{//丟進同一顏色() 
	for(int i=0;i<a;i++)
	cap.push_back(c);
}
/* 
作者:徐晨瀚
輸入:無 
輸出:無 
功能:將cap[]丟掉a個資料 
*/ 
void bottle::pop(int a)
{
    for(int i=0;i<a;i++)
    cap.pop_back();
}
/* 
作者:許仲岳
輸入:無 
輸出:無 
功能:回傳cap[]資料數 
*/ 
int bottle::size()
{ 
	return cap.size();
}
/* 
作者:許仲岳 
輸入:無 
輸出:size(),a,O or X,cap裡每個資料的字元 
功能:讓使用者看到瓶子的編號 容量 是否達成過關條件 以及內容物得顏色 
*/ 
void bottle::showbady(int a)
{//輸出瓶身  顯示顏色量和狀態 
	int b=1;
	col(15);
	gotoxy((a+1)*4-1,20);
	cout<<size();
	gotoxy((a+1)*4-1,16);
	cout<<a;
	if(cap.size()==5)
	{
		for(int i=0;i<4;i++)
		{//判斷是否為全滿且皆同色 
			if(cap[i]==cap[i+1])
			b++;
			else
			break;
		}
		gotoxy((a+1)*4-1,19);
		if(b==5)
		{
			gotoxy((a+1)*4-1,18);
			flag=1;
			cout<<"O";
		}
	}
	else if(cap.size()==0)
	{
		gotoxy((a+1)*4-1,18);
		flag=1;
		cout<<"O";
	}
	else
	{
		gotoxy((a+1)*4-1,18);
		flag=0;
		cout<<"X";
	}
			
	for(int i=0;i<cap.size();i++)
	{
		gotoxy((a)*4+2,15-i);
		col((int(cap[i])-'A'+1)*16);
		cout<<" "<<cap[i]<<" ";
		col(15);
	}
}
/* 
作者:許仲岳
輸入:無 
輸出:無 
功能:回傳瓶子從上到下顏色相同且相鄰的個數 
*/ 
int bottle::samecolor()
{//頂部相同顏色個數 
	int n=1;
	for(int i=cap.size()-1;i>0;i--)
	{
		if(cap[i]==cap[i-1])
		n++;
		else
		break;
	}
	return n;
}
/* 
作者:吳澤延 
輸入: 無 
輸出: 無 
功能:隱藏游標 
*/ 

/*
作者:許仲岳
輸入:c
輸出:無 
功能:更改游標輸出的顏色顏色
*/
int col(int c){
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);//更改文字顏色
  return 0;
}
/*
作者:吳澤延 
輸入:x,y
輸出:無 
功能:設定游標座標 
*/
void gotoxy(int x,int y){
  COORD c;
  c.X=x;
  c.Y=y; 
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

/* 
作者:許仲岳
輸入: 無 
輸出: 無 
功能:隱藏游標 
*/ 
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info={1,0};//第二個值為零=隱藏游標
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info); 
}
/* 
作者:吳澤延 
輸入: 無 
輸出: 無 
功能:回傳範圍內隨機數 
*/ 
int random(int M,int m){
	return (M-m)*rand()/(RAND_MAX+1.0)+m;
}
/* 
作者:吳澤延 
輸入:n
輸出:選單介面 
功能:遊戲選單介面 輸入1:遊戲開始 輸入3:輸出呼叫說明 輸入4:退出遊戲 
*/ 
void welcometogame(){ 
	HideCursor();
	char n;
    col(14);
	gotoxy(42,10);
	cout<<"瓶子遊戲";
	col(240);
	gotoxy(31,13);
	cout<<" 1.START ";
	gotoxy(51,13);
    cout<<" 2.DOD ";
	gotoxy(31,15);
    cout<<" 3.Explation ";
	gotoxy(51,15);
	cout<<" 4.END ";
	n=getch();
	
	
	switch(n){
	 	case '1':
	 		col(144);
			gotoxy(31,13);
			cout<<" 1.START ";
	 		break;
	 	case '2': 
	 		col(144);
			gotoxy(51,13);
    		cout<<" 2.DOD ";
			break;
	 	case '3':
	 		col(144);
	 		gotoxy(31,15);
    		cout<<" 3.Explation ";
	 		break;
		case '4':
			col(144);
			gotoxy(51,15);
			cout<<" 4.END ";
	 		break;
	default:
		col(12);
		gotoxy(40,18);
		cout<<"輸入1到4間數字";
		_getch();//輸入任意數
		system("cls");//清屏
	    welcometogame();
	}
	char enter;
	bool de=1;
	while(de){
		col(10);
		gotoxy(34,18);
		cout<<"點擊Enter確認  Esc取消";
		enter=getch();
		if(enter==13){
			de=0;
		}
		if(enter==27){
			col(7);
			system("cls");
			welcometogame();
			break;
		} 
	}
	

	
	
	
	
	
	if((enter==13)&&(de==0)){
	switch(n){
	 	case '1':
	 		system("cls");
			change();
	 		break;
	 	case '2': 
			system("cls");
			dod();
			break;
	 	case '3':
	 		explation();
	 		break;
		case '4':
			system("cls");
	 		col(10);
	 		gotoxy(30,10);
	 		cout<<"感謝您的遊玩";
	 		
	 		Sleep(1000);
	 		system("cls");
	 		gotoxy(30,10);
	 		cout<<"期待您下次的到來";
	 		
	 		Sleep(1000);
	 		system("cls");
	 		col(10);
	 		gotoxy(30,10);
	 		cout<<"再會!!!!";
	 		Sleep(1000);
	 		system("cls");
	 		exit(0);
	 		break;
	}
	}
	col(7);
}
/* 
作者:吳澤延 
輸入:n
輸出:難易度介面 
功能:選擇難易度，輸入1~3。輸入Esc:返回選單 
*/ 
void dod(){
	col(14);
	gotoxy(42,10);
	cout<<"選擇難易度";
	col(11);
	gotoxy(22,13);
	cout<<"1.NORMAL";
	col(13);
	gotoxy(44,13);
    cout<<"2.HARD";
	col(12);
	gotoxy(62,13);
	cout<<"3.EXTREME";
	col(10);
	gotoxy(45,16);
	cout<<"返回";
	char n;
	n=getch();
	 
	 switch(n){
	 	case '1':
	 		big=(rand()%5)+1;
	 		small=(rand()%8)+(big*2+5);
	 		break;
	 	case '2':
	 		big=(rand()%5)+6;
	 		small=(rand()%2)+(big*2+2);
	 		break;
	 	case '3':
	 		big=(rand()%5)+11;
	 		small=big*2+1;
	 		break;
	 	case 27:
	 		system("cls");
	 		welcometogame();
	 		break;
	default:
		col(12);
		gotoxy(40,28);
		cout<<"輸入1到3間數字";
		_getch();//輸入任意數
		system("cls");//清屏
	    dod();
	}
	system("cls");
	startup();
}
/* 
作者:吳澤延 
輸入:無 
輸出:說明介面 
功能:單純輸出說明  隨便按(別按關機鍵)能退回選單 
*/ 
void explation(){ 
	int i,j=1;
	system("cls");
	col(10);
	gotoxy(35,1);
	cout<<"說明";
	col(2);
  
  for(i=18;i<=55;i++){
  	for(j=3;j<=25;j++){
  		gotoxy(i,j);
  	if(i==18||i==55){
  		cout<<"=";
  	}
  	else if(j==3||j==25){
  		cout<<"||";
	}
  }
  }
  col(6);
  gotoxy(20,5);
  cout<<"1.瓶子底下顯示的數字為編號";
  col(10);
  gotoxy(20,8);
  cout<<"2.瓶子底下顯示的O為完成，X為未完成";
  col(14);
  gotoxy(20,11);
  cout<<"3.輸入A!B可洗牌，AB為任意整數";
  col(8);
  gotoxy(20,14);
  cout<<"祝您玩得愉快!!!";
  col(7);
  gotoxy(22,17);
  cout<<"/*****按任意鍵返回主頁面*****/";
  _getch();
  system("cls");
  welcometogame();  
}
/* 
作者:許仲岳
輸入:big,small
輸出: 無 
功能:input big and small，輸入完成呼叫別的函數 
*/ 
void change(){
	cout<<"輸入顏色數:";
	cin>>big;
	cout<<"輸入大瓶子個數(>"<<big*2<<"):";
	cin>>small;
	while(small<=(big*2)){
		cout<<"ERROR!!!  請重新輸入:";
		cin>>small;
	}
	system("cls");
	startup();
}
/* 
作者:許仲岳
輸入:無 
輸出:無 
功能:生成大瓶子小瓶子，之後大瓶子隨機分配顏色給小瓶子 
*/ 
void startup(){
	for(int i=0;i<small;i++){//製造空瓶子 
		t.push_back(te);
	}
	for(int i=0;i<big;i++){//製造大瓶子 
		bt.set_color(i);
		color.push_back(bt);
		bt.allpop();
	}
	int num=1;
	system("mode con cols=140 lines=35");
	temp2=1;
	while(num>0){//直到大瓶子都是空的 
		num=0;
		
		for(int i=0;i<big;i++){
		if(color[i].size()>0){
		temp1=random(small,0);//空瓶編號 
		
		while((temp2+t[temp1].size())>5){
			temp1=random(small,0);
		}
		t[temp1].push(temp2,color[i].get(color[i].size()-1));
		color[i].pop(temp2);
		num+=1;
		for(int j=0;j<small;j++){
		t[j].showbady(j);
		}
		Sleep(50);
		}
		
		}
	}
	color.clear();
	
}
/* 
作者:徐晨瀚 
輸入:temp1,ch,temp2 
輸出:
功能:單純輸入 
*/ 
void input(){
	pass=0;
	gotoxy(4,22);
	col(14);
	cout<<"input A to B(A-B):";
	cin>>temp1>>ch>>temp2;
	if(ch=='!'){
	}
	else {
		while((ch!='-')||(temp1>small-1)||(temp2>small-1)||(t[temp1].samecolor()+t[temp2].size()>5)){//編號不可超過瓶子總數-1     不可倒過去為overflow(超過容量) 
			cout<<"ERROR!!!"<<endl<<"請重新輸入:";
			cin>>temp1>>ch>>temp2;
	}
	}
}
/* 
作者:徐晨瀚
輸入:無 
輸出:無 
功能:倒水完，呼叫showbady成員函數 
*/ 
void outinput(){
	t[temp2].push(t[temp1].samecolor(),t[temp1].get(t[temp1].size()-1));//將A上面相同的顏色丟到B    t[temp2].push(A上面相同的顏色,A最上面的字元) 
	t[temp1].pop(t[temp1].samecolor());//將A上面一樣的字元丟出 
	system("cls");
	for(int j=0;j<small;j++){//顯示丟完的結果 
		t[j].showbady(j);
		if(t[j].get_flag()==1){//判斷是否瓶子是空的，或全滿且同一顏色 
			pass++;
		}
	}
}
/* 
作者:徐晨瀚
輸入: n
輸出: 過關畫面 
功能:輸出過關畫面後再呼叫welcometogame函數 
*/ 
void endgame(){//結束畫面 
	col(7);
 	system("cls");
 	col(6);
 	gotoxy(35,12);
 	cout<<"恭喜過關!!!";
 	Sleep(1000);
 	system("cls");
 	col(6);
 	gotoxy(35,12);
 	cout<<"請問是否繼續遊戲";
 	gotoxy(33,16);
 	col(12);
 	cout<<"1.否";
 	col(11);
 	gotoxy(49,16);
 	cout<<"2.是";
 	char n;
 	n=getch();
 	switch(n){
 		case '1':
 			system("cls");
	 		col(10);
	 		gotoxy(37,12);
	 		cout<<"感謝您的遊玩";
	 		
	 		Sleep(1000);
	 		system("cls");
	 		gotoxy(35,12);
	 		cout<<"期待您下次的到來";
	 		
	 		Sleep(1000);
	 		system("cls");
	 		col(10);
	 		gotoxy(49,12);
	 		cout<<"再會!!!!";
	 		Sleep(1000);
	 		system("cls");
	 		exit(0);
	 		break;
	 	case '2':
	 		system("cls");
	 		welcometogame();
	 		break;
	}
 	
}
/* 
作者:徐晨瀚
輸入: 無 
輸出: 無 
功能:判斷ch是否為!，是的話，將t清空並回傳1，否則只回傳0 
*/ 
int de_ch(){
	if(ch=='!'){
		t.clear();
		return 1;
	}
	else{
		return 0;
	}
}
/* 
作者:徐晨瀚
輸入: 無 
輸出: 無 
功能:判斷pass是否等於small，是的話，將t清空並回傳1，否則只回傳0 
*/ 
int de_end(){
	if(pass==small){
		t.clear();
		return 1;
	}
	else{
		return 0;
	}
}
