//#include <string>
//#include <vector>
//#include <map>
//#include <assert.h>
//#include <string.h>
//
//using namespace std;
//
//typedef enum cmd
//{
//	enter,
//	leave,
//	change
//}cmd;
//
//typedef struct commander
//{
//	cmd command;
//	string id;
//	string nickname;
//}user;
//
//
//
//commander getCommand(const string& str)
//{
//	auto chary = str.c_str();
//	char* tok = strtok(const_cast<char*>(chary), " ");
//	auto  u = commander();
//	if (tok != nullptr)
//	{
//		if (strcmp(tok, "Enter") == 0)
//			u.command = enter;
//		else if (strcmp(tok, "Leave") == 0)
//			u.command = leave;
//		else if (strcmp(tok, "Change") == 0)
//			u.command = change;
//		else
//			assert(0);
//	}
//
//	tok = strtok(nullptr, " ");
//	if (tok != nullptr)
//	{
//		u.id = string(tok);
//	}
//
//	tok = strtok(nullptr , " ");
//	if (tok != nullptr)
//	{
//		u.nickname = string(tok);
//	}
//
//	return u;
//}
//
//string getanswer(const cmd _cmd, string nickname)
//{
//	string answer;
//	answer.reserve(100);
//
//	answer.append(nickname);
//	switch (_cmd)
//	{
//	case enter:
//		answer.append("님이 들어왔습니다.");
//		break;
//	case leave:
//		answer.append("님이 나갔습니다.");
//		break;
//	}
//
//	answer.shrink_to_fit();
//	return answer;
//}
//
//vector<string> solution(vector<string> record) {
//	vector<string> answer;
//	vector<commander> commands;
//	commands.reserve(record.size());
//	answer.reserve(record.size());
//
//	map<string,commander> usermap;
//
//	for (string str : record)
//	{
//		auto _cmd = getCommand(str);
//		switch(_cmd.command)
//		{
//		case change:
//			usermap.erase(_cmd.id);
//			usermap.insert(make_pair(_cmd.id, _cmd));
//			break;
//		case enter:
//			if (usermap.count(_cmd.id))
//				usermap.erase(_cmd.id);
//			usermap.insert(make_pair(_cmd.id, _cmd));
//			commands.emplace_back(_cmd);
//			break;
//		case leave:
//			commands.emplace_back(_cmd);
//			break;
//		default:
//			assert(0);
//		}
//	}
//
//	for (auto u : commands)
//	{
//		answer.emplace_back(getanswer(u.command, usermap.at(u.id).nickname));
//	}
//
//	return answer;
//}
//
//int main()
//{
//		vector<string> s;
//	s.push_back("Enter uid1234 Muzi");
//	s.push_back("Enter uid4567 Prodo");
//	s.push_back("Leave uid1234");
//	s.push_back("Enter uid1234 Prodo");
//	s.push_back("Change uid4567 Ryan");
//	solution(s);
//}