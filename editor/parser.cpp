#include "precompiled.h"

// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef __GNUC__
#  pragma warning(disable:4103)
#  pragma warning(disable:4786)
#endif

#include "parser.h"
#include "../filesystem/input_stream.h"
#include <ostream>
#include <istream>
#include <map>
#include <vector>
#include <cassert>
#include <boost/shared_ptr.hpp>
#include "../system/Logger.h"

#define VALUEMAP_MASK_REFERENCED      1
#define VALUEMAP_MASK_LOG_NONEXISTING 2

typedef std::map<std::string, std::pair<std::string, int> > ValueMap;
typedef std::vector<std::string>                            LineList;

namespace frozenbyte {
    namespace editor {
        namespace {
            std::string tabString = "   ";

            // These to utils tjsp
            bool isWhiteSpace(char character)
            {
                if (character == ' ')
                    return true;
                if (character == '\t')
                    return true;
                if (character == '\r')
                    return true;
                if (character == '\n')
                    return true;
                if (character == '\0')
                    return true;

                return false;
            }

            void removeLeadingWhiteSpaces(std::string &string, int &textStart, int &textEnd)
            {
                for (unsigned int i = 0; i < string.size(); ++i) {
                    if (textStart == -1)
                        if ( !isWhiteSpace(string[i]) )
                            textStart = i;

                    // Remove comment
                    if (i < string.size() - 2)
                        if (string[i] == '/')
                            if (string[i + 1] == '/') {
                                textEnd = i;
                                break;
                            }
                }
            }

            void removeTrailingWhiteSpaces(std::string &string, int &textStart, int &textEnd)
            {
                if (textEnd - 1 >= 0)
                    for (int i = textEnd - 1; i >= 0; --i) {
                        if ( !isWhiteSpace(string[i]) ) {
                            textEnd = i + 1;
                            break;
                        }
                    }
            }

            void removeWhiteSpaces(std::string &string)
            {
                if ( string.empty() )
                    return;

                int textStart = -1;
                int textEnd = string.size();

                removeLeadingWhiteSpaces(string, textStart, textEnd);
                removeTrailingWhiteSpaces(string, textStart, textEnd);

                if (textStart == -1) {
                    string = "";
                } else {
                    int stringStart = (textStart >= 0) ? textStart : 0;
                    int stringEnd = textEnd - stringStart;

                    string = string.substr(stringStart, stringEnd);
                }
            }

            bool readLine(filesystem::InputStream &stream, std::string &result)
            {
                if ( stream.isEof() )
                    return false;

                result.clear();

                //std::getline(stream, result);
                while ( !stream.isEof() ) {
                    signed char c = 0;
                    stream >> c;

                    if (c == '\r')
                        continue;
                    else if (c == '\n')
                        break;

                    result += c;
                }

                removeWhiteSpaces(result);
                if ( result.empty() )
                    return readLine(stream, result);

                return true;
            }

            void splitString(const std::string &string, std::string &first, std::string &second, char splitter)
            {
                std::string::size_type position = string.find_first_of(splitter);
                if (position == std::string::npos)
                    return;

                for (int i = position - 1; i >= 0; --i) {
                    if ( isWhiteSpace(string[i]) )
                        continue;

                    first = string.substr(0, i + 1);
                    break;
                }

                for (unsigned int j = position + 1; j < string.size(); ++j) {
                    if ( isWhiteSpace(string[j]) )
                        continue;

                    second = string.substr(j, string.size() - j);
                    break;
                }

                return;
            }

            ParserGroup *parserGroupFactory();
        }

        struct ParserGroupData {
            ParserGroupData()
                : flags(0)
            {
            }

            typedef std::map<std::string, boost::shared_ptr<ParserGroup> > GroupMap;

            ValueMap    values;
            GroupMap    groups;
            LineList    lines;

            std::string emptyString;

            int         flags;

            void        removeSubGroup(const std::string &name)
            {
                GroupMap::iterator it = groups.find(name);
                if ( it != groups.end() )
                    groups.erase(it);
            }

            const std::string&getValue(const std::string &name, const std::string &defaultValue) const
            {
                ValueMap::const_iterator it = values.find(name);
                if ( it == values.end() ) {
                    if ( (flags & VALUEMAP_MASK_LOG_NONEXISTING) != 0 ) {
                        std::string msg = std::string("ParserGroupData::getValue - Given key \"");
                        msg += name;
                        msg += std::string("\" does not exist, returning default value.");
                        Logger::getInstance()->warning( msg.c_str() );
                    }
                    return defaultValue;
                }

                int *flag = const_cast<int *>( &( (*it).second.second ) );
                *flag |= VALUEMAP_MASK_REFERENCED;
                return (*it).second.first;
            }

