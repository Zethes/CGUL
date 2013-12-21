// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file JSON.cpp
 */

#include "JSON.hpp"

_CGUL_EXPORT CGUL::JSON::Object::Object()
{
}

_CGUL_EXPORT CGUL::JSON::Object::~Object()
{
}

_CGUL_EXPORT CGUL::JSON::Object::Object(const Object& o) :
    pairs(o.pairs)
{
}

_CGUL_EXPORT CGUL::JSON::Object& CGUL::JSON::Object::operator=(const Object& o)
{
    pairs = o.pairs;
    return *this;
}

_CGUL_EXPORT CGUL::JSON::Value& CGUL::JSON::Object::operator[] (const String& key)
{
    return pairs[key];
}

_CGUL_EXPORT std::map<CGUL::String, CGUL::JSON::Value>::const_iterator CGUL::JSON::Object::Begin() const
{
    return pairs.begin();
}

_CGUL_EXPORT std::map<CGUL::String, CGUL::JSON::Value>::const_iterator CGUL::JSON::Object::End() const
{
    return pairs.end();
}

_CGUL_EXPORT std::map<CGUL::String, CGUL::JSON::Value>::iterator CGUL::JSON::Object::Begin()
{
    return pairs.begin();
}

_CGUL_EXPORT std::map<CGUL::String, CGUL::JSON::Value>::iterator CGUL::JSON::Object::End()
{
    return pairs.end();
}

_CGUL_EXPORT std::pair<std::map<CGUL::String, CGUL::JSON::Value>::iterator, bool> CGUL::JSON::Object::Insert(String key, Value v)
{
    return pairs.insert(std::pair<String,Value>(key,v));
}

_CGUL_EXPORT CGUL::Size CGUL::JSON::Object::Size() const
{
    return pairs.size();
}

_CGUL_EXPORT CGUL::JSON::Array::Array()
{
}

_CGUL_EXPORT CGUL::JSON::Array::~Array()
{
}

_CGUL_EXPORT CGUL::JSON::Array::Array(const Array& a) :
    items(a.items)
{
}

_CGUL_EXPORT CGUL::JSON::Array& CGUL::JSON::Array::operator=(const Array& a)
{
    items = a.items;
    return *this;
}

_CGUL_EXPORT CGUL::JSON::Value& CGUL::JSON::Array::operator[] (CGUL::Size i)
{
    return items[i];
}

_CGUL_EXPORT std::vector<CGUL::JSON::Value>::const_iterator CGUL::JSON::Array::Begin() const
{
    return items.begin();
}

_CGUL_EXPORT std::vector<CGUL::JSON::Value>::const_iterator CGUL::JSON::Array::End() const
{
    return items.end();
}

_CGUL_EXPORT std::vector<CGUL::JSON::Value>::iterator CGUL::JSON::Array::Begin()
{
    return items.begin();
}

_CGUL_EXPORT std::vector<CGUL::JSON::Value>::iterator CGUL::JSON::Array::End()
{
    return items.end();
}

_CGUL_EXPORT void CGUL::JSON::Array::PushBack(const Value& v)
{
    items.push_back(v);
}

_CGUL_EXPORT void CGUL::JSON::Array::PopBack()
{
    items.pop_back();
}

_CGUL_EXPORT void CGUL::JSON::Array::Erase(std::vector<Value>::iterator i)
{
    items.erase(i);
}

_CGUL_EXPORT CGUL::Size CGUL::JSON::Array::GetSize() const
{
    return items.size();
}

_CGUL_EXPORT CGUL::JSON::Value::Value() :
    type(ValueType::NIL),
    valueInt(0),
    valueFloat(0.0f),
    valueBool(false)
{
}

_CGUL_EXPORT CGUL::JSON::Value::Value(const SInt32 v) :
    type(ValueType::INT),
    valueInt(v),
    valueFloat(0.0f),
    valueBool(false)
{
}

_CGUL_EXPORT CGUL::JSON::Value::Value(const UInt32 v) :
    type(ValueType::INT),
    valueInt(v),
    valueFloat(0.0f),
    valueBool(false)
{
}

