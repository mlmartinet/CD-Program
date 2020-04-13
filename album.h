#pragma once

#include <string>
#include <iostream>
#include <fstream>


class Album {
	friend std::ostream& operator<<(std::ostream& output, const Album& a);		//Output Object
	friend std::ofstream& operator<<(std::ofstream& output, const Album& a);	//Output Object to file	
	friend std::ifstream& operator>>(std::ifstream& input, Album& a);			//Input from file

public:
	std::string m_Name = "";
	std::string m_Artist = "";
	std::string m_Year;	
};

std::ostream& operator<<(std::ostream& output, const Album& a) {
	output << a.m_Name << std::endl;
	output << "   " << a.m_Artist << std::endl;
	output << "   " << a.m_Year << std::endl;
	return output;
}

std::ofstream& operator<<(std::ofstream& output, const Album& a) {
	output << a.m_Name << std::endl;
	output << a.m_Artist << std::endl;
	output << a.m_Year << std::endl;
	return output;
}

std::ifstream& operator>>(std::ifstream& input, Album& a) {
	getline(input,a.m_Name);
	getline(input, a.m_Artist);
	getline(input, a.m_Year);
	return input;
}