            void parseSubGroup(filesystem::InputStream &stream, const std::string &string, int flags)
            {
                std::string groupName = string;
                std::string superName;

                splitString(string, groupName, superName, ':');
                boost::shared_ptr<ParserGroup> group( parserGroupFactory() );

                group->setFlags(flags);

                if ( !superName.empty() ) {
                    GroupMap::iterator it = groups.find(superName);
                    if ( it != groups.end() )
                        *group.get() = *(*it).second;
                }

                stream >> *group;
                groups[groupName] = group;
            }

            void parseValue(const std::string string, int flags)
            {
                std::string name;
                std::string value;

                if (string == "{")
                    return;
                if (string == "}")
                    return;

                splitString(string, name, value, '=');
                if (name.empty() || string[0] == '<') {
                    if ( !string.empty() )
                        lines.push_back(string);

                    return;
                }

                values[name].first = value;
                values[name].second = flags;
            }

            void parseGroup(filesystem::InputStream &stream, int flags)
            {
                std::string currentLine;
                std::string nextLine;

                readLine(stream, currentLine);
                if (!currentLine.empty() && currentLine[0] == '}')
                    return;

                while ( readLine(stream, nextLine) ) {
                    if (nextLine[0] == '{') {
                        parseSubGroup(stream, currentLine, flags);
                        currentLine = "";
                        continue;
                    }

                    parseValue(currentLine, flags);
                    if (nextLine[0] == '}')
                        return;

                    currentLine.swap(nextLine);
                }

                parseValue(currentLine, flags);
            }

            void copy(ParserGroupData &rhs)
            {
                values = rhs.values;
                lines = rhs.lines;
                groups.clear();

                for (GroupMap::iterator it = rhs.groups.begin(); it != rhs.groups.end(); ++it) {
                    boost::shared_ptr<ParserGroup> g( parserGroupFactory() );
                    *g.get() = *(*it).second.get();

                    groups[(*it).first] = g;
                }
            }

            void writeTabs(std::ostream &stream, int tabCount)
            {
                for (int i = 0; i < tabCount; ++i) {
                    stream << tabString;
                }
            }

            void writeStream(std::ostream &stream, int tabCount)
            {
                for (ValueMap::iterator vi = values.begin(); vi != values.end(); ++vi) {
                    writeTabs(stream, tabCount);
                    stream << (*vi).first << " = " << (*vi).second.first << std::endl;
                }

                for (GroupMap::iterator gi = groups.begin(); gi != groups.end(); ++gi) {
                    if ( ( gi != groups.begin() ) || ( !values.empty() ) )
                        stream << std::endl;

                    writeTabs(stream, tabCount);
                    stream << (*gi).first << std::endl;

                    writeTabs(stream, tabCount);
                    stream << "{" << std::endl;

                    (*gi).second->writeStream(stream, tabCount + 1),

                    writeTabs(stream, tabCount);
                    stream << "}" << std::endl;
                }

                if ( !lines.empty() && ( ( !groups.empty() || !values.empty() ) ) )
                    stream << std::endl;

                for (LineList::iterator li = lines.begin(); li != lines.end(); ++li) {
                    writeTabs(stream, tabCount);

                    //std::string &f = (*li);
                    stream << (*li) << std::endl;
                }
            }
        };

        ParserGroup::ParserGroup()
        {
            boost::scoped_ptr<ParserGroupData> tempData( new ParserGroupData() );
            data.swap(tempData);
        }

        ParserGroup::ParserGroup(const ParserGroup &rhs)
        {
            boost::scoped_ptr<ParserGroupData> tempData( new ParserGroupData() );
            tempData->copy( *rhs.data.get() );

            data.swap(tempData);
        }

        ParserGroup::~ParserGroup()
        {
        }

        ParserGroup &ParserGroup::operator = (const ParserGroup &rhs)
        {
            data->copy( *rhs.data.get() );
            return *this;
        }

        const std::string &ParserGroup::getValue(const std::string &name) const
        {
            return getValue(name, data->emptyString);
        }

        const std::string &ParserGroup::getValue(const std::string &name, const std::string &defaultValue) const
        {
            return data->getValue(name, defaultValue);
        }

        int ParserGroup::getValueAmount() const
        {
            return data->values.size();
        }

        const std::string &ParserGroup::getValueKey(int index) const
        {
            ValueMap::const_iterator it = data->values.begin();
            for (int i = 0; i < index; ++i) {
                ++it;
            }

            return it->first;
        }

        const ParserGroup &ParserGroup::getSubGroup(const std::string &name) const
        {
            assert( !name.empty() );

            ParserGroupData::GroupMap::const_iterator it = data->groups.find(name);
            if ( it != data->groups.end() )
                return *(*it).second.get();

            static ParserGroup emptyGroup;
            return emptyGroup;
        }

        ParserGroup &ParserGroup::getSubGroup(const std::string &name)
        {
            assert( !name.empty() );

            ParserGroupData::GroupMap::iterator it = data->groups.find(name);
            if ( it == data->groups.end() ) {
                boost::shared_ptr<ParserGroup> g( new ParserGroup() );
                data->groups[name] = g;
            }

            //ParserGroup &p = *data->groups[name];
            return *data->groups[name];
        }

