#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

long long cnt[15] = {0};
string out[1010]={"0"};
// typedef string myStr;

// int cnt[150] = {0};
// char pockers[15] = {0, 'A', 'K', 'Q', 'J', 'B', '9', '8', '7', '6', '5', '4', '3', '2', 'A'};

// int conv(myStr s)
// {
//     if ('2' <= s[0] <= '9')
//     {
//         return (s[0] - '0');
//     }
//     if (s[0] == 'B' || s[0] == '1')
//     {
//         return 10;
//     }
//     else
//     {
//         if (s[0] == 'J')
//             return 11;
//         if (s[0] == 'Q')
//             return 12;
//         if (s[0] == 'K')
//             return 13;
//         if (s[0] == 'A')
//             return 14;
//     }
// }

// bool operator<(const myStr &lhs, const myStr &rhs)
// {
//     return conv(lhs) < conv(rhs);
// }

// struct cmp
// {
//     int conv(myStr s)
//     {
//         if ('2' <= s[0] <= '9')
//         {
//             return (s[0] - '0');
//         }
//         if (s[0] == 'B' || s[0] == '1')
//         {
//             return 10;
//         }
//         else
//         {
//             if (s[0] == 'J')
//                 return 11;
//             if (s[0] == 'Q')
//                 return 12;
//             if (s[0] == 'K')
//                 return 13;
//             if (s[0] == 'A')
//                 return 14;
//         }
//     }
//     bool operator()(const myStr &lhs, const myStr &rhs)
//     {
//         return conv(lhs) < conv(rhs);
//     }
// };

// priority_queue<myStr, vector<myStr>,cmp> pq;

// myStr st = "";

// bool judge_four(string &str)
// {
//     st = "";
//     for (int i = 1; i < 15; i++)
//     {
//         st = "";
//         if (cnt[pockers[i]] == 4)
//         {
//             if (pockers[i] != 'B')
//             {

//                 st = pockers[i];
//                 pq.push(st);
//                 st = pockers[i];
//                 pq.push(st);
//                 st = pockers[i];
//                 pq.push(st);
//                 st = pockers[i];
//                 pq.push(st);
//             }
//             else
//             {
//                 for (int i = 0; i < 4; i++)
//                 {
//                     st = "10";
//                     pq.push(st);
//                 }
//             }
//             cnt[pockers[i]] = 0;
//             for (int j = 1; j < 15; j++)
//             {
//                 st = "";
//                 if (cnt[pockers[j]] != 0)
//                 {
//                     if (pockers[j] != 'B')
//                         st = pockers[j];
//                     else
//                         st = "10";
//                     pq.push(st);
//                     break;
//                 }
//             }
//             cnt[pockers[i]] = 4;
//             return true;
//         }
//     }
//     while (!pq.empty())
//         pq.pop();
//     return false;
// }

// bool judge_gourd(string &str)
// {
//     st = "";
//     for (int i = 1; i < 15; i++)
//     {
//         st = "";
//         if (cnt[pockers[i]] == 3)
//         {
//             if (pockers[i] != 'B')
//             {
//                 st = pockers[i];
//                 pq.push(st);
//                 st = pockers[i];
//                 pq.push(st);
//                 st = pockers[i];
//                 pq.push(st);
//             }
//             else
//             {
//                 st = "10 10 10 ";
//                 pq.push(st);
//             }
//             cnt[pockers[i]] = 0;
//             bool flag = false;
//             for (int j = 1; j < 15; j++)
//             {
//                 st = "";
//                 if (cnt[pockers[j]] >= 2)
//                 {
//                     if (pockers[j] != 'B')
//                     {
//                         st = pockers[j];
//                         pq.push(st);
//                         st = pockers[j];
//                         pq.push(st);
//                     }
//                     else
//                     {
//                         st = "10";
//                         pq.push(st);
//                         st = "10";
//                         pq.push(st);
//                     }
//                     flag = true;
//                     break;
//                 }
//             }
//             cnt[pockers[i]] = 3;
//             if (flag == true)
//                 return true;
//             else
//                 while (!pq.empty())
//                     pq.pop();
//             continue;
//         }
//     }
//     while (!pq.empty())
//         pq.pop();
//     return false;
// }

