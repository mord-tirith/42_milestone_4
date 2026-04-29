#include "Card.hpp"

Card::Card(void) {
	_initDefaults();
}

Card::Card(const std::string& title) {
	_initDefaults();
	_singleEntry = title;
	_entries = &_singleEntry;
	_count = 1;
	_listMode = false;
}

Card::Card(const std::string& title, int width) {
	_initDefaults();
	_singleEntry = title;
	_entries = &_singleEntry;
	_count = 1;
	_width = width;
	_listMode = false;
}

Card::Card(const std::string* entries, int count) {
	_initDefaults();
	_entries = entries;
	_count = count;
	_listMode = true;
}

Card::Card(const std::string* entries, int count, int width) {
	_initDefaults();
	_entries = entries;
	_count = count;
	_width = width;
	_listMode = true;
}

Card::Card(const std::string& title, const std::string* entries, int count) {
	_initDefaults();
	_title = title;
	_entries = entries;
	_count = count;
	_listMode = true;
}

Card::Card(const std::string& title, const std::string* entries, int count, int width) {
	_initDefaults();
	_title = title;
	_entries = entries;
	_count = count;
	_width = width;
	_listMode = true;
}

Card::Card(const std::string& title, const HeadedList* sections, int sectionCount) {
	_initDefaults();
	_title = title;
	_sections = sections;
	_sectionMode = true;
	_singleHeaderList = false;
	_sectionCount = sectionCount;
}

Card::Card(const std::string& title, const SingleHeadedList* sections, int sectionCount) {
	_initDefaults();
	_title = title;
	_sectionMode = true;
	_singleHeaderList = true;
	_sectionCount = sectionCount;
	_singleHeadedSections = sections;
}

Card::~Card(void) {
}

void	Card::_initDefaults(void) {
	_count = 0;
	_width = 30;
	_height = 0;
	_listMode = false;
	_sectionMode = false;
	_singleHeaderList = false;
	_entries = NULL;
	_sections = NULL;
	_singleHeadedSections = NULL;
	_sectionCount = 0;
	_singleEntry = "";
	_title = "";
}

int	Card::_visualStrlen(const std::string& str)
{
	int	i = 0;
	int	len = 0;

	while (i < (int)str.length())
	{
		if ((str[i] & 0x80) == 0)
			i++;
		else if ((str[i] & 0xE0) == 0xC0)
			i += 2;
		else if ((str[i] & 0xF0) == 0xE0)
			i += 3;
		else if ((str[i] & 0xF8) == 0xF0)
			i += 4;
		else
			i++;

		len++;
	}
	return (len);
}

std::string	Card::_substring(std::string& remaining, int maxWidth) {
	int			i;
	int			visualLen;
	int			lastSpace;
	std::string	substr;

	while (remaining.length() > 0 && remaining[0] == ' ')
		remaining = remaining.substr(1);

	i = 0;
	visualLen = 0;
	lastSpace = -1;

	while (i < (int)remaining.length() && visualLen < maxWidth)
	{
		if (remaining[i] == ' ')
			lastSpace = i;
		i++;
		visualLen++;
	}

	if (i == (int)remaining.length())
	{
		substr = remaining;
		remaining = "";
		return (substr);
	}
	if (lastSpace > 0)
	{
		substr = remaining.substr(0, lastSpace);
		remaining = remaining.substr(lastSpace + 1);
	}
	else
	{
		substr = remaining.substr(0, i);
		remaining = remaining.substr(i);
	}

	while (remaining.length() > 0 && remaining[0] == ' ')
		remaining = remaining.substr(1);

	return (substr);
}

std::string	Card::_repeatChar(const std::string& str, int count) {
	std::string	result;
	
	if (!str.length())
		return ("");
	for (int i = 0; i < count; i++)
		result += str;

	return (result);
}

std::string	Card::_renderBorder(const std::string& left, std::string right) {
	std::string line = left;

	line += _repeatChar("─", _width - 2);
	line += right;
	return (line);
}

std::string Card::_renderSeparator(void) {
	std::string line;

	line = "├";
	line += _repeatChar("─", _width - 2);
	line += "┤";
	return (line);
}

std::string Card::_renderLine(const std::string& text) {
	int			textLen;
	int			innerWidth;
	int			leftSpaces;
	int			rightSpaces;
	std::string	line;
	std::string	localText = text;

	innerWidth = _width - 2;
	textLen = _visualStrlen(localText);

	if (textLen > innerWidth)
		localText = localText.substr(0, innerWidth);

	textLen = _visualStrlen(localText);
	leftSpaces = (innerWidth - textLen) / 2;
	rightSpaces = innerWidth - textLen - leftSpaces;

	line = "│";
	line += _repeatChar(" ", leftSpaces);
	line += localText;
	line += _repeatChar(" ", rightSpaces);
	line += "│";

	return (line);
}

std::string Card::_renderRawLine(const std::string& text, bool first) {
	int			textLen;
	int			innerWidth;
	int			rightSpaces;
	std::string	line;

	if (first)
		line = "├";
	else
		line = "│";

	innerWidth = _width - 2;
	textLen = _visualStrlen(text);
	rightSpaces = innerWidth - textLen;

	line += text;
	line += _repeatChar(" ", rightSpaces);
	line += "│";

	return (line);
}

std::string Card::_renderListLine(const std::string& text) {
	std::string	result;
	std::string	remaining;
	std::string	chunk;
	std::string	continuation;
	int			firstWidth;
	int			nextWidth;

	remaining = text;
	continuation = " ";

	firstWidth = _width - 3;
	nextWidth = _width - 2 - _visualStrlen(continuation);

	chunk = _substring(remaining, firstWidth);
	result += _renderRawLine(" " + chunk, true);

	while (_visualStrlen(remaining) > 0)
	{
		chunk = _substring(remaining, nextWidth);
		result += "\n";
		result += _renderRawLine(continuation + chunk, false);
	}

	return (result);
}

std::string Card::render(void) {
	int			i;
	std::string	result;

	i = 0;
	result = _renderBorder("┌", "┐") + "\n";

	if (_title.length() > 0)
	{
		result += _renderLine(_title) + "\n";
		if ((_listMode && _count > 0) || (_sectionMode && _sectionCount > 0))
			result += _renderSeparator() + "\n";
	}

	if (_sectionMode)
	{
		for (int s = 0; s < _sectionCount; s++)
		{
			if (_singleHeaderList)
			{
				result += _renderRawLine("┝━━ " + _singleHeadedSections[s].header, true) + "\n";
				result += _renderListLine(_singleHeadedSections[s].item) + "\n";
			}
			else
			{
				result += _renderRawLine("┝━━ " + _sections[s].header, true) + "\n";

				for (int j = 0; j < _sections[s].count; j++)
					result += _renderListLine(_sections[s].entries[j]) + "\n";
			}
		}

		result += _renderBorder("└", "┘");
		return (result);
	}

	while (i < _count)
	{
		if (_listMode)
			result += _renderListLine(_entries[i]) + "\n";
		else
			result += _renderLine(_entries[i]) + "\n";
		i++;
	}

	result += _renderBorder("└", "┘");

	return (result);
}