_CGUL_EXPORT CGUL::JSON::Value::Value(const Float32 v) :
    type(ValueType::FLOAT),
    valueInt(0),
    valueFloat(v),
    valueBool(false)
{
}

_CGUL_EXPORT CGUL::JSON::Value::Value(const bool v) :
    type(ValueType::BOOL),
    valueInt(0),
    valueFloat(0.0f),
    valueBool(v)
{
}

_CGUL_EXPORT CGUL::JSON::Value::Value(const String& v) :
    type(ValueType::STRING),
    valueInt(0),
    valueFloat(0.0f),
    valueBool(false),
    valueString(v)
{
}

_CGUL_EXPORT CGUL::JSON::Value::Value(const Object& v) :
    type(ValueType::OBJECT),
    valueInt(0),
    valueFloat(0.0f),
    valueBool(false),
    valueObject(v)
{
}

_CGUL_EXPORT CGUL::JSON::Value::Value(const Array& v) :
    type(ValueType::ARRAY),
    valueInt(0),
    valueFloat(0.0f),
    valueBool(false),
    valueArray(v)
{
}

_CGUL_EXPORT CGUL::JSON::Value::Value(const JSON::Value& v) :
    type(ValueType::NIL),
    valueInt(0),
    valueFloat(0.0f),
    valueBool(false)
{
    switch (v.Type())
    {
        case ValueType::INT:
        {
            valueInt = v.valueInt;
            type = ValueType::INT;
            break;
        }
        case ValueType::FLOAT:
        {
            valueFloat = v.valueFloat;
            type = ValueType::FLOAT;
            break;
        }
        case ValueType::BOOL:
        {
            valueBool = v.valueBool;
            type = ValueType::BOOL;
            break;
        }
        case ValueType::STRING:
        {
            valueString = v.valueString;
            type = ValueType::STRING;
            break;
        }
        case ValueType::ARRAY:
        {
            valueArray = v.valueArray;
            type = ValueType::ARRAY;
            break;
        }
        case ValueType::OBJECT:
        {
            valueObject = v.valueObject;
            type = ValueType::OBJECT;
            break;
        }
        case ValueType::NIL:
        {
            type = ValueType::NIL;
            break;
        }
    }
}

_CGUL_EXPORT CGUL::UInt32 CGUL::JSON::Value::Type() const
{
    return type;
}

_CGUL_EXPORT CGUL::JSON::Value& CGUL::JSON::Value::operator=(const Value& v)
{
    switch (v.Type())
    {
        case ValueType::INT:
        {
            valueInt = v.valueInt;
            type = ValueType::INT;
            break;
        }
        case ValueType::FLOAT:
        {
            valueFloat = v.valueFloat;
            type = ValueType::FLOAT;
            break;
        }
        case ValueType::BOOL:
        {
            valueBool = v.valueBool;
            type = ValueType::BOOL;
            break;
        }
        case ValueType::STRING:
        {
            valueString = v.valueString;
            type = ValueType::STRING;
            break;
        }
        case ValueType::ARRAY:
        {
            valueArray = v.valueArray;
            type = ValueType::ARRAY;
            break;
        }
        case ValueType::OBJECT:
        {
            valueObject = v.valueObject;
            type = ValueType::OBJECT;
            break;
        }
        case ValueType::NIL:
        {
            type = ValueType::NIL;
            break;
        }
        default:
        {
            break;
        }
    }
    return *this;
}


_CGUL_EXPORT CGUL::String CGUL::JSON::__Indent()
{
    CGUL::String ret = "";
    for (UInt32 i = 0; i < ind; i++)
    {
        ret += "\t";
    }
    return ret;
}

_CGUL_EXPORT CGUL::String CGUL::JSON::Array::ToString()
{
    CGUL::String ret = "[\n";
    CGUL::JSON::ind++;
    for (std::vector<CGUL::JSON::Value>::iterator e = Begin(); e != End();)
    {
        ret += CGUL::JSON::__Indent();
        ret += (*e).ToString();
        if (++e != End())
            ret += ',';
        ret += "\n";
    }
    CGUL::JSON::ind--;
    ret += CGUL::JSON::__Indent();
    ret += "]";
    return ret;
}

