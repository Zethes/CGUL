/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "String.h"
#include "../External/Defines.h"

 namespace Jatta
 {
    namespace JSON
    {
        namespace ValueType
        {
            enum
            {
                INT = 0,
                FLOAT,
                BOOL,
                STRING,
                OBJECT,
                ARRAY,
                NIL
            };
        }

        namespace Grammar
        {
            namespace Structural
            {
                const char BEGIN_ARRAY = '[';
                const char BEGIN_OBJECT = '{';
                const char END_ARRAY = ']';
                const char END_OBJECT = '}';
                const char PAIR_SEPERATOR = ':';
                const char VALUE_SEPERATOR = ',';
                const char STRING_DELIMITOR = '"';
            }
            namespace Literals
            {
                const Jatta::String FALSE_STRING = "false";
                const Jatta::String TRUE_STRING = "true";
                const Jatta::String NULL_STRING = "null";
            }
            namespace Numbers
            {
                const char DECIMAL_POINT = '.';
                const char LOWER_EXP = 'e';
                const char UPPER_EXP = 'E';
                const char MINUS = '-';
                const char PLUS = '+';
            }
            namespace Strings
            {
                const char QUOTATION_MARK = '"';
                const char REVERSE_SOLIDUS = '\\';
                const char SOLIDUS = '/';
                const char BACKSPACE = '\b';
                const char FORM_FEED = '\f';
                const char LINE_FEED = '\n';
                const char CARRIAGE_RETURN = '\r';
                const char TAB = '\t';

                namespace Escape
                {
                    const char BEGIN_ESCAPE = '\\';
                    const char QUOTATION_MARK = '"';
                    const char REVERSE_SOLIDUS = '\\';
                    const char SOLIDUS = '/';
                    const char BACKSPACE = 'b';
                    const char FORM_FEED = 'f';
                    const char LINE_FEED = 'n';
                    const char CARRIAGE_RETURN = 'r';
                    const char TAB = 't';
                    const char BEGIN_UNICODE = 'u';
                    namespace StringForm
                    {
                        const Jatta::String QUOTATION_MARK = "\\\"";
                        const Jatta::String REVERSE_SOLIDUS = "\\\\";
                        const Jatta::String SOLIDUS = "\\/";
                        const Jatta::String BACKSPACE = "\\b";
                        const Jatta::String FORM_FEED = "\\f";
                        const Jatta::String LINE_FEED = "\\n";
                        const Jatta::String CARRIAGE_RETURN = "\\r";
                        const Jatta::String TAB = "\\t";
                        const Jatta::String BEGIN_UNICODE = "\\u";
                    }
                }
            }
        }

        static UInt32 ind;
        _JATTA_EXPORT static Jatta::String __Indent();

        class Array;
        class Object;
        class Value;

        class Array
        {
            std::vector<Value> items;
        public:
            _JATTA_EXPORT Array();
            _JATTA_EXPORT ~Array();

            _JATTA_EXPORT Array(const Array& a);
            _JATTA_EXPORT Array& operator=(const Array& a);

            _JATTA_EXPORT Value& operator[] (Size i);
            _JATTA_EXPORT std::vector<Value>::const_iterator Begin() const;
            _JATTA_EXPORT std::vector<Value>::const_iterator End() const;
            _JATTA_EXPORT std::vector<Value>::iterator Begin();
            _JATTA_EXPORT std::vector<Value>::iterator End();

            _JATTA_EXPORT void PushBack(const Value& v);
            _JATTA_EXPORT void PopBack();
            _JATTA_EXPORT void Erase(std::vector<Value>::iterator i);
            _JATTA_EXPORT Jatta::Size Size() const;

            _JATTA_EXPORT String ToString();
        };

        class Object
        {
            std::map<String, Value> pairs;
        public:
            _JATTA_EXPORT Object();
            _JATTA_EXPORT ~Object();

            _JATTA_EXPORT Object(const Object& o);
            _JATTA_EXPORT Object& operator=(const Object& o);

            _JATTA_EXPORT Value& operator[] (const String& key);
            _JATTA_EXPORT std::map<String, Value>::const_iterator Begin() const;
            _JATTA_EXPORT std::map<String, Value>::const_iterator End() const;
            _JATTA_EXPORT std::map<String, Value>::iterator Begin();
            _JATTA_EXPORT std::map<String, Value>::iterator End();

            _JATTA_EXPORT std::pair<std::map<String,Value>::iterator, bool> Insert(String key, Value v);
            _JATTA_EXPORT Jatta::Size Size() const;

            _JATTA_EXPORT String ToString();
        };

        class Value
        {
            UInt32 type;

            SInt32 valueInt;
            Float32 valueFloat;
            bool valueBool;
            String valueString;

            Object valueObject;
            Array valueArray;
        public:
            _JATTA_EXPORT Value();
            _JATTA_EXPORT Value(const Value& v);
            _JATTA_EXPORT Value(const SInt32 v);
            _JATTA_EXPORT Value(const UInt32 v);
            _JATTA_EXPORT Value(const Float32 v);
            _JATTA_EXPORT Value(const double v);
            _JATTA_EXPORT Value(const bool v);
            _JATTA_EXPORT Value(const String& v);
            _JATTA_EXPORT Value(const Object& v);
            _JATTA_EXPORT Value(const Array& v);

            _JATTA_EXPORT UInt32 Type() const;

            _JATTA_EXPORT Value& operator=(const Value& v);

            operator Float32() const;
            operator SInt32() const;
            operator bool() const;
            operator String() const;
            operator Object() const;
            operator Array() const;

            _JATTA_EXPORT String ToString();
        };

        _JATTA_EXPORT Value ParseNumber(String str);
        _JATTA_EXPORT Value ParseString(String str);
        _JATTA_EXPORT Array ParseArray(String str);
        _JATTA_EXPORT Object ParseObject(String str);
        _JATTA_EXPORT Value ParseValue(String str);
        _JATTA_EXPORT Value Parse(String str);
    }
 }
