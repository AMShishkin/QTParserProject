#include "Parser.h"



const std::string Parser::T_NAME = "u'name'",
                  Parser::T_PAGE_NAME = "u'pagename'",
                  Parser::T_MINRATE = "u'minrate'",
                  Parser::T_CURRENCY_CODE =	"u'currencycode'",
                  Parser::T_CONTRACTCHAIN_ID = "u'contractchain_id'",
                  Parser::T_HOTEL_TYPE_ID =	"u'hoteltype_id'",
                  Parser::T_CITY = "u'city'",
                  Parser::T_ADDRESS = "u'address'";

Parser::Parser()
{
    lBufferSize = objectCount = avarageMinrate = bottomLine = topLine = sumMinrate = 0;
}

//void Parser::WriteInFile(QString const)
//{
   // for (int j = 0; j < str.length(); j++) Parser::FileReslt.write(&str[j], 1);
//}

int Parser::MinrateToInteger(const std::string data)
{
    std::string _valueString;
    for (unsigned int i = 0; i < data.length(); ++i) _valueString += data[i];
    return atoi(_valueString.c_str());
}

void Parser::SearchData(unsigned long* lsize, char* fileText)
{
    std::string _dataKey = "", _dataValue = "";
    DataElement _dataElement;

    bool _isMinrate = false,
         _isCurrencyCode = false,
         _isName = false,
         _isPageName = false,
         _isKey = false,
         _isHotelType = false,
         _isCity = false,
         _isAddress = false;

    // Search key
    // , - 0x2c | u - 0x75 | : - 0x3a | ' - 0x27 | } - 0x7d | { - 0x7b
    for (unsigned long i = 0; i < *lsize; ++i)
    {
        if (fileText[i] == 0x75 && fileText[i + 1] == 0x27) _isKey = true;
        else if (fileText[i] == 0x27 && (fileText[i + 1] == 0x3a || fileText[i + 1] == 0x2c))
        {
            _dataKey += 0x27;
            _isKey = false;

            if (_dataKey == Parser::T_MINRATE || _dataKey == Parser::T_CONTRACTCHAIN_ID)
            {
                if (_dataKey == Parser::T_MINRATE)
                {
                    _isMinrate = true;
                    i += 3;
                }
                else if (_dataKey == Parser::T_CONTRACTCHAIN_ID)
                {
                    Parser::objectCount++;
                    Parser::Elements.push_back(_dataElement);
                    _dataElement.CurrencyCode = _dataElement.HotelTypeId = _dataElement.Minrate = _dataElement.Name = _dataElement.City = "";
                }
            }
            else
            {
                if (_dataKey == Parser::T_CURRENCY_CODE || _dataKey == Parser::T_NAME || _dataKey == Parser::T_HOTEL_TYPE_ID
                    || _dataKey == Parser::T_CITY || _dataKey == Parser::T_ADDRESS || _dataKey == Parser::T_PAGE_NAME)
                {
                    i += 5;
                    if (_dataKey == Parser::T_CURRENCY_CODE) _isCurrencyCode = true;
                    else if (_dataKey == Parser::T_NAME) _isName = true;
                    else if (_dataKey == Parser::T_HOTEL_TYPE_ID) _isHotelType = true;
                    else if (_dataKey == Parser::T_CITY) _isCity = true;
                    else if (_dataKey == Parser::T_ADDRESS) _isAddress = true;
                    else if (_dataKey == Parser::T_PAGE_NAME) _isPageName = true;
                }
                else _dataKey = "";
            }
        }

        // Search value
        if (_isCurrencyCode || _isMinrate || _isName || _isHotelType || _isCity || _isAddress || _isPageName)
        {
            if (fileText[i] != 0x2c ) _dataValue += fileText[i];
            else
            {
                if (_isMinrate)
                {
                    _dataElement.Minrate = _dataValue;
                    Parser::sumMinrate += MinrateToInteger(_dataValue);

                    if (MinrateToInteger(_dataValue) > 0)
                    Parser::Minrates.push_back(MinrateToInteger(_dataValue));

                    _isMinrate = false;
                }
                else if (_isCurrencyCode || _isName || _isHotelType || _isCity || _isAddress || _isPageName)
                {
                     _dataValue[_dataValue.length() - 1] = ' ';

                     if (_isCurrencyCode) _dataElement.CurrencyCode = _dataValue;
                     else if (_isName) _dataElement.Name = _dataValue;
                     else if (_isHotelType) _dataElement.HotelTypeId = _dataValue;
                     else if (_isCity) _dataElement.City = _dataValue;
                     else if (_isAddress) _dataElement.Address = _dataValue;
                     else if (_isPageName) _dataElement.PageName = _dataValue;

                    _isCurrencyCode = _isName = _isHotelType = _isCity = _isAddress = _isPageName = false;
                }
                _dataKey = _dataValue = "";
            }
        }

        if (_isKey) _dataKey += fileText[i];
    }
}