_CGUL_EXPORT CGUL::String CGUL::JSON::Object::ToString()
{
    CGUL::String ret = "{\n";
    CGUL::JSON::ind++;
    for (std::map<CGUL::String, CGUL::JSON::Value>::iterator e = Begin(); e != End();)
    {
        ret += CGUL::JSON::__Indent();
        ret += '"';
        ret += e->first;
        ret += "\": ";
        ret += e->second.ToString();
        if (++e != End())
            ret += ',';
        ret += "\n";
    }
    CGUL::JSON::ind--;
    ret += CGUL::JSON::__Indent();
    ret += "}";
    return ret;
}

_CGUL_EXPORT CGUL::String CGUL::JSON::Value::ToString()
{
    switch (type)
    {
        case CGUL::JSON::ValueType::INT:
        {
            CGUL::String ret = "";
            ret += valueInt;
            return ret;
        }
        case CGUL::JSON::ValueType::FLOAT:
        {
            CGUL::String ret = "";
            ret += valueFloat;
            return ret;
        }
        case CGUL::JSON::ValueType::BOOL:
        {
            return (valueBool ? "true" : "false");
        }
        case CGUL::JSON::ValueType::STRING:
        {
            CGUL::String ret = "\"";
            ret += valueString;
            ret += "\"";
            return ret;
        }
        case CGUL::JSON::ValueType::ARRAY:
        {
            return valueArray.ToString();
        }
        case CGUL::JSON::ValueType::OBJECT:
        {
            return valueObject.ToString();
        }
        case CGUL::JSON::ValueType::NIL:
        default:
        {
            return U8("null");
        }
    }
}

_CGUL_EXPORT CGUL::JSON::Value::operator CGUL::Float32() const
{
    return valueFloat;
}

_CGUL_EXPORT CGUL::JSON::Value::operator CGUL::SInt32() const
{
    return valueInt;
}

_CGUL_EXPORT CGUL::JSON::Value::operator bool() const
{
    return valueBool;
}

_CGUL_EXPORT CGUL::JSON::Value::operator CGUL::String() const
{
    return valueString;
}

_CGUL_EXPORT CGUL::JSON::Value::operator CGUL::JSON::Object() const
{
    return valueObject;
}

_CGUL_EXPORT CGUL::JSON::Value::operator CGUL::JSON::Array() const
{
    return valueArray;
}

