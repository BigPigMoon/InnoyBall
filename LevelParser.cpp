#include "LevelParser.h"

std::vector<std::vector<char>> levelParse(std::string fileName)
{
	// file read
	std::vector<std::vector<char>> level;
	std::ifstream file("Levels/" + fileName);
	std::string line;

	if (file.is_open())
	{
		int y = 0;
		while (getline(file, line))
		{
			std::vector<char> floor;
			level.push_back(floor);
			for (int x = 0; x < line.size(); ++x) { level[y].push_back(line[x]); }
			y++;
		}
	}
	file.close();
	return level;
}

void dialogParse(std::string fileName, std::string personName)
{
	using namespace tinyxml2;
	using std::string;

	fileName = "Dialogs/" + fileName;

	XMLDocument doc;
	doc.LoadFile(fileName.c_str());

	XMLElement* data = doc.FirstChildElement("data");
	if (data == nullptr)
	{
		std::cout << "data not found!" << std::endl;
		return;
	}

	XMLElement* person = data->FirstChildElement("person");

	std::string thisPersonName = person->FindAttribute("name")->Value();
	while (thisPersonName != personName)
	{
		person = person->NextSiblingElement("person");
		thisPersonName = person->FindAttribute("name")->Value();
	}
	
	XMLElement* dialog = person->FirstChildElement("dialog");
	int dialogID = dialog->FindAttribute("id")->IntValue();
	while (dialogID != 0)
	{
		dialog = dialog->NextSiblingElement("dialog");
		dialogID = dialog->FindAttribute("id")->IntValue();
	}

	string repl = dialog->FindAttribute("title")->Value();
	
	std::cout << repl << std::endl;
	std::cout << (int)repl.at(1) << std::endl;
	std::cout << (int)'р' << std::endl;

	terminal_printf(15, 30, repl.c_str());

	// выводим варианты ответа и ждем ввод пльзователя
	// печатаем диалог и показываем варианты ответа, ждем ввод пользователя
	// и так до победного пока не найдем конец.
}
