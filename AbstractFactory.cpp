//
// Created by Kirill Zharenkov on 02.01.2017.

#include<string>
#include<vector>
#include <iostream>
#include <memory>


class AbstractBook{

protected:
    std::string author;
    std::string title;
    AbstractBook(const char* author, const char* title): author(author), title(title){}
public:

    virtual const std::string& getAuthor()const = 0;
    virtual const std::string& getTitle()const = 0;
};


class AbstractBookFactory{
public:
    AbstractBookFactory(){}
    virtual std::shared_ptr<AbstractBook> makeBook()const = 0;
};


class CppBook: public AbstractBook{
public:
    CppBook(const char* author, const char* title): AbstractBook(author, title){}
    const std::string& getAuthor() const  { return author;}
    const std::string& getTitle() const {return title;}
};

class SwiftBook: public AbstractBook{
public:
    SwiftBook(const char* author, const char* title): AbstractBook(author, title){}
    const std::string& getAuthor()const override { return author;}
    const std::string& getTitle()const override {return title;}
};

class CppFactory: public AbstractBookFactory{
public:
    CppFactory(){}
    std::shared_ptr<AbstractBook> makeBook() const override {
        return  std::make_shared<CppBook>("Straustrup","How to C++17");
    }
};

class SwiftFactory: public AbstractBookFactory{
public:
    SwiftFactory(){}
    std::shared_ptr<AbstractBook> makeBook() const override {
        return std::make_shared<SwiftBook>("Cris Lattner","Pro Swift 3");
    }
};

void show (const std::shared_ptr<AbstractBookFactory> factory){
    auto book = factory->makeBook();
    std::cout << book->getAuthor()<< " : "<< book->getTitle() <<std::endl;

}

int main(){
    std::shared_ptr<AbstractBookFactory> factory =  std::make_shared<CppFactory>();
    show(factory);
    factory.reset();
    factory  = std::make_shared<SwiftFactory>();
    show(factory);
}