_CGUL_EXPORT CGUL::JSON::Value CGUL::JSON::ParseNumber(String str)
{
    bool negate = (str[0] == JSON::Grammar::Numbers::MINUS);

    UInt32 splitLoc = 0;
    UInt32 expLoc = 0;
    bool isInt = true;
    bool hasExp = false;
    for (UInt32 i = 1; i < str.GetLength(); i++)
    {
        if (str[i] == Grammar::Numbers::DECIMAL_POINT)
        {
            if (!isInt)
            {
                break;    //ERROR
            }
            isInt = false;
            splitLoc = i;
        }
        else if (str[i] == Grammar::Numbers::LOWER_EXP ||
                 str[i] == Grammar::Numbers::UPPER_EXP)
        {
            hasExp = true;
            expLoc = i;
            break;
        }
    }
    if (!hasExp)
    {
        expLoc = str.GetLength();
    }

    if (isInt)
    {
        splitLoc = expLoc;
    }

    float number = 0;
    float place = 1;

    // Start with the left side (> 0)
    for (UInt32 i = splitLoc - 1; i >= 0; i--)
    {
        if (str[i] == JSON::Grammar::Numbers::MINUS && i == 0)
        {
            break;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            //Can't have a trail of zeros at start (unless it's the only 0)
            if (str[i] == '0' || i == splitLoc - 1)
            {
                bool bad = true;
                for (UInt32 j = 0; j < i; j++) //Check to see if there is only zeros before this.
                {
                    if (str[j] >= '1' && str[j] <= '9')
                    {
                        bad = false;
                        break;
                    }
                }
                if (bad)
                    break;
            }

            //Appears to be fine, lets add this number and increment the place.
            number += (str[i] - '0') * place;
            place *= 10;
        }
        else
        {
            //ERROR unknown Char
        }
    }

    if (!isInt) //It's a decimal!
    {
        place = 0.1f;
        for (UInt32 i = splitLoc + 1; i < str.GetLength() && i < expLoc; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                number += (str[i] - '0')*place;
                place /= 10;
            }
            else
            {
                 //ERROR unknown Char
            }
        }
    }

    //Is it in scientific notation?
    if (hasExp)
    {
        float notationAmount = 0;
        bool negativeNotate = true;
        place = 1;
        if (!str.IsEmpty())
        {
            for (UInt32 i = str.GetLength() - 1; i >= 0 && i > expLoc; i--)
            {
                if (str[i] >= '0' && str[i] <= '9')
                {
                    notationAmount += (str[i] - '0') * place;
                    place *= 10;
                }
                else if ((i == expLoc + 1 && str[i] == Grammar::Numbers::MINUS) || str[i] == Grammar::Numbers::PLUS)
                {
                    negativeNotate = (str[i] == Grammar::Numbers::MINUS);
                }
                else
                {
                    //ERROR unknown Char
                }
            }
        }
        place = 1;
        for (UInt32 i = 0; i < notationAmount; i++)
        {
            place *= 10;
        }

        if (negativeNotate)
        {
            place = 0.1f;
            for (UInt32 i = 0; i < notationAmount - 1; i++)
            {
                place /= 10;
            }
        }

        number *= place;
    }

    if (negate)
    {
        number *= -1;
    }

    if ((SInt32)number == number && isInt)
    {
        return JSON::Value((SInt32)(number));
    }
    else
    {
        return JSON::Value(number);
    }
}

_CGUL_EXPORT CGUL::JSON::Value CGUL::JSON::ParseString(String str)
{
    CGUL::String ret;

    UInt32 i = 0;
    if (str[0] == Grammar::Structural::STRING_DELIMITOR)
    {
        i++;
    }

    for (; i < str.GetLength(); i++)
    {
        if (str[i] == Grammar::Structural::STRING_DELIMITOR)
        {
            break;
        }
        if (str[i] == Grammar::Strings::Escape::BEGIN_ESCAPE)
        {
            if (i+1 >= str.GetLength())
            {
                //ERROR
            }
            switch (str[i+1])
            {
                case Grammar::Strings::Escape::QUOTATION_MARK:
                {
                    ret += Grammar::Strings::QUOTATION_MARK;
                    break;
                }
                case Grammar::Strings::Escape::REVERSE_SOLIDUS:
                {
                    ret += Grammar::Strings::REVERSE_SOLIDUS;
                    break;
                }
                case Grammar::Strings::Escape::SOLIDUS:
                {
                    ret += Grammar::Strings::SOLIDUS;
                    break;
                }
                case Grammar::Strings::Escape::BACKSPACE:
                {
                    ret += Grammar::Strings::BACKSPACE;
                    break;
                }
                case Grammar::Strings::Escape::FORM_FEED:
                {
                    ret += Grammar::Strings::FORM_FEED;
                    break;
                }
                case Grammar::Strings::Escape::LINE_FEED:
                {
                    ret += Grammar::Strings::LINE_FEED;
                    break;
                }
                case Grammar::Strings::Escape::CARRIAGE_RETURN:
                {
                    ret += Grammar::Strings::CARRIAGE_RETURN;
                    break;
                }
                case Grammar::Strings::Escape::TAB:
                {
                    ret += Grammar::Strings::TAB;
                    break;
                }
                case Grammar::Strings::Escape::BEGIN_UNICODE:
                {
                    CGUL::String copy = str;
                    copy.ToLower();
                    if (i + 5 >= str.GetLength()) //Need 4 hexadecimal digits
                    {
                        //ERROR
                    }

                    UInt32 charCode = 0;
                    UInt32 place = 1;
                    for (UInt32 j = i + 4; j >= i + 1; j--)
                    {
                        if (copy[j] >= '0' && copy[j] <= '9')
                        {
                            charCode += (copy[j]-'0')*place;
                            place *= 16;
                        }
                        else if (copy[j] >= 'a' || copy[j] <= 'f' )
                        {
                            charCode += (copy[j] - 'a' + 10) * place;
                            place *= 16;
                        }
                        else
                        {
                            //ERROR! Unknown character.
                        }
                    }
                    i += 4;

                    ret += String::FromCodePoint(charCode);
                }
                break;
            }
            i += 1;
        }
        else
        {
            ret += str[i];
        }
    }

    return JSON::Value(ret);
}