// bool judge_continuous(string &str)
// {
//     st = "";
//     for (int i = 1; i < 11; i++)
//     {
//         st = "";
//         if (cnt[pockers[i]] != 0 && cnt[pockers[i + 1]] != 0 && cnt[pockers[i + 2]] != 0 && cnt[pockers[i + 3]] != 0 && cnt[pockers[i + 4]] != 0)
//         {
//             for (int j = i; j < i + 4; j++)
//             {
//                 st = "";
//                 if (pockers[j] != 'B')
//                     cout << pockers[j] << ' ';
//                 else
//                     cout << "10 ";
//             }
//             if (pockers[i + 4] != 'B')
//                 cout << pockers[i + 4];
//             else
//                 cout << "10";
//             return true;
//         }
//     }
//     return false;
// }

// bool judge_three(string &str)
// {
//     st = "";
//     for (int i = 1; i < 15; i++)
//     {
//         st = "";
//         if (cnt[pockers[i]] == 3)
//         {
//             if (pockers[i] != 'B')
//             {
//                 st = pockers[i];
//                 pq.push(st);
//                 st = pockers[i];
//                 pq.push(st);
//                 st = pockers[i];
//                 pq.push(st);
//             }
//             else
//             {
//                 st = "10";
//                 pq.push(st);
//                 pq.push(st);
//                 pq.push(st);
//             }
//             cnt[pockers[i]] = 0;
//             bool flag = false;
//             int tp = 0;
//             for (int j = 1; j < 15 && tp < 3; j++)
//             {
//                 st = "";
//                 if (cnt[pockers[j]] != 0)
//                 {
//                     if (pockers[j] != 'B')
//                     {
//                         st = pockers[j];
//                         pq.push(st);
//                     }
//                     else
//                     {
//                         st = "10";
//                         pq.push(st);
//                     }
//                     tp++;
//                 }
//                 if (tp == 2)
//                 {
//                     flag = true;
//                     break;
//                 }
//             }
//             cnt[pockers[i]] = 3;
//             if (flag == true)
//                 return true;
//             else
//                 while (!pq.empty())
//                     pq.pop();
//             continue;
//         }
//     }
//     while (!pq.empty())
//         pq.pop();
//     return false;
// }

// bool judge_doublePair(string &str)
// {
//     st = "";
//     for (int i = 1; i < 15; i++)
//     {
//         st = "";
//         if (cnt[pockers[i]] == 2)
//         {
//             if (pockers[i] != 'B')
//             {
//                 st = pockers[i];
//                 pq.push(st);
//                 st = pockers[i];
//                 pq.push(st);
//             }
//             else
//             {
//                 st = "10";
//                 pq.push(st);
//             }
//             cnt[pockers[i]] = 0;
//             bool flag = false;
//             for (int j = 1; j < 15; j++)
//             {
//                 st = "";
//                 if (cnt[pockers[j]] == 2)
//                 {
//                     if (pockers[j] != 'B')
//                     {
//                         st = pockers[j];
//                         pq.push(st);
//                         st = pockers[j];
//                         pq.push(st);
//                     }
//                     else
//                     {
//                         st = "10";
//                         pq.push(st);
//                     }
//                     cnt[pockers[j]] = 0;
//                     for (int out = 1; out < 15; out++)
//                     {
//                         st = "";
//                         if (cnt[pockers[out]] != 0)
//                         {
//                             if (pockers[out] != 'B')
//                                 st = pockers[out];
//                             else
//                                 st = "10";
//                             pq.push(st);
//                             flag = true;
//                             break;
//                         }
//                     }
//                     cnt[pockers[j]] = 2;
//                     if (flag == true)
//                         break;
//                 }
//             }
//             cnt[pockers[i]] = 2;
//             if (flag == true)
//                 return true;
//             else
//                 while (!pq.empty())
//                     pq.pop();
//             continue;
//         }
//     }
//     while (!pq.empty())
//         pq.pop();
//     return false;
// }

