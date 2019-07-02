// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
#include <string>
#include <iterator>
#include <stdio.h>
using namespace std;
void Show(std::vector<std::string> &v)
{
	for(int i=0; i<v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n" << endl;
}
vector<string>split(string str, string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str+=pattern;//拓展字符字串以方便操作
	int size=str.size();

	for(int i=0; i<size; i++)
	{
		pos=str.find(pattern,i);
		if(pos<size)
		{
			std::string s=str.substr(i,pos-i);
			result.push_back(s);
			i=pos+pattern.size()-1;
		}
	}
	return result;
}
int main () {
	std::vector<std::string> VCmdstring;
	std::vector<std::string> VCmdPacket;
	string VCmdpush;
	string str1 = "# 1 3 5 -90 0 0 * # 2 4 6 -90 0 0 * # 5 4 8 -90 0 0 * ";
	string str2 = "# -1 3 5 -90 0 0 * # -2 4 6 -90 0 0 * # -5 4 8 -90 0 0 * ";
	string str3 = "# 1 3 5 -90 0 0 * ";
	//test 0702 push_back & erase
	string str4 = "11111111";
	VCmdPacket.push_back(str3);
	VCmdPacket.push_back(str2);
	VCmdPacket.push_back(str1);
	cout << "Vcmdpacket[0] :"<<VCmdPacket[0]<<endl;
	cout << "Vcmdpacket[1] :"<<VCmdPacket[1]<<endl;
	cout << "Vcmdpacket[2] :"<<VCmdPacket[2]<<endl;

	VCmdPacket.erase(VCmdPacket.begin( ) );
	if (VCmdPacket.empty() == true)
	{
		cout << "empty"<<endl;
	}
	else
	{
		cout << "false"<<endl;
	}
	//test 0702
	VCmdpush.insert(VCmdpush.size(),str1);
	VCmdpush.insert(VCmdpush.size(),str2);
	//VCmdpush.insert(VCmdpush.size(),str3);
	//VCmdstring =split( ( str ), " " );
	///20190701 新增封包分割 處理黏包問題 與新增push_back 存取資料 與提取資料----

	VCmdstring =split( ( VCmdpush ), " " );
	//Show(VCmdstring);
	std::vector<std::string>::iterator VCmdTmp;
	for (int i=0;i<6;i++)
	{
		cout << " cycle: "<< i <<endl;
		VCmdTmp = find(VCmdstring.begin()+1, --(VCmdstring.end()), "#");

		if (VCmdTmp != VCmdstring.end())
		{
				int index = std::distance(VCmdstring.begin(),VCmdTmp);
				//int index = std::distance(VCmdTmp,VCmdstring.end());
				std::cout << "Element found in VCmdstring: " << index << '\n';

				std::vector<std::string> VCmdTmp1;
				VCmdTmp1.assign(VCmdstring.begin(),VCmdstring.begin()+index);
				cout <<"ans:"<<endl;
				//Show(VCmdTmp1);
				//VCmdstring = VCmdTmp1;

				std::vector<std::string> VCmdstring2;
				VCmdstring2 = VCmdTmp1;
				//填入動作指令
				Show(VCmdstring2);
				//------
				//cout <<"size:"<<VCmdstring.size()<<endl;
				//VCmdpush.erase(VCmdpush.begin(),VCmdpush.begin() + VCmdTmp1.size());
				//std::cout << VCmdpush << "\n";
				VCmdstring.erase(VCmdstring.begin(),VCmdstring.begin()+index);
		}
		else
		{
			std::cout << "Element not found in VCmdstring\n";
		}
	}
	/*VCmdpush.erase(VCmdpush.begin(),VCmdpush.begin() + VCmdTmp1.size());
	std::cout << VCmdpush << "\n";*/
	system("pause");
	return 0;
}
void Show_int(std::vector<int> &v)
{
	for(int i=0; i<v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n" << endl;
}
//int main()
//{
//	std::vector<int> v;
//
//	v.push_back(1);
//	v.push_back(3);
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(3);
//	v.push_back(2);
//
//	std::vector<int>::iterator i = std::find(v.begin(), v.end(), 2);
//	if (i != v.end())
//	{
//			int index = std::distance(v.begin(),i);
//			//int index = std::distance(VCmdTmp,VCmdstring.end());
//			std::cout << "Element found in VCmdstring: " << index << '\n';
//			std::vector<int> VCmdTmp1;
//			VCmdTmp1.assign(v.begin(),v.begin()+index);
//			Show_int(VCmdTmp1);
//		
//	}
//	//Show_int
//	system("pause");
//	return 0;
//}