_CGUL_EXPORT CGUL::JSON::Array CGUL::JSON::ParseArray(CGUL::String str)
{
    Array ret;

    String value;
    bool insideString = false;
    int objInd = 0, arrayInd = 0;
    for (UInt32 i = 0; i < str.GetLength(); i++)
    {
        if (insideString)
        {
            if (str[i] == Grammar::Structural::STRING_DELIMITOR)
            {
                value += str[i];
                insideString = false;
            }
            else
            {
                value += str[i];
            }
        }
        else if (objInd > 0 || str[i] == Grammar::Structural::BEGIN_OBJECT)
        {
            if (str[i] == Grammar::Structural::END_OBJECT)
            {
                objInd--;
            }
            if (str[i] == Grammar::Structural::BEGIN_OBJECT)
            {
                objInd++;
            }
            value += str[i];
        }
        else if (arrayInd > 0 || str[i] == Grammar::Structural::BEGIN_ARRAY)
        {
            if (str[i] == Grammar::Structural::END_ARRAY)
            {
                arrayInd--;
            }
            if (str[i] == Grammar::Structural::BEGIN_ARRAY)
            {
                arrayInd++;
            }
            value += str[i];
        }
        else if (str[i] == Grammar::Structural::STRING_DELIMITOR)
        {
            value += str[i];
            insideString = true;
        }
        else if (str[i] == Grammar::Structural::VALUE_SEPERATOR)
        {
            ret.PushBack(CGUL::JSON::ParseValue(value));
            value.Set("");
        }
        else
        {
            value += str[i];
        }
    }

    if (value.GetLength() > 0)
    {
        ret.PushBack(CGUL::JSON::ParseValue(value));
    }

    return ret;
}

_CGUL_EXPORT CGUL::JSON::Object CGUL::JSON::ParseObject(CGUL::String str)
{
    Object ret;

    std::vector<String> parts;
    String part;
    bool insideString = false;
    int objInd = 0, arrayInd = 0;
    for (UInt32 i = 0; i < str.GetLength(); i++)
    {
        if (insideString)
        {
            if (str[i] == Grammar::Structural::STRING_DELIMITOR)
            {
                insideString = false;
                part += str[i];
            }
            else
            {
                part += str[i];
            }
        }
        else if (objInd > 0 || str[i] == Grammar::Structural::BEGIN_OBJECT)
        {
            if (str[i] == Grammar::Structural::END_OBJECT)
            {
                objInd--;
            }
            if (str[i] == Grammar::Structural::BEGIN_OBJECT)
            {
                objInd++;
            }
            part += str[i];
        }
        else if (arrayInd > 0 || str[i] == Grammar::Structural::BEGIN_ARRAY)
        {
            if (str[i] == Grammar::Structural::END_ARRAY)
            {
                arrayInd--;
            }
            if (str[i] == Grammar::Structural::BEGIN_ARRAY)
            {
                arrayInd++;
            }
            part += str[i];
        }
        else if (str[i] == Grammar::Structural::STRING_DELIMITOR)
        {
            part += str[i];
            insideString = true;
        }
        else if (str[i] == Grammar::Structural::VALUE_SEPERATOR)
        {
            parts.push_back(part);
            part.Set("");
        }
        else
        {
            part += str[i];
        }
    }
    parts.push_back(part);

    for (std::vector<String>::const_iterator i = parts.begin(); i != parts.end(); ++i)
    {
        bool insideString = false;

        CGUL::String key;
        for (UInt32 j = 0; j < i->GetLength(); j++)
        {
            if (insideString)
            {
                if (i->GetChar(j) == Grammar::Structural::STRING_DELIMITOR)
                {
                    insideString = false;
                }
                else
                {
                    key += i->GetChar(j);
                }
            }
            else if (i->GetChar(j) == Grammar::Structural::STRING_DELIMITOR)
            {
                insideString = true;
            }
            else if (i->GetChar(j) == Grammar::Structural::PAIR_SEPERATOR)
            {
                if (key.GetLength() == 0)
                {
                    //ERROR
                }
                ret.Insert(key, JSON::ParseValue(i->SubString(j + 1)));
                break;
            }
        }
    }

    return ret;
}