        bool ParserGroup::hasSubGroup(const std::string &name) const
        {
            ParserGroupData::GroupMap::iterator it = data->groups.find(name);
            if ( it == data->groups.end() )
                return false;

            return true;
        }

        int ParserGroup::getSubGroupAmount() const
        {
            return data->groups.size();
        }

        const std::string &ParserGroup::getSubGroupName(int index) const
        {
            ParserGroupData::GroupMap::iterator it = data->groups.begin();
            int i = 0;

            for (; it != data->groups.end(); ++it) {
                if (i++ == index)
                    return it->first;
            }

            assert(!"...");

            static std::string empty;
            return empty;
        }

        const ParserGroup &ParserGroup::getSubGroup(int index) const
        {
            ParserGroupData::GroupMap::iterator it = data->groups.begin();
            int i = 0;

            for (; it != data->groups.end(); ++it) {
                if (i++ == index)
                    return *it->second.get();
            }

            static ParserGroup empty;
            return empty;
        }

        bool ParserGroup::hasValueBeenReferenced(int index) const
        {
            // if index >= values.size()
            //assert(!"ParserGroup::hasValueBeenReferenced - bad index parameter?");

            ValueMap::const_iterator it = data->values.begin();
            for (int i = 0; i < index; ++i) {
                ++it;
            }

            if ( (it->second.second & VALUEMAP_MASK_REFERENCED) != 0 )
                return true;
            else
                return false;
        }

        int ParserGroup::getLineCount() const
        {
            return data->lines.size();
        }

        const std::string &ParserGroup::getLine(int index) const
        {
            assert( (index >= 0) && ( index < getLineCount() ) );
            return data->lines[index];
        }

        void ParserGroup::setValue(const std::string &name, const std::string &value)
        {
            data->values[name].first = value;
            data->values[name].second |= VALUEMAP_MASK_REFERENCED;
        }

        void ParserGroup::addLine(const std::string &value)
        {
            data->lines.push_back(value);
        }

        void ParserGroup::addSubGroup(const std::string &name, ParserGroup &group)
        {
            assert( !name.empty() );

            boost::shared_ptr<ParserGroup> g( new ParserGroup() );
            g->data->copy( *group.data.get() );

            g->data->flags = data->flags;

            data->groups[name] = g;
        }

        void ParserGroup::removeSubGroup(const std::string &name)
        {
            data->removeSubGroup(name);
        }

        std::ostream &ParserGroup::writeStream(std::ostream &stream, int tabCount) const
        {
            data->writeStream(stream, tabCount);
            return stream;
        }

        filesystem::InputStream &ParserGroup::readStream(filesystem::InputStream &stream)
        {
            data->parseGroup(stream, data->flags);
            return stream;
        }

        void ParserGroup::setFlags(int flags)
        {
            data->flags = flags;
        }

        namespace {
            ParserGroup *parserGroupFactory()
            {
                return new ParserGroup();
            }
        }

/******/

        struct ParserData {
            ParserGroup globals;
            bool        logUnreferenced;
            bool        logNonExisting;
        };

        static void parser_unreferenced_check_walk(const ParserGroup &pg)
        {
            int branches = pg.getSubGroupAmount();
            for (int i = 0; i < branches; i++) {
                parser_unreferenced_check_walk( pg.getSubGroup(i) );
            }

            int leaves = pg.getValueAmount();
            for (int i = 0; i < leaves; i++) {
                if ( !pg.hasValueBeenReferenced(i) ) {
                    std::string msg = std::string();
                    msg = "parser_unreferenced_check_walk - Unreferenced parser group key \"";
                    msg += pg.getValueKey(i);
                    msg += "\".";
                    Logger::getInstance()->warning( msg.c_str() );
                }
            }
        }

        EditorParser::EditorParser(bool logUnreferenced, bool logNonExisting)
        {
            boost::scoped_ptr<ParserData> tempData( new ParserData() );
            data.swap(tempData);
            data->logUnreferenced = logUnreferenced;
            data->logNonExisting = logNonExisting;
        }

        EditorParser::~EditorParser()
        {
            if (data->logUnreferenced)
                parser_unreferenced_check_walk(data->globals);
        }

        const ParserGroup &EditorParser::getGlobals() const
        {
            return data->globals;
        }

        ParserGroup &EditorParser::getGlobals()
        {
            return data->globals;
        }

        std::ostream &EditorParser::writeStream(std::ostream &stream) const
        {
            data->globals.writeStream(stream, 0);
            return stream << std::endl;
        }

        filesystem::InputStream &EditorParser::readStream(filesystem::InputStream &stream)
        {
            int flags = 0;
            if (data->logNonExisting)
                flags |= VALUEMAP_MASK_LOG_NONEXISTING;

            data->globals.setFlags(flags);

            return stream >> data->globals;
        }

    } // end of namespace editor
}     // end of namespace frozenbyte