// bool judge_pair(string &str)
// {
//     st = "";
//     for (int i = 1; i < 15; i++)
//     {
//         st = "";
//         if (cnt[pockers[i]] == 2)
//         {
//             if (pockers[i] != 'B')
//             {
//                 st = pockers[i];
//                 pq.push(st);
//                 st = pockers[i];
//                 pq.push(st);
//             }
//             else
//             {
//                 st = "10";
//                 pq.push(st);
//                 pq.push(st);
//             }
//             cnt[pockers[i]] = 0;
//             bool flag = false;
//             int tp = 0;
//             for (int j = 1; j < 15 && tp < 4; j++)
//             {
//                 st = "";
//                 if (cnt[pockers[j]] != 0)
//                 {
//                     if (pockers[j] != 'B')
//                     {
//                         st = pockers[j];
//                         pq.push(st);
//                     }
//                     else
//                     {
//                         st = (tp < 3 ? "10" : "10");
//                         pq.push(st);
//                     }
//                     tp++;
//                 }
//                 if (tp == 3)
//                 {
//                     flag = true;
//                     break;
//                 }
//             }
//             cnt[pockers[i]] = 2;
//             if (flag == true)
//                 return true;
//             else
//                 while (!pq.empty())
//                     pq.pop();
//             continue;
//         }
//     }
//     while (!pq.empty())
//         pq.pop();
//     return false;
// }

// void judge_biggest(string &str)
// {
//     st = "";
//     int tmp = 0;
//     for (int i = 1; i < 15 && tmp < 5; i++)
//     {
//         st = "";
//         if (cnt[pockers[i]] != 0)
//         {
//             tmp++;
//             if (pockers[i] != 'B')
//             {
//                 cout << pockers[i] << (tmp == 5 ? "" : " ");
//             }
//             else
//             {
//                 cout << (tmp == 5 ? "10" : "10 ");
//             }
//         }
//     }
// }

string conv(int num)
{
    string s;
    if (num == 14)
        s = "A";
    if (num == 13)
        s = "K";
    if (num == 12)
        s = "Q";
    if (num == 11)
        s = "J";
    if (num == 10)
        s = "10";
    if (num == 9)
        s = "9";
    if (num == 8)
        s = "8";
    if (num == 7)
        s = "7";
    if (num == 6)
        s = "6";
    if (num == 5)
        s = "5";
    if (num == 4)
        s = "4";
    if (num == 3)
        s = "3";
    if (num == 2)
        s = "2";
    if (num == 1)
        s = "A";
    return s;
}

long long limit01,limit02,limit03,temp=0;