_CGUL_EXPORT CGUL::JSON::Value CGUL::JSON::ParseValue(CGUL::String str)
{
    String strLower = str;
    strLower.ToLower();
    if (strLower == Grammar::Literals::FALSE_STRING)
    {
        return CGUL::JSON::Value(false);
    }
    else if (strLower == Grammar::Literals::TRUE_STRING)
    {
        return CGUL::JSON::Value(true);
    }
    else if (strLower == Grammar::Literals::NULL_STRING)
    {
        return CGUL::JSON::Value();
    }
    //Is it a number?
    else if (str[0] == Grammar::Numbers::MINUS || (str[0] >= '0' && str[0] <= '9'))
    {
        return JSON::ParseNumber(str);
    }
    //What about a string?
    else if (str[0] == Grammar::Structural::STRING_DELIMITOR)
    {
        return JSON::ParseString(str);
    }
    else if (str[0] == Grammar::Structural::BEGIN_ARRAY) //Array
    {
        //Get the code.
        int ind = 0;
        CGUL::String code;
        for (UInt32 i = 0; i < str.GetLength(); i++)
        {
            if (str[i] == Grammar::Structural::BEGIN_ARRAY)
            {
                ind++;
            }
            else if (str[i] == Grammar::Structural::END_ARRAY)
            {
                ind--;
                if (ind == 0)
                {
                    break;
                }
            }

            if (ind > 0 && i > 0)
            {
                code += str[i];
            }
        }
        if (ind != 0)
        {
            //ERROR
        }

        return CGUL::JSON::Value(CGUL::JSON::ParseArray(code));
    }
    else if (str[0] == Grammar::Structural::BEGIN_OBJECT) //Object
    {
        //Get the code.
        int ind = 0;
        String code;
        for (UInt32 i = 0; i < str.GetLength(); i++)
        {
            if (str[i] == Grammar::Structural::BEGIN_OBJECT)
            {
                ind++;
            }
            else if (str[i] == Grammar::Structural::END_OBJECT)
            {
                ind--;
                if (ind == 0)
                {
                    break;
                }
            }

            if (ind > 0 && i > 0)
            {
                code += str[i];
            }
        }
        if (ind != 0)
        {
            //ERROR
        }

        return CGUL::JSON::Value(CGUL::JSON::ParseObject(code));
    }
    else
    {
        return CGUL::JSON::Value();
    }
}

_CGUL_EXPORT CGUL::JSON::Value CGUL::JSON::Parse(CGUL::String str)
{
    //Remove the unnecessary whitespacing.
    String newStr;
    bool insideString = false;
    for (UInt32 i = 0; i < str.GetLength(); i++)
    {
        if (insideString)
        {
            if (str[i] == Grammar::Structural::STRING_DELIMITOR)
            {
                newStr += str[i];
                insideString = false;
            }
            else
            {
                newStr += str[i];
            }
        }
        else if (str[i] == Grammar::Structural::STRING_DELIMITOR)
        {
            newStr += str[i];
            insideString = true;
        }
        else if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r')
        {
            newStr += str[i];
        }
    }

    //Parse!
    return ParseValue(newStr);
}
