#include<iostream>
#include<vector>
using namespace std;
class bottle{//製造瓶子 
	private:
		vector<char> cap;
		int flag;
	public:
		bottle();
		bottle(char);
		void set_color(int);
		void allpop();
		int get_flag();
		char get(int);
		void push(int,char);
        void pop(int);
		int size();
		void showbady(int);
		int samecolor();
};
namespace b{
	vector<bottle> t;//空瓶子
	vector<bottle> color;//大瓶子 
	bottle te,bt;//作為小瓶子和大瓶子的預設空間 
}