int main()
{
    for (int i = 1; i <= 7; i++)
    {
        string str;
        cin >> str;
        if (str == "A")
        {
            cnt[1]++;
            cnt[14]++;
        }
        if (str == "K")
            cnt[13]++;
        if (str == "Q")
            cnt[12]++;
        if (str == "J")
            cnt[11]++;
        if (str == "10")
            cnt[10]++;
        if (str == "9")
            cnt[9]++;
        if (str == "8")
            cnt[8]++;
        if (str == "7")
            cnt[7]++;
        if (str == "6")
            cnt[6]++;
        if (str == "5")
            cnt[5]++;
        if (str == "4")
            cnt[4]++;
        if (str == "3")
            cnt[3]++;
        if (str == "2")
            cnt[2]++;
    }
    // st = "";
    // string str;
    // for (int i = 0; i < 7; i++)
    // {
    //     char tmpch;
    //     cin >> tmpch;
    //     if (tmpch != '1' && tmpch != '\n')
    //     {
    //         str = str + tmpch;
    //         cnt[tmpch]++;
    //     }
    //     else if (tmpch == '1')
    //     {
    //         cin >> tmpch;
    //         if (tmpch == '0')
    //         {
    //             str += 'B';
    //             cnt['B']++;
    //         }
    //     }
    //     else if (tmpch == '\n')
    //     {
    //         i -= 1;
    //     }
    // }
    // if (!judge_four(str))
    // {
    //     st = "";
    //     if (!judge_gourd(str))
    //     {
    //         st = "";
    //         if (!judge_continuous(str))
    //         {
    //             st = "";
    //             if (!judge_three(str))
    //             {
    //                 st = "";
    //                 if (!judge_doublePair(str))
    //                 {
    //                     st = "";
    //                     if (!judge_pair(str))
    //                     {
    //                         st = "";
    //                         judge_biggest(str);
    //                         return 0;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    // while (1 < pq.size())
    // {
    //     myStr myst = pq.top();
    //     cout << myst << ' ';
    //     pq.pop();
    // }
    // myStr myst = pq.top();
    // cout << myst;
    // pq.pop();
    // return 0;
    for (int i=14;i>=2;i--) {
		if(cnt[i]==4){
			string z=conv(i);
			out[1]=z;
			out[2]=z;
			out[3]=z;
			out[4]=z;
			cnt[i]=0;
			for (int j=14;j>=2;j--)
				if(cnt[j]!=0&&j>limit01)
				limit01=j;
			if(limit01>i){
				out[5]=conv(limit01);
				cout<<out[5]<<" "<<out[4]<<" "<<out[3]<<" "<<out[2]<<" "<<out[1]<<endl;
				return 0;
			}
			if(limit01<i){
				out[0]=conv(limit01);
				cout<<out[4]<<" "<<out[3]<<" "<<out[2]<<" "<<out[1]<<" "<<out[0]<<endl;
				return 0;
			}
		}
	}//四条 
	for (int i=14;i>=2;i--) {
		if(cnt[i]==3) {
			string z=conv(i);
			out[1]=z;
			out[2]=z;
			out[3]=z;
			for (int j=14;j>=2;j--)
				if(cnt[j]>=2&&j!=i&&j>limit01)
				limit01=j;
			if(limit01==0)
			break;
			out[4]=conv(limit01);
			out[5]=conv(limit01);
			if(limit01>i) {
				
				cout<<out[5]<<" "<<out[4]<<" "<<out[3]<<" "<<out[2]<<" "<<out[1]<<endl;
				return 0;
			}
			else {
				cout<<out[1]<<" "<<out[2]<<" "<<out[3]<<" "<<out[4]<<" "<<out[5]<<endl;
				return 0;
			}
		}
	}//葫芦 
	for (int i=14;i>=1;i--) {
		if(cnt[i]>=1&&cnt[i-1]>=1&&cnt[i-2]>=1&&cnt[i-3]>=1&&cnt[i-4]>=1) {
			out[1]=conv(i);
			out[2]=conv(i-1);
			out[3]=conv(i-2);
			out[4]=conv(i-3);
			out[5]=conv(i-4);
			cout<<out[1]<<" "<<out[2]<<" "<<out[3]<<" "<<out[4]<<" "<<out[5]<<endl;
			return 0;
		}
	}// 顺子 
	for (int i=14;i>=2;i--) {
		if(cnt[i]==3) {
			string z=conv(i);
			out[1]=z;
			out[2]=z;
			out[3]=z;
			cnt[i]=0;
			for (int j=14;j>=2;j--)
				if(cnt[j]!=0&&j>limit01)
				limit01=j;
			cnt[limit01]=0;
			for (int j=14;j>=2;j--)
				if(cnt[j]!=0&&j>limit02)
				limit02=j;
			cnt[limit02]=0;
			out[4]=conv(limit01);
			out[5]=conv(limit02);
			if(limit02>i){
				cout<<out[4]<<" "<<out[5]<<" "<<out[3]<<" "<<out[2]<<" "<<out[1]<<endl;
				return 0;
			}
			if(limit02<i&&limit01>i) {
				cout<<out[4]<<" "<<out[3]<<" "<<out[2]<<" "<<out[1]<<" "<<out[5]<<endl;
				return 0;
			}
			if(limit01<i) {
				cout<<out[1]<<" "<<out[2]<<" "<<out[3]<<" "<<out[4]<<" "<<out[5]<<endl;
				return 0;
			}
		}
	}
	for (int i=14;i>=2;i--) {
		
		if(cnt[i]==2) {
			string z=conv(i);
			out[1]=z;
			out[2]=z;
			cnt[i]=0;
			limit01=0;
			for (int j=14;j>=2;j--){
				if(cnt[j]>=2&&j>limit01)
				limit01=j;
				
				}
				out[4]=conv(limit01);
				out[5]=conv(limit01);
				cnt[limit01]=0;
			if(limit01==0)
			break;
			for (int j=14;j>=2;j--)
				if(cnt[j]!=0&&j>limit02)
				limit02=j;
			out[3]=conv(limit02);
			if(limit01>limit02) {
				cout<<out[1]<<" "<<out[2]<<" "<<out[4]<<" "<<out[5]<<" "<<out[3]<<endl;
				return 0;
			}
			if(limit02>limit01&&limit02<i)	{
				cout<<out[1]<<" "<<out[2]<<" "<<out[3]<<" "<<out[4]<<" "<<out[5]<<endl;
				return 0;
			}
			if(limit02>i) {
				cout<<out[3]<<" "<<out[1]<<" "<<out[2]<<" "<<out[4]<<" "<<out[5]<<endl;
				return 0;
			}
		}
	}//两对 
	for (int i=14;i>=2;i--) {
		if(cnt[i]==2) {
			string z=conv(i);
			out[1]=z;
			out[2]=z;
			cnt[i]=0;
			temp=2;
			for (int j=14;i>=2;j--){
				if(cnt[j]!=0&&j>limit01)
				limit01=j;
				if(limit01>i){
					out[3]=conv(limit01);
				}
			}
			for (int j=limit01;j>=2;j--){
				if(cnt[j]!=0&&j>limit02)
				limit02=j;
				if(limit02>i){
					out[4]=conv(limit02);
				}
			}
			for (int j=limit03;j>=2;j--){
				if(cnt[j]!=0&&j>limit03)
				limit03=j;
				if(limit03>i){
					out[5]=conv(limit03);
				}
			}
			if(limit01<i) {
				cout<<out[1]<<" "<<out[2]<<" "<<out[3]<<" "<<out[4]<<" "<<out[5]<<endl;
				return 0;
			}
			if(limit01>i&&limit02<i) {
				cout<<out[3]<<" "<<out[1]<<" "<<out[2]<<" "<<out[4]<<" "<<out[5]<<endl;
				return 0;
			}
			if(limit02>i&&limit03<i)	{
				cout<<out[3]<<" "<<out[4]<<" "<<out[1]<<" "<<out[2]<<" "<<out[5]<<endl;
				return 0;
			}
			if(limit03>i) {
				cout<<out[3]<<" "<<out[4]<<" "<<out[5]<<" "<<out[1]<<" "<<out[2]<<endl;
				return 0;
			}
		}
	}//一对 
	for (int i=14;i>=2;i--) {
		if(cnt[i]!=0) {
			temp++;
			out[temp]=conv(i);
		}
		if(temp==5) {
			cout<<out[1]<<" "<<out[2]<<" "<<out[3]<<" "<<out[4]<<" "<<out[5]<<endl;
			return 0;
		}
	}// 高牌 
	return 0;
}