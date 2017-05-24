#ifndef PARSER_H
#define PARSER_H

#include <QMainWindow>
#include <iostream>
#include <cstdlib>

struct DataElement
{
    std::string Name;
    std::string PageName;
    std::string Minrate;
    std::string HotelTypeId;
    std::string CurrencyCode;
    std::string City;
    std::string Address;
};

class Parser
{

public:
    Parser();

   // void WriteInFile(QString const );
    int MinrateToInteger(const std::string data);
    void SearchData(unsigned long *lsize, char *ptb);

    unsigned long lBufferSize;
    unsigned int objectCount, avarageMinrate, bottomLine, topLine;
    unsigned long sumMinrate;

    bool isOpenFile;

    char *buffer;
    FILE *pFile;
    size_t result;

    std::vector<DataElement> Elements;
    std::vector<float> Minrates;

private:
    static const std::string T_NAME, T_PAGE_NAME, T_MINRATE, T_CURRENCY_CODE, T_CONTRACTCHAIN_ID, T_HOTEL_TYPE_ID, T_CITY, T_ADDRESS;
    static std::string FileResult;

};

#endif // PARSER_H
