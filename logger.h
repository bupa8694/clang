//
// Created by zebra on 1/11/23.
//

#ifndef CLANG_LOGGER_H
#define CLANG_LOGGER_H


#include <memory>
#include<type_traits>

enum STATUS{
    FAILURE=0,
    SUCCESS=1
};

struct Console{

    STATUS writer(const std::string& message)
    {
        data+=_tag + message+"\n";
        return STATUS::SUCCESS;
    }
    std::string getData()
    {
        return data;
    }
    const std::string _tag = "[CONSOLE LOG]";
    std::string data= "";
    int status = 0;
};
struct File{

    STATUS writer(const std::string& message)
    {
        data+=_tag+message+"\n";
       return STATUS::SUCCESS;
    }
    std::string getData()
    {
        return data;
    }
    const std::string _tag = "[FILE LOG]";
    std::string data= "";
    int status = 0;
};
struct QTGUI{

    STATUS writer(const std::string& message)
    {
        data+=_tag+message+"\n";
        return STATUS::SUCCESS;
    }
    std::string getData()
    {
        return data;
    }
    const std::string _tag = "[QTGUI LOG]";
    std::string data= "";
    int status = 0;
};
class logger {
public:
    logger();
    logger(const logger& other) = delete;
    ~logger();

    template<class T>
    STATUS writer(const std::string& message){
        if(std::is_same<T,Console>::value){
             return m_cons->writer( message);
        }
        if(std::is_same<T,File>::value){
            return m_file->writer( message);
        }
        if(std::is_same<T,QTGUI>::value)
        {
            return m_qtgui->writer( message);
        }
        return STATUS::FAILURE;
    }

    template<class T>
    std::string getData() const{
        if(std::is_same<Console,T>::value){
            return m_cons->getData();
        }
        if(std::is_same<File, T>::value){
            return m_file->getData();
        }
        if(std::is_same<QTGUI, T>::value)
        {
            return m_qtgui->getData();
        }
        return "";
    }

private :
    std::shared_ptr<Console> m_cons = std::make_shared<Console>();
    std::shared_ptr<File> m_file= std::make_shared<File>();
    // introducing new custom attribute
    std::unique_ptr<QTGUI> m_qtgui = std::make_unique<QTGUI>();

};

logger&& get_logger();
#endif //CLANG_LOGGER_H
