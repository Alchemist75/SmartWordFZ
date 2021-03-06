#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include "Word.h"
#include <set>

class Dictionary
{
private:
    //数据
	std::set<Word> Dict;
public:
    //构造与析构
	Dictionary();
	virtual ~Dictionary();
    //接口函数
    std::string getMeaning(const std::string &word) const;
    std::string getExample(const std::string &word, const int &pos) const;
    std::string getTranslation(const std::string &word, const int &pos) const;
    int getNumOfExample(const std::string &word) const;
    std::string getAllExample(const std::string &word) const;
    std::set<Word>::iterator searchWordWithIter(const std::string &word) const;
    Word getSearchWord(const std::string &word) const;
    //功能函数
    bool importDict(const std::string &filename);
    bool isExisted(const std::string &word);
    bool addWord(const std::string &word, const std::string &meaning);
    bool addExample(const std::string &word, const std::string &example, const std::string &translation);
    bool modifyWord(const std::string &word, const std::string &new_meaning, const int &new_degree = 0);
};

#endif
