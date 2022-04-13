/*
输入任意一种物质，要求输出其每种元素的数量。
比如
输入 CaCO3，其组成分别为 Ca：1，C：1，O：3，输出 Ca1C1O3
输入 Fe2(SO4)3，其组成分别为 Fe：2，S：3，O：12，输出 Fe2S3O12
（注意：元素名称首字母大写，剩余字母都小写；括号括起来表示括号中的结构作
为整体出现多少次）
*/

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	string GetRet(const string& str) {
		if (str.size() <= 1) {
			return str;
		}
		return Transform(str);
	}

private:
	string Transform(const string& str) {
		stack<string> main_stk;           // 主栈
		stack<string> assist_stk;         // 辅助栈
		unordered_map<string, int> umap;  // 记录每种元素出现多少次
		int str_size = str.size();
		int left = 0, right = 0;
		int count = 0;  // 临时记录某种元素出现的次数
		while (right < str_size) {
			// 1.如果 right 所指向的位置是一个 "("
			if (str[right] == '(') {
				main_stk.push(str.substr(left, right - left));
				// 修改 left 的值
				left = right;
			}
			// 2.如果 right 所指向的是一个小写字母
			else if (str[right] >= 97 && str[right] <= 122) {
				right++;
			}
			// 3.如果 right 所指向的是一个大写字母
			else if (str[right] >= 65 && str[right] <= 90) {
				// 3.1 如果 left 与 right 在同一位置
				if (left == right) {
					right++;
					continue;
				}
				else {
					// 3.2 left 与 right 不指向同一位置
					main_stk.push(str.substr(left, right - left));
					// 修改 left 的值
					left = right;
				}
				if (count == 0) {
					umap[main_stk.top()] = 1;
				}
				else {
					umap[main_stk.top()] = count;
				}
				count = 0;
			}
			// 4.如果 right 所指向的是一个数字
			else if (str[right] >= 48 && str[right] <= 57) {
				main_stk.push(str.substr(left, right - left));
				// 直到找到不为数字的位置为止
				while (str[right] >= 48 && str[right] <= 57) {
					count += (count * 10) + str[right] - '0';
					right++;
				}
				// umap 没有加入过此数据
				if (umap.find(main_stk.top()) == umap.end()) {
					umap[main_stk.top()] = count;
				}
				count = 0;
				// 修改 left 的值
				left = right;
			}
			// 5. 如果 right 所指向的位置是 ')'
			else if (str[right] == ')') {
				main_stk.push(str.substr(left, right - left));
				int temp_index = right + 1;
				if (temp_index < str_size) {
					// 如果 ')' 后面是数字
					if (str[temp_index] >= 48 && str[temp_index] <= 57) {
						while (temp_index < str_size && str[temp_index] >= 48 && str[temp_index] <= 57) {
							count += (count * 10) + str[temp_index++] - '0';
						}
					}
				}
				// 找到与之对应的第一个 ')'
				while (main_stk.top() != "(") {
					assist_stk.push(main_stk.top());
					main_stk.pop();
				}
				// 弹出 "("
				main_stk.pop();
				// 记录新的次数
				if (count > 0) {
					if (umap.find(assist_stk.top()) == umap.end()) {
						umap[assist_stk.top()] = 1;
					}
					else {
						umap[assist_stk.top()] *= count;
					}
					main_stk.push(assist_stk.top());
					assist_stk.pop();
				}
				count = 0;
				right = temp_index;
				left = right;
				continue;
			}
		}
		// 处理最后一个元素
		if (str[str_size - 1] >= 65 && str[str_size - 1] <= 90 || str[str_size - 1] >= 48 && str[str_size - 1] <= 57) {
			string s = str.substr(left, right - left);
			main_stk.push(s);
			if (umap.find(s) != umap.end()) {
				umap[s] == 1;
			}
			umap[s] += 1;
		}
		// 拼接字符串
		string ret = "";
		// 反转 main_stk
		while (main_stk.size() > 0) {
			if (main_stk.top() == "") {
				main_stk.pop();
				continue;
			}
			assist_stk.push(main_stk.top());
			main_stk.pop();
		}
		// 拼接字符串
		while (assist_stk.size() > 0) {
			string temp_str = assist_stk.top();
			ret.append(temp_str);
			ret.append(to_string(umap[temp_str]));
			assist_stk.pop();
		}
		return ret;
	}
};

int main() {
	cout << "请输入任意一种物质：\n";
	string s;
	cin >> s;
	Solution solution;
	cout << solution.GetRet(s);
}