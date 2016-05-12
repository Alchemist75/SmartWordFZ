#include "Dictionary.h"
#include "Word.h"
#include <fstream>
#include <iostream>
#include <string>

Dictionary::Dictionary() { }

Dictionary::~Dictionary() { }

bool Dictionary::importDict(const std::string& filename) {
    //读入文件
    std::ifstream fin(filename.c_str());
    if(!fin) {
		std::cerr << "File can not open!" << std::endl;
		return false;
	}
    //导入单词
    
    int isAdded = 0;
    int isExisted = 0;
    std::string line = "";
    while(getline(fin, line)) {
		std::string word;
		std::string meaning;
		int len = line.length();
        for (int i = 0; i < len; ++i) {
            if(line[i] == '|') {
				word = line.substr(0, i);
				meaning = line.substr(i+1, len);
                break;
                //std::cout << word << " " << meaning << std::endl;
			}
		}
        bool add_success = Dictionary::addWord(word, meaning);
        if(add_success) {
            isAdded ++;
        }
        else {
            isExisted ++;
        }
	}
    std::cerr << "成功导入" << isAdded << "个单词，其中" << isExisted << "个单词重复！" << std::endl;
	return true;
}

std::set<Word>::iterator Dictionary::searchWordWithIter(const std::string &word) const {
    const Word search_word(word);
    std::set<Word>::iterator iter;
    iter = Dict.find(search_word);
    return iter;
}

bool Dictionary::isExisted(const std::string &word) {
    std::set<Word>::iterator iter;
    iter = searchWordWithIter(word);
    if(iter != Dict.end()) {
        return true;
    }
    else {
        return false;
    }
}

Word Dictionary::getSearchWord(const std::string& word) const {
    //利用set查找，重载比较运算符
	std::set<Word>::iterator iter;
    iter = searchWordWithIter(word);
    //找到了
    if(iter != Dict.end()) {
        return *iter;
    }
    //没找到
    else {
        //std::cerr << "Can not find the word!" << std::endl;
        return Word("NULL", "Can't Find the Word!");
    }
}

bool Dictionary::addWord(const std::string &word, const std::string &meaning)
{
    //查重
    if (isExisted(word)) {
        std::cerr << "Word already exists!" << std::endl;
        return false;
    }
    //添加
    else {
        Word add_word(word, meaning);
        Dict.insert(add_word);
        return true;
    }
}

//searchword返回值得是指针，反正得是可以修改的东西！！！！
bool Dictionary::addExample(const std::string &word, const std::string &example, const std::string &translation) {
    std::set<Word>::iterator iter = Dictionary::searchWordWithIter(word);

    if(iter == Dict.end()) {
        std::cerr << "Word not exists!" << std::endl;
        return false;
    }
    else {
        Word search_word = *iter;
        search_word.addExample(example, translation);
        Dict.erase(iter);
        Dict.insert(search_word);
        return true;
    }
}

bool Dictionary::modifyWord(const std::string &word, const std::string &new_meaning, const int &new_degree) {
    std::set<Word>::iterator iter = Dictionary::searchWordWithIter(word);

    if(iter == Dict.end()) {
        std::cerr << "Word doesn't exist!" << std::endl;
        return false;
    }
    else {
        Word search_word = *iter;
        search_word.modifyWord(word, new_meaning);
        search_word.setDegree(new_degree);
        Dict.erase(iter);
        Dict.insert(search_word);
        return true;
    }
}

std::string Dictionary::getMeaning(const std::string &word) const {
    const Word &search_word = Dictionary::getSearchWord(word);
    return search_word.getMeaning();
}

std::string Dictionary::getExample(const std::string &word, const int &pos) const {
    const Word &search_word = Dictionary::getSearchWord(word);
    return search_word.getExample(pos);
}

std::string Dictionary::getTranslation(const std::string &word, const int &pos) const {
    const Word &search_word = Dictionary::getSearchWord(word);
    return search_word.getTranslation(pos);
}

int Dictionary::getNumOfExample(const std::string &word) const {
    const Word &search_word = Dictionary::getSearchWord(word);
    return search_word.getNumOfExample();
}

std::string Dictionary::getAllExample(const std::string &word) const {
    const Word &search_word = Dictionary::getSearchWord(word);
    int num = search_word.getNumOfExample();
    //std::cerr << num << std::endl;

    std::string output = "";
    for (int i = 0; i < num; i++) {
        output = output + search_word.getExample(i) + '\n';
        output = output + search_word.getTranslation(i) + '\n';

        output = output + '\n';
        std::cerr << output << std::endl;
    }
    return output;
}




