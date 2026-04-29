#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class Card
{
	public:
		struct	HeadedList
		{
			int						count;
			const	std::string		header;
			const	std::string*	entries;
		};

		struct SingleHeadedList
		{
			const	std::string	header;
			const	std::string	item;
		};

		// Constructors
		Card(void);
		Card(const std::string& title);
		Card(const std::string& title, int width);
		Card(const std::string* entries, int count);
		Card(const std::string* entries, int count, int width);
		Card(const std::string& title, const std::string* entires, int count);
		Card(const std::string& title, const std::string* entires, int count, int width);
		Card(const std::string& title, const HeadedList* sections, int sectionCount);
		Card(const std::string& title, const SingleHeadedList* sections, int sectionCount);
		// Destructors
		~Card(void);
		// Functions
		std::string	render(void);
	
	private:
		int							_count;
		int							_width;
		int							_height;
		int							_sectionCount;
		bool						_listMode;
		bool						_sectionMode;
		bool						_singleHeaderList;
		std::string					_singleEntry;
		std::string					_title;
		const	HeadedList*			_sections;
		const	SingleHeadedList*	_singleHeadedSections;
		const std::string*			_entries; // To avoid "new", Cards don't own _entries, must be kept alive until Card is destroyed

		int			_visualStrlen(const std::string& str);
		void		_initDefaults(void);
		void		_setSingleEntry(const std::string& title);
		std::string	_substring(std::string& remaining, int maxWidth);
		std::string	_repeatChar(const std::string& str, int count);
		std::string	_renderSeparator(void);
		std::string	_renderBorder(const std::string& left, std::string right);
		std::string	_renderLine(const std::string& text);
		std::string	_renderRawLine(const std::string& text, bool first);
		std::string	_renderListLine(const  std::string& text);
};

#endif
